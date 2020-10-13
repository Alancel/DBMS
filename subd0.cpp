#include <limits>
#include <cctype>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

void    ft_init(char *arr, int size);
string  ft_print(char *arr, int size);
char     ft_average(char *arr, int size);
bool     ft_check_size(int size);
int     ft_check_char(int value);


int main(int argc, char** argv)
{
  int size;
  string str;

  cout << "Input array size: ";
  cin >> size;

  if (ft_check_size(size))
  {
    char *arr = new char[size];

    ft_init(arr, size);
    cout << "average value: " << ft_average(arr, size) << endl;
    cout << "generated array: " << ft_print(arr, size) << endl;
    delete [] arr;
  }
  else
    cout << "Wrong array size\n";
}

void ft_init(char *arr, int size)
{
  srand(time(0));
  const int char_max = 127;
  const int min_char = 15;

  for (int i = 0; i < size;)
  {
    char ch = min_char +  rand() % char_max;
    if (isalnum(ch))
    {
      arr[i] = ch;
      ++i;
    }
  }
}

string ft_print(char *arr, int size)
{
  string str(arr, size);
  return str;
}

char  ft_average(char *arr, int size)
{
  int tmp = 0;
  char avg;

  for (int i = 0; i < size; i++)
    tmp += arr[i];
  avg = ft_check_char(tmp);
  return avg;
}

bool ft_check_size(int size)
{
  if (size > 0 && size < numeric_limits<int>::max())
    return 1;
  else
    return 0;
}

int ft_check_char(int value)
{
  const int max_visible_char = 127;

  if (value > max_visible_char)
    value = value % max_visible_char;;
  return value;
}
