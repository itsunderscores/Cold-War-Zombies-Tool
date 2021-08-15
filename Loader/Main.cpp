#include "Main.h"
int main()
{
    SetConsoleTitle(rand_str(12).c_str());
    DoBypassInstaller();
    menuStart();
}