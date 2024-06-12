#include "admin.h"
#include "patient.h"  
#include "blood_bank.h"
#include <iostream>
#include <fstream>


Admin::Admin(const std::string& n, const std::string& s)
    : Person(n, s, 0) {}

void Admin::displayBloodStock() {
    std::cout << "Blood Stock:\n";
    for (int i = 0; i < 8; ++i) {
        std::cout << BloodBank::getBloodGroupName(i) << ": " << BloodBank::getBloodStock(i) << "\n";//BloodBank sınıfının getBloodGroupName ve getBloodStock fonksiyonları
    }
    std::cout << "\n";
}


void Admin::addBloodStock() {
    std::cout << "Current Blood Stock:\n";
    for (int i = 0; i < 8; ++i) {
        std::cout << i << ". " << BloodBank::getBloodGroupName(i) << " (" << BloodBank::getBloodStock(i) << " packets)\n";
    }

    int group;
    int quantity;

    std::cout << "Enter blood group index (0-7): ";
    std::cin >> group;

    if (group < 0 || group > 7) {
        std::cout << "Invalid blood group index.\n";
        return;
    }

    std::cout << "Enter quantity to add: ";
    std::cin >> quantity;

    BloodBank::addBloodStock(group, quantity);

    std::cout << "Blood stock updated.\n";
}

void Admin::updateBloodStock() {
    int group;//eski
    int newQuantity;//yeni

    BloodBank::displayBloodGroups();
    std::cout << "Enter blood group index (0-7): ";
    std::cin >> group;

    if (group < 0 || group > 7) {
        std::cout << "Invalid blood group index.\n";
        return;
    }

    std::cout << "Enter new quantity: ";
    std::cin >> newQuantity;

    BloodBank::updateBloodStock(group, newQuantity);

    std::cout << "Blood stock updated.\n";
}

void Admin::deleteBloodStock() {
    int group;

    std::cout << "Enter blood group index (0-7): ";
    std::cin >> group;

    if (group < 0 || group > 7) {
        std::cout << "Invalid blood group index.\n";
        return;
    }

    BloodBank::deleteBloodStock(group);

    std::cout << "Blood stock deleted.\n";
}

bool Admin::loginPatient(int identityNumber, const std::string& password) {
    std::ifstream file("patients.txt");
    int idFromFile;
    std::string name, surname, passwordFromFile;
    int phone_no;

    while (file >> name >> surname >> idFromFile >> phone_no >> passwordFromFile) {
        if (idFromFile == identityNumber && passwordFromFile == password) {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

void Admin::registerPatient() {
    Patient* newPatient = new Patient; 
    
    std::cout << "Enter name: ";
    std::cin >> newPatient->name;

    std::cout << "Enter surname: ";
    std::cin >> newPatient->surname;

    std::cout << "Enter ID: ";
    std::cin >> newPatient->id;

    std::cout << "Enter phone number: ";
    std::cin >> newPatient->phone_no;

    std::cout << "Enter password: ";
    std::cin >> newPatient->password;

    std::ofstream file("patients.txt", std::ios::app);
    file << newPatient->name << ' ' << newPatient->surname << ' '
         << newPatient->id << ' ' << newPatient->phone_no << ' ' << newPatient->password << '\n';

    std::cout << "Patient registered successfully.\n"
              "---------------------------------------------\n";
    file.close();

    delete newPatient;
}


bool Admin::login() {
   const std::string correctUsername = "admin";
        const std::string correctPassword = "admin123";
        int maxAttempts = 3;
        
        while (maxAttempts > 0) {
            std::string username, password;

            std::cout << "Enter admin username: ";
            std::cin >> username;

            std::cout << "Enter admin password: ";
            std::cin >> password;

            if (username == correctUsername && password == correctPassword) {
                std::cout << "Admin login successful!\n";
                return true;
            } else {
                std::cout << "Admin login failed. Incorrect username or password. "
                          << maxAttempts - 1 << " attempts remaining.\n";
                maxAttempts--;
            }
        }

        std::cout << "Maximum login attempts reached. Exiting program.\n";
        return false;
    }

