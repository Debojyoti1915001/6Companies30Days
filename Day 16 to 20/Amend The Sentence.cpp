// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
    public:
    string amendSentence (string s)
    {
        // your code here
        string ans;
        for(int i=0;i<s.length();i++){
            if(i==0){
                ans+=tolower(s[i]);
            }else if(isupper(s[i])){
                ans+=' ';
                ans+=tolower(s[i]);
            }else{
                ans+=s[i];
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
	int t; cin >> t;
	while (t--)
	{
		string s; cin >> s;
		Solution ob;
		cout << ob.amendSentence (s) << endl;
	}
}  // } Driver Code Ends