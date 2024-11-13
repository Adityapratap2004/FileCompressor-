#ifndef HUFFMAN_TREE_H
#define HUFFMAN_TREE_H

#include <unordered_map>
#include <string>
using namespace std;

void buildHuffmanTree(const string& content, unordered_map<char, string>& huffmanCodes);

#endif
