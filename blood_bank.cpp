#include "blood_bank.h"
#include <iostream>

int BloodBank::BloodGroup::bloodgroup[8] = {10, 20, 15, 5, 8, 12, 7, 3};//bloodgroups stok özelliği
BloodBank::BloodGroup** BloodBank::bloodGroups = nullptr;//başlangıcta bir şey ifade etmiyor.
int BloodBank::groupCount = 0;

void BloodBank::initializeBloodGroups() {
    bloodGroups = new BloodGroup*[8];

    bloodGroups[0] = new BloodGroup{"A positive", 0};
    bloodGroups[1] = new BloodGroup{"O positive", 0};
    bloodGroups[2] = new BloodGroup{"B positive", 0};
    bloodGroups[3] = new BloodGroup{"AB positive", 0};
    bloodGroups[4] = new BloodGroup{"A negative", 0};
    bloodGroups[5] = new BloodGroup{"O negative", 0};
    bloodGroups[6] = new BloodGroup{"B negative", 0};
    bloodGroups[7] = new BloodGroup{"AB negative", 0};

    groupCount = 8;
}

void BloodBank::displayBloodStock() {
    for (int i = 0; i < groupCount; ++i) {
        std::cout << bloodGroups[i]->name << ": " << bloodGroups[i]->stock << std::endl;
    }
}

std::string BloodBank::getBloodGroupName(int index) {
    switch (index) {
        case 0:
            return "A positive";
        case 1:
            return "O positive";
        case 2:
            return "B positive";
        case 3:
            return "AB positive";
        case 4:
            return "A negative";
        case 5:
            return "O negative";
        case 6:
            return "B negative";
        case 7:
            return "AB negative";
        default:
            return "Invalid blood group";
    }
}

int BloodBank::getBloodStock(int index) {
    if (index >= 0 && index < 8) {
        return bloodGroups[index]->stock;
    } else {
        return -1; // Invalid numberrr
    }
}

void BloodBank::addBloodStock(int index, int quantity) {
    if (index >= 0 && index < 8 && quantity > 0) {
        bloodGroups[index]->stock += quantity;
    }
}

void BloodBank::updateBloodStock(int index, int newQuantity) {
    if (index >= 0 && index < 8 && newQuantity >= 0) {
        bloodGroups[index]->stock = newQuantity;
    }
}

void BloodBank::deleteBloodStock(int index) {
    if (index >= 0 && index < 8) {
        bloodGroups[index]->stock = 0;
    }
}

BloodBank::~BloodBank() {//BloodGroup nesnelerini ve bloodGroups dizisini temizler
    for (int i = 0; i < groupCount; ++i) {
        delete bloodGroups[i];
    }
    delete[] bloodGroups;
}
void initializeBloodBank() {
    BloodBank::initializeBloodGroups();
}
void BloodBank::displayBloodGroups() {
    std::cout << "Blood Groups:\n"
              << "0 = A positive\n1 = O positive\n2 = B positive\n3 = AB positive\n"
              << "4 = A negative\n5 = O negative\n6 = B negative\n7 = AB negative\n";
}

bool BloodBank::checkBloodStock(const std::string& bloodGroup, int requestedAmount) {
    int index = getBloodGroupIndex(bloodGroup);
    if (index != -1 && BloodGroup::bloodgroup[index] >= requestedAmount) {
        BloodGroup::bloodgroup[index] -= requestedAmount;
        return true;  
    } else {
        std::cout << "Requested blood group not available in stock or insufficient quantity.\n";
        return false;  
    }
}
int BloodBank::getBloodGroupIndex(const std::string& bloodGroup) {
    for (int i = 0; i < groupCount; ++i) {
        if (bloodGroups[i]->name == bloodGroup) {
            return i;
        }
    }
    return -1; 
}