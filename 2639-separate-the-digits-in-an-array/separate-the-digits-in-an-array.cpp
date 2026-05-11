class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int>ans;

        for(int i:nums){
            
            string k=to_string(i);

            for(char c:k){
                ans.push_back(c-'0');
            }
        }
        return ans;
    }
};