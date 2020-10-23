#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    struct Node *next;
};

Node* XOR(Node *A, Node *B ) {

    return reinterpret_cast<Node*>(
        reinterpret_cast<uintptr_t> (A) ^ reinterpret_cast<uintptr_t> (B)
    );

}

void printList(Node **head) {
    if(*head == NULL) {
        cout<<"\nNULL";
        return;
    }
    Node* temp = *head;
    Node* PREV = NULL;
    while(temp != NULL) {
        Node *T = temp;
        cout<<temp->data<<" ";
        temp = XOR(temp->next, PREV);
        PREV = T;
    }
    return;
}

void insert(Node **head, int val) {
    Node *temp = new Node();
    temp->data = val;
    temp->next = *head;
    if(*head != NULL) {
        (*head)->next = XOR(temp, (*head)->next);
    }
    *head = temp;
    //printList(*head);
}



int main()
{
    Node *head = NULL;
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);
    insert(&head, 50);
    printList(&head);
    return 0;
}