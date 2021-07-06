#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

#define SIZE 5

int deque[SIZE];

int front=-1,rear=-1;



void insert_at_front()
{
    int x;
    printf("==============================================\n");
    printf("\nEnter Element you want to insert: ");
    scanf("%d",&x);

    if((front==0 && rear==SIZE-1) || (front==rear+1))
        printf("Queue is Overflow.");


    else if(front==-1 && rear==-1)
    {
        front=rear=0;
        deque[front]=x;

        printf("\nFRONT=%d\tREAR=%d\nInserted at FRONT--> %d\n",front,rear,x);
    }


    else if(front==0)
    {
        front=SIZE-1;
        deque[front]=x;

        printf("\nFRONT=%d\tREAR=%d\nInserted at FRONT--> %d\n",front,rear,x);
    }


    else
    {
        front--;
        deque[front]=x;

        printf("\nFRONT=%d\tREAR=%d\nInserted at FRONT--> %d\n",front,rear,x);
    }


    printf("==============================================\n");

}



void insert_at_rear()
{
    int x;

    printf("==============================================\n");

    printf("\nEnter Element you want to insert: ");
    scanf("%d",&x);

    if((front==0 && rear==SIZE-1) || (front==rear+1))
        printf("\nQueue is Overflow.\n");

    else if(front==-1 && rear==-1)
    {
        front=rear=-1;
        deque[rear]=x;
        printf("\nIFRONT=%d\tREAR=%d\nnserted at REAR--> %d\n",front,rear,x);
    }

    else if(rear==SIZE-1)
    {
         rear=0;
         deque[rear]=x;\
         printf("\nIFRONT=%d\tREAR=%d\nnserted at REAR--> %d\n",front,rear,x);
    }

    else
    {
        rear++;
        deque[rear]=x;
        printf("\nIFRONT=%d\tREAR=%d\nnserted at REAR--> %d\n",front,rear,x);

    }


    printf("==============================================\n");


}

void delete_from_front()
{

    printf("==============================================\n");

    if(front==-1 && rear==-1)
        printf("\nQueue is Underflow.");

    else if(front==rear)
    {
        printf("\nFRONT=%d\tREAR=%d\nDeleted from FRONT--> %d\n",front,rear,deque[front]);
        front=rear=-1;
    }


    else if(front==SIZE-1)
    {
        printf("\nFRONT=%d\tREAR=%d\nDeleted from FRONT--> %d\n",front,rear,deque[front]);
        front=0;

    }

    else
    {
        printf("\nFRONT=%d\tREAR=%d\nDeleted from FRONT--> %d\n",front,rear,deque[front]);
        front++;
    }

    printf("==============================================\n");
}

void delete_from_rear()
{
    printf("==============================================\n");

    if(front==-1 && rear==-1)
        printf("\nQueue is Underflow.");

    else if(front==rear)
    {
        printf("\nFRONT=%d\tREAR=%d\nDeleted from REAR--> %d\n",front,rear,deque[rear]);
        front=rear=-1;
    }

    else if(rear==0)
    {
        printf("\nFRONT=%d\tREAR=%d\nDeleted from REAR--> %d\n",front,rear,deque[rear]);

        rear=SIZE-1;

    }
    else
    {
        printf("\nFRONT=%d\tREAR=%d\nDeleted from REAR--> %d\n",front,rear,deque[rear]);

        rear--;


    }
    printf("==============================================\n");

}

void display()
{
    printf("==============================================\n");

    int i=front;

    if(front==-1 && rear==-1)
        printf("\nQueue is Underflow.\n");

    else
    {
        printf("\nDisplaying all elements in queue:\n");
        while(i!=rear)
        {
            printf("%d\t",deque[i]);
            i=(i+1)%SIZE;
        }


        printf("%d",deque[rear]);

    }
    printf("==============================================\n");
}

void peek_front()
{
    printf("==============================================\n");

    if(front==-1 && rear==-1)
        printf("\nQueue is Underflow.\n");

    else
        printf("\nFront element is: %d\n",deque[front]);

    printf("==============================================\n");
}

void peek_rear()
{
    printf("==============================================\n");

    if(front==-1 && rear==-1)
        printf("\nQueue is Underflow.\n");

    else
        printf("\nRear element is: %d\n",deque[rear]);

    printf("==============================================\n");
}



int main()
{
    int ch;

    while(1)
    {

        printf("\n1. Insert At Front\t2. Insert At Rear\n3.Delete From Front\t4. Delete From Rear\n5. Peek Front\t\t6. Peek Rear\n7. Display\t\t8. EXIT");
        printf("\nEnter Your choice:");
        scanf("%d",&ch);


        switch(ch)
        {
            case 1:
                insert_at_front();
                break;

            case 2:
                insert_at_rear();
                break;

            case 3:
                delete_from_front();
                break;

            case 4:
                delete_from_rear();
                break;

            case 5:
                peek_front();
                break;

            case 6:
                peek_rear();
                break;

            case 7:
                display();
                break;

            case 8:
                exit(0);

        }
    }


    return 0;
}
