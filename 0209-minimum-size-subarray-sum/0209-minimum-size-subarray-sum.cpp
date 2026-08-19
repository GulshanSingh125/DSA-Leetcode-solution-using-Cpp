class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = 0;
        int sum = nums[0];
        int minLen = INT_MAX;
        
        while(left<n && right<n){
            if(sum>=target){
                int tempLen = right-left+1;
                if(minLen>tempLen){
                    minLen = tempLen;
                }
                sum = sum - nums[left];
                left++;
            } else {
                right++;
                if(right<n){
                sum = sum + nums[right];
                }
            }
        }
        if(minLen == INT_MAX){
            return 0;
        }
        return minLen;
    }
};