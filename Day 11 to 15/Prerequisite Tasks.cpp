// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    bool isCyclic(vector<vector<int>>&adj,int cur,vector<int>&vis){
        vis[cur]=1;
        for(auto &i:adj[cur]){
            if(vis[i]==0){
                if(isCyclic(adj,i,vis))return true;
            }
            else if(vis[i]==1)return true;
        }
        vis[cur]=2;
        return false;
    }
	bool isPossible(int n, vector<pair<int, int> >& p) {
	    // Code here
	    vector<vector<int>>adj(n);
	    vector<int>vis(n);
	    //0->not visited 2->processing 1->done
	    for(auto &i:p){
	        adj[i.first].push_back(i.second);
	    }
	    for(int i=0;i<n;i++){
	        if(vis[i]==0){
	            if(isCyclic(adj,i,vis))return false;
	        }
	    }
	    return true;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends