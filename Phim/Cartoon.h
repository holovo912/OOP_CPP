#include "Action.h"

class Cartoon : public Phim
{
public:
    Cartoon() {}
    void Input(string tenphim, int gio, int phut, int gio_end, int phut_end, vector<int> chongoi)
    {
        Phim::Input(tenphim, gio, phut, gio_end, phut_end, chongoi);
        GiaVe = 40000;
        Tag = 2;
        Phong = 2;
    }
    bool CheckTuoi(int tuoi) override
    {
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
    ~Cartoon() {}
};