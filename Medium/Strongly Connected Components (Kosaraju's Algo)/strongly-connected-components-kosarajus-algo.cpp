//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    void dfs_sort(int node, vector<bool>& vis, vector<vector<int>>& adj, stack<int>& s) {
        vis[node] = true;
        
        for(auto nbr : adj[node]) {
            if(!vis[nbr])
                dfs_sort(nbr, vis, adj, s);
        }
        s.push(node);
    }
    
    void dfs(int node, vector<bool>& vis, vector<vector<int>>& adj) {
        vis[node] = true;
        
        for(auto nbr : adj[node]) {
            if(!vis[nbr])
                dfs(nbr, vis, adj);
        }
    }
    
	public:
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        stack<int>s;
        vector<bool> vis(V, false);
        for(int i = 0; i < V; i++) {
            if(!vis[i])
                dfs_sort(i, vis, adj, s);
        }
        
        
        vector<vector<int>> rev_adj(V);         // reverse the graph
        for(int i = 0; i < V; i++) {
            for(auto node : adj[i])
                rev_adj[node].push_back(i);
        }
        
        for(auto i : vis)                       // mark all node as univisted
            i = false;
        
        int cnt = 0;
        while(!s.empty()) {
            int node = s.top();
            s.pop();
            if(!vis[node]) {
                dfs(node, vis, rev_adj);
                cnt++;
            }
        }
        
        return cnt;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends