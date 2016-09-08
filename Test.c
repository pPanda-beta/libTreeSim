#include <stdio.h>
#include <stdlib.h>


#define item int

typedef struct bintree
{
	item d;
	struct bintree *l;
	struct bintree *r;
} tree;


#include "binTreeSim.h"





void insertBST(tree **rootp,item z)
{
 if(*rootp)
 {
 	if(z<(*rootp)->d)
 		insertBST(&((*rootp)->l),z);
 	else
 		insertBST(&((*rootp)->r),z);
 	
 }
 else
 {
 	 *rootp=(tree *)malloc(sizeof(tree));
 	 (*rootp)->d=z;
 	 (*rootp)->l=(*rootp)->r=NULL;
 	 
 }
 
}




main()
{
	int i;
	tree *bst=NULL;
	insertBST(&bst,50);


	init(&bst);

	printf("All ok__press any key to insert random nos...\n");
	 //setopfmt("%5d");
  //	setopfmt("%0x");
	
	while(getch()!=27)
	{
		redraw();
		insertBST(&bst,rand()%100);
	}
  getchar();
}
