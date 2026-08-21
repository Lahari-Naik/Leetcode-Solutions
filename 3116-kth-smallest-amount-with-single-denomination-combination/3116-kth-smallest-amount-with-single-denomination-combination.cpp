class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        auto count = [&](long long x) {
            long long ans = 0;
            for (int mask = 1; mask < (1 << n); mask++) {
                long long l = 1;
                int bits = 0;
                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i)) {
                        bits++;

                        long long g = gcd(l, (long long)coins[i]);
                        l = l / g * coins[i];

                        if (l > x)
                            break;
                    }
                }
                if (l > x)
                    continue;
                if (bits % 2 == 1)
                    ans += x / l;
                else
                    ans -= x / l;
            }
            return ans;
        };
        long long left = 1;
        long long right = 1LL * k * (*min_element(coins.begin(), coins.end()));
        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (count(mid) >= k)
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};