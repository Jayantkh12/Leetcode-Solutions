class Solution {
public:
    struct Node {
        array<int, 5> cnt{};
        int prod = 1;
    };

    class SegmentTree {
    public:
        int n;
        int k;

        vector<Node> tree;

        SegmentTree(vector<int>& nums, int K) {

            n = nums.size();
            k = K;

            tree.resize(4 * n);

            build(1, 0, n - 1, nums);
        }
        Node mergeNodes(const Node& left, const Node& right) {

            Node result;

            result.prod = (left.prod * right.prod) % k;

            result.cnt = left.cnt;
            for (int r = 0; r < k; r++) {
                int newRemainder = (left.prod * r) % k;
                result.cnt[newRemainder] += right.cnt[r];
            }
            return result;
        }

        void build(int node, int left, int right, vector<int>& nums) {
            if (left == right) {
                int value = nums[left] % k;
                tree[node].prod = value;
                tree[node].cnt.fill(0);
                tree[node].cnt[value] = 1;
                return;
            }

            int mid = left + (right - left) / 2;

            build(node * 2, left, mid, nums);

            build(node * 2 + 1, mid + 1, right, nums);

            tree[node] = mergeNodes(tree[node * 2], tree[node * 2 + 1]);
        }

        void update(int node, int left, int right, int index, int value) {

            if (left == right) {

                value %= k;

                tree[node].prod = value;

                tree[node].cnt.fill(0);
                tree[node].cnt[value] = 1;

                return;
            }

            int mid = left + (right - left) / 2;

            if (index <= mid) {

                update(node * 2, left, mid, index, value);
            } else {

                update(node * 2 + 1, mid + 1, right, index, value);
            }

            tree[node] = mergeNodes(tree[node * 2], tree[node * 2 + 1]);
        }

        Node query(int node, int left, int right, int ql, int qr) {

            if (ql <= left && right <= qr) {
                return tree[node];
            }

            int mid = left + (right - left) / 2;

            if (qr <= mid) {

                return query(node * 2, left, mid, ql, qr);
            }

            if (ql > mid) {

                return query(node * 2 + 1, mid + 1, right, ql, qr);
            }

            Node leftResult = query(node * 2, left, mid, ql, qr);

            Node rightResult = query(node * 2 + 1, mid + 1, right, ql, qr);

            return mergeNodes(leftResult, rightResult);
        }

        void update(int index, int value) { update(1, 0, n - 1, index, value); }

        Node query(int left, int right) {

            return query(1, 0, n - 1, left, right);
        }
    };

    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {

        int n = nums.size();
        SegmentTree tree(nums, k);

        auto veltrunigo = nums;

        vector<int> answer;

        for (auto& q : queries) {

            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];
            tree.update(index, value);
            Node result = tree.query(start, n - 1);

            answer.push_back(result.cnt[x]);
        }

        return answer;
    }
};