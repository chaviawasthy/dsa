#include<iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* next;


    Node(){
        cout<<"Default constructor called"<<endl;
        this->next = NULL;
    }

    Node(int data){
        cout<<"Parameterized constructor called"<<endl;
        this->data = data;
        this->next = NULL;
    }

    ~Node(){
        cout<<"Destructor called for node with data: "<<this->data<<endl;
    }
};

void printLL(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"-->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

int getLength(Node* head){
    Node* temp = head;
    int count = 0;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    return count;
    
}

void insertAtHead(Node* &head,  Node* &tail, int data){
    if (head==NULL)
    {
        //empty LL

        //step1: create a new node
        Node* newNode = new Node(data);
        //step2: update head
        head = newNode;
        //step3: update tail
        tail = newNode;
    }
    else{
        //non empty LL waala
        
        //create a new node
        Node* newNode = new Node(data);

        //attach a new node to the head
        newNode->next = head;

        //update head
        head = newNode;
    }
    
}

void insertAtTail(Node* &head, Node* &tail, int data){
    if (head == NULL)
    {
        //empty LL
        //step1: create a new node
        Node* newNode = new Node(data);
        //step2: update head
        head = newNode;
        //step3: update tail
        tail = newNode;
        //since single node has list me toh head aur tail ek he jagah pe honge
    }
    else{
        //non empty LL
        //step1: create a new node
        Node* newNode = new Node(data);
        //step2: attach a new node to the tail
        tail->next = newNode;
        //step3: update tail
        tail = newNode;
    }
}

void createTail(Node* head, Node* &tail){
    Node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    //when loop ends temp will be at the last node
    tail = temp;
}

void insertAtPosition(Node* &head, Node* &tail, int data, int pos){
    // if (pos < 1)
    // {
    //     cout<<"Can't insert. Please enter a valid position";
    //     return;
    // }
//assumption is that pos ki value always lies between [1 to length+1]
    int length = getLength(head);
    if (pos == 1)
    {
        insertAtHead(head, tail, data);
    }
    else if (pos == length+1) //insert at tail
    {
        insertAtTail(head, tail, data);
    }
    else{
        //insert at middle of linked list
        //step 1: create a new node
        Node* newNode = new Node(data);
        //step2: traverse prev // curr to position
        Node* prev = NULL;
        Node* curr = head;
        while (pos != 1)
        {
            prev = curr;
            curr = curr->next;
            pos--;
        }
        //step3: attach prev to new node
        prev->next = newNode;
        //step4: attach new node to curr
        newNode->next = curr;
    }
    
}

void deleteNode(Node* &head, Node* &tail, int pos){
    //empty list
    if (head==NULL)
    {
        cout<<"Can't delete. List is empty"<<endl;
        return;
    }

    if (head == tail)
    {
        //single element in list
        Node* temp = head;
        delete temp;
        head = NULL;
        tail = NULL;
        return;
    }
    

    int len = getLength(head);

    //delete from head
    if (pos == 1)
    {
        //first node ko delete karna hai
        Node* temp = head;
        head = head->next;
        //head = temp->next;  //same cheez
        temp->next = NULL;
        delete temp;
    }
    else if(pos == len){
        //last node ko delete karna hai

        //find prev
        Node* prev = head;
        while (prev->next != tail)
        {
            prev = prev->next;
        }
        //prev node ka link null kar do
        prev->next = NULL;

        //node delete karo
        delete tail;

        //update tail
        tail = prev;
        
    }
    else{
        //middle node ko delete karna hai

        //step1: set prev/curr pointers
        Node* prev = NULL;
        Node* curr = head;
        while (pos != 1)
        {
            pos--;
            prev = curr;
            curr = curr->next;
        }

        //step2: prev->next me curr ke next ko add karo
        prev->next = curr->next;

        //step3: node isloate karo
        curr->next = NULL;

        //step4: delete node
        delete curr;
        
    }
    
    
}

int main(){
    // Node a; //static memory allocation
    // Node* b = new Node(); //dynamic memory allocation
    // Node* c = new Node(10);
    // Node* d = new Node(20);
    // Node* e = new Node(30);
    // Node* f = new Node(40);
    // Node* tail = f;

    // c->next = d;
    // d->next = e;
    // e->next = f;

    // Node* head = c;
    // cout<<"Linked List is: "<<endl;
    // printLL(head);

    // insertAtHead(head, tail, 5);
    // insertAtTail(head, tail, 50);
    // printLL(head);

    // cout<<"Length of linked list is: "<<getLength(head)<<endl;

    Node* head = NULL;
    Node* tail = NULL;

    // insertAtHead(head, tail, 10);
    // insertAtHead(head, tail, 20);
    // insertAtHead(head, tail, 30);
    // insertAtTail(head, tail, 50);

    insertAtTail(head, tail, 10);
    insertAtTail(head, tail, 20);
    insertAtTail(head, tail, 30);
    insertAtTail(head, tail, 50);

    printLL(head);

    // insertAtPosition(head, tail, 5, 1);
    insertAtPosition(head, tail, 200, 4);
    printLL(head);

    deleteNode(head, tail, 1);
    printLL(head);

    // deleteNode(head, tail, 4);
    // printLL(head);

    // deleteNode(head, tail, 2);
    // printLL(head);
    return 0;
}