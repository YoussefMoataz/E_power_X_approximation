#include <iostream>
#include <cmath>

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

        if (counter < 9){
            cout << eToTheX << "  ";
            counter += 1;
            continue;
        }else if(counter == 9){
            cout << eToTheX << endl;
            counter = 0;
            continue;
        }

    }

    return eToTheX;

}

int main() {

//    cout << factorial(30);
//    cout << power(2, 10);
    getEPowerX(3);
//    cout << exp(90);


    return 0;
}
