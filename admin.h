#ifndef ADMIN_H
#define ADMIN_H

#include "person.h"

class Admin : public Person {
public:
    Admin(const std::string& n, const std::string& s);


    void displayBloodStock();
    void addBloodStock();
    void updateBloodStock();
    void deleteBloodStock();
    bool loginPatient(int identityNumber, const std::string& password);
    void registerPatient();
    bool login();  


};

#endif  
