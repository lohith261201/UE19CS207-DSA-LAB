#include"dll.h"
int count_nodes(List* dll)
{
    return dll->number_of_nodes;	
}


void insert_front(List* dll, int data)
{
    Node *node=create_node(data);
    Node *tmp=NULL;
    if(dll->head==NULL)
    {
        dll->head=node;
        dll->tail=node;
        node->prev=NULL;   
        node->next=NULL;
        dll->number_of_nodes++;
    }
    else
    {
        dll->head->prev=node;
        node->next=dll->head;
        dll->head=node;
        node->prev=NULL;
        dll->number_of_nodes++;
    }
}


void dllist_delete_beginning(List* list)
{
    Node *tmp=list->head;
    if(tmp!=NULL)
    {
        list->head=list->head->next;
        free(tmp);
        list->head->prev=NULL;
        list->number_of_nodes--;
    }
}


void position_delete(List* dll, int pos)
{
    Node *tmp=dll->head;
    Node *node=NULL;
    int n=0;
    if(dll->number_of_nodes==1)
    {
        tmp=dll->tail;
        free(tmp);
        dll->number_of_nodes--;
    }
    else if(pos>dll->number_of_nodes)
    {
        return;
    }
    else if(tmp!=NULL)
    {
        while(n<pos)
        {
            node=tmp;
            tmp=tmp->next;
            n++;
        }
        tmp->prev=node->prev;
        free(node);
        dll->number_of_nodes--;
    }
}

int search_list(List* dll,int key)
{
    Node *cur=dll->head;
    Node *node=NULL;
    int n=0,flag=0;
    if(cur!=NULL)
    {
        while(cur!=NULL)
        {
            node=cur;
            cur=cur->next;
            if(node->data==key)
            {
                flag=1;
                goto a;
            }
            n++;
        }
    }
a:
if(flag==0)
    return -1;
else
    return n;
}


void reverse_list(List* dll)
{
    Node *cur=dll->head;
    Node *tmp=NULL;
    while(cur!=NULL)
    {
        tmp=cur->prev;
        cur->prev=cur->next;
        cur->next=tmp;
        cur=cur->prev;
    }
    if(tmp!=NULL)
    {
        dll->head=tmp->prev;
    }
}


