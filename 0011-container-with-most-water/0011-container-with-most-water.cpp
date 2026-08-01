class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = height.size() - 1;
        int maxW = 0;
        while(left < right){
            int x = right - left;
            int y = min(height[left],height[right]);
            maxW = max(x*y,maxW) ;
            if(height[left] > height[right]) right --;
            else left++;
        }
        return maxW;
    }
};