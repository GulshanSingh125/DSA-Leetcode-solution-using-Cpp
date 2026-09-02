class Solution {
public:
    void backTrack(vector<int> &candidates, int target, int start,vector<int> &current, vector<vector<int>> &ans){
        if(target == 0){
            ans.push_back(current);
            return;
        }
        if(target<0){
            return;
        }

        for(int i=start;i<candidates.size();i++){
            current.push_back(candidates[i]);
            backTrack(candidates,target-candidates[i],i,current,ans);
            current.pop_back();
        }

    }


    vector<vector<int>> combinationSum(vector<int>& candidates,int target) {
        vector<int> current;
        vector<vector<int>> ans;
        backTrack(candidates,target,0,current,ans);
        return ans;
    }
};