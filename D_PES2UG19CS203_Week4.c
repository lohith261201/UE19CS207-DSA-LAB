#include "cll.h"
void position_insert(List* cll, int data, int pos)
{
    if (pos < 0 || pos > cll->length)
        return;
    else{
        Node *new = create_node(data);
        Node *tmp = cll->head;
        int i;
        if (cll->head == NULL && pos == 0)
        {
            cll->head = new;
            cll->tail = new;
            new->next = new;
        }
        else if (pos == 0)
        {
            new->next = cll->head;
            cll->head = new;
        }
        else if(pos == cll->length){
            cll->tail->next = new;
            cll->tail = new;
            new->next = cll->head;
        }
        else{
            for (i = 0; i < pos - 1; i++)
            {
                tmp = tmp->next;
            }
            new->next = tmp->next;
            tmp->next = new;
        }
        cll->length++;
    }
}

void position_delete(List* cll, int pos)
{
    if (cll->head == NULL)
        printf("\nEmpty list\n");
    else if (pos < 0 || pos > cll->length-1)
        printf("Invalid position\n");
    else{
        Node *tmp = cll->head;
        Node *prev;
        int i;
        if (pos == 0)
        {
            cll->tail->next = tmp->next;
            cll->head = tmp->next;
            tmp->next = NULL;
            free(tmp);
        }
        else if (pos == cll->length - 1){
            while (tmp->next != cll->head){
                prev = tmp;
                tmp = tmp->next;
            }
            prev->next = tmp->next;
            cll->tail = prev;
            tmp->next = NULL;
            free(tmp);
        }
        else{
            for (i = 0; i < pos; i++){
                prev = tmp;
                tmp = tmp->next;
            }
            prev->next = tmp->next;
            tmp->next = NULL;
            free(tmp);
        }
        cll->length--;
    }
}

int josephus(List* cll, int k)
{
    if (cll->head == NULL){
        printf("\nEmpty list\n");
        return -1;
    }
    else{
        while (cll->head != cll->tail)
        {
            position_delete(cll,(k + 1) % cll->length);
            if (k != cll->length)
                k++;
            else
                k = 0;
        }
        return (cll->head->data);
    }
}


