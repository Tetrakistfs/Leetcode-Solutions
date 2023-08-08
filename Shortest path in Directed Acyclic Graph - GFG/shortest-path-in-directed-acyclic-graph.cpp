//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    void topoSort(int node, vector<vector<pair<int, int>>>& adj, stack<int>& s, vector<bool>& vis) {
        vis[node] = true;
        for(auto temp : adj[node]) {
            if(!vis[temp.first])
                topoSort(temp.first, adj, s, vis);
        }
        
        s.push(node);
    }
  
    vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<vector<pair<int, int>>> adj(N);
        for(int i = 0; i < M; i++) {
            adj[edges[i][0]].push_back(make_pair(edges[i][1], edges[i][2]));
        }
        
        vector<bool> vis(N, false);
        stack<int> s;
        
        for(int i = 0; i < N; i++) {
            if(!vis[i])
                topoSort(i, adj, s, vis);
        }
        
        vector<int> dist(N,1e9);
        dist[0] = 0;
        
        while(!s.empty()) {
            int temp = s.top();
            s.pop();
            for(auto node : adj[temp]) {
                if(dist[temp] + node.second < dist[node.first])
                    dist[node.first] = dist[temp] + node.second;
            }
        }
        
        for(int i = 0; i < N; i++)
            if(dist[i] == 1e9)  
                dist[i] = -1;
        
        return dist; 
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends