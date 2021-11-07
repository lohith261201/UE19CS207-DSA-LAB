#include "6b.h"
stack* stack_initialize(int size)
{
  stack *stmpe = (stack *)malloc(sizeof(stack));
  stmpe -> arr = (int *)malloc(size  * sizeof(int));
  stmpe -> top = -1;
  return stmpe;
}

void stack_push(stack *ptr_stack, int key)
{
  ptr_stack -> arr[++(ptr_stack -> top)] = key;
}

void stack_pop(stack *ptr_stack)
{
  (ptr_stack -> top)=(ptr_stack -> top)-1;
}

int stack_is_empty(stack *ptr_stack)
{
  return ((ptr_stack -> top) + 1)? 0:1;
}

int stack_peek(stack *ptr_stack)
{
  return ptr_stack -> arr[ptr_stack -> top];
}

void stack_destroy(stack *ptr_stack)
{
  free(ptr_stack -> arr);
  free(ptr_stack);
}

void convert_infix_to_postfix(const char *source_infix,char *target_postfix)
{
  stack *sck = stack_initialize(strlen(source_infix));
  int i,j=0,m;
  for(i = 0;i<strlen(source_infix);i++)
  {
    if(source_infix[i] == '(' || source_infix[i] == '{' || source_infix[i] == '[')
      stack_push(sck,(source_infix[i] == '(')?5:(source_infix[i] == '{')?6:7);
    else if(source_infix[i] == '*' || source_infix[i] == '/')
    {
      if(stack_is_empty(sck) || stack_peek(sck) > 4 || stack_peek(sck) == 1 || stack_peek(sck) == 2)
        stack_push(sck,(source_infix[i] == '*')?3:4);
      else
      {
        target_postfix[j++] = (stack_peek(sck) == 3)?'*':'/';
        stack_pop(sck);
        stack_push(sck,(source_infix[i] == '*')?3:4);
      }
    }
    else if (source_infix[i] == '+' || source_infix[i] == '-' )
    {
      if(!stack_is_empty(sck) && stack_peek(sck) <= 4)
      {
        target_postfix[j++] = (stack_peek(sck) == 1)?'+':(stack_peek(sck) == 2)?'-':(stack_peek(sck) == 3)?'*':'/';
        stack_pop(sck);
      }
      stack_push(sck,(source_infix[i] == '+')?1:2);
    }
    else if(source_infix[i] == ')' || source_infix[i] == '}' || source_infix[i] == ']')
    {
      m = (source_infix[i] == ')')?5:(source_infix[i] == '}')?6:7;
      while(stack_peek(sck) != m)
      {
        target_postfix[j++] = (stack_peek(sck) == 1)?'+':(stack_peek(sck) == 2)?'-':(stack_peek(sck) == 3)?'*':'/';
        stack_pop(sck);
      }
      stack_pop(sck);
    }
    else
      target_postfix[j++] = source_infix[i];
  }
  while(stack_is_empty(sck) == 0)
  {
    target_postfix[j++] = (stack_peek(sck) == 1)?'+':(stack_peek(sck) == 2)?'-':(stack_peek(sck) == 3)?'*':'/';
    stack_pop(sck);
  }
target_postfix[j]='\0';
}
