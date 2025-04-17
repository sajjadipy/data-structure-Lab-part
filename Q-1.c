#include<stdio.h>
#include<stdlib.h>

struct nodd {
    int data;
    struct nodd *left;
    struct nodd *right;
};

typedef struct nodd N;

N* create(int data) {
    N* newnode = (N*)malloc(sizeof(N));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

N* insertBST(N* root, int key) {
    if(root == NULL)
        return create(key);
    if(key < root->data)
        root->left = insertBST(root->left, key);
    else if(key > root->data)
        root->right = insertBST(root->right, key);
    return root;
}

void PrintInOrder(N* root) {
    if(root == NULL)
        return;
    PrintInOrder(root->left);
    printf("%d\n", root->data);
    PrintInOrder(root->right);
}

int search(N* root, int key) {
    if(root == NULL)
        return 0;
    if(root->data == key)
        return 1;
    else if(key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

int main() {
    N* root = NULL;
    int student_ID = 40;
    int XX = ((student_ID % 10) + 26);  
    int arr[10] = {26, 44, 73, 30, 111, 122, 86, 116, 52, 130};
    
    for(int i = 0; i < 10; i++) {
        root = insertBST(root, arr[i]);
    }
    
    printf("In-Order Traversal:\n");
    PrintInOrder(root);
    
    printf("\nSearching for XX (%d):\n", XX);
    if(search(root, XX))
        printf("XX Found in BST.\n");
    else
        printf("XX Not Found in BST.\n");
    
    return 0;
}

