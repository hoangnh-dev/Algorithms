class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int size = nums.size();
        int bitmapSize = (size + 31) / 32;
        int sum = size * (size + 1) / 2;
        int duplicate = 0;
        vector<uint32_t> bitmap(bitmapSize, 0);
        for (int x : nums) {
            int index = (x - 1) / 32;
            int bitPos = (x - 1) % 32;
            if ((bitmap[index] & (1U << bitPos)) != 0) {
                duplicate = x;
            } else {
                bitmap[index] |= (1U << bitPos);
                sum = sum - x;
            }
        }
        return {duplicate,sum};
    }
};