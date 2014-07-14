// O(n), time complexity doesn't matter actually.
class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> ret;
        int len = 0, pre = 0, i = 0, j = 0;
        while (j < words.size()) {
            len += words[j++].size() + 1;
            if (len > L) {
                if (len - 1 > L) {
                    -- j;
                    len -= words[j].size() + 1;
                }
                ret.push_back(join(words, i, j, len - j + i, L, j == words.size()));
                i = j;
                len = 0;
            }
            if (len > 0 && j == words.size()) 
                ret.push_back(join(words, i, j, len - 1, L, true));
        }
        return ret;
    }
    
    string join(vector<string> &words, int start, int end, int len, int L, bool last) {
        string s(words[start]);
        int n = end - start;
        if (n > 1) {
            int aver = (L - len) / (n - 1);
            int extra = (L - len) % (n - 1);
            if (last) {aver = 1; extra = 0;}
            for (int i = start + 1; i < end; ++i) {
                s.append(aver, ' ');
                if (extra -- > 0) s += " ";
                s += words[i];
            }
        }
        s.append(L - s.size(), ' ');
        return s;
    }
    
};