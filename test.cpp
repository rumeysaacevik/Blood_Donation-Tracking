#include <iostream>
#include "donor.h"
#include "admin.h"
#include "blood_bank.h"
#include "patient.h"
#include "admin.cpp"
#include "blood_bank.cpp"
#include "donor.cpp"
#include "patient.cpp"

int main()
{
    Admin admin("admin", "admin123");
    initializeBloodBank();
    int c;
    bool exitProgram = false;

    while (!exitProgram)
    {
        std::cout << "\nMain Menu:\n"
                     "1. Admin\n"
                     "2. Donor\n"
                     "3. Patient\n"
                     "4. Exit\n"
                     "Enter your choice: ";
        std::cin >> c;

        switch (c)
        {
        case 1:
        {
            if (admin.login())
            {
                int adminChoice;
                do
                {
                    std::cout << "\nAdmin Menu:\n"
                                 "1. Display Blood Stock\n"
                                 "2. Add Blood Stock\n"
                                 "3. Update Blood Stock\n"
                                 "4. Delete Blood Stock\n"
                                 "5. Register Patient\n"
                                 "6. Exit\n"
                                 "Enter your choice: ";
                    std::cin >> adminChoice;

                    switch (adminChoice)
                    {
                    case 1:
                        admin.displayBloodStock();
                        break;

                    case 2:
                        admin.addBloodStock();
                        break;

                    case 3:
                        admin.updateBloodStock();
                        break;

                    case 4:
                        admin.deleteBloodStock();
                        break;

                    case 5:
                        admin.registerPatient();
                        break;

                    case 6:
                        exitProgram = true;
                        break;

                    default:
                        std::cout << "Invalid choice.\n";
                        break;
                    }

                    if (adminChoice != 6)
                    {
                        std::cout << "\nDo you want to perform another operation? (1 for yes, 0 for no): ";
                        std::cin >> adminChoice;
                    }

                } while (adminChoice == 1);
            }
            break;
        }

        case 2:
        {
            Donor donor;
            donor.save();
            donor.writeDonationInfoToFile();
            break;
        }

        case 3:
        {
            Patient patient;
            bool loggedIn = false;

            do
            {
                loggedIn = patient.login();
                if (!loggedIn)
                {
                    std::cout << "Login failed. Please check your credentials and try again.\n";
                }
            } while (!loggedIn);

            int patientChoice;
            do
            {
                std::cout << "\nPatient Menu:\n"
                             "1. Search for Blood Group\n"
                             "2. Display Information\n"
                             "3. Exit\n"
                             "Enter your choice: ";
                std::cin >> patientChoice;

                switch (patientChoice)
                {
                case 1:
                    patient.searchForBloodGroup();
                    break;

                case 2:
                    patient.display();
                    break;

                case 3:
                    exitProgram = true;
                    break;

                default:
                    std::cout << "Invalid choice.\n";
                    break;
                }

                if (patientChoice != 3)
                {
                    std::cout << "\nDo you want to perform another operation? (1 for yes, 0 for no): ";
                    std::cin >> patientChoice;
                }

            } while (patientChoice == 1);
            break;
        }

        case 4:
            exitProgram = true;
            break;

        default:
            std::cout << "Invalid choice.\n";
            break;
        }
    }

    std::cout << "Exiting program.\n";
    return 0;
}