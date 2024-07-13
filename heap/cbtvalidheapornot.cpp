#include<bits/stdc++.h>

using namespace std;

class info{
    public:
    int maxVal;
    bool isHeap;
    info(int a, int b){
        this->maxVal = a;
        this->isHeap=b;
    }
};

Info checkMaxHeap(Node* root){
    //base case
    if(root == NULL){
        info temp;
        temp.maxVal=INT_MIN;
        temp.isHeap = true;
        return temp;
    }

    if(root->left == NULL && root->right == NULL) {
        info temp;
        temp.maxVal = root->data;
        temp.isHeap = true;
        return temp;
    }

    //recursion
    info leftAns = checkMaxHeap(root->left);
    info rightAns = checkMaxHeap(root->right);
    //1 case mujhe solve karna hai
    if(root->data > leftAns.maxVal && root->data > rightAns > rightAns,maxVal && leftAns.isHeap && rightAns.isHeap){
        info ans;
        ans.maxVal = root->data;
        ans.isHeap = true;
        return ans;
    }
    else{
        info ans;
        ans.maxVal = max(root->data, max(leftAns.maxVal, rightAns.maxVal));
        ans.isHeap = false;
        return ans;
    }
}
