#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#define ENTER 13
#define MAX 200
	
void f1()				
{
    int selection=0;
	char str[MAX],ch;
	 FILE * fptr; 
	 int i=0;
	 
	 	    printf("Please input content(ex:�Z��/�m�W/�Ǹ�/�p���覡/�ɶ�....) \n");
         fptr=fopen("C:/Users/jeffy/OneDrive/�ୱ/output.txt","a");
			while((ch=getche())!=ENTER&&i<MAX)
			str[i++]=ch;
			putc('\n',fptr);
			fwrite(str,sizeof(char),i,fptr);
			fclose(fptr);
		while(selection != 4)											
	{
	
		printf("1:�T�{�x�s\n2:delete content\n3:���s��J\n4:end\n");
		scanf("%d",&selection);			
		if(selection ==1)
		{
		  break;	     
        }
   
		else if(selection ==2)
		{   
		   printf("press enter to delete\n");
		
		   
		   char	str[MAX]="N/A";
		   fptr=fopen("C:/Users/jeffy/OneDrive/�ୱ/output.txt","w");
		 while((ch=getche())!=ENTER&&i<MAX)
		  str[i++]=ch;
		  putc('\n',fptr);
		  fwrite(str,sizeof(char),i,fptr);
		  fclose(fptr);		
		  	
		}
		else if(selection ==3)
		{
	   	     printf("Please input content(ex:�Z��/�m�W/�Ǹ�/�p���覡/�ɶ�....) or selection \n");
         fptr=fopen("C:/Users/jeffy/OneDrive/�ୱ/output.txt","w");
			while((ch=getche())!=ENTER&&i<MAX)
			str[i++]=ch;
			putc('\n',fptr);
			fwrite(str,sizeof(char),i,fptr);
			fclose(fptr);
		}	
		else if(selection ==4)
		{
			break;
		}
	
	    else 
		{
			printf("error!\nPlease input  number  1~3...\nPlease restart program again\n ");
			break;			
		}
	} 
	
} 
	


int main(){
	
	
	int selection;
	printf("Please choose a selection...\n");	
	printf("\n 1: input content,\n -1:leave \n ");

	scanf("%d",&selection);
		
	switch(selection){
		
		case 1:	
		       f1();		        
		       break;
	
		case -1:printf("leave"); 
		        break;
		
		default: printf("invalid input");
		         break;
				        
	}

	 
	
	
	return 0;
}
