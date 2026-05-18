class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n <= 1) return 0;

        unordered_map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }

        queue<int> q;
        vector<bool> vis(n, false);

        q.push(0);
        vis[0] = true;

        int steps = 0;

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                int curindex = q.front();
                q.pop();

                if (curindex == n - 1) return steps;

                // curstep +1 ke liye
                if (curindex + 1 < n && !vis[curindex + 1]) {
                    vis[curindex + 1] = true;
                    q.push(curindex + 1);
                }

                // curstep- 1
                if (curindex - 1 >= 0 && !vis[curindex - 1]) {
                    vis[curindex - 1] = true;
                    q.push(curindex - 1);
                }

                // same value jumps
                for (int j : mp[arr[curindex]]) {
                    if (!vis[j]) {
                        vis[j] = true;
                        q.push(j);
                    }
                }

              
                mp[arr[curindex]].clear();
            }
            steps++;
        }

        return -1;
    }
};