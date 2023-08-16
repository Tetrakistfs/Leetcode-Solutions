//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // code here
        typedef pair<int, int> pi;
        priority_queue< pi, vector<pi>, greater<pi>> pq;
        vector<bool> vis(V, false);

        pq.push({0, 0});
        int minSum = 0;
        
        while(!pq.empty()) {
            auto temp = pq.top();
            pq.pop();
            int wt = temp.first;
            int node = temp.second;
            
            
            
            if(vis[node]) continue;
            
            vis[node] = true;
            minSum += wt;
            
            // if(parent != -1)
            // mst.push_back({parent, node});
            for(auto nbr : adj[node]) {
                int nbrnode = nbr[0];
                int edgewt = nbr[1];
                if(!vis[nbrnode]) {
                    pq.push({edgewt, nbrnode});
                }
            }
        }
        
        return minSum;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends