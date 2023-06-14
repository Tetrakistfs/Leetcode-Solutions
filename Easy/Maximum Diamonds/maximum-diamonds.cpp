//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
        long long sub(priority_queue<int> &pq, int K, long long int &dmnds) {
            if(K == 0)
                return dmnds;
            int max = pq.top();
            pq.pop();
            pq.push(max/2);
            dmnds += max;
            sub(pq, K-1, dmnds);
        }
      
        long long maxDiamonds(int A[], int N, int K) {
            // code here
            priority_queue<int> pq;
            for(int i = 0; i < N;i++)
                pq.push(A[i]);
            long long int dmnds = 0;
            sub(pq, K, dmnds);
            return dmnds;
        }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,K;
        
        cin>>N>>K;
        int A[N];
        
        for(int i=0; i<N; i++)
            cin>>A[i];

        Solution ob;
        cout << ob.maxDiamonds(A,N,K) << endl;
    }
    return 0;
}
// } Driver Code Ends