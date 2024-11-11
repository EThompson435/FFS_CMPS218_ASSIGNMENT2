#include <iostream>
#include <string>
#include <iomanip>  // For controlling output format

using namespace std;

// Function to calculate BMI
double calculateBMI(double weight, double heightInches) {
    return (703 * weight) / (heightInches * heightInches);
}

// Function to determine BMI category
string getBMICategory(double bmi) {
    if (bmi < 18.5) {
        return "Underweight";
    }
    else if (bmi >= 18.5 && bmi < 24.9) {
        return "Normal weight";
    }
    else if (bmi >= 25 && bmi < 29.9) {
        return "Overweight";
    }
    else {
        return "Obesity";
    }
}

int main() {
    // Declare variables to store user input
    string name, gender;
    int age, heightFeet, heightInches;
    double weight, heightInchesTotal, bmi;

    // Ask the user for their information
    cout << "Please enter your name: ";
    getline(cin, name);

    cout << "Please enter your age: ";
    while (!(cin >> age) || age <= 0) {
        cout << "Please enter a valid age: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Please enter your Gender (male/female): ";
    cin >> gender;

    cout << "Please enter your height in feet: ";
    while (!(cin >> heightFeet) || heightFeet <= 0) {
        cout << "Please enter a valid height in feet: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Please enter your height in inches: ";
    while (!(cin >> heightInches) || heightInches < 0 || heightInches >= 12) {
        cout << "Please enter a valid height in inches (0-11): ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Please enter your weight in pounds: ";
    while (!(cin >> weight) || weight <= 0) {
        cout << "Please enter a valid weight in pounds: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Convert height to inches
    heightInchesTotal = (heightFeet * 12) + heightInches;

    // Calculate BMI
    bmi = calculateBMI(weight, heightInchesTotal);

    // Get the BMI category
    string bmiCategory = getBMICategory(bmi);

    // Output the result with formatting
    cout << fixed << setprecision(2); // Display BMI with two decimal places
    cout << "\nHi " << name << "," << endl;
    cout << "You are a " << gender << ". You are " << age << " years old." << endl;
    cout << "You are " << heightFeet << "' " << heightInches << "\" tall and weigh " << weight << " pounds." << endl;
    cout << "Your BMI is " << bmi << ", which is considered " << bmiCategory << "." << endl;
    cout << "Thank you for using the BMI Calculator!" << endl;

    return 0;
}