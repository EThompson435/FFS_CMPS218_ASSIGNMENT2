#include <iostream>
#include <string>
using namespace std;

// Struct to store birthday information
struct Birthday {
    int month;
    int day;
    int year;
};

// Function to get the month meaning
string getMonthMeaning(int month) {
    switch (month) {
    case 1: return "Janus";
    case 2: return "Juno";
    case 3: return "Mars";
    case 4: return "Venus";
    case 5: return "Mercury";
    case 6: return "Ceres";
    case 7: return "Apollo";
    case 8: return "Artemis";
    case 9: return "Zeus";
    case 10: return "Hera";
    case 11: return "Poseidon";
    case 12: return "Hestia";
    default: return "Invalid month";
    }
}

// Function to get the day number meaning
string getDayMeaning(int day) {
    if (day == 1) return "Self-Started";
    else if (day == 2) return "Diplomatic";
    else if (day == 3) return "Creative";
    else if (day == 4) return "Disciplined";
    else if (day == 5) return "Adventurous";
    else if (day == 6) return "Responsible";
    else if (day == 7) return "Intellectual";
    else if (day == 8) return "Powerful";
    else if (day == 9) return "Humanitarian";
    else if (day == 10) return "Leader";
    else return "Day number meaning not available";
}

// Function to get the year meaning
string getYearMeaning(int year) {
    if (year >= 2000 && year <= 2023) {
        if (year >= 2000 && year <= 2009) return "Millennial";
        else if (year >= 2010 && year <= 2019) return "Generation Z";
        else if (year >= 2020 && year <= 2023) return "Generation Alpha";
    }
    return "Year meaning not available";
}

// Function to get the month name
string getMonthName(int month) {
    switch (month) {
    case 1: return "January";
    case 2: return "February";
    case 3: return "March";
    case 4: return "April";
    case 5: return "May";
    case 6: return "June";
    case 7: return "July";
    case 8: return "August";
    case 9: return "September";
    case 10: return "October";
    case 11: return "November";
    case 12: return "December";
    default: return "Invalid month";
    }
}

int main() {
    string response;

    cout << "Welcome to Birthday Date Meaning Generator!" << endl;

    do {
        // Create an instance of the Birthday struct
        Birthday userBirthday;

        // Input the birthday information
        cout << "Please enter the month of your birthday (1-12): ";
        cin >> userBirthday.month;

        cout << "Please enter the day of your birthday (1-31): ";
        cin >> userBirthday.day;

        cout << "Please enter the year of your birthday (2000-2023): ";
        cin >> userBirthday.year;

        // Display the meaning for the month, day, and year
        cout << "The month of " << getMonthName(userBirthday.month)
            << " means " << getMonthMeaning(userBirthday.month) << endl;

        cout << "The " << userBirthday.day << "th of the month means "
            << getDayMeaning(userBirthday.day) << endl;

        cout << "The year " << userBirthday.year << " means that you are "
            << getYearMeaning(userBirthday.year) << endl;

        // Ask if the user wants to try again
        cout << "Would you like to try another one? (Y/N): ";
        cin >> response;

    } while (response == "Y" || response == "y");

    cout << "Thanks for playing!" << endl;
    return 0;
}