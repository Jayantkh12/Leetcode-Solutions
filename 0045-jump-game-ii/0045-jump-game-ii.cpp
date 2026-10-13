class Solution {
    int solve(vector<int>& nums, int curr,vector<int>& dp){
        
        if(curr>=nums.size()-1) return 0;

        if (dp[curr] != -1) return dp[curr];
        int ans = INT_MAX;
        for(int i = 1;i<=nums[curr];i++){
            if (curr + i < nums.size()) {
                int jumps = solve(nums, curr + i, dp);

                if (jumps != INT_MAX) {
                    ans = min(ans, 1 + jumps);
                }
            }
        }
        return dp[curr] = ans;
    }
public:
    int jump(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return solve(nums,0,dp);
    }
};