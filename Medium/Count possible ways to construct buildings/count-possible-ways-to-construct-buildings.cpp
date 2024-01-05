//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public: 
    int TotalWays(int N)
    {
        long mod=1000000007;
    long  ans=0,curr=1, prev=1;
        for(int i=1;i<=N;i++)
        {
            ans=(prev+curr)%mod; 
            prev=curr;
            curr=ans;
        }//User function Template for Java


        ans= (ans*ans)%mod;
        return (int)ans;
    }
};



//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int N;
		cin >> N;
		Solution ob;
		int ans = ob.TotalWays(N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends