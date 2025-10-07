#include <iostream>
#include <vector>
#include <locale>

using namespace std;

int bin_search(vector<int> mass, int key) // Алг. сложность O(log(N))
{
    int l = 0;
    int r = mass.size() - 1;

    while (r > l)
    {
        int mid = (l + r) / 2;

        if (mass[mid] == key)
        {
            return mid;
        }

        else if (mass[mid] < key)
        {
            l = mid + 1;
        }

        else
        {
            r = mid;
        }
    }

    return -1;
}

int end_to_end_search(vector<int> mass, int key) // Алг. сложность O(N)
{
    int index = 0;

    while (index != mass.size())
    {
        if (mass[index] == key)
        {
            return index;
        }

        else
        {
            index++;
        }
    }

    return -1;
}

int interpolating_search(vector<int> mass, int key) // Алг. сложность варьируется от O(log(log(N))) до O(N)
{
    int l = 0, r = mass.size() - 1, mid;

    while (mass[l] < key && mass[r] >= key)
    {
        mid = l +((key - mass[l]) * (r - l)) / (mass[r] - mass[l]);

        if (mass[mid] < key)
        {
            l = mid + 1;
        }

        else
        {
            if (mass[mid] > key)
            {
                r = mid -1;
            }

            else
            {
                return mid;
            }
        }
    }

    if (mass[l] == key)
    {
        return l;
    }

    else
    {
        return -1;
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");

    vector<int> nums = {1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
    int target = 23;

    cout << "Поиск индекса элемента: " << target << endl;
    cout << "Массив: ";

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }

    cout << endl;

    int r_b = bin_search(nums,target), r_en = end_to_end_search(nums, target), r_in = interpolating_search(nums, target);
    cout << "Бинарный поиск\n" << "Индекс элемента: " << r_b << endl;
    cout << "Сквозной поиск\n" << "Индекс элемента: " << r_en << endl;
    cout << "Интерполяционный поиск\n" << "Индекс элемента: " << r_in << endl;

    if (r_b == r_en && r_b == r_in && r_en == r_in)
    {
        cout << "Результаты совпадают" << endl;
    }

    else
    {
        cout << "Результаты НЕ совпадают" << endl;
    }

    return 0;
}
