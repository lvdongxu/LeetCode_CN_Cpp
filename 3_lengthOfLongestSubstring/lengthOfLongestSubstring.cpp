#include <iostream>
#include <string>
using namespace std;

int main() {
    string test_String = "dvdf";
    // Wrong test example: "pwwkew", "c", "dvdf"
    string final_String;
    string string_Cache;
    int max_Length = 0;
    for (int i = 0; i < test_String.length(); i++) {
        if (final_String.find(test_String[i]) == string::npos) {
            final_String += test_String[i];
        }
        else {
            if (max_Length < final_String.length()) {
                max_Length = final_String.length();
                string_Cache = final_String;
            }
            final_String = final_String.substr(final_String.find(test_String[i])+1) + test_String[i];
        }
        if ((i == test_String.length()-1) && (max_Length < final_String.length())) {
            max_Length = final_String.length();
            string_Cache = final_String;
        }
    }

    cout << string_Cache << endl;
    cout << max_Length << endl;
    // cout << final_String << endl;
    // cout << test_String.find("bb") << endl;

    return 0;
    
}