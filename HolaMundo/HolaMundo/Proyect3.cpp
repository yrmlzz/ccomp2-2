#include <iostream>

using namespace std;

class Vehicle {
protected:
    string license;
    int year;

public:
    Vehicle(const string &myLicense, const int myYear)
        : license(myLicense), year(myYear) {}

    const string &getLicense() const { return license; }
    const int getYear() const { return year; }
};

class Truck : public Vehicle {
private:
    int capacity; // capacidad en toneladas

public:
    Truck(const string &lic, int y, int c)
        : Vehicle(lic, y), capacity(c) {}

    int getCapacity() const { return capacity; }
};

class Car : public Vehicle {
private:
    int doors;

public:
    Car(const string &lic, int y, int d)
        : Vehicle(lic, y), doors(d) {}

    int getDoors() const { return doors; }
};


int main() {
    int n;
    cout << "Ingrese tamano del arreglo: ";
    cin >> n;

    Vehicle **arr = new Vehicle*[n]; // arreglo dinámico de punteros

    for(int i = 0; i < n; i++) {
        int tipo;
        cout << "\n1. Car   2. Truck: ";
        cin >> tipo;

        string lic;
        int year;

        cout << "License: ";
        cin >> lic;
        cout << "Year: ";
        cin >> year;

        if(tipo == 1) {
            int doors;
            cout << "Puertas: ";
            cin >> doors;
            arr[i] = new Car(lic, year, doors);
        }
        else {
            int cap;
            cout << "Capacidad (toneladas): ";
            cin >> cap;
            arr[i] = new Truck(lic, year, cap);
        }
    }

    cout << "\n--- Vehiculos ingresados ---\n";
    for(int i = 0; i < n; i++) {
        cout << "License: " << arr[i]->getLicense()
             << "  Year: " << arr[i]->getYear() << endl;
    }

    // liberar memoria
    for(int i = 0; i < n; i++)
        delete arr[i];

    delete [] arr;

    return 0;
}
