#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        this->data = value;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertIntoBST(Node* root, int data) {
    if (root == NULL) {
        root = new Node(data);
        return root;
    }

    if (data > root->data) {
        root->right = insertIntoBST(root->right, data);
    } else {
        root->left = insertIntoBST(root->left, data);
    }
    return root;
}

void createBST(Node* &root) {
    cout << "Enter data (enter -1 to terminate):" << endl;
    int data;
    cin >> data;

    while (data != -1) {
        root = insertIntoBST(root, data);
        cout << "Enter data (enter -1 to terminate):" << endl;
        cin >> data;
    }
}

void printLinkedList(Node* head) {
    cout << "Flattened Linked List: ";
    while (head != NULL) {
        cout << head->data << "->";
        head = head->right;
    }
    cout << "NULL" << endl;
}

Node* flatten(Node* root) {
    if (root == NULL) return NULL;

    Node* dummy = new Node(-1);
    Node* prev = dummy;
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();

        prev->right = curr;
        prev = curr;

        if (curr->left != NULL) {
            q.push(curr->left);
        }

        if (curr->right != NULL) {
            q.push(curr->right);
        }
    }

    root = dummy->right;
    delete dummy;
    return root;
}

int main() {
    Node* root = NULL;
    createBST(root);
    cout << "Level Order Traversal:" << endl;
    levelOrderTraversal(root);

    root = flatten(root);
    printLinkedList(root);

    return 0;
}
