#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

int circular_queue[SIZE];
int front=-1,rear=-1;

void enqueue()
{
    int n;

    printf("\nEnter element you want to enqueue:");
    scanf("%d",&n);

    if( (front==0 && rear==(SIZE-1)) || (front==rear+1) )
       printf("\nCirculer queue is full.");

    else
    {
        if(front==-1)
            front=0;

        rear=(rear+1)%SIZE;

        circular_queue[rear]=n;
        printf("\ninserted --> %d",n);

    }

}

void dequeue()
{
    int x;

    if(front==-1)
        printf("\nCircular queue is empty.");

    else
    {
        x=circular_queue[front];

        if(front==rear)
            front=rear=-1;
        else
        {
            front=(front+1)%SIZE;
            printf("Deleted --> %d",x);
        }
    }
}

void display()
{
    int i;

    if (front==-1)
        printf(" \n Empty Queue\n");
    else
    {

        printf("\n Displaying elements in CIRCULAR QUEUE -> ");
        for (i = front; i != rear; i = (i + 1) % SIZE) {
            printf("%d ", circular_queue[i]);
    }

    printf("%d ", circular_queue[i]);
    printf("\n Rear -> %d \n", rear);
  }
}

void isfull()
{
    if( (front==0 && rear==(SIZE-1)) || (front==rear+1) )
       printf("\nCirculer queue is full.");

    else
        printf("\nCirculer queue is not full.");
}

void isempty()
{
    if(front==-1)
        printf("\nCircular queue is empty.");
    else
        printf("\nCircular queue is not empty.");
}

int main()
{
    int c;



    while(1)
    {
        printf("\nEnter your choice:");
        printf("\n1. ENQUEUE\t2. DEQUEUE\t3. DISPLAY\n4. ISFULL\t5. ISEMPTY\t6. EXIT");
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
