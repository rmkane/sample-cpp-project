#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

#include <iostream>

template <typename T>
class LinkedList
{
    // Forward declaration
    class Node;

public:
    LinkedList<T>() noexcept
    {
        // caution: static members can't be
        // initialized by initializer list
        m_spRoot = nullptr;
    }

    // Forward declaration must be done
    // in the same access scope
    class Iterator;

    // Root of LinkedList wrapped in Iterator type
    Iterator begin()
    {
        return Iterator(m_spRoot);
    }

    // End of LinkedList wrapped in Iterator type
    Iterator end()
    {
        return Iterator(nullptr);
    }

    // Check if list is empty
    bool is_empty();

    // Size of list
    int size();

    // Adds data to the end of list
    void push_back(T data);

    // Print the list
    void print();

    // Iterator class can be used to
    // sequentially access nodes of linked list
    class Iterator
    {
    public:
        Iterator() noexcept : m_pCurrentNode(m_spRoot) {}

        Iterator(const Node *pNode) noexcept : m_pCurrentNode(pNode) {}

        Iterator &operator=(Node *pNode)
        {
            this->m_pCurrentNode = pNode;
            return *this;
        }

        // Prefix ++ overload
        Iterator &operator++()
        {
            if (m_pCurrentNode)
                m_pCurrentNode = m_pCurrentNode->pNext;
            return *this;
        }

        // Postfix ++ overload
        Iterator operator++(int)
        {
            Iterator iterator = *this;
            ++*this;
            return iterator;
        }

        bool operator!=(const Iterator &iterator)
        {
            return m_pCurrentNode != iterator.m_pCurrentNode;
        }

        int operator*()
        {
            return m_pCurrentNode->data;
        }

    private:
        const Node *m_pCurrentNode;
    };

private:
    class Node
    {
        T data;
        Node *pNext;

        // LinkedList class methods need
        // to access Node information
        friend class LinkedList;
    };

    // Create a new Node
    Node *GetNode(T data)
    {
        Node *pNewNode = new Node;
        pNewNode->data = data;
        pNewNode->pNext = nullptr;

        return pNewNode;
    }

    // Return by reference so that it can be used in
    // left hand side of the assignment expression
    Node *&GetRootNode()
    {
        return m_spRoot;
    }

    static Node *m_spRoot;
};

template <typename T>
/*static*/ typename LinkedList<T>::Node *LinkedList<T>::m_spRoot = nullptr;

template <typename T>
bool LinkedList<T>::is_empty()
{
    return m_spRoot != NULL;
}

template <typename T>
int LinkedList<T>::size()
{
    int count = 0;
    Node *pCrawler = GetRootNode();

    while (pCrawler)
    {
        count += 1;
        pCrawler = pCrawler->pNext;
    }

    return count;
}

template <typename T>
void LinkedList<T>::push_back(T data)
{
    Node *pTemp = GetNode(data);
    if (!is_empty())
    {
        GetRootNode() = pTemp;
    }
    else
    {
        Node *pCrawler = GetRootNode();
        while (pCrawler->pNext)
        {
            pCrawler = pCrawler->pNext;
        }

        pCrawler->pNext = pTemp;
    }
}

template <typename T>
void LinkedList<T>::print()
{
    Node *pCrawler = GetRootNode();

    std::cout << "[";

    while (pCrawler)
    {
        std::cout << pCrawler->data;
        pCrawler = pCrawler->pNext;

        if (pCrawler)
        {
            std::cout << ", ";
        }
    }

    std::cout << "]" << std::endl;
}

#endif // LINKED_LIST_H_
