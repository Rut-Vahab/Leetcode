class Solution {
public:
    const int MOD = 1e9 + 7;
    vector<int> primes = {2,3,5,7,11,13,17,19,23,29};

    int getMask(int x) {
        if (x == 1) return 0;
        int mask = 0;
        for (int i = 0; i < primes.size(); i++) {
            int p = primes[i], count = 0;
            while (x % p == 0) {
                x /= p;
                count++;
            }
            if (count > 1) return -1; 
            if (count == 1) mask |= (1 << i);
        }
        if (x > 1) return -1;
        return mask;
    }

    int squareFreeSubsets(vector<int>& nums) {
        int count1 = 0;
        vector<int> masks;
        for (int x : nums) {
            if (x == 1) { count1++; continue; }
            int m = getMask(x);
            if (m != -1) masks.push_back(m);
        }

        vector<long long> dp(1 << primes.size(), 0);
        dp[0] = 1;

        for (int m : masks) {
            for (int mask = (1 << primes.size()) - 1; mask >= 0; mask--) {
                if ((mask & m) == 0) {
                    dp[mask | m] = (dp[mask | m] + dp[mask]) % MOD;
                }
            }
        }

        long long result = 0;
        for (int mask = 1; mask < (1 << primes.size()); mask++) {
            result = (result + dp[mask]) % MOD;
        }

        long long pow1 = 1;
        for (int i = 0; i < count1; i++) pow1 = (pow1 * 2) % MOD;

        result = (result * pow1) % MOD;
        if (count1 > 0) result = (result + pow1 - 1) % MOD;

        return (int)result;
    }
};
