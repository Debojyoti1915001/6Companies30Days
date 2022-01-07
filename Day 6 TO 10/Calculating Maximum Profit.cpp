// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxProfit(int k, int n, int prices[]) {
        // code here
        if(k==0 || n<=1)
            return 0;
        
        if(2*k>n)
        {
            int res = 0;
            for(int i=1;i<n;++i)
                if(prices[i]>prices[i-1])
                    res+=(prices[i]-prices[i-1]);
            return res;
        }
        
        int dp[2*k+1];
        dp[0]=-prices[0];
        for(int i=1;i<=2*k;++i)
        {
            if(i%2==0)  //Buy
                dp[i]=INT_MIN;
            else    //SELL
                dp[i]=0;
        }
        
        for(int i=0;i<n;++i)
        for(int j=0;j<=2*k;++j)
        {
            if(j==0)
                dp[j]=max(dp[j],-prices[i]);
            else if(j%2==0)         //BUY
                dp[j]=max(dp[j],dp[j-1]-prices[i]);
            else                    //SELL
                dp[j]=max(dp[j],dp[j-1]+prices[i]);
        }
        return dp[2*k-1];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}  // } Driver Code Ends