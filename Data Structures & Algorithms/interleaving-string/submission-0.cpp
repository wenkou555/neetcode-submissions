class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size();
        if (n1 == 0)
            return s2 == s3;

        int n2 = s2.size();
        if (n2 == 0)
            return s1 == s3;

        if (n1 + n2 != s3.size())
            return false;

        vector<vector<bool>> mapping(n1 + 1, vector<bool>(n2 + 1, false));

        mapping[0][0] = true;

        for (int i = 0; i <= n1; i++ ) {
            for (int j = 0; j <= n2; j++ ) {
                if (mapping[i][j] == true)
                    continue;

                if (j > 0 && mapping[i][j - 1] && s3[i+j-1] == s2[j - 1])
                    mapping[i][j] = true;
                
                if (i > 0 && mapping[i - 1][j] && s3[i+j-1] == s1[i - 1])
                    mapping[i][j] = true;
            }
        }

        return mapping[n1][n2];

    }
};
