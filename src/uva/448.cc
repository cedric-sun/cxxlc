#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
using namespace std;
const string operator_list[] =
{
    "ADD", "SUB", "MUL", "DIV", "MOV", "BREQ", "BRLE",
    "BRLS", "BRGE", "BRGR", "BRNE", "BR", "AND", "OR", "XOR", "NOT"
};

string& hex2bin(string &hexstr, string &binstr)
{
    string temp;
    binstr.clear();
    for (int i = 0, j = 0; i<4; i++, j = 0)
    {
        temp = "0000";
        int dec = hexstr[i] >= 'A' ? hexstr[i] - 'A' + 10 : hexstr[i] - '0';
        while (dec)
        {
            temp[j++] = dec % 2 + '0';
            dec /= 2;
        }
        reverse(temp.begin(), temp.end());
        binstr += temp;
    }
    return binstr;
}
string& bin2dec(string &binstr, string &decstr)
{
    int dec = 0, length = binstr.length();
    char str[6];
    for (int i = 0; i<length; i++)
    {
        dec += (binstr[length - i - 1] - '0')*(int)(pow(2 * 1.0, i*1.0) + 0.5);
    }
    sprintf(str, "%d", dec);
    decstr = str;
    return decstr;
}
string& getoperand(string &fourhex, string &operand)
{
    string bin, dec;
    hex2bin(fourhex, bin);
    if (bin[0] == '0')
    {
        if (bin[1] == '0')
        {
            string bin_from_2(bin, 2);
            operand = "R" + bin2dec(bin_from_2, dec);
        }
        else
        {
            string bin_from_2(bin, 2);
            operand = "$" + bin2dec(bin_from_2, dec);
        }
    }
    else
    {
        if (bin[1] == '0')
        {
            string bin_from_2(bin, 2);
            operand = "PC+" + bin2dec(bin_from_2, dec);
        }
        else
        {
            string bin_from_2(bin, 2);
            operand = bin2dec(bin_from_2, dec);
        }
    }
    return operand;
}
int main()
{
    char _operator, temp;
    string operand, fourhex;
    while (cin >> _operator)
    {
        cout << operator_list[_operator >= 'A' ? _operator - 'A' + 10 : _operator - '0'] << ' ';
        switch (_operator)
        {
        case 'C':
        case 'D':
        case 'E':
            for (int i = 0, j = 0; i < 3; i++, j = 1)
            {
                while (fourhex.length() < 4)
                {
                    cin.get(temp);
                    if (temp != '\n')
                        fourhex += temp;
                }
                if (j)
                    cout << ',';
                cout << getoperand(fourhex, operand);
                fourhex.clear();
                operand.clear();
            }
            break;
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
            for (int i = 0, j = 0; i < 2; i++, j = 1)
            {
                while (fourhex.length() < 4)
                {
                    cin.get(temp);
                    if (temp != '\n')
                        fourhex += temp;
                }
                if (j)
                    cout << ',';
                cout << getoperand(fourhex, operand);
                fourhex.clear();
                operand.clear();
            }
            break;
        default:
            while (fourhex.length() < 4)
            {
                cin.get(temp);
                if (temp != '\n')
                    fourhex += temp;
            }
            cout << getoperand(fourhex, operand);
            fourhex.clear();
            operand.clear();
        }
        cout << endl;
    }
    return 0;
}
