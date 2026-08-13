class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> mp(n+1);
        for(int i=0;i<n;i++){
            auto it = mp.find(nums[i]);
            if(it != mp.end()){
                return true;
            }
            mp[nums[i]] = i;
        }
        return false;
    }
};