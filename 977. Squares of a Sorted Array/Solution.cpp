class Solution {
    public:

    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> absNums(nums.size());

        for (size_t i = 0; i < nums.size(); ++i) {
            absNums[i] = nums[i] * nums[i];
        }

        std::sort(absNums.begin(), absNums.end());

        return absNums;
    }

};
