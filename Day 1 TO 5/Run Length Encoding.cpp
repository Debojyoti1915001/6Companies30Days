// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

string encode(string src);    
 
int main() {
	
	int T;
	cin>>T;
	while(T--)
	{
		string str;
		cin>>str;
		
		cout<<encode(str)<<endl;
	}
	return 0;
}// } Driver Code Ends


/*You are required to complete this function */

string encode(string s)
{     
  //Your code here 
  string ans="";
  int i=0;
  while(i<s.length()){
      int c=1;
      ans+=s[i];
      while(i!=s.length()-1&&s[i]==s[i+1]){
          i++;
          c++;
      }
      ans+=c+'0';
      i++;
  }
  return ans;
}     
 
