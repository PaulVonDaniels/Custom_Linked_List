составь мне readme файл для моего кода:
#include <iostream>
#include <stdexcept>
#include <cstdint>

using std::cout; 
using std::cin;
using std::endl;


template <typename T>
struct Node
{
    T data;
    Node* next;

    Node(T value) : data(value), next(nullptr) { }
};

template <typename T>
class LinkedList
{
private:
    Node<T>* head;
    Node<T>* tail;
    int size;

public:
    LinkedList() : head(nullptr), tail(nullptr), size(0) { }

    ~LinkedList() { clear(); }

    void push_back(T value)
    {
        Node<T>* newNode = new Node<T>(value);
        if (!tail)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    void push_front(T value)
    {
        Node<T>* newNode = new Node<T>(value);
        if (!head)
        {
            head = tail = newNode;
        }
        else
        {
            newNode->next = head;
            head = newNode;
        }
        size++;
    }

    void pop_back()
    {
        if (!tail)
        {
            throw std::out_of_range("List is empty!");
        }
        if (head == tail)
        {
            delete tail;
            head = tail = nullptr;
        }
        else
        {
            Node<T>* temp = head;
            while (temp->next != tail)
            {
                temp = temp->next;
            }
            delete tail;
            tail = temp;
            tail->next = nullptr;
        }
        size--;
    }

    void pop_front()
    {
        if (!head)
        {
            throw std::out_of_range("List is empty!");
        }
        Node<T>* temp = head;
        head = head->next;
        delete temp;
        if (!head)
        {
            tail = nullptr;
        }
        size--;
    }

    Node<T>* find(T value) const
    {
        Node<T>* current = head;
        while (current)
        {
            if (current->data == value)
            {
                return current;
            }
            current = current->next;
        }
        return nullptr;
    }

    void remove(T value)
    {
        if (!head)
        {
            throw std::out_of_range("List is empty!");
        }
        if (head->data == value)
        {
            pop_front();
            return;
        }
        Node<T>* current = head;
        while (current->next && current->next->data != value)
        {
            current = current->next;
        }
        if (!current->next)
        {
            throw std::out_of_range("Element not found!");
        }
        Node<T>* temp = current->next;
        current->next = temp->next;
        if (temp == tail)
        {
            tail = current;
        }
        delete temp;
        size--;
    }

    void clear()
    {
        while (head)
        {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        size = 0;
    }

    int getSize() const
    {
        return size;
    }

    bool isEmpty() const
    {
        return size == 0;
    }

    T& at(int index)
    {
        if (index < 0 || index >= size)
        {
            throw std::out_of_range("Index out of range!");
        }
        Node<T>* current = head;
        for (int i = 0; i < index; i++)
        {
            current = current->next;
        }
        return current->data;
    }

    void print() const
    {
        Node<T>* current = head;
        while (current)
        {
            std::cout << current->data << " -> ";
            current = current->next;
        }
        std::cout << "nullptr\n";
    }

    void reverse()
    {
        Node<T>* prev = nullptr;
        Node<T>* current = head;
        Node<T>* next = nullptr;
        tail = head;
        while (current)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }

    void insert(int index, T value)
    {
        if (index < 0 || index > size)
        {
            throw std::out_of_range("Index out of range!");
        }
        if (index == 0)
        {
            push_front(value);
        }
        else if (index == size)
        {
            push_back(value);
        }
        else
        {
            Node<T>* newNode = new Node<T>(value);
            Node<T>* current = head;
            for (int i = 0; i < index - 1; i++)
            {
                current = current->next;
            }
            newNode->next = current->next;
            current->next = newNode;
            size++;
        }
    }

    void erase(int index)
    {
        if (index < 0 || index >= size)
        {
            throw std::out_of_range("Index out of range!");
        }
        if (index == 0)
        {
            pop_front();
        }
        else if (index == size - 1)
        {
            pop_back();
        }
        else
        {
            Node<T>* current = head;
            for (int i = 0; i < index - 1; i++)
            {
                current = current->next;
            }
            Node<T>* temp = current->next;
            current->next = temp->next;
            delete temp;
            size--;
        }
    }
};

signed int main()
{
    LinkedList<int64_t> list;

    list.push_back(10);
    list.push_back(20);
    list.push_back(30);
    list.push_front(5);

    std::cout << "List: ";
    list.print();

    list.pop_back();
    std::cout << "After pop_back: ";
    list.print();

    list.pop_front();
    std::cout << "After pop_front: ";
    list.print();

    std::cout << "Is 20 in the list? " << (list.find(20) ? "Yes" : "No") << "\n";

    list.remove(20);
    std::cout << "After removing 20: ";
    list.print();

    list.insert(1, 15);
    std::cout << "After inserting 15 at index 1: ";
    list.print();

    list.erase(1);
    std::cout << "After erasing index 1: ";
    list.print();

    list.reverse();
    std::cout << "After reverse: ";
    list.print();

    std::cout << "Element at index 0: " << list.at(0) << "\n";

    list.clear();
    std::cout << "After clear: ";
    list.print();

    return 0;
}


