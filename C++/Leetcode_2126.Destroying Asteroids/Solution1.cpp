class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        long long m = mass;
        int n = asteroids.size();
        for (int x : asteroids) {
            if (m < x) { // 无法摧毁小行星 x
                return false;
            }
            m += x; // 获得这颗小行星的质量
            if(m>=asteroids[n-1]) {
                return true;
            }
        }
        return true;
    }
};
