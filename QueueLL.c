#include<stdio.h>
#include<stdlib.h>


struct node {
    int data;
    struct node* next;
};

struct node* front;
struct node* rear;

void enqueue(int item){
    struct node* new_node;
    new_node = (struct node*)malloc(sizeof(struct node));
    new_node -> data = item;
    new_node -> next = NULL;
    
    if((front == NULL) && (rear == NULL))
    {
        front = rear = new_node;
    }
    else{
        rear->next = new_node;
        rear=new_node;
    }
}

void display()
{
    struct node* temp;
    if(front == NULL && rear == NULL){
        printf("Queue is empty");
        return;
    }
    else{
        temp = front;
        while(temp)
        {
            printf("%d\n",temp-> data);
            temp = temp->next;

        }
        
    }
}

void dequeue(){
    struct node* temp;
    temp = front;

    if(front == NULL && rear == NULL)
    {
        printf("Queue is underflow");
    }
    else
    {

        front  = front->next;
        
        free(temp);
}

}

int main(){
    printf("insertion operation\n");
    enqueue(10);
    enqueue(14);
    enqueue(12);
    enqueue(13);

    display();

    dequeue();
    dequeue();

    printf("after deletion operation\n");


    display();

    return 0;
}
    
