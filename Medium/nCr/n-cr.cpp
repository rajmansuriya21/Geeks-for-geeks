//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    
    int mod=1e9+7;
    int t[1001][801];
    int solve(int n,int r){
        int i,j;
      
        for(i=1;i<=n;i++){
            for(j=1;j<=r;j++){
                t[i][j]=(t[i-1][j]%mod + t[i-1][j-1]%mod)%mod;
            }
        }
        return t[n][r];
    }
    int nCr(int n, int r){
        // code here
        memset(t,-1,sizeof(t));
        for(int i=0;i<=n;i++){
            for(int j=0;j<=r;j++){
                if(j>i){
                    t[i][j]=0;
                }
                if(j==0){
                    t[i][j]=1;
                }
            }
        }
        
        return solve(n,r);
        
    }
    
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends