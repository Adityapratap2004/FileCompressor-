#include "compressor.h"
#include "huffman_tree.h"
#include "string"
#include <fstream> 
using namespace std;


void compress(const string& content, string& compressedData, unordered_map<char, string>& huffmanCodes) {
    buildHuffmanTree(content, huffmanCodes);

    for (char ch : content) {
        compressedData += huffmanCodes[ch];
    }
}
