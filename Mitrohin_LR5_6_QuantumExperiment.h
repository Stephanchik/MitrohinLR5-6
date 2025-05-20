#ifndef _MITROHIN_LR5_6_QUANTUMEXPERIMENT_H
#define _MITROHIN_LR5_6_QUANTUMEXPERIMENT_H

#include "Mitrohin_LR5_6_Experiment.h"
#include <string>
#include <iostream>

using namespace std;

class QuantumSimulator {
protected:
    virtual string getSimulationParams() const { return "QuantumSimulator params"; }
public:
    virtual ~QuantumSimulator() {}
};

class QuantumExperiment : public Experiment, public QuantumSimulator {
protected:
    int qubits;
    double entanglementLevel;
    ostream& print(ostream& myostream) const override;
    istream& input(istream& myistream) override;

public:
    QuantumExperiment();
    QuantumExperiment(const QuantumExperiment& other);
    QuantumExperiment(const string& id);
    virtual ~QuantumExperiment();
    void run() const override;
    string getExperimentType() const override;
    bool validate() const override;
    void optimizeCoherence();
    double operator[](const string& param) const;
    int getQubits() const { return qubits; }
    void setQubits(int q) { qubits = q; }
    double getEntanglementLevel() const { return entanglementLevel; }
    void setEntanglementLevel(double el) { entanglementLevel = el; }
};

QuantumExperiment::QuantumExperiment() : qubits(0), entanglementLevel(0) {
    cout << "Default constructor QuantumExperiment\n";
}

QuantumExperiment::QuantumExperiment(const QuantumExperiment& other) : Experiment(other), QuantumSimulator(), qubits(other.qubits), entanglementLevel(other.entanglementLevel) {
    cout << "Copy constructor QuantumExperiment\n";
}

QuantumExperiment::QuantumExperiment(const string& id) : Experiment(id), qubits(0), entanglementLevel(0) {
    cout << "Transformation constructor QuantumExperiment\n";
}

QuantumExperiment::~QuantumExperiment() {
    cout << "QuantumExperiment destroyed: " << experimentId << endl;
}

ostream& QuantumExperiment::print(ostream& myostream) const {
    myostream << "QuantumExperiment [ID: " << experimentId << ", Duration: " << duration
              << ", Risk Level: " << riskLevel << ", Qubits: " << qubits
              << ", Entanglement Level: " << entanglementLevel << "]\n";
    return myostream;
}

istream& QuantumExperiment::input(istream& myistream) {
    Experiment::input(myistream);
    EnterNumber(myistream, qubits, "Enter number of qubits");
    EnterDouble(myistream, entanglementLevel, "Enter entanglement level (0-1)");
    return myistream;
}

void QuantumExperiment::run() const {
    cout << "Calibrating qubits: " << qubits << endl;
}

string QuantumExperiment::getExperimentType() const {
    return "Quantum";
}

bool QuantumExperiment::validate() const {
    return Experiment::validate() && entanglementLevel >= 0.7 && entanglementLevel <= 1.0;
}

void QuantumExperiment::optimizeCoherence() {
    cout << "Coherence time increased for " << qubits << " qubits\n";
}

double QuantumExperiment::operator[](const string& param) const {
    if (param == "qubits") return qubits;
    if (param == "entanglement") return entanglementLevel;
    throw runtime_error("Invalid parameter");
}

#endif // _MITROHIN_LR5_6_QUANTUMEXPERIMENT_H