#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_CHAR = 256;

void computeBadCharHeuristic(const string &pattern, vector<int> &badChar) {
    int m = pattern.length();

    fill(badChar.begin(), badChar.end(), -1);

    for (int i = 0; i < m; i++)
        badChar[(int)pattern[i]] = i;
}

void computeGoodSuffixHeuristic(const string &pattern, vector<int> &goodSuffix) {
    int m = pattern.length();
    int i, j;

    vector<int> longestPrefix(m + 1);

    
    for (i = 0; i <= m; i++)
        longestPrefix[i] = 0;

    
    i = m;
    j = m + 1;
    longestPrefix[i] = j;
    while (i > 0) {
        while (j <= m && pattern[i - 1] != pattern[j - 1]) {
            if (goodSuffix[j] == 0)
                goodSuffix[j] = j - i;
            j = longestPrefix[j];
        }
        i--;
        j--;
        longestPrefix[i] = j;
    }

    j = longestPrefix[0];
    for (i = 0; i <= m; i++) {
        if (goodSuffix[i] == 0)
            goodSuffix[i] = j;
        if (i == j)
            j = longestPrefix[j];
    }
}

// Function to perform Boyer-Moore string matching
void boyerMoore(const string &text, const string &pattern) {
    int n = text.length();
    int m = pattern.length();

    vector<int> badChar(MAX_CHAR, 0); // Bad character heuristic array
    vector<int> goodSuffix(m + 1, 0); // Good suffix heuristic array

    computeBadCharHeuristic(pattern, badChar);
    computeGoodSuffixHeuristic(pattern, goodSuffix);

    int s = 0; 
    while (s <= (n - m)) {
        int j = m - 1;

        while (j >= 0 && pattern[j] == text[s + j])
            j--;

        if (j < 0) {
            cout << "Pattern found at index " << s << endl;

            s += goodSuffix[0];
        } else {
            s += max(goodSuffix[j + 1], j - badChar[text[s + j]]);
        }
    }
}

int main() {
    string text, pattern;

    cout << "Enter the text: ";
    getline(cin, text);
    cout << "Enter the pattern to search for: ";
    getline(cin, pattern);

    cout << "Text: " << text << endl;
    cout << "Pattern: " << pattern << endl;
    
    cout << "Pattern occurrences: " << endl;
    boyerMoore(text, pattern);

    return 0;
}


/*

Worst Case: O(nm) where n is the length of the text and m is the length of the pattern. This occurs when the pattern occurs at every position in the text.
Average Case: O(n/m) where n is the length of the text and m is the length of the pattern. This occurs when mismatches happen frequently, leading to larger skips in the search.
Best Case: O(n/m) where n is the length of the text and m is the length of the pattern. This occurs when the pattern does not occur in the text at all, or only occurs at the end of the text, allowing for maximal shifts.
*/