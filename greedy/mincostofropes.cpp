#include<bits/stdc++.h>

using namespace std;

int main(){
    int arr[] = {4,3,2,6};
    int n = 4;
    priority_queue<int, vector<int>, greater<int>> pq(arr, arr+n);
    int cost = 0;
    while(pq.size() > 1){
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();
        cost += a+b;
        pq.push(a+b);
    }
    cout<<cost<<endl;
    return 0;
}