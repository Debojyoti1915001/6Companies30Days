// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    bool canPair(vector<int> nums, int k) {
        // Code here.
        unordered_map<int,int>m;
        for(auto &num:nums){
            num=num%k;
            m[num]++;
            if(m[k-num]){
                m[num]--;
                m[k-num]--;
            }
        }
        if(m[0]%2!=0)return false;
        for(auto &i:m){
            if(i.first==0)continue;
            if(i.second)return false;
        }
        return true;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, k;
        cin >> n >> k;
        vector<int> nums(n);
        for (int i = 0; i < nums.size(); i++) cin >> nums[i];
        Solution ob;
        bool ans = ob.canPair(nums, k);
        if (ans)
            cout << "True\n";
        else
            cout << "False\n";
    }
    return 0;
}  // } Driver Code Ends