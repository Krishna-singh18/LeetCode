class Solution {
public:
    long long sumAndMultiply(int n) {
        string s= to_string(n);
        long long sum=0;
        int newn=0;

        for(char c:s){
            if(c-'0'!=0){
                newn=newn*10+c-'0';
                sum+=c-'0';
            }
        }
        return newn*sum;
    }
};