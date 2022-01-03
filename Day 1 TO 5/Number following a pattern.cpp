// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
    string printMinNumberForPattern(string S){
        // code here
        stack<int>stk;
        int cur=1;
        string ans="";
        for(auto s:S){
            if(s=='D'){
                stk.push(cur);
                cur++;
            }else{
                stk.push(cur);
                cur++;
                while(!stk.empty()){
                    ans+=to_string(stk.top());
                    stk.pop();
                }
            }
        }
        stk.push(cur);
                while(!stk.empty()){
                    ans+=to_string(stk.top());
                    stk.pop();
                }
        return ans;
    }
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends