class Solution {
public:
    int uniquePaths(int m, int n) {
        long long nn = m+n-2;
        long long rr = m-1;

        long long res = 1;

        for(int i=1;i<=rr;i++){
            res = res * (nn - rr + i) / i;
        }

        return res;
    }
};
