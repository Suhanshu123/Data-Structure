#include<stdio.h>
#define max 5
int q[max],front=0,rear=-1;
void main()
{
    int ch=0;
    while(ch<4)
    {
	printf("\nCircular Queue operations\n\n");
	printf("1.insert\n2.delete\n3.display\n4.exit\n");
	printf("Enter your choice:");
	scanf("%d",&ch);
	switch(ch)
	{
	case 1: insert();
	    break;
	case 2: delet();
	    break;
	case 3: display();
	    break;
    }
}
}
insert()
{
    int x;
    if(((front==0)&&(rear==max-1))||((front>0)&&(front==rear+1)))
        printf("que is overflow\n\n");
    else if((rear==max-1)&&front>0)
    {
        printf("Enter value to be inserted\n\n");
        scanf("%d",&x);
        rear=0;
        q[rear]=x;
        printf("%d is inserted\n\n",x);
    }
    else
    {
        printf("Enter value to be inserted\n\n");
        scanf("%d",&x);
        if((front==0&&rear==-1)||(front!=rear+1))
        {
          rear++;
          q[rear]=x;
        }
        printf("%d is inserted\n\n",x);
    }
    printf("rear is at %d\n",rear);
    printf("front is at %d\n",front);
}
delet()
{
    if((front==0)&&(rear==-1))
        printf("que is empty\n\n");
    else if(front==max-1)
    {
        printf("%d is deleted\n\n",q[front]);
        front=0;
    }
    else if((front==rear))
    {
        printf("%d is deleted\n\n",q[front]);
        front=0;
        rear=-1;
    }
    else
    {
        printf("%d is deleted\n\n",q[front]);
        front++;
    }
    printf("front is at %d\n\n",front);
    printf("rear is at %d\n\n",rear);
}

display()
{
    int i,j;
    if(front==0&&rear==-1)
    {
	printf("Queue is underflow\n");
    }
    else if(front>rear)
    {
        for(j=front;j<=max-1;j++)
	    printf("\t%d",q[j]);
	for(i=0;i<=rear;i++)
	    printf("\t%d",q[i]);

    }
    else
    {
        for(i=front;i<=rear;i++)
        {
            printf("\t%d",q[i]);
        }
    }
    getch();
}











