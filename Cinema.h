// Chứa chức năng lấy phim và thông tin khách hàng từ file txt
#include "Cinema/VIP_Cus.h"
#include "Phim/Horror.h"

vector<VIP_Cus *> List_VIP; // Danh sách khách hàng VIP
int num_vip = 5;
// Danh sách các thể loại phim và số lượng của mỗi loại
vector<Action *> List_Action;
int num_action = 2;

vector<Cartoon *> List_Cartoon;
int num_cartoon = 2;

vector<Drama *> List_Drama;
int num_drama = 2;

vector<Horror *> List_Horror;
int num_horror = 2;

vector<Phim *> List_Phim;
int num_phim = num_action + num_cartoon + num_drama + num_horror;

void LayThongTinVIP(const char fname[], vector<VIP_Cus *> &List_VIP, int num)
{
    ifstream input(fname);
    if (input.fail())
    {
        cout << "Khong mo duoc tep tin !" << endl;
        return;
    }
    for (int i = 0; i < num; i++)
    {
        VIP_Cus *temp = new VIP_Cus();
        string id;
        string ten;
        int tuoi;
        input >> id >> ten >> tuoi;
        temp->Input(id, ten, tuoi);
        List_VIP.push_back(temp);
    }
}
void LayThongTinAction(const char fname[], vector<Action *> &List_Action, int num)
{
    ifstream input(fname);
    if (input.fail())
    {
        cout << "Khong mo duoc tep tin !" << endl;
        return;
    }
    for (int i = 0; i < num; i++)
    {
        Action *temp = new Action();
        string id, tenphim;
        int gio, phut, gio_end, phut_end;
        vector<int> chongoi;
        input >> tenphim >> gio >> phut >> gio_end >> phut_end;
        for (int i = 0; i < Slot; i++)
        {
            int temp;
            input >> temp;
            chongoi.push_back(temp);
        }
        temp->Input(tenphim, gio, phut, gio_end, phut_end, chongoi);
        List_Action.push_back(temp);
    }
}
void LayThongTinCartoon(const char fname[], vector<Cartoon *> &List_Cartoon, int num)
{
    ifstream input(fname);
    if (input.fail())
    {
        cout << "Khong mo duoc tep tin !" << endl;
        return;
    }
    for (int i = 0; i < num; i++)
    {
        Cartoon *temp = new Cartoon();
        string id, tenphim;
        int gio, phut, gio_end, phut_end;
        vector<int> chongoi;
        input >> tenphim >> gio >> phut >> gio_end >> phut_end;
        for (int i = 0; i < Slot; i++)
        {
            int temp;
            input >> temp;
            chongoi.push_back(temp);
        }
        temp->Input(tenphim, gio, phut, gio_end, phut_end, chongoi);
        List_Cartoon.push_back(temp);
    }
}
void LayThongTinDrama(const char fname[], vector<Drama *> &List_Drama, int num)
{
    ifstream input(fname);
    if (input.fail())
    {
        cout << "Khong mo duoc tep tin !" << endl;
        return;
    }
    for (int i = 0; i < num; i++)
    {
        Drama *temp = new Drama();
        string id, tenphim;
        int gio, phut, gio_end, phut_end;
        vector<int> chongoi;
        input >> tenphim >> gio >> phut >> gio_end >> phut_end;
        for (int i = 0; i < Slot; i++)
        {
            int temp;
            input >> temp;
            chongoi.push_back(temp);
        }
        temp->Input(tenphim, gio, phut, gio_end, phut_end, chongoi);
        List_Drama.push_back(temp);
    }
}
void LayThongTinHorror(const char fname[], vector<Horror *> &List_Horror, int num)
{
    ifstream input(fname);
    if (input.fail())
    {
        cout << "Khong mo duoc tep tin !" << endl;
        return;
    }
    for (int i = 0; i < num; i++)
    {
        Horror *temp = new Horror();
        string id, tenphim;
        int gio, phut, gio_end, phut_end;
        vector<int> chongoi;
        input >> tenphim >> gio >> phut >> gio_end >> phut_end;
        for (int i = 0; i < Slot; i++)
        {
            int temp;
            input >> temp;
            chongoi.push_back(temp);
        }
        temp->Input(tenphim, gio, phut, gio_end, phut_end, chongoi);
        List_Horror.push_back(temp);
    }
}
void LayHetPhim(vector<Phim *> &List_Phim)
{
    for (int i = 0; i < num_action; i++)
        List_Phim.push_back(List_Action[i]);

    for (int i = 0; i < num_cartoon; i++)
        List_Phim.push_back(List_Cartoon[i]);

    for (int i = 0; i < num_drama; i++)
        List_Phim.push_back(List_Drama[i]);

    for (int i = 0; i < num_horror; i++)
        List_Phim.push_back(List_Horror[i]);
}