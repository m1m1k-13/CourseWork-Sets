#include <string>
#include "SetOnSet.h"

SetOnSet::SetOnSet() {};

SetOnSet::SetOnSet(int count, int min, int max) : SetOnSet()
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

SetOnSet::~SetOnSet()
{
    set.clear();
};

bool SetOnSet::is_empty_set()
{
    return set.empty();
};

bool SetOnSet::contains_element(int value)
{
    return set.contains(value);
};

void SetOnSet::add_element(int value)
{
    set.insert(value);
};

int SetOnSet::get_size()
{
    return set.size();
};

std::string SetOnSet::set_to_string(char separator)
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

bool SetOnSet::is_subset(SetOnSet* B)
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

bool SetOnSet::is_equal(SetOnSet* B)
{
    return this->is_subset(B) && B->is_subset(this);
};

SetOnSet* SetOnSet::union_sets(SetOnSet* A, SetOnSet* B)
{
    SetOnSet* result = new SetOnSet();

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

SetOnSet* SetOnSet::intersect_sets(SetOnSet* A, SetOnSet* B)
{
    SetOnSet* result = new SetOnSet();

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

SetOnSet* SetOnSet::difference_sets(SetOnSet* A, SetOnSet* B)
{
    SetOnSet* result = new SetOnSet();

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

SetOnSet* SetOnSet::symmetric_difference_sets(SetOnSet* A, SetOnSet* B)
{
    return difference_sets(union_sets(A, B), intersect_sets(B, A));
};