#include<stdio.h> 
#include<string.h> 
#include<stdlib.h> 
typedef unsigned char U8;
typedef unsigned short U16;

void findIP_status(char str[]) 
{
	U16 len=0;
    U8  oct[4]={0},cnt=0,cnt1=0,i,buf[5];
 
    len=strlen(str);
    for(i=0;i<len;i++)
    {
        if(str[i]!='.'){
            buf[cnt++] =str[i];
        }
        if(str[i]=='.' || i==len-1){
            buf[cnt]='\0';
            cnt=0;
            oct[cnt1++]=atoi(buf);
        }
    }
    if(oct[0]==10 || oct[0]==192 || oct[0]==172)
    {
    	if(oct[0]==10)
    	{
    		if((oct[1]>=0 && oct[1]<=255) && (oct[2]>=0 && oct[2]<=255) && (oct[3]>=0 && oct[3]<=255))

    	{
    		printf("Private IP Adress\n");
    	}
    else
    {
    	printf("Public IP Adress\n");
    }	
    	}

    	else if(oct[0]==192)
    	{
    		if(oct[1]==168 && (oct[2]>=0 && oct[2]<=255) && (oct[3]>=0 && oct[3]<=255))
    			{
    				printf("Private IP Adress\n");
    			}
    else
    {
    	printf("Public IP Adress\n");
    }	
    	}

    	else if(oct[0]==172)
    	{
    		if((oct[1]>=16 && oct[1]<=31) && (oct[2]>=0 && oct[2]<=255) && (oct[3]>=0 && oct[3]<=255))
    			{
    				printf("Private IP Adress\n");
    			}
    else
    {
    	printf("Public IP Adress\n");
    }	
    	}

    }
    else
    {
    	printf("Public IP Adress\n");
    }
} 
void main() 
{ 
	char str[100],ipClass;
	printf("Enter IP Address (xxx.xxx.xxx.xxx format): ");
    scanf("%s",str);
	findIP_status(str); 

}
