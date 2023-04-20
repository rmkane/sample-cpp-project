#ifndef LinkedList_h
#define LinkedList_h

using namespace std;

// Declaring node class
template <typename TData>
struct Node
{
    Node<TData> *next;
    TData data;
};

template <typename TData>
class LinkedList
{
private:
    Node<TData> *head;
    Node<TData> *last;

public:
    LinkedList<TData>();
    void add(TData data);
    TData get(int index);
    TData operator[](int index);
    void print();
};

template <typename TData>
LinkedList<TData>::LinkedList()
{
    this->head = NULL;
    this->last = NULL;
}

template <typename TData>
void LinkedList<TData>::add(TData data)
{
    if (!this->head)
    {
        // When there is no element in the list
        this->head = new Node<TData>;
        this->head->data = data;
        this->head->next = NULL;
        this->last = head;
    }
    else
    {
        // When the list is not empty
        if (this->last == this->head)
        {
            // When the list has one element
            this->last = new Node<TData>;
            this->last->data = data;
            this->last->next = NULL;
            this->head->next = this->last;
        }
        else
        {
            // When the list has more than one element
            Node<TData> *insdata = new Node<TData>;
            insdata->data = data;
            insdata->next = NULL;
            this->last->next = insdata;
            this->last = insdata;
        }
    }
}

template <typename TData>
TData LinkedList<TData>::get(int index)
{
    if (index == 0)
    {
        // Returning the head element
        return this->head->data;
    }
    else
    {
        // Get the index'th element
        Node<TData> *curr = this->head;
        for (int i = 0; i < index; ++i)
        {
            curr = curr->next;
        }
        return curr->data;
    }
}

template <typename TData>
TData LinkedList<TData>::operator[](int index)
{
    return get(index);
}

template <typename TData>
void LinkedList<TData>::print()
{
    if (this->head == NULL)
    {
        cout << "List is empty" << endl;
        return;
    }

    if (this->head == this->last)
    {
        cout << "[" << this->head->data << "]" << endl;
        return;
    }

    Node<TData> *curr = this->head;

    cout << "[" << curr->data << ", ";
    curr = curr->next;

    while (curr != NULL)
    {
        cout << curr->data;
        curr = curr->next;

        if (curr != NULL)
        {
            cout << ", ";
        }
    }

    cout << "]" << endl;
}

#endif // LinkedList_h
