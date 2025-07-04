
#include <iostream>
#include <queue>
#include <unordered_map>
#include <string>

using namespace std;

// Huffman tree node
struct Node {
    char data;
    int freq;
    Node *left, *right;
    Node(char d, int f) : data(d), freq(f), left(nullptr), right(nullptr) {}
};

// Comparison for priority queue
struct Compare {
    bool operator()(Node* l, Node* r) {
        return l->freq > r->freq;
    }
};

// Generate Huffman codes
void generateCodes(Node* root, string code, unordered_map<char, string>& codes) {
    if (!root) return;
    if (!root->left && !root->right) {
        codes[root->data] = code.empty() ? "0" : code;
    }
    generateCodes(root->left, code + "0", codes);
    generateCodes(root->right, code + "1", codes);
}

// Build Huffman tree and return root
Node* buildHuffmanTree(string text) {
    // Count frequency of each character
    unordered_map<char, int> freq;
    for (char c : text) freq[c]++;

    // Create priority queue of nodes
    priority_queue<Node*, vector<Node*>, Compare> pq;
    for (auto pair : freq) {
        pq.push(new Node(pair.first, pair.second));
    }

    // Build the Huffman tree
    while (pq.size() > 1) {
        Node* left = pq.top(); pq.pop();
        Node* right = pq.top(); pq.pop();
        Node* parent = new Node('\0', left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        pq.push(parent);
    }
    return pq.top();
}

// Encode the text
string encode(string text, unordered_map<char, string>& codes) {
    string encoded = "";
    for (char c : text) {
        encoded += codes[c];
    }
    return encoded;
}

// Decode the encoded string
string decode(Node* root, string encoded) {
    string decoded = "";
    Node* current = root;
    for (char bit : encoded) {
        if (bit == '0') current = current->left;
        else current = current->right;
        
        if (!current->left && !current->right) {
            decoded += current->data;
            current = root;
        }
    }
    return decoded;
}

// Clean up memory
void deleteTree(Node* root) {
    if (!root) return;
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    string text = "hello world";
    cout << "Original text: " << text << endl;

    // Build Huffman tree
    Node* root = buildHuffmanTree(text);

    // Generate codes
    unordered_map<char, string> codes;
    generateCodes(root, "", codes);

    // Print codes
    cout << "Huffman Codes:" << endl;
    for (auto pair : codes) {
        cout << pair.first << ": " << pair.second << endl;
    }

    // Encode
    string encoded = encode(text, codes);
    cout << "Encoded: " << encoded << endl;

    // Decode
    string decoded = decode(root, encoded);
    cout << "Decoded: " << decoded << endl;

    // Clean up
    deleteTree(root);
    return 0;
}
