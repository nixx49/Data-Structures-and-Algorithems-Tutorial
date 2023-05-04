//AA1885

#include <pthread.h> 
#include <stdio.h>
#include <stdlib.h> 
#include <assert.h>  
#include <semaphore.h>  
#include <unistd.h>

sem_t lock, items;

/* to compile use -lpthread */
void * producer(void *); 
void * consumer(void *); 


/* Linked list implementation */
struct node {
  int data;
  struct node *next;
};

typedef struct node node_t;
typedef node_t ** linked_t;

// List operations
linked_t create_list(void); // create a new empty list 
void enqueue(linked_t list, int data); // insert the given item. Can fail 
int dequeue(linked_t list, int *data); /* If there are items remove first and
				       * store value in data and return 1. 
				       * return 0 otherwise */
int isEmpty(linked_t list); // return 1 if list is empty 

/***********************************************************
 * Need to implement suitable synch primitives
 * The given code will work for a single thread not when
 * you have many.
 * Assume you have a single list  
 ***********************************************************/
linked_t create_list(void)
{
  node_t ** tmp = (linked_t) malloc(sizeof(linked_t));
  *tmp = NULL;
  return tmp;
}

int isEmpty(linked_t list)
{
  return (*list == NULL);
}

void enqueue(linked_t list, int val)
{
  node_t ** head = list;
 
  node_t * tmp = (node_t *)malloc(sizeof(node_t));
  assert(tmp != NULL);
  
  tmp -> data = val;
  tmp -> next = NULL;

  if(*head == NULL) *head = tmp;
  else {
    node_t * cur = *head, *pre = *head;
    while(cur != NULL) {
      pre = cur;
      cur = cur -> next;
    }
    pre -> next = tmp;
  }

  return;
}

int dequeue(linked_t list, int *ret)
{
  node_t * head = *list;
  if(isEmpty(list)) return 0;

  *ret = head -> data; 
  node_t * tmp = head;
  
  *list = head -> next; 
  free(tmp);
  return 1;
}

/*************************************************
 * Producer and comsumer threads 
 * Need to put proper sychronization primitives
 **************************************************/
linked_t list;
#define SIZE 100

void * producer(void *p)
{
  int i, val;
  // producer need not sleep
  // buffer will never be full
  // enqueue should be thread safe 
  for(i=0; i < SIZE; i++) { 
    val = rand() % 20; // produce value 
    sem_wait(&lock);
    enqueue(list, val);  // insert to buffer
    sem_post(&lock);
    sem_post(&items);
    usleep(rand() % 10); 
  }
  printf("%s: Done\n", __func__);
}

void * consumer(void *p) 
{ 
  int i, val; 
  for(i=0; i < SIZE; i++) {
      
    // need to sleep if the buffer is empty
    // suppose there is one item only. 
    // how to make sure that other consumer did not consume the item 
    
	sem_wait(&items);
    sem_wait(&lock);
    assert(dequeue(list, &val));

    printf("got: %d\n", val);  
    sem_post(&lock);
    usleep(rand() % 10); 
  }
  
  printf("%s: Done\n", __func__); 
}



int main()
{
  pthread_t c1,c2, p1,p2;
  list = create_list(); 
  
  //create two consumers and two producers
  // Need to initialize synchronization primitives
  
  sem_init(&lock, 0, 1);
  sem_init(&items, 0, 0);
  
  // here after the code should be fine. No need to worry 
  
  assert(!pthread_create(&c1, NULL, consumer, NULL));
  assert(!pthread_create(&c2, NULL, consumer, NULL));

  assert(!pthread_create(&p1, NULL, producer, NULL));
  assert(!pthread_create(&p2, NULL, producer, NULL));

  void *dummy;
  pthread_join(c1, &dummy);
  pthread_join(c2, &dummy);


  pthread_join(p1, &dummy);
  pthread_join(p2, &dummy);

  sem_destroy(&lock); 
  sem_destroy(&items); 
  
  //If all was OK, you should be here and list should be empty 
  if(isEmpty(list)) printf("Looks good!\n");
  else printf("Almost! Somethingn wrong\n");

  return 0;
}