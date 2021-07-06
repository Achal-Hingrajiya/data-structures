#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;

};

struct node *create()
{
        struct node *newnode;
        int x;
        newnode=(struct node *)malloc(sizeof(struct node));

        printf("\nEnter data to enter.\nIf you want to insert null, Insert -1 :\t");
        scanf("%d",&x);

        if(x==-1)
            return NULL;
        newnode->data=x;
        printf("\nLeft child of %d.",x);
        newnode->left=create();
        printf("\nRight child of %d.",x);
        newnode->right=create();

        return newnode;


}

void preorder(struct node *root)
{
    if(root==NULL)
        return;
    printf("%d, ",root->data);
    preorder(root->left);
    preorder(root->right);

    return;

}

void inorder(struct node *root)
{
    if(root==NULL)
        return;


    inorder(root->left);
    printf("%d, ",root->data);
    inorder(root->right);

    return;

}

void postorder(struct node *root)
{
    if(root==NULL)
        return;


    postorder(root->left);
    postorder(root->right);
    printf("%d, ",root->data);

    return;

}
int main()
{

    struct node *root=NULL;
    int choice;

    while(1)
    {

        printf("\n1. create\t2. Traverse\n3.Exit\nEnter Your choice:\t");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                root=create();
                getch();
                system("cls");
                break;

            case 2:
                if(root==NULL)
                {
                    printf("\nTree is empty.\nTo create Tree Enter 1 else 0 :\t");
                    scanf("%d",&choice);

                    if(choice==1)
                        root=create();
                    else
                        break;

                }

                else
                {
                    printf("\n1. Preorder\t2. Inorder\n3. Postorder\t4. Back\nEnter Your choice:\t");
                    scanf("%d",&choice);

                    switch(choice)
                    {
                        case 1:
                            preorder(root);
                            break;

                        case 2:
                            inorder(root);
                            break;

                        case 3:
                            postorder(root);
                            break;

                        case 4:
                            break;

                        default:
                            printf("\nPlease make appropriate choice.\n");



                        }//switch


                }//else
                getch();
                system("cls");
                break;


            case 3:
                exit(0);

            default:
                printf("\nPlease make appropriate choice.\n");
                getch();
                system("cls");
                break;




        }//switch


    }//while

}//int main
