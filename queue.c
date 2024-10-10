#include<stdio.h>
int Q[50],size,element,front=-1,rear=-1,i,choice;
void enqueue();
void dequeue();
void display();
int main()
{
	printf("\nQUEUE");
	printf("\nEnter the size of the queue");
	scanf("%d",&size);
	while(choice!=4)
	{
	printf("\n\t1.Enqueue\n\t2.Dequeue\n\t3.Display\n\t4.Exit");
	
		printf("\nEnter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				enqueue();
				break;
			case 2:
			  	dequeue();
			  	break;
			case 3:
				display();
				break;
			case 4:
				break;
			default:
				printf("\nInvalid choice");
		}
	}
return 0;
}
void enqueue()
{
	printf("Enter the element to insert:");
	scanf("%d",&element);
	if(rear==size-1)
	{
		printf("\nQueue overflow");
		
	}
	else if(front==-1&&rear==-1)
	{
		front=0;
		rear=0;
		Q[rear]=element;
	}
	else
	{
		rear++;
		Q[rear]=element;
	}
}
void dequeue()
{
	if(front==-1&&rear==-1)
	{
		printf("Queue underflow");
	}
	else if(front==rear)
	{
		front=-1;
		rear=-1;
	}
	else
	{
		front++;
	}
}
void display()
{
	if(front==-1&&rear==-1)
	{
		printf("\nQueue underflow");
	}
	else
	{
		printf("\n");
		for(i=front;i<=rear;i++)
		{
			printf("%d\t",Q[i]);
		}
	}
}
