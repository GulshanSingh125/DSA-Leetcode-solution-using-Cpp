class Solution {
public:

    struct Node {
        int prod;
        int cnt[5];

        Node() {
            prod = 1;

            for(int i = 0; i < 5; i++) {
                cnt[i] = 0;
            }
        }
    };

    int k;
    vector<Node> tree;

    Node merge(Node left, Node right) {

        Node parent;

        // Product of complete segment
        parent.prod = (left.prod * right.prod) % k;

        // Prefixes completely inside left
        for(int r = 0; r < k; r++) {
            parent.cnt[r] = left.cnt[r];
        }

        // Prefixes which cross from left into right
        for(int r = 0; r < k; r++) {

            int newRem = (left.prod * r) % k;

            parent.cnt[newRem] += right.cnt[r];
        }

        return parent;
    }


    void build(vector<int>& nums, int node, int l, int r) {

        if(l == r) {

            int val = nums[l] % k;

            tree[node].prod = val;

            // Only one non-empty prefix
            tree[node].cnt[val] = 1;

            return;
        }

        int mid = (l + r) / 2;

        build(nums, node * 2, l, mid);

        build(nums, node * 2 + 1, mid + 1, r);

        tree[node] = merge(tree[node * 2],
                           tree[node * 2 + 1]);
    }


    void update(int node, int l, int r,
                int index, int value) {

        if(l == r) {

            value %= k;

            tree[node].prod = value;

            for(int i = 0; i < k; i++) {
                tree[node].cnt[i] = 0;
            }

            tree[node].cnt[value] = 1;

            return;
        }

        int mid = (l + r) / 2;

        if(index <= mid) {

            update(node * 2,
                   l,
                   mid,
                   index,
                   value);

        } else {

            update(node * 2 + 1,
                   mid + 1,
                   r,
                   index,
                   value);
        }

        tree[node] = merge(tree[node * 2],
                           tree[node * 2 + 1]);
    }


    Node query(int node, int l, int r,
               int ql, int qr) {

        // Completely inside query range
        if(ql <= l && r <= qr) {
            return tree[node];
        }

        int mid = (l + r) / 2;

        // Completely in left
        if(qr <= mid) {
            return query(node * 2,
                         l,
                         mid,
                         ql,
                         qr);
        }

        // Completely in right
        if(ql > mid) {
            return query(node * 2 + 1,
                         mid + 1,
                         r,
                         ql,
                         qr);
        }

        // Query overlaps both
        Node left = query(node * 2,
                          l,
                          mid,
                          ql,
                          qr);

        Node right = query(node * 2 + 1,
                           mid + 1,
                           r,
                           ql,
                           qr);

        return merge(left, right);
    }


    vector<int> resultArray(vector<int>& nums,
                            int K,
                            vector<vector<int>>& queries) {

        k = K;

        int n = nums.size();

        tree.resize(4 * n);

        // Build segment tree
        build(nums, 1, 0, n - 1);

        vector<int> ans;

        for(auto &q : queries) {

            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // 1. Permanent update
            update(1,
                   0,
                   n - 1,
                   index,
                   value);

            // 2. Query [start ... n-1]
            Node res = query(1,
                             0,
                             n - 1,
                             start,
                             n - 1);

            // 3. Number of prefixes having remainder x
            ans.push_back(res.cnt[x]);
        }

        return ans;
    }
};