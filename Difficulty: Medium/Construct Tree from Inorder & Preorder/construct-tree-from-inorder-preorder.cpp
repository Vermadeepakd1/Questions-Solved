//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Definition of the Node class
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

// Function to print the tree in postorder traversal
void printPostOrder(Node *root) {
    if (root == NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}


// } Driver Code Ends

// Class that contains the logic to build the binary tree
/*
Definition of the Node class
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
  public:
    int find(int n, vector<int> &in, int size){
        for(int i = 0; i<size; i++){
            if(in[i] == n){
                return i;
            }
        }
        return -1;
    }
    Node* solve(vector<int> &in, vector<int> &pre, int &index, int start, int end , int n){
        if(index >= n || start > end){
            return NULL;
        }
        
        int element = pre[index++];
        int p = find(element,in,n);
        
        Node *root = new Node(element);
        root->left = solve(in,pre,index,start,p-1,n);
        root->right = solve(in,pre,index,p+1,end,n);
        
        return root;
    }
    
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        // code here
        int preorderindex = 0;
        int n = inorder.size();
        Node * result = solve(inorder,preorder,preorderindex,0,n-1,n);
        return result;
    }
};


//{ Driver Code Starts.

// Main function where the test cases are handled
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> inorder, preorder;

        // Input the inorder traversal
        string input;
        getline(cin, input);
        stringstream ss1(input);
        int num;
        while (ss1 >> num)
            inorder.push_back(num);

        // Input the preorder traversal
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> num)
            preorder.push_back(num);

        // Create Solution object and build the tree
        Solution obj;
        Node *root = obj.buildTree(inorder, preorder);

        // Print the postorder traversal of the constructed tree
        printPostOrder(root);
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends