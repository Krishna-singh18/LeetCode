class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> mapst;
        unordered_map<char, char> mapts;

        for (int i = 0; i < s.length(); i++) {
            char sc = s[i], tc = t[i];
            if (mapst.count(sc) && mapst[sc] != tc) return false;
            if (mapts.count(tc) && mapts[tc] != sc) return false;

            mapst[sc] = tc;
            mapts[tc] = sc;
        }
        return true;
    }
};

