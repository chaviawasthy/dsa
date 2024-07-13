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

Node* buildTreeFromPostorderAndInOrderTraversal(map<int, int>& valueToIndexMap, int postOrder[], int inOrder[], int& postIndex, int inOrderStart, int inOrderEnd) {
    if(postIndex < 0 || inOrderStart > inOrderEnd){
        return NULL;
    }

    //1 cas
    int element = postOrder[postIndex--];
    Node* root = new Node(element);
    //search karo inorder me
    int position = valueToIndexMap[element];
    //now rec
    //right ki call
    root->right = buildTreeFromPostorderAndInOrderTraversal(valueToIndexMap, postOrder, inOrder, postIndex, position + 1, inOrderEnd);
    //left ki call
    root->left = buildTreeFromPostorderAndInOrderTraversal(valueToIndexMap, postOrder, inOrder, postIndex, inOrderStart, position - 1);

    return root;
}

int main() {
    // int inOrder[] = {10, 8, 6, 2, 4, 12};
    // int preOrder[] = {2, 8, 10, 6, 4, 12};
    // int size = sizeof(inOrder) / sizeof(inOrder[0]);
    // int preOrderIndex = 0;
    // int inOrderStart = 0;
    // int inOrderEnd = size - 1;
    // map<int, int> valueToIndexMap;
    // createMapping(inOrder, size, valueToIndexMap);

    int inOrder[] = {8, 14, 6, 2, 10, 4};
    int postOrder[] = {8, 6, 14, 4, 10, 2};
    int size = 6;
    int postIndex = size - 1;
    int inOrderStart = 0;
    int inOrderEnd = size - 1;
    map<int, int> valueToIndexMap;
    createMapping(inOrder, size, valueToIndexMap);


    Node* root = buildTreeFromPostorderAndInOrderTraversal(valueToIndexMap, postOrder, inOrder, postIndex, inOrderStart, inOrderEnd);
    // Node* root = buildTreeFromPreorderAndInOrderTraversal(valueToIndexMap, preOrder, inOrder, preOrderIndex, inOrderStart, inOrderEnd);
    cout << "Printing the entire tree:" << endl;
    levelOrderTraversal(root);

    return 0;
}
