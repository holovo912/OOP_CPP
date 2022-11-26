#include "Phim.h"

class Action : public Phim
{
public:
    Action() {}
    void Input(string tenphim, int gio, int phut, int gio_end, int phut_end, vector<int> chongoi)
    {
        Phim::Input(tenphim, gio, phut, gio_end, phut_end, chongoi);
        GiaVe = 80000;
        Tag = 1;
        Phong = 1;
    }
    bool CheckTuoi(int tuoi) override
    {
        if (tuoi < 16)
            return false;
        return true;
    }
    void Infor()
    {
        Phim::Infor();
    }
    void Seat()
    {
        Phim::Seat();
    }
    ~Action(){}
};