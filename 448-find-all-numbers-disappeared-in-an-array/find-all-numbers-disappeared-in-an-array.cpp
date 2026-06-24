class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
       vector<int>curr(nums.size()+1,0);
        vector<int>ans;

        for(int i:nums){
           curr[i]++;
        }

        for(int i=1;i<=nums.size();i++){
            if(curr[i]==0) ans.push_back(i);
        }

        return ans;
    }
};