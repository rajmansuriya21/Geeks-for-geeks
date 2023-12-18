//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int size)
    { if (size == 1 && a[0] > size/2) {
            return a[0];
        }
        int max_size = size;
        for (int i =0; i<size; i++) {
            if (a[i] >= max_size) {
                max_size = a[i];
            }
        }
        bool is_present = false;
        int output;
        int fre_arr[max_size] = {0};
        for (int i=0; i<size; i++) {
            fre_arr[a[i]]++;
        }
        for (int i=0; i<max_size; i++) {
            if(fre_arr[i] > size/2 ) {
                is_present = true;
                output = i;
                break;
            }
        }
        if (is_present) {
            return output;
        } else {
            return -1;
        }
    }
};

//{ Driver Code Starts.

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.majorityElement(arr, n) << endl;
    }

    return 0;
}

// } Driver Code Ends