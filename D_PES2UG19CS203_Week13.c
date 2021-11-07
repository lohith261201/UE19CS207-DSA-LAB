#include<stdio.h>
#include "trie.h"

int length = -1;
int top = -1;

struct trienode *getnode()
{
    int i;
    struct trienode* tmpr = (struct trienode*)malloc(sizeof(struct trienode));
    tmpr->endofword = 0;
    for (i = 0; i < 26; i++)
        tmpr->child[i] = NULL;
    return tmpr;
}

void insert(struct trienode *root, char *key)
{
    int l = 0;
    struct trienode *temp = root;
    while (key[l] != '\0') {
        int letter = key[l] - 'a';
        if (temp->child[letter] == NULL)
            temp->child[letter] = getnode();
        temp = temp->child[letter];
        l++;
    }
    int val = key[--l] - 'a';
    temp->child[val] = getnode();
    temp->child[val]->endofword = 1;
}

void display(struct trienode *curr)
{
    int i, j;
    for (j = 0; j < 26; j++) {
        if (curr->child[j] != NULL){
            word[++length] = j + 'a';
            if (curr->child[j]->endofword == 1) {
                printf("\n");
                for(i = 0; i < length; i++)
                   printf("%c", word[i]);
            }
            display(curr->child[j]);
            length--;
        }
    }
}

int search(struct trienode *root,char *key)
{
  
    struct trienode *temp = root;
    int i = 0;
    while (key[i] != '\0') {
        int value = key[i] - 'a';
        if (temp->child[value] != NULL)
            temp = temp->child[value];
        else
            return 0;
        i++;
    }
    int val = key[--i] - 'a';
    if (temp->child[val]->endofword == 1)
        return 1;
    return 0;
}

void delete_trie(struct trienode *root,char *key)
{
    int i = 0, ltter;
    struct trienode *temp = root;
    struct stack nde;
    while (key[i] != '\0') {
        ltter = key[i] - 'a';
        if (temp->child[ltter] == NULL)
            return;
        push(temp, ltter);
        temp = temp->child[ltter];
        i++;
    }
    temp = temp->child[ltter];
    temp->endofword = 0;
    push(temp, -1);
    while(1) {
        nde = pop();
        if(nde.index != -1)
            nde.m->child[nde.index] = NULL;
        if(nde.m == root)
            break;
        if(check(nde.m) == 0 || nde.m->endofword == 1)
            break;
        else
            free(nde.m);
    }
}

int check(struct trienode *x)
{
    int m;
    for (m = 0; m < 26; m++){
        if (x->child[m] != NULL)
{
            return 0;
} 
   }
    return 1;
}

void push(struct trienode *x,int k)
{
    struct stack stc;
    stc.m = x;
    stc.index = k;
    s[++top] = stc;
}

struct stack pop()
{
    return s[top--];
}
