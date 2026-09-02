class Solution {
public:

    bool isPalindrome(string s){
        string s2 = s;
        reverse(s2.begin(),s2.end());
        return s == s2;
    }

    void backtrack(string s, vector<string> &current, vector<vector<string>> &ans){
        if(s.size() == 0){
            ans.push_back(current);
            return;
        }
        for(int i=0;i<s.size();i++){
            string part = s.substr(0,i+1);
            if(isPalindrome(part)){
               current.push_back(part);
               backtrack(s.substr(i+1),current,ans);
               current.pop_back();
            }
        }

    }
    vector<vector<string>> partition(string s) {
        vector<string> current;
        vector<vector<string>> ans;

        backtrack(s,current,ans);
        return ans;
    }
};