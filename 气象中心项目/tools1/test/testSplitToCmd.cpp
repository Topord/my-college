/*g++ -g -o testSplitToCmd testSplitToCmd.cpp -I/project/public /project/public/_public.cpp*/
#include "_public.h"
int main(int argc, char* argv[])
{
    char str[64] = "123,dasd,qweq,v,dasd";

    CCmdStr Cmdstr;
    Cmdstr.SplitToCmd(str, ",");

    printf("拆分个数为 = %d\n", Cmdstr.CmdCount());

    for (int i = 0; i < Cmdstr.CmdCount(); i++)
    {
        cout << Cmdstr.m_vCmdStr[i] << endl;
    }

    return 0;
}