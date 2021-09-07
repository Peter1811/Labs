#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>

int count = 0;
struct Node{

    int data;
    struct Node* left;
    struct Node* right;

};

struct Node* createNode(value){
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->right = NULL;
    newNode->left = NULL;

    return newNode;
};

struct Node* insert(struct Node* root, int data){

    if (root == NULL) return createNode(data);
    if (data < root->data) root->left = insert(root->left, data);
    else if (data > root->data) root->right = insert(root->right, data);

    return root;
};

int func(int N, struct Node* node){
  
  if(N==1 && !node->left && !node->right) return 1;
  else if(!node->left && !node->right) {
    return 0; 
  } else{
    if(node->left && node->right){
    return 2;
  }
  else if(node->left){
      N = 1;
      func(N, node->left);
  }
  else if(node->right){
      N = 1;
      func(N, node->right);
   }
  }
}


void inorder(struct Node* root){

    if(root == NULL) return;
    inorder(root->left);
    printf("%d ->", root->data);
    inorder(root->right);
    count++;

}

bool search(struct Node* root, int number) {
    if (root == NULL) return 0;
    else if (number == root->data) return 1;
    else if (number < root->data && root->left != NULL) return search(root->left, number);
    else if (number > root->data && root->right != NULL) return search(root->right, number);
    else return 0;
    }

struct Node* minimum(struct Node* root){
    if (root->left == NULL)
        return root;
    return minimum(root->left);
}

struct Node* delete(struct Node* root, int data){
        if (root == NULL) return root;
        if (data < root->data) root->left = delete(root->left, data);
        else if (data > root->data) root->right = delete(root->right, data);
        else if (root->left != NULL && root->right != NULL){
            root->data = minimum(root->right)->data;
            root->right = delete(root->right, root->data);
        }
        else
            if (root->left != NULL) {
                struct Node* left = root->left;
                free(root);
                root = left;
            }
            else if (root->right != NULL) {
                struct Node* right = root->right;
                free(root);
                root = right;
            }
            else {
                free(root);
                root = NULL;
            }
    return root;
}

struct Node* clear(struct Node* root){
    if(root == NULL) return root;
    if(root->left == NULL && root->right == NULL){
        free(root);
        return NULL;
    }
    if (root->right != NULL){
        root->right = clear(root->right);
    }
    if (root->left != NULL){
        root->left = clear(root->left);
    }
    return clear(root);
}

int main() {

    int N = 0;
    int number = 0;
    char symbol;
    struct Node *root = NULL;
    int f = 0;
    while((symbol = getchar()) != EOF){
        if ((symbol != ' ') && (symbol != '+') && (symbol != 'p') && (symbol != '?') && (symbol != '\n') && (symbol != '-')&&(symbol != 'c')&&(symbol != 's')) {
            number *= 10;
            number += symbol-'0';
        }
        else if (symbol == '+') {
            if (f == 0) {
                root = insert(root, number);
                printf("Element added\n");
                f++;
            }
            else if (f != 0) insert(root, number);
            number = 0;
            }
        else if (symbol == 'p') {
            inorder(root);
            number = 0;
        }
        else if (symbol == '?') {
            if (search(root, number) == 1) printf("Element founded\n");
            else printf( "Element not founded\n");
            number = 0;
        }
        else if (symbol == '-'){
            if (search(root, number) == 1) {
                delete(root, number);
                printf("Element deleted\n");
            }
            else printf("Element not founded\n");
            number = 0;
        }
        else if(symbol == 's'){
            int M = 0;
            printf("%d\n", func(M, root));
        }
        else if(symbol == 'c'){
            clear(&root);
        }
        else {
            continue;
        }
        }
    
    //clear(root);
}
