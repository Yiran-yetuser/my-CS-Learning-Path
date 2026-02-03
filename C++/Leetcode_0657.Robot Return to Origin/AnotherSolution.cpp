class Solution {
public:
    bool judgeCircle(string moves) {
        unordered_map <char,int> mp;
        for (auto &i:moves){
            mp[i]++;
        }
        if ((mp['L'] == mp['R']) && (mp['U'] == mp['D'])){
            return true;
        }else{
            return false;
        }
    }
};
