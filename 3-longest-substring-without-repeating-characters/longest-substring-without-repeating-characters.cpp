class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int i=0;
        unordered_set<char>st;
        int ans =0;

        for(int j=0;j<n;j++){

            while(st.find(s[j])!=st.end()){
                st.erase(s[i]);
                i++;
            }

            st.insert(s[j]);
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};