#pragma once
#include "SetOnNode.h"

class SetOnClassList {
private:
    Node* start;
public:
    SetOnClassList();
    SetOnClassList(int count, int min, int max);
    ~SetOnClassList();

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
    bool is_subset(SetOnClassList* B);

    // Равенство двух множеств А - В
    // Входные параметры: указатель на множество В.
    // Выходные параметры: логическое значение True, если А равно В.
    bool is_equal(SetOnClassList* B);

    // Объединение двух множеств
    // Входные параметры: два указателя на множества А и В.
    // Выходные параметры: множество-результат.
    static SetOnClassList* union_sets(SetOnClassList* A, SetOnClassList* B);

    // Пересечение двух множеств
    // Входные параметры: два указателя на множества А и В.
    // Выходные параметры: множество-результат. 
    static SetOnClassList* intersect_sets(SetOnClassList* A, SetOnClassList* B);

    // Разность множеств
    // Входные параметры: два указателя на множества А и В.
    // Выходные параметры: множество-результат.
    static SetOnClassList* difference_sets(SetOnClassList* A, SetOnClassList* B);

    // Симметричная разность
    // Входные параметры: два указателя на множества А и В.
    // Выходные параметры: множество-результат.
    static SetOnClassList* symmetric_difference_sets(SetOnClassList* A, SetOnClassList* B);
};