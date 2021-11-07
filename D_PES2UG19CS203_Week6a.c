#include "6a.h"

static Node* create_Node(int data, Node* link) {
	Node* temp =  (Node*)malloc(sizeof(Node));
	temp -> data = data; 
	temp -> link = link;
	return temp;
}


void list_initialize(List* ptr_List) 
{
	//TODO - initialize structure members to default values
	ptr_List->head = NULL;
	ptr_List->number_of_Nodes = 0;
}


void list_insert_front(List* ptr_List, int data) 
{
	//TODO - perform linked list implementation of push operation.
	Node *this = ptr_List->head;
	Node *tmp = create_Node(data, this);
	ptr_List->head = tmp;
	ptr_List->number_of_Nodes = ptr_List->number_of_Nodes + 1;		
}


const int Node_get_data(Node *Node_ptr) 
{
	//TODO - return the top most element
	return (Node_ptr->data);
}


void list_delete_front(List* ptr_List) 
{
	//TODO - perform linked list implementation of pop operation.
	Node *curr = ptr_List->head;
	ptr_List->head = curr->link;
	free(curr);
	ptr_List->number_of_Nodes--;
}


void list_destroy(List* ptr_List) 
{
	//TODO - free the allocated space
	Node *l = ptr_List->head;
	Node *m = NULL;
	if(ptr_List->head == NULL)
		return;
	for(int i=0; i<ptr_List->number_of_Nodes; i++)
    	{
		m = l;
		l = l->link;
		free(m);
	}
	ptr_List->head = NULL;
}

void Stack_initialize(Stack *ptr_Stack) 
{
	//TODO - get the memory allocation for stack, and intern call list initialize
	ptr_Stack->ptr_List = (List*)malloc(sizeof(List));
	list_initialize(ptr_Stack->ptr_List);
}

void Stack_push(Stack *ptr_Stack, int key) 
{
	//TODO	 - call the function list_insert_front
	list_insert_front(ptr_Stack->ptr_List, key);
}

void Stack_pop(Stack *ptr_Stack) 
{
	//TODO- call the function list_delete_front
	list_delete_front(ptr_Stack->ptr_List);
}

int Stack_is_empty(Stack *ptr_Stack) 
{
	//TODO	- return 0 if stack is not empty
	if((ptr_Stack->ptr_List->number_of_Nodes) != 0)
		return 0;
	else
		return 1;
}

const int Stack_peek(Stack *ptr_Stack)
{
	//TODO	- return the top most element of the stack
	return (Node_get_data(ptr_Stack->ptr_List->head));
}

void Stack_destroy(Stack *ptr_Stack)
{
	//TODO	- deallocate
	list_destroy(ptr_Stack->ptr_List);
}


int postfix_eval(const char* expression) 
{
    // TODO
Stack ptr_Stack;
Stack_initialize(&ptr_Stack);
while((*expression) != '\0') 
{
switch(*expression)
{
case '+' :	
{
int a=0,b=0;
a=Stack_peek(&ptr_Stack);
Stack_pop(&ptr_Stack);
b=Stack_peek(&ptr_Stack);
Stack_pop(&ptr_Stack);
Stack_push(&ptr_Stack,a+b); 
break;
}

case '-' : 
{
int a=0,b=0;
a=Stack_peek(&ptr_Stack);
Stack_pop(&ptr_Stack);
b=Stack_peek(&ptr_Stack);
Stack_pop(&ptr_Stack);
Stack_push(&ptr_Stack,b-a); 
break;
}					
case '*' : 
{
int a=0,b=0;
a=Stack_peek(&ptr_Stack);
Stack_pop(&ptr_Stack);
b=Stack_peek(&ptr_Stack);
Stack_pop(&ptr_Stack);
Stack_push(&ptr_Stack,b*a); 
break;
}
case '/' :
{
int a=0,b=0;
a=Stack_peek(&ptr_Stack);
Stack_pop(&ptr_Stack);
b=Stack_peek(&ptr_Stack);
Stack_pop(&ptr_Stack);
Stack_push(&ptr_Stack,b/a); 
break;
}
case '^' :	
{
int a=0,b=0;
a=Stack_peek(&ptr_Stack);
Stack_pop(&ptr_Stack);
b=Stack_peek(&ptr_Stack);
Stack_pop(&ptr_Stack);
int k=0;
k=b;
for(int i=1;i<a;i++)
{
b=b*k;
}
Stack_push(&ptr_Stack,b); 
break;
}
			
default :	
{
int i;
i= *expression - '0';
Stack_push(&ptr_Stack,i);
break;
}
					

}
expression++;
}
int k=Stack_peek(&ptr_Stack);
return k;
Stack_destroy(&ptr_Stack);


}
