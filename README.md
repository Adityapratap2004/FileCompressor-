
# File Compression Tool using Huffman Coding

This project is a C++ command-line tool for compressing and decompressing files using Huffman coding, an efficient, lossless data compression algorithm. This tool enables users to reduce file sizes by encoding data based on frequency, making it perfect for text files with redundant characters. The tool also allows decompression, restoring the original file from its compressed version.



## Features

- **Compression**: Reduces file size using Huffman coding.
- **Decompression**: Restores original data from compressed files.
- **Interactive CLI**: User-friendly prompts for specifying input and output files.
- **Error Handling**: Robust error handling for file operations and invalid input cases.


## How Huffman Coding Works

Huffman coding is a lossless data compression algorithm that assigns variable-length codes to characters based on their frequencies. Characters that occur more frequently receive shorter codes, thus reducing the overall file size.
## Getting Started

*Prerequisites*
- A C++ compiler (e.g., g++)
- Basic command-line knowledge

*Installation*

- Clone the repository:

```
git clone https://github.com/your-username/file-compression-tool.git
cd file-compression-tool
```

*Compilation*

- To compile the project, run the following command:

```
g++ -o huffman_compressor main.cpp compressor.cpp decompressor.cpp file_io.cpp huffman_tree.cpp
```







## Usage

The tool provides both compression and decompression options through the command line. Use the commands below to compress and decompress files.

*Compress a File*

```
./huffman_compressor compress <input_file> <compressed_output_file>
```
Example:

```
./huffman_compressor compress input.txt compressed_output.huf
```

*Decompress a File*

```
./huffman_compressor decompress <compressed_file> <output_file>
```
Example:

```
./huffman_compressor decompress compressed_output.huf decompressed.txt
```
## Example

For a quick demonstration, create a simple text file and compress it:

```
echo "Example text for compression" > sample.txt
./huffman_compressor compress sample.txt compressed.huf
./huffman_compressor decompress compressed.huf decompressed.txt
cat decompressed.txt
```
## Limitations

- Huffman coding is best suited for files with character redundancy (e.g., text files).

- For highly unique or complex files (e.g., images or already compressed files), Huffman coding may increase file size.
