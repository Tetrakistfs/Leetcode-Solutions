//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(vector<int>arr, int n, long long s)
    {
        // Your code here
        if(s == 0)  return {-1};
        int i = 0;
        int j = i+1;
        long long sum = arr[i];
        
        while(i <= j && j < n) {
            if(sum > s) {                   //if sum > s slide i till sum < s or it reaches end
                while(i < n && sum > s) {
                    sum = sum - arr[i++];
                }
            }
            else if(sum == s)   break;      //if sum == s then break;
            else {                          //if sum < s then add arr[j] to it and slide j
                sum += arr[j++];
            }
        }
        
        if(sum > s) {                       //if the last element we added get sum > s
            while(i < n && sum > s)
                sum = sum - arr[i++];
        }
        
        if(sum != s)    return {-1};
        return {i+1, j};
    }
};

//{ Driver Code Starts.

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        long long s;
        cin>>n>>s;
        vector<int>arr(n);
        // int arr[n];
        const int mx = 1e9;
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        vector<int>res;
        res = ob.subarraySum(arr, n, s);
        
        for(int i = 0;i<res.size();i++)
            cout<<res[i]<<" ";
        cout<<endl;
        
    }
	return 0;
}
// } Driver Code Ends