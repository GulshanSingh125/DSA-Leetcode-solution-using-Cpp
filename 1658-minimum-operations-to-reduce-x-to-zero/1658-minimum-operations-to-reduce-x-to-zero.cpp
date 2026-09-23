class Solution {
public:
    int minOperations(vector<int>& nums, int x) {

        int total = 0;

        for(int num : nums)
            total += num;

        int target = total - x;

        if(target < 0)
            return -1;

        int left = 0;
        int sum = 0;
        int maxLen = 0;

        for(int right = 0; right < nums.size(); right++) {

            sum += nums[right];

            while(sum > target) {
                sum -= nums[left];
                left++;
            }

            if(sum == target) {
                maxLen = max(maxLen, right - left + 1);
            }
        }

        // No valid subarray
        if(maxLen == 0 && target != 0)
            return -1;

        return nums.size() - maxLen;
    }
};