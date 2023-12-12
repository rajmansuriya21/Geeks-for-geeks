//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
  int maxGold(int n, int m, vector<vector<int>> M)
    {
        vector<int> prev(n, 0);
        vector<int> curr(n, 0);
        for(int j=0;j<m;j++) {
            for(int i=0;i<n;i++) {
                if(i-1>=0) {
                    curr[i] = max(curr[i], prev[i-1] + M[i][j]);
                }
                if(i+1<n) {
                    curr[i] = max(curr[i], prev[i+1] + M[i][j]);
                }
                curr[i] = max(curr[i], prev[i] + M[i][j]);
            }
            prev = curr;
        }
        int ans = 0;
        for(int i=0;i<n;i++) {
            ans = max(ans, curr[i]);
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}
// } Driver Code Ends