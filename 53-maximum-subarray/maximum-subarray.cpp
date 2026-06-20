class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int cursum=0;
        int maxsum=nums[0];
        for(int i:nums){
            cursum+=i;
            maxsum=max(maxsum,cursum);
            if(cursum<0)cursum=0;

        }
        return maxsum;

    }
};