/*

 --- Exponential function calculator ---

 This program calculates e^x by the summation:
 --(1 + x + x^2/2! + x^3/3! + ... + x^n/n!)--
 where x is our number and n is the iteration

 @Date: March 13, 2022
 @Author: Youssef Moataz
 @Version: v1.0.0

 */

#include <iostream>
#include <cmath>
#include <string>

using namespace std;

long double power(int base, int power) {

    int counter = 0;
    double num = 1;

    while (counter < power) {
        num *= base;
        counter += 1;
    }

    return num;
}

long double factorial(int num) {

    if (num == 0 || num == 1) {
        return 1;
    } else {
        return num * factorial(num - 1);
    }

}

long double getEPowerX(int num) {

    int counter = 0;
    long double eToTheX = 0;

    for (int i = 0; i < 100; i++) {
        eToTheX += (power(num, i) / factorial(i));

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

void getUserNumber() {

    bool isValidNumber = true;

    string userNumber;

    cout << "Enter number to get its exponential result :" << endl;
    cin >> userNumber;

    for (char i: userNumber) {

        if (!isdigit(i)) {
            isValidNumber = false;
            break;
        }

    }

    if (isValidNumber) {

        long double ePowerXCalculatedValue = getEPowerX(stoi(userNumber, 0, 10));

        cout << endl << "Calculated value = " << ePowerXCalculatedValue;
        cout << endl << "Expected value   = " << exp(stoi(userNumber, 0, 10));

    } else {
        getUserNumber();
        return;
    }

}

int main() {

    getUserNumber();

    return 0;
}
