//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h> 
using namespace std; 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data%10; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/* 

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node * reverse(Node * head)
    {
      Node * curr = head, *prev =NULL, *front = NULL;
      
      while(curr){
          front = curr->next;
          curr->next = prev;
          prev= curr;
          curr = front;
      }
      return prev;
      
    }
    
    Node* addOne(Node *head) 
    {
        // Your Code here
        // return head of list after adding one
        Node * rev = reverse(head);
        Node * temp = rev , *tail;
        
        while(temp){
            if(temp->data == 9){
                temp->data =0;
            }
            else{
                temp->data = temp->data+1;
                head = reverse(rev);
                return head;
            }
            tail = temp;
            temp=temp->next;
        }
        
             tail->next = new Node(1);
             head= reverse(rev);
             return head;
        
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        
        Node* head = new Node( s[0]-'0' );
        Node* tail = head;
        for(int i=1; i<s.size(); i++)
        {
            tail->next = new Node( s[i]-'0' );
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head); 
    }
    return 0; 
} 

// } Driver Code Ends