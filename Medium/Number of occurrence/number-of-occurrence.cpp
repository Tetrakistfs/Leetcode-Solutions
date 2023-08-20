//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
    
void binarySearch(int l, int h, int x, int arr[], vector<int>& ans) {
    if(l > h)   return;
    int mid = l + (h-l)/2;
    
    if(arr[mid] < x) {
        binarySearch(mid+1, h, x, arr, ans);
    }
    else if(arr[mid] > x) {
        binarySearch(l, mid-1, x, arr, ans);
    }
    else {
        ans.push_back(mid);
        binarySearch(l, mid-1, x, arr, ans);
        binarySearch(mid+1, h, x, arr, ans);
    }
}

	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int count(int arr[], int n, int x) {
	    // code here
	    vector<int> ans;
	    binarySearch(0, n-1, x, arr, ans);
	    return ans.size();
	}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, x;
        cin >> n >> x;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.count(arr, n, x);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends