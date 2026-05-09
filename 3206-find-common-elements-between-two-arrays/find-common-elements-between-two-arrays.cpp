class Solution {
public:
    vector<int> findIntersectionValues(vector<int>& nums1, vector<int>& nums2) {
        int n1=nums1.size();
        int n2=nums2.size();
        unordered_set<int>st1;
        unordered_set<int>st2;
        for(int i:nums1){
            st1.insert(i);
        }
        for(int i:nums2){
            st2.insert(i);
        }
        
        int c1=0,c2=0;

        for(int i=0;i<n1;i++){

            if(st2.count(nums1[i])){
                c1++;
            }
        }
        for(int i=0;i<n2;i++){

            if(st1.count(nums2[i])){
                c2++;
            }
        }
        return {c1,c2};
    }
};