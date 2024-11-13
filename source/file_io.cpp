#include "file_io.h"
#include <fstream>
#include <stdexcept>
using namespace std;

string loadFile(const string& filename) {
    ifstream file(filename, ios::binary);
    if (!file) {
        throw runtime_error("Could not open file " + filename);
    }
    return {istreambuf_iterator<char>(file), istreambuf_iterator<char>()};
}

void saveCompressedFile(const string& filename, const string& compressedData, const unordered_map<char, string>& huffmanCodes) {
    ofstream outFile(filename, ios::binary);
    if (!outFile) {
        throw runtime_error("Could not open file for writing: " + filename);
    }

    
    outFile << huffmanCodes.size() << "\n";
    for (const auto& pair : huffmanCodes) {
        outFile << pair.first << ":" << pair.second << "\n";
    }

    
    outFile << compressedData;
}

void loadCompressedFile(const string& filename, string& compressedData, unordered_map<char, string>& huffmanCodes) {
    ifstream inFile(filename, ios::binary);
    if (!inFile) {
        throw runtime_error("Could not open file for reading: " + filename);
    }

    int codeCount;
    inFile >> codeCount;
    inFile.ignore();

    char ch;
    string code;
    for (int i = 0; i < codeCount; ++i) {
        inFile.get(ch);
        inFile.ignore(1);  // Skip ':'
        getline(inFile, code);
        huffmanCodes[ch] = code;
    }

    compressedData.assign(istreambuf_iterator<char>(inFile), {});
}
