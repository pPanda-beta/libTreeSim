#include <stdio.h>
#include <stdlib.h>

#define item int

typedef struct bintree
{
	int d;
	struct bintree *l;
	struct bintree *r;
} tree;




void insertbst(tree **rtp,item z)
{
	if(*rtp)
	{
		if(z<(*rtp)->d)
			insertbst( &((*rtp)->l),z);
		else
			insertbst( &((*rtp)->r),z);

	}
	else
	{
		*rtp=(tree *)malloc(sizeof(tree));
		(*rtp)->d=z;
		(*rtp)->l=(*rtp)->r=NULL;

	}

}


void insertbstnonRec(tree **rtp,item z)
{
	while(*rtp)
	{
		if(z<(*rtp)->d)
			rtp=&((*rtp)->l);
		else
			rtp=&((*rtp)->r);
	}

	*rtp=(tree *)malloc(sizeof(tree));
	(*rtp)->d=z;
	(*rtp)->l=(*rtp)->r=NULL;
}



tree *search(tree *rt,item key)
{
	while(rt && rt->d!=key)
	{
		if(key < rt->d)
			rt=rt->l;
		else
			rt=rt->r;
	}

	return rt;
}



tree *min(tree *rt)
{
	if(rt)
		while(rt->l)
			rt=rt->l;
	return rt;
}

int depth(tree *rt)
{
	int hl,hr;

	if(rt)
	{
		hl=depth(rt->l);
		hr=depth(rt->r);

		return 1+ (hl>hr? hl :hr) ;

	}
	else return 0;

}



/*


i 10
i 8
i 14
i 11
i 12
i 15
d 10

*/




delnode(tree **rtp,item z)
{
	if(!(rtp || *rtp)) return;

	tree *t;
	if(z < (*rtp)->d)
		delnode( &((*rtp)->l) , z);
	else if(z > (*rtp)->d)
		delnode( &((*rtp)->r) , z);
	else
	{
		if((*rtp)->l && (*rtp)->r)
		{
			t=min((*rtp)->r);

			(*rtp)->d=t->d	;
			delnode(&((*rtp)->r),t->d);
		}
		else
		{
			t=*rtp;
			if((*rtp)->l)
				*rtp=(*rtp)->l;
			else
				*rtp=(*rtp)->r ;

			free(t);
		}

	}
}





delnodenonRec(tree **rtp,item z)
{
	tree *t;
	while(*rtp)
	{
		while(z != (*rtp)->d)
		{
			if(z < (*rtp)->d)
				rtp = &((*rtp)->l);
			else
				rtp = &((*rtp)->r);
		}

		if((*rtp)->l && (*rtp)->r)
		{
			t=min((*rtp)->r);
			(*rtp)->d=t->d	;

			rtp = &((*rtp)->r);
			z=t->d;
		}
		else
		{
			printf("Else part\n");
			t=*rtp;
			if((*rtp)->l)
				*rtp=(*rtp)->l;
			else
				*rtp=(*rtp)->r ;

			free(t);
			return ;
		}
	}

}








//traversal



preorder(tree *rt)
{
	if(!rt)	return;

	printf("%2d, ",rt->d);
	preorder(rt->l);
	preorder(rt->r);
}




inorder(tree *rt)
{
	if(!rt)	return;

	inorder(rt->l);
	printf("%2d, ",rt->d);
	inorder(rt->r);
}




postorder(tree *rt)
{
	if(!rt)	return;

	postorder(rt->l);
	postorder(rt->r);
	printf("%2d, ",rt->d);
}










