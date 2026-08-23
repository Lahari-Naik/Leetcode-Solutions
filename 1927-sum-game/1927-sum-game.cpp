class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int sumLeft = 0, sumRight = 0;
        int qLeft = 0, qRight = 0;
        for (int i = 0; i < n / 2; i++) {
            if (num[i] == '?')
                qLeft++;
            else
                sumLeft += num[i] - '0';
        }
        for (int i = n / 2; i < n; i++) {
            if (num[i] == '?')
                qRight++;
            else
                sumRight += num[i] - '0';
        }
        if ((qLeft + qRight) % 2 == 1)
            return true;
        return sumLeft - sumRight != 9 * (qRight - qLeft) / 2;
    }
};