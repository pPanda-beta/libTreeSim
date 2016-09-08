#include <stdio.h>


append(char *fn,char *an,FILE *op)
{
	FILE *ip=fopen(fn,"rb");

	long long d;
	int i=0;

	fprintf(op,"\nlong long %s[]=\n{",an);


	while(!feof(ip))
	{
		fread(&d,sizeof(d),1,ip);
		fprintf(op,"\n%lluULL,",d);
	}

	fseek(op,-1,1);
	fprintf(op,"\n}  ;\n\n");

	fclose(ip);
}




main(int n,char **fnames)
{
	FILE *dt=fopen("../libPrj/imgData.db","w");

	if(n>1)
	{
		char buf[10];
		while(n--)
		{
			;
		}
	}
	else
	{

		append("logo.jpg","lgd",dt);
		append("Title.png","ttd",dt);
		append("footer.png","ftd",dt);
		append("pPanda_bkgd.jpg","bkd",dt);
	}
}





