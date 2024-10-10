#include<stdio.h>
#include<stdlib.h>
int Q[50],size,choice,element,i,front=-1,rear=-1;
void enqueue();
void dequeue();
void display();
int main()
{
	printf("Enter the size of the queue:");
	scanf("%d",&size);
	while(choice!=4)
	{
		printf("\n\tQUEUE OPERATIONS\n\t1.Enqueue\n\t2.Dequeue\n\t3.Display\n\t4.Exit");
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
				printf("\n\tExit point");
				break;
			default:
				printf("Invalid choice!");
		}
	}
return 0;
}
void enqueue()
{
	printf("\nEnter the element to insert:");
	scanf("%d",&element);
	if(front==-1&&rear==-1)
	{
		front=0;
		rear=0;
		Q[rear]=element;	
	}
	else if(((rear+1)%size)==front)
	{
		printf("\nQueue overflow");	
	}
	else
	{
		rear=(rear+1)%size;
		Q[rear]=element;
	}
		printf("\nElement inserted");
}
void dequeue()
{
	int element;
	if(front==-1&&rear==-1)
	{
		printf("\nQueue underflow");
	}
	else if(front==rear)
	{
		//element=Q[front];
		//front=rear-1;	
		front=-1;
		rear=-1;
		printf("\nElement deleted");
	}
	else
	{
		//element=Q[front];
		front=(front+1)%size;
		printf("\nElement deleted");
	}
}
void display()
{
	//int i=front;
	int i,j;
	printf("\nElements in queue are:");
	if((front==-1)&&(rear==-1))
	{
		printf("\nQueue is empty");
	}
	if(front>rear)
	{
		for(i=front;i<size;i++)
			printf("\t %d",Q[i]);
		for(j=0;j<=rear;j++)
			printf("\t%d",Q[j]);		
	}
	else
	{
		//printf("\nElements in queue are:");
		//while(i<=rear)
		//{
			//printf("\t %d",Q[i]);
			//if(i==rear)break;
			//i=(i+1)%size;
		//}
		for(i=front;i<=rear;i++)
			printf("\t%d",Q[i]);
	}
	printf("\n");
}
