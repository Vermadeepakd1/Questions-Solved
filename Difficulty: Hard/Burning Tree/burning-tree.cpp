//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends

// User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    Node* createMap(Node* root,int target, map<Node*,Node*>&mp){
        Node* res = NULL;
        queue<Node*> q;
        
        q.push(root);
        mp[root] = NULL;
        
        while(!q.empty()){
            Node* frontnode = q.front();
            q.pop();
            
            if(frontnode -> data == target){
                res = frontnode;
            }
            
            if(frontnode->left){
                q.push(frontnode->left);
                mp[frontnode->left] = frontnode;
            }
            
            if(frontnode -> right){
                q.push(frontnode -> right);
                mp[frontnode->right] = frontnode;
            }
            
        }
        return res;
    }
    
    int burntree(Node* root, map<Node*,Node*> &mp){
        map<Node*,bool> visited;
        queue<Node*> q;
        q.push(root);
        int ans = 0;
        bool flag = false;
        visited[root] = true;
        
        while(!q.empty()){
            int s = q.size();
            flag = false;
            for(int i =0; i<s; i++){
                Node* frontnode = q.front();
                q.pop();
                
                if(frontnode->left && !visited[frontnode->left]){
                    q.push(frontnode->left);
                    visited[frontnode->left] = true;
                    flag = true;
                }
                
                if(frontnode->right && !visited[frontnode->right]){
                    q.push(frontnode->right);
                    visited[frontnode->right] = true;
                    flag = true;
                }
                
                if(mp[frontnode] && !visited[mp[frontnode]]){
                    q.push(mp[frontnode]);
                    visited[mp[frontnode]] = true;
                    flag = true;
                }
            }
            if(flag){
                ans++;
            }
        }
        return ans;
    }
    
    int minTime(Node* root, int target) {
        // code here
        int ans = 0;
        map<Node*,Node*> mp;
        Node* targetnode = createMap(root,target,mp);
        ans = burntree(targetnode,mp);
        return ans;
        
    }
};


//{ Driver Code Starts.

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin >> target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout << obj.minTime(root, target) << "\n";

        cin.ignore();

        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends