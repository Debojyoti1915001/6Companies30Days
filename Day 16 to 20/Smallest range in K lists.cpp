// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


 // } Driver Code Ends
// you are required to complete this function 
// function should print the required range
class Solution{
    public:
    pair<int,int> findSmallestRange(int a[][N], int n, int k)
    {
          //code here
          vector<pair<int,int>>v;
          for(int i=0;i<k;i++){
              for(int j=0;j<n;j++){
                  v.push_back({a[i][j],i});
              }
          }
          sort(v.begin(),v.end());
          vector<int>count(k);
          int total=0;
          int i=0,j=0,mn=INT_MAX,ansi=0,ansj=0;
          while(j<v.size()){
              count[v[j].second]++;
              if(count[v[j].second]==1)total++;
              while(i<=j&&count[v[i].second]!=1){
                  count[v[i].second]--;
                  i++;
              }
              if(total==k&&v[j].first-v[i].first<mn){
                  mn=v[j].first-v[i].first;
                  ansi=v[i].first;
                  ansj=v[j].first;
              }
              j++;
          }
          return {ansi,ansj};
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}

  // } Driver Code Ends