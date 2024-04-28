//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
   int palindromicPartition(string s)
    {
        int n = s.size();
        vector<int> dp(n+1,0);
        for(int i=0; i<=n; i++) dp[i]=i-1;
        for(int i=0; i<n; i++){
            for(int j=0; i-j>=0 && i+j<n && s[i-j]==s[i+j] ; j++)
                dp[i+j+1] = min(dp[i+j+1],1+dp[i-j]);
            
            for(int j=1; i-j+1>=0 && i+j<n && s[i-j+1]==s[i+j];j++)
                dp[i+j+1] = min(dp[i+j+1],1+dp[i-j+1]);
        }

        return dp[n];
    }

};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends