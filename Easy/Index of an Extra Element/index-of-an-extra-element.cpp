//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int findExtra(int n, int arr1[], int arr2[]) {
   
        
        int sum1 =0;
        int sum2 =0;
        
        for(int i=0;i<n;i++){
            sum1 += arr1[i];
        }
        for(int i=0;i<n-1;i++){
            sum2 += arr2[i];
        }
        
        
        int i=0;
        int j=n-1;
        
        while(j >= i){
            int mid = (i+j)/2;
            
            if(sum1 - arr1[mid] == sum2){
                return mid;
            }
            else if (sum1 - arr1[mid] > sum2){
                i = mid+1;
            }
            else{
                j = mid-1;
            }
        }
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr1[n], arr2[n - 1];
        for (int i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (int i = 0; i < n - 1; i++) {
            cin >> arr2[i];
        }
        Solution obj;
        cout << obj.findExtra(n, arr1, arr2) << endl;
    }
}
// } Driver Code Ends