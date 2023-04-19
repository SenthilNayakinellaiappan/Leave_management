#include<stdio.h>  
#include<stdlib.h>
#include<string.h>
#define max 5
void insert();
void delete();
void deletebeg();
void medical();
void casual();
void display();
struct leave
{ 
    int data;
	char name[20];
	char dept[20];
	int days; 
	struct leave*next;
	
}e,*head,*newnode,*temp,*nextnode;
int count =0;
int main()
{
head=0;
int choice;
do
{
printf("\nenter your choice\n");
printf("1.APPLY LEAVE\n");
printf("2.TO VIEW NO OF PERSONS APPLIED LEAVE\n");
printf("3.CANCEL LEAVE");
printf("4.EXIT\n");
scanf("%d",&choice);
switch(choice)
{
	case 1:
	insert();
	break;
	
	case 2:
	display();
	break;
	
	case 3:
	delete();
	break;
       
        case 4:
        exit(0);
        break;
}
}while(choice<=5);
return 0;
}

void insert()
{
	                newnode=(struct leave*)malloc(sizeof(struct leave));
	                printf("\nEnter name");
	                scanf("%s",e.name);
	                strcpy(newnode->name,e.name);
	                printf("\nenter department");
	                scanf("%s",e.dept);
	                strcpy(newnode->dept,e.dept);
	                printf("\nno of days yo u want leave");
	                scanf("%d", &e.days);
	                newnode->days=e.days;
	                newnode->next=0;
	                if(head==0)
	                {
	                head=temp=newnode;
	                count++;
	                temp->data=count;
	                }
	                else
	                {
	                 temp->next=newnode;
	                 temp =newnode;
	                 count++;
	                 temp->data=count;
					}
					printf("What will be the reason for your leave");
	                int r1;
	                printf("\npress 1 for casual leave");
	                printf("\npress 2 for medical leave");
	                scanf("%d",&r1);
	                switch(r1)
	                {
	                	case 1:
	                	casual();
	                	break;
	                	
	                	case 2:
	                	medical();
	                	break;
	                		
					}
					printf("\nyour application no is %d",count);
                                        FILE *fp;
                                        fp=fopen("applyleave","a+");
                                        fprintf(fp,"%s %s %d\n",e.name,e.dept,e.days);
                                        fclose(fp); 
	                
}
void delete()
{
printf("\nenter your name");
scanf("%s",e.name);
printf("\nenter your leave application no");
int pos;
scanf("%d",&pos);
if(pos== 1)
{
deletebeg();
}
else
{
	int i=1;
	temp=head;
	while(i<pos-1)
	{
		temp=temp->next;
		i++;	
	}

nextnode=temp->next;
temp->next=nextnode->next;
free(nextnode);
}
 
}
void deletebeg()
{
	temp=head;
	head=head->next;
	free(temp);
}
void display()
{
    temp=head;
	while(temp!=0)
	{
	printf("%s\t%s\t%d\t\n ", temp->name,temp->dept,temp->days);
	temp=temp->next;
    }
}
void casual()
{
int choose;
if(e.days>=3)
{
	printf("\nyou are taking leave beyond limit ");
	printf("\n1.would you like to continue with loss of pay");
        scanf("%d",&choose);
        if(choose)
        {
         FILE *fptr;
         fptr=fopen("lossofpay","a+");
         fprintf(fptr,"%s %d\n",e.name,e.days);
         fclose(fptr);
        }

}
else
{
printf("your application is successfully submitted");
}	
}
void medical()
{
printf("your leave is recorded");
}
