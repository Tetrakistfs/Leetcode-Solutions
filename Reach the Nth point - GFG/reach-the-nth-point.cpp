//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
		int nthPoint(int n){
		    // Code here
		    int prev, prev2;
		    prev = prev2 = 1;
		    
		    for(int i = 2; i <= n; i++) {
		        int curr =  (prev + prev2) % 1000000007;
		        prev2 = prev;
		        prev = curr;
		    }
		    return prev%1000000007;
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