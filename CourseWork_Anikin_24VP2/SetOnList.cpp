#include <string>
#include "SetOnList.h"

SetOnList::SetOnList() {};

SetOnList::SetOnList(int count, int min, int max) : SetOnList()
{
    if (min > max) return;

    int possibleValues = max - min + 1;

    if (count > possibleValues) return;

    while (get_size() < count)
    {
        int value = rand() % possibleValues + min;
        add_element(value);
    }
};

SetOnList::~SetOnList()
{
    set.clear();
};

bool SetOnList::is_empty_set()
{
    return set.empty();
};

bool SetOnList::contains_element(int value)
{
    if (!is_empty_set())
    {
        for (const auto& elem : set)
        {
            if (elem == value)
                return true;
        }
    }

    return false;
};

void SetOnList::add_element(int value)
{
    if (!contains_element(value))
        set.push_front(value);
};

int SetOnList::get_size()
{
    return set.size();
};

std::string SetOnList::set_to_string(char separator)
{
    if (is_empty_set())
        return "empty";

    std::string result{};

    for (const auto& elem : set)
    {
        result += std::to_string(elem);
        result += separator;
    }

    return result.erase(result.length() - 1);
};

bool SetOnList::is_subset(SetOnList* B)
{
    if (!is_empty_set())
    {
        for (const auto& elem : set)
        {
            if (!B->contains_element(elem))
                return false;
        }
    }

    return true;
};

bool SetOnList::is_equal(SetOnList* B)
{
    return this->is_subset(B) && B->is_subset(this);
};

SetOnList* SetOnList::union_sets(SetOnList* A, SetOnList* B)
{
    SetOnList* result = new SetOnList();

    for (const auto& elem : A->set)
    {
        result->add_element(elem);
    }

    for (const auto& elem : B->set)
    {
        result->add_element(elem);
    }

    return result;
};

SetOnList* SetOnList::intersect_sets(SetOnList* A, SetOnList* B)
{
    SetOnList* result = new SetOnList();

    if (!A->is_empty_set() && !B->is_empty_set())
    {
        for (const auto& elem : A->set)
        {
            if (B->contains_element(elem))
            {
                result->add_element(elem);
            }
        }
    }

    return result;
};

SetOnList* SetOnList::difference_sets(SetOnList* A, SetOnList* B)
{
    SetOnList* result = new SetOnList();

    if (!A->is_empty_set())
    {
        for (const auto& elem : A->set)
        {
            if (!B->contains_element(elem))
            {
                result->add_element(elem);
            }
        }
    }

    return result;
};

SetOnList* SetOnList::symmetric_difference_sets(SetOnList* A, SetOnList* B)
{
    return difference_sets(union_sets(A, B), intersect_sets(B, A));
};