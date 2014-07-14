class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        queue<string> q;
        q.push(start);
        unordered_map<string, bool> visited;
        visited[start] = true;
        int l1 = 1, l2 = 0, l = 1;
        while (!q.empty()) {
            string f = q.front();
            q.pop();
            -- l1;
            if (f == end) return l;
            for (int i = 0; i < f.size(); ++i) {
                for (int c = 'a'; c <= 'z'; ++c) {
                    string t = f;
                    t[i] = c;
                    if (dict.find(t) != dict.end() && !visited[t]) {
                        q.push(t);
                        visited[t] = true;
                        ++ l2;
                    }
                }
            }
            if (l1 == 0) {
                l1 = l2;
                l2 = 0;
                ++ l;
            }
        }
        return 0;
    }
};