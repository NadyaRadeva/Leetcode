class Solution {
public:
    int countDigits(int x) {
        int counter=0;

        while(x!=0){
            x/=10;
            ++counter;
        }

        return counter;
    }

    int* turnNumIntoArr(int x) {
        int* arr=new int[countDigits(x)];
        int index=0;

        while(x!=0) {
            arr[index]=x%10;
            x/=10;
            ++index;
        }

        return arr;
    }

    bool isPalindrome(int x) {
        int* numberArr=turnNumIntoArr(x);

        if(x < 0) {
            return false;
        }

        for(size_t i=0; i < countDigits(x); ++i) {
            if(numberArr[i] != numberArr[countDigits(x) - i - 1]) {
                return false;
            }
        }

        return true;

        delete numberArr;
    }
};
