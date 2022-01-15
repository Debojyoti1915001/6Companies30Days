// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int isValid(vector<vector<int>> mat){
        // code here
        int N=9;
        vector<unordered_set<int>>rowSet(9);
        vector<unordered_set<int>>columnSet(9);
        vector<unordered_set<int>>squareSet(9);
        for(int r=0;r<9;r++){
            for(int c=0;c<9;c++){
                if(mat[r][c]==0)continue;
                int sq=(r/3)*3+c/3;
                if(rowSet[r].count(mat[r][c])||columnSet[c].count(mat[r][c])||squareSet[sq].count(mat[r][c]))return false;
                rowSet[r].insert(mat[r][c]);
                columnSet[c].insert(mat[r][c]);
                squareSet[sq].insert(mat[r][c]);
            }
        }
        return true;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        vector<vector<int>> mat(9, vector<int>(9, 0));
        for(int i = 0;i < 81;i++)
            cin>>mat[i/9][i%9];
        
        Solution ob;
        cout<<ob.isValid(mat)<<"\n";
    }
    return 0;
}  // } Driver Code Ends