class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        map<int, int> m;
        for(int i : nums) {
            m[i]++;
        }
        map<int, vector<int>, greater<int>> ma;
        for(auto it=m.begin(); it!=m.end(); it++) {
            ma[(*it).second].push_back((*it).first);
        }
        for(auto it=ma.begin(); it!=ma.end(); it++) {
            for(int i : (*it).second) {
                if(k--) {
                    res.push_back(i);
                } else {
                    return res;
                }
            }
        }
        return res;
    }
};
