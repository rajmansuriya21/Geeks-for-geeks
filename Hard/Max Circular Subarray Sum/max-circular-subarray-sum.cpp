//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    // arr: input array
    // num: size of array
    //Function to find maximum circular subarray sum.
    int normalSubarraySum(int arr[],int n){
        int result=arr[0],maxi=arr[0];
        for(int i=1;i<n;i++){
            maxi=max(maxi+arr[i],arr[i]);
            result=max(result,maxi);
        }
        return result;
}
int circularSubarraySum(int arr[], int num){
        int normalmax=normalSubarraySum(arr,num);
        if(normalmax<0)
            return normalmax;
        int sum=0;
        for(int i=0;i<num;i++){
            sum =sum+arr[i];
            arr[i]=-arr[i];
        }
        int circularmax=sum+normalSubarraySum(arr,num);
        int result=max(normalmax,circularmax);
        return result;
}
};

//{ Driver Code Starts.

int main()
 {
	int T;
	
	//testcases
	cin>> T;
	
	while (T--)
	{
	    int num;
	    
	    //size of array
	    cin>>num;
	    int arr[num];
	    
	    //inserting elements
	    for(int i = 0; i<num; i++)
	        cin>>arr[i];
	        
	    Solution ob;
	    //calling function
	    cout << ob.circularSubarraySum(arr, num) << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends