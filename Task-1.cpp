#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    int reg_no;
    string st_name;
    float cgpa;

public:
    void input() {
        cout << "Enter registration number: "; cin >> reg_no;
        cin.ignore();
        cout << "Enter name: "; getline(cin, st_name);
        cout << "Enter CGPA: "; cin >> cgpa;
    }
    void output() const {
        cout << "\nRegistration Number: " << reg_no 
             << "\nName: " << st_name 
             << "\nCGPA: " << cgpa << "\n";
    }
};

class Stack {
private:
    Student* students;
    int top, capacity;

public:
    Stack(int size) : capacity(size), top(-1) {
        students = new Student[size];
    }
    ~Stack() { delete[] students; }

    bool isFull() { return top == capacity - 1; }
    bool isEmpty() { return top == -1; }

    void push(const Student& s) {
        if (isFull()) cout << "\nStack is full!\n";
        else students[++top] = s;
    }

    void pop() {
        if (isEmpty()) cout << "\nStack is empty!\n";
        else students[top--].output();
    }
};

int main() {
    int size, choice;
    cout << "Enter stack size: "; cin >> size;
    Stack stack(size);

    do {
        cout << "\n1. Push Student\n2. Pop Student\n3. Exit\nChoice: "; cin >> choice;
        if (choice == 1 && !stack.isFull()) {
            Student s; s.input();
            stack.push(s);
        } else if (choice == 2) {
            stack.pop();
        } else if (choice != 3) {
            cout << "Invalid choice!\n";
        }
    } while (choice != 3);

    return 0;
}
