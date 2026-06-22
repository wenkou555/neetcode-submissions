class Solution {
public:
    double myPow(double x, int n) {
        long long exp = n;

        if (exp < 0) {
            exp = -exp;
            x = 1.0 / x;
        }

        double result = 1.0;
        while (exp > 0) {
            if (exp % 2 > 0) {
                result *= x;
            }

            x *= x;
            exp /= 2;
        }

        return result;
    }
};
