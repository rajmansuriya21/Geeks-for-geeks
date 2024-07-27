//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	vector<int> kLargest(int arr[], int n, int k) {
        // code here
        
        priority_queue<int, vector<int>, greater<int>> pq;
        int i = 0;
        while(k--){
            pq.push(arr[i]);
            i++;
        }
        
        while(i<n){
            if(arr[i]>pq.top()){
                pq.push(arr[i]);
                pq.pop();
            }
            i++;
        }
        
        vector<int>v;
        while(!pq.empty()){
            v.push_back(pq.top());
            pq.pop();
        }
        
        reverse(v.begin(), v.end());
        
        return v;
    }



};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.kLargest(arr, n, k);
        for (auto x : ans) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends