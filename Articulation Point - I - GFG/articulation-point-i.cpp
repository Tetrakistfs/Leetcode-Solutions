//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    int timer = 0;
    
    void dfs(int node, int parent, vector<int>& vis, vector<int>& tin, vector<int>& low, vector<int> &mark, vector<int> adj[]) {
        vis[node] = true;
        tin[node] = low[node] = timer++;
        
        int child = 0;
        for(int nbr : adj[node]) {
            if(nbr == parent) continue;
            if(!vis[nbr]) {
                dfs(nbr, node, vis, tin, low, mark, adj);
                low[node] = min(low[node], low[nbr]);
                
                if(parent != -1 && low[nbr] >= tin[node])
                    mark[node] = 1;
                child++;
            }
            else {
                low[node] = min(low[node], tin[nbr]);
            }
        }
        
        if(child >= 2 && parent == -1)
            mark[node] = 1;
    }
    
    
  public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        // Code here
        
        vector<int> vis(V, false);
        vector<int> tin(V,0);
        vector<int> low(V,0);
        vector<int> mark(V, 0);
        vector<int> artPoint;
        dfs(0, -1, vis, tin, low, mark, adj);
        
        for(int i = 0; i < V; i++) {
            if(mark[i] == 1)
                artPoint.push_back(i);
        }
        
        if(artPoint.size() == 0)
            artPoint.push_back(-1);
        return artPoint;
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends