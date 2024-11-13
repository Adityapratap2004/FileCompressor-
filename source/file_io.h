#ifndef FILE_IO_H
#define FILE_IO_H

#include <string>
#include <unordered_map>
using namespace std;

string loadFile(const string& filename);
void saveCompressedFile(const string& filename, const string& compressedData, const unordered_map<char, string>& huffmanCodes);
void loadCompressedFile(const string& filename, string& compressedData, unordered_map<char, string>& huffmanCodes);

#endif
