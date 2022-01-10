// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    map<string,pair<int,string>>dp;
    pair<int,string> solve(int p[], int l,int r){
        if(l+1==r)return {0,string(1,l+'A')};
        string key=to_string(l)+'#'+to_string(r);
        if(dp.count(key))return dp[key];
        int cur=INT_MAX;
        string minString;
        for(int k=l+1;k<r;k++){
            auto p1=solve(p,l,k);
            auto p2=solve(p,k,r);
            if(p1.first+p2.first+p[l]*p[r]*p[k]<cur){
                cur=p1.first+p2.first+p[l]*p[r]*p[k];
                minString='('+p1.second+p2.second+')';
            }
        }
        return dp[key]={cur,minString};
    }
    string matrixChainOrder(int p[], int n){
        // code here
        return solve(p,0,n-1).second;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int p[n];
        for(int i = 0;i < n;i++)
            cin>>p[i];
        
        Solution ob;
        cout<<ob.matrixChainOrder(p, n)<<"\n";
    }
    return 0;
}  // } Driver Code Ends