#include <bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        this->data = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* createTree() {
    cout << "Enter the value for Node: ";
    int value;
    cin >> value;

    if (value == -1) {
        return NULL;
    }

    // Create Node
    Node* root = new Node(value);
    cout << "Enter the left child of " << value << endl;
    root->left = createTree();
    cout << "Enter the right child of " << value << endl;
    root->right = createTree();

    return root;
}

void preOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void postOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

void levelOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; i++) {
            Node* front = q.front();
            q.pop();
            cout << front->data << " ";
            if (front->left != NULL) {
                q.push(front->left);
            }
            if (front->right != NULL) {
                q.push(front->right);
            }
        }
        cout << endl;
    }
}

void printLeftView(Node* root, int level, vector<int>& leftView) {
    if (root == NULL) return;

    if (level == leftView.size()) {
        leftView.push_back(root->data);
    }
    printLeftView(root->left, level + 1, leftView);
    printLeftView(root->right, level + 1, leftView);
}

void printRightView(Node* root, int level, vector<int>& rightView) {
    if (root == NULL) return;

    if (level == rightView.size()) {
        rightView.push_back(root->data);
    }
    printRightView(root->right, level + 1, rightView);
    printRightView(root->left, level + 1, rightView);
}

void printTopView(Node* root){
    map<int, int> hdToNodemap;
    queue<pair<Node*, int>> q;
    q.push(make_pair(root, 0));

    while(!q.empty()){
        pair<Node*, int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;
    //if there is no entry for hd in map then create one
        if(hdToNodemap.find(hd) == hdToNodemap.end()){
            hdToNodemap[hd] = frontNode->data;
        }

        //child ko dekho
        if(frontNode->left != NULL){
            q.push(make_pair(frontNode->left, hd - 1));
        }
        if(frontNode->right != NULL){
            q.push(make_pair(frontNode->right, hd + 1));
        }
    }
    cout<<"Top View: ";
    for(auto i = hdToNodemap.begin(); i != hdToNodemap.end(); i++){
        cout<<i->second<<" ";
    }
    cout<<endl;
}

void printBottomView(Node* root){
    map<int, int> hdToNodemap;
    queue<pair<Node*, int>> q;
    q.push(make_pair(root, 0));

    while(!q.empty()){
        pair<Node*, int> temp = q.front();
        q.pop();

        Node* frontNode = temp.first;
        int hd = temp.second;

        //update the hdToNodemap, ovrwriting the answrs so that the deeper nodes can be stored
        hdToNodemap[hd] = frontNode->data;

        //child ko dekho
        if(frontNode->left != NULL){
            q.push(make_pair(frontNode->left, hd - 1));
        }
        if(frontNode->right != NULL){
            q.push(make_pair(frontNode->right, hd + 1));
        }
    }
    cout<<"Bottom View: ";
    for(auto i = hdToNodemap.begin(); i != hdToNodemap.end(); i++){
        cout<<i->second<<" ";
    }
    cout<<endl;
}

int main() {
    Node* root = createTree();
    cout << "Level Order Traversal: " << endl;
    levelOrderTraversal(root);
    cout << endl;
    cout << "Left View: ";
    vector<int> leftView;
    printLeftView(root, 0, leftView);
    for (int i = 0; i < leftView.size(); i++) {
        cout << leftView[i] << " ";
    }
    cout << endl;
    cout << "Right View: ";
    vector<int> rightView;
    printRightView(root, 0, rightView);
    for (int i = 0; i < rightView.size(); i++) {
        cout << rightView[i] << " ";
    }
    cout << endl;

    printTopView(root);
    printBottomView(root);

    return 0;
}
