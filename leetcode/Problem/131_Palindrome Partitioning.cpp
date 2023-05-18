class Solution {
public:
    vector<vector<string>> partition(string s) {
        int l = s.size();
        vector<vector<bool>> dp(l, vector<bool>(l, false));
        vector<vector<string>> result;
        vector<string> currentList;
        dfs(result, s, 0, currentList, dp);
        return result;
    }

    void dfs(vector<vector<string>>& result, string &s, int start,
    vector<string>& currentList, vector<vector<bool>>& dp) {
        if (start >= s.size()) result.push_back(currentList);
        for (int end = start; end < s.size(); end++) {
            if (s[start] == s[end] && (end-start <= 2 || dp[start+1][end-1])) {
                dp[start][end] = true;
                currentList.push_back(s.substr(start, end-start+1));
                dfs(result, s, end+1, currentList, dp);
                currentList.pop_back();
            }
        }
    }

};