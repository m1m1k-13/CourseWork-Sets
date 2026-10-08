#include <string>
#include "SetOnMap.h"

SetOnMap::SetOnMap() {};

SetOnMap::SetOnMap(int count, int min, int max) : SetOnMap()
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

SetOnMap::~SetOnMap()
{
    set.clear();
};

bool SetOnMap::is_empty_set()
{
    return set.empty();
};

bool SetOnMap::contains_element(int value)
{
    return set.contains(value);
};

void SetOnMap::add_element(int value)
{
    set.insert({ value, value });
};

int SetOnMap::get_size()
{
    return set.size();
};

std::string SetOnMap::set_to_string(char separator)
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

bool SetOnMap::is_subset(SetOnMap* B)
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

bool SetOnMap::is_equal(SetOnMap* B)
{
    return this->is_subset(B) && B->is_subset(this);
};

SetOnMap* SetOnMap::union_sets(SetOnMap* A, SetOnMap* B)
{
    SetOnMap* result = new SetOnMap();

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

SetOnMap* SetOnMap::intersect_sets(SetOnMap* A, SetOnMap* B)
{
    SetOnMap* result = new SetOnMap();

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

SetOnMap* SetOnMap::difference_sets(SetOnMap* A, SetOnMap* B)
{
    SetOnMap* result = new SetOnMap();

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

SetOnMap* SetOnMap::symmetric_difference_sets(SetOnMap* A, SetOnMap* B)
{
    return difference_sets(union_sets(A, B), intersect_sets(B, A));
};