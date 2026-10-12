
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int l = 0;
        int r = 0;
        int total = 0;

        for (int num : nums) {
            total += num;
        }

        int target = total - x;

        if (target < 0) return -1;

        int sum = 0;
        int longest = -1;

        while (r < n) {
            sum += nums[r];

            while (sum > target && l <= r) {
                sum -= nums[l];
                l++;
            }

            if (sum == target) {
                longest = max(longest, r - l + 1);
            }

            r++;
        }

        if (longest == -1) return -1;

        return n - longest;
    }
};
