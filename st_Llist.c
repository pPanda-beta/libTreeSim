#include <stdlib.h>

#ifndef item
#define item int
#endif

struct llist
{
   item d;
   struct llist *n;
};

typedef struct llist* stack ;






initLst(stack *s)
{
	*s=NULL;
}



int isfull(stack *s)
{
 return NULL;
}

int isempty(stack *s)
{
 return !(*s);
}


push(stack *s,item v)
{
 stack t=malloc(sizeof(*t));
 
 t->d=v;
 t->n=*s;
 
 *s=t;
}


item pop(stack *s)
{
 if(!isempty(s))
 {
  stack	t=*s;
  item z=t->d;	
  
  *s=(*s)->n;
  free(t);
  return z;
 }
 else
  return 0;
}


item peak(stack *s)
{
 return *s?(*s)->d:0; ;
}

