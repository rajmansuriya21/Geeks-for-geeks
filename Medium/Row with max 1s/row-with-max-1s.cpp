//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
    int lower_bound(vector<int> a){
        int start = 0;
        int end = a.size()-1;
        int ans;
        while(start<=end){
            int mid = (start+end)/2;
            if(a[mid])
            {
                ans = mid;
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return ans;
    }
	int rowWithMax1s(vector<vector<int> > arr, int n, int m) {
	    int maxi = 0;
	    int ans = -1;
	    for(int i=0;i<n;i++){
	        int count = m-lower_bound(arr[i]);
	        if(count>maxi){
	            maxi = count;
	            ans = i;
	        }
	    }
	    return ans;
	}

};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends