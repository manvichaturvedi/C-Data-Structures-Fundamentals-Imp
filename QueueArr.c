#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX 10

//function to insert an element
int front=-1;
int rear=-1;
int Queuearr[MAX];

//for checking queue is full or not

bool isFull(){
    if(rear == MAX-1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//for checking queue is empty or not

bool isEmpty(){
    if(front == -1 && rear == -1)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

void insert(int item){

    if(isFull()){
        printf("Overflow\n");
    }
    else if(isEmpty()){
        front=rear=0;
    }
    else{
        rear=rear+1;
    }
    Queuearr[rear]=item;

}

void dequeue(){
    int y;
    if(isEmpty()){
        printf("Queue is empty\n");
    }
    else if(front==0 && rear==0){
        y=Queuearr[front];
        front = -1;
        rear=-1;
        printf("The item poped is %d\n",y);
        }
    else
    {
        y = Queuearr[front];
        front = front+1;
        printf("The item poped is %d\n",y);
    }
}

void display()
{
    if(isEmpty()){
        printf("Queue is empty");
    }
    else {
        for(int i=front;i<rear;i++){
            printf("%d element of the queue is : %d\n",i, Queuearr[i]);
        }
    }
}

int main()
{
    printf("Adding elements in the queue :\n");
    insert(5);
    insert(10);
    insert(15);
    insert(20);
    insert(25);

    display();

    dequeue();
    dequeue();

    display();

    return 0;

}
