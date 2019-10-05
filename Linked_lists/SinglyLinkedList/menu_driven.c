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

void AddNodeAtBeginning(){
    int val;
    printf("Enter the value that you wanna add at the beginning\n");
    scanf("%d",&val);
    Node *newNode = createNode(val);

    if(head == NULL){
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }

    return;
}

void AddNodeAtEnd(){
    int val;
    printf("Enter the value that you wanna add at the end\n");
    scanf("%d",&val);
    Node *newNode = createNode(val);
    
    if(head == NULL){
        head = newNode;
    } else {
        Node *iter = head;
        while(iter->next != NULL){
            iter=iter->next;
        }
        iter->next = newNode;
    }

    return;
}

void AddNodeAtMiddle(){
    int val,mid_val;
    printf("Enter the value that you wanna add at the middle\n");
    scanf("%d",&val);
    printf("Enter the value after which you wanna add the value %d\n", val);
    scanf("%d",&mid_val);

    Node *newNode = createNode(val);
    
    if(head == NULL){
        printf("%d Not found in the list\n",mid_val);
    } else {
        Node *iter = head;
        while(iter != NULL && iter->data != mid_val){
            iter=iter->next;
        }
        if(iter == NULL){
            printf("%d is not found in the list\n",mid_val);
            return;
        }
        if(iter->data == mid_val){
            Node *temp = iter->next;
            newNode->next = temp;
            iter->next = newNode;
            return;
        }      
    }

    return;
}

void createLinkedList(){
    int N,i,val;
    if(head != NULL){
        printf("Linked List already exists\n");
        return;
    }
    printf("How many Nodes you have to insert\n");
    scanf("%d",&N);
    for(i=0;i<N;i++){
        scanf("%d", &val);
        Node *temp = createNode(val);
        if(head == NULL){
            head = temp;
        }
        else{
            Node *iter = head;
            while(iter->next != NULL){
                iter = iter -> next;
            }
            iter->next = temp;
        }
    }
}

void DeleteNodeFromBeginning(){
    Node *beg = head;
    if(head == NULL){
        printf("The Linked List is empty, You should have atleast one node to delete\n");
        return;
    }

    head = head->next;
    free(beg);
    return;
}

void DeleteNodeFromEnd(){
    Node *iter = head;
    Node *prev;
    if(head == NULL){
        printf("The Linked List is empty, You should have atleast one node to delete\n");
        return;
    }

    while(iter->next != NULL){
        prev = iter;
        iter = iter->next;
    }

    prev->next = NULL;
    free(iter);
    return;

}

void DeleteNodeFromMiddle(){
    int val;
    Node *iter = head;
    Node *prev;
    if(head == NULL){
        printf("The Linked List is empty, You should have atleast one node to delete\n");
        return;
    }

    printf("Enter the number to be deleted\n");
    scanf("%d", &val);

    while(iter != NULL && iter->data != val){
        prev = iter;
        iter = iter->next;
    }

    if(iter == NULL){
        printf("%d is not found in the linked list\n", val);
        return;
    }

    if(iter->data == val){
        Node *temp = iter->next;
        prev->next = temp;
        free(iter);
        return;
    }
}

void ExitPrograme(){
    printf("This is the end of this menu driven programme\n");
    exit(0);
}

void PrintList(){
    if(head == NULL){
        printf("The Linked List is empty, You should have atleast one node to delete\n");
        return;
    }
    Node *iter = head;
    while(iter != NULL){
        printf("%d ", iter->data);
        iter = iter -> next;
    }
    printf("\n");
}

int main(){

    int options;

    here: printf("Please select one option from below\n");
    printf("1.Create a linked list\n2.Add node at the beginning\n3.Add Node at the end\n4.Add Node at the middle\n5.Delete the node from beginning\n6.Delete the node from end\n7.Delete the node from the middle\n8.Print the current linked list\n9.Exit\n");
    scanf("%d", &options);
    switch(options){
        case 1:
            createLinkedList();
            goto here;
            break;
        case 2:
            AddNodeAtBeginning();
            goto here;
            break;
        case 3:
            AddNodeAtEnd();
            goto here;
            break;
        case 4:
            AddNodeAtMiddle();
            goto here;
            break;
        case 5: 
            DeleteNodeFromBeginning();
            goto here;
            break;
        case 6:
            DeleteNodeFromEnd();
            goto here;
            break;
        case 7:
            DeleteNodeFromMiddle();
            goto here;
            break;
        case 8:
            PrintList();
            goto here;
            break;
        case 9:
            ExitPrograme();
            break;
        default:
            printf("You have Entered a wrong option\n");
            goto here;
    }


}