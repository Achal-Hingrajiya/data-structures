
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

int stack[SIZE];
int top=-1;

void push()
{
    int n;
    printf("\nEnter element you want to push:");
    scanf("%d",&n);

    if(top==SIZE-1)
        printf("Stack is overflow.");
    else
        stack[++top]=n;
}

void pop()
{
    int x;
    if(top==-1)
        printf("satck is underflow");
    else
    {
        x=stack[top--];
        printf("\npoped element is:%d",x);
    }

}

void display()
{
    if(top==-1)
        printf("satck is underflow");
    else
    {
        int i;

        printf("Displaying stack:\n");

        for(i=top;i>-1;i--)
            printf("| %d |\n",stack[i]);

    }
}

void isfull()
{
    if(top==SIZE-1)
        printf("\nsatck is full.");
    else
        printf("\nsatck is not full.");
}

void isempty()
{
    if(top==-1)
        printf("\nsatck is empty.");
    else
        printf("\nsatck is not empty.");
}

int main()
{
    int c;

    while(1)
    {
        printf("Enter Your choice:");
        printf("\n1. PUSH\t2. POP\t3. DISPLAY\n4. ISFULL\t5. ISEMPTY\t6. EXIT");
        scanf("%d",&c);

        switch(c)
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
                isfull();
                break;

            case 5:
                isempty();
                break;

            case 6:
                exit(0);
        }

    }


    return 0;
}
