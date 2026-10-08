#include <string>
#include "SetOnNode.h"

using namespace std;

Node* create_empty_set()
{
    return NULL;
}

bool is_empty_set(Node* start)
{
    return (start == NULL);
}

bool contains_element(Node* start, int value)
{
    if (!is_empty_set(start))
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
}

Node* add_element(Node* start, int value)
{
    if (contains_element(start, value))
        return start;

    Node* work = new Node;
    work->data = value;
    work->next = start;

    return work;
}

Node* create_set(int count, int min, int max)
{
    if (min > max)
        return NULL;

    int possibleValues = max - min + 1;

    if (count > possibleValues)
        return NULL;

    Node* start = create_empty_set();

    for (int i{}; i < count; i++)
    {
        Node* tmp = start;
        while (tmp == start)
        {
            int value = rand() % (max - min + 1) + min;
            start = add_element(start, value);
        }
    }

    return start;
}

int get_size(Node* start)
{
    int counter = 0;

    if (!is_empty_set(start))
    {
        Node* work = start;

        while (work != NULL)
        {
            counter++;
            work = work->next;
        }
    }

    return counter;
}

string set_to_string(Node* start, char separator)
{
    if (is_empty_set(start))
        return "empty";

    string result{};

    Node* work = start;

    while (work != NULL)
    {
        result += to_string(work->data);
        result += separator;
        work = work->next;
    }

    return result.erase(result.length() - 1);
}

Node* delete_set(Node* start)
{
    Node* work = start;

    while (work != NULL)
    {
        Node* tmp = work;
        work = work->next;
        delete tmp;
    }

    return NULL;
}

bool is_subset(Node* A, Node* B)
{
    if (is_empty_set(A))
        return true;

    Node* work = A;

    while (work != NULL)
    {
        if (!contains_element(B, work->data))
            return false;

        work = work->next;
    }

    return true;
}

bool are_equal(Node* A, Node* B)
{
    return is_subset(A, B) && is_subset(B, A);
}

Node* union_sets(Node* A, Node* B)
{
    Node* result = create_empty_set();

    Node* work = A;

    while (work != NULL)
    {
        result = add_element(result, work->data);
        work = work->next;
    }

    work = B;

    while (work != NULL)
    {
        result = add_element(result, work->data);
        work = work->next;
    }

    return result;
}

Node* intersect_sets(Node* A, Node* B)
{
    Node* result = create_empty_set();

    if (!is_empty_set(A) && !is_empty_set(B))
    {
        Node* work = A;

        while (work != NULL)
        {
            if (contains_element(B, work->data))
                result = add_element(result, work->data);

            work = work->next;
        }
    }

    return result;
}

Node* difference_sets(Node* A, Node* B)
{
    Node* result = create_empty_set();

    if (!is_empty_set(A))
    {
        Node* work = A;

        while (work != NULL)
        {
            if (!contains_element(B, work->data))
                result = add_element(result, work->data);

            work = work->next;
        }
    }

    return result;
}

Node* symmetric_difference_sets(Node* A, Node* B)
{
    return difference_sets(union_sets(A, B), intersect_sets(B, A));
}