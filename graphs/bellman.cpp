#include <iostream>
#include<unordered_map>
#include<list>
#include<vector>
#include<stack>
#include<limits.h>
using namespace std;

class Graph {
public:
	//unordered_map<int,list<pair<int,int> > > adjList;
	unordered_map<int,list<int> > adjList;

	void addEdge(int u, int v,bool direction) {
		//direction -> 0 -> undorected
		//direction -> 1 -> directed
		if(direction == 0) {
			adjList[u].push_back(v);
			adjList[v].push_back(u);
		}
		else {
			adjList[u].push_back(v);
		}
	}

	// void addEdge(int u, int v, int wt, bool direction) {
	// 	//direction -> 0 -> undorected
	// 	//direction -> 1 -> directed
	// 	if(direction == 0) {
	// 		adjList[u].push_back({v,wt});
	// 		adjList[v].push_back({u,wt});
	// 	}
	// 	else {
	// 		adjList[u].push_back({v,wt});
	// 	}
	// }

	// void printAdjList() {
	// 	for(auto i: adjList) {
	// 		cout << i.first << "-> ";
	// 		for(auto j: i.second) {
	// 			cout <<"{"<<j.first<<", "<<j.second <<"}, ";
	// 		}cout<<endl;
	// 	}
	// }
	// void bellmanFord(int n, char src) {
	// 	//initial state
	// 	vector<int> dist(n,INT_MAX);
	// 	dist[src-'A'] = 0;
	// 	//N-1 times -> RELAXATION
	// 	for(int i=1; i<n; i++) {
	// 		//tarverse on entire edge list
	// 		for(auto a: adjList) {
	// 			for(auto b: a.second) {
	// 				char u = a.first;
	// 				char v = b.first;
	// 				int wt = b.second;
	// 				if(dist[u-'A'] != INT_MAX && dist[u-'A'] + wt < dist[v-'A']) {
	// 					dist[v-'A'] = dist[u-'A'] + wt;
	// 				}
	// 			}
	// 		}
	// 	}
	// 	//yaha tak shorteest distance ready h 
	// 	//check for -ve cycle 
	// 	//1 time relaxation 
	// 	bool anyUpdate = false;
	// 	for(auto a: adjList) {
	// 		for(auto b: a.second) {
	// 			char u = a.first;
	// 			char v = b.first;
	// 			int wt = b.second;
	// 			if(dist[u-'A'] != INT_MAX && dist[u-'A'] + wt < dist[v-'A']) {
	// 				anyUpdate = true;
	// 				break;
	// 				dist[v-'A'] = dist[u-'A'] + wt;
	// 			}
	// 		}
	// 	}

	// 	if(anyUpdate == true) {
	// 		cout << "Negative Cycle Present" << endl;
	// 	}
	// 	else {
	// 		cout << "No Negative Cycle in Graph " << endl;
	// 		cout << "Printing Distance Array: " ;
	// 		for(auto i: dist) {
	// 			cout << i << ", ";
	// 		}cout << endl;
	// 	}
	// }

	// void floydWarshal(int n) {
	// 	//intial state
	// 	vector<vector<int> > dist(n, vector<int>(n, 1e9));
	// 	//diagnol pr 0
	// 	for(int i=0; i<n; i++) {
	// 		dist[i][i] = 0;
	// 	}
	// 	//kuch weights graph k andar bhi given h
	// 	//update dist array accordingly
	// 	for(auto a: adjList) {
	// 		for(auto b: a.second) {
	// 			int u = a.first;
	// 			int v = b.first;
	// 			int wt = b.second;
	// 			dist[u][v] = wt;
	// 		}
	// 	}
	// 	//main logic - helper logic 
	// 	for(int helper = 0; helper < n; helper++) {
	// 		for(int src =0; src < n; src++) {
	// 			for(int dest = 0; dest < n; dest++) {
	// 				dist[src][dest] = min(dist[src][dest], dist[src][helper] + dist[helper][dest]);
	// 			}
	// 		}
	// 	}

	// 	//printing distance array
	// 	for(int i=0; i<n; i++) {
	// 		for(int j=0; j<n; j++ ) {
	// 			cout << dist[i][j] << " ";
	// 		}
	// 		cout << endl;
	// 	}
	// }

	void dfs1(int node, stack<int>& ordering, unordered_map<int,bool>& vis) {
		vis[node] = true;
		for(auto nbr: adjList[node]) {
			if(!vis[nbr]) {
				dfs1(nbr, ordering, vis);
			}
		}
		//wapas aate hue stack me push
		ordering.push(node);
	}
	void dfs2(int src, unordered_map<int,bool>& vis2, unordered_map<int,list<int> >& adjNew) {
		vis2[src] = true;
		cout << src <<"; ";

		for(auto nbr: adjNew[src]) {
			if(!vis2[nbr]) {
				dfs2(nbr, vis2, adjNew);
			}
		}
	}

	int getStronglyConnectedComponents(int n) {
		//step1: get the Ordering
		stack<int> ordering;
		unordered_map<int,bool> vis;

		for(int i=0; i<n; i++ ){
			if(!vis[i]) {
				dfs1(i,ordering,vis);
			}
		}

		//step2: reverse edges
		unordered_map<int, list<int> > adjNew;
		for(auto a: adjList) {
			for(auto b: a.second) {
				int u = a.first;
				int v = b;
				//v -> u ki entry create krni h 
				adjNew[v].push_back(u);
			}
		}
		//step3: traverse using ordering and count components
		int count = 0;
		unordered_map<int,bool> vis2;

		while(!ordering.empty()) {
			int node = ordering.top();
			ordering.pop();
			if(!vis2[node]) {
				cout << "SCC #" << count+1 << ": ";
				dfs2(node, vis2,adjNew);
				count++;
				cout << endl;
			}
		}
		return count;
	}

};

int main() {
	Graph g;
	g.addEdge(0, 1, 1);
	g.addEdge(1, 2, 1);
	g.addEdge(2, 3, 1);
	g.addEdge(3, 0, 1);

	g.addEdge(2, 4, 1);

	g.addEdge(4, 5, 1);
	g.addEdge(5, 6, 1);
	g.addEdge(6, 4, 1);

	g.addEdge(6, 7, 1);
	int n = 8;
  int ans = g.getStronglyConnectedComponents(n);
  cout << "SCC Count: " << ans << endl;

	// g.addEdge(0, 1, 3, 1);
	// g.addEdge(1, 0, 2, 1);
	// g.addEdge(0, 3, 5, 1);
	// g.addEdge(1, 3, 4, 1);
	// g.addEdge(3, 2, 2, 1);
	// g.addEdge(2, 1, 1, 1);
	// g.floydWarshal(4);
	//cout << "hello "<<endl;
	// g.addEdge('A','B', -1,1);
	// g.addEdge('B','E', 2,1);
	// g.addEdge('E','D', -3,1);
	// g.addEdge('D','C', 5,1);
	// g.addEdge('A','C', 4,1);
	// g.addEdge('B','C', 3,1);
	// g.addEdge('B','D', 2,1);
	// g.addEdge('D','B', 1,1);
	//g.printAdjList();
  //g.bellmanFord(5,'A');
	return 0;
}