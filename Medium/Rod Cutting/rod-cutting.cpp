//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
  public:
//   int memoization(int idx, int length, vector<vector<int>>& dp, int price[], int n) {
//         if(length == 0)
//             return 0;
//         if(idx == 0) {
//             return length*price[0];
//         }
        
//         if(dp[idx][length] != -1)
//             return dp[idx][length];
        
//         int notcut = memoization(idx-1, length, dp, price, n);
//         int cut = 0;
//         if(idx+1 <= length)
//             cut = price[idx] + memoization(idx, length-(idx+1), dp, price, n);
        
//         return dp[idx][length] = max(cut,notcut);
//   }
  
    int cutRod(int price[], int n) {
        //code here
        // vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
        // return memoization(n-1, n, dp, price, n);
        
        /******TABULATION********/
        // vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        // for(int i = 0; i <= n; i++)
        //     dp[0][i] = i*price[0];
        
        // for(int idx = 1; idx < n; idx++) {
        //     for(int length = 0; length <= n; length++) {
        //         int notcut = dp[idx-1][length];
        //         int cut = 0;
        //         if(idx+1 <= length)
        //             cut = price[idx] + dp[idx][length-(idx+1)];
                
        //         dp[idx][length] = max(cut,notcut);
        //     }
        // }
        // return dp[n-1][n];
        
        /****SPACE OPTIMIZATION****/
        vector<int> curr (n+1, 0);
        for(int i = 0; i <= n; i++)
            curr[i] = i*price[0];
        
        for(int idx = 1; idx < n; idx++) {
            for(int length = 0; length <= n; length++) {
                int notcut = curr[length];
                int cut = 0;
                if(idx+1 <= length)
                    cut = price[idx] + curr[length-(idx+1)];
                
                curr[length] = max(cut,notcut);
            }
        }
        return curr[n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        Solution ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
// } Driver Code Ends