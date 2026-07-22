class Solution {
public:
    static const int MOD = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {

        int n = s.size();
        vector<int> prefCnt(n + 1, 0);
        vector<int> digits;

        for (char c : s) {
            if (c != '0') digits.push_back(c - '0');
        }

        int m = digits.size();

        vector<long long> prefSum(m + 1, 0);
        vector<long long> prefVal(m + 1, 0);
        vector<long long> pow10(m + 1, 1);

        for (int i = 1; i <= m; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD;

        for (int i = 0; i < m; i++) {
            prefSum[i + 1] = prefSum[i] + digits[i];
            prefVal[i + 1] = (prefVal[i] * 10 + digits[i]) % MOD;
        }

        for (int i = 0; i < n; i++) prefCnt[i + 1] = prefCnt[i] + (s[i] != '0');

        vector<int> ans;

        for (auto &q : queries) {

            int l = q[0];
            int r = q[1];

            int left = prefCnt[l];
            int right = prefCnt[r + 1] - 1;

            if (left > right) {
                ans.push_back(0);
                continue;
            }

            long long sum = prefSum[right + 1] - prefSum[left];
            int len = right - left + 1;

            long long x = (prefVal[right + 1] - prefVal[left] * pow10[len] % MOD + MOD) % MOD;
            ans.push_back((x * sum) % MOD);
        }

        return ans;
    }
};