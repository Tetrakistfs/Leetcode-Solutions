//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    // int memoization(int idx, int weight, int val[], int wt[], int n) {
    //     if(weight == 0)
    //         return 0;
    //     if(idx == 0)
    //         return (weight/wt[0]) * val[0];
            
        
    //     int notpick = memoization(idx-1, weight, val, wt, n);
    //     int pick = INT_MIN;
    //     if(wt[idx] <= weight)
    //         pick = val[idx] + memoization(idx, weight-wt[idx], val, wt, n);
        
    //     return max(pick, notpick);
    // }

    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        // memoization(N-1, W, val, wt, N);
        
        vector<int> curr(W+1, 0);
        for(int i = 0; i <= W; i++) {
            curr[i] = (i/wt[0]) * val[0];
        }
        
        for(int idx = 0; idx < N; idx++) {
            for(int weight = 0; weight <= W; weight++) {
                int notpick = curr[weight];
                int pick = INT_MIN;
                if(wt[idx] <= weight)
                    pick = val[idx] + curr[weight-wt[idx]];
                
                curr[weight] = max(pick, notpick);
            }
        }
        return curr[W];
        
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends