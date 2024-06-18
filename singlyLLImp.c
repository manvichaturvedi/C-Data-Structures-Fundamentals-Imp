#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};
struct node* start = NULL;

void insert(){
    struct node* new_node;
    struct node* temp;
    new_node = (struct node *)(malloc(sizeof(struct node)));

    if(new_node == NULL){
        printf("list is full");
        exit(0);
    }
    printf("\nenter the element in the node:");
    scanf("%d",&new_node->data);
    new_node->next=NULL;
    if(start == NULL){
        printf("\nlist is empty\n");
            start=new_node;
        }
        else{
            temp = start;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=new_node;
            }
    }

    void display(){
        struct node* temp;
        if(start==NULL)
        {
            printf("\nlist is empty:");
        }
        else{
            
            temp=start;
            printf("\nthe list elements are:\n");
            while(temp!=NULL){
                printf("%d\t\t",temp->data);
                temp=temp->next;
            }
        }
    }

    void insert_beg(){
        struct node* temp;
    
        temp = (struct node*)malloc(sizeof(struct node));

        printf("\nenter element in the new node\n");
        scanf("%d",&temp->data);
        temp->next = NULL;

        if(start == NULL)
        {
            printf("\nlist is empty\n");
            start = temp;


        }
        else{
            temp->next = start;
            start=temp;
        }
    }

    void insert_end()
    {
         struct node* temp;
         struct node* ptr;
    
        temp = (struct node*)malloc(sizeof(struct node));

        printf("\nenter element in the new node\n");
        scanf("%d",&temp->data);
        temp->next = NULL;
        if(start == NULL)
        {
            printf("\nlist is empty\n");
            start = temp;
        }
        else{
            ptr = start;
            while(ptr->next!=NULL){
                ptr=ptr->next;
            }
            ptr->next=temp;
        }


        
    }

    void delete_beg(){
        struct node *temp;

        if(start==NULL)
        {
            printf("\nlist is empty\n");
        }
        else{
             temp=start;
             start=start->next;
             free(temp);
             }
        }

        void delete_end(){
            struct node *temp;
            struct node *ptr;

             if(start==NULL)
             {
                 printf("\nlist is empty\n");
              }
              else if(start->next==NULL){
                ptr=start;
                start=NULL;
                free(ptr);

              }
              else{
                ptr = start;
                while(ptr->next!=NULL){

                    temp=ptr;

                    ptr=ptr->next;
                }
                     temp->next=NULL;
                     free(ptr);
              }

        }
    

    int main()
    {
        insert();
        insert();
        insert();
        insert();
        display();
        insert_beg();
        display();
        insert_end();
        
        display();

        delete_beg();

        display();

        delete_end();

        display();

        return 0;
    }

