#include "queue.h"
static node *create_node(int id, int time, node *link)
{
	node *tmpe = (node *)malloc(sizeof(node));
	tmpe -> id = id;
	tmpe -> time = time;
	tmpe -> link = link;
	return tmpe;
}

void list_initialize(List *ptr_list)
{
	ptr_list -> head = NULL;
	ptr_list -> tail = NULL;
	ptr_list -> number_of_nodes = 0;
}
const int node_get_id(node *node_ptr)
{
	return node_ptr -> id;
}

const int node_get_time(node *node_ptr)
{
	return node_ptr -> time;
}

void list_insert_rear(List *ptr_list, int id, int time)
{
	node *tp = create_node(id,time,NULL);
	if(ptr_list -> head == NULL)
		ptr_list -> head = ptr_list -> tail = tp;
	else
	{
		(ptr_list -> tail) -> link = tp;
		ptr_list -> tail = tp;
	}
	++(ptr_list -> number_of_nodes);
}

void list_delete_front(List *ptr_list)
{
	if(ptr_list -> number_of_nodes == 0)
	{
		printf("List empty\n");
		return;
	}
	node *dum = ptr_list -> head;
	ptr_list -> head = ptr_list -> head -> link;
	if(ptr_list -> head == NULL)
		ptr_list -> tail = NULL;
	--(ptr_list -> number_of_nodes);
	free(dum);
}

void list_destroy(List *ptr_list)
{
	node *alias = ptr_list -> head,*prev;
	while(alias != NULL)
	{
		prev = alias;
		alias = alias -> link;
		free(prev);
	}
}

void queue_initialize(Queue *queue_list)
{
	queue_list -> ptr_list = (List *)malloc(sizeof(List));
	list_initialize(queue_list -> ptr_list);
}

void queue_enqueue(Queue *ptr, int id, int time)
{
	list_insert_rear(ptr -> ptr_list,id,time);
}

void queue_dequeue(Queue *ptr)
{
	list_delete_front(ptr -> ptr_list);
}

int queue_is_empty(Queue *ptr)
{
	if(ptr -> ptr_list -> number_of_nodes == 0)
		return 1;
	return 0;
}

void queue_peek(Queue *ptr)
{
	if(queue_is_empty(ptr))
		printf("Empty Queue\n");
	else
		printf("%d %d\n",node_get_id(ptr->ptr_list->head),node_get_time(ptr->ptr_list->head));
}

void queue_destroy(Queue *ptr)
{
	list_destroy(ptr -> ptr_list);
	free(ptr -> ptr_list);
}

const int queue_find_person(Queue *ptr_queue, int t)
{
	node *aka = ptr_queue -> ptr_list -> head;
	int id;
	while(aka != NULL && t>0)
	{
		t -= node_get_time(aka);
		id = node_get_id(aka);
		aka = aka -> link;
	}
	if(t <= 0)
	{
		printf("%d\n",id);
		return id;
	}
	printf("Empty Queue\n");
}
