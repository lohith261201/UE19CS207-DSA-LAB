#include "heap.h"
heap* heap_construct(int n){
    heap* temppor=(heap*)malloc(sizeof(heap)+n*sizeof(int));
    temppor->capacity=n;
    temppor->size=0;
    return(temppor);
}
void heap_destruct(heap* tmp){
	free(tmp);

}
int heap_get_capacity(heap* tmp){
	return (tmp->capacity);

}
int heap_get_size(heap* tmp){
	return (tmp->size);

}

int heap_insert(heap* tmp,int data){



	int posit,temp,t;		
        int siz,capic;	
	siz=heap_get_size(tmp);
	capic=heap_get_capacity(tmp);	
	if(siz==capic)
		return 0;

	*((tmp->elements)+siz)=data;
	tmp->size+=1;
	posit=(tmp->size)-1;
	while(posit)
	{
		if(posit%2!=0)
		{
			temp=(posit-1)/2;
		}
		else
		{
			temp=(posit-2)/2;
		}
		if(*((tmp->elements)+posit)<*((tmp->elements)+temp))
		{
			t=*((tmp->elements)+posit);
			*((tmp->elements)+posit)=*((tmp->elements)+temp);
			*((tmp->elements)+temp)=t;
		}
		else
			break;
		posit=temp;
	}
	return 1;
	
	
}
int heap_get_min(heap* tmp){

	return *(tmp->elements);

}
void heap_remove(heap* tmp){


	int temp=0;
        int lpo,rpot,t,min;	
	int si=tmp->size;
	*(tmp->elements)=*((tmp->elements)+(si-1));
	tmp->size-=1;
	si=tmp->size;
	while(temp<si)
	{
		min=temp;		
		lpo=(2*temp)+1;
		rpot=(2*temp)+2;
		if(lpo<si && *((tmp->elements)+lpo)<*((tmp->elements)+min))
			min=lpo;
		if(rpot<si && *((tmp->elements)+rpot)<*((tmp->elements)+min))
			min=rpot;
		if(min!=temp)
		{
			t=*((tmp->elements)+min);
			*((tmp->elements)+min)=*((tmp->elements)+temp);
			*((tmp->elements)+temp)=t;
			temp=min;
		}
		else
			break;
	}
	
	
}

