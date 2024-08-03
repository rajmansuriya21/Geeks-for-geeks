//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int n, vector<int>& arr){
        // Step - 1
        // Find the breakpoint
        int ind = -1;
        for(int i=n-2; i>=0; i--) {
            if(arr[i] < arr[i+1]) {
                ind = i;
                break;
            }
        }
        if(ind == -1) { // [5 4 3 2 1] next greater permutation-1,2,3,4,5
            reverse(arr.begin(), arr.end());
            return arr;
        }
        
        // Step - 2
        // Swap the breakpoint(ind) with the greater number than it but least from the right side
        for(int i=n-1; i>=0; i--) {
            if(arr[i] > arr[ind]) {
                swap(arr[i], arr[ind]);
                break;
            }
        }
        
        // Step - 3
        // Sort or reverse the array from breakpoint to end
        reverse(arr.begin()+ind+1, arr.end());
        return arr;
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends