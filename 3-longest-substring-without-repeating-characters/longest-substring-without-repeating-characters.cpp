class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_set<char>st;
        int i=0;
        int ans=0;
        for(int j=0;j<n;j++){

            while(st.find(s[j]) !=st.end()){
                st.erase(s[i]);
                i++;
            }

            st.insert(s[j]);
            ans=max(ans,j-i+1);

        }
        return ans;
    }
};