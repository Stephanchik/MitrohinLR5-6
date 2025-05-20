#ifndef _MITROHIN_LR5_6_EXPERIMENTS_DEF_H
#define _MITROHIN_LR5_6_EXPERIMENTS_DEF_H

#include <string>
#include <iostream>
#include <functional>
#include <stdexcept>

using namespace std;

bool UserInputInt(string input) {
    if (input.empty()) return false;
    try {
        int number = stoi(input);
        return number >= 0;
    } catch (...) {
        return false;
    }
}

bool UserInputDbl(string input) {
    if (input.empty()) return false;
    try {
        double number = stod(input);
        return number >= 0;
    } catch (...) {
        return false;
    }
}

bool UserInputStr(string input) {
    return !input.empty();
}

function<void()> EnterNumber(istream& myistream, int& varLink, string label) {
    return [&myistream, &varLink, label]() {
        string raw_input;
        cout << label << " - ";
        getline(myistream, raw_input);
        while (!UserInputInt(raw_input)) {
            cout << label << " - ";
            getline(myistream, raw_input);
        }
        varLink = stoi(raw_input);
    };
}

function<void()> EnterDouble(istream& myistream, double& varLink, string label) {
    return [&myistream, &varLink, label]() {
        string raw_input;
        cout << label << " - ";
        getline(myistream, raw_input);
        while (!UserInputDbl(raw_input)) {
            cout << label << " - ";
            getline(myistream, raw_input);
        }
        varLink = stod(raw_input);
    };
}

function<void()> EnterString(istream& myistream, string& varLink, string label) {
    return [&myistream, &varLink, label]() {
        cout << label << " - ";
        getline(myistream, varLink);
        while (!UserInputStr(varLink)) {
            cout << label << " - ";
            getline(myistream, varLink);
        }
    };
}

#endif // _MITROHIN_LR5_6_EXPERIMENTS_DEF_H