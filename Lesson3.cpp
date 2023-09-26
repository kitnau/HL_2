#include <iostream>
#include <fstream>
#include <string>

using namespace std;

//Первый вариант

class TxtToGift {
private:
    ifstream inputFile;
    ofstream outputFile;
    bool isQuestion;

public:
    TxtToGift(string inputFileName, string outputFileName) {
        inputFile.open(inputFileName);
        outputFile.open(outputFileName);

        isQuestion = false;
    }

    ~TxtToGift() {

        inputFile.close();
        outputFile.close();
    }

    void transform() {
        string line;
        while (getline(inputFile, line)) {
            
            if (isdigit(line[0])) {
                if (isQuestion) {
                    outputFile << "}" << "\n";
                }
                outputFile << line.substr(2) << " {"<< "\n";
                isQuestion = true;
            } 
            else if (!isalpha(line[0])) {
                outputFile << (line[0] == '+' ? '=' : '~') << line.substr(1) << "\n";
            }
            
            
        }
        if (isQuestion) {
            outputFile << "}" << "\n";
        }
    }
};

int main() {
    TxtToGift converter("input.txt", "output.gift");
    converter.transform();
    return 0;
}