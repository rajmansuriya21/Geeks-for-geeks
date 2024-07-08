//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
	    
        for(int i=n-1;i>=0;i--){
            for(int last=i-1;last>=-1;last--){
            int incl = 0;
            if(last==-1 || arr[i] > arr[last]){
                incl = arr[i] + dp[i+1][i+1];
            }
            int excl = dp[i+1][last+1];
            
            dp[i][last+1] = max(incl, excl);
            }
        }
        
        return dp[0][0];
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends