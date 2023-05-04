#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * prev;
    struct node * next;
}*head, *last;

void createList(int n);
//void deleteFromBeginning();
//void deleteFromN(int position);

void WinMain(int n){

printf("=================================================\n");
printf("CCS210 - AA1885 - TUTORIAL2 - Q2\n");
printf("=================================================\n");
printf("\nENTER THE NUMBER OF NODES IF YOU WANT: ");
    scanf("%d", &n);
    void createList(int n);

//printf("Enter the node position which you want to delete: ");
          //  scanf("%d", &n);
//deleteFromBeginning();

}

void createList(int n){
    int i, data;
    struct node *newNode;

    if(n >= 1)
    {
        head = (struct node *)malloc(sizeof(struct node));

        printf("\nASSIGN DATA TO NODE 1: ");
        scanf("%d", &data);

        head->data = data;
        head->prev = NULL;
        head->next = NULL;

        last = head;

        for(i=2; i<=n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));

            printf("ASSIGN DATA TO NODE %d: ", i);
            scanf("%d", &data);

            newNode->data = data;
            newNode->prev = last;
            newNode->next = NULL;

            last->next = newNode;
            last = newNode;
        }
        printf("\n=================================================\n");
        printf("YOUR DOUBLY LINKED LIST CREATED SUCCESSFULLY.\n");
        printf("=================================================\n");
    }
}




