// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{
  public:
    string nextPalin(string s) { 
        //complete the function here
        int n=s.size();
        if(n<=3)return "-1";
        string half=s.substr(0,n/2);
        int i=half.length()-2,j=half.length()-1;
        //code for next permutation
        while(i>=0&&half[i]>=half[i+1]){
            i--;
        }//find the first decreasing element
        if(i==-1)return "-1";
        if(i>=0){
            //replace the decreasing element with a larger element than s[i]
            while (j >= 0 && half[j] <= half[i]) {
                j--;
            }
                char temp=half[j];
                half[j]=half[i];
                half[i]=temp;
        }
        //reverese the rest part of the array
        reverse(half.begin()+i+1,half.end());
        string ans=half;
        if(s.length()%2){
            half+=s[s.length()/2];
        }
        reverse(half.begin(),half.end());
        ans+=half;
        return ans;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution obj;
        cout << obj.nextPalin(s) << endl;
    }
    return 0;
}  // } Driver Code Ends