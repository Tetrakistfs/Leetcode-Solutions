//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int func(int idx, int previdx, vector<vector<int>>& dp, int arr[], int n) {
	    if(idx == n)    return 0;
	    
	    if(dp[idx][previdx+1] != -1)    return dp[idx][previdx+1];
	    
	    int maxi = func(idx+1, previdx, dp, arr, n);
	    if(previdx == -1 || arr[idx] > arr[previdx]) {
	        maxi = max(maxi, arr[idx] +  func(idx+1, idx, dp, arr, n));
	    }
	    return dp[idx][previdx+1] = maxi; 
	}
	
	
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
	    return func(0, -1, dp, arr, n);
	   // vector<int> res;
	   // res.push_back(arr[0]);
	   // for(int i = 0; i < n; i++) {
	   //     if(arr[i] > res.back()) {
	   //         res.push_back(arr[i]);
	   //     }
	   //     else if(arr[i] < res.back()) {
	   //         vector<int>::iterator it = lower_bound(res.begin(), res.end(), arr[i]);
	   //         if(it != res.end())
	   //             res[it-res.begin()] = arr[i];
	   //     }
	   // }
	   // int ans = 0;
	   // for(auto i : res)
	   //     ans += i;
	   // return ans;
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends