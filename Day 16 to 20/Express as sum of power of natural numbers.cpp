// { Driver Code Starts
// Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    long long int numOfWays(int n, int x)
    {
        // code here
        vector<long long int>dp(n+1);
        int mod=1e9+7;
        dp[0]=dp[1]=1;// 0*0 so dp[0]=1,1*1 so dp[1]=1
        int maxLimit=pow(n,1.0/x);
        for(int i=2;i<=maxLimit;i++){
            int cur=pow(i,x);
            for(int j=n;j>=cur;j--){
                dp[j]=(dp[j]+dp[j-cur])%mod;
            }
        }
        return dp[n];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n, x;
        cin >> n >> x;
        Solution ob;
        cout<<ob.numOfWays(n, x)<<endl;
    }
    return 0;
}
  // } Driver Code Ends