//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   bool isOperator(char c)
    {
        if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        {
            return false;
        }
        return true;
    }

    string postToInfix(string exp) {
        // Write your code here
        stack<string> st;

        string res;

        for(int i=exp.length()-1;i>=0;i--)
        {
            char c = exp[i];

            if(isOperator(c))
            {
                string str1 = st.top();
                st.pop();
                
                string str2 = st.top();
                st.pop();

                st.push('(' + str2 + exp[i] + str1 + ')');
            }
            else
            {
                st.push(string(1,exp[i]));
            }
        }
        
        
        return st.top();
    }
    string preToInfix(string pre_exp) {
        // Write your code here
        string ans= postToInfix(pre_exp);
        reverse(ans.begin(),ans.end());
        for(auto &i:ans)
        if(i=='(')
        i=')';
        else if(i==')')
        i='(';
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string prefix;
        cin >> prefix;

        Solution obj;
        cout << obj.preToInfix(prefix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends