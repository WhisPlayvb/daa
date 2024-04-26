#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;


class Node {
    public:
        char data;
        int freq;
        Node *left, *right;
};


Node* createNode(char data, int freq) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->freq = freq;
    newNode->left = newNode->right = nullptr;
    return newNode;
}


struct comp {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};


Node* buildHuffmanTree(const unordered_map<char, int>& freq) {
    priority_queue<Node*, vector<Node*>, comp> pq;

    for (const auto& pair : freq) {
        pq.push(createNode(pair.first, pair.second));
    }

    while (pq.size() != 1) {
        Node *left = pq.top(); pq.pop();
        Node *right = pq.top(); pq.pop();

        Node *merged = createNode('\0', left->freq + right->freq);
        merged->left = left;
        merged->right = right;
        pq.push(merged);
    }

    return pq.top();
}


void encode(Node* root, string code, unordered_map<char, string>& huffmanCode) {
    if (!root)
        return;

    if (!root->left && !root->right) {
        huffmanCode[root->data] = code;
        cout << root->data << ": " << code << endl;
    }

    encode(root->left, code + "0", huffmanCode);
    encode(root->right, code + "1", huffmanCode);
}


string huffmanEncode(const string& input ,unordered_map<char, int> freq) {

    Node* root = buildHuffmanTree(freq);

    unordered_map<char, string> huffmanCode;
    encode(root, "", huffmanCode);

    string encodedString = "";
    for (char c : input) {
        encodedString += huffmanCode[c];
    }

    return encodedString;
}

string huffmanDecode(const string& encodedString, Node* root) {
    string decodedString = "";
    Node* current = root;

    for (char bit : encodedString) {
        if (bit == '0') {
            current = current->left;
        } else {
            current = current->right;
        }

        if (!current->left && !current->right) {
            decodedString += current->data;
            current = root;
        }
    }

    return decodedString;
}

int main() {
    string input;
    cout<<"Enter String:";
    cin>>input;
    unordered_map<char, int> freq;
    for (char c : input) {
        freq[c]++;
    }

    string encodedString = huffmanEncode(input,freq);
    cout << "Encoded string: " << encodedString << endl;

    Node* root = buildHuffmanTree(freq);

    string decodedString = huffmanDecode(encodedString, root);
    cout << "Decoded string: " << decodedString << endl;

    return 0;
}
