//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
    //Function is to check whether two strings are anagram of each other or not.
    
    bool func(string a, string b, unordered_map<char, int>& mp) {
        for(int i = 0; i < b.size(); i++) {
            mp[b[i]]++;
        }
        
        for(int i = 0; i < a.size(); i++) {
            if(mp.find(a[i]) == mp.end() || mp[a[i]] == 0)   return false;
            else mp[a[i]]--;
        }
        return true;
    }
    
    bool isAnagram(string a, string b){
        
        // Your code here
        if(a.size() != b.size())    return false;
        unordered_map<char, int> mp;
        return func(a, b, mp);
    }

};

//{ Driver Code Starts.

int main() {
    
    int t;

    cin >> t;

    while(t--){
        string c, d;

        cin >> c >> d;
        Solution obj;
        if(obj.isAnagram(c, d)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }

}

// } Driver Code Ends