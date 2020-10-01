#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include <stddef.h>
#include <iostream>

template <class T>
class Node
{
private:
    T val;
    Node<T> *next;

public:
    ~Node<T>() {};
    Node<T>(T pVal, Node<T> *pNext)
    {
        val = pVal;
        next = pNext;
    };

    T get_val() {return val;};
    void set_val(T pVal) {val = pVal;};
    Node<T> *get_next() {return next;};
    void set_next(Node<T> *pNext) {next = pNext;};
};

template <class T>
class LinkedList
{
protected:
    Node<T> *head;

public:
    ~LinkedList(){};
    LinkedList()
    {
        head = NULL;
    };

    int length()
    {
        int length = 0;
        Node<T> *ptr = head;
        while (ptr != NULL)
        {
            length++;
            ptr = ptr->get_next();
        }
        return length;
    };

    void print()
    {
        Node<T> *ptr = head;
        while (ptr != NULL)
        {
            std::cout << ptr->get_val() << ", ";
            ptr = ptr->get_next();
        }
        std::cout << std::endl;        
    }

    void push(T pVal)
    {
        Node<T> *node = new Node<T>(pVal, head);
        head = node;
    };

    void append(T pVal)
    {
        Node<T> *ptr = head;
        while (ptr->get_next() != NULL)
        {
            ptr = ptr->get_next();
        }
        Node<T> *node = new Node<T>(pVal, NULL);
        ptr->set_next(node);
    };

    int insert_item(T pVal, int index)
    {
        if (index > length())
            return -1;
        if (index < 0)
            return -2;
        if (index == 0)
        {
            push(pVal);
            return 1;
        }

        int i = 0;
        Node<T> *ptr = head;
        Node<T> *pre = NULL;
        while (ptr != NULL && index > i)
        {
            pre = ptr;
            ptr = ptr->get_next();
            i++;
        }
        Node<T> *node = new Node<T>(pVal, ptr);
        pre->set_next(node);
        return 1;
    };

    bool is_empty()
    {        
        return head == NULL;
    };

    int delete_item(int index)
    {
        if (is_empty())
            return -1;
        if (index >= length())
            return -1;
        if (index < 0)
            return -2;
        if (index == 0)
        {
            Node<T> *temp = head;
            head = head->get_next();
            delete temp;
            return 1;
        }

        int i = 0;
        Node<T> *ptr = head;
        Node<T> *pre = NULL;
        while (ptr->get_next() != NULL && index > i)
        {
            pre = ptr;
            ptr = ptr->get_next();
            i++;
        }
        pre->set_next(ptr->get_next());
        delete ptr;
        return 1;
    };

    int get_nth(int index, T &item)
    {
        if (index < 0)
            return -1;
        if (index >= length())
            return -2;
            
        int i = 0;
        Node<T> *ptr = head;
        while (ptr->get_next() != NULL && index > i)
        {
            ptr = ptr->get_next();
            i++;
        }
        item = ptr->get_val();
        return 1;
    };

    //Count method, takes T value as argument and
    //returns the amount of times it appears in the list
    //While loop goes through entire list and uses get_val()
    //to check if the value is equal to the requested value
    //Complexity of O(n)
    int count(T searchFor)
    {
        int counter = 0;
        Node<T> *ptr = head;
        while(ptr != NULL)
        {
            if(ptr->get_val() == searchFor)
                counter++;
            ptr = ptr->get_next();
        }
        return counter;
    };

    //deleteList method, has no arguments or return value
    //Using a temporary Node, deletes the head until no values are left
    //Complexity O(n)
    void deleteList()
    {
        Node<T> *ptr = head;

        while (ptr != NULL)
        {
            Node<T> *temp = head;
            head = head->get_next();
            delete temp;
            ptr = ptr->get_next();
        }
    };


    //sortedInsert method takes a node pointer as an argument and has no return value
    //assumes linkedlist is in order
    //compares value of given node with current node
    //always checks if next is null before anything else
    //uses insert_item if condition is met, index begins at 1 and has +1 every loop
    //Complexity of O(n)
    void sortedInsert(Node<T> *newNode)
    {
        Node<T> *ptr = head;
        int i = 1;
        while(ptr != NULL)
        {
            if((ptr->get_next()==NULL) && newNode->get_val() >= ptr->get_val())
            {
                insert_item(newNode->get_val(), i);
                break;
            }
            else if(newNode->get_val() >= ptr->get_val() && newNode->get_val() <= ptr->get_next()->get_val())
            {
                insert_item(newNode->get_val(), i);
                break;
            }
            else if(newNode->get_val() <= ptr->get_val())
            {
                insert_item(newNode->get_val(), i-1);
                break;
            }

            ptr = ptr->get_next();
            i++;  
        }
    };

    //removeDuplicates method has no arguments or return value
    //while loop runs from first node to penultimate node
    //if current node is equal to next one, deletes next one
    //pointer does not move to next one until the current and next values are different
    //index of 1 is used to delete the next item and not the current
    //index increases by 1 every time the current and next values are different
    //complexity of O(n)
    void removeDuplicates()
    {
        Node<T> *ptr = head;
        int i = 1;
        while(ptr->get_next() != NULL)
        {
            if(ptr->get_val() == ptr->get_next()->get_val())
                delete_item(i);
            else
            {
                ptr = ptr->get_next();
                i++;
            }
            
        }

        
    };

    //reverse method has no arguments or return value
    //Uses two additional node objects to store previous node and temporary nodes
    //stores current next node in temporary node object
    //sets actual current next node to be equal to current previous node
    //sets previous node to be equal to current node
    //finally sets current node to be equal to stored temporary node
    //Complexity O(n)
    void reverse()
    {
        Node<T> *ptr = head;
        Node<T> *pre = NULL;
        Node<T> *temp = NULL;
        while(ptr != NULL)
        {
            temp = ptr->get_next();
            ptr->set_next(pre);
            pre = ptr;
            ptr = temp;
        }
        head = pre;
    };

};

#endif