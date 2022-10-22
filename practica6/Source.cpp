#ifndef UNICODE
#define UNICODE
#endif 

#include <windows.h>
#include "resource.h"
#include <string>
#include <iostream>
#include <math.h>
HWND ghDlg = 0;
wchar_t char_num1[5];
wchar_t char_num2[5];
wchar_t char_num3[5];
wchar_t resultado[5];
wchar_t num_temp[5];
HWND h_Num1;
HWND h_Num2;
HWND h_Num3;
wint_t num2;
wint_t num3;
wint_t num1;

BOOL CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ PWSTR pCmdLine, _In_ int nCmdShow)
{
    ghDlg = CreateDialog(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), 0, (DLGPROC)WindowProc);
    ShowWindow(ghDlg, nCmdShow);
    MSG msg;
    ZeroMemory(&msg, sizeof(MSG));
    while (GetMessage(&msg, 0, 0, 0))
    {
        if (ghDlg == 0 || !IsDialogMessage(ghDlg, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }
    return (int)msg.wParam;
}

BOOL CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg)
    {

    case WM_INITDIALOG:
        h_Num1 = GetDlgItem(hwnd, EDT_Num1);
        h_Num2 = GetDlgItem(hwnd, EDT_Num2);
        h_Num3 = GetDlgItem(hwnd, EDT_Num3);
        /*h_static = GetDlgItem(hwnd, StaticResultado);
        h_icono = GetDlgItem(hwnd, staticicono);*/

        break;

    case WM_COMMAND:
        switch (LOWORD(wParam))
        {
        case boton1:

            GetWindowText(h_Num1, (LPWSTR)char_num1, 5);
            GetWindowText(h_Num2, (LPWSTR)char_num2, 5);

            num1 = _wtoi(char_num1);
            num2 = _wtoi(char_num2);
            num3 = num1 + num2;

            _itow_s(num3, resultado, 5, 10);

            SetWindowText(h_Num3, (LPWSTR)resultado); 
                break;
        case boton2:

            GetWindowText(h_Num1, (LPWSTR)char_num1, 5);
            GetWindowText(h_Num2, (LPWSTR)char_num2, 5);

            num1 = _wtoi(char_num1);
            num2 = _wtoi(char_num2);
            num3 = num1 - num2;

            _itow_s(num3, resultado, 5, 10);

            SetWindowText(h_Num3, (LPWSTR)resultado);
            break;
        case boton3:

            GetWindowText(h_Num1, (LPWSTR)char_num1, 5);
            GetWindowText(h_Num2, (LPWSTR)char_num2, 5);

            num1 = _wtoi(char_num1);
            num2 = _wtoi(char_num2);
            num3 = num1 * num2;

            _itow_s(num3, resultado, 5, 10);

            SetWindowText(h_Num3, (LPWSTR)resultado);
            break;

        case boton4:

            GetWindowText(h_Num1, (LPWSTR)char_num1, 5);
            GetWindowText(h_Num2, (LPWSTR)char_num2, 5);

            num1 = _wtoi(char_num1);
            num2 = _wtoi(char_num2);
            num3 = num1 / num2;

            _itow_s(num3, resultado, 5, 10);

            SetWindowText(h_Num3, (LPWSTR)resultado);
            break;
        case boton5:

            GetWindowText(h_Num1, (LPWSTR)char_num1, 5);
           

            num1 = _wtoi(char_num1);
 
            num3 = num1 * num1;

            _itow_s(num3, resultado, 5, 10);

            SetWindowText(h_Num3, (LPWSTR)resultado);
            break;
        }
        break;

    case WM_CLOSE:
        DestroyWindow(hwnd);
        return 0;

    case WM_DESTROY:
        PostQuitMessage(0);
        break;

    }

    return FALSE;
}