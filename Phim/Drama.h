#include "Cartoon.h"

class Drama : public Phim
{
public:
    Drama() {}
    void Input(string tenphim, int gio, int phut, int gio_end, int phut_end, vector<int> chongoi)
    {
        Phim::Input(tenphim, gio, phut, gio_end, phut_end, chongoi);
        GiaVe = 60000;
        Tag = 3;
        Phong = 3;
    }
    bool CheckTuoi(int tuoi) override
    {
        if (tuoi < 14)
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
    ~Drama() {}
};