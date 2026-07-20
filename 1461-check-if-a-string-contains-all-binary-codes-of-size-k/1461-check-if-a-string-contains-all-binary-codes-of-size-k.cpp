class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        unordered_set<string> store;

        if (k > n) return false;
        string temp = "";
        
        for (int i = 0; i < k; i++) {
            temp.push_back(s[i]);
        }
        store.insert(temp);
        int j = k;
        while (j < n) {
            temp.push_back(s[j]);
            temp.erase(temp.begin());
            store.insert(temp);
            j++;
        }
        return store.size() == (1 << k);
    }
};