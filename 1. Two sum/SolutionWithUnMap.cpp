class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> m;

        for(int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            if(m.find(target - num) != m.end()) {
                return {i, m[target - num]};
            }
            m[num] = i;
        }

        return {};
    }

};
