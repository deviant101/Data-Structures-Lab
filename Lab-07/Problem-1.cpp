#include <iostream>
using namespace std;

class Node
{
public:
    char Parenthesis;
    Node *next;

    Node()
    {
        char Parenthesis = '\0';
        next = NULL;
    }
};

class Stack
{
private:
    Node *top;
    int size;
    int no_of_elements;

public:
    Stack()
    {
        top = nullptr;
        size = 8;
        no_of_elements = 0;
    }
    void push(char parenthesis)
    {
        Node *temp = new Node;
        temp->Parenthesis = parenthesis;
        temp->next = top;
        top = temp;
        no_of_elements++;
    }
    Node *pop()
    {
        Node *temp = top;
        top = top->next;
        no_of_elements--;
        return temp;
    }
    bool is_empty()
    {
        if (top == nullptr && no_of_elements == 0)
            return true;
        else
            return false;
    }
    bool is_full()
    {
        if (no_of_elements == size)
            return true;
        else
            return false;
    }
    void clear()
    {
        if (top != nullptr)
        {
            Node *temp = top;
            while (temp != nullptr)
            {
                top = top->next;
                delete temp;
                temp = top;
            }
        }
        else
            cout << "Stack is already empty" << endl;
    }
    void Peak()
    {
        if (!is_empty())
            cout << top->Parenthesis << endl;
        else
            cout << "Stack is empty" << endl;
    }
    void Print()
    {
        Node *temp = top;
        while (temp != nullptr)
        {
            cout << temp->Parenthesis << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    ~Stack()
    {
        clear();
    }
};

int main()
{
    Stack stack;
    stack.push('d');
    stack.push('e');
    stack.push('m');
    stack.push('h');
    stack.push('A');
    stack.Print();
    stack.Peak();
    cout << "Check for Full: " << stack.is_full() << endl;
    cout << "Check for Empty: " << stack.is_empty() << endl;
    stack.pop();
    stack.Print();
    stack.Peak();
    cout << "Clearing Stack....." << endl;
    stack.clear();

    return 0;
}
