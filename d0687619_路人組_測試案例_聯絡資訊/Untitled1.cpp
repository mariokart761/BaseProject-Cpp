#include<stdio.h>
#include<stdlib.h>
#include<string.h>
	
void f1()				
{
    int selection=0;
	char content[1000]="N/A";


	
	
		while(selection != 4 )											// make a decision //
	{
		
	    printf("Please input content(ex:�Z��/�m�W/�Ǹ�/�p���覡/�ɶ�....) or selection \n�p����T:\n");
		
	    scanf("%s",content);
		printf("1:�T�{�x�s\n2:delete content\n3:���s��J\n4:end\n");
		scanf("%d",&selection);
				
		if(selection ==1)
		{
			printf("save success!\n");
			break;
		}
		else if(selection ==2)
		{
		  char content[1000]="N/A";
		  printf("�p����T: \n");
		  printf("%s\n",content);
		  printf("delete success!\n");
		  break;	
		}
		else if(selection ==3)
		{
	   	  
		}
		else if(selection ==4)
		{
		  printf("�p����T:\nN/A\n");
		  break;
		}
	    else
		{
			printf("Please input  number  1~4...\n");
		}
	} 
	
} 
	


int main(){
	
	
	int selection;
	printf("Please choose a selection...\n");	
	printf("\n 1: input content,\n -1:cancel input \n ");

	scanf("%d",&selection);
		
	switch(selection){
		
		case 1:	
		       f1();		        
		       break;
	
		case -1:printf("cancel input \n"); 
		        break;
		
		default: printf("invalid input");
		         break;
				        
	}

	 
	
	
	return 0;
}
