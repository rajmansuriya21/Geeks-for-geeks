//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    bool isPossible(int reqdDish, vector<int>&A, int mid, int &n)
    {
        int timeTaken = 0;
        int dishesPrepared = 0;
        
        for(int i = 0; i < n; i++)
        {
            timeTaken = A[i];
            
            int j = 2;
            while(timeTaken <= mid)
            {
                timeTaken += A[i]*j;
                dishesPrepared += 1;
                j++;
            }
            if(dishesPrepared >= reqdDish) return true;
        }
        if(dishesPrepared >= reqdDish) return true;
        else return false;
    }
    public:
    int findMinTime(int N, vector<int>&A, int L)
    {
        int l = 0;
        // ideally according to inputs
        // maxtime = 8*(1000)(1001)/2  = 4004000 (8 + 8*2 + 8*3 + ... 8 * 1000)
        // so r should be 4004000
        //but here r = 1e6 also works
        int r = 1e6;
        int mid;
        int ans = mid;
        while (l <= r)
        {   
            mid = l + (r - l)/2;
            
            if(isPossible(N, A, mid, L))
            {
                ans = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return ans;
        
        
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    int l;
	    cin >> l;
	    vector<int>arr(l);
	    for(int i = 0; i < l; i++){
	        cin >> arr[i];
	    }
	    Solution ob;
	    int ans = ob.findMinTime(n, arr, l);
	    cout << ans <<endl;
	}
	return 0;
}

// } Driver Code Ends