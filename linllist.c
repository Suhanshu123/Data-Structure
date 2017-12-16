#include<stdio.h>
#include<conio.h>
#include<malloc.h>
typedef struct list{
int data;
struct list *link
}node;

node *first=NULL,*last=NULL;
 main()
{
 int  ch;
 void insert();
 void delet();
 void display();

 while(ch<4)
 {
  printf("\n1.Insert\n2.Delete\n3.Display");
  printf("\nEnter your choice..");
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

display()
{
    if(first==NULL)
        printf("Linklist is empty");
    else{
            node *temp=first;
        while(temp!=NULL)
        {
            printf("%d\t",temp->data);
            temp=temp->link;

        }
    }
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
      case 1:first=first->link;
      case 2:while(cur!=NULL)
      {

          prev=cur;
          cur=cur->link;
      }
       prev->link=NULL;
	   last=prev;
	   break;

	   case 3:  printf("\nEnter value");
	            scanf("%d",&val);
	            while((cur->data!=val)&&cur!=NULL)
	              {
	                  prev=cur;
	                  cur=cur->link;

                  }
                  if(cur==NULL)
		     {
		      printf("\nNot found");
		      getch();
		      }
		   else if(cur==first)
			   first=first->link;
			else if(cur==last)
			     {
			      prev->link=NULL;
			      last=prev;
			     }
			else
			    prev->link=cur->link;
		   break;

       case 4:printf("\nEnter position..");
		   scanf("%d",&pos);
		   while(temp1!=NULL)
		      { temp1=temp1->link;
			len++;
		      }
	       if(pos>len)
		 { printf("\nInvalid position");
		  getch();
		  break;
		 }
		else
		  if(pos==1)
		     first=first->link;
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
    case 1:n=(node*)(malloc (sizeof(node)));
	 printf("\nEnter data..");
	 scanf("%d",&n->data);
	  n->link=first;
	   first=n;
	   break;
    case 2 :n=(node*)(malloc (sizeof(node)));
	 printf("\nEnter data..");
	scanf("%d",&n->data);
	n->link=NULL;
	last->link=n;
		last=n;
		break;
    case 3:    printf("\nEnter position..");
		scanf("%d",&pos);
		while(temp1!=NULL)
		      {
            temp1=temp1->link;
			len++;
		      }
	       if(pos>len)
		 { printf("\nInvalid position");
		  getch();
		  break;
		 }
		n=(node*)(malloc (sizeof(node)));
		printf("\nEnter data..");
		scanf("%d",&n->data);

		if(pos==1)
		  {n->link=first;
		   first=n;
		  }
		else
	       {
	       while(count<pos)
		 {
		  prev=cur;
		  cur=cur->link;
		  count++;
		 }
		if(cur==NULL)
		  { prev->link=n;
		   last=n;
		   }
	       else{	prev->link=n;
		n->link=cur;
	       } }
		break;
    }//switch
  }
  }
    //else









