class Solution {
public:
    string multiply(string num1, string num2) {
        
        if (num1 == "0" || num2 == "0")
            return "0";

        int m = num1.size();
        int n = num2.size();

        vector<int> product(m + n, 0);

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                int digit1 = num1[i] - '0';
                int digit2 = num2[j] - '0';

                int res = (digit1 * digit2) + product[i + j + 1];

                product[i + j + 1] = res % 10;

                product[i + j] += res/10;
            }
        }

        string stringRes = "";
        for(int num: product) {
            if (stringRes.empty() && num == 0)
                continue;

            stringRes.push_back(num + '0');
        }

        return stringRes;
    }
};
