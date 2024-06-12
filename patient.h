#ifndef PATIENT_H
#define PATIENT_H

#include "blood_bank.h"

class Patient {
public:
    int c;
    int x;
    char name[50];
    char surname[50];
    char gender[15];
    char password[50];
    int id; 
    struct Date {
        int day;
        int month;
        int year;
    } date;
    char blood_group[20];
    int phone_no; 

public:
    void save();
    void display();  
    bool login();
    void searchForBloodGroup();
};
#endif