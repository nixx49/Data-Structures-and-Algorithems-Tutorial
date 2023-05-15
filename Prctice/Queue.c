//AA1885
#include <stdio.h>
#include <stdlib.h>

struct QNode {
	int Element;
	struct QNode* next;
};

struct Queue {
	struct QNode *front, *rear;
};

struct QNode* newNode(int E){
	struct QNode* temp = (struct QNode*)malloc(sizeof(struct QNode));
	temp->Element = E;
	temp->next = NULL;
	return temp;
}

struct Queue* createQueue(){
	struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
	q->front = q->rear = NULL;
	return q;
}

void enQueue(struct Queue* q, int E){
	struct QNode* temp = newNode(E);

	if (q->rear == NULL) {
		q->front = q->rear = temp;
		return;
	}
	q->rear->next = temp;
	q->rear = temp;
}

void deQueue(struct Queue* q){
	if (q->front == NULL)
		return;

	struct QNode* temp = q->front;
	q->front = q->front->next;

	if (q->front == NULL)
		q->rear = NULL;
	free(temp);
}

void delqueue(struct Queue* q){
    while(q->front != NULL){
        deQueue(q);
    }
}

void show(struct Queue* q){
    if(q->front == NULL || q->rear == NULL){
        printf("QUEUE IS EMPTY \n");
    }
    while(q->front != NULL){
        printf("QUEUE FRONT ELEMENT: %d \n", q->front->Element);
        q->front = q->front->next ;

    }
}

int main(){
	struct Queue* q = createQueue();
	enQueue(q, 10);
	enQueue(q, 20);
	enQueue(q, 30);
	enQueue(q, 40);

    show(q);
	delqueue(q);
    show(q);
	return 0;
}
