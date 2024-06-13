//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    vector<string> ans;

    void solve(string s, unordered_map<string, int> &mp, int n, int i, string str) {
        
        string word = "";
        
        for (int j = i; j < n; j++) {
            word += s[j];
            
            if (mp[word]) {
                if (j == n - 1) {
                    ans.push_back(str + word);
                    return;
                }
                
                solve(s, mp, n, j + 1, str + word + " ");
            }
        }
    }
    
public:
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        unordered_map<string, int> mp;
        
        for (auto i : dict) mp[i]++;
        
        solve(s, mp, s.size(), 0, "");
        
        return ans;
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends