//{ Driver Code Starts
// C++ implementation to convert infix expression to postfix
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to convert an infix expression to a postfix expression.
    bool check(char ch)
    {
        return ((ch>='A' and ch<='Z') or(ch>='a' and ch<='z'));
    }
    int operat(char ch)
    {
        switch(ch)
        {
            case '^':return 3;
            break;
            case '*':
            case '/':return 2;
            break;
            case '-':
            case '+':return 1;
            break;
        }
        return 0;
    }
    string infixToPostfix(string s) {
        // Your code here
        string ans;
        stack<char> st;
        for(auto i:s)
        {
           if(check(i))
           ans.push_back(i);
           else if(i=='(')
           st.push(i);
           else if(i==')')
           {
               while(!st.empty() and st.top()!='(')
               {
                   ans.push_back(st.top());
                   st.pop();
               }
               if(!st.empty())st.pop();
           }
           else{
               while(!st.empty() and operat(st.top())>=operat(i))
               {
                   ans.push_back(st.top());
                   st.pop();
               }
               st.push(i);
           }
        }
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};


//{ Driver Code Starts.
// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    cin.ignore(INT_MAX, '\n');
    while (t--) {
        string exp;
        cin >> exp;
        Solution ob;
        cout << ob.infixToPostfix(exp) << endl;
    }
    return 0;
}

// } Driver Code Ends