//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
public:
      string maxSum(string w,char x[], int b[],int n){
          // code here
          int l = w.length();
          int val[l];

          for(int i = 0; i < l; i++) {
              val[i] = int(w[i]);
            for(int j = 0; j < n; j++) {
                if(w[i] == x[j])
                    val[i] = b[j]; 
            }
          }
          
          string curr_str = "";
          string max_str = "";
          int max_ending_here = 0;
          int max_ending_soFar = -1e9;
          for(int i = 0; i < l; i++) {
            max_ending_here += val[i];
            curr_str += w[i];
            
            if(max_ending_soFar < max_ending_here) {
                max_ending_soFar = max_ending_here;
                max_str = curr_str;
            }
            
            if(max_ending_here < 0) {
                max_ending_here = 0;
                curr_str.clear();
            }
        
          }
          return max_str;
      }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string w;
        cin>>w;
        int n;
        cin>>n;
        char x[n];
        int b[n];
        for(int i = 0;i<n;i++)
            cin>>x[i];
        for(int i = 0;i<n;i++)
            cin>>b[i];
        Solution ob;
        cout << ob.maxSum(w,x,b,n) << endl;
    }
    return 0; 
}
// } Driver Code Ends