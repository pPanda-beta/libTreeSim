#include <stdio.h>


typedef struct bintree
{
	int v;
	struct bintree *l;
	struct bintree *r;
} tree;




#define item tree*
#include "st_Llist.c"





postorder(tree *rt)
{
	if(!rt)	return;

	postorder(rt->l);
	postorder(rt->r);
	printf("%c",rt->v);

}


eval(tree *rt)
{
	if(isalnum(rt->v))
		return rt->v -'0' ;
	else switch(rt->v)
		{
				/*
				#define	_op(c) case 'c' :	return (eval(rt->l) c eval(rt->r))

				_op(+);
				_op(-);
				_op(*);
				_op(/);
					*/

			case '+' :
				return eval(rt->l)+eval(rt->r)	;
			case '-' :
				return eval(rt->l)-eval(rt->r)	;
			case '*' :
				return eval(rt->l)*eval(rt->r)	;
			case '/' :
				return eval(rt->l)/eval(rt->r)	;

		}



}




pr(stack st)
{
	while(st)
	{
		postorder(st->d);
		printf("   XX\n",st->d->v);
		st=st->n;
	}

	printf("----\n");
}






insert(stack *trp,stack *opp)
{
	tree *o,*o1,*o2	;

	o=pop(opp);

	o->r=pop(trp);
	o->l=pop(trp);

	push(trp,o);
}



int prec(char op)
{
	char *oplst[]= {"(","+-","*/"};
	int i;

	for(i=0; i < sizeof(oplst)/sizeof(*oplst);  i++)
		if(strchr(oplst[i],op))   return i;

	return -1;
}




tree *in2post(char *ip)
{
	stack tr=0,op=0,x;
	tree *t;

	while(*ip)
	{
		t=malloc(sizeof(tree));
		t->v=*ip;
		t->l=t->r=0;

		if(isalnum(*ip))
			push(&tr,t);
		else switch(*ip)
			{
				case '(' :
					push(&op,t);
					break;

				case ')' :
					while(peak(&op)->v!='(' )
						insert(&tr,&op);
					pop(&op);
					break;
				default  :
					while(!isempty(&op) && prec(*ip) <= prec(peak(&op)->v))
						insert(&tr,&op);
					push(&op,t);
					break;

			}

		ip++;
	}

//	pr(tr);	pr(op);

	while(!isempty(&op))
		insert(&tr,&op);


	return pop(&tr);
}


main()
{
	tree *expt=0;
	init(&expt);
	setopfmt("%c");
	char form[80];


	printf("Enter infix form : ");
	fgets(form,sizeof(form),stdin);
//gets(form);

	form[strlen(form)-1]=0;
	/*  (5+5*8)*9  */

	printf("The postfix form is .\n");
	postorder(expt=in2post(form));

	redraw();

	printf("\nThe answer is %d.\n",eval(expt));

	getchar();
}
