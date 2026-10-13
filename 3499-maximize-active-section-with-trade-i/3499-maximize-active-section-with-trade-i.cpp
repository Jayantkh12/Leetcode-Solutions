class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        int ans =0;

        int ones = count(s.begin(),s.end(),'1');

        int i = 0;
        vector<int>zeroBlock;
        while(i<n){
            if(s[i]=='0'){
                int st = i;
                while(i<n&& s[i]=='0')i++;

                zeroBlock.push_back(i-st);
            }
            else{
                i++;
            }
        }
        
        for(int i =1;i<zeroBlock.size();i++){
            ans = max(ans,zeroBlock[i]+zeroBlock[i-1]);
        }

        return ans+ones;
    }
};