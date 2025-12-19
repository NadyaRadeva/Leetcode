class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(trust.size() < n - 1) {
            return -1;
        }

        vector<int> potential(n + 1, 0);

        for(auto& relationship: trust) {
            potential[relationship[0]]--;
            potential[relationship[1]]++;
        }

        for(int i = 1; i <= n; ++i) {
            if(potential[i] == n - 1) {
                return i;
            }
        }

        return -1;
    }
};
