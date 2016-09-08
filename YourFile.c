#include <string.h>
#include <ctype.h>

#include "bintreesim.h"




//#include "bst.c"
#include "avl.c"



main()
{
	char ch;
	int x;
	tree *bst=0;

	init(&bst);

	printf("\nEnter :-\n\
1) I to insert\n\
2) D to delete\n\
3.a) R for preorder traverse \n\
3.b) N for inorder traverse \n\
3.c) O for postorder traverse \n\
4) F to find an element\n\
5) ctrl+c or Q to exit\n\
6) L to rotate left around root\n\
7) R to rotate right around root\n\
8) B to balance root\n\
");



	while((ch=toupper(getch())) != 'Q')
	{




		switch(ch)
		{

			case 'I' :
				printf("Enter a no.");
				scanf("%d",&x);
				insertavl(&bst,x);
				break;

			case 'D' :
				printf("Enter a no. to delete : ");
				scanf("%d",&x);
				delnodeavl(&bst,x);
				printf("Deleted\n");
				break;



			case 'P' :
				printf("The preorder traversal is :- ");
				preorder(bst);
				printf("\b\b \n");
				break;

			case 'N' :
				printf("The inorder traversal is :- ");
				inorder(bst);
				printf("\b\b \n");
				break;

			case 'O' :
				printf("The postorder traversal is :- ");
				postorder(bst);
				printf("\b\b \n");
				break;



			case 'F' :
				printf("Enter a no.");
				scanf("%d",&x);
				printf("The element is %s found\n",search(bst,x)?"\b":"not");
				break;

			case 'L' :
				lrotate(&bst);
				break;

			case 'R' :
				rrotate(&bst);
				break;

			case 'B' :
				bnode(&bst);
				break;


		}

		redraw();
	}


}
