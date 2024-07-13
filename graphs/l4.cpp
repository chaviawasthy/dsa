class Solution {
public:
    void solve(int src, int parent, unordered_map<int,list<int> >& adj, int &timer, 
    vector<vector<int>>& ans,vector<int>& tin,vector<int>& low,unordered_map<int,bool>& vis ) {
        
        vis[src] = true;
        tin[src] = timer;
        low[src] = timer;
        timer++;

        //nbrs
        for(auto nbr: adj[src]) {
            if(nbr == parent) {
                //ignore this
                continue;
            }
            if(!vis[nbr]) {
                //step1
                solve(nbr, src, adj, timer, ans, tin, low, vis);
                //low update
                low[src] = min(low[src], low[nbr]);
                //bridge testing
                if(low[nbr] > tin[src]) {
                    vector<int> temp;
                    temp.push_back(src);
                    temp.push_back(nbr);
                    ans.push_back(temp);
                }

            }
            else {
                //ek or raasta milgya 
                //low update
                low[src] = min(low[src], low[nbr]);
                //no need of bridge testing
            }
        }


    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        unordered_map<int,list<int> > adj;
        for(auto vec: connections) {
            int u = vec[0];
            int v = vec[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        //main logic 
        int timer = 1;
        vector<vector<int>> ans;
        vector<int> low(n,0);
        vector<int> tin(n,0);
        int src = 0;
        int parent = -1;
        unordered_map<int,bool> vis;
        solve(src, parent, adj,timer,ans, tin, low,vis);
        return ans;
    }
};