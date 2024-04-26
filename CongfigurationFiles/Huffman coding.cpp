#include <iostream>
#include <queue>
#include <map>
#include <string>
using namespace std;

// A Huffman tree node
struct Node {
    char data;
    unsigned freq;
    Node *left, *right;
};

// Function to create a new node
Node* newNode(char data, unsigned freq) {
    Node* node = new Node();
    node->data = data;
    node->freq = freq;
    node->left = node->right = NULL;
    return node;
}

// Comparison object to be used to order the heap
struct compare {
    bool operator()(Node* l, Node* r) {
        return (l->freq > r->freq);
    }
};

// Function to build Huffman Tree and return the root node
Node* buildHuffmanTree(const string& text) {
    // Count frequencies of characters
    map<char, unsigned> freq;
    for (size_t i = 0; i < text.length(); ++i) {
        freq[text[i]]++;
    }

    // Create a priority queue to store live nodes of Huffman tree
    priority_queue<Node*, vector<Node*>, compare> pq;

    // Create leaf nodes for each character and add them to the priority queue
    for (map<char, unsigned>::iterator it = freq.begin(); it != freq.end(); ++it) {
        pq.push(newNode(it->first, it->second));
    }

    // Iterate while size of priority queue is greater than 1
    while (pq.size() > 1) {
        // Remove the two nodes with the lowest frequency
        Node* left = pq.top();
        pq.pop();
        Node* right = pq.top();
        pq.pop();

        // Create a new internal node with these two nodes as children
        // and with a frequency equal to the sum of their frequencies.
        // Add the new node to the priority queue.
        Node* top = newNode('\0', left->freq + right->freq);
        top->left = left;
        top->right = right;
        pq.push(top);
    }

    // Root of the Huffman Tree is the only node remaining in the priority queue
    return pq.top();
}

// Function to print Huffman codes from the root of Huffman Tree
void printHuffmanCodes(Node* root, string code, map<char, string>& huffmanCode) {
    if (root == NULL)
        return;

    // Found a leaf node
    if (!root->left && !root->right) {
        huffmanCode[root->data] = code;
        cout << root->data << ": " << code << endl;
    }

    // Recur for left and right sub-tree
    printHuffmanCodes(root->left, code + "0", huffmanCode);
    printHuffmanCodes(root->right, code + "1", huffmanCode);
}

// Function to encode the input text using Huffman codes
string encode(const string& text, const map<char, string>& huffmanCode) {
    string encodedMsg = "";
    for (size_t i = 0; i < text.length(); ++i) {
        encodedMsg += huffmanCode.at(text[i]);
    }
    return encodedMsg;
}

// Function to decode the encoded text using Huffman codes
string decode(const string& encodedMsg, Node* root) {
    string decodedMsg = "";
    Node* current = root;
    for (size_t i = 0; i < encodedMsg.length(); ++i) {
        if (encodedMsg[i] == '0') {
            current = current->left;
        } else {
            current = current->right;
        }
        if (!current->left && !current->right) {
            decodedMsg += current->data;
            current = root;
        }
    }
    return decodedMsg;
}

int main() {
    string text;
    cout << "Enter a string: ";
    getline(cin, text);

    // Build Huffman Tree
    Node* root = buildHuffmanTree(text);

    // Print character frequencies and Huffman codes
    map<char, string> huffmanCode;
    cout << "Character frequencies and Huffman codes:" << endl;
    printHuffmanCodes(root, "", huffmanCode);

    // Encode the input text using Huffman codes
    string encodedMsg = encode(text, huffmanCode);
    cout << "Encoded message: " << encodedMsg << endl;

    // Decode the encoded message
    string decodedMsg = decode(encodedMsg, root);
    cout << "Decoded message: " << decodedMsg << endl;

    return 0;
}
/*Enter a string: BCAADDDCCACACAC
Character frequencies and Huffman codes:
C: 0
B: 100
D: 101
A: 11
Encoded message: 1000111110110110100110110110
Decoded message: BCAADDDCCACACAC*/
