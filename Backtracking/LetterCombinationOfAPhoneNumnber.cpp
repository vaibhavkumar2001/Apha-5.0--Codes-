#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    void Solve(string& output, string digits, vector<string>& ans, unordered_map<char, string>& mapping, int i) {
        // Base case
        if (i >= digits.length()) {
            if (output.length() > 0) {
                ans.push_back(output);
            }
            return;
        }

        // Fetch current digit
        char digit = digits[i];

        // Get corresponding characters from mapping
        string mappedString = mapping[digit];

        // Try all characters
        for (char ch : mappedString) {
            output.push_back(ch);

            // Recursion handles the rest
            Solve(output, digits, ans, mapping, i + 1);

            // Backtrack
            output.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.empty()) return ans;

        unordered_map<char, string> mapping;
        mapping['2'] = "abc";
        mapping['3'] = "def";
        mapping['4'] = "ghi";
        mapping['5'] = "jkl";
        mapping['6'] = "mno";
        mapping['7'] = "pqrs";
        mapping['8'] = "tuv";
        mapping['9'] = "wxyz";

        int i = 0;
        string output = "";
        Solve(output, digits, ans, mapping, i);
        return ans;
    }
};
int main() {
    Solution sol;
    string input = "23";
    vector<string> result = sol.letterCombinations(input);

    cout << "Letter combinations of \"" << input << "\":" << endl;
    for (const string& s : result) {
        cout << s << " ";
    }
    cout << endl;
    return 0;
}
