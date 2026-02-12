int longestBalanced(string s) {
    int n = s.size(), res = 0;
    for (int i = 0; i < n && n - i > res; i++) {
        int freq[26] = {0};
        int dist = 0, maxF = 0, len = 1;

        for (int j = i; j < n; j++, len++) {
            int idx = s[j] - 'a';
            dist += freq[idx] == 0;
            maxF = max(maxF, ++freq[idx]);

            if (len == dist * maxF)
                res = max(res, len);
        }
    }
    return res;
}
