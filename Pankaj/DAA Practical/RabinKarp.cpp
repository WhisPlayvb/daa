/*
 C++ implementation of the Rabin-Karp algorithm along with proper comments explaining each part of the code:
*/



#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// Function to implement Rabin-Karp algorithm
void rabinKarp(string pattern, string text) {
    int prime = 101; // Prime number used for hashing
    int patLength = pattern.length();
    int txtLength = text.length();
    int patHash = 0; // Hash value for the pattern
    int txtHash = 0; // Hash value for the current window of text
    int h = 1;       // Value of h will be pow(prime, patLength-1) % prime

    // Calculate h
    for (int i = 0; i < patLength - 1; i++) {
        h = (h * prime) % prime;
    }

    // Calculate hash value for the pattern and the first window of text
    for (int i = 0; i < patLength; i++) {
        patHash = (prime * patHash + pattern[i]) % prime;
        txtHash = (prime * txtHash + text[i]) % prime;
    }

    // Slide the pattern over the text one by one
    for (int i = 0; i <= txtLength - patLength; i++) {
        // Check if the hash values of current window of text and pattern match
        if (patHash == txtHash) {
            // Check each character in the window to confirm the match
            int j;
            for (j = 0; j < patLength; j++) {
                if (text[i + j] != pattern[j])
                    break;
            }
            // If pattern found
            if (j == patLength) {
                cout << "Pattern found at index " << i << endl;
            }
        }
        // Calculate hash value for the next window of text
        if (i < txtLength - patLength) {
            txtHash = (prime * (txtHash - text[i] * h) + text[i + patLength]) % prime;
            // Handling negative hash value
            if (txtHash < 0)
                txtHash += prime;
        }
    }
}

int main() {
    string text;
    cout<<"enter string \n";
    cin>>text;
    string pattern ;
    cout<<"enter pattern \n";
    cin>>pattern;

    cout << "Text: " << text << endl;
    cout << "Pattern: " << pattern << endl;
    cout << "Pattern found at indices: " << endl;
    rabinKarp(pattern, text);

    return 0;
}

/*

enter string 
AABAACAADAABAABA
enter pattern 

AABA
Text: AABAACAADAABAABA
Pattern: AABA
Pattern found at indices: 
Pattern found at index 0
Pattern found at index 9
Pattern found at index 12
*/