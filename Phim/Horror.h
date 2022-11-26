#include "Drama.h"

class Horror : public Phim
{
public:
    Horror() {}
    void Input(string tenphim, int gio, int phut, int gio_end, int phut_end, vector<int> chongoi)
    {
        Phim::Input(tenphim, gio, phut, gio_end, phut_end, chongoi);
        GiaVe = 80000;
        Tag = 4;
        Phong = 4;
    }
    bool CheckTuoi(int tuoi) override
    {
        if (tuoi < 18)
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
    ~Horror() {}
};