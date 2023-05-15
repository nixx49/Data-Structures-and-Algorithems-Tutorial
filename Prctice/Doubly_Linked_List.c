#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * prev;
    struct node * next;
}*head, *last;

void createList(int n);


void WinMain(int n) {
printf("=================================================\n");
printf("CCS210 - AA1885 - TUTORIAL2 - Q2\n");
printf("=================================================\n");
printf("\nENTER THE NUMBER OF NODES IF YOU WANT: ");
            scanf("%d", &n);
            createList(n);

}

void createList(int n)
{
    int i, data;
    struct node *newNode;

    if(n >= 1)
    {
        head = (struct node *)malloc(sizeof(struct node));

        printf("ASSIGN VALUE TO NODE 1: ");
        scanf("%d", &data);

        head->data = data;
        head->prev = NULL;
        head->next = NULL;

        last = head;

        for(i=2; i<=n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));

            printf("ASSIGN VALUE TO NODE %d : ", i);
            scanf("%d", &data);

            newNode->data = data;
            newNode->prev = last;
            newNode->next = NULL;

            last->next = newNode;
            last = newNode;
        }

        printf("\nYOUR DOUBLY LINKED LIST IS CREATED.\n");
    }
}
