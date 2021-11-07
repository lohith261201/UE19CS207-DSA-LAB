#include<stdio.h>
#include "bst.h"
void tree_initialize(Tree *tree)
{
    tree = (Tree*)malloc(sizeof(Tree));
    tree->root = NULL;
}

void tree_insert(Tree *tree, int data)
{
    Node *tmper = (Node*)malloc(sizeof(Node));
    tmper->left = NULL;
    tmper->right = NULL;
    tmper->data = data;
    Node *alias = tree->root;
    Node *prv;
    
    if (tree->root == NULL)
    {
        tree->root = tmper;
    }
    else{
        while (alias != NULL){
            prv = alias;
            if (data < alias->data)
                alias = alias->left;
        
            else
                alias = alias->right;
        }
        if (data < prv->data)
            prv->left = tmper;
        else
            prv->right = tmper;
    }
}

void tree_delete(Tree *tree, int element)
{
    Node *aka,*prev;
    aka = tree->root;
    if (tree->root == NULL){
        printf("Empty tree\n");
        return;
    }
    
    while (aka != NULL && aka->data != element){
        if (element > aka->data){
            prev = aka;
            aka = aka->right;
        }
        else{
            prev = aka;
            aka = aka->left;
        }
    }
    
    
    
    if (aka == tree->root && (aka->right == NULL || aka->left == NULL)){
        if (aka->left == NULL)
            tree->root = aka->right;
        else
            tree->root = aka->left;
        free(aka);
    }
    
    else if (aka == NULL)
        printf("Element not found\n");


    else if (aka->left == NULL){
        if (aka == prev->left)
            prev->left = aka->right;
        else
            prev->right = aka->right;
        free(aka);
    }    
    




    else if (aka->right == NULL){
        if (aka == prev->left)
            prev->left = aka->left;
        else
            prev->right = aka->left;
        free(aka);
    }
        
    
        
    else{
        Node *offspring = aka->right;
        Node *parent = aka;
        while (offspring->left != NULL){
            parent = offspring;
            offspring = offspring->left;
        }
        aka->data = offspring->data;
        if (offspring == parent->left)
            parent->left = offspring->right;
        else
            parent->right = offspring->right;
        free(offspring);
    }
}

void tree_inorder(Node *r)
{
 	 if (r == NULL)
           return;
    tree_inorder(r->left);
    printf("%d ",r->data);
    tree_inorder(r->right);
}

void tree_preorder(Node *r)
{
    if (r == NULL)
         return;
    printf("%d ",r->data);
    tree_preorder(r->left);
    tree_preorder(r->right);
}

void tree_postorder(Node *r)
{
    if (r == NULL)
        return;
    tree_postorder(r->left);
    tree_postorder(r->right);
    printf("%d ",r->data);
}

void postorder(Tree *t)
{
    tree_postorder(t->root);
    printf("\n");
}

void preorder(Tree *t)
{
    tree_preorder(t->root);
    printf("\n");
}

void inorder(Tree *t)
{
    tree_inorder(t->root);
    printf("\n");
}

void destroy(Node *r)
{
    if (r == NULL)
        return;
    
    destroy(r->left);
    destroy(r->right);
    if(r->left != NULL)
        r->left = NULL;
    if(r->right != NULL)
        r->right = NULL;
    r = NULL;
    free(r);
}

void tree_destroy(Tree *t)
{ 
    destroy(t->root);
    t->root = NULL;
}
