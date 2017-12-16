/*DOUBLY LINKED LIST*/
#include<stdio.h>
#include<conio.h>
#include<malloc.h>

typedef struct list
{
	int data;
	struct list *next;
	struct list *pre;
}node;
node *first=NULL,*last=NULL;

display()
{

	if(first==NULL)
	printf("\nNo data");
	else
	{
		node *temp=first;
		while(temp!=NULL)
		{
			printf("%d\t",temp->data);
			temp=temp->next;
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
		n->next=NULL;
		n->pre=NULL;
		first=last=n;
	}
	else
	{
		node *temp1=first;int len=1;
		display();
		printf("\n\n1.at beginning\n2.at end\n3.anywhere");
		printf("\nEnter your choice..");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			n=(node*)(malloc (sizeof(node)));
			printf("\nEnter data..");
			scanf("%d",&n->data);
			n->pre=NULL;
			n->next=first;
			first->pre=n;
			first=n;
			break;

			case 2 :
			n=(node*)(malloc (sizeof(node)));
			printf("\nEnter data..");
			scanf("%d",&n->data);
			n->next=NULL;
			n->pre=last;
			last->next=n;
			last=n;
			break;

			case 3:
			printf("\nEnter position..");
			scanf("%d",&pos);
			while(temp1!=NULL)
			{
				temp1=temp1->next;
				len++;
			}
			if(pos>len)
			{
				printf("length = %d",len);
				printf("\nInvalid position");
				getch();
				break;
			}
			n=(node*)(malloc (sizeof(node)));
			printf("\nEnter data.. ");
			scanf("%d",&n->data);
			if(pos==1)
			{
				n->pre=NULL;
				n->next=first;
				first->pre=n;
				first=n;
			}
			else
			{
				while(count<pos)
				{
					prev=cur;
					cur=cur->next;
					count++;
				}
				if(cur==NULL)
				{
					prev->next=n;
					n->pre=prev;
					last=n;
				}
				else
				{
					prev->next=n;
					n->next=cur;
					n->pre=prev;
					cur->pre=n;
				}
			}//else
			break;
		}//switch
	}  //else
	display();
}


delet()
{
	int ch,i,val,pos,count=1,len=0;
	node *cur=first,*prev=NULL,*temp1=first;

	display();
	printf("\n1.first node\n2.last node\n3.by value\n4.by position\n5.whole list");
	printf("\nEnter your choice");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
		first=first->next;
		first->pre=NULL;
		break;

		case 2:
		while(cur->next!=NULL)
		{
			prev=cur;
			cur=cur->next;
		}
		prev->next=NULL;
		last=prev;
		break;

		//last = last->pre;
		//last->next=NULL;

		case 3:
		printf("\nEnter value");
		scanf("%d",&val);
		while(cur->data!=val&&cur!=NULL)
		{
			prev=cur;
			cur=cur->next;
		}
		if(cur==NULL)
		{
			printf("\nNot found");
			getch();
		}
		else if(cur==first)
		{
			first=first->next;
			first->pre=NULL;
		}
		else if(cur==last)
		{
			prev->next=NULL;
			last=prev;
		}
		else
		{
			 prev->next=cur->next;
			 cur=cur->next;
			 cur->pre=prev;
		}
		break;

		case 4:
		printf("\nEnter position..");
		scanf("%d",&pos);
		while(temp1!=NULL)
		{
			temp1=temp1->next;
			len++;
		}
		if(pos>len)
		{
			printf("\nInvalid position");
			getch();
			break;
		}
		else
		if(pos==1)
		{
			first=first->next;
			first->pre=NULL;
		}
		else
		{
			while(count<pos)
			{
				prev=cur;
				cur=cur->next;
				count++;
			}

			prev->next=cur->next;
			cur=cur->next;
			cur->pre=prev;
		}
		break;

		case 5:
		first=last=NULL;
		break;
	} //switch
	display();
}


 main()
{
	int  ch;

	while(1)
	{
		printf("\n1.Insert\n2.Delete\n3.exit");
		printf("\nEnter your choice..");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			insert();
			break;
			case 2:
			delet();
			break;
			case 3:
			exit(0);
			default:
			printf("\nWrong choice");
		}
	}
}

