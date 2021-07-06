#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

struct node{
    int data;
    struct node *link;

};

struct node *head=NULL;
struct node *newnode, *temp;


int main()
{
    int choice;




    while(choice)
    {
        newnode=(struct node*)malloc(sizeof(struct node));

        printf("\nEnter a element to be inserted in linked list: ");
        scanf("%d",&newnode->data);
        newnode->link=NULL;

        if(head==NULL)
            head=temp=newnode;

        else
        {
            temp->link=newnode;
            temp=newnode;

        }

        printf("\nDisplaying Linked list:\n");

        temp=head;

        while(temp!=NULL)
        {
            printf("%d\t",temp->data);
            temp=temp->link;
        }

        printf("\nDo you want to continue??  :  ");
        scanf("%d",&choice);

    }

    return 0;
}
