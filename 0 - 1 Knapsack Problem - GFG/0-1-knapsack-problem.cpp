//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    // int memoization(int idx, int w, vector<vector<int>>& dp, int wt[], int val[]) {
    //     if(idx == 0) {
    //         if(wt[0] <= w)  return val[idx];
    //         return 0;
    //     }
        
    //     if(dp[idx][w] != -1)
    //         return dp[idx][w];
        
    //     int notpick = memoization(idx-1, w, dp, wt, val);
    //     int pick = -1e8;
    //     if(wt[idx] <= w)
    //         pick = val[idx] + memoization(idx-1, w - wt[idx], dp, wt, val);
    //     return dp[idx][w] = max(pick, notpick);
    // }
    
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        // Your code here
        // return memoization(n-1, W, dp, wt, val);
        
        /****TABLUATION****/
        // vector<vector<int>> dp(n+1, vector<int>(W+1, 0));
        // for(int w = wt[0]; w <= W; w++)
        //     dp[0][w] = val[0];
            
        
        // for(int idx = 1; idx < n; idx++) {
        //     for(int w = 0; w <= W; w++) {
        //         int notpick = dp[idx-1][w];
        //         int pick = -1e8;
        //         if(wt[idx] <= w)
        //             pick = val[idx] + dp[idx-1][w - wt[idx]];
                
        //         dp[idx][w] = max(pick, notpick);
        //     }
        // }
        // return dp[n-1][W];
        
        //******SPACE OPTIMIZATION******//
        vector<int> prev(W+1, 0);
        for(int w = wt[0]; w <= W; w++)
            prev[w] = val[0];
        
        for(int idx = 1; idx < n; idx++) {
            for(int w = W; w >= 0; w--) {
                int notpick = prev[w];
                int pick = -1e8;
                if(wt[idx] <= w)
                    pick = val[idx] + prev[w - wt[idx]];
                
                prev[w] = max(pick, notpick);
            }
        }
        return prev[W];
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends