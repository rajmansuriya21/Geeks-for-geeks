//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
      
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
          
        // Get the current node's value from the string
        string currVal = ip[i];
          
        // If the left child is not null
        if(currVal != "N") {
            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }
          
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
          
        // If the right child is not null
        if(currVal != "N") {
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function template for C++
/*
Structure of the node of the tree is as follows 
struct Node {
    struct Node* left, *right;
    int data;
};
*/

class Solution{
  public:
    // function should return the number of turns required to go from first node to second node 
    int ans;
    
    pair<pair<bool,char>,int> solve(struct Node* root, int n1, int n2, char c){
        if(root==NULL){
            return {{false,c},0};
        }
        
        auto it1= solve(root->left, n1, n2, 'L');
        auto it2= solve(root->right, n1, n2, 'R');
        
        if(it1.first.first && it2.first.first){
            ans= it1.second+it2.second-1;
            return {{false,c},0};
        }
        else if(it1.first.first && (root->data==n1 || root->data==n2)){
            ans= it1.second-1;
            return {{false,c},0};
        }
        else if(it2.first.first && (root->data==n1 || root->data==n2)){
            ans= it2.second-1;
            return {{false,c},0};
        }
        
        if(root->data==n1 || root->data==n2){
            return {{true, c},1};
        }
        
        if(it1.first.first){
            if(it1.first.second!=c){
                return {{true, c},it1.second+1};
            }
            else{
                return {{true, c},it1.second};
            }
        }
        else if(it2.first.first){
            if(it2.first.second!=c){
                return {{true, c},it2.second+1};
            }
            else{
                return {{true, c},it2.second};
            }
        }
    }
    
    int NumberOFTurns(struct Node* root, int first, int second)
    {
      // Your code goes here
      ans= -1;
      solve(root, first, second, 'N'); // 'N' for indicate not (left,right)
      return ans;
      
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    struct Node *child;
    scanf("%d ", &t);
    while (t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        int turn, first, second;
        cin>>first>>second;
        Solution ob;
        if ((turn = ob.NumberOFTurns(root, first, second) ))
            cout<<turn<<endl;
        else 
            cout<<"-1\n";
        cin.ignore();
    }
    return 0;
}

// } Driver Code Ends