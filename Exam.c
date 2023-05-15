#include <stdio.h>
#include <stdlib.h>
//AA1885

struct node {
int data;
struct node *next;
};
struct node *start=NULL;


int insert (int dat){
int P start;
while (P->link!=NULL)
    P=P->link;
P->link=data;
    data->link=NULL;
}


array A[b]={12,78,25,46,92,65}
int insert(int data){
P=start;
int x=1;
while(P->link1=NULL){
    P=P->link
    P->link=array A;
    array A ->link=NULL;
    int y =0;}
return;
}


int count(struct node* head, int_serch_for)
{
    struct node*current=head;
    int count=0;
    while (current!=NULL){
        if(current->data==serchfor)
            count++;
        current=current->next;
    }
return count;
}


void deletenode(node**head_ref, int key)
{
    node*temp = *head_ref;
    node* prev = NULL;

    if(temp != NULL && temp-> data == key)
    {
        *head_ref=temp->next;
        delete=temp;
        return;
    }
    else
    {
        while(temp!= NULL && temp ->data!=key)
        {
            prev=temp;
            temp=temp->next;
        }
        if (temp == NULL)
            return;
        prev->next=temp->next;
        delete temp;
    }
}
