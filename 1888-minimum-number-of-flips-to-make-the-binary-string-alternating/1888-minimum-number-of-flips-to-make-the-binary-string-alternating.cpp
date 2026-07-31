class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        string t = s + s;

        int mismatch01 = 0;  
        int mismatch10 = 0;   

        int ans = INT_MAX;
        int left = 0;

        for (int right = 0; right < 2 * n; right++) {

            if (t[right] != ((right % 2 == 0) ? '0' : '1')) mismatch01++;

            if (t[right] != ((right % 2 == 0) ? '1' : '0')) mismatch10++;

            if (right - left + 1 > n) {

                if (t[left] != ((left % 2 == 0) ? '0' : '1')) mismatch01--;

                if (t[left] != ((left % 2 == 0) ? '1' : '0')) mismatch10--;

                left++;
            }

            if (right - left + 1 == n) ans = min(ans, min(mismatch01, mismatch10));
        }

        return ans;
    }
};