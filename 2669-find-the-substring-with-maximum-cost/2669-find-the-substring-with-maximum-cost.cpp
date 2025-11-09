class Solution {
public:

int maximumCostSubstring(string s, string chars, vector<int>& vals) {
    vector<int> value(26);
    for (int i = 0; i < 26; i++) value[i] = i + 1;
    for (int i = 0; i < chars.size(); i++) {
        value[chars[i] - 'a'] = vals[i];
    }
    int max_sum = 0;
    int current_sum = 0;

    for (char c : s) {
        current_sum += value[c - 'a'];
        if (current_sum < 0) current_sum = 0;
        max_sum = max(max_sum, current_sum);
    }

    return max_sum;
}

};