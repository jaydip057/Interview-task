
#include<stdio.h>
#include<stdlib.h>
#define CAR_IN '1'
#define CAR_OUT '2'
#define CAR_STATUS '3'
#define EXIT '4'
typedef char U8;
typedef int S32;
void car_parking_systeam_carin(U8 **park_space);
void car_parking_systeam_carout(U8 **park_space);
void car_parking_systeam_carstatus(U8 **park_space);
void car_parking_systeam_status();


S32 parking_row,parking_collom,parking_count=0;
S32 main()
{
	U8 **park_space,temp_1,temp_2;
	U8 temp_3;
	car_parking_systeam_status();
	park_space=(U8**)malloc(sizeof(U8*)*parking_row);
	if(park_space<0)
	{
		perror("malloc");
		return 0;
	}

	for(temp_1=0;temp_1<parking_row;temp_1++)
	{
		park_space[temp_1]=(U8 *)malloc(sizeof(U8)*parking_collom);
		if(park_space[temp_1]<0)
		{
			perror("malloc");
			return 0;
		}
	}
	for(temp_1=0;temp_1<parking_row;temp_1++)
		for(temp_2=0;temp_2<parking_collom;temp_2++)
			park_space[temp_1][temp_2]='0';
		do
			{
				printf("\t\t\t1)car in\n");
				printf("\t\t\t2)car out\n");
				printf("\t\t\t3)parking status\n");
				printf("\t\t\t4)exit\n");
				printf("select one option\n");
				scanf(" %c",&temp_3);
				switch(temp_3)
				{
					case CAR_IN : car_parking_systeam_carin(park_space);
						      break;
					case CAR_OUT : car_parking_systeam_carout(park_space);
						       break;
					case CAR_STATUS: car_parking_systeam_carstatus(park_space);
							 break;
					case EXIT:
							 break;
					default:
							 printf("Enter the valid option or press q for exit\n");
							 break;
				}
			}while(temp_3!=EXIT);
	return 0;
}
void car_parking_systeam_carin(U8 **park_space)
{
	if(parking_count==parking_row*parking_collom)
	{
		printf("parking is full NO SPACE\n");
	}
	else
	{
		S32 temp_1,temp_2;
		printf("Enter the row and colom where you want park the car\n");
		scanf("%d%d",&temp_1,&temp_2);
		if(temp_1 < parking_row && temp_2 < parking_collom)
		{
			if(park_space[temp_1][temp_2]=='0')
			{
				park_space[temp_1][temp_2]='*';
				parking_count++;
			}
			else
			{
				printf("try another location that loaction is already allocated \n");
			}
		}else
		{
			if(temp_1>parking_row)
				printf("usage:plase enter valid row\n");
			else
				printf("usage:plase enter valid col\n");
		}
	}
	return;
}
void car_parking_systeam_carout(U8 **park_space)
{
	if(parking_count==0)
	{
		printf("whole parking area is empty\n");
	}
	else
	{
		S32 temp_1,temp_2;
		printf("Enter the row and colom where you want exit the car from parking area\n");
		scanf("%d%d",&temp_1,&temp_2);
		if(temp_1 < parking_row && temp_2 < parking_collom)
		{
			if(park_space[temp_1][temp_2]=='*')
			{
				park_space[temp_1][temp_2]='0';
				parking_count--;
			}
			else
			{
				printf("loaction is already vacant\n");
			}
		}
		else
		{
			if(temp_1>parking_row)
				printf("usage:plase enter valid row\n");
			else
				printf("usage:plase enter valid col\n");
		}
	}
	return;
}
void car_parking_systeam_carstatus(U8 **park_space)
{
	S32 temp_1,temp_2;
	printf(" ");
	for(temp_1=0;temp_1<parking_collom;temp_1++)printf("% d ",temp_1);
	printf("\n");
	for(temp_1=0;temp_1<parking_row;temp_1++)
	{
		printf("%d",temp_1);
		for(temp_2=0;temp_2<parking_collom;temp_2++)
			printf(" %c ",park_space[temp_1][temp_2]);
		printf("\n");
	}
}
void car_parking_systeam_status()
{
	printf("enter the row and collom for parking space\n");
	scanf("%d%d",&parking_row,&parking_collom);
}
