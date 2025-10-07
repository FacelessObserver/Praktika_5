#include <iostream>
#include <vector>
#include <locale>

using namespace std;

int bin_search(vector<int> mass, int key, int& iters) // Алг. сложность O(log(N))
{
    int l = 0;
    int r = mass.size() - 1;

    while (r > l)
    {
        iters ++;

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

int end_to_end_search(vector<int> mass, int key, int& iters) // Алг. сложность O(N)
{
    int index = 0;

    while (index != mass.size())
    {
        iters++;

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

int interpolating_search(vector<int> mass, int key, int& iters) // Алг. сложность варьируется от O(log(log(N))) до O(N)
{
    int l = 0, r = mass.size() - 1, mid;

    while (mass[l] < key && mass[r] >= key)
    {
        iters++;
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

    vector<int> nums = {1, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113};
    int target = 97;

    cout << "Поиск индекса элемента: " << target << endl;
    cout << "Массив: ";

    for (int i = 0; i < nums.size(); i++)
    {
        cout << nums[i] << " ";
    }

    cout << "\nКоличество элементов: " << nums.size() << endl;

    int iters_bin = 0, iters_en = 0, iters_in = 0;
    cout << "Бинарный поиск\n" << "Индекс элемента: " << bin_search(nums, target, iters_bin) << " Число итераций: " << iters_bin << endl;
    cout << "Сквозной поиск\n" << "Индекс элемента: " << end_to_end_search(nums, target, iters_en) << " Число итераций: " << iters_en << endl;
    cout << "Интерполяционный поиск\n" << "Индекс элемента: " << interpolating_search(nums, target, iters_in) << " Число итераций: " << iters_in << endl;

    return 0;
}
