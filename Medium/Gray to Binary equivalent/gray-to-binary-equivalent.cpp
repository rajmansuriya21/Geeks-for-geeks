//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // function to convert a given Gray equivalent n to Binary equivalent.
    int grayToBinary(int n)
    {
        int new_n = n , len = 0 ,  ans = 0 , prev_bit = 0;
        
        while(new_n){
            len++;
            new_n >>=1;
        }
        
        
        while(len){
            
            if( n & (1<< (len-1)) )prev_bit = prev_bit^1;
            ans |= (prev_bit << (len-1));
            len--;
        }
        
        return ans;
        
    }
};

 

//{ Driver Code Starts.

// Driver code
int main()
{
    int t,n;
    cin>>t;//testcases
    while(t--)
    {
        cin>>n;//initializing n
        
        Solution ob;
        //calling function grayToBinary()
       cout<< ob.grayToBinary(n)<<endl;
    }
}

// } Driver Code Ends