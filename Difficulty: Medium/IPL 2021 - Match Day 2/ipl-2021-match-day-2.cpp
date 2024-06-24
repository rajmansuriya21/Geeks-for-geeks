//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        vector<int> ans;
        deque<int> dq;
        
        // Just go through k-1 elements and push each of them from backside
        // If the incoming element is greater than the one at backside then pop it back
        for(int i=0; i<k-1; i++){
            if(dq.empty()){
                dq.push_back(i);
            }else{
                while(!dq.empty() and arr[i] > arr[dq.back()])
                    dq.pop_back();
                dq.push_back(i);
            }
        }
        
        // This is just a simple extension of the above logic with a condition check
        // that if the element's index is greater than the range then pop it
        for(int i=k-1; i<n; i++){
            while(!dq.empty() and arr[i] > arr[dq.back()])
                dq.pop_back();
            dq.push_back(i);    
            
            if(dq.front() <= i-k)
                dq.pop_front();
                
            ans.push_back(arr[dq.front()]);
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}
// } Driver Code Ends