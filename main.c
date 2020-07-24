#define _GNU_SOURCE
#include <stdio.h>
#include <string.h>

#include <stdlib.h>
char rev[150];
	char buffer[33];
char* string_reverse(char st[])
{
	int i,j,len;
	char ch;

	j = len = strlen(st) - 1;
	i = 0;

	while(i < j) {
		ch = st[j];
		st[j] = st[i];
		st[i] = ch;
		i++;
		j--;
	}
	return st;
} 
char* pelsum(char *line,int read)
{
	int j,i,count=0,k,l,no=0;
	char *temp;
	for(i=0;i<read;i++)
	{
		if(line[i] != ' ' || line[i] != '\n')
		{
			for(j=i;j<read;j++)
			{
				if(line[j] == ' ' || line[j] == '\n')
					break;
				else
					no=no*10+(line[j]-48);
			}
		}

		for(k=i,l=j-1;;)
		{
			if(line[k] != line[l])
			{
				no=0;
				break;
			}
			else if(k >= l)
			{
				count+=no;
				no=0;
				break;
			}
			else
			{
				k = k + 1;
				l = l - 1;

				continue;
			}
		}

		i = j;
	}
	printf("sum=%d",count);
	int r,a=0;
	for(j=0,i=count;i>0;i=i/10,j++)
	{
		r=i%10;
		buffer[j]=r+48;
	}
	buffer[j]='\0';
					string_reverse(buffer);
//	printf("\nbuffer=%s\n",buffer);

	for(i=0;i<read;i++)
	{
		if(line[i] != ' ' || line[i] != '\n')
		{
			for(j=i;j<read;j++)
			{
				rev[a++]=line[j];
				if(line[j] == ' ' || line[j] == '\n')
					break;
			}
		}
		for(k=i,l=j-1;;)
		{
			if(line[k] != line[l])
			{
				break;
			}
			else if(k >= l)
			{
				a=i;
				for(k=i,l=0;buffer[l];k++)
				{
				rev[a++]=buffer[l++];
				}
				rev[a++]=line[j];
				
				break;
				break;
			}
			else
			{

				k = k + 1;
				l = l - 1;

				continue;
			}
		}

		i = j;
	}
	return rev;
}
char* reverse(char *str) 
{ // defining the function
	static int z= 0;
	if(*str)
	{
		reverse(str+1);
		rev[z++] = *str;
	}
	else
	{
		z=0;
		return rev;
	}
}
int countpel(char *line,int read)
{
	int j,i,count=0,k,l;
	for(i=0;i<read;i++)
	{
		if(line[i] != ' ' || line[i] != '\n')
		{
			for(j=i;j<read;j++)
			{
				if(line[j] == ' ' || line[j] == '\n')
					break;
			}
		}

		for(k=i,l=j-1;;)
		{
			if(line[k] != line[l])
				break;
			else if(k >= l)
			{
				count = count + 1;
				break;
			}
			else
			{
				k = k + 1;
				l = l - 1;
				continue;
			}
		}

		i = j;
	}
	return count;
}

int main(void)
{
	FILE * fp;
	char *rev1; 
	char * line = NULL;
	size_t len = 0;
	ssize_t read;
	int count,i,j;
	char rev2[100]="";

	fp = fopen("data", "r");
	if (fp == NULL)
	{
		perror("fopen");
	}
	else
	{
		while ((read = getline(&line, &len, fp)) != -1) 
		{
			printf("%s ", line);

			count=countpel(line,read);
			printf("\bpalndrom no=%d:",count);
			if(count==1 || count==4)
			{

				rev1 = reverse(line);
					printf("   so string:%s\n",rev1);
				memset(rev, 0, 150); 
			}
			else if(count==2 || count==5)
			{
				memset(rev, 0, 150); 
					rev1 = pelsum(line,read);
					printf("   so string:%s",rev1);
				memset(rev, 0, 150); 
			}
			else if(count==3 || count==7)
			{
				for(i = 0; i < (read-1); i++)
				{

					for(j = 0; i < (read-1) && line[i]!=' '; ++i,++j) {
						rev[j] = line[i];
					}

					rev[j] = '\0';

					string_reverse(rev);

					strcat(rev2, rev);
					strcat(rev2, " ");
				}
					printf("   so string:%s\n",rev2);
				memset(rev2, 0, 100); 
			}
		}
		fclose(fp);
	}
	if (line)
		free(line);
}
