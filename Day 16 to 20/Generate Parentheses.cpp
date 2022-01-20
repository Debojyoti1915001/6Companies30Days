// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


 // } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    vector<string>ans;
    void solve(int n,int o,int c,string cur){
        if(c>o||o>n||c>n)return;
        if(o==n&&c==n){
            ans.push_back(cur);
            return;
        }
        solve(n,o+1,c,cur+'(');
        solve(n,o,c+1,cur+')');
    }
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
        solve(n,0,0,"");
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
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 
  // } Driver Code Ends