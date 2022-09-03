#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int key,height;  //height of a node stores height of subtree formed with this node as root
    struct Node * left,* right;  
}node;

node * createNode(int key){
    node * temp = (node *) malloc(sizeof(node));
    temp -> key = key, temp -> left = temp -> right = NULL,temp -> height = 1;
    return temp;
}

node * search(node * root,int key){ //returns pointer to the node with given key if present in tree
    if(root == NULL) return NULL;
    else if(root -> key < key) return search(root -> right, key);
    else if(root -> key > key) return search(root -> left, key);
    return root;
}

int max(node * root){ //returns maximum subtree height for a node
    if(root -> left == NULL){
        if(root -> right == NULL) return 0;
        return root -> right -> height;
    }
    else if(root -> right == NULL) return root -> left-> height;
    if(root -> right -> height > root -> left -> height) return root -> right -> height;
    return root -> left -> height;
}

node * leftRotate(node * root){
    node * temp = root -> right;
    root -> right = temp -> left, temp -> left = root;
    root -> height = 1 + max(root);    
    temp -> height = 1 + max(temp);
    return temp;
}

node * rightRotate(node * root){
    node * temp = root -> left;
    root -> left = temp -> right, temp -> right = root;
    root -> height = 1 + max(root);    
    temp -> height = 1 + max(temp);
    return temp;
}

node * insert(node * root,int key){
    node * temp; 
    if(root == NULL){
        temp = createNode(key);
        return temp;
    }
    if(search(root, key) != NULL) return root; 
    int hDiff;
    if(root -> key < key) root -> right = insert(root -> right, key);
    else if(root -> key > key) root -> left = insert(root -> left, key);
    root -> height = 1 + max(root);
    hDiff = ((root -> left == NULL)? 0 : root -> left -> height) - ((root -> right == NULL)? 0 : root -> right -> height);
    if(hDiff < -1 && key > root -> right -> key) root = leftRotate(root);
	else if(hDiff > 1 && key < root -> left -> key) root = rightRotate(root);
	else if(hDiff < -1){
		root -> right = rightRotate(root -> right);
		root = leftRotate(root);
	}
	else if(hDiff > 1){
		root -> left = leftRotate(root -> left);
		root = rightRotate(root);
	}
	return root;
}

node * successor(node * root){//successor when right node is not null
    if(root == NULL || root -> right == NULL) return NULL;
    node * temp = root -> right;
    while(temp -> left != NULL) temp = temp -> left;
    return temp;
}

node * delete(node * root,int key){
    node * temp;
    if(root == NULL) return NULL;
    if(root -> key < key) root -> right = delete(root -> right,key);
    else if(root -> key > key) root -> left = delete(root -> left,key);
    else{
        if(root -> left == NULL){
            if(root -> right == NULL){
                free(root);    
                return NULL;
            }
            temp = root -> right;
            free(root);
            return temp;
        }
        else{
            if(root -> right == NULL){
                temp = root -> left;
                free(root);
                return temp;
            }
            temp = successor(root);
            root -> key = temp -> key;
            root -> right = delete(root->right, temp -> key);
        }
    }
    int hDiff;
    root -> height = 1 + max(root);
    hDiff = ((root -> left == NULL)? 0 : root -> left -> height) - ((root -> right == NULL)? 0 : root -> right -> height);
    if(hDiff < -1 && key > root -> right -> key) root = leftRotate(root);
	else if(hDiff > 1 && key < root -> left -> key) root = rightRotate(root);
	else if(hDiff < -1){
		root -> right = rightRotate(root -> right);
		root = leftRotate(root);
	}
	else if(hDiff > 1){
		root -> left = leftRotate(root -> left);
		root = rightRotate(root);
	}
	return root;
}

void printTree(node * root){ //inorder traversal
    if(root == NULL) return;
    printf("%d ",root -> key);
    printTree(root -> left);
    printTree(root -> right);
}

int main(){
    node * root = NULL;
    root = insert(root, );

    root = delete(root, );


    printTree(root);
    printf("\n");
    return 0;
}