class Solution {
public:
    void type(const string& s, stack<char>& st) {
        for (char ch : s) {
            if (ch == '#') {
                if (!st.empty()) {
                    st.pop();
                }
            } else {
                st.push(ch);
            }
        }
    }

    bool backspaceCompare(string s, string t) {
        stack<char> strS;
        stack<char> strT;

        type(s, strS);
        type(t, strT);

        if (strS.size() != strT.size()) {
            return false;
        }

        while (!strS.empty()) {
            if (strS.top() != strT.top()) {
                return false;
            }

            strS.pop();
            strT.pop();
        }

        return true;
    }
};
