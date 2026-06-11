class Solution {
public:
    string multiply(string num1, string num2) {
        // 處理乘數為 0 的特例
        if (num1 == "0" || num2 == "0") return "0";

        int n = num1.length();
        int m = num2.length();
        vector<int> ans(n + m, 0);

        // 修正 1：索引從 n-1 和 m-1 開始，走到 0
        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int prod = (num1[i] - '0') * (num2[j] - '0');
                
                // 修正 2：計算總和 (包含該位置原本累積的數字)
                // 這裡的小技巧：i+j+1 是放個位數的位置，i+j 是放十位數(進位)的位置
                int sum = prod + ans[i + j + 1];
                
                ans[i + j + 1] = sum % 10; // 留下個位數
                ans[i + j] += sum / 10;    // 將進位往前加
            }
        }

        string res = "";
        for (int i = 0; i < n + m; i++) {
            // 修正 4：只跳過最前面的零
            // 意思是：如果 res 還是空的，且當前數字是 0，就跳過不要加
            if (res.empty() && ans[i] == 0) {
                continue;
            }
            
            // 修正 3：整數轉字元
            res += (ans[i] + '0');
        }
        
        return res;
    }
};