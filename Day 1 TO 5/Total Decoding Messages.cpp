// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		int CountWays(string s){
		    // Code here
		    int mod=1e9+7;
		    int n=s.length();
		    if(n==0)return 1;
		    vector<long long int>dp(n+1);
		    dp[0]=1;
		    if(s[0]=='0')dp[1]=0;
		    else dp[1]=1;
		    for(int i=2;i<=n;i++){
		        if(s[i-1]!='0'){
		            dp[i]=dp[i-1];
		        }
		        if(s[i-2]!='0'){
		            int ten=s[i-2]-'0';
		            int one=s[i-1]-'0';
		            if(ten*10+one<=26)dp[i]=(dp[i]+dp[i-2])%mod;
		        }
		    }
		    return dp[n];
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends