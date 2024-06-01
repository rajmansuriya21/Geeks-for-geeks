//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    string oddEven(string s) {
        int x{}, y{}, a[26]{};
        
        for(char c : s) ++a[c - 'a'];
        for(int i{}; i < 26; i++)
            if(a[i]) {
                if(!((i + 1) & 1) and !(a[i] & 1)) ++x;
                if((i + 1) & 1 and a[i] & 1) ++y;
            }
            
        return (x + y) & 1 ? "ODD" : "EVEN";
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s;
        getline(cin, s);

        Solution obj;
        string res = obj.oddEven(s);

        cout << res << "\n";
    }
}

// } Driver Code Ends