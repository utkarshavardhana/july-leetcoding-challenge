class Solution {
public:
    string addBinary(string a, string b) {
        if(a.size() > b.size()) swap(a, b);
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int i=0;
        int carry = 0;
        while(i<a.size()) {
            int t = a[i] + b[i] - 2*'0' + carry;
            if(t == 2) {
                b[i] = '0';
                carry = 1;
            } else if(t == 3) {
                b[i] = '1';
                carry = 1;
            } else {
                b[i] = '0' + t;
                carry = 0;
            }
            i++;
        }
        while(i<b.size()) {
            int t = b[i] - '0' + carry;
            if(t == 2) {
                b[i] = '0';
                carry = 1;
            } else {
                b[i] = '0' + t;
                carry = 0;
            }
            i++;
        }
        reverse(b.begin(), b.end());
        if(carry){
            b.insert(b.begin(), '0' + carry);
        }
        return b;
    }    
};
