#ifndef COMPRESSOR_H
#define COMPRESSOR_H

#include <string>
#include <unordered_map>

using namespace std;

void compress(const string& content, string& compressedData, unordered_map<char,string>& huffmanCodes);

#endif