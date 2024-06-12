#include <iostream>
#include <limits> 
#include "blood_bank.h"
#include "donor.h"

void Donor::save()//bağışçıdan gerekli bilgileri alır ve kan bağışı yapılıp yapılamayacağını değerlendirir.
{
    std::cout << "Enter your name and surname: ";
    std::cin.ignore(); 
    std::getline(std::cin, name);

    std::cout << "Enter your gender: ";
    std::getline(std::cin, gender); 

    std::cout << "Enter date (DD MM YY): ";
    std::cin >> date.day >> date.month >> date.year;

    BloodBank::displayBloodGroups();

    int bloodGroupIndex;
    do
    {
        std::cout << "Enter the type of blood group you are donating (0-7): ";
        std::cin >> bloodGroupIndex;
    } while (bloodGroupIndex < 0 || bloodGroupIndex > 7);

    std::cout << "How many packets of blood are you donating: ";
    std::cin >> x;

    std::cout << "Are you eligible for blood donation?\n";
    isEligible = checkEligibility();

    if (isEligible)
    {
        BloodBank::bloodGroups[bloodGroupIndex]->stock += x;
        char ch;
        std::cout << "Do you want your information to be displayed now (Y/N): ";
        std::cin >> ch;

        if (ch == 'Y' || ch == 'y')
        {
            display();
        }
    }
    else
    {
        std::cout << "Sorry, you are not eligible for blood donation.\n";
    }
}

bool Donor::checkEligibility()
{
    char answer;
    std::cout << "Do you smoke? (Y/N): ";
    std::cin >> answer;
    if (answer == 'Y' || answer == 'y')
    {
        std::cout << "Smokers are not eligible for blood donation.\n";
        return false;
    }

    std::cout << "Have you had a tattoo in the last 6 months? (Y/N): ";
    std::cin >> answer;
    if (answer == 'Y' || answer == 'y')
    {
        std::cout << "Individuals with recent tattoos are not eligible for blood donation.\n";
        return false;
    }

    std::cout << "Is there any medication you use regularly? (Y/N): ";
    std::cin >> answer;
    if (answer == 'Y' || answer == 'y')
    {
        std::cout << "Individuals using medication regularly are not eligible for blood donation.\n";
        return false;
    }

    std::cout << "Is there anyone in your family who has or has had cancer? (Y/N): ";
    std::cin >> answer;
    if (answer == 'Y' || answer == 'y')
    {
        std::cout << "Individuals with a family history of cancer are not eligible for blood donation.\n";
        return false;
    }

    return true;
}

void Donor::display()
{
    std::cout << "\nDonor Information:\n";
    std::cout << "Name: " << name << std::endl;
    std::cout << "Gender: " << gender << std::endl;
    std::cout << "Date (DD MM YY): " << date.day << " " << date.month << " " << date.year << std::endl;
    std::cout << "Blood group: ";

    switch (c)
    {
    case 0:
        std::cout << "A positive" << std::endl;
        break;
    case 1:
        std::cout << "O positive" << std::endl;
        break;
    case 2:
        std::cout << "B positive" << std::endl;
        break;
    case 3:
        std::cout << "AB positive" << std::endl;
        break;
    case 4:
        std::cout << "A negative" << std::endl;
        break;
    case 5:
        std::cout << "O negative" << std::endl;
        break;
    case 6:
        std::cout << "B negative" << std::endl;
        break;
    case 7:
        std::cout << "AB negative" << std::endl;
        break;
    default:
        std::cout << "Invalid blood group" << std::endl;
    }

    std::cout << "Packets of blood: " << x << std::endl;
}

void Donor::writeDonationInfoToFile()
{
    std::ofstream file("donation_info.txt", std::ios::app);
    if (file.is_open())
    {
        file << "Name and Surname: " << name << "\n"
             << "Gender: " << gender << "\n"
             << "Date of Birth: " << date.day << " " << date.month << " " << date.year << "\n"
             << "Blood group: " << c << "\n"
             << "Packets of blood: " << x << "\n"
             << "Is Eligible: " << (isEligible ? "Yes" : "No") << "\n"
             << "---------------------------------------------\n";

        file.close();
    }
    else
    {
        std::cerr << "Unable to open file for writing donation information." << std::endl;
    }
}
