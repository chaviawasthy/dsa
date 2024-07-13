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

void createMapping(int inOrder[], int size, map<int, int>& valueToIndexMap) {
    for (int i = 0; i < size; i++) {
        valueToIndexMap[inOrder[i]] = i;
    }
}

Node* buildTreeFromPreorderAndInOrderTraversal(map<int, int>& valueToIndexMap, int preOrder[], int inOrder[], int& preIndex, int inOrderStart, int inOrderEnd) {
    if (inOrderStart > inOrderEnd) {
        return NULL;
    }

    int element = preOrder[preIndex++];
    Node* root = new Node(element);
    if (inOrderStart == inOrderEnd) {
        return root;
    }

    int position = valueToIndexMap[element];
    root->left = buildTreeFromPreorderAndInOrderTraversal(valueToIndexMap, preOrder, inOrder, preIndex, inOrderStart, position - 1);
    root->right = buildTreeFromPreorderAndInOrderTraversal(valueToIndexMap, preOrder, inOrder, preIndex, position + 1, inOrderEnd);

    return root;
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

int main() {
    int inOrder[] = {10, 8, 6, 2, 4, 12};
    int preOrder[] = {2, 8, 10, 6, 4, 12};
    int size = sizeof(inOrder) / sizeof(inOrder[0]);
    int preOrderIndex = 0;
    int inOrderStart = 0;
    int inOrderEnd = size - 1;
    map<int, int> valueToIndexMap;
    createMapping(inOrder, size, valueToIndexMap);

    Node* root = buildTreeFromPreorderAndInOrderTraversal(valueToIndexMap, preOrder, inOrder, preOrderIndex, inOrderStart, inOrderEnd);
    cout << "Printing the entire tree:" << endl;
    levelOrderTraversal(root);

    return 0;
}




// #include<bits/stdc++.h>

// using namespace std;

// class Node {
// public:
//     int data;
//     Node* left;
//     Node* right;
//     Node(int val) {
//         this->data = val;
//         this->left = NULL;
//         this->right = NULL;
//     }
// };

// // Function to create a binary tree
// Node* createTree() {
//     cout << "Enter the value (or -1 to terminate): ";
//     int data;
//     cin >> data;

//     if (data == -1) {
//         return NULL;
//     }

//     // Step 1: Create a new node
//     Node* root = new Node(data);

//     // Step 2: Create left subtree
//     cout << "Enter the left child of " << data << ": ";
//     root->left = createTree();

//     // Step 3: Create right subtree
//     cout << "Enter the right child of " << data << ": ";
//     root->right = createTree();

//     return root;
// }

// void preOrdTraversal(Node* root){
//     //base case
//     if (root == NULL)
//     {
//         return;
//     }

//     //NLR
//     //N
//     cout << root->data << " ";
//     //L
//     preOrdTraversal(root->left);
//     //R
//     preOrdTraversal(root->right);
// }

// void inOrdTraversal(Node* root){
//     //base case
//     if (root == NULL)
//     {
//         return;
//     }

//     //LNR
//     //L
//     inOrdTraversal(root->left);
//     //N
//     cout << root->data << " ";
//     //R
//     inOrdTraversal(root->right);
// }

// void postOrdTraversal(Node* root){
//     //base case
//     if (root == NULL)
//     {
//         return;
//     }

//     //LRN
//     //L
//     postOrdTraversal(root->left);
//     //R
//     postOrdTraversal(root->right);
//     //N
//     cout << root->data << " ";
// }

// void levelOrderTraversal(Node* root){
//     queue<Node*> q;
//     q.push(root);
//     q.push(NULL);

//     //asli traversal start karte hai
//     while (!q.empty())
//     {
//         Node* front = q.front();
//         q.pop();

//         if(front == NULL){
//             cout<<endl;
//             if(!q.empty()){
//                 q.push(NULL);
//             }
//         }

//         else{
//             cout<<front->data<<" ";

//             if(front->left != NULL){
//                 q.push(front->left);
//             }
//             if(front->right != NULL){
//                 q.push(front->right);
//             }
//         }
//     }
    
// }

// int searchInorder(int inOrder[], int size, int element){
//     for (int i = 0; i < size; i++)
//     {
//         if(inOrder[i] == element){
//             return i;
//         }
//     }
//     return -1;
// }

// Node* buildTreeFromPreorderAndInOrderTraversal(int preOrder[], int inOrder[], int preIndex, int inOrderStart, int inOrderEnd, int size) {
//     //base case
//     if(preIndex >= size || inOrderStart > inOrderEnd){
//         return NULL;
//     }

//     //1 case
//     int element = preOrdTraversal[preIndex];
//     preIndex++;
//     Node* root = new Node(element);
//     //search the element in inorder array
//     int position = searchInorder(inOrder, size, element);
//     //rec
//     root->left = buildTreeFromPreorderAndInOrderTraversal(preOrder, inOrder, preIndex, inOrderStart, position-1, size);
//     root->right = buildTreeFromPreorderAndInOrderTraversal(preOrder, inOrder, preIndex, position+1, inOrderEnd, size);

//     return root;
// }

// int main(){
//     int inOrder[] = {10, 8, 6, 2, 4, 12};
//     int preOrder[] = {2, 8, 10, 6, 4, 12};
//     int size = 6;
//     int preOrderIndex = 0;
//     int inOrderStart = 0;
//     int inOrderEnd = 5;

//     Node* root = buildTreeFromPreorderAndInOrderTraversal(preOrder, inOrder, preOrderIndex, inOrderStart, inOrderEnd, size);
//     cout<<"Prinitng the entire tree: "<<endl;
//     levelOrderTraversal(root);
//     return 0;
// }