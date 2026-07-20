class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double ans = INT_MIN;
        double sum  = 0;
        int n =  nums.size();
        int left = 0;
        for(int i = 0 ; i<k ;i++){
            sum+= nums[i];
        }
        ans = max(ans,sum/k);
        for(int i = k;i<n;i++){
            sum = sum + nums[i] - nums[left];
            left++;
            ans = max(ans,sum/k);
        }
        return ans;
    }
};