//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
    int minNumber(int arr[],int N)
      {
        int s=0;
        for(int i=0;i<N;i++){
            s+=arr[i];
        }
        if(s<=2)return 2-s;
        for(int i=s;i<2*s;i++){
            bool f=1;
            for(int j=2;j<=sqrt(i);j++){
                if(i%j==0){
                    f=0;
                    break;
                }
            }
            if(f)return i-s;
        }
    }

};


//{ Driver Code Starts.

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution obj;
        cout << obj.minNumber(arr, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends