class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int longest = 0;
        int subString[256] = {0};
        for (int right = 0; right < s.length(); right++) {
            int c = s[right]; 
            if(subString[c] > left){
                left = subString[c];
            }
            subString[c] = right+1;
            longest = max(longest, right - left + 1);
        }
        return longest;
    }
};