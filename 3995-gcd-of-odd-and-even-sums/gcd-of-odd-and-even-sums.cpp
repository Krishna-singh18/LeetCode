class Solution {
public:
    int gcd1(int a,int b){
        while(b!=0){
            int t = a%b;
            a=b;
            b=t;
        }
        return a;
    }
    int gcdOfOddEvenSums(int n) {
        int even=n*(n+1);
        int odd=n*n;
       

        return gcd1(even ,odd);
    }
};