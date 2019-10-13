#include <stdio.h>
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

void insertIntoTree(Node *newNode){
    Node *startTree = tree;
    if(startTree == NULL){
        tree = newNode;
        return;
    }

    while(startTree){
        if(startTree->data < newNode->data){
            if(startTree->right == NULL){
                startTree->right = newNode;
                break;
            }
            else {
                startTree = startTree->right;
            }
        } else {
            if(startTree->left == NULL){
                startTree->left = newNode;
                break;
            }
            else {
                startTree = startTree->left;
            }
        }
    }
    return;
}

void preorder(Node *bst, int q){
    if(bst != NULL){
        printf("%d\n", bst->data);
        preorder(bst->left,q);
        preorder(bst->right, q);
    }   
}

void findAndPrintPreorder(Node *bst, int q){
    if(bst->data == q){
        return preorder(bst,q);
    }
    if(q > bst->data){
        return findAndPrintPreorder(bst->right, q);
    }
    if(q < bst->data){
        return findAndPrintPreorder(bst->left, q);
    }
}

void printTree(Node *bst){
    if(bst != NULL){
        printTree(bst->left);
        printf("%d ", bst->data);
        printTree(bst->right);
    }
    return;
}

int main(){
	int num,i,data,q;
	scanf("%d", &num);
    tree = NULL;
	for(i = 0; i < num; i++){
	       scanf("%d", &data);
	       Node *newNode = createNode(data);
	       insertIntoTree(newNode);
	}
	scanf("%d", &q);
	findAndPrintPreorder(tree,q);
    printf("\n"); 
}

