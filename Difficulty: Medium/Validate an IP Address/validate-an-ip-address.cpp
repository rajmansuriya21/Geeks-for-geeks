//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/* The function returns 1 if
IP string is valid else return 0
You are required to complete this method */
class Solution {
  public:
    int isValid(string str) {
        int n=str.size();
        string s="";
        int cnt=0;
        for(int i=0;i<n;i++){
            if(str[i]!='.'){
                s+=str[i];
            }
            else{
                if(s.empty()){
                    return false;
                }
                if(stoi(s)<0 || stoi(s)>255){
                    return false;
                }
                s="";
                cnt++;
            }
        }
        if(stoi(s)<0 || stoi(s)>255){
                    return false;
        }
        cnt++;
        if(cnt==4)return true;
        return false;
        
    }
};



//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // if (s.size() == 3) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        bool f = ob.isValid(s);
        if (f)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends