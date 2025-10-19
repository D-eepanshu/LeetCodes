class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        unordered_set<string> visited;
        queue<string> q;
        string result = s;

        q.push(s);
        visited.insert(s);

        while (!q.empty()) {
            string curr = q.front();
            q.pop();
            result = min(result, curr);

            // Operation 1: Add a to odd indices
            string added = curr;
            for (int i = 1; i < added.size(); i += 2) {
                added[i] = (added[i] - '0' + a) % 10 + '0';
            }

            if (visited.find(added) == visited.end()) {
                visited.insert(added);
                q.push(added);
            }

            // Operation 2: Rotate right by b positions
            string rotated = curr.substr(curr.size() - b) + curr.substr(0, curr.size() - b);

            if (visited.find(rotated) == visited.end()) {
                visited.insert(rotated);
                q.push(rotated);
            }
        }

        return result;
    }
};
