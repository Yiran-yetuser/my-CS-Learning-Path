class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        vector<uint8_t> visited(n); // 仅1byte
        queue<int> q;
        q.push(start);
        visited[start] = 1;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            if (arr[cur] == 0) {
                return true;
            }
            int next_pos1 = cur + arr[cur];
            int next_pos2 = cur - arr[cur];
            if(next_pos1>=0&&next_pos1<n&&visited[next_pos1] == 0) {
                q.push(next_pos1);
                visited[next_pos1] = 1;
            }
            if(next_pos2>=0&&next_pos2<n&&visited[next_pos2] == 0) {
                q.push(next_pos2);
                visited[next_pos2] = 1;
            }
        }
        return false;
    }
};
