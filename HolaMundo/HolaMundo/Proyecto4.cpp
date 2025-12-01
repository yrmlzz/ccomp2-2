#include <iostream>
using namespace std;


class Student {
public:
    explicit Student(std::string n, int a) {
    name = n;
    age = a;
   }
   bool isOlder() const {
    return age >= 18;
}

   
private:
    std::string name;
    int age;
};




int main() {
    std::string n1, n2;
    int a1, a2;

    cout << "Nombre 1: ";
    cin >> n1;
    cout << "Edad 1: ";
    cin >> a1;

    cout << "Nombre 2: ";
    cin >> n2;
    cout << "Edad 2: ";
    cin >> a2;

    Student s1(n1, a1);
    Student s2(n2, a2);

    cout << "\n--- Datos del estudiante 1 ---\n";
    cout << "Nombre: " << n1 << "\nEdad: " << a1 << endl;
    cout << (s1.isOlder() ? "Es mayor de edad" : "Es menor de edad") << endl;

    cout << "\n--- Datos del estudiante 2 ---\n";
    cout << "Nombre: " << n2 << "\nEdad: " << a2 << endl;
    cout << (s2.isOlder() ? "Es mayor de edad" : "Es menor de edad") << endl;

    return 0;

