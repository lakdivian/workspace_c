#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *next;
};

typedef struct node Node;

Node *head = NULL;

Node *createNode(int data){
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void insertNode(Node *newNode){
    if(head == NULL){
        head = newNode;
    } else {
        Node *iter = head;
        while(iter->next != NULL){
            iter=iter->next;
        }

        iter->next = newNode;
    }
}

void print_list(){
    Node *iter = head;
    while(iter != NULL){
        printf("%d ", iter->data);
        iter = iter -> next;
    }
    printf("\n");
}

int main(){

    int N,i,j,val;
    printf("How many Nodes you have to insert\n");
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d", &val);
        insertNode(createNode(val));
    }

    printf("The list you have entered is\n");
    print_list();

}