class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cur=0;
        int maxone=0;
        for(int i:nums){
            if(i==1){
            cur++;
            maxone=max(maxone,cur);
            }
            else{
                cur=0;
            }

        }
        return maxone;
    }
};