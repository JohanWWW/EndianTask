#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream bigEndianFile("bigendian.txt");
    ofstream littleEndianFile("littleendian.txt");
    ofstream middleByteFile("middlebyte.txt");

    long input;
    while (bigEndianFile >> input) {
        if (input < 0 || input > USHRT_MAX)
            cout << "Warning: " << input << " is not an unsigned short. Value will overflow." << endl;

        unsigned short bigEndianVal = input;
        unsigned char lbyte = (bigEndianVal >> 8) & 0xFF;
        unsigned char rbyte = bigEndianVal & 0xFF;
        unsigned short littleEndianVal = (rbyte << 8) | lbyte;

        littleEndianFile << littleEndianVal << endl;
        middleByteFile << ((littleEndianVal >> 4) & 0xFF) << endl;
    }

    bigEndianFile.close();
    littleEndianFile.close();
    middleByteFile.close();

    return 0;
}