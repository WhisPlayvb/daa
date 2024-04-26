#include <iostream>
#include <string>
using namespace std;

void naiveStringMatching(const string& text, const string& pattern) {
    int n = text.length();
    int m = pattern.length();

    if(m>n)
    {
    	cout<<"Pattren is longer than text .. No string match possible..."<<endl;
    	return;
	}
    
    	
    for (int i = 0; i <= n - m; i++) {
        bool found = true;
        
        for (int j = 0; j < m; j++) {
            if (text[i + j] != pattern[j]) {
                found = false;
                break;
            }
        }
        
        if (found) {
            cout << "Pattern found at index " << i << endl;
        }
    }
}

int main() {
    string text, pattern;

   
    cout << "Enter the text: ";
    getline(cin, text);
    cout << "Enter the pattern: ";
    getline(cin, pattern);

    naiveStringMatching(text, pattern);

    return 0;
}
