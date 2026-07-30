class Solution {
public:
    bool checkOnesSegment(string s) {
        bool zero = false;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){
                zero = true;
            }
            else if (zero) {
                return false;
            }
        }
        return true;
    }
};