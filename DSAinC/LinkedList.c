#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next; 
};

struct Node* createNode (int data){
    struct Node* newnode = (struct Node*) malloc (sizeof(struct Node));
    newnode -> data = data;
    newnode -> next = NULL;
    return newnode;
}

void insertatbeginning (struct Node* *head, int data){
    struct Node* temp = createNode (data);
    temp -> next = *head;
    *head = temp;

}
void insertatend (struct Node** head, int data){
    struct Node* Last = createNode (data);
    struct Node* temp = *head;
    while (temp->next != NULL){
        temp = temp -> next;

    }
    
    Last -> next = NULL;
    temp -> next = Last;
}

void insertafteranode (struct Node** head, )

void display(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);  // Print node data with a space
        temp = temp->next;          // Move to the next node
    }
    printf("\n");  // Print a newline at the end for better readability
}


int main(){
    struct Node* head = createNode (10);
    head -> next = createNode (20);
    head -> next -> next = createNode (30);

    insertatbeginning(&head, 0);
    insertatend(&head, 50);
    
    
    display (head);

}