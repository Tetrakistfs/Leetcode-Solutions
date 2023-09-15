//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int subsets(int idx, int sum, int arr[], vector<vector<int>>& dp) {
        if(sum == 0)    return 1;
        if(idx == 0)    return arr[0] == sum;
        
        if(dp[idx][sum] != -1)  return dp[idx][sum];
        
        int notpick = subsets(idx-1, sum, arr, dp);
        int pick = 0;
        if(arr[idx] <= sum)
            pick = subsets(idx-1, sum - arr[idx], arr, dp);
            
        return dp[idx][sum] = pick || notpick;
    }

    int equalPartition(int N, int arr[])
    {
        // code here
        int sum = 0;
        for(int i = 0; i < N; i++)
            sum += arr[i];
            
        vector<vector<int>> dp(N, vector<int>(sum+1, -1));
        if(sum % 2 != 0)    return 0;
        else {
            return subsets(N-1, sum/2, arr, dp);
        }
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends