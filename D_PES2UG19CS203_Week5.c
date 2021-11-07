#include "5a.h"

static Node* create_Node(int data, Node* link)
{
	// TODO - create and allocate dynamic space
	Node *nd = (Node *)malloc(sizeof(Node));
	nd->data = data;
	nd->link = link;
	return nd;
}


void list_initialize(List* ptr_list) 
{
	//TODO - initialize structure members to default values
	ptr_list->head = NULL;
	ptr_list->number_of_Nodes = 0;
}


void list_insert_front(List* ptr_list, int data) 
{
	//TODO - perform linked list implementation of push operation.
	Node *this = ptr_list->head;
	Node *tmp = create_Node(data, this);
	ptr_list->head = tmp;
	ptr_list->number_of_Nodes = ptr_list->number_of_Nodes + 1;		
}


const int Node_get_data(Node *Node_ptr) 
{
	//TODO - return the top most element
	return (Node_ptr->data);
}


void list_delete_front(List* ptr_list) 
{
	//TODO - perform linked list implementation of pop operation.
	Node *curr = ptr_list->head;
	ptr_list->head = curr->link;
	free(curr);
	ptr_list->number_of_Nodes--;
}


void list_destroy(List* ptr_list) 
{
	//TODO - free the allocated space
	Node *l = ptr_list->head;
	Node *m = NULL;
	if(ptr_list->head == NULL)
		return;
	for(int i=0; i<ptr_list->number_of_Nodes; i++)
    	{
		m = l;
		l = l->link;
		free(m);
	}
	ptr_list->head = NULL;
}

void Stack_initialize(Stack *ptr_Stack) 
{
	//TODO - get the memory allocation for stack, and intern call list initialize
	ptr_Stack->ptr_list = (List*)malloc(sizeof(List));
	list_initialize(ptr_Stack->ptr_list);
}

void Stack_push(Stack *ptr_Stack, int key) 
{
	//TODO	 - call the function list_insert_front
	list_insert_front(ptr_Stack->ptr_list, key);
}

void Stack_pop(Stack *ptr_Stack) 
{
	//TODO- call the function list_delete_front
	list_delete_front(ptr_Stack->ptr_list);
}

int Stack_is_empty(Stack *ptr_Stack) 
{
	//TODO	- return 0 if stack is not empty
	if((ptr_Stack->ptr_list->number_of_Nodes) != 0)
		return 0;
	else
		return 1;
}

const int Stack_peek(Stack *ptr_Stack)
{
	//TODO	- return the top most element of the stack
	return (Node_get_data(ptr_Stack->ptr_list->head));
}

void Stack_destroy(Stack *ptr_Stack)
{
	//TODO	- deallocate
	list_destroy(ptr_Stack->ptr_list);
}

int match_parenthesis(const char* string)
{
	//TODO - implement the code to match paranthesis in a string which is passed as a parameter.
	Stack ptrStack;
	Stack_initialize(&ptrStack);
	while((*string) != '\0') {
		switch(*string) {
			case '(' :	Stack_push(&ptrStack, 40);
				break;
			case '[' : 	Stack_push(&ptrStack, 91);
				break;
			case '{' : 	Stack_push(&ptrStack, 123);
				break;
			case ')' : 	if(Stack_is_empty(&ptrStack))
					return 0;
				if(Stack_peek(&ptrStack) != 40)
					return 0;
				Stack_pop(&ptrStack);
				break;
			case ']' :	if(Stack_is_empty(&ptrStack))
					return 0;
				if(Stack_peek(&ptrStack) != 91)
					return 0;
				Stack_pop(&ptrStack);
				break;
			case '}' :	if(Stack_is_empty(&ptrStack))
					return 0;
				if(Stack_peek(&ptrStack) != 123)
					return 0;
				Stack_pop(&ptrStack);
				break;
			default:	break;
		}
		string++;
	}
	int res = Stack_is_empty(&ptrStack);
	if(res == 0) {
		Stack_destroy(&ptrStack);
		return 0;
	}
	Stack_destroy(&ptrStack);
	return 1;
}	




 

