#include<stdio.h>
#define s 5
int rear=-1,front=-1,que[s];
main()
{
	int ch=0;
	while(ch<4)
	{
		printf("\n\t1. Insert\n\t2. Delete\n\t3. Display\n\t4. Exit\n\n\t  Enter your choice : ");
		scanf("%d",&ch);
		switch(ch)
		{
		    case 1:
			ins();
			break;

			case 2:
			del();
			break;

			case 3:
			list();
			break;
		}
	}
}
ins()
{
    int val;
    if(rear==s-1)
        printf("que is full");
    else
    {
        printf("Enter value");
        scanf("%d",&val);
        rear++;
        que[rear]=val;
        printf("%d is inserted",val);
        if(front==-1)
            front=0;

    }

}
del()
{
    if(rear==-1)
        printf("que is empty");
    else
    {
        printf("%d is deleted",que[front]);

        if(rear==front)
            front=rear=-1;
        front++;
    }
}
list()
	{
		int i;
		if(rear==-1)
		{
			printf("\n\n\tqueue is empty");
		}
		else
        {
		printf("\n\n");
		for(i=front;i<=rear;i++)
		{
			printf("%d",que[i]);
		}
		getch();
        }
	}





















