class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n = num.size();
        vector<int> ans;
        int i = n - 1;

        while (i >= 0 || k > 0) {
            int sum = k % 10 + (i >= 0 ? num[i] : 0);
            ans.push_back(sum % 10);
            k = k / 10 + sum / 10;
            i--;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};