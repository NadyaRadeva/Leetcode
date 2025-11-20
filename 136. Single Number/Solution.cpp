// With unordered map

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> a;

        for (int i = 0; i < nums.size(); ++i) {
            a[nums[i]]++;
        }

        for (unordered_map<int,int>::iterator it = a.begin(); it != a.end(); ++it) {
            if (it->second == 1) {
                return it->first;
            }
        }

        return -1;
    }
};
