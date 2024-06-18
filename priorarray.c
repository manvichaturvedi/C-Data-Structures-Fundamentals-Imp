#include<stdio.h>
#include<limits.h>

#define MAX 10

int pqValues[MAX];
int pqindexes[MAX];
int rear = -1;

void enqueue(int item, int priority)
{
    if(rear == MAX-1)
    {
        printf("Overflow\n");
    }
    else 
    {
        rear++;

        pqValues[rear] = item;
        pqindexes[rear] = priority;
    }
}

int peek()
{
    int indexPos = INT_MIN;

    if(rear != -1)
    {
        for(int i=0;i<=rear;i++){
            if(pqindexes[i]>indexPos){
                indexPos = pqindexes[i];
            }
        }
        return indexPos;
    }
}

int dequeue()
{
    int p,item,i;
    p=peek();

    for(int i=0;i<=rear;i++)
    {
        if(pqindexes[i] == p){
            item = pqValues[i];
            break;
        }
    }

    if(i<rear){
        for(int j=i;j<rear;j++)
        {
            pqValues[j] = pqValues[j+1];
            pqindexes[j] = pqindexes[j+1];
            item = pqValues[j];
        }
    }
    rear = rear-1;
    return item;
}

void display(){
    int i;
    printf("\nPriority Queue :");
    for(i=0;i<rear;i++){
        printf("\nitem = %d ---- priority = %d",pqValues[i],pqindexes[i]);
    }
}

int main()
{
    enqueue(34,1);
    enqueue(15,2);
    enqueue(14,0);
    enqueue(16,1);

    display();

    dequeue();
    
    printf("\nAfter deletion\n");

    display();

    return 0;
}