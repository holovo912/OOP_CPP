#include "Customer.h"

class NOR_Cus : public Customer
{
public:
    NOR_Cus() {}
    void Input(string id, string ten, int tuoi) override
    {
        ID = id;
        Ten = ten;
        Tuoi = tuoi;
        GiamGia = 0.1;
    }
    double Discount() override
    {
        return GiamGia;
    }
    ~NOR_Cus() {}
};