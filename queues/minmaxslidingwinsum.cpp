#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int sumOfMinMaxOfAllWindowsOfSizeK(vector<int> nums, int k) {
    deque<int> dq, dq2;
    int ans = 0;

    // Step 1: Process the first window
    for (int i = 0; i < k; i++) {
        // Remove smaller elements from the back of the queue
        while (!dq.empty() && nums[i] >= nums[dq.back()]) {
            dq.pop_back();
        }
        // Remove larger elements from the back of the queue
        while (!dq2.empty() && nums[i] <= nums[dq2.back()]) {
            dq2.pop_back();
        }
        // Insert the current index into the queues
        dq.push_back(i);
        dq2.push_back(i);
    }

    // Add the sum of the min and max elements of the first window to the answer
    ans += nums[dq.front()] + nums[dq2.front()];

    // Step 2: Process the remaining windows - removal and addition
    for (int i = k; i < nums.size(); i++) {
        // Remove elements out of the window range
        if (!dq.empty() && i - dq.front() >= k) {
            dq.pop_front();
        }
        if (!dq2.empty() && i - dq2.front() >= k) {
            dq2.pop_front();
        }
        // Remove smaller elements from the back of the queues
        int element = nums[i];
        while (!dq.empty() && element >= nums[dq.back()]) {
            dq.pop_back();
        }
        while (!dq2.empty() && element <= nums[dq2.back()]) {
            dq2.pop_back();
        }
        // Add the current index to the queues
        dq.push_back(i);
        dq2.push_back(i);
        // Store the sum of the min and max elements of the current window
        ans += nums[dq.front()] + nums[dq2.front()];
    }
    return ans;
}

int main() {
    vector<int> v = {2, 5, -1, 7, -3, -1, -2};
    int k = 3;
    cout << sumOfMinMaxOfAllWindowsOfSizeK(v, k);
    return 0;
}
