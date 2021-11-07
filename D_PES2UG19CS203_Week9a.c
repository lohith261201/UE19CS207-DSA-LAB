#include "et.h"

Node * createExpressionTree(char* a,int len)
{
    //TODO
    Node * curnt=(Node*)malloc(sizeof(Node));
    Node * root=(Node*)malloc(sizeof(Node));
    Node * alias=(Node*)malloc(sizeof(Node));
    root=NULL;
    for(int j=len-1 ; j>=0 ; j--)
  {
   Node * nde=(Node*)malloc(sizeof(Node));
   nde->data=a[j];
   nde->left=nde->right=nde->prev=NULL;
   if(root!=NULL)
   {
    if(a[j]=='+' ||a[j]=='-' ||a[j]=='*'||a[j]=='/')
    {
     if(alias->right==NULL)
     {
      curnt=nde;
      alias->right=curnt;
      curnt->prev=alias;
      alias=curnt;
     }
     else if(alias->left==NULL)
     {
      curnt=nde;
      alias->left=curnt;
      curnt->prev=alias;
      alias=curnt;
     }
    else
    {
     while(alias->left!=NULL)
     {
      alias=alias->prev;
     }
     curnt=nde;
     alias->left=curnt;
     curnt->prev=alias;
     alias=curnt;
    }
   }
   else
   {
    if(alias->right==NULL)
    {
     curnt=nde;
     alias->right=curnt;
     curnt->prev=alias;
    }
    else if(alias->left==NULL)
    {
     curnt=nde;
     alias->left=curnt;
     curnt->prev=alias;
    }
    else
    {
     while(alias->left!=NULL)
     {
      alias=alias->prev;
     }
     curnt=nde;
     alias->left=curnt;
     curnt->prev=alias;
    }
   }
  }
   else
   {
     root=nde;
     curnt=alias=root;
   }


 }
 return root;
}


void inorder(Node *root)
{
 //TODO 
 // Note : Do not change the printf
  if(root!=NULL)
  {
    inorder(root->left);
    printf("%c",root->data);
    inorder(root->right); 
  }
}

void preorder(Node *root)
{
 //TODO 
 // Note : Do not change the printf
 if(root!=NULL)
 {
  printf("%c",root->data);
  preorder(root->left);
  preorder(root->right);   
 }
}

void postorder(Node *root)
{
 //TODO 
 // Note : Do not change the printf
  if(root!=NULL)
  {
  postorder(root->left);
  postorder(root->right);
  printf("%c",root->data); 
  }
}

void freeTree(Node *root)
{
  if(root!=NULL)
 {
    freeTree(root->left);
    freeTree(root->right);
    free(root);
 }
   
  else
  {  
    return;
  }
}

