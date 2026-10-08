#pragma once
#include <map>

class SetOnMultimap {
private:
    std::multimap<int, int> set;
public:
    SetOnMultimap();
    SetOnMultimap(int count, int min, int max);
    ~SetOnMultimap();

    // Пустое множество?
    // Выходные параметры: логическое значение.
    bool is_empty_set();

    // Проверка принадлежности элемента множеству
    // Входные параметры: значение элемента. 
    // Выходные параметры: логическое значение. 
    bool contains_element(int value);

    // Добавление элемента в множество
    // Входные параметры: добавляемое в список значение. 
    void add_element(int value);

    // Мощность множества
    // Выходные параметры: целочисленное значение. 
    int get_size();

    // Вывод множества в строку
    // Входные параметры: символ разделителя. 
    // Выходные параметры: строка, содержащая элементы множества, разделенные символом разделителя. 
    std::string set_to_string(char separator);

    // Подмножество А-В
    // Входные параметры: указатель на множество В.
    // Выходные параметры: логическое значение True, если А является подмножеством В. 
    bool is_subset(SetOnMultimap* B);

    // Равенство двух множеств А - В
    // Входные параметры: указатель на множество В.
    // Выходные параметры: логическое значение True, если А равно В.
    bool is_equal(SetOnMultimap* B);

    // Объединение двух множеств
    // Входные параметры: два указателя на множества А и В.
    // Выходные параметры: множество-результат.
    static SetOnMultimap* union_sets(SetOnMultimap* A, SetOnMultimap* B);

    // Пересечение двух множеств
    // Входные параметры: два указателя на множества А и В.
    // Выходные параметры: множество-результат. 
    static SetOnMultimap* intersect_sets(SetOnMultimap* A, SetOnMultimap* B);

    // Разность множеств
    // Входные параметры: два указателя на множества А и В.
    // Выходные параметры: множество-результат.
    static SetOnMultimap* difference_sets(SetOnMultimap* A, SetOnMultimap* B);

    // Симметричная разность
    // Входные параметры: два указателя на множества А и В.
    // Выходные параметры: множество-результат.
    static SetOnMultimap* symmetric_difference_sets(SetOnMultimap* A, SetOnMultimap* B);
};