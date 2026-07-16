class Solution {
public:
    int gcd(int a, int b){
        while(b!=0){
            int t= a%b;
            a=b;
            b=t;
        }
        return a;
    }

    long long gcdSum(vector<int>& nums) {
        vector<int>pre;
        int maxe=nums[0];

        for(int i=0;i<nums.size();i++){

            maxe=max(maxe,nums[i]);
            pre.push_back(gcd(maxe,nums[i]));
        }

        long long ans=0;
        sort(pre.begin(), pre.end());
        
        int l=0;
        int r=pre.size()-1;
        while(l<r){
            ans+=gcd(pre[l],pre[r]);
            l++;
            r--;
        }

    return ans;
    }
};