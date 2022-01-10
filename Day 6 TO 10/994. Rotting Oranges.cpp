class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>>q;
        int dir[5]={1,0,-1,0,1};
        int ans=0,oranges=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                    grid[i][j]=0;
                    oranges++;
                }else if(grid[i][j]==1){
                    oranges++;
                }
            }
        }
        while(q.size()){
            int sz=q.size();
            while(sz--){
                oranges--;
                int i=q.front().first;
                int j=q.front().second;
                q.pop();
                for(int k=0;k<4;k++){
                    int ai=i+dir[k];
                    int aj=j+dir[k+1];
                    if(ai>=0&&ai<n&&aj>=0&&aj<m&&grid[ai][aj]==1){
                        q.push({ai,aj});
                        grid[ai][aj]=0;
                    }
                }
            }
            ans++;
        }
        if(oranges!=0)return -1;
        return max(0,ans-1);
    }
};