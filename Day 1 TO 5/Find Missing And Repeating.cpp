// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int*ptr=new int[2]; 
        for(int i=0;i<n;i++){
            int idx=abs(arr[i])-1;
            if(arr[idx]>0){
                arr[idx]=-arr[idx];
            }
            else
            ptr[0]=abs(arr[i]);//since all numbers are positive get a neg no will mean this index was visited before
        }
        for(int i=0;i<n;i++){
            if(arr[i]>0)ptr[1]=i+1;//since that index is not modified
        }
        return ptr;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  // } Driver Code Ends