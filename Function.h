#include "Cinema.h"

Customer *cus = new Customer(); // Lưu thông tin khách hàng đang sử dụng
int key = 0, key2 = 0;          // Khóa để switch
int nor_type = 0;               // Lưu loại khách hàng đang sử dụng
int age = 18;                   // Tuổi của khách (VIP mặc định 18) (NOR thì đổi lại sau)
double dis = 0;                 // Lưu giá trị giảm giá

vector<Phim *> total;              // Lưu phim mua
vector<int> seat;                  // Lưu chỗ ngồi mua
int num_total = 0, cost_total = 0; // Lưu số lượng và tổng giá trị phim vừa mua

void RunSignIn()
{
    while (key == 0)
    {
        cout << "You are Normal(1) or VIP(2) customer? (press 1 or 2): ";
        cin >> key;
        if (key == 1)
        {
            NOR_Cus *nor = new NOR_Cus();
            string id, name;
            bool check = true;
            while (check == true)
            {
                check = false;
                cout << "Create your ID (0: return): ";
                cin >> id;
                if (id == "0")
                {
                    key = 0;
                    break;
                }
                for (int i = 0; i < num_vip; i++)
                    if (List_VIP[i]->CheckID(id))
                    {
                        system("CLS");
                        cout << "ID exist, please create another ID\n";
                        check = true;
                    }
            }
            if (key != 0)
            {
                cout << "Enter your name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Your age: ";
                cin >> age;
                nor->Input(id, name, age);
                dis = dis = nor->Discount();
                nor_type = 1;
                system("CLS");
                cus = nor;
                break;
            }
            system("CLS");
        }
        if (key == 2)
        {
            string id;
            bool check = true;

            while (check == true)
            {
                cout << ("Enter your VIP ID (0: return): ");
                cin >> id;
                if (id == "0")
                {
                    key = 0;
                    system("CLS");
                    break;
                }
                for (int i = 0; i < num_vip; i++)
                {
                    if (List_VIP[i]->CheckID(id))
                    {
                        system("CLS");
                        cout << "Successfully accessed\n";
                        cus = List_VIP[i];
                        dis = List_VIP[i]->Discount();
                        nor_type = 3;
                        key = 3;
                        check = false;
                        break;
                    }
                }
                if (key != 3)
                {
                    system("CLS");
                    cout << "Wrong ID, please type again or call: 19000091" << endl;
                }
            }
        }
    }
    cus->Info();
}
void ShowAllPhim()
{
    cout << "-----------------------------------------------------------\n";
    cout << "| Num |   Tag   |      Name       |     Time     |  Room  |\n";
    cout << "-----------------------------------------------------------\n";
    for (int i = 0; i < num_phim; i++)
    {
        cout << "|  " << i + 1 << "  ";
        List_Phim[i]->Infor();
    }
    cout << "-----------------------------------------------------------\n";
}
void ShowAction()
{
    cout << "-----------------------------------------------------------\n";
    cout << "| Num |   Tag   |      Name       |     Time     |  Room  |\n";
    cout << "-----------------------------------------------------------\n";
    for (int i = 0; i < num_action; i++)
    {
        cout << "|  " << i + 1 << "  ";
        List_Action[i]->Infor();
    }
    cout << "-----------------------------------------------------------\n";
}
void ShowCartoon()
{
    cout << "-----------------------------------------------------------\n";
    cout << "| Num |   Tag   |      Name       |     Time     |  Room  |\n";
    cout << "-----------------------------------------------------------\n";
    for (int i = 0; i < num_cartoon; i++)
    {
        cout << "|  " << i + 1 << "  ";
        List_Cartoon[i]->Infor();
    }
    cout << "-----------------------------------------------------------\n";
}
void ShowDrama()
{
    cout << "-----------------------------------------------------------\n";
    cout << "| Num |   Tag   |      Name       |     Time     |  Room  |\n";
    cout << "-----------------------------------------------------------\n";
    for (int i = 0; i < num_drama; i++)
    {
        cout << "|  " << i + 1 << "  ";
        List_Drama[i]->Infor();
    }
    cout << "-----------------------------------------------------------\n";
}
void ShowHorror()
{
    cout << "-----------------------------------------------------------\n";
    cout << "| Num |   Tag   |      Name       |     Time     |  Room  |\n";
    cout << "-----------------------------------------------------------\n";
    for (int i = 0; i < num_horror; i++)
    {
        cout << "|  " << i + 1 << "  ";
        List_Horror[i]->Infor();
    }
    cout << "-----------------------------------------------------------\n";
}
void ShowByTime(int gio, int phut)
{
    cout << "-----------------------------------------------------------\n";
    cout << "| Num |   Tag   |      Name       |     Time     |  Room  |\n";
    cout << "-----------------------------------------------------------\n";
    for (int i = 0; i < num_phim; i++)
    {
        if (List_Phim[i]->CheckTime(gio, phut) == true)
        {
            cout << "|  " << i + 1 << "  ";
            List_Phim[i]->Infor();
        }
    }
    cout << "-----------------------------------------------------------\n";
}
void RunTotal()
{
    system("CLS");
    cout << "--------------------------------------------------------------------\n";
    cout << "| Num |  Seat  |   Tag   |      Name       |     Time     |  Room  |\n";
    cout << "--------------------------------------------------------------------\n";
    for (int i = 0; i < num_total; i++)
    {
        string temp = "(" + to_string(seat[i]) + ")";
        cout << "|  " << i + 1 << "  |  " << setw(6) << left << temp;
        total[i]->Infor();
        cost_total += total[i]->GetGiaVe();
    }
    cout << "--------------------------------------------------------------------\n";
    cout << "Total: " << cost_total * (1 - dis) << " VND";
}
void RunMenu()
{
    cout << "------------------------------------------\n";
    cout << "| Action: 80000 VND | Cartoon: 40000 VND |\n";
    cout << "| Drama: 60000 VND  | Horror: 80000 VND  |\n";
    cout << "------------------------------------------\n";
    cout << "| 0: Total          | 1: Show All        |\n";
    cout << "| 7: Delete Seat    | 2: Show Action     |\n";
    cout << "|                   | 3: Show Cartoon    |\n";
    cout << "|                   | 4: Show Drama      |\n";
    cout << "|                   | 5: Show Horror     |\n";
    cout << "|                   | 6: Movie by Time   |\n";
    cout << "------------------------------------------\n";
}
void RunShowPhim()
{
    while (true)
    {
        RunMenu();
        cout << "Choose: ";
        cin >> key;
        if (key == 0)
        {
            break;
        }
        if (key == 1)
        {
            ShowAllPhim();
            cout << "Choose movie you want (0: return): ";
            cin >> key2;
            if (key2 == 0)
            {
                system("CLS");
                cus->Info();
            }
            else if (List_Phim[key2 - 1]->CheckTuoi(age) == false)
            {
                system("CLS");
                cout << "The movie is resticted for your age, choose another movie\n";
                cus->Info();
            }
            else
            {
                List_Phim[key2 - 1]->Infor();
                List_Phim[key2 - 1]->Seat();
                int temp = List_Phim[key2 - 1]->ChooseSeat();
                seat.push_back(temp);
                total.push_back(List_Phim[key2 - 1]);
                num_total++;
                system("CLS");
                cout << "Choosed successfully\n";
            }
        }
        if (key == 2)
        {
            ShowAction();
            cout << "Choose movie you want (0: return): ";
            cin >> key2;
            if (key2 == 0)
            {
                system("CLS");
                cus->Info();
            }
            else if (List_Action[key2 - 1]->CheckTuoi(age) == false)
            {
                system("CLS");
                cout << "The movie is resticted for your age, choose another movie\n";
                cus->Info();
            }
            else
            {
                List_Action[key2 - 1]->Infor();
                List_Action[key2 - 1]->Seat();
                int temp = List_Action[key2 - 1]->ChooseSeat();
                seat.push_back(temp);
                total.push_back(List_Action[key2 - 1]);
                num_total++;
                system("CLS");
                cout << "Choosed successfully\n";
            }
        }
        if (key == 3)
        {
            ShowCartoon();
            cout << "Choose movie you want (0: return): ";
            cin >> key2;
            if (key2 == 0)
            {
                system("CLS");
                cus->Info();
            }
            else if (List_Cartoon[key2 - 1]->CheckTuoi(age) == false)
            {
                system("CLS");
                cout << "The movie is resticted for your age, choose another movie\n";
                cus->Info();
            }
            else
            {
                List_Cartoon[key2 - 1]->Infor();
                List_Cartoon[key2 - 1]->Seat();
                int temp = List_Cartoon[key2 - 1]->ChooseSeat();
                seat.push_back(temp);
                total.push_back(List_Cartoon[key2 - 1]);
                num_total++;
                system("CLS");
                cout << "Choosed successfully\n";
            }
        }
        if (key == 4)
        {
            ShowDrama();
            cout << "Choose movie you want (0: return): ";
            cin >> key2;
            if (key2 == 0)
            {
                system("CLS");
                cus->Info();
            }
            else if (List_Drama[key2 - 1]->CheckTuoi(age) == false)
            {
                system("CLS");
                cout << "The movie is resticted for your age, choose another movie\n";
                cus->Info();
            }
            else
            {
                List_Drama[key2 - 1]->Infor();
                List_Drama[key2 - 1]->Seat();
                int temp = List_Drama[key2 - 1]->ChooseSeat();
                seat.push_back(temp);
                total.push_back(List_Drama[key2 - 1]);
                num_total++;
                system("CLS");
                cout << "Choosed successfully\n";
            }
        }
        if (key == 5)
        {
            ShowHorror();
            cout << "Choose movie you want (0: return): ";
            cin >> key2;
            if (key2 == 0)
            {
                system("CLS");
                cus->Info();
            }
            else if (List_Horror[key2 - 1]->CheckTuoi(age) == false)
            {
                system("CLS");
                cout << "The movie is resticted for your age, choose another movie\n";
                cus->Info();
            }
            else
            {
                List_Horror[key2 - 1]->Infor();
                List_Horror[key2 - 1]->Seat();
                int temp = List_Horror[key2 - 1]->ChooseSeat();
                seat.push_back(temp);
                total.push_back(List_Horror[key2 - 1]);
                num_total++;
                system("CLS");
                cout << "Choosed successfully\n";
            }
        }
        if (key == 6)
        {
            int gio, phut;
            cout << "Hour: ";
            cin >> gio;
            cout << "Minute: ";
            cin >> phut;
            ShowByTime(gio, phut);
            cout << "Choose movie you want (0: return): ";
            cin >> key2;
            if (key2 != 0)
            {
                bool check = List_Phim[key2 - 1]->CheckTime(gio, phut);
                while (check == false)
                {
                    cout << "Invalid, please choose again!!!\n";
                    cout << "Choose movie you want (0: return): ";
                    cin >> key2;
                    if (key2 == 0)
                    {
                        check = true;
                    }
                    else
                        check = List_Phim[key2 - 1]->CheckTime(gio, phut);
                }
            }
            if (key2 == 0)
            {
                system("CLS");
                cus->Info();
            }
            else if (List_Phim[key2 - 1]->CheckTuoi(age) == false)
            {
                system("CLS");
                cout << "The movie is resticted for your age, choose another movie\n";
                cus->Info();
            }
            else
            {
                List_Phim[key2 - 1]->Infor();
                List_Phim[key2 - 1]->Seat();
                int temp = List_Phim[key2 - 1]->ChooseSeat();
                seat.push_back(temp);
                total.push_back(List_Phim[key2 - 1]);
                num_total++;
                system("CLS");
                cout << "Choosed successfully\n";
            }
        }
    }
}
