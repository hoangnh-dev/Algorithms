class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0;
        int right = 0;
        int sum = 0;
        int minLen = 0;
        while(right < nums.size()|| sum >= target){
            if(sum < target){
                sum += nums[right];
                right++;
            }else{
                if(minLen == 0 || minLen > (right - left)) minLen = right - left;
                sum -= nums[left];
                left++;
            }
        }
        return minLen;
    }
};