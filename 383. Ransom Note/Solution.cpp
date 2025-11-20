class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> res;

        for (int i = 0; i < ransomNote.length(); ++i) {
            res[ransomNote[i]]++;
        }

        for (int i = 0; i < magazine.length(); ++i) {
            char c = magazine[i];
            if (res.find(c) != res.end()) {
                res[c]--;
                if (res[c] == 0) {
                    res.erase(c);
                }
            }
        }

        return res.empty();
    }
};
