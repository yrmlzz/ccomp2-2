#include <iostream>
using namespace std;

class Cuaderno {
protected:
    string tamano;
    int hojas;

public:
    Cuaderno(string t = "A4", int h = 100) {
        tamano = t;
        hojas = h;
    }

    virtual void imprimir() {
        cout << "Tamano: " << tamano << ", Hojas: " << hojas;
    }

    virtual ~Cuaderno() { }
};

class Marca : public Cuaderno {
private:
    string nombre;

public:
    Marca(string n, string t, int h) : Cuaderno(t, h) {
        nombre = n;
    }

    void imprimir() override {
        cout << "Marca: " << nombre << " | ";
        Cuaderno::imprimir();
    }
};

int main() {
    Cuaderno *c1 = new Marca("Stanford", "A5", 80);
    Cuaderno *c2 = new Marca("Justus", "A4", 100);

    cout << "--- Cuaderno 1 ---\n";
    c1->imprimir();

    cout << "\n\n--- Cuaderno 2 ---\n";
    c2->imprimir();

    delete c1;
    delete c2;

    return 0;
}
