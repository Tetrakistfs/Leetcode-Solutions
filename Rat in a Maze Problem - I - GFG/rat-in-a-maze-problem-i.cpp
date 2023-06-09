//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    void paths(vector<vector<int>> &m, vector<vector<bool>> &vis, vector<string> &ans, string dir, int xcurr, int ycurr,int n) {
        if(xcurr == n-1 && ycurr == n-1) {
            ans.push_back(dir);
            return;
        }
        string s = "DLRU";
        int dx[] = {1, 0, 0, -1};
        int dy[] = {0, -1, 1, 0};
        for(int i = 0;i < 4;i++) {
            int xnew = xcurr + dx[i];
            int ynew = ycurr + dy[i];
            if(xnew >= 0 && ynew >= 0 && xnew < n && ynew < n && m[xnew][ynew] != 0 && vis[xnew][ynew] == false) {
                vis[xcurr][ycurr] = true;
                paths(m, vis,  ans, dir + s[i], xnew, ynew, n);
                vis[xcurr][ycurr] = false;
            }
        }
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<string> ans;
        vector<vector<bool>> vis (n, vector<bool>(n, false));
        
        if(m[0][0] != 0)
            paths(m, vis, ans, "", 0, 0, n);
        return ans;
        
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends