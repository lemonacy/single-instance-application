// single-instance-application.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>
#include <conio.h>

int main() {
    HANDLE h = CreateMutex(NULL, FALSE, TEXT("{0D9949D7-512A-4CDC-AE77-A40E55719A60}"));
    if (GetLastError() == ERROR_ALREADY_EXISTS) {
        MessageBox(NULL, TEXT("There is an instance of single-instance-application already running."), TEXT("Warning"), MB_OK);
        if (h != NULL)
            CloseHandle(h);
        return 1;
    }

    printf("press any key to exit . . . ");
    _getch();

    if (h != NULL)
        CloseHandle(h);

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started:
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
