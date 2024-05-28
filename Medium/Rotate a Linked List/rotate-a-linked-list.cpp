//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    //Function to rotate a linked list.

   
    Node* rotate(Node* head, int k)
    {   if(head==NULL && head->next==NULL )return head ;
         int count =1;
        Node *p=head;
        Node *q=head;  
        while(p!=NULL){
          p=p->next;
          count++;
      }
      p=head;
       for(int i=1;i<k;i++){
           if(k%count==0) return head;
           p=p->next;
       }
       q=p;
       
       while(p->next!=NULL){
           p=p->next;
       }
       p->next=head;
       head=q->next;
       q->next=NULL;
       return head;
    }
};


//{ Driver Code Starts.

void printList(Node *n)
{
    while (n != NULL)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, val, k;
        cin>>n;
        
        cin>> val;
        Node *head = new Node(val);
        Node *tail = head;
        
        for(int i=0; i<n-1; i++)
        {
            cin>> val;
            tail->next = new Node(val);
            tail = tail->next;
        }
        
        cin>> k;
        
        Solution ob;
        head = ob.rotate(head,k);
        printList(head);
    }
    return 1;
}

// } Driver Code Ends