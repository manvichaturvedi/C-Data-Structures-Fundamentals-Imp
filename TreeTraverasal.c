#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *firstchild;
    struct node *secondchild;
};

/*create a new node */

struct node *createNode(int value){
    struct node *new_Node = (struct node *)malloc(sizeof(struct node));

    new_Node->data = value;
    new_Node->firstchild = NULL;
    new_Node->secondchild=NULL;

    return (new_Node); 
}

/* PreOrder Traversal */

void TravarsePreorder(struct node *root){
    if(root != NULL){
        
        printf("%d\t",root->data);
        TravarsePreorder(root->firstchild);
        TravarsePreorder(root->secondchild);
   }
}

/* postOrder Traversal */

void postOrderTraversal(struct node *root){
    if(root!=NULL){
        

       postOrderTraversal(root->firstchild);
       postOrderTraversal(root->secondchild);
       printf("%d\t",root->data);

    }

    
}

/* InOrderTraversal */

void InOrderTraversal(struct node *root){
    if(root!=NULL){
    

         InOrderTraversal(root->firstchild);
         printf("%d\t",root->data);
         InOrderTraversal(root->secondchild);

    }
}


int main(){
    struct node *root = createNode(36);
    root->firstchild = createNode(26);
    root->secondchild = createNode(46);
    root->firstchild->firstchild = createNode(21);
    root->secondchild->secondchild = createNode(56);
    root->firstchild->secondchild = createNode(31);
    root->firstchild->firstchild->firstchild = createNode(11);
    root->firstchild->firstchild->secondchild = createNode(24);
    root->secondchild->firstchild = createNode(41);
    root->secondchild->secondchild->firstchild = createNode(51);
    root->secondchild->secondchild->secondchild = createNode(66);

    printf("\n PreOrder Traversal \n");
    TravarsePreorder(root);

    printf("\n postOrderTraversal \n");
    postOrderTraversal(root);

    printf("\n InOrder Traversal \n");
    InOrderTraversal(root);


    return 0;

    
    }




