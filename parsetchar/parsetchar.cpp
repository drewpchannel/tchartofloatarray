// parsetchar.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <tchar.h>
#include <string>

using namespace std;

int main()
{
    TCHAR info[260];
    _tcscpy(info, _T("X=-770.003 Y=370.000 Z=228.417"));
    wstring test(&info[0]);
    string test2(test.begin(), test.end());
    float results[100];
    string x;
    int k = 0;

    for (int i = 0; i < test2.size() + 1; i++)
    {
        if (isspace(test2[i]) || i == test2.size())
        {
            cout << "adding " << x << " to k" << endl;
            results[k] = stof(x);
            k++;
            x.clear();
        }
        else
        {
            if (isdigit(test2[i]) || test2[i] == '.' || test2[i] == '-')
            {
                x += test2[i];
                //cout << "trying to add " << test2[i] << " to " << x << endl;
            }
        }
    }
    cout << results[0] << " " << results[1] << " " << results[2] << endl;
}
