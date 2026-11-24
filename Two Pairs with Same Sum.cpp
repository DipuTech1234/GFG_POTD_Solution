
class Solution {
public:
    vector<int> findPairs(vector<int>& arr) {
        int n = arr.size();

        unordered_map<long long, vector<pair<int, int>>> mp;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                long long sum = (long long)arr[i] + arr[j];
                mp[sum].push_back({i, j});
            }
        }

        vector<int> ans = {-1, -1, -1, -1};

        for (auto &entry : mp) {
            auto &v = entry.second;

            for (int i = 0; i < (int)v.size(); i++) {
                for (int j = i + 1; j < (int)v.size(); j++) {
                    int a = v[i].first;
                    int b = v[i].second;
                    int c = v[j].first;
                    int d = v[j].second;

                    if (a != c && a != d &&
                        b != c && b != d) {

                        vector<int> temp = {a, b, c, d};

                        if (ans[0] == -1 || temp < ans) {
                            ans = temp;
                        }

                        break;
                    }
                }

                if (ans[0] != -1 && 
                    ans[0] == v[i].first &&
                    ans[1] == v[i].second) {
                    break;
                }
            }
        }

        return ans;
    }
};
