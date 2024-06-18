#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node *create_node(int item){
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));

    temp->data = item;
    temp->left = NULL;
    temp->right = NULL;


    return temp;
}

struct node *insert(struct node *root, int item){

    if(root == NULL){
        return create_node(item);
    }
    else if(item < root->data){
        root->left = insert(root->left,item);
    }
    else{
        root->right = insert(root->right,item);
    }

    return root;

}


bool search(struct node *root,int item){
    if(root == NULL || root->data == item){
        return true;
    }
    else if(item>root->data){

        search(root->right,item);

    }
    else{
        return search(root->left,item);
    }
}

struct node *min(struct node *root){
    if(root == NULL){
        return NULL;
    }
    else if(root->left!=NULL){
        return min(root->left);
    }

    return root;
}

void inorder(struct node *root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d\t\t",root->data);
        inorder(root->right);
    }
}

int main(){

    struct node *root;
    root = create_node(20);
    insert(root,5);
    insert(root,1);
    insert(root,15);
    insert(root,9);
    insert(root, 7);
    insert(root,12);
    insert(root,30);
    insert(root,25);
    insert(root,40);
    insert(root,45);
    insert(root,42);

    inorder(root);
    printf("\n");
    if (search(root, 40))
    {
      printf ("Found\n");
    }
    else
    {
      printf ("Not Found\n");
    }


    min(root);


    return 0;


}