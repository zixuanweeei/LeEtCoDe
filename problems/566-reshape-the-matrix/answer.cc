#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
        size_t origin_r = nums.size();
        size_t origin_c = nums[0].size();
        if (origin_c * origin_r != r * c) return nums;
        vector<vector<int>> ret(r, vector<int>(c, 0));

        for (size_t orr = 0; orr < r; ++orr) {
            for (size_t oc = 0; oc < c; ++oc) {
                size_t idx = orr * c + oc;
                size_t ir = idx / origin_c;
                size_t ic = idx % origin_c;
                ret[orr][oc] = nums[ir][ic];
            }
        }

        return ret;
    }
};
