// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends



class Solution
{
    public:
    //Function to calculate the span of stockâ€™s price for all n days.
    vector <int> calculateSpan(int p[], int n)
    {
       // Your code here
       stack<pair<int,int>>stk;
       vector<int>ans;
       for(int i=0;i<n;i++){
           //older stocks are stored in stack so stop when you found something smaller or equal 
           //to p[i]
           while(!stk.empty()&&p[i]>=stk.top().first){
               stk.pop();
           }
           if(stk.empty()){
               ans.push_back(i+1);
           }else{
               ans.push_back(i-stk.top().second);
           }
           stk.push({p[i],i});
       }
       return ans;
    }
};



// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution obj;
		vector <int> s = obj.calculateSpan(a, n);
		
		for(i=0;i<n;i++)
		{
			cout<<s[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}
  // } Driver Code Ends