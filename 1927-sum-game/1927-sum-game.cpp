class Solution {
public:
    bool sumGame(string num) {
        string l = num.substr(0,num.size()/2);
        string r = num.substr(num.size()/2,num.size());
        int lS= 0;
        int lQ = 0;
        int rQ = 0;
        int rS = 0;
        
        for(int i = 0 ;i<num.size()/2;i++){
            if(l[i]=='?')lQ++;
            else lS += l[i] - '0';

            if(r[i]=='?')rQ++;
            else rS+=r[i]- '0';
        }
        
        int diff = 2 * (lS - rS) + 9 * (lQ - rQ);

        return diff != 0;
    } 
};