class Solution {
public:
    vector<string> generateUsernames(vector<string> arr) {
        unordered_set<string> reserved(arr.begin(), arr.end());
        unordered_set<string> assigned;
        unordered_map<string, int> count;

        vector<string> result;

        for (string name : arr) {
            if (assigned.find(name) == assigned.end()) {
                result.push_back(name);
                assigned.insert(name);
            } else {
                int suffix = count[name] + 1;
                string newName;

                do {
                    newName = name + to_string(suffix);
                    suffix++;
                } while (reserved.find(newName) != reserved.end() ||
                         assigned.find(newName) != assigned.end());

                count[name] = suffix - 1;
                result.push_back(newName);
                assigned.insert(newName);
            }
        }

        return result;
    }
};
