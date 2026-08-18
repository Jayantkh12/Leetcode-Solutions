class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        set<pair<int, int>> kelem;
        vector<int> ans;
        int n = nums.size();
        int i = 0;
        while (i < k) {
            kelem.insert({nums[i], i});
            i++;
        }
        auto x = *kelem.rbegin();
        ans.push_back(x.first);
        while (i < n) {
            kelem.erase({nums[i - k], i - k});
            kelem.insert({nums[i], i});
            x = *kelem.rbegin();
            ans.push_back(x.first);
            i++;
        }
        return ans;
    }
};