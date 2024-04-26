#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Preprocess the pattern to calculate the longest proper prefix which is also a suffix for each prefix
vector<int> computeLPS(const string& pattern) {
    int m = pattern.length();
    vector<int> lps(m, 0); // Initialize LPS array with zeros
    int len = 0; // Length of the previous longest prefix suffix

    for (int i = 1; i < m; ) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        }
        else {
            if (len != 0) {
                len = lps[len - 1];
            }
            else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

// KMP string matching algorithm
void KMP(const string& text, const string& pattern) {
    int n = text.length();
    int m = pattern.length();

    vector<int> lps = computeLPS(pattern); // Preprocess the pattern

    int i = 0; // Index for text[]
    int j = 0; // Index for pattern[]

    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) { // Pattern found
            cout << "Pattern found at index " <<  i - j  << endl; // Adjusted the index to start from 1
            j = lps[j - 1];
        }
        else if (i < n && pattern[j] != text[i]) {
            if (j != 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
}

int main() {
    string text, pattern;
    cout << "Enter the text: ";
    getline(cin, text);
    cout << "Enter the pattern to search for: ";
    getline(cin, pattern);

    KMP(text, pattern);

    return 0;
}
/*Time Complexity: O(N+M) where N is the length of the text and M is the length of the pattern to be found.
Auxiliary Space: O(M)*/

