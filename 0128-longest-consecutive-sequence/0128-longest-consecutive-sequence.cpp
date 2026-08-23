class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int maxLen = 0;

        for (int num : st) {
            if (st.find(num - 1) == st.end()) {
                int currentNum = num;
                int currentLen = 1;

                while (st.find(currentNum + 1) != st.end()) {
                    currentNum++;
                    currentLen++;
                }

                maxLen = max(maxLen, currentLen);
            }
        }

        return maxLen;
    }
};