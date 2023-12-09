//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  public:
      bool prime(int n){
          for(int i=2;i<=sqrt(n);i++){
              if(n%i==0){
                  return 0;
              }
          }
          return 1;
      }
      int fun(int n){
          int s=0;
           while(n>0){
            s+=n%10;
            n=n/10;
        }
        return s;
      }
    int smithNum(int n) {
        
        if(prime(n)){
            return 0;
        }
        int k=n;int s=0;
        while(k>0){
            s+=k%10;
            k=k/10;
        }
        int a=0;
        for(int i=2;i<n;i++){
            while(n%i==0){
               
                n=n/i;
                int h=0;
                 if(i>=10 ){
                h=fun(i);
                a+=h;
                }
                else{
                    a+=i;
                }
                
            }
        }
        int j=n;
        if(prime(j) && j!=1){
            while(j>0){
                a+=j%10;
                j=j/10;
            }
        }
        // return a;
        if(a==s){
            return 1;
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        cout << ob.smithNum(n) << endl;
    }
    return 0;
}
// } Driver Code Ends