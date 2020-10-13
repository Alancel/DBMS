#include <limits>
#include <cctype>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

void    ft_init(char *arr, size_t size);
string  ft_prsize_t(char *arr, size_t size);
char    ft_average(const char *arr, size_t size);
bool    ft_check_size(size_t size);
char    ft_check_char(int value);


int main(int argc, char** argv)
{
    size_t size;
    string str;

    cout << "Input array size: ";
    cin >> size;

    if (ft_check_size(size))
    {
        const auto arr = new char[size];

        ft_init(arr, size);
        cout << "generated array: " << ft_prsize_t(arr, size) << endl;
        cout << "average value: " << ft_average(arr, size) << endl;
        delete[] arr;
    }
    else
    {
        cout << "Wrong array size" << endl;
    }
}

void ft_init(char *arr, const size_t size)
{
    srand(static_cast<unsigned int>(time(nullptr)));

    const char max_char = 127;
    const char min_char = 15;

    for (size_t i = 0; i < size;)
    {
        const char ch = rand() % (max_char - min_char) + min_char;
        if (isalnum(ch))
        {
            arr[i++] = ch;
        }
    }
}

string ft_prsize_t(char *arr, const size_t size)
{
    return string(arr, size);
}

char  ft_average(const char *arr, const size_t size)
{
    int sum = 0;
    for (size_t i = 0; i < size; i++)
        sum += arr[i];
    return ft_check_char(sum);
}

bool ft_check_size(const size_t size)
{
    return size > 0 && size < numeric_limits<size_t>::max();
}

char ft_check_char(const int value)
{
    const char max_visible_char = 127;
    return static_cast<char>(value % max_visible_char);
}
