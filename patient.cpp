#include "patient.h"
#include "blood_bank.h"
#include <iostream>
#include <fstream>




void Patient::display() {
    std::cout << "Patient Information:" << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Surname: " << surname << std::endl;
    std::cout << "Gender: " << gender << std::endl;
    std::cout << "Date of Birth: " << date.day << "/" << date.month << "/" << date.year << std::endl;
    std::cout << "Blood Group: " << blood_group << std::endl;
    std::cout << "Phone Number: " << phone_no << std::endl;

    std::cout << "---------------------------------------------\n";
}


bool Patient::login() {
    int enteredId;
    std::wstring enteredPassword;

    std::wcout << "Enter your ID: ";
    std::wcin >> enteredId;

    std::wcout << "Enter your password: ";
    std::wcin >> enteredPassword;

    std::wifstream file("patients.txt", std::ios::in | std::ios::binary);
    int idFromFile;
    std::wstring nameFromFile, surnameFromFile, passwordFromFile;
    int phone_noFromFile;

    bool found = false;

    while (file >> nameFromFile >> surnameFromFile >> idFromFile >> phone_noFromFile >> passwordFromFile) {
        if (idFromFile == enteredId && passwordFromFile == enteredPassword) {
            found = true;
            break;
        }
    }

    file.close();

    if (found) {
        std::wcout << "Login successful!\n";
        return true;
    } else {
        std::wcout << "Patient record not found. Login failed.\n";
        return false;
    }
}
void Patient::searchForBloodGroup() {//belirli bir kan grubu için kan arama işlemi yapma fonksiyonu
    int bloodGroupChoice;
    int requestedPackets;

    std::cout << "\nEnter the type of blood group you are looking for:" << std::endl;
    std::cout << "0 = A positive\n1 = O positive\n2 = B positive\n3 = AB positive\n"
              << "4 = A negative\n5 = O negative\n6 = B negative\n7 = AB negative\n";
    std::cin >> bloodGroupChoice;

    std::cout << "Enter the number of blood packets you need: ";
    std::cin >> requestedPackets;

    
    if (BloodBank::BloodGroup::bloodgroup[bloodGroupChoice] >= requestedPackets) {
        BloodBank::BloodGroup::bloodgroup[bloodGroupChoice] -= requestedPackets;
        std::cout << requestedPackets << " blood packets requested. Your request has been processed.\n";
    } else {
        std::cout << "Sorry, the requested blood group is not available in sufficient quantity.\n";
    }
}

