#include <bits/stdc++.h>

using namespace std;

class NStack{
    int *a, *top, *next;
    int n; // Number of stacks
    int size; // Size of the main array
    int freeSpot; // tells Free spot in the main array
    public:
    NStack(int _n, int _s):n(_n), size(_s) {
        freeSpot = 0;
        a = new int[size];
        top = new int[n];
        next = new int[size];

        for (int i = 0; i < n; i++)
        {
            top[i] = -1;
        }

        for (int i = 0; i < size; i++)
        {
            next[i] = i+1;
        }
        next[size-1] = -1;
    }

    //push X in the mth stack
    bool push(int X, int m) {
        if(freeSpot == -1) {
            cout<<"Stack Overflow"<<endl;
            return false;
        }

        //find index
        int index = freeSpot;

        //update free spot
        freeSpot = next[index];

        //insert
        a[index] = X;

        //update next of the new top
        next[index] = top[m-1];

        //update top
        top[m-1] = index;

        return true;
    }

    //pop from mth stack
    int pop(int m) {
        if(top[m-1] == -1) {
            cout<<"Stack Underflow"<<endl;
            return -1;
        }

        //find index
        int index = top[m-1];

        //update top
        top[m-1] = next[index];

        //update next of the new top
        int poppedEle = a[index];
        next[index] = freeSpot;
        //update free spot
        freeSpot = index;

        return poppedEle;
    }

    ~NStack() {
        delete[] a;
        delete[] top;
        delete[] next;
    }
};

int main() {
    NStack s(3,6);
    cout<<s.push(10, 1)<<endl;
    cout<<s.push(10, 1)<<endl;
    cout<<s.push(10, 1)<<endl;
    cout<<s.push(10, 1)<<endl;
    cout<<s.push(10, 1)<<endl;
    cout<<s.push(10, 1)<<endl;
    cout<<s.push(10, 1)<<endl;
    cout<<s.pop(1)<<endl;
    return 0;
}