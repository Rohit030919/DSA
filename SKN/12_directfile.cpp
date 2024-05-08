#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

const string FILENAME = "records.txt"; // Name of the text file

// Function to insert a record into the direct access file
void insertRecord(int position, const string& record) {
    ofstream file(FILENAME, ios::app);
    if (!file.is_open()) {
        cerr << "Error: Unable to open file." << endl;
        return;
    }

    file.seekp(position * (record.size() + 1)); // Move to the appropriate position in the file
    file << record << endl;
    file.close();
}

// Function to delete a record from the direct access file
void deleteRecord(int position) {
    ifstream inFile(FILENAME);
    if (!inFile.is_open()) {
        cerr << "Error: Unable to open file." << endl;
        return;
    }

    string line;
    vector<string> records;
    while (getline(inFile, line)) {
        records.push_back(line);
    }
    inFile.close();

    if (position < 0 || position >= records.size()) {
        cerr << "Error: Invalid position." << endl;
        return;
    }

    records.erase(records.begin() + position); // Erase the record at the specified position

    ofstream outFile(FILENAME);
    if (!outFile.is_open()) {
        cerr << "Error: Unable to open file." << endl;
        return;
    }

    for (const string& record : records) {
        outFile << record << endl;
    }
    outFile.close();
}

int main() {
    // Insert records
    insertRecord(0, "Record 1");
    insertRecord(1, "Record 2");
    insertRecord(2, "Record 3");

    // Delete record at position 1
    deleteRecord(1);

    // Read and print contents of the file
    ifstream inFile(FILENAME);
    if (!inFile.is_open()) {
        cerr << "Error: Unable to open file." << endl;
        return 1;
    }

    cout << "Contents of the text file:" << endl;
    string line;
    while (getline(inFile, line)) {
        cout << line << endl;
    }
    inFile.close();

    return 0;
}
