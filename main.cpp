#include <iostream>

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

long double getEPowerX(int num, int iterations) {

    long double eToTheX = 0;

    for (int i = 0; i < iterations; i++) {
        eToTheX += (power(num, i) / factorial(i));
    }

    return eToTheX;

}

int main() {

//    cout << factorial(30);
//    cout << power(2, 10);
//    cout << getEPowerX(90, 150);

    return 0;
}
