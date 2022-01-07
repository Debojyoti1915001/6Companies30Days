//TLE Solution
// vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
//         // your code here
//         map<int,int>m;
//         for(int i=0;i<k;i++){
//             m[arr[i]]++;
//         }
//         vector<int>res;
//         auto itr=m.end();
//         advance(itr,-1);
//         res.push_back(itr->first);
//         for(int i=k;i<n;i++){
//             m[arr[i-k]]--;
//             if(m[arr[i-k]]==0)m.erase(arr[i-k]);
//             m[arr[i]]++;
//             itr=m.end();
//             advance(itr,-1);
//             res.push_back(itr->first);
//         }
//         return res;
//     }

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        // your code here
        vector<int>res;
        priority_queue<pair<int,int>>pq;
        int i=0,j=0;
        while(j<n){
            if(j-i+1<k){
                pq.push({arr[j],j});
                j++;
            }else{
                pq.push({arr[j],j});
                int t=pq.top().first;
                res.push_back(t);
                while(!pq.empty()&&pq.top().second<=i){
                    pq.pop();
                }
                i++;
                j++;
            }
        }
        return res;
    }
};

// { Driver Code Starts.

int main() {

    int t;
    cin >> t;

    while (t--) {

        int n, k;
        cin >> n >> k;

        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        Solution ob;
        vector<int> res = ob.max_of_subarrays(arr, n, k);
        for (int i = 0; i < res.size(); i++) cout << res[i] << " ";
        cout << endl;
    }

    return 0;
}  // } Driver Code Ends