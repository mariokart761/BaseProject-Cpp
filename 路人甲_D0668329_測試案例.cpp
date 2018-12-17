#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void f1()				// invite function //
{
	char sid[8];
	char searching[10];
	int selection = 0;
	
	printf("Please input your SID...\n");									// sign in your student ID //
	scanf("%s",&sid);
	
	while(selection != 3)													// make a decision //
	{
		printf("Please input searching people name or SID...\n");
		scanf("%s",&searching);
	 
		printf("1.send a invite\n2.research again\n3.return to menu\n");
		scanf("%d",&selection);
	
		if(selection == 1)
		{
			printf("sending a invite success !!!\n");
			break;
		}
		else if(selection == 2)
		{
			
		}
		else if(selection ==3)
		{
			break;
		}
		else
		{
			printf("Please input 1~2 number ...\n");
		}
	}
}

void f2()				//  create group  //
{
	char sid[8];
	char name[10];
	
	printf("Please input your SID...\n");							// sign in your student ID //
	scanf("%s",&sid);
	
	printf("Please input a name of group...\n");
	scanf("%s",&name);
	
	printf("You are already create the group !!!\n");
}

void f3()				//  apply to a group  //
{
	char sid[8];
	char name[10];
	int selection = 0;
	
	printf("Please input your SID...\n");							// sign in your student ID //
	scanf("%s",&sid);
	
	while(selection != 3 )											// make a decision //
	{
		
		printf("Please input the name of group you wanna to join in...\n");
		scanf("%s",&name);
		
		printf("1.sending a application\n2.research again\n3.return to menu\n");
		scanf("%d",&selection);
		
		if(selection ==1)
		{
			printf("You are already sending the application , please waiting the reply!!!\n");
			break;
		}
		else if(selection ==2)
		{
			
		}
		else if(selection ==3)
		{
			break;
		}
		else
		{
			printf("Please input 1~3 number ...\n");
		}
	}
}

void f4()				//  drop out to a group  //
{
	char sid[8];
	char name[10];
	int selection =0;
	
	printf("Please input your SID...\n");									// sign in your student ID //
	scanf("%s",&sid);
	
	while(selection != 3)													// make a decision //
	{
		printf("Please input the name of group you wanna to drop out...\n");
		scanf("%s",&sid);
		
		printf("Are you sure you want to drop out this group?\n1.Yes\n2.No\n");
		scanf("%d",&selection);
		
		if(selection ==1)
		{
			printf("You are already drop out this group !!!\n");
			break;
		}
		else if(selection ==2)
		{
			break;
		}
		else
		{
			printf("Please input 1~2 number\n");
		}
	}
} 

int main()
{
	int input = 100;
	
	do
	{
		printf("Please choose a selection...\n1.Invite people\n2.Create a group\n3.Apply to a group\n4.Drop out to a group\n0.Exit\n");		// choosing a selection //
		scanf("%d",&input);
		
		if(input == 1)
		{
			f1();
		}
		if(input == 2)
		{
			f2();
		}
		if(input == 3)
		{
			f3();
		}
		if(input == 4)
		{
			f4();
		}
		
	}while(input != 0);					// exit the program //
	
	return 0;
} 
