#include "Function.h"

int main()
{
    LayThongTinVIP("Database/VIP.txt", List_VIP, num_vip);
    LayThongTinAction("Database/Action.txt", List_Action, num_action);
    LayThongTinCartoon("Database/Cartoon.txt", List_Cartoon, num_cartoon);
    LayThongTinDrama("Database/Drama.txt", List_Drama, num_drama);
    LayThongTinHorror("Database/Horror.txt", List_Horror, num_action);
    LayHetPhim(List_Phim);
    RunSignIn();
    RunShowPhim();
    RunTotal();
    return 0;
}
