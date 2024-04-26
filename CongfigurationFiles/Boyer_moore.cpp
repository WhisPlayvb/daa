#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int ALPHABET_SIZE = 256;

// Function to preprocess the pattern and calculate bad character heuristic
void preProcessBadChar(const string& pattern, vector<int>& badChar) {
    fill(badChar.begin(), badChar.end(), 0); // Filling with 0 instead of -1
    for (int i = 1; i <= pattern.size(); i++) // Starting from 1
        badChar[pattern[i - 1]] = i; // Adjusting index
}

// Function to compute suffixes for the Good Suffix Heuristic
void suffixes(const string& pattern, vector<int>& suffix) {
    int m = pattern.size();
    int f = 0;
    suffix[m] = m; // Adjusting index
    for (int i = m - 1; i >= 1; i--) { // Starting from 1
        while (f > 0 && pattern[m - f] != pattern[i - 1]) // Adjusting index
            f = suffix[m - f]; // Adjusting index
        if (pattern[m - f] == pattern[i - 1]) // Adjusting index
            f++;
        suffix[i] = f;
    }
}

// Function to preprocess the pattern and calculate good suffix heuristic
void preProcessGoodSuffix(const string& pattern, vector<int>& goodSuffix) {
    int m = pattern.size();
    vector<int> suffix(m + 1);
    suffixes(pattern, suffix);
    fill(goodSuffix.begin(), goodSuffix.end(), m);
    int j = 0;
    for (int i = m; i >= 0; i--) { // Starting from 0
        if (i == 0 || suffix[i] == i) { // Adjusting index
            for (; j < m - i; j++) {
                if (goodSuffix[j] == m)
                    goodSuffix[j] = m - i;
            }
        }
    }
    for (int i = 1; i <= m; i++) // Starting from 1
        goodSuffix[m - suffix[i]] = m - i; // Adjusting index
}

// Function to perform Boyer-Moore string matching
void boyerMoore(const string& text, const string& pattern) {
    int n = text.size();
    int m = pattern.size();
    vector<int> badChar(ALPHABET_SIZE);
    preProcessBadChar(pattern, badChar);
    vector<int> goodSuffix(m + 1);
    preProcessGoodSuffix(pattern, goodSuffix);

    int s = 0; // Shift of the pattern with respect to text
    while (s <= n - m) {
        int j = m;
        while (j >= 1 && pattern[j - 1] == text[s + j - 1]) // Adjusting index
            j--;
        if (j == 0) { // Adjusting index
            cout << "Pattern occurs at index " << s + 1 << endl; // Adjusting index
            s += max(1, goodSuffix[0]); // Ensure minimum shift of 1
        } else {
            s += max(goodSuffix[j], j - badChar[text[s + j - 1]]);
        }
    }
}

int main() {
    string text, pattern;
    cout << "Enter the text: ";
    getline(cin, text);
    cout << "Enter the pattern to search for: ";
    getline(cin, pattern);

    boyerMoore(text, pattern);

    return 0;
}
/*
time complexity of O(n/m), where n is the text’s length and m is the pattern’s length
On average, the Boyer-Moore algorithm maintains an O(n) time complexity
worst case: with a time complexity of O(mn), where m is the length of the pattern and n is the length of the text.
Enter the text: I HATE MITAOE
Enter the pattern to search for: MIT
Pattern occurs at index 8

--------------------------------
Process exited after 8.314 seconds with return value 0
Press any key to continue . . .*/

