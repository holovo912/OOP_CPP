#include <bits/stdc++.h>
using namespace std;

class Customer
{
public:
    Customer() {}
    virtual void Input(string id, string ten, int tuoi)
    {

    }
    void Info()
    {
        cout << "------------------------------------------\n";
        cout << "ID: " << ID << endl;
        cout << "Name: " << Ten << endl;
        cout << "Age: " << Tuoi << endl; 
        cout << "Discount: " << GiamGia * 100 << "%" << endl;
    }
    virtual double Discount()
    {
        
    }
    ~Customer() {}
protected: // Xài protected bên C# thì không cần property
    string ID;
    string Ten;
    int Tuoi;
    double GiamGia;
};