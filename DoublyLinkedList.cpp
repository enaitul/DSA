#include <bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node* next;
    Node* back;

    Node (int data1, Node* next1, Node* back1){
        data = data1;
        next = next1;
        back = back1;
    }

    Node (int data1){
        data = data1;
        next = nullptr;
        back = nullptr;
    }
};

Node* convertarrtoDLL (vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for (int i= 1; i< arr.size(); i++){
        Node* temp = new Node(arr[i],nullptr, prev);
        prev -> next = temp;
        prev = temp;
    }
    
    return head;
}

/*void print(Node* head){
    while (head!=NULL){
        cout<<head->data<<" ";
        head = head->next;
        
    }
}*/
void print(Node* head) {
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

/*Node* DeleteHead (Node* head){
    if (head == NULL || head -> next == NULL) return NULL;
    Node* prev = head;
    head = head-> next;
    head -> next = nullptr;
    prev -> next = nullptr;
    delete prev;
    return head;
}*/
Node* DeleteHead(Node* head) {
    if (head == NULL) return NULL;  // Handle empty list
    if (head->next == NULL) {       // Handle single node list
        delete head;
        return NULL;
    }

    Node* temp = head;      // Store the current head
    head = head->next;      // Move head to the next node
    head->back = nullptr;   // Update the back pointer of the new head

    delete temp;            // Delete the old head
    return head;            // Return the new head
}

Node* DeleteTail (Node* head){
    Node* tail = head;
    while (tail->next != NULL){
        tail = tail->next;
    }
    Node* prev = tail->back;
    prev->next = nullptr;
    tail->back = nullptr;

    return head;
}
/*Node* convertarrtoLL (vector<int> arr){
    Node* head = new Node(arr[0], nullptr);
    Node* mover = head;
    for (int i = 1; i< arr.size(); i++){
        Node* temp = new Node (arr[i], nullptr);
        mover -> next = temp;
        mover = temp;

    }
    return head;
}*/
Node* RemoveKthElement(Node* head, int k){
    if (head == NULL) return NULL;
    Node* KNode = head;
    int cnt=0;
    while (KNode){
        cnt++;
        if (cnt == k) break;
        KNode = KNode -> next;
    }
    if (KNode -> next == NULL && KNode -> back == NULL) return NULL;
    else if (KNode -> next == NULL && KNode -> back!= NULL) return DeleteTail(head);
    else if (KNode -> next != NULL && KNode -> back== NULL) return DeleteHead(head);

    Node* prev = KNode-> back;
    Node* front = KNode -> next;

    prev -> next = front;
    front -> back = prev;

    KNode -> next = nullptr;
    KNode -> back = nullptr;
    delete KNode;
    return head;
}

void deletenode(Node* temp){
    Node* prev = temp -> back;
    Node* front = temp -> next;
    if (front == NULL){
        prev -> next = nullptr;
        temp -> back = nullptr;
        delete (temp);
    }
    prev -> next = front;
    front -> back = prev;
    temp -> next = temp -> back = nullptr;
    delete (temp);
    
    
}

int main(){
    vector<int> arr = {0,1,2,3};
    Node* head = convertarrtoDLL(arr);
    deletenode(head-> next -> next);
    print(head);
    
    
}