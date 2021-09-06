#include <stdio.h>
#include <stdlib.h>

typedef struct BST{
    int i; //the number
    struct BST* left; //initialize pointer to each child
    struct BST* right;
}node;

struct BST* init(int data){//creates and returns new tree node pointer
    struct BST* temp = (struct BST*)malloc(sizeof(struct BST));
    temp->i = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

//recursive function finds correct spot and calls init function, returns pointer to node 
struct BST* insert(struct BST* root, int data){ 
    if (root == NULL)
        return init(data); //if node is empty, create node at this location
    if(data < root->i){ //if entry is less than current node value
        root->left = insert(root->left, data); //run function on left (small) child node
    }else if(data >= root->i){
        root->right = insert(root->right, data);
    }
    
    return root; //return node pointer
}

void minVal(struct BST* root){//find minuimum value 
    if(root->left == NULL){
        printf("%d", root->i); // the leftmost value is printed to console
    }else{//if value has left child
        minVal(root->left);//call function on left child
    }
}

int main(){
    struct BST* root = NULL;//initialize NULL pointer
    root = insert(root, 5); //initialize parent node
    int list[10] = {9,5,0,-1,6,2,3,8,5,1}; 
    for (int j = 0;j<9;j++){ // iterate list to populate tree
        insert(root,list[j]);
    }

    minVal(root);
    return 0;

}