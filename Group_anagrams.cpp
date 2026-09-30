#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        map<string, vector<string>> mp;

        for (auto& str : strs) {

            string val = str;

            sort(val.begin(), val.end());

            mp[val].push_back(str);
        }

        vector<vector<string>> ans;

        for (auto& val : mp) {
            ans.push_back(val.second);
        }

        return ans;
    }
};