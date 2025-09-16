class Solution {
public:
    int lcm(int a, int b) {
        return (1LL * a / __gcd(a, b)) * b;
    }

    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> v;

        for (int x : nums) {
            v.push_back(x);

            while (v.size() > 1) {
                int gc = __gcd(v[v.size()-1], v[v.size()-2]);
                if (gc > 1) {
                    int lc = lcm(v[v.size()-1], v[v.size()-2]);
                    v.pop_back();
                    v.pop_back();
                    v.push_back(lc);
                } else {
                    break;
                }
            }
        }
        return v;
    }
};