//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
                                    /****USING PRIORITY QUEUE****/
        // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // pq.push({S,0});
        
        // vector<int> dist(V, 1e9);
        // dist[S] = 0;
        
        // while(!pq.empty()) {
        //     int temp = pq.top().first;
        //     int wt = pq.top().second;
        //     pq.pop();
        //     for(auto node : adj[temp]) {
        //         int adjnode = node[0];
        //         int edgewt = node[1];
        //         if(wt + edgewt < dist[adjnode]) {
        //             dist[adjnode] = edgewt + wt;
        //             pq.push({adjnode, dist[adjnode]});
        //         }
        //     }
        // }
        
        // return dist;
        
                                    /****USING ORDERED SET****/
        set<pair<int, int>> st;
        vector<int> dist(V, 1e9);
        dist[S] = 0;
        st.insert({S, 0});
        
        while(!st.empty()) {
            auto node = *(st.begin());
            int temp = node.first;
            int wt = node.second;
            st.erase(node);
            
            for(auto it : adj[temp]) {
                int adjnode = it[0];
                int edgewt = it[1];
                if(wt + edgewt < dist[adjnode]) {
                    if(dist[adjnode] != 1e9)
                        st.erase({adjnode, edgewt});
                    dist[adjnode] = wt + edgewt;
                    st.insert({adjnode, dist[adjnode]});
                }
            }
        }
        return dist;
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends