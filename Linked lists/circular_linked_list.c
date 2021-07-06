#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

void create();

void insert_at_begining();
void insert_at_end();
void insert_at_index();

void delete_from_begining();
void delete_from_end();
void delete_from_index();

int length();

void display();
void display_reverse();

struct node{
    int data;
    struct node *previous;
    struct node *next;

};

struct node *head=NULL, *tail=NULL, *temp, *newnode;


int main()
{
    int choice,l;

        while(1)
        {
            printf("\n\n1. Create\t\t2. Insert_at_begining\n3. Insert_at_end\t4. Insert_at_index\n5. Delete_from_begining\t6. Delete_from_end\n7. Delete_from_index\t8. Length\n9. Display\t\t10. Exit");
            printf("\nEnter your choice ::\t");
            scanf("%d",&choice);
            switch(choice)
            {
                case 1:
                    create();
                    break;

                case 2:
                    insert_at_begining();
                    break;

                case 3:
                    insert_at_end();
                    break;

                case 4:
                    insert_at_index();
                    break;

                case 5:
                    delete_from_begining();
                    break;

                case 6:
                    delete_from_end();
                    break;

                case 7:
                    delete_from_index();
                    break;

                case 8:
                    l=length();
                    printf("\nLength of list is:  %d\n",l);
                    break;

                case 9:
                    display();
                    break;

                case 10:
                    exit(0);

                default :
                    printf("\nWrong choice.\nPlease enter proper choice.\n");


            }//switch

        }//while_loop


    return 0;

}//int_main


void create()
{

    if(head==NULL && tail==NULL)
    {
        newnode=(struct node*)malloc(sizeof(struct node));

        printf("\nEnter data you want to insert : ");
        scanf("%d",&newnode->data);

        head=tail=newnode;
        newnode->previous=newnode->next=newnode;


    }
    else
        printf("\n\nList is already created.\nPlease Try another option. ");

    return;

}


void insert_at_begining()
{
    if(head==NULL && tail==NULL)
        create();

    else
    {
        newnode=(struct node*)malloc(sizeof(struct node));

        printf("\nEnter data you want to insert : ");
        scanf("%d",&newnode->data);

        newnode->next=head;
        head->previous=newnode;
        newnode->previous=tail;
        tail->next=newnode;
        head=newnode;
    }

    return;
}



void insert_at_end()
{
    if(head==NULL && tail==NULL)
        create();

    else
    {
        newnode=(struct node*)malloc(sizeof(struct node));

        printf("\nEnter data you want to insert : ");
        scanf("%d",&newnode->data);


        newnode->previous=tail;
        tail->next=newnode;
        newnode->next=head;
        head->previous=newnode;
        tail=newnode;

    }

    return;
}




void insert_at_index()
{
    if(head==NULL && tail==NULL)
        create();

    else
    {
        int i,j=0,len;

        len=length();

        newnode=(struct node*)malloc(sizeof(struct node));

        printf("\nEnter index : ");
        scanf("%d",&i);


        if(i<0 || i>len-1)
            printf("\n\nInvalid index.");

        else if(i==0)
            insert_at_begining();


        else
        {
            printf("\nEnter data you want to insert : ");
            scanf("%d",&newnode->data);

            temp=head;

            while(j<i-1)
            {
                temp=temp->next;
                j++;

            }//while

            newnode->previous=temp;
            newnode->next=temp->next;
            newnode->next->previous=newnode;
            temp->next=newnode;



        }//inner_else


    }//outer_else

    return;
}




void delete_from_begining()
{

    if(head==NULL && tail==NULL)
        printf("\n\nList is empty.");

    else if(head->next==head)
        head=tail=NULL;

    else
    {
        temp=head;
        head=head->next;
        head->previous=tail;
        tail->next=head;
    }
    free(temp);
}



void delete_from_end()
{
    if(head==NULL && tail==NULL)
        printf("\n\nList is empty.");

    else if(head->next==head)
        head=tail=NULL;

    else
    {
        tail=tail->previous;
        tail->next=head;
        head->previous=tail;
    }

     free(temp);

    return;
}

void delete_from_index()
{
    int i,j=0;
    int len=length();

    printf("\nEnter index: ");
    scanf("%d",&i);

    if(i<0 || i>len-1)
            printf("\n\nInvalid index.");

        else if(i==0)
            delete_from_begining();

        else if(i==len-1)
            delete_from_end();

        else
        {
            temp=head;

            while(j<i)
            {
                temp=temp->next;
                j++;

            }

            temp->previous->next=temp->next;
            temp->next->previous=temp->previous;

            free(temp);

        }


    return;
}

int length()
{
    int i=0;

    if(head==NULL)
        return i;


    else
    {
        temp=head;

        while(temp!=tail)
        {
            temp=temp->next;
            i++;
        }
        i++;

        return i;
    }
}

void display()
{
    if(head==NULL)
        printf("\nList is Empty.\n");

    else
    {
        printf("\nDisplaying Linked list:\n");

        temp=head;

        while(temp!=tail)
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }
         printf("%d",temp->data);
    }


    return;
}

/*
void display_reverse()
{
    temp=tail;

    if(tail==NULL)
        printf("\nList is Empty.\n");

    else
    {
        printf("\nDisplaying Linked list:\n");


        while(temp!=head)
        {
            printf("%d\t",temp->data);
            temp=temp->previous;
        }
         printf("%d",temp->data);
    }
    return;

}
*/

