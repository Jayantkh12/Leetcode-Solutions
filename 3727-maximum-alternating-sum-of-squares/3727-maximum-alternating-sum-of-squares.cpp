class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        long long ans = 0;
        for(int& num :nums){
            if(num<0){
                num = -num;
            }
        }
        sort(nums.begin(),nums.end());

        int l = 0;
        int r = nums.size()-1;
        while(l<r){
            ans+= (long long)nums[r]*nums[r];
            ans-= (long long)nums[l]*nums[l];
            r--;
            l++;
        }
        if(nums.size()%2!=0){
            ans+= (long long)nums[r]*nums[r];
        }
        return ans;
    }
};