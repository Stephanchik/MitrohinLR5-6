#ifndef _MITROHIN_LR5_6_BIOLOGICALEXPERIMENT_H
#define _MITROHIN_LR5_6_BIOLOGICALEXPERIMENT_H

#include "Mitrohin_LR5_6_Experiment.h"
#include <string>
#include <iostream>

using namespace std;

class BiologicalExperiment final : public Experiment {
protected:
    string organismType;
    bool isContained;
    ostream& print(ostream& myostream) const override;
    istream& input(istream& myistream) override;

public:
    BiologicalExperiment();
    BiologicalExperiment(const BiologicalExperiment& other);
    BiologicalExperiment(const string& id);
    virtual ~BiologicalExperiment();
    void run() const override;
    string getExperimentType() const override;
    bool validate() const override;
    void sterilize();
    BiologicalExperiment& operator+=(const string& newOrganism);
    string getOrganismType() const { return organismType; }
    void setOrganismType(const string& ot) { organismType = ot; }
    bool getIsContained() const { return isContained; }
    void setIsContained(bool ic) { isContained = ic; }
};

BiologicalExperiment::BiologicalExperiment() : organismType("Unknown"), isContained(true) {
    cout << "Default constructor BiologicalExperiment\n";
}

BiologicalExperiment::BiologicalExperiment(const BiologicalExperiment& other) : Experiment(other), organismType(other.organismType), isContained(other.isContained) {
    cout << "Copy constructor BiologicalExperiment\n";
}

BiologicalExperiment::BiologicalExperiment(const string& id) : Experiment(id), organismType("Unknown"), isContained(true) {
    cout << "Transformation constructor BiologicalExperiment\n";
}

BiologicalExperiment::~BiologicalExperiment() {
    cout << "BiologicalExperiment destroyed: " << experimentId << endl;
}

ostream& BiologicalExperiment::print(ostream& myostream) const {
    myostream << "BiologicalExperiment [ID: " << experimentId << ", Duration: " << duration
              << ", Risk Level: " << riskLevel << ", Organism Type: " << organismType
              << ", Contained: " << (isContained ? "Yes" : "No") << "]\n";
    return myostream;
}

istream& BiologicalExperiment::input(istream& myistream) {
    Experiment::input(myistream);
    EnterString(myistream, organismType, "Enter organism type");
    string contained;
    EnterString(myistream, contained, "Is contained? (yes/no)");
    isContained = (contained == "yes" || contained == "Yes");
    return myistream;
}

void BiologicalExperiment::run() const {
    cout << "Cultivating: " << organismType << endl;
}

string BiologicalExperiment::getExperimentType() const {
    return "Biological";
}

bool BiologicalExperiment::validate() const {
    return Experiment::validate() && isContained;
}

void BiologicalExperiment::sterilize() {
    cout << "Equipment sterilized for " << organismType << endl;
}

BiologicalExperiment& BiologicalExperiment::operator+=(const string& newOrganism) {
    organismType += ", " + newOrganism;
    return *this;
}

#endif // _MITROHIN_LR5_6_BIOLOGICALEXPERIMENT_H