#include <iostream>
#include <string>
using namespace std;
string words[15];
const string basicnum[28] = { "zero", "one", "two", "three", "four", "five",
                              "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen",
                              "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty", "thirty", "forty",
                              "fifty", "sixty", "seventy", "eighty", "ninety"
                            };
const string neg = "negative";
const string slj[3] = { "hundred", "thousand", "million" };
int valueof(string &str)
{
    int i;
    for (i = 0; i<3; i++)
        if (str == slj[i])
        {
            switch (i)
            {
            case 0:
                return 100;
            case 1:
                return 1000;
            case 2:
                return 1000000;
            }
        }
    for (i = 0; i<28; i++)
        if (str == basicnum[i])
        {
            if (i <= 20)
                return i;
            else
            {
                switch (i)
                {
                case 21:
                    return 30;
                case 22:
                    return 40;
                case 23:
                    return 50;
                case 24:
                    return 60;
                case 25:
                    return 70;
                case 26:
                    return 80;
                case 27:
                    return 90;
                }
            }
        }
}
int valuebetween(int a, int b)
{
    int temp, value, i;
    value = 0;
    for (i = a; i <= b; i++)
    {
        temp = valueof(words[i]);
        if (temp<100)
            value += temp;
        else
            value *= temp;
    }
    return value;
}
int main()
{
    int num, i, wordsmax, k, ifneg, a,rec;
    string line;
    while (getline(cin, line))
    {
        for (i = 0; i<14; i++)
            words[i].clear();
        num = 0;
        wordsmax = 0;
        ifneg = 0;
        for (i = 0; i <= line.length(); i++)
            if (line[i] >= 'a'&&line[i] <= 'z')
                words[wordsmax] += line[i];
            else
            {
                wordsmax++;
            }
        i = 0;
        a = 0;
        if (words[i] == neg)
        {
            ifneg = 1;
            i++;
            a++;
        }
        rec = i;
        for (k = 2; k > 0; k--)
        {
            i = rec;
            while (i < wordsmax)
            {
                if (words[i] == slj[k])
                {
                    num += valuebetween(a, i - 1)*valueof(words[i]);
                    a = i + 1;
                    break;
                }

                i++;
            }
        }
        num += valuebetween(a, wordsmax-1);
        if (ifneg)
            num *= -1;
        cout << num << endl;
    }
    return 0;
}
