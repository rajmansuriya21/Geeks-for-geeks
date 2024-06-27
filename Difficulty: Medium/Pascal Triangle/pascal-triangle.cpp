//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// #define ll long long
class Solution{
public:
   
    vector<long long> nthRowOfPascalTriangle(int n) {
        long long int a1[n+1],a2[n+1],i,j,mod=1000000007;
        a1[0]=1;
        a2[0]=a2[1]=1;
        for(i=3;i<=n;i++){
            if((i%2)==0){
                for(j=0;j<i;j++){
                    if(j==0||j==i-1){
                    a2[j]=1;}
                    else{
                    a2[j]=(a1[j-1]+a1[j])%mod;}
                }
            }
            else{
                for(j=0;j<i;j++){
                    if(j==0||j==i-1){
                    a1[j]=1;}
                    else{
                    a1[j]=(a2[j-1]+a2[j])%mod;
                    }
                }
            }
        }
    vector<long long >ans;
    if((n%2)==0){
        for(i=0;i<n;i++){
            ans.push_back(a2[i]);
        }
    }
    else{
        for(i=0;i<n;i++){
            ans.push_back(a1[i]);}
    }
        return ans;
    
}
};




//{ Driver Code Starts.


void printAns(vector<long long> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}

// } Driver Code Ends