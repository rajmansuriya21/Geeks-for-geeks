//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*
The structure of the class is as follows
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/

class Solution{
    int minEle;
    stack<int> s;
    public:
       int getMin(){
      
           if(s.empty()){
               return -1;
           }
           return s.top()%101;
       }
       int pop(){
           if(s.empty()){
               return -1;
           }
           
           int num = s.top()/101;
           s.pop();
           
           return num;
       }
       void push(int x){
          
           if(s.empty()){
               minEle = x;
           }
           else{
               minEle = min(x,s.top()%101);
           }
           
           s.push(x*101 + minEle);
       }
};

//{ Driver Code Starts.

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int q;
        cin>>q;
        Solution ob;
        while(q--){
           int qt;
           cin>>qt;
           if(qt==1)
           {
              //push
              int att;
              cin>>att;
              ob.push(att);
           }
           else if(qt==2)
           {
              //pop
              cout<<ob.pop()<<" ";
           }
           else if(qt==3)
           {
              //getMin
              cout<<ob.getMin()<<" ";
           }
       }
       cout<<endl;
    }
    return 0;
}

// } Driver Code Ends