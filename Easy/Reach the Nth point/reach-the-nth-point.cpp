//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	    int sub(int rem, vector<int> &dp) {
	       // cout<<rem<<endl;
	        if(rem <= 1) {
	            return dp[rem] = 1;
	        }
	        
	        if(dp[rem] != -1) {
	            return dp[rem];
	        }
	       int fs = sub(rem-1, dp);
	       int ss = 0;
	       if(rem > 1)
	            ss = sub(rem-2, dp);
	       return dp[rem] = (fs + ss)%1000000007;
	    }
	
		int nthPoint(int n){
		    // Code here
		    vector<int> dp(n+1, -1);
		    return sub(n, dp)%1000000007;
		  //  for(auto i : dp)
		  //      cout<<i;
		}   
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans  = ob.nthPoint(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends