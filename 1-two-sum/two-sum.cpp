class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){

            int di=target-nums[i];

            if(mp.count(di)){
                return {mp[di], i};
            }
            mp[nums[i]]=i;

        }
        return {};
    }
};