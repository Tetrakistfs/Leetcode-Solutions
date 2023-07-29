//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	void dfs(int node, stack<int>& s, vector<bool>& vis, vector<int> adj[]) {
	    vis[node] = true;
	    
	    for(auto nbr : adj[node]) {
	        if(!vis[nbr])
	            dfs(nbr, s, vis, adj);
	    }
	    s.push(node);
	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	   // vector<int> indegree(V,0);
	   // for(int i = 0; i < V; i++) {
	   //     for(auto nbr : adj[i])
	   //         indegree[nbr]++;
	   // }
	    
	   // queue<int> q;
	   // vector<int> res;
	   // for(int i = 0; i < V; i++)
	   //     if(indegree[i] == 0)
	   //         q.push(i);
	    
	   // while(!q.empty()) {
	   //     int temp = q.front();
	   //     q.pop();
	   //     res.push_back(temp);
	   //     for(auto node : adj[temp]) {
	   //         indegree[node]--;
	   //         if(indegree[node] == 0)
	   //             q.push(node);
	   //     }
	   // }
	   // return res;
	   
	   
        stack<int> s;
        vector<bool> vis(V, false);
        for(int i = 0; i < V; i++) 
            if(!vis[i])
                dfs(i, s, vis, adj);
        
        vector<int> res;
        while(!s.empty()) {
            res.push_back(s.top());
            s.pop();
        }
        return res;
	}
};

//{ Driver Code Starts.

/*  Function to check if elements returned by user
*   contains the elements in topological sorted form
*   V: number of vertices
*   *res: array containing elements in topological sorted form
*   adj[]: graph input
*/
int check(int V, vector <int> &res, vector<int> adj[]) {
    
    if(V!=res.size())
    return 0;
    
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends