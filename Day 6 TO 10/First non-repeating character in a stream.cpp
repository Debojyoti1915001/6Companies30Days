// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string s){
		    // Code here
		    string res="";
		    vector<int>cnt(26);
		    int i=0,j=0;
		    while(j<s.length()){
		        cnt[s[j]-'a']++;
		        if(cnt[s[i]-'a']==1){
		            res+=s[i];
		        }else{
		            while(i<j&&cnt[s[i]-'a']!=1){
		                i++;
		            }
		            if(i==j){
		                res+='#';
		                i++;
		            }
		            else res+=s[i];
		        }
		        j++;
		    }
		    return res;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends