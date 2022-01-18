// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<vector<int>> fourSum(vector<int> &a, int k) {
    if (a.size() < 4) return {};
    vector<vector<int>> ans;
    sort(a.begin(), a.end());
    for (int i = 0; i < a.size() - 3; ++i) {
        if (a[i] > 0 && a[i] > k) break;
        if (i > 0 && a[i] == a[i - 1]) continue;
        for (int j = i + 1; j < a.size() - 2; ++j) {
            if (j > i + 1 && a[j] == a[j - 1]) continue;

            int left = j + 1;
            int right = a.size() - 1;
            while (left < right) {
                int l = left;
                int r = right;
                int sum = a[i] + a[j] + a[l] + a[r];
                if (sum == k) {
                    ans.push_back({a[i], a[j], a[left], a[right]});

                    while (left < right && a[left] == a[l]) left++;
                    while (left < right && a[right] == a[r]) right--;
                } else if (sum > k) {
                    right--;
                } else {
                    left++;
                }
            }
        }
    }
    return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends