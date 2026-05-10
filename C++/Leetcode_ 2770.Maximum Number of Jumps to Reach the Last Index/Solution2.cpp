class SegmentTree {
    vector<int> tree;
    void maintain(int o) {
        tree[o] = max(tree[2 * o], tree[2 * o + 1]);
    }

public:
    SegmentTree(int m) : tree(4 * m, -1) {}

    int query(int o, int l, int r, int QL, int QR) {
        if (r < QL || l > QR) return -1;
        if (l >= QL && r <= QR) {
            return tree[o];
        }
        int mid = l + (r - l)/2;
        
   
        return max(query(2 * o, l, mid, QL, QR), query(2 * o + 1, mid + 1, r, QL, QR));
     
    }

    void modify(int o, int l, int r, int Q, int target) {
    
        if (r < Q || l > Q) return;
        
        if (l == r) {
            tree[o] = target;
            return;
        }
        int mid = l + (r - l)/2;
        modify(2 * o, l, mid, Q, target);
        modify(2 * o + 1, mid + 1, r, Q, target);
        maintain(o);
    }
};
class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> arr(nums);
        ranges::sort(arr);
        arr.erase(unique(arr.begin(), arr.end()), arr.end());
        int m = arr.size();
        unordered_map<int, int> mapping;
        for (int i = 0;i < m;++i) {
            mapping[arr[i]] = i;
        }
        SegmentTree t(m);
        t.modify(1, 0, m - 1, mapping[nums[0]], 0);

        for (int i = 1;i < n;++i) {
            long long x = nums[i];
            int l = ranges::lower_bound(arr, x - target) - arr.begin();
            int r = prev(ranges::upper_bound(arr, x + target)) - arr.begin();
            int res = t.query(1, 0, m - 1, l, r);
            if (res != -1) {
                t.modify(1, 0, m - 1, mapping[x], res + 1);
            }
        }
        return t.query(1, 0, m - 1, mapping[nums.back()], mapping[nums.back()]);

    }
};
