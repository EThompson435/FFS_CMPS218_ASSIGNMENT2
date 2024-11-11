#include <iostream>
#include <string>
#include <cmath>
#include <cctype>
#include <sstream>

using namespace std;

// Utility function to check if a character is a digit or a decimal point
bool isDigitOrDot(char c) {
    return isdigit(c) || c == '.';
}

// Function to solve an expression inside parentheses
double solveSimpleExpression(const string& expr) {
    stringstream ss(expr);
    double result;
    ss >> result;
    return result;
}

// Define a struct to hold the calculator state
struct CalculatorState {
    string problem;
    char again;
};

// Main program
int main() {
    // Create a struct to hold the calculator state
    CalculatorState state;

    do {
        cout << "Enter a problem to solve: ";
        getline(cin, state.problem);

        // First, handle parentheses
        size_t openParen = state.problem.find('(');
        while (openParen != string::npos) {
            size_t closeParen = state.problem.find(')', openParen);
            string subExpr = state.problem.substr(openParen + 1, closeParen - openParen - 1);

            double result = solveSimpleExpression(subExpr);
            cout << "Solving: " << subExpr << " = " << result << endl;

            // Replace the parentheses with the result
            state.problem.replace(openParen, closeParen - openParen + 1, to_string(result));
            openParen = state.problem.find('('); // Find next parentheses
        }

        // Solve Exponentiation ( ^ )
        size_t pos = state.problem.find('^');
        while (pos != string::npos) {
            size_t start = pos - 1;
            while (start > 0 && isDigitOrDot(state.problem[start])) start--;
            size_t end = pos + 1;
            while (end < state.problem.size() && isDigitOrDot(state.problem[end])) end++;

            double base = stod(state.problem.substr(start, pos - start));
            double exponent = stod(state.problem.substr(pos + 1, end - pos - 1));

            double result = pow(base, exponent);
            cout << "Solving: " << base << " ^ " << exponent << " = " << result << endl;

            // Replace the expression with the result
            state.problem.replace(start, end - start, to_string(result));

            // Look for next exponent
            pos = state.problem.find('^');
        }

        // Solve Multiplication and Division ( * / )
        pos = state.problem.find_first_of("*/");
        while (pos != string::npos) {
            char op = state.problem[pos];
            size_t start = pos - 1;
            while (start > 0 && isDigitOrDot(state.problem[start])) start--;
            size_t end = pos + 1;
            while (end < state.problem.size() && isDigitOrDot(state.problem[end])) end++;

            double left = stod(state.problem.substr(start, pos - start));
            double right = stod(state.problem.substr(pos + 1, end - pos - 1));

            double result = (op == '*') ? left * right : left / right;
            cout << "Solving: " << left << " " << op << " " << right << " = " << result << endl;

            // Replace the expression with the result
            state.problem.replace(start, end - start, to_string(result));

            // Look for next multiplication/division
            pos = state.problem.find_first_of("*/");
        }

        // Solve Addition and Subtraction ( + - )
        pos = state.problem.find_first_of("+-");
        while (pos != string::npos) {
            char op = state.problem[pos];
            size_t start = pos - 1;
            while (start > 0 && isDigitOrDot(state.problem[start])) start--;
            size_t end = pos + 1;
            while (end < state.problem.size() && isDigitOrDot(state.problem[end])) end++;

            double left = stod(state.problem.substr(start, pos - start));
            double right = stod(state.problem.substr(pos + 1, end - pos - 1));

            double result = (op == '+') ? left + right : left - right;
            cout << "Solving: " << left << " " << op << " " << right << " = " << result << endl;

            // Replace the expression with the result
            state.problem.replace(start, end - start, to_string(result));

            // Look for next addition/subtraction
            pos = state.problem.find_first_of("+-");
        }

        // Output final result
        cout << "The answer to this problem is: " << state.problem << endl;

        // Ask if the user wants to solve another problem
        cout << "Would you like to solve another problem? (Y/N) ";
        cin >> state.again;
        cin.ignore();  // To ignore the trailing newline character from previous input

    } while (state.again == 'Y' || state.again == 'y');

    cout << "Thank you for using this calculator!" << endl;

    return 0;
}