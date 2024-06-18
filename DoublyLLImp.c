#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *prev;
    struct node *next;

};
struct node *head;

void insert_beg(int item){
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    if(temp==NULL){
        printf("\noverflow");
    }
    else{
        if(head==NULL){
            printf("\n list is empty\n");
            temp->data=item;
            temp->prev=NULL;

            temp->next=NULL;
            
            head=temp;


        }
        else{
            temp->data=item;
            temp->prev=NULL;
            temp->next=head;
            head->prev=temp;
            head=temp;
        }

    }

}

void delete_beg(){
    struct node *temp;
    if(head==NULL){
        printf("\nempty list\n");
    }
    else if(head->next==NULL){
        temp=head;
        head=NULL;
        free(temp);
    }
    else{
        temp=head;
        head=head->next;
        head->prev=NULL;
        free(temp);
    }
}

void delete_end(){
    struct node *temp,*ptr;
    if(head==NULL){
        printf("\nempty list\n");
    }
    else if(head->next==NULL){
        temp=head;
        head=NULL;
        free(temp);

    }
    else{
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->prev->next = NULL;
        free(temp);

    }
}
void display(){
    struct node *temp;
    printf("\nprinting values\n");
    temp=head;
    while(temp!=NULL){
        printf("%d\t",temp->data);
        temp = temp->next;
    }
}

void insert_end(int item){
    struct node *temp,*ptr;
    temp = (struct node *)malloc(sizeof(struct node));
    if(temp==NULL){
        printf("\nfully filled list\n");
    }
    else{
        if(head==NULL){
            printf("\nempty list\n");
            temp->data=item;
            temp->next=NULL;
            temp->prev=NULL;
            head=temp;
        }
        else{
              ptr=head;
              while(ptr->next!=NULL){
                ptr=ptr->next;
              }

              ptr->next=temp;
              temp->data=item;

              temp->prev=ptr;
              temp->next=NULL;
              

        }
    }

    
}

void search()  
{  
    struct node *ptr;  
    int item,i=0,flag;  
    ptr = head;   
    if(ptr == NULL)  
    {  
        printf("\nEmpty List\n");  
    }  
    else  
    {   
        printf("\nEnter item which you want to search?\n");   
        scanf("%d",&item);  
        while (ptr!=NULL)  
        {  
            if(ptr->data == item)  
            {  
                printf("\nitem found at location %d ",i+1);  
                flag=0;  
                break;  
            }   
            else  
            {  
                flag=1;  
            }  
            i++;  
            ptr = ptr -> next;  
        }  
        if(flag==1)  
        {  
            printf("\nItem not found\n");  
        }  
    }     
          
}  


int main(){
    insert_beg(3);
    insert_beg(2);
    insert_beg(4);

    display();

    insert_end(6);
    insert_end(9);
    display();

    delete_beg();
    delete_end();

    display();

    search();


    return 0;
}



