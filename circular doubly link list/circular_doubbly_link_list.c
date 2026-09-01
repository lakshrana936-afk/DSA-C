#include <stdio.h>
#include <stdlib.h>
struct CDLL
{
    int data;
    struct CDLL *next;
    struct CDLL *prev;
} *new, *temp, *head;
void create_node()
{
    int val;
    new = (struct CDLL *)malloc(sizeof(struct CDLL));
    if (new == NULL)
    {
        printf("\n Memory Issue ");
        return;
    }

    printf("\n Enter Your Elemant ");
    scanf("%d", &val);
    // new->prev = NULL;
    new->data = val;
    // new->next = NULL;
}
void main_menu();
void insert_menu();
void insert_beg();
void insert_end();
// DELETE PART
void delete_menu();
void delete_beg();
// DISPLAY PART
void backword_display();
void forwerd_display();
void display();
void display_menu();
int main()
{
    int ch, ch1, ch2, ch3;
    do
    {
        main_menu();
        printf("\n Enter Your Choice ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            system("cls");
            do
            {
                insert_menu();
                printf("\n Enter Your Choice ");
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
                    printf("\n Back To Main");
                    break;
                default:
                    system("cls");
                    printf("\n Invalide Choice ");
                    break;
                }
            } while (ch1 != 3);

            break;
        case 2:
            do
            {
                delete_menu();
                printf("\n Enter Your Choice ");
                scanf("%d", &ch3);
                switch (ch3)
                {
                case 1:
                    system("cls");
                    delete_beg();
                    break;

                default:
                    system("cls");
                    printf("\n Invalide Choice ");
                    break;
                }

            } while (ch3 != 3);

            
        case 3:
            system("cls");
            do
            {
                display_menu();
                printf("\n Enter Your Choice ");
                scanf("%d", &ch2);
                switch (ch2)
                {
                case 1:
                    system("cls");
                    backword_display();
                    break;
                case 2:
                    system("cls");
                    forwerd_display();
                    break;
                case 3:
                    system("cls");
                    printf("\n Back To The Main Menu ");
                    break;
                default:
                    system("cls");
                    printf("\n Invalide Choice  ");
                    break;
                }

            } while (ch2 != 3);
            break;
        default:
            system("cls");
            printf("\n Invalide Choice ");
            break;
        }
    } while (ch != 4);

    return 0;
}
void main_menu()
{
    printf("\n ==== MAIN MENU ==== ");
    printf("\n      1. Insert ");
    printf("\n      2. Delete ");
    printf("\n      3. Display ");
    printf("\n      4. Exit");
}
void insert_menu()
{
    printf("\n ======= INSERT MENU =======");
    printf("\n         1. Insert On Beginig");
    printf("\n         2. Insert On End ");
    printf("\n         3. Back To Main Menu ");
}
void insert_beg()
{
    create_node();
    // IF ONE NODE IS EXISIST
    if (head == NULL)
    {
        head = new;
        new->next = head;
        new->prev = head;
    }
    else
    {
        new->next = head;
        new->prev = head->prev;
        head->prev->next = new;
        head->prev = new;
        head = new;
    }

    printf("\n Insert Is Done %d Elemant Is Insert In The Link List ", new->data);
}
void insert_end()
{
    if (head == NULL)
    {
        insert_beg();
    }
    else
    {
        create_node();
        head->prev->next = new;
        new->prev = head->prev;
        new->next = head;
        head->prev = new;
        printf("\n The %d Elemant Is Inserted In Link List %d ", new->data);
    }
}
void backword_display()
{
    if (head == NULL)
    {
        printf("\n The Link List Is Empty ");
        return;
    }
    temp = head;
    do
    {
        printf(" %d ", temp->data);
        temp = temp->next;
    } while (temp != head);
}
void forwerd_display()
{
    if (head == NULL)
    {
        printf("\n The Link List Is Empty ");
        return;
    }
    temp = head;
    do
    {
        temp = temp->next;
    } while (temp->next != head);
    do
    {
        printf(" %d ", temp->data);
        temp = temp->next;
    } while (temp->next != head);
}
void display_menu()
{
    printf("\n ==== DISPLAY MENU ====");
    printf("\n      1. Display From Rigth To Left ");
    printf("\n      2. Display From Left To Right ");
    printf("\n      3. Back To Main Menu ");
}
// DELETE PART
void delete_menu()
{
    printf("\n === DELETE MENU ===");
    printf("\n     1. Delete Beg");
    printf("\n     2. Delete End ");
    printf("\n     3. Back To The Main Menu ");
}
void delete_beg()
{
    if (head == NULL)
    {
        printf("\n The Link List Is Empty");
        return;
    }
    else
    {
        temp = head;
        temp->next->prev = head->prev;
        head = temp->prev;
        printf("\n The %d Elemant Deleted From Link List ", temp->data);
        free(temp);
    }
}