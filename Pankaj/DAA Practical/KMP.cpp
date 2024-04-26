#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> computeLPS(const string& pattern) {
    int n = pattern.size();
    vector<int> lps(n, 0);

    int len = 0; 

    lps[0] = 0;

    int i = 1;
    while (i < n) {
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


void KMP(const string& text, const string& pattern) {
    int n = text.size();
    int m = pattern.size();

    vector<int> lps = computeLPS(pattern);

    int i = 0;
    int j = 0;

    while (i < n) {
        if (pattern[j] == text[i]) {
            i++;
            j++;
        }

        if (j == m) {
            cout << "Pattern found at index " << i - j << endl;
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

    cout << "Text: " << text << endl;
    cout << "Pattern: " << pattern << endl;

    KMP(text, pattern);

    return 0;
}


/*
Text: ABABDABACDABABCABAB
Pattern: ABABCABAB
Pattern found at index 10


Enter the text: ABABDABACDABABCABAB
Enter the pattern to search for: ABABCABAB
Text: ABABDABACDABABCABAB
Pattern: ABABCABAB
Pattern found at index 10



Worst Case: O(n + m)
This occurs when the pattern occurs at the end of the text or doesn't occur at all. The entire text needs to be traversed, and in the worst case, the pattern is matched against every character in the text.
Average Case: O(n + m)
Typically, the algorithm performs close to its worst-case time complexity, as it still needs to traverse both the text and the pattern.
Best Case: O(n)
The best case occurs when the pattern is found at the very beginning of the text. In this case, the algorithm only needs to traverse the text once.
*/