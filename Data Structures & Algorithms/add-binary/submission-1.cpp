class Solution {
public:
    string addBinary(string a, string b) {
        int n = max(a.length(), b.length());
        string ans = "";
        bool carry = false;

        while (a.length() < n || b.length() < n) {
            if (a.length() < n) a = '0' + a;
            if (b.length() < n) b = '0' + b;
        }

        for (int i = n-1; i>=0; i--) {
            char bit = '0';
            int abit = a[i] - '0';
            int bbit = b[i] - '0';
            
            bit += (abit ^ bbit ^ carry);
            carry = (abit + bbit + carry) > 1;

            ans = bit + ans;
        }
        if (carry) ans = '1' + ans;
        
        return ans;
    }
};