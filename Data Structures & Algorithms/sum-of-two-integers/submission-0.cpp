class Solution {
public:
    int getSum(int a, int b) {

        while (b != 0) {
            unsigned int carry = a&b;
            unsigned int shiftedCarry = carry << 1;

            a = a^b;
            b = shiftedCarry;
        }
        return a;
    }
};
