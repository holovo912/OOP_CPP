#include <bits/stdc++.h>
using namespace std;
#define Slot 28 // Số chỗ ngồi
class Phim
{
public:
	Phim() {}
	void Input(string tenphim, int gio, int phut, int gio_end, int phut_end, vector<int> chongoi)
	{
		TenPhim = tenphim;
		Gio = gio;
		Phut = phut;
		Gio_End = gio_end;
		Phut_End = phut_end;
		ChoNgoi = chongoi;
	}
	virtual bool CheckTuoi(int tuoi)
	{
		return true;
	}
	void Infor()
	{
		string tag_name;
		if (Tag == 1)
			tag_name = "Action";
		if (Tag == 2)
			tag_name = "Cartoon";
		if (Tag == 3)
			tag_name = "Drama";
		if (Tag == 4)
			tag_name = "Horror";
		cout << "| " << setw(8) << left << tag_name << "| " << setw(16) << left << TenPhim << "| ";
		string temp = to_string(Gio) + ":" + to_string(Phut) + "--" + to_string(Gio_End) + ":" + to_string(Phut_End);
		cout << setw(12) << left << temp;
		cout << " |   " <<  Phong << "    |" << endl;
	}
	void Seat()
	{
		cout << "-------------------------------------------------\n";
		cout << "-                ==============                 -\n";
		cout << "-                ==  Screen  ==                 -\n";
		cout << "-                ==============                 -\n\n";
		int count = 0;
		for (int i = 1; i <= 4; i++)
		{
			cout << "-             ";
			for (int j = 1; j <= Slot / 4; j++)
			{
				cout.width(2);
				cout << ChoNgoi[count] << " ";
				count++;
			}
			cout << "             -" << endl;
		}
		cout << "-------------------------------------------------\n";
	}
	int GetGiaVe()
	{
		return GiaVe;
	}
	bool CheckSeat(int i)
	{
		if (ChoNgoi[i - 1] == 0)
			return false;
		return true;
	}
	int ChooseSeat()
	{
		int i;
		cout << "Choose seat: ";
		cin >> i;
		while (i <= 0 || i > 28)
		{
			cout << "Invalid seat, please choose again !!!\n";
			cout << "Choose seat: ";
			cin >> i;
		}
		while (ChoNgoi[i - 1] == 0)
		{
			cout << "Seat choosen, choose another seat !!!\n";
			cout << "Choose seat: ";
			cin >> i;
		}
		ChoNgoi[i - 1] = 0;
		return i;
	}
	bool CheckTime(int gio, int phut)
	{
		if (gio > Gio && gio < Gio_End)
		{
			return true;
		}
		else if (gio == Gio)
		{
			if (phut > Phut)
				return true;
		}
		else if (gio == Gio_End)
		{
			if (phut < Phut_End)
				return true;
		}
		return false;
	}
	~Phim() {}

protected:
	string TenPhim;
	int Tag;
	int Gio;
	int Phut;
	int Gio_End;
	int Phut_End;
	int GiaVe;
	int Phong;
	vector<int> ChoNgoi;
};