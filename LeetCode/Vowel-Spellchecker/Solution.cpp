class Solution {
public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact(wordlist.begin(), wordlist.end());
        unordered_map<string, string> caseInsensitive;
        unordered_map<string, string> vowelInsensitive;
        
        // helper: lowercasing
        auto toLower = [](string s) {
            for (char &c : s) c = tolower(c);
            return s;
        };
        
        // helper: replace vowels with '*'
        auto devowel = [&](string s) {
            for (char &c : s) {
                char low = tolower(c);
                if (low=='a' || low=='e' || low=='i' || low=='o' || low=='u')
                    c = '*';
                else
                    c = low;
            }
            return s;
        };
        
        // build mappings
        for (string &w : wordlist) {
            string lower = toLower(w);
            string vword = devowel(w);
            
            if (caseInsensitive.find(lower) == caseInsensitive.end())
                caseInsensitive[lower] = w;
            
            if (vowelInsensitive.find(vword) == vowelInsensitive.end())
                vowelInsensitive[vword] = w;
        }
        
        vector<string> ans;
        for (string &q : queries) {
            if (exact.count(q)) {
                ans.push_back(q);
                continue;
            }
            
            string lower = toLower(q);
            if (caseInsensitive.count(lower)) {
                ans.push_back(caseInsensitive[lower]);
                continue;
            }
            
            string vword = devowel(q);
            if (vowelInsensitive.count(vword)) {
                ans.push_back(vowelInsensitive[vword]);
                continue;
            }
            
            ans.push_back("");
        }
        return ans;
    }
};