// Longest Consecutive Sequence

// This is a stupid solution -- Brute Force
class Solution {
public:
    int longestConsecutive(vector<int> &num) {
        if(num.size() < 2) return num.size();
        map<int, bool> visit;
        for(int i = 0; i < num.size(); ++i) visit[num[i]] = true;
        map<int, bool>::iterator it = visit.begin();
        int tmp = 1, ret = 1, last = (*it++).first;
        while(it != visit.end()) {
            if((*it).first != last + 1) {
                tmp = 1;
            } else {
                ++tmp;
            }
            ret = max(ret, tmp);
            last = (*it++).first;
        }
        return ret;
    }
};

// 