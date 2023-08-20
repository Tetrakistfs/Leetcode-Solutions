//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // long long int func(int idx, int sum, vector<vector<long long int>>& dp, int coins[]) {
    //     if(sum == 0)    return 1;
    //     if(idx == 0)
    //         return (sum%coins[0] == 0);
        
    //     if(dp[idx][sum] != -1)  return dp[idx][sum];
        
    //     long long int notPick = func(idx-1, sum, dp, coins);
    //     long long int pick = 0;
    //     if(coins[idx] <= sum)
    //         pick = func(idx, sum-coins[idx], dp, coins);
        
    //     return dp[idx][sum] = pick + notPick;
    // }
    
  
    long long int count(int coins[], int N, int sum) {

        // code here.
        // vector<vector<long long int>> dp(N+1, vector<long long int>(sum+1, -1));
        // return func(N-1, sum, dp, coins);
        
        vector<vector<long long int>> dp(N+1, vector<long long int>(sum+1, 0));
        for(int i = 0; i <= sum; i++) {
            if(i%coins[0] == 0)
                dp[0][i] = 1;
        }
        
        for(int i = 0; i <= N; i++) 
            dp[i][0] = 1;
        
            
        for(int idx = 1; idx < N; idx++) {
            for(int s = 1; s <= sum; s++) {
                long long int notPick = dp[idx-1][s];
                long long int pick = 0;
                if(coins[idx] <= s)
                    pick = dp[idx][s-coins[idx]];
                
                dp[idx][s] = pick + notPick;
            }
        }
        
        return dp[N-1][sum];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends