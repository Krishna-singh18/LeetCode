class Solution {
public:
    void helper(int idx,vector<int>& nums,vector<vector<int>>&ans,vector<int>ds){
        if(idx==nums.size()){
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[idx]);
        helper(idx+1,nums,ans,ds);
        ds.pop_back();
        helper(idx+1,nums,ans,ds);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        helper(0,nums,ans,ds);
        return ans;
    }
};