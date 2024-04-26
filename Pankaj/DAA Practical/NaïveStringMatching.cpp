#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> naiveStringMatching(const string& text, const string& pattern) {
    vector<int> matches;

    int n = text.length();
    int m = pattern.length();

    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if (text[i + j] != pattern[j])
                break;
        }
        if (j == m) {
            matches.push_back(i);
        }
    }

    return matches;
}

int main() {
    string text, pattern;

    cout << "Enter the text: ";
    getline(cin, text);

    cout << "Enter the pattern to search: ";
    getline(cin, pattern);

    // Find matches using naive string matching algorithm
    vector<int> matches = naiveStringMatching(text, pattern);

    // Print the positions where pattern is found in the text
    if (matches.empty()) {
        cout << "Pattern not found in the text." << endl;
    } else {
        cout << "Pattern found at positions: ";
        for (int i = 0; i < matches.size(); i++) {
            cout << matches[i];
            if (i != matches.size() - 1) {
                cout << ", ";
            }
        }
        cout << endl;
    }

    return 0;
}


/*
Worst-case: O((n - m + 1) * m)
Average-case: O((n - m + 1) * m)
Best-case: O(n)
*/