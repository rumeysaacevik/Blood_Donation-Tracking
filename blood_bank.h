#ifndef BLOOD_BANK_H
#define BLOOD_BANK_H

#include <string>

class BloodBank {
public:
static int totalDonation;
static int getBloodGroupIndex(const std::string& bloodGroup); 
  
    class BloodGroup {
    public:
        std::string name;  
        int stock;         

        BloodGroup(const std::string& groupName, int initialStock)
            : name(groupName), stock(initialStock) {}
        static int bloodgroup[8];
    };


    static BloodGroup** bloodGroups;
    static int groupCount;


    static void initializeBloodGroups();

    static void displayBloodStock();

    static std::string getBloodGroupName(int index);

    static int getBloodStock(int index);
    static void addBloodStock(int index, int quantity);
    static void updateBloodStock(int index, int newQuantity);
    static void deleteBloodStock(int index);
    static void displayBloodGroups();
    static bool checkBloodStock(const std::string &bloodGroup, int requestedAmount);
    ~BloodBank();
};

#endif 
