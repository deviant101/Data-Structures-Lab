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
    void push_expression(string expression)
    {
        clear();
        for (int i = 0; expression[i] != '\0'; i++)
        {
            if (expression[i] == '(' || expression[i] == '{' || expression[i] == '[')
                push(expression[i]);
            else if (expression[i] == ')' || expression[i] == '}' || expression[i] == ']')
            {
                if (is_empty())
                {
                    cout << "Invalid Expression\n";
                    return;
                }
                Node *temp = pop();
                delete temp;
            }
        }
        if (is_empty())
            cout << "Valid Expression\n";
        else
            cout << "Invalid Expression\n";
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
    stack.push_expression("1+2*(3/4)");                                                                // valid
    stack.push_expression("1 + 2 * [3 * 3 + {4 – 5 (6 (7/8/9) + 10)} – 11 + (12*8) / {13 +13}] + 14"); // valid
    stack.push_expression("1 + 2 * [3 * 3 + {4 – 5 (6 (7/8/9) + 10) – 11 + (12*8)] + 14");             // invalid

    return 0;
}