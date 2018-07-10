#ifndef List_H
#define List_H

#include <iostream>

using namespace std;

template <class TYPE>
struct Node
{
    TYPE m_data; // data of list
    Node<TYPE>* m_next; // pointer pointing to next Node of list
    Node<TYPE>* m_previous; // pointer pointing to previous Node of list
    Node(TYPE data, Node<TYPE>* next = nullptr, Node<TYPE>* previous = nullptr) : m_data(data), m_next(next), m_previous(previous) // constructor
    {

    }
};

template <class TYPE>
class List
{

// the public constructors and operators
public:
    List(); // default constructor
    List(const List& other); // copy constructor
    List<TYPE>& operator =(const List& other) const; // assignment operator
    bool operator ==(const List& other) const; // returns true if two lists are equal
    bool operator !=(const List& other) const; // returns true if two lists are different
    bool operator <(const List& other) const; // returns true if first list is smaller than second list
    bool operator >(const List& other) const; // returns true if first list is bigger than second list
    bool operator <=(const List& other) const; // returns true if first list is smaller than or equal to second list
    bool operator >=(const List& other) const; // returns true if first list is bigger than or equal to second list
    ~List(); // destructor

// iterator and reverse iterator of list
public:
    class Iterator
    {
        friend class List;
    public:
        Iterator(Node<TYPE>* position); // constructor
        const TYPE& operator *() const; // const operator to access value of position
        TYPE& operator *(); // operator to access value of position
        const Node<TYPE>* operator ->() const; // const operator to access pointer of position
        Node<TYPE>* operator ->(); // operator to access pointer of position
        Iterator& operator ++(); // operator to increase address of list
        Iterator operator ++(int); // operator to return value contained in address of list
        bool operator ==(const Iterator& other) const; // returns true if two positions are equal
        bool operator !=(const Iterator& other) const; // returns true if two positions are different
        bool operator <(const Iterator& other) const; // returns true if first position is smaller than second position
        bool operator >(const Iterator& other) const; // returns true if first position is bigger than second position
        bool operator <=(const Iterator& other) const; // returns true if first position is smaller than or equal to second position
        bool operator >=(const Iterator& other) const; // returns true if first position is bigger than or equal to second position

    private:
        Node<TYPE>* m_position; // pointer pointing to current position in list
    };

    class Reverse_Iterator
    {
        friend class List;
    public:
        Reverse_Iterator(Node<TYPE>* position); // constructor
        const TYPE& operator *() const; // const operator to access value of position
        TYPE& operator *(); // operator to access value of position
        const Node<TYPE>* operator ->() const; // const operator to access pointer of position
        Node<TYPE>* operator ->(); // operator to access pointer of position
        Reverse_Iterator& operator --(); // operator to decrease address of list
        Reverse_Iterator operator --(int); // operator to return value contained in address of list
        bool operator ==(const Reverse_Iterator& other) const; // returns true if two positions are equal
        bool operator !=(const Reverse_Iterator& other) const; // returns true if two positions are different
        bool operator <(const Reverse_Iterator& other) const; // returns true if first position is smaller than second position
        bool operator >(const Reverse_Iterator& other) const; // returns true if first position is bigger than second position
        bool operator <=(const Reverse_Iterator& other) const; // returns true if first position is smaller than or equal to second position
        bool operator >=(const Reverse_Iterator& other) const; // returns true if first position is bigger than or equal to second position

    private:
        Node<TYPE>* m_position; // pointer pointing to current position in list
    };

// the public methods
public:
    void push_front(const TYPE& data); // adds element in front of list
    void push_back(const TYPE& data); // adds element in back of list
    void pop_front(); // removes element in front of list
    void pop_back(); // removes element in back of list
    void insert_after(const TYPE& data, const size_t& index); // inserts after a current node by index
    void insert_before(const TYPE& data, const size_t& index); // inserts before a current node by index
    void remove_at(const size_t &index); // removes a current node by index
    void clear(); // clears list
    void merge(const List& other); // merges two lists
    void unique(); // removes consecutive duplicate elements
    void process(const List& dll); // converts list to an arithmetic progression
    void swap(List& other); // swaps two lists
    void sort(); // sorts list
    void reverse(); // reverses list's elements

    bool empty() const; // returns true if list is empty
    size_t size() const; // returns size of list
    void print() const; // prints list
    TYPE& front() const; // returns front data of list
    TYPE& back() const; // returns back data of list
    Iterator begin() const; // returns iterator to front of list
    const Iterator cbegin() const; // returns const iterator to front of list
    Iterator end() const; // returns iterator to back of list
    const Iterator cend() const; // returns const iterator to back of list
    Reverse_Iterator rbegin() const; // returns reverse iterator to front of list
    const Reverse_Iterator crbegin() const; // returns const reverse iterator to front of list
    Reverse_Iterator rend() const; // returns reverse iterator to back of list
    const Reverse_Iterator crend() const; // returns const reverse iterator to back of list

// the private methods
private:
    void copy(const List& other); // copies one list to another
    void destroy(); // destroys list
    Node<TYPE>* find(const size_t& index); // finds current node in list by index

// the private members
private:
    Node<TYPE>* m_head; // front of list
    Node<TYPE>* m_tail; // back of list
    size_t m_size; // size of list
};

template <class TYPE>
void List<TYPE>::copy(const List& other)
{
    m_size = other.m_size;
    m_head = new Node<TYPE>(other.m_head->m_data);
    Node<TYPE> *ours, *theirs;
    ours = m_head;
    theirs = other.m_head->m_next;
    while(theirs != nullptr)
    {
        ours->m_next = new Node<TYPE>(theirs->m_data);
        ours->m_next->m_previous = ours;
        m_tail = ours->m_next;
        ours = ours->m_next;
        theirs = theirs->m_next;
    }
}

template <class TYPE>
void List<TYPE>::destroy()
{
    while(empty() == false)
    {
        pop_front();
    }
}

template <class TYPE>
Node<TYPE>* List<TYPE>::find(const size_t& index)
{
    if(index < 0 || index > m_size)
    {
        return nullptr;
    }
    Node<TYPE>* temp = m_head;
    for(size_t i = 0; i < index; i++)
    {
        temp = temp->m_next;
    }
    return temp;
}

template <class TYPE>
List<TYPE>::List() : m_head(nullptr), m_tail(nullptr), m_size(0)
{

}

template <class TYPE>
List<TYPE>::List(const List& other)
{
    if(this != &other)
    {
        copy(other);
    }
}

template <class TYPE>
List<TYPE>& List<TYPE>::operator =(const List& other) const
{
    if(this != &other)
    {
        copy(other);
    }

    return* this;
}

template <class TYPE>
bool List<TYPE>::operator ==(const List& other) const
{
    if(m_size == other.m_size)
    {
        Node<TYPE>* ours = m_head;
        Node<TYPE>* theirs = other.m_head;
        while(ours != nullptr && theirs != nullptr)
        {
            if(ours->m_data == theirs->m_data)
            {
                ours = ours->m_next;
                theirs = theirs->m_next;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

template <class TYPE>
bool List<TYPE>::operator !=(const List& other) const
{
    return !(operator ==(other));
}

template <class TYPE>
bool List<TYPE>::operator <(const List& other) const
{
    if(m_size < other.m_size)
    {
        return true;
    }
    else if(m_size == other.m_size)
    {
        Node<TYPE>* ours = m_head;
        Node<TYPE>* theirs = other.m_head;
        while(ours != nullptr && theirs != nullptr)
        {
            if(ours->m_data < theirs->m_data)
            {
                ours = ours->m_next;
                theirs = theirs->m_next;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

template <class TYPE>
bool List<TYPE>::operator >(const List& other) const
{
    if(m_size > other.m_size)
    {
        return true;
    }
    else if(m_size == other.m_size)
    {
        Node<TYPE>* ours = m_head;
        Node<TYPE>* theirs = other.m_head;
        while(ours != nullptr && theirs != nullptr)
        {
            if(ours->m_data > theirs->m_data)
            {
                ours = ours->m_next;
                theirs = theirs->m_next;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
    return false;
}

template <class TYPE>
bool List<TYPE>::operator <=(const List& other) const
{
    return !(operator >(other));
}

template <class TYPE>
bool List<TYPE>::operator >=(const List& other) const
{
    return !(operator <(other));
}

template <class TYPE>
List<TYPE>::~List()
{
    destroy();
}

template <class TYPE>
List<TYPE>::Iterator::Iterator(Node<TYPE>* position)
{
    m_position = position;
}

template <class TYPE>
const TYPE& List<TYPE>::Iterator::operator *() const
{
    return m_position->m_data;
}

template <class TYPE>
TYPE& List<TYPE>::Iterator::operator *()
{
    return m_position->m_data;
}

template <class TYPE>
const Node<TYPE>* List<TYPE>::Iterator::operator ->() const
{
    return m_position;
}

template <class TYPE>
Node<TYPE>* List<TYPE>::Iterator::operator ->()
{
    return m_position;
}

template <class TYPE>
typename List<TYPE>::Iterator& List<TYPE>::Iterator::operator ++()
{
    m_position = m_position->m_next;
    return *this;
}

template <class TYPE>
typename List<TYPE>::Iterator List<TYPE>::Iterator::operator ++(int)
{
    Iterator res(*this);
    ++(*this);
    return res;
}

template <class TYPE>
bool List<TYPE>::Iterator::operator ==(const Iterator& other) const
{
    return m_position == other.m_position;
}

template <class TYPE>
bool List<TYPE>::Iterator::operator !=(const Iterator& other) const
{
    return !(operator ==(other));
}

template <class TYPE>
bool List<TYPE>::Iterator::operator <(const Iterator& other) const
{
    return m_position < other.m_position;
}

template <class TYPE>
bool List<TYPE>::Iterator::operator >(const Iterator& other) const
{
    return m_position > other.m_position;
}

template <class TYPE>
bool List<TYPE>::Iterator::operator <=(const Iterator& other) const
{
    return !(operator >(other));
}

template <class TYPE>
bool List<TYPE>::Iterator::operator >=(const Iterator& other) const
{
    return !(operator <(other));
}

template <class TYPE>
List<TYPE>::Reverse_Iterator::Reverse_Iterator(Node<TYPE>* position)
{
    m_position = position;
}

template <class TYPE>
const TYPE& List<TYPE>::Reverse_Iterator::operator *() const
{
    return m_position->m_data;
}

template <class TYPE>
TYPE& List<TYPE>::Reverse_Iterator::operator *()
{
    return m_position->m_data;
}

template <class TYPE>
const Node<TYPE>* List<TYPE>::Reverse_Iterator::operator ->() const
{
    return m_position;
}

template <class TYPE>
Node<TYPE>* List<TYPE>::Reverse_Iterator::operator ->()
{
    return m_position;
}

template <class TYPE>
typename List<TYPE>::Reverse_Iterator& List<TYPE>::Reverse_Iterator::operator --()
{
    m_position = m_position->m_previous;
    return *this;
}

template <class TYPE>
typename List<TYPE>::Reverse_Iterator List<TYPE>::Reverse_Iterator::operator --(int)
{
    Reverse_Iterator res(*this);
    --(*this);
    return res;
}

template <class TYPE>
bool List<TYPE>::Reverse_Iterator::operator ==(const Reverse_Iterator& other) const
{
    return m_position == other.m_position;
}

template <class TYPE>
bool List<TYPE>::Reverse_Iterator::operator !=(const Reverse_Iterator& other) const
{
    return !(other == *this);
}

template <class TYPE>
bool List<TYPE>::Reverse_Iterator::operator <(const Reverse_Iterator& other) const
{
    return m_position < other.m_position;
}

template <class TYPE>
bool List<TYPE>::Reverse_Iterator::operator >(const Reverse_Iterator& other) const
{
    return m_position > other.m_position;
}

template <class TYPE>
bool List<TYPE>::Reverse_Iterator::operator <=(const Reverse_Iterator& other) const
{
    return !(operator >(other));
}

template <class TYPE>
bool List<TYPE>::Reverse_Iterator::operator >=(const Reverse_Iterator& other) const
{
    return !(operator <(other));
}

template <class TYPE>
void List<TYPE>::push_front(const TYPE& data)
{
    Node<TYPE>* temp = new Node<TYPE>(data);
    if(empty() == true)
    {
        m_head = temp;
        m_tail = temp;
    }
    else
    {
        temp->m_next = m_head;
        m_head->m_previous = temp;
        m_head = temp;
    }
    m_size++;
}

template <class TYPE>
void List<TYPE>::push_back(const TYPE& data)
{
    Node<TYPE>* temp = new Node<TYPE>(data);
    if(empty() == true)
    {
        m_head = temp;
        m_tail = temp;
    }
    else
    {
        temp->m_previous = m_tail;
        m_tail->m_next = temp;
        m_tail = temp;
    }
    m_size++;
}

template <class TYPE>
void List<TYPE>::pop_front()
{
    if(empty() == false)
    {
        Node<TYPE>* temp;
        temp = m_head;
        m_head = m_head->m_next;
        if(m_head != nullptr)
        {
            m_head->m_previous = nullptr;
        }
        else
        {
            m_tail = nullptr;
        }
        delete temp;
        m_size--;
    }
}

template <class TYPE>
void List<TYPE>::pop_back()
{
    if(empty() == false)
    {
        Node<TYPE>* temp;
        temp = m_tail;
        m_tail = m_tail->m_previous;
        if(m_tail != nullptr)
        {
            m_tail->m_next = nullptr;
        }
        else
        {
            m_head = nullptr;
        }
        delete temp;
        m_size--;
    }
}

template <class TYPE>
void List<TYPE>::insert_after(const TYPE& data, const size_t& index)
{
    if(empty() == true)
    {
        push_back(data);
    }
    else
    {
        if(index < 0 || index >= m_size)
        {
            return;
        }
        else
        {
            Node<TYPE>* node_at = find(index);
            if(node_at == m_tail)
            {
                push_back(data);
            }
            else
            {
                Node<TYPE>* new_node = new Node<TYPE>(data, node_at->m_next, node_at);
                node_at->m_next->m_previous = new_node;
                node_at->m_next = new_node;
                m_size++;
            }
        }
    }
}

template <class TYPE>
void List<TYPE>::insert_before(const TYPE& data, const size_t& index)
{
    if(empty() == true)
    {
        push_front(data);
    }
    else
    {
        if(index < 0 || index >= m_size)
        {
            return;
        }
        else
        {
            Node<TYPE>* node_at = find(index);
            if(node_at == m_head)
            {
                push_front(data);
            }
            else
            {
                Node<TYPE>* new_node = new Node<TYPE>(data, node_at, node_at->m_previous);
                node_at->m_previous->m_next = new_node;
                node_at->m_previous = new_node;
                m_size++;
            }
        }
    }
}

template <class TYPE>
void List<TYPE>::remove_at(const size_t& index)
{
    if(empty() == false)
    {
        if(index < 0 || index >= m_size)
        {
            return;
        }
        else
        {
            if(index == 0)
            {
                pop_front();
            }
            else
            {
                Node<TYPE>* node_before_removed = find(index - 1);
                Node<TYPE>* node_to_remove = find(index);
                if(index == m_size - 1)
                {
                    m_tail = node_before_removed;
                    m_tail->m_next = nullptr;
                }
                else
                {
                    node_before_removed->m_next = node_to_remove->m_next;
                    node_to_remove->m_next->m_previous = node_before_removed;
                }
                delete node_to_remove;
                m_size--;
            }
        }
    }
}

template <class TYPE>
void List<TYPE>::clear()
{
    destroy();
}

template <class TYPE>
void List<TYPE>::merge(const List& other)
{
    Node<TYPE>* temp = other.m_head;
    while(temp != nullptr)
    {
        push_back(temp->m_data);
        temp = temp->m_next;
    }
}

template <class TYPE>
void List<TYPE>::unique()
{
    Node<TYPE>* temp = m_head;
    unsigned short index = 0;
    while(temp)
    {
        index++;
        if(temp->m_data == temp->m_next->m_data)
        {
            remove_at(index);
        }
        temp = temp->m_next;
    }
}

template <class TYPE>
void List<TYPE>::process(const List& dll)
{
    Node<TYPE>* second = dll.m_head->m_next;
    Node<TYPE>* first = dll.m_head;
    TYPE difference = second->m_data - first->m_data;
    unsigned short idx = 0;
    while(second->m_next != nullptr)
    {
        idx++;
        if(difference != second->m_next->m_data - first->m_next->m_data)
        {
            remove_at(idx + 1);
            insert_after(second->m_data + difference, idx);
        }
        second = second->m_next;
        first = first->m_next;
    }
}

template <class TYPE>
void List<TYPE>::swap(List& other)
{
    Node<TYPE>* ours = m_head;
    size_t temp = m_size;
    if(this != &other)
    {
        copy(other);
    }
    other.m_head = ours;
    while(ours->m_next != nullptr)
    {
        ours = ours->m_next;
    }
    other.m_tail = ours;
    other.m_size = temp;
}

template <class TYPE>
void List<TYPE>::sort()
{
    TYPE temp;
    for(Node<TYPE>* i = m_head; i != nullptr; i = i->m_next)
    {
        for(Node<TYPE>* j = i->m_next; j != nullptr; j = j->m_next)
        {
            if(i->m_data > j->m_data)
            {
                temp = i->m_data;
                i->m_data = j->m_data;
                j->m_data = temp;
            }
        }
    }

//    Node<TYPE>* current = m_head->m_next;
//    Node<TYPE>* prev = m_head;
//    while(current)
//    {
//        if(prev->m_data > current->m_data)
//        {
//            TYPE temp = prev->m_data;
//            prev->m_data = current->m_data;
//            current->m_data = temp;
//            if(prev != m_head)
//            {
//                prev = prev->m_previous;
//                current = current->m_previous;
//            }
//        }
//        else
//        {
//            prev = prev->m_next;
//            current = current->m_next;
//        }
//    }
}

template <class TYPE>
void List<TYPE>::reverse()
{
    Node<TYPE>* prev = nullptr;
    Node<TYPE>* current = m_head;
    Node<TYPE>* next = nullptr;
    while(current != nullptr)
    {
        next = current->m_next;
        current->m_next = prev;
        prev = current;
        current = next;
    }
    Node<TYPE>* temp = m_head;
    m_head = prev;
    while(temp->m_next)
    {
        temp = temp->m_next;
    }
    m_tail = temp;
}

template <class TYPE>
bool List<TYPE>::empty() const
{
    return m_size == 0;
}

template <class TYPE>
size_t List<TYPE>::size() const
{
    return m_size;
}

template <class TYPE>
void List<TYPE>::print() const
{
    if(empty() == false)
    {
        Node<TYPE>* temp = m_head;
        while(temp != nullptr)
        {
            cout << temp->m_data << " ";
            temp = temp->m_next;
        }
        cout << endl;
    }
}

template <class TYPE>
TYPE& List<TYPE>::front() const
{
    return m_head->m_data;
}

template <class TYPE>
TYPE& List<TYPE>::back() const
{
    return m_tail->m_data;
}

template <class TYPE>
typename List<TYPE>::Iterator List<TYPE>::begin() const
{
    return List<TYPE>::Iterator(m_head);
}

template <class TYPE>
const typename List<TYPE>::Iterator List<TYPE>::cbegin() const
{
    return List<TYPE>::Iterator(m_head);
}

template <class TYPE>
typename List<TYPE>::Iterator List<TYPE>::end() const
{
    return List<TYPE>::Iterator(m_tail->m_next);
}

template <class TYPE>
const typename List<TYPE>::Iterator List<TYPE>::cend() const
{
    return List<TYPE>::Iterator(m_tail->m_next);
}

template <class TYPE>
typename List<TYPE>::Reverse_Iterator List<TYPE>::rbegin() const
{
    return List<TYPE>::Reverse_Iterator(m_head->m_previous);
}

template <class TYPE>
const typename List<TYPE>::Reverse_Iterator List<TYPE>::crbegin() const
{
    return List<TYPE>::Reverse_Iterator(m_head->m_previous);
}

template <class TYPE>
typename List<TYPE>::Reverse_Iterator List<TYPE>::rend() const
{
    return List<TYPE>::Reverse_Iterator(m_tail);
}

template <class TYPE>
const typename List<TYPE>::Reverse_Iterator List<TYPE>::crend() const
{
    return List<TYPE>::Reverse_Iterator(m_tail);
}

#endif // List_H
