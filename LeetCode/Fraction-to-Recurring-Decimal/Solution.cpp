class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        
        string result;
        
        // Handle sign
        if ((numerator < 0) ^ (denominator < 0)) result += "-";
        
        // Convert to long long to avoid overflow
        long long n = llabs((long long)numerator);
        long long d = llabs((long long)denominator);
        
        // Append integer part
        result += to_string(n / d);
        long long rem = n % d;
        if (rem == 0) return result; // No fractional part
        
        result += ".";
        
        // Map to store remainder and its position in result string
        unordered_map<long long, int> seen;
        
        while (rem != 0) {
            if (seen.count(rem)) {
                // Repeating remainder found
                result.insert(seen[rem], "(");
                result += ")";
                break;
            }
            
            seen[rem] = result.size();
            rem *= 10;
            result += to_string(rem / d);
            rem %= d;
        }
        
        return result;
    }
};