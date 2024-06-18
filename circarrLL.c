#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node *front=NULL;
struct node *rear=NULL;

int isEmpty()
{
    if(front == NULL && rear == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void enqueue(int d){

    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));

    temp->data = d;
    temp->next=NULL;

    if(isEmpty()){
        front = rear = temp;

        rear->next=front;
    }

    else{
        rear->next = temp;
        rear = temp;
        temp->next = front;
    }
    

}

void dequeue(){
    struct node *temp;
    temp = front;
    if(isEmpty()){
        printf("Queue is empty\n");
    }
    else if(front == rear){
        front = rear = NULL;
        free(temp);
    }
    else{
        front = front->next;
        rear->next = front;
        free(temp);
    }
}

void display(){
    struct node *temp;
    temp = front;
    if(isEmpty()){
        printf("queue is empty\n");
    }
    else{
    printf("\nthe elements in the queue are :\n");
    do{
        printf("%d\t",temp->data);
        temp = temp->next;
    }
    while(temp!=front);
    }
}

int main(){

    dequeue();
    enqueue(3);
    enqueue(6);
    enqueue(7);

    display();

    dequeue();
    dequeue();

    printf("\nAfter deletion:\n");
    display();

    return 0;
}







