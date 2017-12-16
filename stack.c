#include<stdio.h>
# define s 5
int top=-1,stk[s],i;
main()

{
    int ch=0;
 while(ch<4)
    {
        printf("\n\t1. Push\n\t2. Pop\n\t3. List\n\t4. Exit\n\n\t  Enter  your choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                push();
                break;

            case 2:
                pop();
                break;
            case 3:
                list();
                break;
            case 4: break;

        }
    }
}
push()
{
    int val;
    if(top==s-1)
        printf("Stack is overflow");
    else
    {
        printf("Enter data to be pushed");
        scanf("%d",&val);
        top++;
        stk[top]=val;
        printf("%dis inserted",val);

    }
}
pop()
{

    if(top==-1)
        printf("stack is empty");
    else
    {
        printf("%d is deleted",stk[top]);
        top--;
    }
}
list()
{
    if(top==-1)
        printf("stack is empty");
    else{
        for(i=0;i<=top;i++)
            printf("%d\t",stk[i]);
    }
}

