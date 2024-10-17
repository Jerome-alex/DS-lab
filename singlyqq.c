#include<stdio.h>
#include<stdlib.h>
int c;
void enqueue();
void dequeue();
void display();
struct node
{
	int data;
	struct node *next;
}*front=NULL,*last=NULL,*temp=NULL,*newnode;
int main()
{
	while(c!=4)
	{
	printf("please select the choice\n\tMENU\n\n1.enqueue\n2.dequeue\n3.display\n4.exit\n");
	printf("Enter the option:");
	scanf("%d",&c);

	
		switch(c)
		{
			case 1:enqueue();
				break;
			case 2:dequeue();
				break;
			case 3:display();
				break;
			case 4:break;
		}
	}
return 0;
}
void enqueue()
{
	int v;
	printf("Enter the element to be inserted:");
	scanf("%d",&v);
	newnode = (struct node*)malloc(sizeof(struct node));
	newnode->data=v;
	newnode->next=NULL;
	if(front==NULL)
	{
		front=last=newnode;
	}
	else
	{
		newnode->next=front;
		front=newnode;
	}
}
void dequeue()
{
	if(front==NULL)
	{
		printf("LIST IS EMPTY...\n");
	}
	else
	{
		temp=front;
		while(temp->next->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=NULL;  
		last=temp;                                                                        
		printf("\nElement deleted..\n");
		
	}
}
void display()
{
	if(front==NULL)
	{
		printf("LIST IS EMPTY..\n");
	}
	else
	{
		temp=front;
		while(temp!=NULL)
		{
			printf("%d\n\n",temp->data);
			temp=temp->next;
		}
		
	}
}

