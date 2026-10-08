#include <string>
#include "SetOnMultimap.h"

SetOnMultimap::SetOnMultimap() {};

SetOnMultimap::SetOnMultimap(int count, int min, int max) : SetOnMultimap()
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

SetOnMultimap::~SetOnMultimap()
{
    set.clear();
};

bool SetOnMultimap::is_empty_set()
{
    return set.empty();
};

bool SetOnMultimap::contains_element(int value)
{
    return set.contains(value);
};

void SetOnMultimap::add_element(int value)
{
    set.insert({ value, value });
};

int SetOnMultimap::get_size()
{
    return set.size();
};

std::string SetOnMultimap::set_to_string(char separator)
{
    if (is_empty_set())
        return "empty";

    std::string result{};

    for (const auto& elem : set)
    {
        result += std::to_string(elem.second);
        result += separator;
    }

    return result.erase(result.length() - 1);
};

bool SetOnMultimap::is_subset(SetOnMultimap* B)
{
    if (!is_empty_set())
    {
        for (const auto& elem : set)
        {
            if (!B->contains_element(elem.first))
                return false;
        }
    }

    return true;
};

bool SetOnMultimap::is_equal(SetOnMultimap* B)
{
    return this->is_subset(B) && B->is_subset(this);
};

SetOnMultimap* SetOnMultimap::union_sets(SetOnMultimap* A, SetOnMultimap* B)
{
    SetOnMultimap* result = new SetOnMultimap();

    for (const auto& elem : A->set)
    {
        result->add_element(elem.second);
    }

    for (const auto& elem : B->set)
    {
        result->add_element(elem.second);
    }

    return result;
};

SetOnMultimap* SetOnMultimap::intersect_sets(SetOnMultimap* A, SetOnMultimap* B)
{
    SetOnMultimap* result = new SetOnMultimap();

    if (!A->is_empty_set() && !B->is_empty_set())
    {
        for (const auto& elem : A->set)
        {
            if (B->contains_element(elem.first))
            {
                result->add_element(elem.second);
            }
        }
    }

    return result;
};

SetOnMultimap* SetOnMultimap::difference_sets(SetOnMultimap* A, SetOnMultimap* B)
{
    SetOnMultimap* result = new SetOnMultimap();

    if (!A->is_empty_set())
    {
        for (const auto& elem : A->set)
        {
            if (!B->contains_element(elem.first))
            {
                result->add_element(elem.second);
            }
        }
    }

    return result;
};

SetOnMultimap* SetOnMultimap::symmetric_difference_sets(SetOnMultimap* A, SetOnMultimap* B)
{
    return difference_sets(union_sets(A, B), intersect_sets(B, A));
};