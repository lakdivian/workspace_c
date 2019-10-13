#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

typedef struct node Node;

Node *tree;

Node *createNode(int data){
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(Node *newNode){
    Node *start = tree;
    if(start == NULL){
        tree = newNode;
        return;
    }

    while(start){
        if(newNode->data > start->data){
            if(start->right == NULL){
                start->right = newNode;
                break;
            } else {
                start = start->right;
            }
        } else {
            if(start->left == NULL){
                start->left = newNode;
                break;
            } else {
                start = start->left;
            }    
        }
    }

    return;
}

int max(int a, int b){
    return a > b ? a : b;
}

int height(Node *tree){
    if(tree == NULL)
        return 0;
    return 1 + max(height(tree->left), height(tree->right));
}

void printTree(Node *tree){
    if(tree){
        printTree(tree->left);
        printf("%d ", tree->data);
        printTree(tree->right);
    }
}

void main(){

    tree = NULL;
    int N,data,i;
    scanf("%d", &N);
    for(i = 0; i < N; i++){
        scanf("%d", &data);
        Node *newNode = createNode(data);
        insert(newNode);
    }
    printf("%d\n",height(tree));
}

    //        4
    //     2     5
    // 1