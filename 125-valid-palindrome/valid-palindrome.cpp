class Solution {
public:
    bool isPalindrome(string s) {
        string k;
        for(char i:s){
           if(isalnum(i)){
            k+=tolower(i);
           }
        }

        int l=0;
        int r=k.size()-1;

        while(l<r){
            if(k[l]!=k[r])return false;
            l++;
            r--;

        }
        return true;
    }
};