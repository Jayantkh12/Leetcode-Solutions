class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        unordered_map<int, vector<int>> indices;
        for (int i = 0; i < nums.size(); ++i) {
            indices[nums[i]].push_back(i);
        }

        int min_dist = INT_MAX;

        for (const auto& [num, pos] : indices) {
            if (pos.size() >= 3) {

                for (size_t i = 0; i + 2 < pos.size(); ++i) {
                    int dist = 2 * (pos[i + 2] - pos[i]);
                    min_dist = min(min_dist, dist);
                }
            }
        }

        return min_dist == INT_MAX ? -1 : min_dist;
    }
};