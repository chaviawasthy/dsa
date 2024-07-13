#include <iostream>
#include <vector>
#include<algorithm>
#include<queue>
using namespace std;

bool cmp(pair<int,int> a, pair<int,int> b) {
	return a.second < b.second;
}

int minMeetings(int st[], int end[], int n) {
	vector<pair<int,int> > time;
	for(int i=0; i<n; i++) {
		time.push_back({st[i], end[i]});
	}
	sort(time.begin(), time.end(),cmp);

	int count = 1;
	int prevStart = time[0].first;
	int prevEnd = time[0].second;

	for(int i=1; i<n; i++) {
		int currStart = time[i].first;
		int currEnd = time[i].second;
		if(currStart > prevEnd) {
			//include current meeting
			count++;
			prevStart = currStart;
			prevEnd = currEnd;
		}
	}
	return count;
}


int fractionalKnapsack(vector<int> val, vector<int> wt, int n, int capacity) {
	vector<float> valWtRatio;
	for(int i=0; i<n; i++) {
		float ratio  = (val[i] * 1.0) / wt[i];
		valWtRatio.push_back(ratio);
	}

	priority_queue<pair<float,pair<int,int> > > maxi;
	for(int i=0; i<n; i++) {
		maxi.push({valWtRatio[i], {val[i], wt[i] } } ); 
	}
	//max heap is ready 
	int totalVal = 0;
	while(capacity != 0 && !maxi.empty() ) {
		auto front = maxi.top();
		float ratio = front.first;
		int value = front.second.first;
		int weight = front.second.second;
		maxi.pop();
		//fulll insert hoga
		if(capacity >= weight) {
			totalVal += value;
			capacity = capacity - weight;
		}
		else {
			//fractional insert hoga
			int valueToInclude = ratio * capacity;
			totalVal += valueToInclude;
			capacity = 0;
			break;
		}
	}
	return totalVal;
}

int solve(int arr[], int n) {
	priority_queue<int,vector<int>, greater<int> > minHeap;
	//insert all elements
	for(int i=0; i<n; i++ ){
		int val = arr[i];
		minHeap.push(val);
	}
	int cost = 0;
	while(minHeap.size() > 1) {
		int a = minHeap.top();
		minHeap.pop();
		int b = minHeap.top();
		minHeap.pop();
		
		cost += a + b;
		int sum = a+ b;
		minHeap.push(sum);
	}
	return cost;
}

int main() {

	int st[] = {10,12,20};
	int end[] = {20,25,30};
	int n = 3;
	int ans = minMeetings(st, end, n);
	cout << "Final Ans: " << ans << endl;
	
	// vector<int> val = {60,100};
	// vector<int> wt = {10,20};
	// int n = 2;
	// int W = 50;
	// int ans = fractionalKnapsack(val,wt,n,W);
	// cout << "Final Ans: " << ans << endl;
	// int arr[] = {4,3,2,6};
	// int size = 4;
	// int ans  = solve(arr,size);
	// cout << "Final Ans: " << ans << endl;

 //  int row = 8;
 //  int col = 15;
 //  int tower = 3;
 //  cout << row << col << tower;
 //  vector<pair<int, int>> loc;
 //  loc.push_back({3, 8});
 //  loc.push_back({11, 2});
 //  loc.push_back({8, 6});

	// vector<int> xDim;
	// xDim.push_back(0);
	// xDim.push_back(col + 1);
	// for(int i=0; i<loc.size(); i++){
	// 	xDim.push_back(loc[i].first);
	// }
	// sort(xDim.begin(), xDim.end());

	// vector<int> yDim;
	// yDim.push_back(0);
	// yDim.push_back(row + 1);
	// for(int i=0; i<loc.size(); i++){
	// 	yDim.push_back(loc[i].second);
	// }
	// sort(yDim.begin(), yDim.end());

	// vector<int> xAns;
	// for(int i=1; i<xDim.size(); i++) {
	// 	int diff = xDim[i] - xDim[i-1] - 1;
	// 	xAns.push_back(diff);
	// }

	// vector<int> yAns;
	// for(int i=1; i<yDim.size(); i++) {
	// 	int diff = yDim[i] - yDim[i-1] - 1;
	// 	yAns.push_back(diff);
	// }

	// int maxi = -1;
	// for(int i=0; i<xAns.size(); i++) {
	// 	for(int j=0; j<yAns.size(); j++) {
	// 		int prod = xAns[i] * yAns[j];
	// 		maxi = max(maxi, prod);
	// 	}
	// }
	// cout << "final ANs: " << maxi << endl;

	
	


  return 0;
}