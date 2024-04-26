#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

class Node {
public:
    int data;
    char ch;
    Node* left;
    Node* right;
    
    Node(int d, char ch1) {
        data = d;
        ch = ch1;
        left = NULL;
        right = NULL;
    }
};

class cmp {
public:
    bool operator()(Node* a , Node* b) {
        return a->data > b->data;
    }
};

class Solution {
public:
    void traverse(Node* root, vector<pair<char, string> >& ans, const string& temp) {
        if (root->left == NULL && root->right == NULL) {
            ans.push_back(make_pair(root->ch, temp));
            return;
        }

        string leftTemp = temp + '0';
        string rightTemp = temp + '1';

        this->traverse(root->left, ans, leftTemp);
        this->traverse(root->right, ans, rightTemp);
    }

    vector<pair<char, string> > huffmanCodes(string S, vector<int> f, int N) {
        priority_queue<Node*, vector<Node*>, cmp> pq;
        
        for(int i = 0; i < N; i++) {
            Node* temp = new Node(f[i], S[i]);
            pq.push(temp);
        }
        
        while(pq.size() > 1) {
            Node* left = pq.top();
            pq.pop();
            Node* right = pq.top();
            pq.pop();
            
            Node* newnode = new Node(left->data + right->data, ' ');
            newnode->left = left;
            newnode->right = right;
            
            pq.push(newnode);
        }
        
        Node* root = pq.top();
        vector<pair<char, string> > ans;
        string temp = "";
        traverse(root, ans, temp);
        return ans;
    }
};

int main() {
    string S = "ABCDEF";
    vector<int> f; // frequencies
    f.push_back(5);
    f.push_back(12);
    f.push_back(13);
    f.push_back(16);
    f.push_back(45);
    int N = S.size(); // number of characters

    Solution solution;
    vector<pair<char, string> > huffman_codes = solution.huffmanCodes(S, f, N);

    cout << "Huffman Codes:\n";
    for (int i = 0; i < N; ++i) {
        cout << huffman_codes[i].first << ": " << huffman_codes[i].second << endl;
    }

    return 0;
}
