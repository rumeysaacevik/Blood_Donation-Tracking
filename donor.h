#ifndef DONOR_H
#define DONOR_H

#include <string>
#include "blood_bank.h"

class Donor {
public:
    int c;
    int x;
    std::string name;
    std::string gender;
    
    struct Date {
        int day;
        int month;
        int year;
    } date;

    std::string blood_group;
    long long phone_no;
    bool isEligible;

public:
    void save();
    void display();
    bool checkEligibility();
    int bloodGroupIndex;
    void writeDonationInfoToFile();
};

#endif 
