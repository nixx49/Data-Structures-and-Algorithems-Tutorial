//AA1885
#include <stdio.h>
#include <stdlib.h>

struct node;
void push(struct node** ref,int newData);
void asc(struct node *node);
void display(struct node *node);
void getInput();

int A[100],x;
int B[100],y;

struct node{
    int data;
    struct node* next;
};

void main(){
printf("=================================================\n");
printf("CCS210 - AA1885 - TUTORIAL2 - Q1\n");
printf("=================================================\n");
    struct node *topA =NULL,*topB =NULL,*topD =NULL;
    getInput();
    for(int i=0;i<x;i++){
        push(&topA,A[i]);
    }
    for(int i=0;i<y;i++){
        push(&topB,B[i]);
    }

    printf("\n=================================================\n");
    printf("GIVEN NUMBERS FROM END TO BEGINING:\n");
    display(topA);
    display(topB);
    printf("\nGIVEN NUMBERS FROM ASCENDING ODER:\n");
    asc(topB);
    asc(topA);
    display(topA);
    display(topB);

    for(int i=0;i<x;i++){
        push(&topD,A[i]);
    }
    for(int i=0;i<y;i++){
        push(&topD,B[i]);
    }
    asc(topD);
    printf("\n=================================================\n");
    printf("\nSTACK D OUTPUT : ");
    display(topD);
    printf("\n=================================================\n");
}

void asc(struct node *Node){
    struct node* temp=Node->next;
    struct node* start=Node;

    int tmpData;
    while(temp!=NULL){
        if(Node->data > temp->data){
            tmpData=Node->data;
            Node->data=temp->data;
            temp->data=tmpData;

            Node=start;
            temp=Node->next;

        }else{
        Node=Node->next;
        temp=temp->next;
        }
    }
}

void display(struct node *Node){
  while(Node!=NULL){
    printf("%d, ",Node->data);
    Node= Node->next;
  }
  printf("\n");
}

void push(struct node** ref,int newData){
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = newData;
    newNode->next =(*ref);
    (*ref)=newNode;
}

void getInput(){
    printf("\nENTER NUMBER OF ELEMENT IN STACK A : ");
    scanf("%d",&x);

    for(int i=0; i<x; i++){
        printf("ENTER ELEMENT ONE BY ONE : ");
        scanf("%d",&A[i]);
    }
    printf("\nENTER NUMBER OF ELEMENT IN STACK B : ");
    scanf("%d",&y);

    for(int i=0; i<y; i++){
        printf("ENTER ELEMENT ONE BY ONE : ");
        scanf("%d",&B[i]);
    }
}
