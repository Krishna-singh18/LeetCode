class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n=nums.size();
        vector<int>freq(n,0);
        for(int i:nums){
            if (i >= n) return false;
            freq[i]++;
        }

        for(int i=1;i<n-1;i++){
            if(freq[i]!=1)return false;
        }

        return freq[n-1]==2;

    }
};