
class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size() - 1;
        int j = b.size() - 1;
        string ans = "";
        int carry = 0;

        while (i >= 0 || j >= 0 || carry) {
            int x = carry;

            if (i >= 0) x += a[i--] - '0';
            if (j >= 0) x += b[j--] - '0';

            ans += (x % 2) + '0';
            carry = x / 2;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
