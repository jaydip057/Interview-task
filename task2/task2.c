#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main(int argc,char**argv)
{
	FILE *fp,*fp1;
	char j,c,i,**cp,c1,max,*p,m,ch,n;
	char buff[80];
	int w=0,ch1=0,k;
	if(argc != 2)
	{
		printf("Usage : ./a.out filename\n");
		return;
	}
	fp=fopen(argv[1],"r");
	fp1=fopen("data1","w");
	if(fp==0)
	{
		printf("File is not present\n");
		return;
	}
	//////////////////////////////////////////////////////////////////task1/////////////////////////////////////////////////////////////////////////////////////
	printf("task 1>findout words from source file which contains minimum 1 Capital letter & stored in \"data1\" file.\n");
	while((fscanf(fp,"%s",buff)) != EOF)
	{
		for(m=0;buff[m];m++)
		{
			if((buff[m]>='A')&&(buff[m]<='Z'))
			{
				for(;buff[m];m++);
				buff[m]=' ';
				fputs(buff,fp1);
			}
		}
		memset(buff,0,80);
	}
	fclose(fp1);
	rewind(fp);
	//////////////////////////////////////////////////////////////////task3/////////////////////////////////////////////////////////////////////////////////////
	c1 = max = c = k = 0;
	while((ch = fgetc(fp)) != EOF)
	{
		c1++;
		c++;
		ch1++;
		if(ch==32)
			w++;
		if(ch==10)
		{
			w++;
			k++;
			if(c1>max)
				max=c1;
			c1=0;
		}
	}
	rewind(fp);
	n=k;
	cp = malloc(sizeof(char*)*k);
	for(i=0;i<k;i++)
	{
		cp[i] = malloc(max+1);
	}
	for(i=0;i<k;i++)
	{
		fgets(cp[i],max+1,fp);
	}
	////////////////////////////////////////////////////////////////////////////////////task2////////////////////////////////////////////////////////////////////////
	printf("task 2> file have multiplication of 5 lines, so lines interchange\n");
	c=0;
	c1=4;
	while(n>4)
	{
		for(i=c,m=c1;i<m;i++,m--)
		{
			p=cp[i];
			cp[i]=cp[m];
			cp[m]=p;
		}
		c+=5;
		c1+=5;
		n=n-5;
	}
	printf("task 3>%s file have %d words %d character %d lines..\n",argv[1],w,ch1,k);
	fclose(fp);
	fp = fopen(argv[1],"w");
	for(i=0;i<k;i++)
	{
		fputs(cp[i],fp);
	}
}
