#include<stdio.h>

#include<stdlib.h>

#include "sll.h"



void insert_at_end(List *list, int data)
{

	
Node *tmp = (Node *)malloc(sizeof(Node));
tmp->data = data;

tmp->link = NULL;
	
Node *curr = list->head;

if((list->head) == NULL)
	
{
	
list->head = tmp;
	                
	
}

else

{
		
while((curr->link) != NULL)
		
{
			
curr = curr->link;

}
	
curr->link = tmp;

}

list->number_of_nodes = list->number_of_nodes + 1;

}




void list_delete_front(List* list)
{

	
if(list->head == NULL)
{
printf("EMPTY\n");
}
else
{
Node *start = list->head;
list->head = start->link;
free(start);
list->number_of_nodes = list->number_of_nodes - 1;
}

}





void list_insert_at (List *list, int data, int position)

{
	
Node *tmp = (Node *)malloc(sizeof(Node));

tmp->data = data;

Node *curr = list->head;
Node *prev = NULL;
        
if((position<0) | (position>(list->number_of_nodes)))

{
		
return;			
}
else if(position == 0)
{
tmp->link = curr;
list->head = tmp;
}
else
{
for(int j=1 ; j<=position ;j++)
{
prev = curr;
curr = curr->link;
}
prev->link = tmp;
tmp->link = curr;
}
list->number_of_nodes = list->number_of_nodes + 1;
}



void list_reverse(List* list)

{
 
Node *curr;
curr = list->head;
Node *prev = NULL;

Node *next = NULL;

if((list->head) == NULL)

{
			
printf("EMPTY\n");
		
}
	
else
{
{
while(curr != NULL)
		
{

next = curr->link;
			
curr->link = prev;
			
prev = curr;
		
curr = next;
		
}

list->head = prev;
	
}

}



}	
