class Solution {
public:
    int arrangeCoins(int n) {
        return (sqrt(1 + (long long)(8*n)) - 1) / 2;
    }
};
