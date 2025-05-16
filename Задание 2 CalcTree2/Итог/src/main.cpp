#include "include/processor.h"

int main() {
    try {
        cout << "Enter input filename: ";
        string filename;
        cin >> filename;

        Node* result = processExpressionFile(filename);
        cout << "\nProcessing result:\n"
            << "Root address: " << result << "\n"
            << "Root value: " << result->value << endl;

        delete result;
    }
    catch (const exception& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
    return 0;
}