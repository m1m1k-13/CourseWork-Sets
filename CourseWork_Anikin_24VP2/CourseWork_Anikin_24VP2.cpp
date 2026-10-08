#include <iostream>
#include <string>
#include <iomanip>
#include <chrono>

#include "SetOnNode.h"
#include "SetOnClassList.h"
#include "SetOnList.h"
#include "SetOnSet.h"
#include "SetOnMap.h"
#include "SetOnMultimap.h"

using namespace std;

string center(const string& text, int width);

int main()
{
    setlocale(LC_ALL, "");
    auto times = time(NULL);
    srand(times);

    cout << "Курсовая работа Аникин А. А. 24ВП2" << endl;
    cout << endl;

    int size_A{};
    int size_B{};

    while (true)
    {
        cout << "Введите мощность множества A (от 0 до 100000): ";
        cin >> size_A;

        if (cin.fail() || size_A < 0 || size_A > 100000)
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Неверный ввод! Введите мощность множества A в диапазоне от 0 до 100000.\n" << endl;
        }
        else break;
    }

    while (true)
    {
        cout << "Введите мощность множества B (от 0 до 100000): ";
        cin >> size_B;

        if (cin.fail() || size_B < 0 || size_B > 100000)
        {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Неверный ввод! Введите мощность множества B в диапазоне от 0 до 100000.\n" << endl;
        }
        else break;
    }

    cout << endl;

    const int width = 20;
    const char header_delimiter = '=';
    const char delimiter = '-';
    const char row_delimiter = '|';

    string columns[]
    { 
        "Операция",
        "Односвязный список",
        "Класс \"Cписок\"",
        "List",
        "Set",
        "Map",
        "Multimap"
    };

    string rows[]
    { 
        "Создание множества",
        "Мощность",
        "Подмножество A - A",
        "Подмножество B - A",
        "Равенство A = A",
        "Равенство B = A",
        "Объединение A и B",
        "Пересечение A и B",
        "Разность A-B",
        "Разность B-A",
        "Симметричная разность A и B"
    };

    cout << setfill(header_delimiter) << setw(31 + (width + 1) * 6) << "" << endl;
    cout << center(columns[0], 30) << row_delimiter;
    for (int col = 1; col < 7; col++)
    {
        cout << center(columns[col], width) << row_delimiter;
    }
    cout << endl;
    cout << setfill(header_delimiter) << setw(31 + (width + 1) * 6) << "" << endl;


    // Измерение
    long results[11][6]{};

    Node* SetOnNodeA, *SetOnNodeB;
    SetOnClassList* SetOnClassListA, *SetOnClassListB;
    SetOnList* SetOnListA, *SetOnListB;
    SetOnSet* SetOnSetA, *SetOnSetB;
    SetOnMap* SetOnMapA, *SetOnMapB;
    SetOnMultimap* SetOnMultimapA, *SetOnMultimapB;

    // Создание множества
    auto start_time = chrono::high_resolution_clock::now();
    SetOnNodeA = create_set(size_A, 0, 10 * size_A);
    auto end_time = chrono::high_resolution_clock::now();
    results[0][0] = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
    SetOnNodeB = create_set(size_B, 0, 10 * size_B);

    start_time = chrono::high_resolution_clock::now();
    SetOnClassListA = new SetOnClassList(size_A, 0, 10 * size_A);
    end_time = chrono::high_resolution_clock::now();
    results[0][1] = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
    SetOnClassListB = new SetOnClassList(size_B, 0, 10 * size_B);

    start_time = chrono::high_resolution_clock::now();
    SetOnListA = new SetOnList(size_A, 0, 10 * size_A);
    end_time = chrono::high_resolution_clock::now();
    results[0][2] = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
    SetOnListB = new SetOnList(size_B, 0, 10 * size_B);

    start_time = chrono::high_resolution_clock::now();
    SetOnSetA = new SetOnSet(size_A, 0, 10 * size_A);
    end_time = chrono::high_resolution_clock::now();
    results[0][3] = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
    SetOnSetB = new SetOnSet(size_B, 0, 10 * size_B);

    start_time = chrono::high_resolution_clock::now();
    SetOnMapA = new SetOnMap(size_A, 0, 10 * size_A);
    end_time = chrono::high_resolution_clock::now();
    results[0][4] = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
    SetOnMapB = new SetOnMap(size_B, 0, 10 * size_B);

    start_time = chrono::high_resolution_clock::now();
    SetOnMultimapA = new SetOnMultimap(size_A, 0, 10 * size_A);
    end_time = chrono::high_resolution_clock::now();
    results[0][5] = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();
    SetOnMultimapB = new SetOnMultimap(size_B, 0, 10 * size_B);


    // Мощность
    start_time = chrono::high_resolution_clock::now();
    get_size(SetOnNodeA);
    end_time = chrono::high_resolution_clock::now();
    results[1][0] = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    start_time = chrono::high_resolution_clock::now();
    SetOnClassListA->get_size();
    end_time = chrono::high_resolution_clock::now();
    results[1][1] = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    start_time = chrono::high_resolution_clock::now();
    SetOnListA->get_size();
    end_time = chrono::high_resolution_clock::now();
    results[1][2] = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    start_time = chrono::high_resolution_clock::now();
    SetOnSetA->get_size();
    end_time = chrono::high_resolution_clock::now();
    results[1][3] = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    start_time = chrono::high_resolution_clock::now();
    SetOnMapA->get_size();
    end_time = chrono::high_resolution_clock::now();
    results[1][4] = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    start_time = chrono::high_resolution_clock::now();
    SetOnMultimapA->get_size();
    end_time = chrono::high_resolution_clock::now();
    results[1][5] = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();


    // Подмножество A - A
    start_time = chrono::high_resolution_clock::now();
    is_subset(SetOnNodeA, SetOnNodeA);
    end_time = chrono::high_resolution_clock::now();
    results[2][0] = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    start_time = chrono::high_resolution_clock::now();
    SetOnClassListA->is_subset(SetOnClassListA);
    end_time = chrono::high_resolution_clock::now();
    results[2][1] = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    start_time = chrono::high_resolution_clock::now();
    SetOnListA->is_subset(SetOnListA);
    end_time = chrono::high_resolution_clock::now();
    results[2][2] = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    start_time = chrono::high_resolution_clock::now();
    SetOnSetA->is_subset(SetOnSetA);
    end_time = chrono::high_resolution_clock::now();
    results[2][3] = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    start_time = chrono::high_resolution_clock::now();
    SetOnMapA->is_subset(SetOnMapA);
    end_time = chrono::high_resolution_clock::now();
    results[2][4] = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    start_time = chrono::high_resolution_clock::now();
    SetOnMultimapA->is_subset(SetOnMultimapA);
    end_time = chrono::high_resolution_clock::now();
    results[2][5] = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();


    // Подмножество B - A
    start_time = chrono::high_resolution_clock::now();
    is_subset(SetOnNodeB, SetOnNodeA);
    end_time = chrono::high_resolution_clock::now();
    results[3][0] = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    start_time = chrono::high_resolution_clock::now();
    SetOnClassListB->is_subset(SetOnClassListA);
    end_time = chrono::high_resolution_clock::now();
    results[3][1] = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    start_time = chrono::high_resolution_clock::now();
    SetOnListB->is_subset(SetOnListA);
    end_time = chrono::high_resolution_clock::now();
    results[3][2] = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    start_time = chrono::high_resolution_clock::now();
    SetOnSetB->is_subset(SetOnSetA);
    end_time = chrono::high_resolution_clock::now();
    results[3][3] = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    start_time = chrono::high_resolution_clock::now();
    SetOnMapB->is_subset(SetOnMapA);
    end_time = chrono::high_resolution_clock::now();
    results[3][4] = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    start_time = chrono::high_resolution_clock::now();
    SetOnMultimapB->is_subset(SetOnMultimapA);
    end_time = chrono::high_resolution_clock::now();
    results[3][5] = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();


    // Равенство A = A
    start_time = chrono::high_resolution_clock::now();
    are_equal(SetOnNodeA, SetOnNodeA);
    end_time = chrono::high_resolution_clock::now();
    results[4][0] = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    start_time = chrono::high_resolution_clock::now();
    SetOnClassListA->is_equal(SetOnClassListA);
    end_time = chrono::high_resolution_clock::now();
    results[4][1] = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    start_time = chrono::high_resolution_clock::now();
    SetOnListA->is_equal(SetOnListA);
    end_time = chrono::high_resolution_clock::now();
    results[4][2] = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    start_time = chrono::high_resolution_clock::now();
    SetOnSetA->is_equal(SetOnSetA);
    end_time = chrono::high_resolution_clock::now();
    results[4][3] = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    start_time = chrono::high_resolution_clock::now();
    SetOnMapA->is_equal(SetOnMapA);
    end_time = chrono::high_resolution_clock::now();
    results[4][4] = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    start_time = chrono::high_resolution_clock::now();
    SetOnMultimapA->is_equal(SetOnMultimapA);
    end_time = chrono::high_resolution_clock::now();
    results[4][5] = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();


    // Равенство B = A
    start_time = chrono::high_resolution_clock::now();
    are_equal(SetOnNodeB, SetOnNodeA);
    end_time = chrono::high_resolution_clock::now();
    results[5][0] = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    start_time = chrono::high_resolution_clock::now();
    SetOnClassListB->is_equal(SetOnClassListA);
    end_time = chrono::high_resolution_clock::now();
    results[5][1] = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    start_time = chrono::high_resolution_clock::now();
    SetOnListB->is_equal(SetOnListA);
    end_time = chrono::high_resolution_clock::now();
    results[5][2] = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    start_time = chrono::high_resolution_clock::now();
    SetOnSetB->is_equal(SetOnSetA);
    end_time = chrono::high_resolution_clock::now();
    results[5][3] = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    start_time = chrono::high_resolution_clock::now();
    SetOnMapB->is_equal(SetOnMapA);
    end_time = chrono::high_resolution_clock::now();
    results[5][4] = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    start_time = chrono::high_resolution_clock::now();
    SetOnMultimapB->is_equal(SetOnMultimapA);
    end_time = chrono::high_resolution_clock::now();
    results[5][5] = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();


    // Объединение A и B
    start_time = chrono::high_resolution_clock::now();
    union_sets(SetOnNodeA, SetOnNodeB);
    end_time = chrono::high_resolution_clock::now();
    results[6][0] = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    start_time = chrono::high_resolution_clock::now();
    SetOnClassList::union_sets(SetOnClassListA, SetOnClassListB);
    end_time = chrono::high_resolution_clock::now();
    results[6][1] = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    start_time = chrono::high_resolution_clock::now();
    SetOnList::union_sets(SetOnListA, SetOnListB);
    end_time = chrono::high_resolution_clock::now();
    results[6][2] = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    start_time = chrono::high_resolution_clock::now();
    SetOnSet::union_sets(SetOnSetA, SetOnSetB);
    end_time = chrono::high_resolution_clock::now();
    results[6][3] = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    start_time = chrono::high_resolution_clock::now();
    SetOnMap::union_sets(SetOnMapA, SetOnMapB);
    end_time = chrono::high_resolution_clock::now();
    results[6][4] = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    start_time = chrono::high_resolution_clock::now();
    SetOnMultimap::union_sets(SetOnMultimapA, SetOnMultimapB);
    end_time = chrono::high_resolution_clock::now();
    results[6][5] = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();


    // Пересечение A и B
    start_time = chrono::high_resolution_clock::now();
    intersect_sets(SetOnNodeA, SetOnNodeB);
    end_time = chrono::high_resolution_clock::now();
    results[7][0] = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    start_time = chrono::high_resolution_clock::now();
    SetOnClassList::intersect_sets(SetOnClassListA, SetOnClassListB);
    end_time = chrono::high_resolution_clock::now();
    results[7][1] = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    start_time = chrono::high_resolution_clock::now();
    SetOnList::intersect_sets(SetOnListA, SetOnListB);
    end_time = chrono::high_resolution_clock::now();
    results[7][2] = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    start_time = chrono::high_resolution_clock::now();
    SetOnSet::intersect_sets(SetOnSetA, SetOnSetB);
    end_time = chrono::high_resolution_clock::now();
    results[7][3] = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    start_time = chrono::high_resolution_clock::now();
    SetOnMap::intersect_sets(SetOnMapA, SetOnMapB);
    end_time = chrono::high_resolution_clock::now();
    results[7][4] = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    start_time = chrono::high_resolution_clock::now();
    SetOnMultimap::intersect_sets(SetOnMultimapA, SetOnMultimapB);
    end_time = chrono::high_resolution_clock::now();
    results[7][5] = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();


    // Разность A-B
    start_time = chrono::high_resolution_clock::now();
    difference_sets(SetOnNodeA, SetOnNodeB);
    end_time = chrono::high_resolution_clock::now();
    results[8][0] = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    start_time = chrono::high_resolution_clock::now();
    SetOnClassList::difference_sets(SetOnClassListA, SetOnClassListB);
    end_time = chrono::high_resolution_clock::now();
    results[8][1] = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    start_time = chrono::high_resolution_clock::now();
    SetOnList::difference_sets(SetOnListA, SetOnListB);
    end_time = chrono::high_resolution_clock::now();
    results[8][2] = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    start_time = chrono::high_resolution_clock::now();
    SetOnSet::difference_sets(SetOnSetA, SetOnSetB);
    end_time = chrono::high_resolution_clock::now();
    results[8][3] = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    start_time = chrono::high_resolution_clock::now();
    SetOnMap::difference_sets(SetOnMapA, SetOnMapB);
    end_time = chrono::high_resolution_clock::now();
    results[8][4] = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    start_time = chrono::high_resolution_clock::now();
    SetOnMultimap::difference_sets(SetOnMultimapA, SetOnMultimapB);
    end_time = chrono::high_resolution_clock::now();
    results[8][5] = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();


    // Разность B-A
    start_time = chrono::high_resolution_clock::now();
    difference_sets(SetOnNodeB, SetOnNodeA);
    end_time = chrono::high_resolution_clock::now();
    results[9][0] = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    start_time = chrono::high_resolution_clock::now();
    SetOnClassList::difference_sets(SetOnClassListB, SetOnClassListA);
    end_time = chrono::high_resolution_clock::now();
    results[9][1] = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    start_time = chrono::high_resolution_clock::now();
    SetOnList::difference_sets(SetOnListB, SetOnListA);
    end_time = chrono::high_resolution_clock::now();
    results[9][2] = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    start_time = chrono::high_resolution_clock::now();
    SetOnSet::difference_sets(SetOnSetB, SetOnSetA);
    end_time = chrono::high_resolution_clock::now();
    results[9][3] = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    start_time = chrono::high_resolution_clock::now();
    SetOnMap::difference_sets(SetOnMapB, SetOnMapA);
    end_time = chrono::high_resolution_clock::now();
    results[9][4] = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    start_time = chrono::high_resolution_clock::now();
    SetOnMultimap::difference_sets(SetOnMultimapB, SetOnMultimapA);
    end_time = chrono::high_resolution_clock::now();
    results[9][5] = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();


    // Симметричная разность A и B
    start_time = chrono::high_resolution_clock::now();
    symmetric_difference_sets(SetOnNodeB, SetOnNodeA);
    end_time = chrono::high_resolution_clock::now();
    results[10][0] = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    start_time = chrono::high_resolution_clock::now();
    SetOnClassList::symmetric_difference_sets(SetOnClassListA, SetOnClassListB);
    end_time = chrono::high_resolution_clock::now();
    results[10][1] = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    start_time = chrono::high_resolution_clock::now();
    SetOnList::symmetric_difference_sets(SetOnListA, SetOnListB);
    end_time = chrono::high_resolution_clock::now();
    results[10][2] = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    start_time = chrono::high_resolution_clock::now();
    SetOnSet::symmetric_difference_sets(SetOnSetA, SetOnSetB);
    end_time = chrono::high_resolution_clock::now();
    results[10][3] = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    start_time = chrono::high_resolution_clock::now();
    SetOnMap::symmetric_difference_sets(SetOnMapA, SetOnMapB);
    end_time = chrono::high_resolution_clock::now();
    results[10][4] = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();

    start_time = chrono::high_resolution_clock::now();
    SetOnMultimap::symmetric_difference_sets(SetOnMultimapA, SetOnMultimapB);
    end_time = chrono::high_resolution_clock::now();
    results[10][5] = chrono::duration_cast<chrono::microseconds>(end_time - start_time).count();



    for (int row = 0; row < 11; row++)
    {
        cout << left << setw(30) << setfill(' ') << rows[row] << row_delimiter;
        for (int col = 0; col < 6; col++)
        {
            cout << center(to_string(results[row][col]), width) << row_delimiter;
        }
        cout << endl;
        cout << setfill(delimiter) << setw(31 + (width + 1) * 6) << "" << endl;
    }
}

string center(const string& text, int width)
{
    int len = text.length();
    if (len >= width) return text;

    int left = (width - len) / 2;
    int right = width - len - left;

    return string(left, ' ') + text + string(right, ' ');
}