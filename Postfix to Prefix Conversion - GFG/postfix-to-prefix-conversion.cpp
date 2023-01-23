//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   bool check(char ch)
  {
      return!((ch>='a' and ch<='z') or (ch>='A' and ch<='Z'));
  }
  string solve(string exp)
  {
      stack<string> st;
      for(char i:exp)
      {
          if(check(i))
          {
              string temp=st.top();
              st.pop();
              temp+=st.top();
              st.pop();
              temp+=i;
              st.push(temp);
          }
          else
              st.push(string(1,i));
      }
      string result="";
      while(!st.empty())
      {
          result+=st.top();
          st.pop();
      }
      return result;
  }
    string preToPost(string exp) {
        //reverse(exp.begin(),exp.end());
        return solve(exp);
    }
    string postToPre(string exp) {
        // Write your code here
        
       string ans= preToPost(exp);
       reverse(ans.begin(),ans.end());
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
        string postfix;
        cin >> postfix;

        // char marker; cin >> marker;

        Solution obj;
        cout << obj.postToPre(postfix) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends