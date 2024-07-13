#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
    int data;
    int children_count;
    Node** children; //array of pointers to children

    Node(int value) {
        this->data = value;
        this->children_count = 0;
        this->children = 0;
    }
};

Node* takeInput(){
    int data, count;
    cout<<"enter root data: ";
    cin>>data;
    cout<<"enter children count for: "<<data<<endl;
    cin>>count;
    Node* root = new Node(data);
    root->children_count = count;
    root->children = new Node*[count]; //array to store links to children

    for(int i=0; i<count; i++){
        root->children[i] = takeInput();
    }
    return root;
}

void levelOrderPrint(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            for(int i=0; i<temp->children_count; i++){
                q.push(temp->children[i]);
            }
        }
    }
}

int main(){
    Node* root = takeInput();
    levelOrderPrint(root);

    return 0;
}