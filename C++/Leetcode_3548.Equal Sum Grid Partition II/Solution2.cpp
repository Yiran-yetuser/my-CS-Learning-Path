
class Solution {
public:
    const int MAX_ELEMENT = 100000; // 单个单元格最大值
    bool in_range_and_connect(int x, int y, int rows, int cols, int bound,
                              bool horizontal_or_vertical) {
        bool dec_or_inc = bound < 0;
        bound = abs(bound);
        bool in_range; // 判断满足差值的矩阵单元格本身是否在标记范围
        bool l_in_range, r_in_range;
        bool up_in_range, down_in_range;
        // 分别判断满足差值的矩阵单元格的上下左右单元格是否在标记范围
        if (horizontal_or_vertical) {
            in_range = dec_or_inc ? x < bound : x >= bound;
            if (!in_range)
                return false;
            up_in_range = dec_or_inc ? x - 1 >= 0 : x - 1 >= bound;
            down_in_range = dec_or_inc ? x + 1 < bound : x + 1 < rows;
            l_in_range = y > 0;
            r_in_range = y < cols - 1;
        } else {
            in_range = dec_or_inc ? y < bound : y >= bound;
            if (!in_range)
                return false;
            up_in_range = x > 0;
            down_in_range = x < rows - 1;
            l_in_range = dec_or_inc ? y - 1 >= 0 : y - 1 >= bound;
            r_in_range = dec_or_inc ? y + 1 < bound : y + 1 < cols;
        }
        bool dis_connect =
            (up_in_range && down_in_range && !l_in_range && !r_in_range) ||
            (!up_in_range && !down_in_range && l_in_range && r_in_range);
        // 如果一个单元格上下不在范围而左右都在，那么删除此单元格导致左右断连
        // 上下断连同理
        return !dis_connect;
        // 单元格本身满足条件，且删除不会导致断连
    }
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<long long> row_sums(m);
        // 保存前i行和，前m行即整个矩阵，对题目无意义，不想处理边界因此保留
        vector<long long> col_sums(n);
        // 保存第j列和
        unordered_map<int, int> row_dis_marks;
        // 保存横向分割的两部分差值和此时分割线位置
        unordered_map<int, int> col_dis_marks;
        // 保存纵向分割的两部分差值和此时分割线位置
        long long sum = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int e = grid[i][j];
                sum += e;
                col_sums[j] += e; // 第j列和
            }
            row_sums[i] = sum; // 前i行和
        }
        for (int i = 0; i < m - 1; i++) {
            long long key = row_sums[i] - (sum - row_sums[i]);
            // 两部分差值作key
            if (abs(key) > MAX_ELEMENT) // 差值大于单个单元格最大值，舍去
                continue;
            else if (key == 0)
                return true; // 两部分相等满足
            else if (key < 0)
                row_dis_marks[-key] = i + 1;
            // 0没有正负区分不了方向，因此加一避免使用
            else
                row_dis_marks[key] = -(i + 1);
            // 哈希保存两边差值为键，值为分割线位置。
            // 值负表示更大的一部分在左，正表示在右（包括线本身值）。
        }
        for (int j = 0; j < n - 1; j++) {
            if (j > 0) {
                col_sums[j] += col_sums[j - 1];
            } // 补上前缀和计算
            long long key = col_sums[j] - (sum - col_sums[j]);
            if (abs(key) > MAX_ELEMENT)
                continue;
            else if (key == 0)
                return true;
            else if (key < 0)
                col_dis_marks[-key] = (j + 1);
            else
                col_dis_marks[key] = -(j + 1);
        }

        // 再次遍历原矩阵
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int e = grid[i][j];
                auto f = row_dis_marks.find(e); // 若值等于某横向分割两部分差值
                if (f != row_dis_marks.end()) {
                    if (in_range_and_connect(i, j, m, n, f->second, 1))
                        return true; // 判断此单元格是否满足条件
                }
                f = col_dis_marks.find(e); // 若值等于某纵向分割两部分差值
                if (f != col_dis_marks.end()) {
                    if (in_range_and_connect(i, j, m, n, f->second, 0))
                        return true; // 判断此单元格是否满足条件
                }
            }
        }
        return false; // 无任何单元格满足题意
    }
};

// 作者：Youthful Mayer2DU
// 链接：https://leetcode.cn/problems/equal-sum-grid-partition-ii/solutions/3937358/c-hashbao-cun-chai-zhi-ji-fen-ge-xian-we-8a7w/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
