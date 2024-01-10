//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	 vector<int> preSum={arr[0]};
        for(int i=1; i<n; i++){
            preSum.push_back(preSum[i-1]+arr[i]);
        }
        int prev=n, i=0, j=n-1;
        while(prev){
            int tmp=preSum[j]-(i!=0?preSum[i-1]:0);
            if(tmp%k==0) return prev;
            if(j==n-1){
                prev--;
                j=j-i-2;
                i=-1;
            }
            
            i++, j++;
        }
        return 0;
   }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	int n,k,i;
	cin>>n>>k; int arr[n];
	for(i=0;i<n;i++)
	cin>>arr[i];
	Solution ob;
	cout<<ob.longSubarrWthSumDivByK(arr, n, k)<<"\n";
	}
	return 0;	 
}

// } Driver Code Ends