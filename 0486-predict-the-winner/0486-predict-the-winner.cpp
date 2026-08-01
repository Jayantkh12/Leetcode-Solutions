class Solution {
    int solve(vector<int>& nums,int i ,int j){
        if(i>j) return 0;

        return max(nums[i]-solve(nums,i+1,j),nums[j]-solve(nums,i,j-1));
    }
public:
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        return solve(nums,0,n-1)>=0;
    }
};