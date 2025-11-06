class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> result;

        for (const string& op : operations) {
            if (op == "+") {
                int top1 = result.top(); 
                result.pop();
                int top2 = result.top();
                int sum = top1 + top2;
                result.push(top1);
                result.push(sum);
            }
            else if (op == "D") {
                result.push(result.top() * 2);
            }
            else if (op == "C") {
                result.pop();
            }
            else {
                result.push(stoi(op));
            }
        }

        int total = 0;
        while (!result.empty()) {
            total += result.top();
            result.pop();
        }

        return total;
    }
};
