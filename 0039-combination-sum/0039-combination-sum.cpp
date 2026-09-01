class Solution {
public:

    void backtrack(vector<int>& candidates,
                   int target,
                   int start,
                   vector<int>& curr,
                   vector<vector<int>>& ans) {

        if(target == 0) {
            ans.push_back(curr);
            return;
        }

        if(target < 0) {
            return;
        }

        for(int i = start; i < candidates.size(); i++) {

            // Choose
            curr.push_back(candidates[i]);

            // Explore
            backtrack(candidates,
                      target - candidates[i],
                      i,
                      curr,
                      ans);

            // Undo
            curr.pop_back();
        }
    }


    vector<vector<int>> combinationSum(vector<int>& candidates,int target) {

        vector<int> curr;
        vector<vector<int>> ans;

        backtrack(candidates, target, 0, curr, ans);

        return ans;
    }
};