// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	void dfs(vector<int> adj[],int cur,vector<bool>&vis){
	    vis[cur]=1;
	    for(int itr:adj[cur]){
	        if(!vis[itr]){
	            dfs(adj,itr,vis);
	        }
	    }
	}
	bool isConnected(int V, vector<int> adj[], int c, int d){
	    vector<bool>vis(V);
	    dfs(adj,c,vis);
	    if(!vis[d])return false;
	    return true;
	}
    //Function to find if the given edge is a bridge in graph.
    int isBridge(int V, vector<int> adj[], int c, int d) 
    {
        // Code here
        if(!isConnected(V,adj,c,d)){
            return 0;
        }
        vector<int>temp;
        for(int i=0;i<adj[c].size();i++){
            if(adj[c][i]!=d)temp.push_back(adj[c][i]);
        }
        
        adj[c]=temp;
        temp.clear();
        for(int i=0;i<adj[d].size();i++){
            if(adj[d][i]!=c)temp.push_back(adj[d][i]);
        }
        
        adj[d]=temp;
        if(!isConnected(V,adj,c,d)){
            return 1;
        }  
        return 0;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}

  // } Driver Code Ends