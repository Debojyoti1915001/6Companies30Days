class Solution {
public:
    int minSubArrayLen(int t, vector<int>& v) {
        int n=v.size();
        long long int i=0,j=0;
        long long int ans=INT_MAX,sum=0;
        while(j<n){
            sum+=v[j];
                while(sum>=t){
                    ans=min(ans,j-i+1);
                    sum-=v[i];
                    i++;
                }
            
            j++;
        }
        return ans==INT_MAX?0:ans;
    }
};