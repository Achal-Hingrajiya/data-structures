#include<stdio.h>
#include<stdlib.h>

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


struct node
{
    int data;
    struct node *next;
};

struct node *head=NULL;
struct node *temp, *newnode;

int main()
{
        int ch,l;

        while(1)
        {
            printf("\n\n1. Create\t\t2. Insert_at_begining\n3. Insert_at_end\t4. Insert_at_index\n5. Delete_from_begining\t6. Delete_from_end\n7. Delete_from_index\t8. Display\n9. Length\t\t10. Exit");
            printf("\nEnter your choice ::\t");
            scanf("%d",&ch);
            switch(ch)
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
                    display();
                    break;

                case 9:
                    l=length();
                    printf("\nLength of list is:  %d\n",l);
                    break;

                case 10:
                    exit(0);

                default :
                    printf("\nWrong choice.\nPlease enter proper choice.\n");


            }
        }

        return 0;

}






void create()
{


    if(head==NULL)
    {
        newnode=(struct node*)malloc(sizeof(struct node));

        printf("\nEnter data to insert: ");
        scanf("%d",&newnode->data);

        newnode->next=NULL;
        head=temp=newnode;

    }




    else
    {
        printf("\nList is already created.\n");
    }

    return;

}

void insert_at_begining()
{
    if(head==NULL)
    {
        create();

    }


    else
    {
        newnode=(struct node*)malloc(sizeof(struct node));

        printf("\nEnter data you want to Insert : ");
        scanf("%d",&newnode->data);

        newnode->next=head;
        head=newnode;

    }

    return;

}


void insert_at_end()
{
    if(head==NULL)
    {
        create();
    }

    else
    {
        newnode=(struct node*)malloc(sizeof(struct node));

        printf("\nEnter data you want to Insert : ");
        scanf("%d",&newnode->data);
        newnode->next=NULL;

        temp=head;

        while(temp->next!=NULL)
            temp=temp->next;

        temp->next=newnode;
    }

    return;

}

void insert_at_index()
{
    int i,j,len;

    printf("\nEnter index: ");
    scanf("%d",&i);

    len=length();

    if(i>len-1 || i<0)
    {
        printf("\nInvalid Index.\n");
    }

    else if(i==0)
        insert_at_begining();



    else
    {
        newnode=(struct node*)malloc(sizeof(struct node));

        printf("\nEnter data you want to Insert : ");
        scanf("%d",&newnode->data);

        temp=head;

        while(j<i-1)
        {
            temp=temp->next;
            j++;
        }

        newnode->next=temp->next;
        temp->next=newnode;



    }

    return;
}


void delete_from_begining()
{
    if(head==NULL)
        printf("\nList is already empty.\n");

    else
    {
        temp=head;
        head=head->next;
        free(temp);
    }

    return;
}


void delete_from_end()
{
    if(head==NULL)
        printf("\nList is already empty.\n");

    else
    {
        struct node *prevnode;

        temp=head;

        while(temp->next!=NULL)
        {
            prevnode=temp;
            temp=temp->next;
        }

        if(temp==head)
            head=NULL;

        else
            prevnode->next=NULL;

        free(temp);
    }

    return;
}

void delete_from_index()
{

    int i,j=0;
    int len=length();

    printf("\nEnter Index: ");
    scanf("%d",&i);

    if(i<0 || i>len-1)
        printf("\n\nInvalid Index.");

    else if(i==0)
        delete_from_begining();

    else if(i==len-1)
        delete_from_end();

    else
    {
        newnode=(struct node*)malloc(sizeof(struct node));

        temp=head;



        while(j<i-1)
        {
            temp=temp->next;
            j++;
        }

        newnode=temp->next;
        temp->next=newnode->next;

        free(newnode);

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

        while(temp->next!=NULL)
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

        while(temp->next!=NULL)
        {
            printf("%d\t",temp->data);
            temp=temp->next;
        }
         printf("%d",temp->data);
    }


    return;
}

void display_reverse()
{
    struct Node* prev = NULL;
    struct Node* current = *head_ref;
    struct Node* next = NULL;
    while (current != NULL) {
        // Store next
        next = current->next;

        // Reverse current node's pointer
        current->next = prev;

        // Move pointers one position ahead.
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

