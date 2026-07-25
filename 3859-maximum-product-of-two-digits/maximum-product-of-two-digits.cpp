class Solution {
public:
    int maxProduct(int n) {
        int maxi1 = 0;
        int maxi2 = 0;

        while (n != 0) {
            int k = n % 10;

            if (k >= maxi1) {
                maxi2 = maxi1;
                maxi1 = k;
            } 
            else if (k > maxi2) {
                maxi2 = k;
            }

            n /= 10;
        }

        return maxi1 * maxi2;
    }
};