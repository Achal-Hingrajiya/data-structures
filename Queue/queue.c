#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define SIZE 5

int queue[SIZE];

int front=-1, rear=-1;

void enqueue()
{
    int n;

    printf("\nEnter the number you want to enqueue :");
    scanf("%d",&n);

    if(rear==(SIZE-1))
        printf("\nQueue is full.");

    else {
        if (front == -1)
            front = 0;

        queue[++rear]=n;
        printf("\nInserted -> %d\n", n);
    }

}

void dequeue()
{
    int x;

    if(front==-1)
        printf("\nqueue is empty.");
    else
    {
        printf("\n%d is Deleted.",queue[front++]);

        if(front>rear)
            front=rear=-1;
    }
}

void display()
{
    int i;

    if(rear==-1 )
        printf("\nqueue is empty.");
    else
    {
        printf("\nDisplaying queue:\n");

        for(i=front;i<=rear;i++)
            printf("|%d\t",queue[i]);
        printf("|");

    }


}

void isfull()
{
    if(rear==(SIZE-1))
        printf("\nqueue is full.");
    else
        printf("\nqueue is not full.");
}

void isempty()
{
    if(front==-1 )
        printf("\nqueue is empty.");
    else
        printf("\nqueue is not empty.");

}

int main()
{
    int c;

    while(1)
    {
        printf("\nEnter your choice:");
        printf("\n1. ENQUEUE\t2. DEQUEUE\t3. DISPLAY\n4. ISFULL\t5. ISEMPTY\t6. EXIT:\t");
        scanf("%d",&c);

        switch(c)
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
