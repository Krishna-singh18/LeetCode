class SegmentTree {
public:
    int n;
    vector<int> tree;

    SegmentTree(int n) : n(n) {
        tree.assign(4 * n + 5, 0);
    }

    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            tree[node] = val;
            return;
        }

        int mid = (l + r) >> 1;

        if (idx <= mid)
            update(node * 2, l, mid, idx, val);
        else
            update(node * 2 + 1, mid + 1, r, idx, val);

        tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
    }

    int query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) return 0;

        if (ql <= l && r <= qr) return tree[node];

        int mid = (l + r) >> 1;

        return max(
            query(node * 2, l, mid, ql, qr),
            query(node * 2 + 1, mid + 1, r, ql, qr)
        );
    }
};

class Solution {
public:
    vector<bool> getResults(vector<vector<int>>& queries) {

        const int MAXX = 50000;

        set<int> obstacles;
        obstacles.insert(0);

        // Insert all obstacles first
        for (auto &q : queries) {
            if (q[0] == 1)
                obstacles.insert(q[1]);
        }

        SegmentTree seg(MAXX);

        auto setGap = [&](int pos, int gap) {
            seg.update(1, 0, MAXX, pos, gap);
        };

        // Build initial gaps
        int previous = 0;

        for (auto it = next(obstacles.begin());
             it != obstacles.end();
             ++it) {

            setGap(*it, *it - previous);
            previous = *it;
        }

        vector<bool> ans;

        reverse(queries.begin(), queries.end());

        for (auto &q : queries) {

            if (q[0] == 2) {

                int x = q[1];
                int sz = q[2];

                auto it = obstacles.upper_bound(x);

                int lastObstacle =
                    (it == obstacles.begin())
                    ? 0
                    : *std::prev(it);

                int bestGap =
                    seg.query(1, 0, MAXX, 0, x);

                bool canPlace =
                    max(bestGap, x - lastObstacle) >= sz;

                ans.push_back(canPlace);
            }
            else {

                int x = q[1];

                auto it = obstacles.find(x);

                auto prv = std::prev(it);
                auto nxt = std::next(it);

                if (nxt != obstacles.end()) {
                    setGap(*nxt, *nxt - *prv);
                }

                obstacles.erase(it);
            }
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};