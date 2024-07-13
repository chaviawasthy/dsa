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

int findLength(Node* &head){
    Node* temp = head;
    int len = 0;
    while (temp!=NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
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

void insertAtTail(Node* &head, Node* &tail, int data){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else{
        Node* newNode = new Node(data);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void insertAtMiddle(Node* &head, Node* &tail, int data, int pos){

    if(head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else{
        int len = findLength(head);
        if (pos == 1)
        {
            insertAtHead(head, tail, data);
        }
        else if(pos == len+1){
            insertAtTail(head, tail, data);
        }
        else{
            //insert in middle
            //step1: create a new node
            Node* newNode = new Node(data);
            //step2: ste prev/curr pointer
            Node* prevNode = NULL;
            Node* currNode = head;
            while (pos != 1)
            {
                pos--;
                prevNode = currNode;
                currNode = currNode->next;
            }
            //step3: attach prev to new node
            prevNode->next = newNode;
            newNode->prev = prevNode;
            //step4: attach new node to curr
            newNode->next = currNode;
            currNode->prev = newNode;
        }
        
    }
    // if(pos == 0){
    //     insertAtHead(head, tail, data);
    // }
    // else if(pos >= findLength(head)){
    //     insertAtTail(head, tail, data);
    // }
    // else{
    //     Node* temp = head;
    //     Node* newNode = new Node(data);
    //     for(int i = 0; i < pos-1; i++){
    //         temp = temp->next;
    //     }
    //     newNode->next = temp->next;
    //     temp->next->prev = newNode;
    //     temp->next = newNode;
    //     newNode->prev = temp;
    // }
}

void deleteNode(Node* &head, Node* &tail, int pos){
    if (head == NULL)
    {
        //LL is empty
        cout<<"Can't delete. List is empty"<<endl;
        return;
    }

    if (head==tail)
    {
        Node* temp = head;
        delete temp;
        head = NULL;
        tail = NULL;
    }
    
    int len = findLength(head);

    if (pos == 1)
    {
        //delete from head
        Node* temp = head;
        head = head->next;
        head->prev = NULL;
        temp->next = NULL;
        delete temp;
    }
    else if(pos == len){
        //delete from tail
        Node* prevNode = tail->prev;
        prevNode->next = NULL;
        tail->prev = NULL;
        delete tail;
        tail = prevNode;
    }
    else{
        //delete from middle
        //step1: set prev/curr/next pointer
        Node* prevNode = NULL;
        Node* currNode = head;
        while (pos != 1)
        {
            pos--;
            prevNode = currNode;
            currNode = currNode->next;
        }
        Node* nextNode = currNode->next;
        prevNode->next = currNode->next;
        currNode->next = NULL;
        currNode->prev = NULL;
        nextNode->prev = prevNode;
        delete currNode;
    
    }
    
}

void revrseUsingRec(Node* prev, Node* curr) {
        //base case
        if(curr == NULL){
            return prev;
        }
        //1 case
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;

        //rec case
        return revrseUsingRec(prev, curr);
}

Node* checkLoop(Node* &head) {
    Node* slow = head;
    Node* fast = head;

    while(fast!=NULL){
        fast = fast->next;
        if(fast!=NULL){
            fast = fast->next;
            slow = slow->next;
        }
        //check for cycle
        if(slow == fast){
            return true;
        }
    }
    return false;
}

Node* getStartingPointOfLoop(Node* &head){
    //check for loop
    Node*slow = head;
    Node*fast = head;
    while(fast != NULL) {
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }

        if (fast == slow)
        {
            break;
        }
    }

    //yaha aana, means slow and fasr are at same point
    slow = head;
    while(fast!=slow){
        fast = fast->next;
        slow = slow->next;
    }
    //return starting point of loop
    return slow;
}

void removeLoop(Node* &head) {
     //check for loop
    Node*slow = head;
    Node*fast = head;
    while(fast != NULL) {
        fast = fast->next;
        if(fast != NULL){
            fast = fast->next;
            slow = slow->next;
        }

        if (fast == slow)
        {
            break;
        }
    }

    //yaha aana, means slow and fasr are at same point
    slow = head;
    while(fast!=slow){
        fast = fast->next;
        slow = slow->next;
    }
    //starting point of loop
    Node* startPoint = slow;

    Node* temp = fast;  //fast = startPoint ya slow ek he jagah point klar raha hai
    while(temp->next != startPoint){
        temp = temp->next;
    }

    temp->next = NULL;
}

int main(){
    // Node* head = new Node(10);

    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head, tail, 40);
    insertAtHead(head, tail, 30);
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 10);
    print(head);

    insertAtMiddle(head, tail, 25, 3);
    cout<<endl;
    print(head);
    deleteNode(head, tail, 3);
    cout<<endl;
    print(head);
    deleteNode(head, tail, 1);
    cout<<endl;
    print(head);

    // tail->next = head->next->next;
    // cout<<checkLoop(head)<<endl;
    // cout<<getStartingPointOfLoop(head)->data<<endl;

    tail->next = head->next;
    cout<< getStartingPointOfLoop(head)->data<<endl;
    removeLoop(head);
    cout<< getStartingPointOfLoop(head)->data<<endl;
    print(head);
    // insertAtTail(head, tail, 1000);
    // print(head);
    return 0;
}