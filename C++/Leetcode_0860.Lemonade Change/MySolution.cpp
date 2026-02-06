class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int countFive = 0, countTen = 0;
        for (auto& bill : bills) {
            switch (bill) {
            case 5:
                countFive++;
                break;
            case 10:
                countFive--;
                countTen++;
                break;
            case 20:
                if (countTen > 0) {
                    countTen--;
                    countFive--;
                } else {
                    countFive -= 3;
                }
                break;
            }
            if (countFive < 0) {
                return false;
            }
        }
        return true;
    }
};
