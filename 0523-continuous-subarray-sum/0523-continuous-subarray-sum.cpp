class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        mp[0] = -1;
        int n = nums.size();
        int preffixSum =0;
        for(int i= 0 ; i<n;i++){
            preffixSum += nums[i];
            int rem = preffixSum%k;

            if (mp.find(rem) != mp.end()) {
                if (i - mp[rem] >= 2)
                    return true;
            } else {
                mp[rem] = i;
            }
        }
        return false;
    }
};