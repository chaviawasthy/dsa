#include<bits/stdc++.h>
using namespace std;

void printFirstNegative(int *arr, int n, int k) {
    deque<int> dq;

    // Process first k elements - first window
    for (int index = 0; index < k; index++) {
        int element = arr[index];
        if (element < 0) {
            dq.push_back(index);
        }
    }

    // Process remaining windows -> Removal and addition of elements
    for (int index = 0; index < n - k + 1; index++) {
        if (dq.empty()) {
            cout << "0" << endl;
        } else {
            cout << arr[dq.front()] << endl;
        }

        // Removal -> Remove elements out of range
        if (!dq.empty() && dq.front() == index) {
            dq.pop_front();
        }

        // Addition
        int nextIndex = index + k;
        if (nextIndex < n && arr[nextIndex] < 0) {
            dq.push_back(nextIndex);
        }
    }
}

int main() {
    int arr[] = {2, -5, 4, -1, -2, 0, 5};
    int n = 7;
    int k = 3;

    printFirstNegative(arr, n, k);

    return 0;
}
