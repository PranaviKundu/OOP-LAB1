#include <iostream>
#include <map>
#include <string>
#include <algorithm> // For transforming input to lowercase

using namespace std;

// Helper function to convert a string to lowercase
string toLowerCase(const string& str) {
    string result = str;
    transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

int main() {
    // Map to store population data with state/UT names as keys and population as values
    map<string, float> populationMap;

    // Inserting population data (in millions)
    populationMap["Maharashtra"] = 125;
    populationMap["Uttar Pradesh"] = 225;
    populationMap["Bihar"] = 120;
    populationMap["West Bengal"] = 100;
    populationMap["Madhya Pradesh"] = 90;
    populationMap["Tamil Nadu"] = 80;
    populationMap["Rajasthan"] = 78;
    populationMap["Andhra Pradesh"] = 53;
    populationMap["Odisha"] = 47;
    populationMap["Kerala"] = 38;
    populationMap["Telangana"] = 37;
    populationMap["Assam"] = 35;
    populationMap["Jharkhand"] = 38;
    populationMap["Karnataka"] = 68;
    populationMap["Gujarat"] = 70;
    populationMap["Punjab"] = 31;
    populationMap["Chhattisgarh"] = 30;
    populationMap["Haryana"] = 29;
    populationMap["UT Delhi"] = 19;
    populationMap["UT Jammu and Kashmir"] = 14;
    populationMap["Uttarakhand"] = 12;
    populationMap["Himachal Pradesh"] = 8;
    populationMap["Tripura"] = 4;
    populationMap["Meghalaya"] = 4;
    populationMap["Manipur"] = 3;
    populationMap["Nagaland"] = 2;
    populationMap["Goa"] = 2;
    populationMap["Arunachal Pradesh"] = 2;
    populationMap["Mizoram"] = 1;
    populationMap["Sikkim"] = 1;
    populationMap["UT Lakshadweep"] = 0.0003;
    populationMap["UT Ladakh"] = 0.00006;

    // Show the total number of entries
    cout << "Total number of states/UTs: " << populationMap.size() << endl;

    // Display population of all states/UTs
    for (auto iter = populationMap.begin(); iter != populationMap.end(); ++iter) {
        cout << iter->first << ": " << iter->second << " million" << endl;
    }

    // Search for a specific state's population
    char cont;
    do {
        string state;
        cout << "\nEnter the state/UT name to find its population: ";
        getline(cin, state);  // Use getline to allow multi-word input

        // Convert the input to lowercase to handle case-insensitive comparison
        string lowerState = toLowerCase(state);

        // Search for the lowercase version of the state name in the map
        bool found = false;
        for (const auto& entry : populationMap) {
            if (toLowerCase(entry.first) == lowerState) {
                cout << entry.first << "'s population is " << entry.second << " million" << endl;
                found = true;
                break;
            }
        }

        if (!found) {
            cout << "State/UT not found in the population map." << endl;
        }

        cout << "Do you want to search for another state? (y/n): ";
        cin >> cont;
        cin.ignore();  // To clear the buffer before the next getline call
    } while (cont == 'y' || cont == 'Y');

    return 0;
}
