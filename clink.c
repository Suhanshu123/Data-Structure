
/*CIRCULAR LINKED LIST*/
#include<stdio.h>
#include<conio.h>
#include<malloc.h>


typedef struct list
{
	int data;
	struct list *link;
}node;

node *first=NULL,*last=NULL;

display()
{
	node *temp=first;
	if(temp==NULL)
	printf("\nNo data");
	else
	{
		do
		{
			printf("%d\t",temp->data);
			temp=temp->link;
		}while(temp!=first);
	}
}

main()
{
	int  ch;
	void insert();
   void delet();
   void display();
	while(1)
	{

		printf("\n1.Insert\n2.Delete\n3.exit");
		printf("\nEnter your choice..");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:insert();
			break;
			case 2:delet();
			break;
			case 3:exit(0);
			default :printf("\nWrong choice");
		}
	}
}

insert()
{
	node *n,*cur=first,*prev=NULL;
	int ch,pos,count=1;

	if(first==NULL)
	{
		n=(node*)(malloc (sizeof(node)));
		printf("\nEnter first node..");
		scanf("%d",&n->data);
		n->link=NULL;
		first=last=n;
		last->link=first;
	}
	else
	{
		node *temp1=first;
		int len=1;

		printf("\n\n1.at beginning\n2.at end\n3.anywhere");
		printf("\nEnter your choice..");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:n=(node*)(malloc (sizeof(node)));
			printf("\nEnter data..");
			scanf("%d",&n->data);
			n->link=first;
			first=n;
			last->link=first;
			break;

			case 2 :n=(node*)(malloc (sizeof(node)));
			printf("\nEnter data..");
			scanf("%d",&n->data);
			last->link=n;
			last=n;
			last->link=first;
			break;

			case 3:printf("\nEnter position..");
			scanf("%d",&pos);
			len=1;
			temp1=first;
			do
			{
				temp1=temp1->link;
				len++;
			}while(temp1!=first);
			if(pos>len)
			{
				printf("\nInvalid position");
				getch();
				break;
			}
			n=(node*)(malloc (sizeof(node)));
			printf("\nEnter data..");
			scanf("%d",&n->data);

			if(pos==1)
			{
				n->link=first;
				first=n;
				last->link=first;
			}
			else
			{
				count=1;
				while(count<pos)
				{
					prev=cur;
					cur=cur->link;
					count++;
				}
				prev->link=n;
				n->link=cur;
			}
			break;
		}//switch
		display();
	}  //else
}


delet()
{
	int ch,i,val,pos,count=1,len=0;
	node *cur=first,*prev=NULL,*temp1=first;


	printf("\n1.first node\n2.last node\n3.by value\n4.by position\n5.whole list");
	printf("\nEnter your choice");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:first=first->link;
		last->link=first;
		break;

		case 2:while(cur!=last)
		{
			prev=cur;
			cur=cur->link;
		}
		prev->link=NULL;
		last=prev;
		last->link=first;
		break;

		case 3:printf("\nEnter value");
		scanf("%d",&val);
		while(cur->data!=val&&cur->link!=first)
		{
			prev=cur;
			cur=cur->link;
		}
		if(cur->data!=val)
		{
			printf("\nNot found");
			getch();
		}
		else if(cur==first)
		{
			if(first==last)
			{
			first=last=NULL;
			}
			else
			{
			first=first->link;
			last->link=first;
			}
		}
		else if(cur==last)
		{
			prev->link=NULL;
			last=prev;
			last->link=first;
		}
		else
		prev->link=cur->link;
		break;

		case 4:printf("\nEnter position..");
		scanf("%d",&pos);
		len=0;
		temp1=first;
		do
		{
			temp1=temp1->link;
			len++;
		}while(temp1!=first);
		if(pos>len)
		{
			printf("\nInvalid position");
			getch();
			break;
		}
		else
		if(pos==1)
		{
			if(first==last)
			{
			first=last=NULL;
			}
			else
			{
			first=first->link;
			last->link=first;
			}
		}
		else
		{
			while(count<pos)
			{
				prev=cur;
				cur=cur->link;
				count++;
			}
			prev->link=cur->link;
		}
		break;

		case 5:first=last=NULL;
		break;
	} //switch
	display();
}
