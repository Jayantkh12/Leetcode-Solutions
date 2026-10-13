class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int cnt = 0;
        int left = 0;

        vector<int> pre(n + 1, 0);

        for (int i = 0; i < n; i++) {
            if (nums[i] == target)
                pre[i + 1] = pre[i] + 1;
            else
                pre[i + 1] = pre[i] - 1;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (pre[i] > pre[j]) {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};
