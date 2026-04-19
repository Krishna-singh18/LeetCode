class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        //using unordered set
        unordered_set<int>st;
        for(int i=0;i<nums.size();i++){
            
            if(st.find(nums[i])!=st.end()){
                return true;
            }
            st.insert(nums[i]);
        }
        return false;
    }
};