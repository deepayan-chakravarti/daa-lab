#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <chrono>

using namespace std;
using namespace std::chrono;

struct Node {
    char ch;
    int freq;
    Node *left, *right;
    
    Node(char c, int f) {
        ch = c;
        freq = f;
        left = right = nullptr;
    }
};

struct Compare {
    bool operator()(Node* a, Node* b) {
        return a->freq > b->freq;
    }
};

void printCodes(Node* root, string code) {
    if (root == nullptr)
        return;
        
    if (root->left == nullptr && root->right == nullptr) {
        cout << root->ch << " : " << (code.empty() ? "0" : code) << '\n';
        return;
    }
    
    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

void huffmanCoding(vector<char>& chars, vector<int>& freq, int n) {
    priority_queue<Node*, vector<Node*>, Compare> pq;
    
    for (int i = 0; i < n; i++) {
        pq.push(new Node(chars[i], freq[i]));
    }
    
    while (pq.size() > 1) {
        Node* left = pq.top();
        pq.pop();
        
        Node* right = pq.top();
        pq.pop();
        
        Node* parent = new Node('$', left->freq + right->freq);
        parent->left = left;
        parent->right = right;
        
        pq.push(parent);
    }
    
    cout << "\nHuffman Codes: \n";
    printCodes(pq.top(), "");
}

int main() {
    cout<<"Deepayan Chakravarti"<<endl;
    cout<<"04714802724"<<endl;
    int n;
    cout << "Enter number of characters: ";
    cin >> n;
    
    if (n <= 0) {
        cout << "Number of characters must be positive.\n";
        return 0;
    }
    
    vector<char> chars(n);
    vector<int> freq(n);
    
    cout << "Enter each character and its frequency:\n";
    for (int i = 0; i < n; i++) {
        cin >> chars[i] >> freq[i];
        if (freq[i] <= 0) {
            cout << "Frequencies must be positive.\n";
            return 0;
        }
    }
    
    auto start = high_resolution_clock::now();
    
    huffmanCoding(chars, freq, n);
    
    auto stop = high_resolution_clock::now();
    double ms = duration<double, milli>(stop - start).count();
    
    cout << "\nExecution time: " << ms << " ms\n";
    
    return 0;
}