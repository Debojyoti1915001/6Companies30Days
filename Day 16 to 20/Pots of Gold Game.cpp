// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int dp[1005][1005];
    int solve(vector<int>A,int i,int j){
        if(dp[i][j]!=-1)return dp[i][j];
        if(i>j)return dp[i][j]=0;
        if(j==i)return A[i];
        //Y wishes to get the minimum
        //so when X take the ith element Y will take i+1 or j
        //lly for the jth element
        int l=A[i]+min(solve(A,i+1,j-1),solve(A,i+2,j));
        int r=A[j]+min(solve(A,i+1,j-1),solve(A,i,j-2));
        return dp[i][j]=max(l,r);
    }
    int maxCoins(vector<int>&A,int n)
    {
	    //Write your code here
	    memset(dp,-1,sizeof(dp));
	    return solve(A,0,n-1);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int>A(N);
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.maxCoins(A, N) << "\n";
    }
    return 0;
}
  // } Driver Code Ends