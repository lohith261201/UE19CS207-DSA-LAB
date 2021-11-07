#include<stdio.h>
#include<stdlib.h>
#include "tbt.h"

Node *newNde(int);
void setL(Node*,int);
void setR(Node*,int);

void tree_initialize(Tree *tree)
{
    tree->root=NULL;
}

void tree_insert(Tree *tree, int data)
{
    Node *ptr_nde=tree->root, *alias=NULL;
    while(ptr_nde!=NULL){
        alias=ptr_nde;
        if(data<ptr_nde->data){
            if(!ptr_nde->leftThread)
             ptr_nde=ptr_nde->left;
            else break;
        }
        else{
            if(!ptr_nde->rightThread)
               ptr_nde=ptr_nde->right;
            else break;
        }
    }
    if(alias==NULL)
    {
        tree->root=newNde(data);
        return ;
    }
    if(data>alias->data)
       setR(alias,data);
    else setL(alias,data);
}

Node *inorder_predecessor(Node *ptr)
{
    if(ptr->leftThread)
    return ptr->left;
else{
    ptr=ptr->left;
    while(!ptr->rightThread)ptr=ptr->right;
    return ptr;
}
}

Node *inorder_successor(Node *ptr)
{
    if(ptr->rightThread)
    return ptr->right;
else{
    ptr=ptr->right;
    while(!ptr->leftThread)ptr=ptr->left;
    return ptr;
}
}

void print_ascending(Tree *tree)
{
    if (tree->root == NULL)
    {
        printf("Empty\n");
        return;
    }
    Node *pter_node=tree->root;
    while(!pter_node->leftThread)
    pter_node=pter_node->left;
    while(pter_node!=NULL)
    {
        printfun(pter_node->data);
        pter_node=inorder_successor(pter_node);
    }
    nextline();
}

void print_descending(Tree *tree)
{
    if (tree->root == NULL)
    {
        printf("Empty\n");
        return;
    }
    Node *ptr_node=tree->root;
    while(!ptr_node->rightThread)ptr_node=ptr_node->right;
    while(ptr_node!=NULL){
        printfun(ptr_node->data);
        ptr_node=inorder_predecessor(ptr_node);
    }
    nextline();
}

void destroy(Node *r)
{
    //TODO
    Node *temp;
    while(r->left!=NULL)r=r->left;
    while(r!=NULL){
        temp=r;
        r=r->right;
        free(temp);
    }
}

void tree_destroy(Tree *t)
{
    destroy(t->root);
}

Node *newNde(int data){
    Node *new_node=(Node*)malloc(sizeof(Node));
    new_node->data=data;
    new_node->left=new_node->right=NULL;
    new_node->leftThread=new_node->rightThread=1;
    return new_node;
}



void setR(Node *ptr_node, int data){
    Node *new_node=newNde(data);
    new_node->right=ptr_node->right;
    ptr_node->right=new_node;
    new_node->left=ptr_node;
    ptr_node->rightThread=0;
}

void setL(Node *ptr_node, int data){
    Node *new_node=newNde(data);
    new_node->left=ptr_node->left;
    ptr_node->left=new_node;
    new_node->right=ptr_node;
    ptr_node->leftThread=0;
}

