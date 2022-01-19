// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int lengthOfLongestAP(int A[], int n) {
        // code here
        if(n==1)return 1;
        int mx=0,maxval=0;
        for(int i=0;i<n;i++)maxval=max(maxval,A[i]);
        
       vector<vector<int>>dp(2*maxval+1,vector<int>(n));
       for(int i=0;i<n;i++){
           for(int j=i+1;j<n;j++){
               int val=A[j]-A[i]+maxval;
               dp[val][j]=max(2,dp[val][i]+1);
               mx=max(mx,dp[val][j]);
           }
       }
       return mx;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int A[n];
        for (int i = 0; i < n; i++) {
            cin >> A[i];
        }
        Solution ob;
        auto ans = ob.lengthOfLongestAP(A, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends