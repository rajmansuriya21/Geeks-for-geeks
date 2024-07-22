//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
        //User function Template for C++
        
        int maxProfit(vector<int>&price){
  int len = price.size();
vector<int> leftProfit(len, 0);
  vector<int> rightProfit(len, 0);

  int minProfit = price[0];
  for (int i = 1; i < len; i++) {
    minProfit = min(minProfit, price[i]);
    leftProfit[i] = max(leftProfit[i - 1], price[i] - minProfit);
  }

  int maxProfit = price[len - 1];
  for (int i = len - 2; i >= 0; i--) {
    maxProfit = max(maxProfit, price[i]);
    rightProfit[i] = max(rightProfit[i + 1], maxProfit - price[i]);
  }

  int profit = 0;
  for (int i = 0; i < len; i++) {
    profit = max(profit, leftProfit[i] + rightProfit[i]);
  }
return profit; 
        }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        Solution obj;
        cout<<obj.maxProfit(price)<<endl;
    }

}

// } Driver Code Ends