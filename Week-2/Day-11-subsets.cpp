class Solution {
public:
    
    void possibleSets(vector<int> nums, int pos, vector<int> temp, vector<vector<int>> &res) {
        res.push_back(temp);
        for(int i=pos; i<nums.size(); i++) {
            temp.push_back(nums[i]);
            possibleSets(nums, i+1, temp, res);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        possibleSets(nums, 0, temp, res);
        return res;
    }
};
