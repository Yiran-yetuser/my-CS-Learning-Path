class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<int, vector<int>> m;
        vector<int> answer(queries.size());
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            m[nums[i]].push_back(i);
        }
        for (auto& [_, pos] : m) {
            int x = pos[0];
            pos.insert(pos.begin(), pos.back() - n);
            pos.push_back(x + n);
        }
        for (int i = 0; i < queries.size(); i++) {
            int val = nums[queries[i]];
            if (m[val].size() == 3) {
                answer[i] = -1;
                continue;
            }
            int pos = lower_bound(m[val].begin(), m[val].end(), queries[i]) -
                      m[val].begin();
            answer[i] = min(m[val][pos + 1] - m[val][pos],
                            m[val][pos] - m[val][pos - 1]);
        }

        return answer;
    }
};
