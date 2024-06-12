//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int countNumberswith4(int n) {
        // code here
        int ans=0;
        for(int i=1;i<=n;i++){
            int num=i;
            while(num>0){
            int rem=num%10;
            //int div=i/10;
            if(rem==4){
                ans++;
                break;
            }
            num=num/10;
        }
        }
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        Solution obj;
        int res = obj.countNumberswith4(n);

        cout << res << endl;
    }
}

// } Driver Code Ends