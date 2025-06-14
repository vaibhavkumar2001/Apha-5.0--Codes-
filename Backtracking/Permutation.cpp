#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void generatePermutations(string &s, int index, vector<string> &result) {
    if (index >= s.length()) {
        result.push_back(s);
        return;
    }

    for (int i = index; i < s.length(); i++) {
        swap(s[index], s[i]);                    // Swap current index with i
        generatePermutations(s, index + 1, result); // Recurse for next index
        swap(s[index], s[i]);                    // Backtrack
    }
}

int main() {
    string input = "ABC";
    vector<string> result;

    generatePermutations(input, 0, result);

    cout << "All permutations:\n";
    for (string perm : result) {
        cout << perm << endl;
    }

    return 0;
}
