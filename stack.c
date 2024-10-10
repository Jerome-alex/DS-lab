#include<stdio.h>
int stack[50],choice,n,top,x,i;
void push();
void pop();
void display();
int main()
{ 
	printf("Enter the size of the stack:");
	scanf("%d",&n);
	top=-1;
	while(choice!=4)
	{	
		printf("\n\tSTACK OPERATIONS");
		printf("\n\t1.Push\n\t2.Pop\n\t3.Display\n\t4.Exit");
			printf("\nEnter the choice:");
			scanf("%d",&choice);
			switch(choice)
			{
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4:
				printf("\n\tExit point");
				break;
			default:
				printf("\nInvalid choice");
			}
	}
return 0;
}
void push()
{
	if(top==n-1)
		{
		printf("\nStack is overflow");
		}
		else
		{
		printf("\nEnter a value to be pushed:");
		scanf("%d",&x);
		top++;
		stack[top]=x;
		}
}
void pop()
{
	if(top==-1)
	{
	printf("Stack is underflow");
	}
	else
	{
	printf("\nThe popped element is %d",stack[top]);
	top--;
	}
}
void display()
{
	if(top==-1)
	{
	printf("\nThe stack is empty");
	}
	else
	{
	printf("\nThe elements in stack are\n");
	for(i=0;i<=top;i++)
	{
		printf("\n%d",stack[i]);
	}
	}	
}
