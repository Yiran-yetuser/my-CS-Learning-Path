class Solution {
public:
    int bitwiseComplement(int n) {
        int sum = 1;
        int nOri = n;
        while(n>1) {
            sum<<=1;
            sum+=1;
            n/=2;
        }
        return sum-nOri;
    }
};
