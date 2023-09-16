//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    long long MOD = 1e9 + 7;
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        
        // your code here
        if(n <= 2)  return n;
        long long prev3 = 1;
        long long prev2 = 1;
        long long prev = 2;
        for(int i = 3; i <= n; i++) {
            int curr = (prev + prev2 + prev3)%MOD;
            prev3 = prev2;
            prev2 = prev;
            prev = curr;
        }
        return prev;
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends