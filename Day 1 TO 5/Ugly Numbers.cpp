// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

#define ull unsigned long long


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// #define ull unsigned long long
	/* Function to get the nth ugly number*/
	ull getNthUglyNo(int n) {
	    // code here
        ull i2=0,i3=0,i5=0;
        vector<ull>dp(n+1);
        dp[0]=1;
        for(int i=1;i<=n;i++){
            dp[i]=min({2*dp[i2],3*dp[i3],5*dp[i5]});
            if(dp[i]==2*dp[i2])i2++;
            if(dp[i]==3*dp[i3])i3++;
            if(dp[i]==5*dp[i5])i5++;
        }
        return dp[n-1];
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.getNthUglyNo(n);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends