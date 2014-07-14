// straightforward solution, kind of stupid, O(n^2), without extra space
class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        int n = tokens.size();
        if (n <= 0) return 0;
        unordered_map<string, int> opt;
        opt["+"] = 1; opt["-"] = 2; opt["*"] = 3; opt["/"] = 4;
        vector<string>::iterator it = tokens.begin();
        while (it != tokens.end()) {
            if (opt[*it]) {
                int l = stoi(*(it - 2));
                int r = stoi(*(it - 1));
                int ret = operate(l, r, opt[*it]);
                ostringstream os;
                os<<ret;
                it = tokens.erase(it - 2, it + 1);
                tokens.insert(it, os.str());
            } else {
                it ++;
            }
        }
        return stoi(tokens[0]);
    }
    
    int operate(int l, int r, int opt) {
        int ret = 0;
        if (opt == 1) ret = l + r;
        else if (opt == 2) ret = l - r;
        else if (opt == 3) ret = l * r;
        else ret = l / r;
        return ret;
    }
};

// Better Solution, O(n) time, O(n) space.
class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> stk;
        unordered_map<string, int> opt;
        opt["+"] = 1; opt["-"] = 2; opt["*"] = 3; opt["/"] = 4;
        for (int i = 0; i < tokens.size(); ++i) {
            if (!opt[tokens[i]]) {
                stk.push(stoi(tokens[i]));
            } else {
                int r = stk.top(); stk.pop();
                int l = stk.top(); stk.pop();
                int ret = operate(l, r, opt[tokens[i]]);
                stk.push(ret);
            }
        }
        return stk.top();
    }
    
    inline int operate(int l, int r, int opt) {
        int ret = 0;
        if (opt == 1) ret = l + r;
        else if (opt == 2) ret = l - r;
        else if (opt == 3) ret = l * r;
        else ret = l / r;
        return ret;
    }
};

// kick the map, shorter, maybe faster.
class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        stack<int> stk;
        for (int i = 0; i < tokens.size(); ++i) {
            if (tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/") {
                stk.push(stoi(tokens[i]));
            } else {
                int right = stk.top(); stk.pop();
                int left = stk.top(); stk.pop();
                int ret = 0;
                if (tokens[i] == "+") ret = left + right;
                else if (tokens[i] == "-") ret = left - right;
                else if (tokens[i] == "*") ret = left * right;
                else ret = left / right;
                stk.push(ret);
            }
        }
        return stk.top();
    }
};
