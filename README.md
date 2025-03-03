A singly linked list in C++

This project is an implementation of a singly linked list in C++. A singly linked list is a data structure consisting of nodes, each of which contains data and a pointer to the next node in the list. This implementation supports basic operations such as adding and deleting items, searching, clearing the list, and others.
Project structure

The project consists of a single file main.cpp , which contains an implementation of a singly linked list and an example of its use.
Main components

    The Node template class:

        T data is the data stored in the node.

        Node* next — a pointer to the next node in the list.

        Node(T value) constructor — creates a node with the specified value.

    The LinkedList template class:

        Node<T>* head is a pointer to the first node in the list.

        Node<T>* tail — pointer to the last node in the list.

        int size is the number of items in the list.

    Methods of the LinkedList class:

        void push_back(T value) — adds an item to the end of the list.

        void push_front(T value) — adds an item to the top of the list.

        void pop_back() — deletes the last item in the list.

        void pop_front() — deletes the first item in the list.

        Node<T>* find(T value) const — searches for an element in the list and returns a pointer to the node containing this element.

        void remove(T value) — deletes the first found element with the specified value.

        void clear() — clears the list by deleting all the elements.

        int getSize() const — returns the number of items in the list.

        bool isEmpty() const — checks if the list is empty.

        T& at(int index) — returns the element by index.

        void print() const — displays the contents of the list on the screen.

        void reverse() — expands the list.

        void insert(int index, T value) — inserts the element at the specified position.

        void erase(int index) — deletes an element by index.

    The main function:

        Demonstrates the use of all the basic methods of the LinkedList class.
