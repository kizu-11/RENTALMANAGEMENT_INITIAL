#ifndef RENTALMANAGEMENT_H
#define RENTALMANAGEMENT_H

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <ctime>
using namespace std;

class RentalManagement {
private:
    struct RentalAgreement {
        string itemName;      // Item name
        string rentedBy;      // Name of the renter
        time_t rentDate;      // Rental start date
        int duration;         // Rental duration in days
    };

    const string DATA_FILE;                // File for storing rental agreements
    vector<RentalAgreement> rentalAgreements;  // List of rental agreements

    void loadRentalAgreementsFromFile();     // Load rental agreements from the file
    void saveRentalAgreementsToFile();       // Save rental agreements to the file
    time_t getCurrentDate();                 // Get the current system date
    string formatDate(time_t date);          // Convert time_t to a readable date string

public:
    RentalManagement();                      // Constructor to initialize and load data
    void displayRentalAgreements();          // Display all rental agreements
    void checkExpiredRentals();              // Check and update items with expired rentals
    void displayRentalHistory();             // Show all rental agreements from the file
};

#endif
