#include "NOR_Cus.h"

class VIP_Cus : public Customer
{
public:
    VIP_Cus() {}
    void Input(string id, string ten, int tuoi) override
    {
        ID = id;
        Ten = ten;
        Tuoi = tuoi;
        GiamGia = 0.2;
    }
    bool CheckID(string id)
    {
        if (id == ID)
            return true;
        return false;
    }  
    double Discount() override
    {
        return GiamGia;
    }
    ~VIP_Cus() {}
};