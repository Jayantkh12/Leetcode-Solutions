class Solution {
public:
    int largestInteger(int n, int s) {

        if (s > 9 * n)
            return -1;

        string ans = "";

        for (int i = 0; i < n; i++) {
            for (int d = 9; d >= 0; d--) {
                if (s - d >= 0 && s - d <= 9 * (n - i - 1)) {
                    ans.push_back('0' + d);
                    s -= d;
                    break;
                }
            }
        }

        return stoi(ans);
    }
};