class Solution {
public:
    double average(vector<int>& salary) {
        int sum = 0, max = 0, min = salary[0];
        for(int &s : salary) {
            sum += s;
            max = max>s?max:s;
            min = min<s?min:s;
        }
        return (sum*1.0 - max - min)/(salary.size() - 2);
    } 
};
