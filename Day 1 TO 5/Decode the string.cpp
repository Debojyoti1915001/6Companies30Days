// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string decodedString(string s){
        // code here
        stack<string>stk;
        int i=0;
        while(i<s.length()){
            if(s[i]==']'){
                string cur="";
                while(stk.top()!="["){
                    cur+=stk.top();
                    stk.pop();
                }
                // reverse(cur.begin(),cur.end());
                stk.pop();
                int num=stoi(stk.top());
                stk.pop();
                string ans="";
                for(int k=0;k<num;k++)ans+=cur;
                stk.push(ans);
                i++;
            }else if(s[i]>='0'&&s[i]<='9'){
                string cur="";
                while(s[i]>='0'&&s[i]<='9'){
                    cur+=s[i];
                    i++;
                }
                
                stk.push(cur);
            }else if(s[i]>='a'&&s[i]<='z'){
                string cur="";
                while(s[i]>='a'&&s[i]<='z'){
                    cur+=s[i];
                    i++;
                }
                reverse(cur.begin(),cur.end());
                stk.push(cur);
            }else{
                stk.push("[");
                i++;
            }
            // cout<<stk.top()<<endl;
        }
            s=stk.top();
            // string cur="";
            // while(stk.size()&&stk.top()!="["){
            //     cur+=stk.top();
            //     cout<<cur<<endl;
            //     stk.pop();
            // }
            //     // reverse(cur.begin(),cur.end());
            // // stk.pop();
            // // int num=stoi(stk.top());
            // // stk.pop();
            // // for(int k=0;k<num;k++)stk.push(cur);
            // // s=cur;
            // // cout<<stk.size()<<endl;
        reverse(s.begin(),s.end());
        return s;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}  // } Driver Code Ends