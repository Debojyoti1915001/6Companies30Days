// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int minInsAndDel(int a[], int b[], int n, int m) {
        // code here
        vector<int>res;
        unordered_set<int>s;
        for(int i=0;i<m;i++)s.insert(b[i]);
        for(int i=0;i<n;i++){
            if(s.find(a[i])!=s.end()){
                auto it=lower_bound(res.begin(),res.end(),a[i]);
                if(it==res.end()){
                    res.push_back(a[i]);
                }else{
                    *it=a[i];
                }
            }
        }
        return n+m-2*res.size();
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,M;
        cin>>N>>M;
        
        int A[N], B[M];
        for(int i=0; i<N; i++)
            cin>>A[i];
        for(int i=0; i<M; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.minInsAndDel(A,B,N,M) << endl;
    }
    return 0;
}  // } Driver Code Ends