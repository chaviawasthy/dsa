#include <iostream>
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

// Function to create a binary tree
Node* createTree() {
    cout << "Enter the value (or -1 to terminate): ";
    int data;
    cin >> data;

    if (data == -1) {
        return NULL;
    }

    // Step 1: Create a new node
    Node* root = new Node(data);

    // Step 2: Create left subtree
    cout << "Enter the left child of " << data << ": ";
    root->left = createTree();

    // Step 3: Create right subtree
    cout << "Enter the right child of " << data << ": ";
    root->right = createTree();

    return root;
}

void preOrdTraversal(Node* root){
    //base case
    if (root == NULL)
    {
        return;
    }

    //NLR
    //N
    cout << root->data << " ";
    //L
    preOrdTraversal(root->left);
    //R
    preOrdTraversal(root->right);
}

void inOrdTraversal(Node* root){
    //base case
    if (root == NULL)
    {
        return;
    }

    //LNR
    //L
    inOrdTraversal(root->left);
    //N
    cout << root->data << " ";
    //R
    inOrdTraversal(root->right);
}

void postOrdTraversal(Node* root){
    //base case
    if (root == NULL)
    {
        return;
    }

    //LRN
    //L
    postOrdTraversal(root->left);
    //R
    postOrdTraversal(root->right);
    //N
    cout << root->data << " ";
}

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    //asli traversal start karte hai
    while (!q.empty())
    {
        Node* front = q.front();
        q.pop();

        if(front == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }

        else{
            cout<<front->data<<" ";

            if(front->left != NULL){
                q.push(front->left);
            }
            if(front->right != NULL){
                q.push(front->right);
            }
        }
    }
    
}

int main() {
    Node* root = createTree();
    cout << "Root of the tree: " << root->data << endl;
    cout << "Preorder Traversal: ";
    preOrdTraversal(root);
    cout << endl;
    cout << "Inorder Traversal: ";
    inOrdTraversal(root);
    cout << endl;
    cout << "Postorder Traversal: ";
    postOrdTraversal(root);
    cout << endl;
    cout << "Level Order Traversal: ";
    levelOrderTraversal(root);
    cout << endl;

    return 0;
}
