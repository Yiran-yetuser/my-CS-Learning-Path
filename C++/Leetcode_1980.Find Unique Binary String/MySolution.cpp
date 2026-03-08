class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string res;
        for(int i = 0;i<nums.size();i++) {
            res.push_back(nums[i][i] == '0'?'1':'0');
        }
        return res;
    }
};
