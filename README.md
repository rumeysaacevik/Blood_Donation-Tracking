 # Donation-Tracking

1) Main Purpose of the Project: 
The project aims to develop a Blood Donation Tracking System where donors can register, 
donate blood, and track their donation history. Admin functionalities include managing blood 
stock, donor information, and ensuring eligibility criteria.

2) Program Objects and Relationship: 
2.1) Donor Object: 
Attributes: - Name: Represents the full name of the donor. - Gender: Denotes the gender of the donor. -Date of Birth: Records the donor's date of birth. -Blood Group: Indicates the blood group of the donor. -Eligibility: Flags whether the donor is eligible for blood donation. -Donation Count: Keeps track of the number of blood donations made by the donor. 
Methods:  -save():Handles the process of donor registration and blood donation. -checkEligibility: Evaluates the donor's eligibility based on health-related questions. -display():Presents detailed information about the donor. -writeDonationInfoToFile():Records the donor's information in a file after each donation. 
Relationships: - BloodBank: Donors contribute to the blood stock managed by the BloodBank. -Admin: Donor information can be accessed by the Admin for monitoring and management. 
-Patient: Donors may have relationships with patients through blood donation. 
2.2. BloodBank Object: 
Attributes: - Blood Groups: An array representing the different blood groups and their respective stock 
levels. -Logs: Records of important actions such as stock updates. 
Methods: - displayBloodGroups(): Presents information about the available blood groups and their 
stock. -addBloodStock():Increases the stock of a specific blood group. -updateBloodStock():Modifies the quantity of a specific blood group in the stock. -deleteBloodStock():Removes a blood group from the stock. 
Relationships: - Donor: Blood donations from donors contribute to the BloodBank's stock. -Admin: BloodBank information is accessible to the Admin for monitoring and management. 
2.3. Admin Object: 
Attributes: - Username and Password: Credentials for secure Admin login. - Patient Database: Stores information about registered patients. 
Methods: -displayBloodStock():Allows the Admin to view the current blood stock. -addBloodStock():Enables the Admin to increase the stock of a specific blood group. -updateBloodStock():Permits the Admin to modify the quantity of a specific blood group in 
the stock. -deleteBloodStock():Allows the Admin to remove a blood group from the stock. -loginPatient():Validates patient login credentials. -registerPatient():Facilitates the registration process for new patients. 
Relationships: -Donor: Admin oversees and manages donor information -BloodBank: Admin has control over blood stock management. -Patient: Admin handles patient registrations and login validations.

3) Rules:
4) 
3.1-)Donors must provide necessary information during registration.
   
3.2-)Admin can manage blood stock, donor information, and patient registrations. 

3.3-)Eligibility checks ensure donors meet health criteria for blood donation. 

3.4-)The system tracks donor information, blood groups, and donation history. 

3.5-)Patients can register, log in, and access their information
