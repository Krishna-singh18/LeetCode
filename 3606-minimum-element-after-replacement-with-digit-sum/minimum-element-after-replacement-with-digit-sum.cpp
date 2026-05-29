class Solution {
public:
    int sum(int k){
        int d=0;
        
        while(k>0){
            d+=k%10;
            k/=10;
        }
        return d;

    }
    int minElement(vector<int>& nums) {
        int mini=INT_MAX;
        for(int i=0;i<nums.size();i++){
            mini=min(mini,sum(nums[i]));
        }
        return mini;
    }
};