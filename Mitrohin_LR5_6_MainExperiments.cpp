#include "Mitrohin_LR5_6_Experiments_def.h"
#include "Mitrohin_LR5_6_Experiments_Methods.cpp"
#include <iostream>
#include <map>
#include <functional>

using namespace std;

int main() {
    map<int, pair<string, function<void()>>> menu = {
        {1, {"Create new Chemical Experiment", createNewChemicalExperiment}},
        {2, {"Create copy of Chemical Experiment", createCopyChemicalExperiment}},
        {3, {"Create modified Chemical Experiment", createModifyChemicalExperiment}},
        {4, {"Create new Biological Experiment", createNewBiologicalExperiment}},
        {5, {"Create copy of Biological Experiment", createCopyBiologicalExperiment}},
        {6, {"Create modified Biological Experiment", createModifyBiologicalExperiment}},
        {7, {"Create new Quantum Experiment", createNewQuantumExperiment}},
        {8, {"Create copy of Quantum Experiment", createCopyQuantumExperiment}},
        {9, {"Create modified Quantum Experiment", createModifyQuantumExperiment}},
        {10, {"Demonstrate polymorphism", demonstrationPolymorphism}}
    };

    int choice = 0;
    while (true) {
        cout << "Menu:\n";
        for (const auto& item : menu) {
            cout << "Task " << item.first << ". " << item.second.first << endl;
        }
        cout << "0. Exit\n";
        EnterNumber(cin, choice, "Enter menu option: ");
        if (choice == 0) {
            cout << "0 2025 Mitrohin\n";
            break;
        }
        cout << "\n-------------------Action:-------------------\n";
        if (menu.find(choice) != menu.end()) {
            menu[choice].second();
        } else {
            cout << "Invalid input.\n";
        }
        cout << endl;
    }
    return 0;
}