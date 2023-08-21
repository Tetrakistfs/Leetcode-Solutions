//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
public:

    int Count(vector<vector<int> >& matrix) {
        // Code here
        int n = matrix.size();
        int m = matrix[0].size();
        
        int res = 0;
        for(int r = 0; r < n; r++) {
            for(int c = 0; c < m; c++) {
                if(matrix[r][c] == 1) {
                    int temp = 0;
            
                    for(int i = -1; i <= 1; i++) {
                        for(int j = -1; j <= 1; j++) {
                            int x = r + i; 
                            int y = c + j; 
                            if(x >= 0 && x < n && y >= 0 && y < m && matrix[x][y] == 0)
                                temp++;
                        }
                    }
                    if(temp > 0 && temp%2 == 0) res++;        
                }
            }
        }
        
        return res;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>> matrix(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> matrix[i][j];
			}
		}
		Solution ob;
		int ans = ob.Count(matrix);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends