class Solution {
public:
    unordered_map<string, bool> memo;
    bool isScramble(string s1, string s2) {
        if (s1 == s2)
            return true;
        string key = s1 + "#" + s2;
        if (memo.find(key) != memo.end())
            return memo[key];
        int n = s1.size();
        vector<int> count(26, 0);
        for (int i = 0; i < n; i++) {
            count[s1[i] - 'a']++;
            count[s2[i] - 'a']--;
        }
        for (int x : count) {
            if (x != 0)
                return memo[key] = false;
        }
        for (int i = 1; i < n; i++) {
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) &&
                isScramble(s1.substr(i), s2.substr(i))) {
                return memo[key] = true;
            }
            if (isScramble(s1.substr(0, i), s2.substr(n - i)) &&
                isScramble(s1.substr(i), s2.substr(0, n - i))) {
                return memo[key] = true;
            }
        }
        return memo[key] = false;
    }
};