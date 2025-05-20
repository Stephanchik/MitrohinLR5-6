#ifndef _MITROHIN_LR5_6_CHEMICALEXPERIMENT_H
#define _MITROHIN_LR5_6_CHEMICALEXPERIMENT_H

#include "Mitrohin_LR5_6_Experiment.h"
#include <string>
#include <iostream>

using namespace std;

class ChemicalExperiment : public Experiment {
protected:
    string substances;
    double temperature;
    ostream& print(ostream& myostream) const override;
    istream& input(istream& myistream) override;

public:
    ChemicalExperiment();
    ChemicalExperiment(const ChemicalExperiment& other);
    ChemicalExperiment(const string& id, const string& subs);
    virtual ~ChemicalExperiment();
    void run() const override;
    string getExperimentType() const override;
    bool validate() const override;
    void addCatalyst();
    ChemicalExperiment* operator+(const ChemicalExperiment& other) const;
    string getSubstances() const { return substances; }
    void setSubstances(const string& s) { substances = s; }
    double getTemperature() const { return temperature; }
    void setTemperature(double t) { temperature = t; }
};

ChemicalExperiment::ChemicalExperiment() : substances("Unknown"), temperature(0) {
    cout << "Default constructor ChemicalExperiment\n";
}

ChemicalExperiment::ChemicalExperiment(const ChemicalExperiment& other) : Experiment(other), substances(other.substances), temperature(other.temperature) {
    cout << "Copy constructor ChemicalExperiment\n";
}

ChemicalExperiment::ChemicalExperiment(const string& id, const string& subs) : Experiment(id), substances(subs), temperature(0) {
    cout << "Transformation constructor ChemicalExperiment\n";
}

ChemicalExperiment::~ChemicalExperiment() {
    cout << "ChemicalExperiment destroyed: " << experimentId << endl;
}

ostream& ChemicalExperiment::print(ostream& myostream) const {
    myostream << "ChemicalExperiment [ID: " << experimentId << ", Duration: " << duration
              << ", Risk Level: " << riskLevel << ", Substances: " << substances
              << ", Temperature: " << temperature << "C]\n";
    return myostream;
}

istream& ChemicalExperiment::input(istream& myistream) {
    Experiment::input(myistream);
    EnterString(myistream, substances, "Enter substances");
    EnterDouble(myistream, temperature, "Enter temperature (C)");
    return myistream;
}

void ChemicalExperiment::run() const {
    cout << "Heating to " << temperature << "C. Reaction: " << substances << endl;
}

string ChemicalExperiment::getExperimentType() const {
    return "Chemical";
}

bool ChemicalExperiment::validate() const {
    return Experiment::validate() && temperature <= 500;
}

void ChemicalExperiment::addCatalyst() {
    cout << "Catalyst added to " << substances << endl;
}

ChemicalExperiment* ChemicalExperiment::operator+(const ChemicalExperiment& other) const {
    ChemicalExperiment* result = new ChemicalExperiment(experimentId + "&" + other.experimentId, substances + ", " + other.substances);
    result->temperature = (temperature + other.temperature) / 2;
    return result;
}

#endif // _MITROHIN_LR5_6_CHEMICALEXPERIMENT_H