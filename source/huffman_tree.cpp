#include "huffman_tree.h"
#include <queue>
#include <memory>
#include <unordered_map>
#include <vector>

using namespace std;

struct HuffmanNode {
    char ch;
    int freq;
    shared_ptr<HuffmanNode> left, right;

    HuffmanNode(char character, int frequency) : ch(character), freq(frequency), left(nullptr), right(nullptr) {}
    bool isLeaf() const { return !left && !right; }
};

struct CompareNode {
    bool operator()(const shared_ptr<HuffmanNode>& a, const shared_ptr<HuffmanNode>& b) {
        return a->freq > b->freq;
    }
};

void generateCodes(const shared_ptr<HuffmanNode>& node, const string& code, unordered_map<char, string>& huffmanCodes) {
    if (node == nullptr) return;

    if (node->isLeaf()) {
        huffmanCodes[node->ch] = code;
    } else {
        generateCodes(node->left, code + "0", huffmanCodes);
        generateCodes(node->right, code + "1", huffmanCodes);
    }
}

void buildHuffmanTree(const string& content, unordered_map<char, string>& huffmanCodes) {
    unordered_map<char, int> freqMap;
    for (char ch : content) {
        freqMap[ch]++;
    }

    priority_queue<shared_ptr<HuffmanNode>, vector<shared_ptr<HuffmanNode>>, CompareNode> minHeap;
    for (const auto& pair : freqMap) {
        minHeap.push(make_shared<HuffmanNode>(pair.first, pair.second));
    }

    while (minHeap.size() > 1) {
        auto left = minHeap.top(); minHeap.pop();
        auto right = minHeap.top(); minHeap.pop();
        auto combined = make_shared<HuffmanNode>('\0', left->freq + right->freq);
        combined->left = left;
        combined->right = right;
        minHeap.push(combined);
    }

    generateCodes(minHeap.top(), "", huffmanCodes);
}
