// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    vector<pair<int,int>>dir={{0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,1},{1,-1},{-1,-1}};
    void dfs(vector<vector<int>>& grid,int i,int j,int &c){
        if(i>=grid.size()||j>=grid[0].size()||i<0||j<0||grid[i][j]==0)return ;
        grid[i][j]=0;
        c++;
        for(auto p:dir){
            dfs(grid,i+p.first,j+p.second,c);
        }
    }
    int findMaxArea(vector<vector<int>>& grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    int c=0;
                    dfs(grid,i,j,c);
                    ans=max(ans,c);
                }
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends