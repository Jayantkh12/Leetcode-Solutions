class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n= nums.size();
        int ans = 0;
        int left = 0;
        int sum = 0;
        for(int i = 0; i<n ;i++){
            mp[nums[i]]++;
            sum+=nums[i];
    
            while(mp[nums[i]]>1){
                sum-=nums[left];
                mp[nums[left]]--;
                left++;
            }
            ans = max(ans,sum);
        }
        return ans;
    }
};