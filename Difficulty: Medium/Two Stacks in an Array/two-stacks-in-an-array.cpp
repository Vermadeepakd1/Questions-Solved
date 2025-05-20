//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends



class twoStacks {
  public:
    vector<int> st;
    int top1 = -1;
    int top2 = -1;
    int size = 0;
    
    twoStacks() {
        st = vector<int>(100);
        size =100;
        top2 = 100;
    }

    // Function to push an integer into the stack1.
    void push1(int x) {
        if(top1 + 1 < top2){
            st[++top1] = x;
        }
        
    }

    // Function to push an integer into the stack2.
    void push2(int x) {
        
        if(top2 - 1 > top1){
            st[--top2] = x;
        }
    }

    // Function to remove an element from top of the stack1.
        
    int pop1() {
        int val = -1;
        if(top1 >= 0){ 
            val = st[top1];
            top1--;
        }
        return val;
    }

        
    // Function to remove an element from top of the stack2.
    int pop2() {
        int val =-1;
        if(top2 < size){ 
            val = st[top2];
            top2++;
        }
        return val;
    }
};



//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;
    while (T--) {
        twoStacks *sq = new twoStacks();

        int Q;
        cin >> Q;
        while (Q--) {
            int stack_no;
            cin >> stack_no;
            int QueryType = 0;
            cin >> QueryType;

            if (QueryType == 1) {
                int a;
                cin >> a;
                if (stack_no == 1)
                    sq->push1(a);
                else if (stack_no == 2)
                    sq->push2(a);
            } else if (QueryType == 2) {
                if (stack_no == 1)
                    cout << sq->pop1() << " ";
                else if (stack_no == 2)
                    cout << sq->pop2() << " ";
            }
        }

        cout << endl;
        cout << "~" << endl;
    }
}

// } Driver Code Ends