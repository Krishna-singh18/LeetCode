class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>>ans;
        sort(arr.begin(),arr.end());
        int mini=INT_MAX;
        for(int i=1;i<arr.size();i++){
            int diff=arr[i]-arr[i-1];
            mini=min(mini,diff);
        }

        for(int i=1;i<arr.size();i++){
            if(arr[i]-arr[i-1]==mini){
                ans.push_back({arr[i-1],arr[i]});
            }
        }
        return ans;
    }
};