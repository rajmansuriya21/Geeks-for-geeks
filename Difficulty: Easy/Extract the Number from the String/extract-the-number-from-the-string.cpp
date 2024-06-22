//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long ExtractNumber(string sentence) {

        // code here
        long long num = 0;
        long long maxi = -1;
        bool flag = 1;
        
        for(int i=0; i<sentence.size(); i++){
            if(sentence[i] == '9'){
                flag = 0;
                num = 0;
            }
            else if(sentence[i] >= '0' && sentence[i] <= '8'){
                if(flag){
                    num *= 10;
                    num += (sentence[i]-'0');
                }
                // cout<<num<<" ";
            }
            else{
                maxi = max(maxi, num);
                flag = 1;
                num = 0;
            }
        }
        maxi = max(maxi, num);
        
        if(maxi == 0){
            long long num = -1;
            bool flag = 1;
            for(int i=0; i<sentence.size(); i++){
                if(sentence[i] == '9'){
                    flag = 0;
                    num = -1;
                }
                else if(sentence[i] >= '0' && sentence[i] <= '8'){
                    if(flag){
                        num = sentence[i]-'0';
                    }
                }
                else{
                    flag = 1;
                    if(num == 0)
                        return 0;
                }
            }
            if(num == 0)
                return 0;
        }
        
        return maxi == 0 ? -1 : maxi;
    }
};

//{ Driver Code Starts.
int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);

        Solution ob;
        cout << ob.ExtractNumber(s) << "\n";
    }

    return 0;
}

// } Driver Code Ends