#include <string.h>
#include <ctype.h>

#include "bst.c"


main()
{
	char ch;
	int x;
	tree *bst=0;
	/*
	for(i=0;i<5;i++)
		insertbst(&bst,rand()%100);
	
	delnode(&bst,34);
	
	preorder(bst); printf("\b\b \n");
	inorder(bst); printf("\b\b \n");
	postorder(bst); printf("\b\b \n");
	
	
	printf("%d\n",min(bst)->d);
	
	//printf("%d\n",search(bst,34)->d);
	*/
	
	init(&bst);
	
	printf("\nEnter :-\n\
1) I to insert\n\
2) D to delete\n\
3.a) R for preorder traverse \n\
3.b) N for inorder traverse \n\
3.c) O for postorder traverse \n\
4) F to find an element\n\
5) ctrl+c or Q to exit\n\
");
	
	
	
	while((ch=toupper(getchar())) != 'Q')
	{
		
		
		
		switch(ch)
		{
			
			case 'I' :
						 printf("Enter a no.");
						 scanf("%d",&x);
						 insertbst(&bst,x);
						 break;
						 
			case 'D' :
						 printf("Enter a no.");
						 scanf("%d",&x);
						 delnode(&bst,x);
						 break;
						 
						 
						 
			case 'R' :
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
			
			
			
			
			
		}
	
		redraw();
	}
	
	
}
