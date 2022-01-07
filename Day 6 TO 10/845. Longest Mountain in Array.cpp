class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n=arr.size();
        int i=0;
        int ans=0;
        while(i<n){
            if(i<n-2&&arr[i]<arr[i+1]){
                int j=i;
                int f=0;
                while(j<n-1&&arr[j]<arr[j+1])j++;
                while(j<n-1&&arr[j]>arr[j+1])j++,f=1;
                if(f){
                    ans=max(ans,j-i+1);
                }
                i=j;
            }else{
                i++;
            }
        }
        if(ans>=3)
        return ans;
        return 0;
    }
};