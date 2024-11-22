#include "RentalManagement.h"

RentalManagement::RentalManagement() : DATA_FILE("RentalAgreements.txt") {
    loadRentalAgreementsFromFile();
}

void RentalManagement::loadRentalAgreementsFromFile() {
    ifstream file(DATA_FILE);
    if (file.is_open()) {
        string itemName, rentedBy;
        time_t rentDate;
        int duration;

        while (getline(file, itemName)) {
            getline(file, rentedBy);
            file >> rentDate >> duration;
            file.ignore();  // To ignore the newline character after the duration

            RentalAgreement agreement = { itemName, rentedBy, rentDate, duration };
            rentalAgreements.push_back(agreement);
        }
        file.close();
    }
}

void RentalManagement::saveRentalAgreementsToFile() {
    ofstream file(DATA_FILE);
    if (file.is_open()) {
        for (const auto& agreement : rentalAgreements) {
            file << agreement.itemName << endl;
            file << agreement.rentedBy << endl;
            file << agreement.rentDate << endl;
            file << agreement.duration << endl;
        }
        file.close();
    }
}

time_t RentalManagement::getCurrentDate() {
    return time(0);  // Get the current system time
}

string RentalManagement::formatDate(time_t date) {
    char buffer[20];
    strftime(buffer, sizeof(buffer), "%Y-%m-%d", localtime(&date));
    return string(buffer);
}

void RentalManagement::displayRentalAgreements() {
    if (rentalAgreements.empty()) {
        cout << "No rental agreements found.\n";
        return;
    }

    cout << "\nRental Agreements:\n";
    for (size_t i = 0; i < rentalAgreements.size(); ++i) {
        cout << i + 1 << ". Item: " << rentalAgreements[i].itemName
             << " | Rented by: " << rentalAgreements[i].rentedBy
             << " | Rent Date: " << formatDate(rentalAgreements[i].rentDate)
             << " | Duration: " << rentalAgreements[i].duration << " days"
             << " | Rental Ends: " << formatDate(rentalAgreements[i].rentDate + rentalAgreements[i].duration * 86400)
             << "\n";
    }
}

void RentalManagement::checkExpiredRentals() {
    time_t now = getCurrentDate();
    for (auto& agreement : rentalAgreements) {
        if (now >= agreement.rentDate + agreement.duration * 86400) {
            cout << "Rental for item '" << agreement.itemName << "' has expired.\n";
        }
    }
}

void RentalManagement::displayRentalHistory() {
    ifstream file(DATA_FILE);
    if (file.is_open()) {
        cout << "\nRental History:\n";
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cout << "No rental history available.\n";
    }
}
#include "RentalManagement.h"

int main() {
    RentalManagement rentalManager;
    int choice;

    do {
        cout << "\nRental Management System:\n";
        cout << "1. Display Rental Agreements\n";
        cout << "2. Check Expired Rentals\n";
        cout << "3. Display Rental History\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                rentalManager.displayRentalAgreements();
                break;
            case 2:
                rentalManager.checkExpiredRentals();
                break;
            case 3:
                rentalManager.displayRentalHistory();
                break;
            case 4:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}