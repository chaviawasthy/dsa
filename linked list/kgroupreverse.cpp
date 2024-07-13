#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(){
        this->prev = NULL;
        this->next = NULL;
    }

    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
};

void print(Node* next){
    Node* temp = next;
    while (temp!=NULL)
    {
        cout<<temp->data<<"-->";
        temp = temp->next;
    }
    
}

void insertAtHead(Node* &head, Node* &tail, int data){
    //LL is empty
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }

    else{
        //LL is not empty
        Node* newNode = new Node(data);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

Node* reverse(Node* &head){
    Node* prev = NULL;
    Node* curr = head;

    while (curr!=NULL)
    {
        Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

void addOne(Node* &head){
    //reverse
    head = reverse(head);

    //add1
    int carry = 1;
    Node* temp = head;
    while (temp->next!=NULL)
    {
        int sum = temp->data + carry;
        int digit = sum%10;
        carry = sum/10;
        temp->data = digit;
        temp = temp->next;
        if (carry==0)
        {
            break;
        }
    }

    //process last node
    if (carry!=0)
    {
        int sum = temp->data + carry;
        int digit = sum%10;
        carry = sum/10;
        temp->data = digit;
        if (carry!=0)
        {
            Node* newNode = new Node(carry);
            temp->next = newNode;
            newNode->prev = temp;
        }
    }
    
    //reverse
    head = reverse(head);
}

Node* reverseInKGroup(Node* &head, int k) {
    
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;
    insertAtHead(head, tail, 9);
    insertAtHead(head, tail, 9);
    insertAtHead(head, tail, 9);

    print(head);
    cout<<endl;
    addOne(head);
    print(head);
    cout<<endl;

    return 0;
}