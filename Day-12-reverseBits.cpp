class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        string str;
        int c = 32;
        while(c--) {
            str += (n % 2) + '0';
            n /= 2;
        }
        uint32_t res = 0;
        for(char c : str) {
            res *= 2;
            res += c-'0';
        }
        return res;
    }
};
