class Solution {
public:
    // Function to calculate GCD
    long long gcd(long long a, long long b) {
        while (b != 0) {
            long long temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    // Function to calculate LCM
    long long lcm(long long a, long long b) {
        return (a / gcd(a, b)) * b;  // avoid overflow
    }
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<long long> st; // use long long to avoid overflow
        for (int num : nums) {
            long long x = num;
            // Merge with stack top if non-coprime
            while (!st.empty() && gcd(st.back(), x) > 1) {
                x = lcm(st.back(), x);
                st.pop_back();
            }
            st.push_back(x);
        }

        // Convert back to int
        vector<int> ans;
        for (auto v : st) ans.push_back((int)v);
        return ans;
    }
};
