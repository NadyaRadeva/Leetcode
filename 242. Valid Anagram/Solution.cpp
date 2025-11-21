//Overcomplicated version to practice quick sort

class Solution {
public:
    int partition(string& str, int low, int high) {
        char pivot = str[high];
        int i = low - 1;

        for(int j = low; j < high; j++) {
            if(str[j] <= pivot) {
                i++;
                swap(str[i], str[j]);
            }
        }

        swap(str[i + 1], str[high]);
        return i + 1;
    }

    void quickSort(string& str, int low, int high) {
        if(low < high) {
            int p = partition(str, low, high);
            quickSort(str, low, p - 1);
            quickSort(str, p + 1, high);
        }
    }

    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) {
            return false;
        }

        quickSort(s, 0, s.length() - 1);
        quickSort(t, 0, t.length() - 1);

        return s == t;
    }
};
