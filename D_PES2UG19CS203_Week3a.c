#include "poly.h"

#include<math.h>
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



long long int evaluate(List *list, int x)


{
    
Node *cur = list->head;
long long int sum=0;
int i=0;
for(i=0;i<list->number_of_nodes;i++)
{
sum+=((cur->data)*(pow(x,i)));
cur=cur->link;
}
return sum;
}
