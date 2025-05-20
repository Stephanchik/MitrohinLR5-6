#ifndef _MITROHIN_LR5_6_EXPERIMENTS_METHODS_H
#define _MITROHIN_LR5_6_EXPERIMENTS_METHODS_H

#include "Mitrohin_LR5_6_ChemicalExperiment.h"
#include "Mitrohin_LR5_6_BiologicalExperiment.h"
#include "Mitrohin_LR5_6_QuantumExperiment.h"
#include <vector>
#include <memory>
#include <iostream>

using namespace std;

map<string, unique_ptr<Experiment>> experimentsMap;

void showExperiments() {
    if (experimentsMap.empty()) {
        cerr << "Error! No experiments in the system!\n";
        return;
    }
    for (const auto& pair : experimentsMap) {
        cout << pair.first << ": " << *pair.second << endl;
    }
}

Experiment* getExperiment(const string& type) {
    showExperiments();
    string id;
    EnterString(cin, id, "Enter " + type + " ID to select");
    auto it = experimentsMap.find(id);
    if (it == experimentsMap.end()) {
        cerr << "Error! Invalid ID\n";
        return nullptr;
    }
    return it->second.get();
}

void createNewChemicalExperiment() {
    auto obj = make_unique<ChemicalExperiment>();
    cin >> *obj;
    if (!obj->validate()) {
        cerr << "Invalid Chemical Experiment data!\n";
        return;
    }
    experimentsMap[obj->getExperimentId()] = move(obj);
}

void createCopyChemicalExperiment() {
    ChemicalExperiment* source = dynamic_cast<ChemicalExperiment*>(getExperiment("Chemical Experiment"));
    if (!source) {
        cerr << "Error! Not a Chemical Experiment!\n";
        return;
    }
    auto copy = make_unique<ChemicalExperiment>(*source);
    experimentsMap[copy->getExperimentId() + "_copy"] = move(copy);
}

void createModifyChemicalExperiment() {
    string id, substances;
    EnterString(cin, id, "Enter new Chemical Experiment ID");
    EnterString(cin, substances, "Enter substances");
    auto obj = make_unique<ChemicalExperiment>(id, substances);
    if (!obj->validate()) {
        cerr << "Invalid Chemical Experiment data!\n";
        return;
    }
    experimentsMap[obj->getExperimentId()] = move(obj);
}

void createNewBiologicalExperiment() {
    auto obj = make_unique<BiologicalExperiment>();
    cin >> *obj;
    if (!obj->validate()) {
        cerr << "Invalid Biological Experiment data!\n";
        return;
    }
    experimentsMap[obj->getExperimentId()] = move(obj);
}

void createCopyBiologicalExperiment() {
    BiologicalExperiment* source = dynamic_cast<BiologicalExperiment*>(getExperiment("Biological Experiment"));
    if (!source) {
        cerr << "Error! Not a Biological Experiment!\n";
        return;
    }
    auto copy = make_unique<BiologicalExperiment>(*source);
    experimentsMap[copy->getExperimentId() + "_copy"] = move(copy);
}

void createModifyBiologicalExperiment() {
    string id;
    EnterString(cin, id, "Enter new Biological Experiment ID");
    auto obj = make_unique<BiologicalExperiment>(id);
    if (!obj->validate()) {
        cerr << "Invalid Biological Experiment data!\n";
        return;
    }
    experimentsMap[obj->getExperimentId()] = move(obj);
}

void createNewQuantumExperiment() {
    auto obj = make_unique<QuantumExperiment>();
    cin >> *obj;
    if (!obj->validate()) {
        cerr << "Invalid Quantum Experiment data!\n";
        return;
    }
    experimentsMap[obj->getExperimentId()] = move(obj);
}

void createCopyQuantumExperiment() {
    QuantumExperiment* source = dynamic_cast<QuantumExperiment*>(getExperiment("Quantum Experiment"));
    if (!source) {
        cerr << "Error! Not a Quantum Experiment!\n";
        return;
    }
    auto copy = make_unique<QuantumExperiment>(*source);
    experimentsMap[copy->getExperimentId() + "_copy"] = move(copy);
}

void createModifyQuantumExperiment() {
    string id;
    EnterString(cin, id, "Enter new Quantum Experiment ID");
    auto obj = make_unique<QuantumExperiment>(id);
    if (!obj->validate()) {
        cerr << "Invalid Quantum Experiment data!\n";
        return;
    }
    experimentsMap[obj->getExperimentId()] = move(obj);
}

void demonstrationPolymorphism() {
    for (const auto& pair : experimentsMap) {
        cout << *pair.second;
        pair.second->run();
        cout << "Experiment Type: " << pair.second->getExperimentType() << endl;
        if (auto chem = dynamic_cast<ChemicalExperiment*>(pair.second.get())) {
            chem->addCatalyst();
        } else if (auto bio = dynamic_cast<BiologicalExperiment*>(pair.second.get())) {
            bio->sterilize();
        } else if (auto quant = dynamic_cast<QuantumExperiment*>(pair.second.get())) {
            quant->optimizeCoherence();
            cout << "Qubits: " << quant->operator[]("qubits") << endl;
        }
        cout << "-------------------\n";
    }
}

#endif // _MITROHIN_LR5_6_EXPERIMENTS_METHODS_H