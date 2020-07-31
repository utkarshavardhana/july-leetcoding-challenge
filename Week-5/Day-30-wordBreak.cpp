// class Solution {
// public:
    
//     void doStuff(string s, unordered_set<string> m, string tmp, vector<string> &res) {
//         if(s.empty()) {
//             if(tmp.empty())    return;
//             tmp.pop_back();
//             res.push_back(tmp);
//             return;
//         }
//         for(int i=1; i<=s.size(); i++) {
//             if(m.find(s.substr(0, i)) != m.end()) {
//                 tmp += s.substr(0, i);
//                 tmp += " ";
//                 doStuff(s.substr(i, s.size()-i), m, tmp, res);
//                 tmp.erase(tmp.begin() + tmp.size() - i-1, tmp.begin() + tmp.size());
//             }
//         }
//     }
    
//     vector<string> wordBreak(string s, vector<string>& wordDict) {
//         vector<string> res;
//         unordered_set<string> m;
//         unordered_set<char> st;
//         for(string gs : wordDict) {
//             m.insert(gs);
//             for(char c : gs)    st.insert(c);
//         }
//         for(char c : s) if(st.find(c) == st.end())  return res;
//         string tmp;
//         doStuff(s, m, tmp, res);
//         return res;
//     }
// };


class Solution {
public:
    vector<string> wordBreak(string& s, int idx, unordered_set<string>& words, unordered_map<int, vector<string>>& dp) {
        if (dp.count(idx) == 0) {
            for (int i = idx-1; i >= 0; i--) {
                string tail = s.substr(i, idx-i);
                if (words.count(tail) == 0) continue;
                for (string sol : wordBreak(s, i, words, dp)) {
                    dp[idx].push_back(sol.append(tail).append(" "));
                }
            }
        }
        
        return dp[idx];
    }
    
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> words(wordDict.cbegin(), wordDict.cend());
        unordered_map<int, vector<string>> dp;
        dp[0] = {""};

        vector<string> result = wordBreak(s, s.length(), words, dp);
        for (string& sentence : result) sentence.pop_back();
        return result;
    }
};
