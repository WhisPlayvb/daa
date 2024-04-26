#include <iostream>
#include <string>

#define d 10

void rabinKarp(const std::string& pattern, const std::string& text) {
    int q = 13; // Predefined prime number
    int m = pattern.length();
    int n = text.length();
    int i, j;
    int p = 0;
    int t = 0;
    int h = 1;

    for (i = 0; i < m - 1; i++)
        h = (h * d) % q;

    // Calculate hash value for pattern and text
    for (i = 0; i < m; i++) {
        p = (d * p + pattern[i]) % q;
        t = (d * t + text[i]) % q;
    }

    // Find the match
    for (i = 0; i <= n - m; i++) {
        if (p == t) {
            for (j = 0; j < m; j++) {
                if (text[i + j] != pattern[j])
                    break;
            }

            if (j == m)
                std::cout << "Pattern is found at position: " << i + 1 << std::endl;
        }

        if (i < n - m) {
            t = (d * (t - text[i] * h) + text[i + m]) % q;

            if (t < 0)
                t = (t + q);
        }
    }
}

int main() {
    std::string text, pattern;

    std::cout << "Enter the text: ";
    std::getline(std::cin, text); // Read entire line
    std::cout << "Enter the pattern to search for: ";
    std::getline(std::cin, pattern); // Read entire line

    rabinKarp(pattern, text);
    return 0;
}
/*Enter the text: MITAOE
Enter the pattern to search for: AO
Pattern is found at position: 4

--------------------------------
Process exited after 12.66 seconds with return value 0
Press any key to continue . . .

time complexity is O(Ns + Np), where ‘Ns’ and ‘Np’ are the lengths of the given string and pattern respectively
space complexity is O(1)
