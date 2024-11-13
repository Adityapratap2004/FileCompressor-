#include "decompressor.h"
#include "file_io.h"
#include "huffman_tree.h"
#include <fstream> 

using namespace std;
void decompressFile(const string& compressedFile, const string& outputFile) {
    string compressedData;
    unordered_map<char, string> huffmanCodes;
    loadCompressedFile(compressedFile, compressedData, huffmanCodes);

    unordered_map<string, char> reverseCodes;
    for (const auto& pair : huffmanCodes) {
        reverseCodes[pair.second] = pair.first;
    }

    string decodedText;
    string buffer;
    for (char bit : compressedData) {
        buffer += bit;
        if (reverseCodes.find(buffer) != reverseCodes.end()) {
            decodedText += reverseCodes[buffer];
            buffer.clear();
        }
    }

    std::ofstream outFile(outputFile);
    if (!outFile) {
        throw runtime_error("Could not open file for writing: " + outputFile);
    }
    outFile << decodedText;
}
