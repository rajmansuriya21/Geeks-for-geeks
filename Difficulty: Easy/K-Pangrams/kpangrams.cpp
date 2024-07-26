//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

   bool kPangram(string str, int k) {
      string ans="";
      int n=str.size();
        for(int i=0;i<n;i++){
          if(str[i]!=' ')  {
              ans.push_back(str[i]);
          }
        }
        int n1=ans.size();
        set<int>st;
        for(int i=0;i<n1;i++){
            st.insert(ans[i]);
        }
        if(n1<26){
            return false;
        }
        if(st.size()==26){
            return true;
        }
        
        if(st.size()+k==26){
            return true;
        }
          if((n1-st.size()>=k)&&(st.size()+k>=26) ) {
            return true;}
         if((n1-st.size()<k) &&(n1>=26) ){
             return true;
         }
            
            return false;
    
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        string str;
        getline(cin, str);

        int k;
        cin >> k;

        Solution ob;
        bool a = ob.kPangram(str, k);
        if (a)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends