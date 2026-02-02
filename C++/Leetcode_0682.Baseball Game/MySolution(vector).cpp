class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> scores;
        for (auto& op : operations) {
            // 检查第一个元素
            switch (op[0]) {
            case '+':
                scores.push_back(scores.at(scores.size() - 2) +
                                 scores.at(scores.size() - 1));
                break;
            case 'D':
                scores.push_back(scores.at(scores.size() - 1) * 2);
                break;
            case 'C':
                scores.pop_back();
                break;
            default:
                scores.push_back(std::stoi(op)); // 将整个string变成十进制数
                break;
            }
        }

        int sum = 0;
        for (int i = 0; i < scores.size(); i++) {
            sum += scores[i];
        }
        return sum;
    }
};
