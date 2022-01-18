// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int n, int m) 
    {
        // code here 
    int l=0,r=m-1,u=0,d=n-1;
    vector<int>arr(n*m);
    int dir=0,i=0;
    while(i<n*m){
        if(dir==0){
            int c=l;
            while(c<=r){
                arr[i++]=matrix[u][c++];
            }
            // cout<<i<<" ";
        }
        if(dir==1){
            int c=u+1;
            while(c<=d){
                arr[i++]=matrix[c++][r];
            }
            // cout<<i<<" ";
        }
        if(dir==2){
            int c=r-1;
            while(c>=l){
                arr[i++]=matrix[d][c--];
            }
            // cout<<i<<" ";
        }
        if(dir==3){
            int c=d-1;
            while(c>u){
                arr[i++]=matrix[c--][l];
            }
            // cout<<i<<" ";
            l++;r--;u++;d--;
        }
        dir=(dir+1)%4;
    }
    return arr;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends