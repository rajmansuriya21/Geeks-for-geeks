//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long trappingWater(int arr[], int n){
        // code here
        int Left_max[n]={0};
        int Right_max[n]={0};
        Left_max[0]=arr[0];
        for(int i=1;i<n;i++){
            Left_max[i]=max(Left_max[i-1],arr[i]);
        }
        Right_max[n-1]=arr[n-1];
        for(int i=n-2;i>=0;i--){
            Right_max[i]=max(Right_max[i+1],arr[i]);
        }
        long long res=0;
        for(int i=1;i<n-1;i++){
            res=res+min(Left_max[i],Right_max[i])-arr[i];
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends