class Solution {
public:
    int calPoints(vector<string>& operations) {  
        stack<int> num;
        int n = operations.size();
        int sum = 0;
        for(auto &ch : operations)
        {
            int temp = 0;
            switch(ch[0])
            {
                case '+':
                {
                    int top_num = num.top();
                    num.pop();
                    temp = num.top() + top_num;
                    num.push(top_num);
                    num.push(temp);
                    break;
                }
                case 'D':
                {
                    temp = num.top() * 2;
                    num.push(temp);
                    break;
                }
                case 'C':
                {
                    num.pop();
                    break;
                }
                default:
                {
                    temp = atoi(ch.c_str());
                    num.push(temp);
                    break;
                }

            } 
        }
        while(!num.empty())
        {
            sum += num.top();
            num.pop();
        }
        return sum;

    }
};

作者：毛毛虫
链接：https://leetcode.cn/problems/baseball-game/solutions/3866312/bang-qiu-bi-sai-by-ghuixin-5ay1/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
