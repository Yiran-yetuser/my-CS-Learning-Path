class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int ans = 0;
        int i = 0;
        for (int j = 0; j < nums2.size(); j++) {
            while (i < nums1.size() && nums1[i] > nums2[j]) {
                i++;
            }
            if (i == nums1.size()) {
                return ans;
            }
            if (ans < j - i) {
                ans = j - i;
            }
        }
        return ans;
    }
};
