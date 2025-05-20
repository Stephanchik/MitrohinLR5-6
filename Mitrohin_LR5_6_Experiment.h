#ifndef _MITROHIN_LR5_6_EXPERIMENT_H
#define _MITROHIN_LR5_6_EXPERIMENT_H

#include "Mitrohin_LR5_6_Experiments_def.h"
#include <string>
#include <iostream>

using namespace std;

class Experiment {
protected:
    string experimentId;
    double duration;
    int riskLevel;
    virtual ostream& print(ostream& myostream) const = 0;
    virtual istream& input(istream& myistream);

public:
    Experiment();
    Experiment(const Experiment& other);
    Experiment(const string& id);
    virtual ~Experiment();
    virtual void run() const = 0;
    virtual string getExperimentType() const = 0;
    virtual bool validate() const;
    bool operator==(const Experiment& other) const;
    string getExperimentId() const { return experimentId; }
    void setExperimentId(const string& id) { experimentId = id; }
    double getDuration() const { return duration; }
    void setDuration(double d) { duration = d; }
    int getRiskLevel() const { return riskLevel; }
    void setRiskLevel(int r) { riskLevel = r; }

    friend ostream& operator<<(ostream& myostream, const Experiment& exp) {
        return exp.print(myostream);
    }
    friend istream& operator>>(istream& myistream, Experiment& exp) {
        return exp.input(myistream);
    }
};

Experiment::Experiment() : experimentId("Unknown"), duration(0), riskLevel(1) {
    cout << "Default constructor Experiment\n";
}

Experiment::Experiment(const Experiment& other) : experimentId(other.experimentId), duration(other.duration), riskLevel(other.riskLevel) {
    cout << "Copy constructor Experiment\n";
}

Experiment::Experiment(const string& id) : experimentId(id), duration(0), riskLevel(1) {
    cout << "Transformation constructor Experiment\n";
}

Experiment::~Experiment() {
    cout << "Experiment destroyed: " << experimentId << endl;
}

istream& Experiment::input(istream& myistream) {
    EnterString(myistream, experimentId, "Enter experiment ID");
    EnterDouble(myistream, duration, "Enter duration (hours)");
    EnterNumber(myistream, riskLevel, "Enter risk level (1-5)");
    return myistream;
}

bool Experiment::validate() const {
    return riskLevel >= 1 && riskLevel <= 3;
}

bool Experiment::operator==(const Experiment& other) const {
    return experimentId == other.experimentId;
}

#endif // _MITROHIN_LR5_6_EXPERIMENT_H