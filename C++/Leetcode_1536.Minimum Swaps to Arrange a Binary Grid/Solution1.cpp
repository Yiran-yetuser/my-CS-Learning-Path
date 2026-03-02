// class Solution {
// public:
//     int minSwaps(vector<vector<int>>& grid) {
//         int n = grid.size();
//         vector<int> suffixLen;
//         for (int i = 0; i < n; i++) {
//             int count = 0;
//             for (int j = n - 1; j >= 0; j--) {
//                 if (grid[i][j] == 0) {
//                     count++;
//                 } else {
//                     break;
//                 }
//             }
//             suffixLen.push_back(count);
//         } // 统计每一行后缀零个数
//         int swapCount = 0;                // 交换次数
//         for (int i = 0; i < n - 1; i++) { // 在倒数第二行终止循环
//             if (suffixLen[i] < n - 1 - i) {
//                 for (int j = i + 1; j < n; j++) {
//                     if (suffixLen[j] >= n - 1 - i) {
//                         for (int k = j; k >= i + 1; k--) {
//                             swap(suffixLen[k], suffixLen[k - 1]);
//                             swapCount++;
//                         } // 层层交换上去
//                         break;
//                     }
//                     if (j == n - 1) {
//                         return -1;
//                     } // 不存在，返回错误
//                 }
//             }
//         }
//         return swapCount;
//     }
// };


class Solution {
public:
    int minSwaps(std::vector<std::vector<int>>& grid) {
        int n = grid.size();
        std::vector<int> trailingZeros(n);

        // 预处理每一行的末尾零个数
        for (int i = 0; i < n; ++i) {
            int count = 0;
            for (int j = n - 1; j >= 0 && grid[i][j] == 0; --j) {
                count++;
            }
            trailingZeros[i] = count;
        }

        int totalSwaps = 0;

        // 贪心放置
        for (int i = 0; i < n; ++i) {
            int required = n - 1 - i;
            int foundIdx = -1;

            // 查找第一个满足要求的行
            for (int j = i; j < n; ++j) {
                if (trailingZeros[j] >= required) {
                    foundIdx = j;
                    break;
                }
            }

            // 如果不存在这样的行，则不可能完成
            if (foundIdx == -1) return -1;

            // 将该行移动到当前位置 'i'
            // 交换次数即为行之间的距离
            totalSwaps += (foundIdx - i);
            
            // 移动元素：从原位置移除并插入到新位置
            int val = trailingZeros[foundIdx];
            trailingZeros.erase(trailingZeros.begin() + foundIdx);
            trailingZeros.insert(trailingZeros.begin() + i, val);
        }

        return totalSwaps;
    }
};


作者：Yiran-yetuser
链接：https://leetcode.cn/problems/minimum-swaps-to-arrange-a-binary-grid/solutions/3912325/zhi-xing-yong-shi-100-by-i3old-rhodesewn-bjrq/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
