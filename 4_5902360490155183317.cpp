#include <iostream>
#include <string>
#include <regex>
#include <complex>
#include <cmath>
using namespace std;
auto extract_complex(string &str)
{
    int counter = 0;
    int counter_2 = 0;
    int counter_3 = 0;
    string real;
    float real_num;
    string imag;
    float imag_num;
    string sign;
    bool negative = false;
    bool decimal = false;

    for (size_t i = 0; i < str.length(); i++)
    {
        if (isdigit(str[i]))
        {
            counter = counter + 1;
        }
        else if (str[0] == '-')
        {
            negative = true;
            continue;
        }
        else if (str[i] == '.')
        {
            decimal = true;
            continue;
        }
        else
        {
            break;
        }
    }

    if (negative == true)
    {
        for (size_t j = 1; j < str.length(); j++)
        {
            if (isdigit(str[j]) || str[j] == '.')
            {
                counter_2 = counter_2 + 1;
            }
            else
            {
                break;
            }
        }

        real = str.substr(1, counter_2);
        real_num = stof(real, nullptr);
        real_num = -real_num;
        cout << "Real part : " << real_num << endl;

        sign = str[counter_2 + 1];
        cout << "sign : " << sign << endl;

        imag = str.substr(counter_2 + 2, str.length());
        imag_num = stof(imag, nullptr);
        cout << "Imaginary part : " << imag_num << endl;

        return real_num, sign, imag_num;
    }
    else if (decimal == true)
    {
        for (size_t k = 0; k < str.length(); k++)
        {
            if (isdigit(str[k]) || str[k] == '.')
            {
                counter_3 += 1;
            }
            else
            {
                break;
            }
        }
        real = str.substr(0, counter_3);
        real_num = stof(real, nullptr);
        cout << "Real part : " << real_num << endl;

        sign = str[counter_3];
        cout << "sign : " << sign << endl;

        imag = str.substr(counter_3 + 1, str.length());
        imag_num = stof(imag, nullptr);
        cout << "Imaginary part : " << imag_num << endl;

        return real_num, sign, imag_num;
    }
    else
    {
        real = str.substr(0, counter);
        real_num = stof(real, nullptr);
        cout << "Real part : " << real_num << endl;

        sign = str[counter];
        cout << "sign : " << sign << endl;

        imag = str.substr(counter + 1, str.length());
        imag_num = stof(imag, nullptr);
        cout << "Imaginary part : " << imag_num << endl;

        return real_num, sign, imag_num;
    }
}
bool check_complex(string& str)
{
    regex check_complex("[0-9](.[0-9*])*+[-+]+[0-9](.[0-9*])*+[i]");
    return regex_match(str, check_complex); 
}
int main()
{
    int n;
    string num;
    cout << "Please enter the first complex number : ";
    while (true)
    {
        cin >> num;
        if (check_complex(num))
        {
            extract_complex(num);
            return false;
        }
        else
        {
            cout << "Invalid input\nTry again: ";
        }
    }
    cout << "\nPlease enter the second complex number : ";
    while (true)
    {
        cin >> num;
        if (check_complex(num))
        {
            extract_complex(num);
            return false;
        }
        else
        {
            cout << "Invalid input\nTry again: ";
        }
    }
    cout << "What's the operation you want to do:\n1+add\n2_sub\n3_multi\n4+div\n5_exit";
    // if (n==1)
    // {
    //     /* code */
    // }
    
    return 0;
}