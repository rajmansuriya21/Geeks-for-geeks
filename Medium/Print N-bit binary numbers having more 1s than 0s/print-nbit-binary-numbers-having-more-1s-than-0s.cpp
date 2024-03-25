//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution
{
public:	
    void solve(string ds, int ones, int remaining, vector<string> &res) 
    {
        if(remaining == 0)
        {
            res.push_back(ds);
            return;
        }
        
        solve(ds + "1", ones + 1, remaining - 1, res);
        if(ones > 0)
            solve(ds + "0", ones - 1, remaining - 1, res);
    }

	vector<string> NBitBinary(int n)
	{
	    vector<string> res;
	    string ds;
	    solve(ds, 0, n, res);
	    return res;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends