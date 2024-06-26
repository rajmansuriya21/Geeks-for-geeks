//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> recamanSequence(int n){
        vector<int> v(n, 0);
        unordered_set<int> s;
        s.insert(0);
        for(int i=1; i<n; i++){
            if (v[i-1] > i and s.count(v[i-1] - i)==0) {
                v[i]=v[i-1]-i;
                s.insert(v[i-1] - i);
            }
            else{
                v[i] = v[i-1]+i;
                s.insert(v[i-1]+i);
            }
        }
        return v;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<int> ans = ob.recamanSequence(n);
        for(int i = 0;i < n;i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends