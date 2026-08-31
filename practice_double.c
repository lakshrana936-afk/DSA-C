#include <stdio.h>
#include <stdlib.h>
struct DDL
{
    int data;
    struct DDL *next;
    struct DDL *prev;
} *new, *temp, *head;
void menu();
void insert_menu();
void insert_beg();
void insert_end();
void display();
void display_menu();
void create_node()
{
    int val;
    new = (struct DDL *)malloc(sizeof(struct DDL));
    if (new == NULL)
    {
        printf("\n It Is A Memory Issue");
        return;
    }

    printf("\n Enter Your Value ");
    scanf("%d", &val);
    new->prev = NULL;
    new->data = val;
    new->next = NULL;
}
int main()
{
    int ch, ch1;
    do
    {
        menu();
        printf("\n Enter Your Choice ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            do
            {
                insert_menu();
                printf("\n Enter Your Choice ");
                scanf("%d", &ch1);
                switch (ch1)
                {
                case 1:
                    insert_beg();
                    break;
                case 2:
                    insert_end();
                case 3:
                    printf("\n BACK TO MAIN MENU ");
                default:
                    break;
                }
            } while (ch1 != 3);

            break;
        case 2:
            display();
            break;
        case 4:
            printf("\n Exit....");
            break;
        default:
            printf("\n Invalide Choice ");
            break;
        }
    } while (ch != 4);

    return 0;
}
void menu()
{
    printf("\n===== MAIN MENU ====");
    printf("\n      1. Insert ");
    printf("\n      2. Delete ");
    printf("\n      3. Display");
    printf("\n      4. Exit ");
}
void insert_menu()
{
    printf("\n===== Insert Main Menu ===== ");
    printf("\n       1. Insert On Beg ");
    printf("\n       2. Insert On End ");
    printf("\n       3. Back To Main Menu ");
}
///[prev||value||next]
void insert_beg()
{
    create_node();
    new->next = head;// [NULL||20||head(100)]  [null(prev)||10||null(next)](first node)
    new->prev = NULL;// [NULL||20||head(100)]  
    if (head != NULL)
    {
        head->prev = new; //[new(200)||10||NULL]
    }
    head = new; // head=100 // head=new=200
    printf("\n Insert Is Done");
}
void insert_end()
{
    create_node();
    temp = head;    // 
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new;
    new->prev = temp;
    printf("\n Insert Is Done ");
}
void display()
{
    int op;
    if (head == NULL)
    {
        printf("\n The Link List Is Empty");
        return;
    }

    do
    {

        display_menu();
        printf("\n Enter Your Choice ");
        scanf("%d", &op);
        if (op == 1)
        {
            temp = head;
            while (temp != NULL)
            {
                printf(" %d ", temp->data);
                temp = temp->next;
            }
        }
        else if (op == 2)
        {
            temp = head;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            while (temp != NULL)
            {
                printf(" %d ", temp->data);
                temp = temp->prev;
            }
        }
    } while (op != 3);
}
void display_menu()
{
    printf("\n === DISPLAY MENU ===");
    printf("\n     1. Display Right To Left ");
    printf("\n     2. Display Left To Right ");
    printf("\n     3. Back To Main Menu ");
}
