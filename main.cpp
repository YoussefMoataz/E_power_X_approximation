/*

 --- Exponential function calculator ---

 This program calculates e^x by the summation:
 --(1 + x + x^2/2! + x^3/3! + ... + x^n/n!)--
 where x is our positive integer and n is the iteration

 @Date: March 13, 2022
 @Author: Youssef Moataz
 @Version: v1.0.0

 */

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

// calculate the power of a number to a given base
long double power(int base, int power) {

    int counter = 0;
    double num = 1;

    while (counter < power) {
        num *= base;
        counter += 1;
    }

    return num;
}

// calculate the factorial of a number
long double factorial(int num) {

    // base case
    if (num == 0 || num == 1) {
        return 1;

    // other cases
    } else {
        return num * factorial(num - 1);
    }

}

// calculate e^x given x as a parameter
long double getEPowerX(int num) {

    // number of iteration
    const int finalNumber = 100;

    int counter = 0;
    long double eToTheX = 0;

    // increase the final number to get higher accuracy
    for (int i = 0; i < finalNumber; i++) {

        // calculate the summation
        eToTheX += (power(num, i) / factorial(i));

        // print the process
        // 10 outputs in one line , 10 lines total (for 100 as final number)
        if (counter < 9) {

            cout << eToTheX << "  ";
            counter += 1;
            continue;

        } else if (counter == 9) {
            cout << eToTheX << endl;
            counter = 0;
            continue;
        }

    }

    return eToTheX;

}

// get the required number from the user
void getUserNumber() {

    // changes false if the input is not digits
    bool isValidNumber = true;

    string userNumber;

    cout << "Enter number to get its exponential result :" << endl;
    cin >> userNumber;

    // check input validity, is numbers
    for (char i: userNumber) {

        if (!isdigit(i)) {
            isValidNumber = false;
            break;
        }

    }

    if (isValidNumber) {

        // make the calculation
        long double ePowerXCalculatedValue = getEPowerX(stoi(userNumber, 0, 10));

        // print the calculated and expected values
        cout << endl << "Calculated value = " << ePowerXCalculatedValue;
        cout << endl << "Expected value   = " << exp(stoi(userNumber, 0, 10));

    } else {

        // re-call this function
        getUserNumber();
        return;
    }

}

// ### MAIN ###
int main() {

    // perform all the operations
    getUserNumber();

    return 0;
}

// End of the file