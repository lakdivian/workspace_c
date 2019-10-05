#include<stdio.h>
#include<stdlib.h>


struct Node {
    int value;
    struct Node *left;
    struct Node *right;
};

struct Node *tree;
int found;

struct Node* createNode(int val){
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->value = val;
    temp->left = NULL;
    temp->right = NULL; 
    return temp;
}

void searchAndInsert(int parent,int child, char direction, struct Node *tree){
    if(tree == NULL){
        return;
    }

    if(tree->value == parent){
        if(direction == 'L'){
            tree->left = createNode(child);
        }
        if(direction == 'R'){
            tree->right = createNode(child);
        }

        return;
    } else {
        //Inserting in the left direction
        searchAndInsert(parent,child,direction,tree->left);
        //Inserting in the right direction
        searchAndInsert(parent,child,direction,tree->right);

        return;
    }
}

void goSearchChildNodes(int mirrNodeOf, struct Node *leftTree, struct Node *rightTree){
            if(leftTree->value == mirrNodeOf){
                printf("%d\n",rightTree->value);
                found = 1;
                return; 
            }
            if(rightTree->value == mirrNodeOf){
                printf("%d\n", leftTree->value);
                found = 1;
                return;
            }

            if(leftTree->left == NULL || rightTree->right == NULL){
                if(leftTree->right == NULL || rightTree->left == NULL){
                    // printf("%d\n", -1);
                    return;
                } else {
                    goSearchChildNodes(mirrNodeOf,leftTree->right,rightTree->left);
                }
            } else {
                goSearchChildNodes(mirrNodeOf,leftTree->left,rightTree->right);
            }

            goSearchChildNodes(mirrNodeOf,leftTree->right,rightTree->left);
}

void findMirrNodeOf(int mirrNodeOf){
    found = 0;
    if(tree->value == mirrNodeOf){
        printf("%d\n",tree->value);
        found = 1;
    } else {
        if(tree->left==NULL || tree->right==NULL){
            found = 1;
            printf("%d\n", -1);
            return;
        }

        goSearchChildNodes(mirrNodeOf,tree->left,tree->right);
        if(found == 0){
            printf("%d\n",-1);
        }
    }
}


int main(){

    // Initializing the root Node
    tree = (struct Node *)malloc(sizeof(struct Node));
    tree->value = 1;
    tree->left = NULL;
    tree->right = NULL;

    int N,Q,i,j,parent,child,mirrNodeOf;
    char direction;
    scanf("%d%d",&N,&Q);
    // printf("N = %d Q = %d\n",N,Q);
    for(i = 0;i < N - 1;i++){
        fscanf(stdin, "%d %d %c", &parent,&child, &direction);
        // printf("p = %d c = %d d = %c\n", parent,child,direction);
        // struct Node *node = createNode(child);
        searchAndInsert(parent,child,direction,tree);
    }

    for(j = 0; j < Q; j++){
        scanf("%d",&mirrNodeOf);
        findMirrNodeOf(mirrNodeOf);
    }


}