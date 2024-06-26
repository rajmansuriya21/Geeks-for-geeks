//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:
	long long maxProduct(vector<int> arr, int n) {
        // code here
        long long ans=INT_MIN;
        for(int i=0;i<n;i++){
            long long prod=1;
            for(int j=i;j<n;j++){
                prod*=arr[j];
                if(prod>ans){
                    ans=prod;
                }
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
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends