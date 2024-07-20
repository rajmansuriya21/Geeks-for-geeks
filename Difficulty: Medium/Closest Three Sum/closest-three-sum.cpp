//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

// arr : given vector of elements
// target : given sum value

class Solution {
  public:
    int threeSumClosest(vector<int> arr, int target) {
        // Your code goes here
        sort(arr.begin(),arr.end());
        int ans=0,dif=INT_MAX;
        for(int i=0;i<arr.size()-2;i++)
        {
            int j=i+1,k=arr.size()-1;
            while(k>j)
            {
                if(abs(arr[i]+arr[j]+arr[k]-target)<dif)
                {
                    dif=abs(arr[i]+arr[j]+arr[k]-target);
                    ans=arr[i]+arr[j]+arr[k];
                }
                else if(abs(arr[i]+arr[j]+arr[k]-target)==dif)
                  ans=max(ans,arr[i]+arr[j]+arr[k]);
                  
                  if(arr[i]+arr[j]+arr[k]>target)
                    k--;
                   else if(arr[i]+arr[j]+arr[k]<target)
                    j++;
                    else
                      return ans;
                    
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int key;
        cin >> key;
        // cin.ignore();
        // if (f)
        //     return 0;
        Solution ob;
        cout << ob.threeSumClosest(arr, key) << endl;
    }
    return 0;
}
// } Driver Code Ends