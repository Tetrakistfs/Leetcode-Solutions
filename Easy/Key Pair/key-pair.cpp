//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// Function to check if array has 2 elements
	// whose sum is equal to the given value
	bool binarySearch(int l, int h, int key, int arr[], int n) {
	    if(l > h)   return false;
	    int mid = l + (h-l)/2;
	    
	    if(arr[mid] == key) return true;
	    else if(key > arr[mid]) {
	        return binarySearch(mid+1, h, key, arr, n);
	    }
	    else {
	        return binarySearch(l, mid-1, key, arr, n);
	    }
	}
	
	bool hasArrayTwoCandidates(int arr[], int n, int x) {
	    // code here
	    sort(arr, arr+n);
	    for(int i = 0; i < n; i++) {
	        if(arr[i] <= x) {
	            int target = x - arr[i];
	            if(binarySearch(i+1, n-1, target, arr, n))   
	                return true;
	        }
	    }
	    
	    return false;
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
        auto ans = ob.hasArrayTwoCandidates(arr, n, x);
        cout << (ans ? "Yes\n" : "No\n");
    }
    return 0;
}

// } Driver Code Ends