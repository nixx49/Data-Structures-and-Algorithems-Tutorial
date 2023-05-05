#include <stdio.h>
#include <stdlib.h>

struct node;
void push(struct node** ref,int newData);
void asc(struct node *node);
void display(struct node *node);
void getInput();

int A[100],aC;
int B[100],bC;

struct node{
    int data;
    struct node* next;
};


void main(){
    struct node *topA =NULL,*topB =NULL,*topD =NULL;
    getInput();//get input from user
    for(int i=0;i<aC;i++){
        push(&topA,A[i]);
    }
    for(int i=0;i<bC;i++){
        push(&topB,B[i]);
    }
    display(topA);
    display(topB);
    asc(topB);
    asc(topA);
    display(topA);
    display(topB);

    for(int i=0;i<aC;i++){
        push(&topD,A[i]);
    }
    for(int i=0;i<bC;i++){
        push(&topD,B[i]);
    }
    asc(topD);
    printf("Final Out put :");
    display(topD);
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

    printf("Enter Element Count of A : ");
    scanf("%d",&aC);
    printf("Enter Element of A : ");
    for(int i=0; i<aC; i++){
        scanf("%d",&A[i]);
    }
    printf("Enter Element Count of B : ");
    scanf("%d",&bC);
    printf("Enter Element of B : ");
    for(int i=0; i<bC; i++){
        scanf("%d",&B[i]);
    }
}
