// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    vector<pair<int,int>>dir{{0,1},{1,0},{-1,0},{0,-1}};
    bool dfs(int i,int j,vector<vector<char>>& board, string word,int idx){
        if(idx==word.size()){
            return true;
        }
        if(i>=board.size()||i<0||j>=board[0].size()||j<0)return false;
        // cout<<board[i][j]<<" ";
        
        if(word[idx]!=board[i][j])return false;
        
        bool x=false;
        if(word[idx]==board[i][j]){
            board[i][j]='#';
            for(int k=0;k<4;k++)
            x|=dfs(i+dir[k].first,j+dir[k].second,board,word,idx+1);
            board[i][j]=word[idx];
            
        }
        
        return x;
    }
    bool isWordExist(vector<vector<char>>& board, string word) {
        // Code here
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(dfs(i,j,board,word,0))return true;
            }
        }
    
        return false;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>board(n, vector<char>(m, '*'));
		for(int i = 0; i < n; i++)
			for(int j = 0; j < m; j++)
				cin >> board[i][j];
		string word;
		cin >> word;
		Solution obj;
		bool ans = obj.isWordExist(board, word);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends