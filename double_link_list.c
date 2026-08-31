#include <stdio.h>
#include <stdlib.h>
struct DDL
{
    int data;
    struct DDL *next;
    struct DDL *prev;
} *new, *head, *temp;
void create_node()
{
    int val;
    new = (struct DDL *)malloc(sizeof(struct DDL));
    printf("\n Enter Your Elemant ");
    scanf("%d", &val);
    new->prev = NULL;
    new->data = val;
    new->next = NULL;
}
void menu();
void insert_menu();
void insert_beg();
void insert_end();
void display_right_to_left();
void display();
void display_menu();
void display_left_to_rigth();
int main()
{
    int ch, ch1;
    do
    {
        menu();
        printf("\n Enter Your Choice");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            system("cls");
            do
            {
                insert_menu();
                printf("\n Enter Your Choice");
                scanf("%d", &ch1);
                switch (ch1)
                {
                case 1:
                    system("cls");
                    insert_beg();
                    break;
                case 2:
                    system("cls");
                    insert_end();
                    break;
                case 3:
                    system("cls");
                    printf("\n Back To The Main Menu ");
                    break;
                default:
                    system("cls");
                    printf("\n Invalide Choice ");
                    break;
                }
            } while (ch1 != 3);

            break;
        case 2:
            system("cls");
            display();
            break;
        default:
            system("cls");
            printf("\n Invalide Choice ");
            break;
        }
    } while (ch != 4);
}
void menu()
{
    printf("\n ------------ MAIN MENU ------------");
    printf("\n |            1. Insert            |");
    printf("\n |            2. Display           |");
    printf("\n |            3. Delete            |");
    printf("\n |            4. Exit              |");
    printf("\n -----------------------------------");
}
void insert_menu()
{
    printf("\n ------------- Insert Menu ------------- ");
    printf("\n |    1. Insert On The Begining         |");
    printf("\n |    2. Insert On The Ending           |");
    printf("\n |    3. Back To Main Menu              |");
    printf("\n ----------------------------------------");
}
void insert_beg()
{
    create_node();
    new->next = head;
    new->prev = NULL;
    if (head != NULL)
    {
        head->prev = new;
    }
    head = new;
    printf("\n Insert Is Done");
}
void insert_end()
{
    create_node();
    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new;
    new->prev = temp;
    printf("\n Insert Is Done On The End");
}
void display()
{
    int op;
    if (head == NULL)
    {
        printf("\n Link List Is Empty ");
        return;
    }
    do
    {
        display_menu();
        printf("\n Enter Your Choice ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            system("cls");
            display_right_to_left();
            break;
        case 2:
            system("cls");
            display_left_to_rigth();
            break;
        case 3:
            system("cls");
            printf("\n Back To The Main Menu ");
            break;
        default:
            system("cls");
            printf("\n Invalide Choice");
            break;
        }
    } while (op != 3);
}
void display_menu()
{
    printf("\n -------------- DISPLAY MENU --------------------");
    printf("\n |              1. Display (Right To Left)       |");
    printf("\n |              2. Display (Left To Right)       |");
    printf("\n |              3. Back To Main                  |");
    printf("\n -------------------------------------------------");
}
void display_right_to_left()
{
    if (head == NULL)
    {
        printf("\n The Link List Is Empty ");
        return;
    }
    temp = head;
    while (temp != NULL)
    {
        printf(" %d ", temp->data);
        temp = temp->next;
    }
}
void display_left_to_rigth()
{

    if (head == NULL)
    {
        printf("\n The Link List ");
        return;
    }

    temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    while (temp != NULL)
    {
        printf("  %d  ", temp->data);
        temp = temp->prev;
    }
}