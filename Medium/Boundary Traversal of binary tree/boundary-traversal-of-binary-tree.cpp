//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str)
{
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

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

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

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
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}









// } Driver Code Ends
class Solution {
public:
    //for left Boundary tree
    //If i can insert  the parent of root->left then only i can insert root->left
    
    // for right Boundary tree
    // If i can insert the parent of root->right then only i can insert root->right
    void help(Node* root, char process, vector<int>& ans, bool canInsert){
        if(!root){
            return;
        }
        if(!root->left && !root->right){
            ans.push_back(root->data);
            return;
        }
        
        if(process == 'L'){ 
            
            if(canInsert){
                ans.push_back(root->data);
            }
            
            //if we can insert parent of root->left (root) then only we can insert root->left
            help(root->left, process, ans, canInsert);

            
            if(root->right){
                
               if(!root->left){
                    //if their is no root->left, 
                    // then if we can insert parent of root->right (root) then only we can insert root->right
                    help(root->right, process, ans, canInsert);
               } else{
                   //if their is root->left then it is confirmed we cannot insert root->left
                   help(root->right, process,ans, false);
               }
               
            }
            
        } else if(process == 'R'){
            
            
            if(root->left){
                
                if(!root->right){
                    // same as above
                    help(root->left, process, ans, canInsert);
                } else{
                    // same as above
                    help(root->left, process, ans, false);
                }
            }
            
            //if we can insert parent of root->right then only we can insert root->right
            help(root->right, process, ans, canInsert);
            
            
            if(canInsert){
                ans.push_back(root->data);
            }
        }
        
    }

    vector <int> boundary(Node *root)
    {
        vector<int> ans;
        ans.push_back(root->data);
        help(root->left, 'L', ans, true);
        help(root->right, 'R', ans, true);
        return ans;
    }
};


//{ Driver Code Starts.

/* Driver program to test size function*/

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);
        Solution ob;
        vector <int> res = ob.boundary(root);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends