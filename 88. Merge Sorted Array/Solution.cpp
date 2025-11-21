class Solution {
public:
    void swap(int& a, int& b) {
        int temp = a;
        a = b;
        b = temp;
    }

    int partition(vector<int>& nums, int low, int high) {
        int pivot = nums[(low + high) / 2];
        int i = low;
        int j = high;

        while (i <= j) {
            while (nums[i] < pivot) {
                i++;
            }

            while (nums[j] > pivot) {
                j--;
            }

            if (i <= j) {
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
        }
        return i;
    }

    void quickSort(vector<int>& nums, int low, int high) {
        if (low >= high) {
            return;
        }

        int p = partition(nums, low, high);
        quickSort(nums, low, p - 1);
        quickSort(nums, p, high);
    }

    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        nums1.resize(m + n);

        for (size_t i = 0; i < n; ++i) {
            nums1[m + i] = nums2[i];
        }

        quickSort(nums1, 0, nums1.size() - 1);
    }
};
