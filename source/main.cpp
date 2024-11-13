#include <iostream>
#include "file_io.h"
#include <fstream>
#include "compressor.h"
#include "decompressor.h"

using namespace std;
void showHelp()
{
    cout << "Usage:\n"
         << "  Compress:   ./file_compressor compress <input_file> <output_file>\n"
         << "  Decompress: ./file_compressor decompress <input_file> <output_file>\n\n"
         << "Options:\n"
         << "  -h               Show this help message\n"
         << "  No arguments     Enter interactive mode to specify files and mode\n";
}

string getFilePath(const string &prompt)
{
    string filePath;
    cout << prompt;
    cin >> filePath;

    // Check if the file exists (for input files only)
    ifstream file(filePath);
    if (!file && prompt.find("input") != string::npos)
    {
        cerr << "Error: File not found. Please enter a valid file path.\n";
        return getFilePath(prompt); // Retry if the file does not exist
    }
    return filePath;
}

int main(int argc, char *argv[])
{
    // display help if requested
    if (argc == 2 && string(argv[1]) == "-h")
    {
        showHelp();
        return 0;
    }
    string mode, inputFile, outputFile;
    if (argc < 4)
    {
        cout << "Welcome to the File Compressor!\n\n";
        cout << "Please choose an operation:\n";
        cout << "1. Compress a file\n";
        cout << "2. Decompress a file\n";
        cout << "Enter your choice (1 or 2): ";
        cin >> mode;

        // Validate mode
        if (mode == "1")
        {
            mode = "compress";
        }
        else if (mode == "2")
        {
            mode = "decompress";
        }
        else
        {
            cerr << "Invalid choice. Exiting.\n";
            return 1;
        }

        inputFile = getFilePath("Enter the input file path: ");
        outputFile = getFilePath("Enter the output file path: ");
    }
    else
    {
        mode = argv[1];
        inputFile = argv[2];
        outputFile = argv[3];
    }

    try
    {
        if (mode == "compress")
        {
            string content = loadFile(inputFile);
            string compressedData;
            unordered_map<char, string> huffmanCodes;
            compress(content, compressedData, huffmanCodes);
            saveCompressedFile(outputFile, compressedData, huffmanCodes);
        }
        else if (mode == "decompress")
        {
            decompressFile(inputFile, outputFile);
        }
        else
        {
            cerr << "Invalid mode. Use 'compress' or 'decompress'.\n";
            return 1;
        }
    }
    catch (const runtime_error &e)
    {
        cerr << "Error: " << e.what() << '\n';
        return 1;
    }

    return 0;
}