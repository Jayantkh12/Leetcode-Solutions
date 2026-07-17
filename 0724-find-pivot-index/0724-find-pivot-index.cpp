class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n);

        int total = 0;
        for (int num : nums)
            total += num;

        prefix[0] = 0;

        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }

        for (int i = 0; i < n; i++) {
            int leftSum = prefix[i];
            int rightSum = total - leftSum - nums[i];

            if (leftSum == rightSum)
                return i;
        }

        return -1;
    }
};