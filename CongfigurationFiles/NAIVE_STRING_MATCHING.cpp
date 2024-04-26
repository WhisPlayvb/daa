#include <iostream>
#include <cstring>

using namespace std;

// Function to perform Naive String Matching
void naiveStringMatch(const char* text, const char* pattern) {
    int n = strlen(text);
    int m = strlen(pattern);

    // Iterate through the text
    for (int i = 0; i <= n - m; ++i) {
        int j;

        // Check if pattern matches at current position of text
        for (j = 0; j < m; ++j) {
            if (text[i + j] != pattern[j])
                break;
        }

        // If pattern matches at current position, print the index
        if (j == m)
            cout << "Pattern found at index " << i << endl;
    }
}

int main() {
    char text[100];
    char pattern[100];

    // Input text from the user
    cout << "Enter the text: ";
    cin.getline(text, sizeof(text));

    // Input pattern from the user
    cout << "Enter the pattern to search for: ";
    cin.getline(pattern, sizeof(pattern));

    cout << "Indices where pattern is found:" << endl;
    naiveStringMatch(text, pattern);

    return 0;
}

/*
OUTPUT:
Enter the text: AABAACAADAABAABA
Enter the pattern to search for: AABA
Indices where pattern is found:
Pattern found at index 0
Pattern found at index 9
Pattern found at index 12
/*

/*
Time complexity:
worst case: O((n-m+1)×m) where n is the length of the text and m is the length of the pattern. 
best case: O(n), where n is the length of the text.
*/
