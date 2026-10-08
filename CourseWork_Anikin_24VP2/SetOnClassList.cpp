#include <string>
#include "SetOnClassList.h"

SetOnClassList::SetOnClassList()
{
    start = NULL;
};

SetOnClassList::SetOnClassList(int count, int min, int max) : SetOnClassList()
{
    if (min > max) return;

    int possibleValues = max - min + 1;

    if (count > possibleValues) return;

    for (int i{}; i < count; i++)
    {
        Node* tmp = start;
        while (tmp == start)
        {
            int value = rand() % possibleValues + min;
            add_element(value);
        }
    }
};

SetOnClassList::~SetOnClassList()
{
    Node* work = start;

    while (work != NULL)
    {
        Node* tmp = work;
        work = work->next;
        delete tmp;
    }

    start = NULL;
};

bool SetOnClassList::is_empty_set()
{
    return (start == NULL);
};

bool SetOnClassList::contains_element(int value)
{
    if (!is_empty_set())
    {
        Node* work = start;

        while (work != NULL)
        {
            if (work->data == value)
                return true;

            work = work->next;
        }
    }

    return false;
};

void SetOnClassList::add_element(int value)
{
    if (!contains_element(value))
    {
        Node* work = new Node;
        work->data = value;
        work->next = start;

        start = work;
    }
};

int SetOnClassList::get_size()
{
    int counter = 0;

    if (!is_empty_set())
    {
        Node* work = start;

        while (work != NULL)
        {
            counter++;
            work = work->next;
        }
    }

    return counter;
};

std::string SetOnClassList::set_to_string(char separator)
{
    if (is_empty_set())
        return "empty";

    std::string result{};
    Node* work = start;

    while (work != NULL)
    {
        result += std::to_string(work->data);
        result += separator;
        work = work->next;
    }

    return result.erase(result.length() - 1);
};

bool SetOnClassList::is_subset(SetOnClassList* B)
{
    if (!is_empty_set())
    {
        Node* work = start;

        while (work != NULL)
        {
            if (!B->contains_element(work->data))
                return false;

            work = work->next;
        }
    }

    return true;
};

bool SetOnClassList::is_equal(SetOnClassList* B)
{
    return this->is_subset(B) && B->is_subset(this);
};

SetOnClassList* SetOnClassList::union_sets(SetOnClassList* A, SetOnClassList* B)
{
    SetOnClassList* result = new SetOnClassList();

    Node* work = A->start;
    while (work != NULL)
    {
        result->add_element(work->data);
        work = work->next;
    }

    work = B->start;
    while (work != NULL)
    {
        result->add_element(work->data);
        work = work->next;
    }

    return result;
};

SetOnClassList* SetOnClassList::intersect_sets(SetOnClassList* A, SetOnClassList* B)
{
    SetOnClassList* result = new SetOnClassList();

    if (!A->is_empty_set() && !B->is_empty_set())
    {
        Node* work = A->start;

        while (work != NULL)
        {
            if (B->contains_element(work->data))
                result->add_element(work->data);

            work = work->next;
        }
    }

    return result;
};

SetOnClassList* SetOnClassList::difference_sets(SetOnClassList* A, SetOnClassList* B)
{
    SetOnClassList* result = new SetOnClassList();

    if (!A->is_empty_set())
    {
        Node* work = A->start;

        while (work != NULL)
        {
            if (!B->contains_element(work->data))
                result->add_element(work->data);

            work = work->next;
        }
    }

    return result;
};

SetOnClassList* SetOnClassList::symmetric_difference_sets(SetOnClassList* A, SetOnClassList* B)
{
    return difference_sets(union_sets(A, B), intersect_sets(B, A));
};