#include <iostream>
using namespace std;

class Stack {
    private:
        int *arr;
        int top;
        int length;
    public:
        Stack(int size){
            length = size;
            arr = new int[size];
            top = -1;
        };

        int isEmpty(){
            return top == -1;
        };

        int isFull(){
            return top + 1 == length;
        };

        bool push(int payload){
            if(isFull()) {
                cout << "Stack is full. Pushing operation failed.\n";
                return false;
            };

            top++;
            arr[top] = payload;
            cout << "Value " << payload << " was successfully pushed into the stack.\n";
            return true;
        };

        int pop() {
            if(isEmpty()) {
                cout << "Stack is already empty.\n";
                return 0;
            }

            int valueToPop = arr[top];
            arr[top] = 0;
            top--;
            return valueToPop;
        };

        int count() {
            return top + 1;
        };

        void display() {
            for(int i = top; i >= 0; i--) {
                cout << i << ": " << arr[i] << endl;
            };
        };

        int peek(int index) {
            if(isEmpty()) {
                cout << "Stack is empty.\n";
                return 0;
            };

            return arr[index];
        };

        int edit(int index, int payload) {
            if(!arr[index]) {
                cout << "Entry could not be found.\n";
                return 0;
            }

            int oldValue = arr[index];
            arr[index] = payload;
            cout << "Value at index " << index << "changed from " << oldValue << "to " << payload << endl;
            return 1;
        };
};

int main(){
    int size;
    cout << "Please enter initialize stack size: \n";
    cin >> size;

    Stack myStack(size);

    myStack.push(10);
    myStack.push(20);
    myStack.push(30);
    myStack.push(40);

    cout << "Stack count: " << myStack.count() << endl;

    cout << "Is stack empty? " << myStack.isEmpty() << endl;

    cout << "Is stack full? " << myStack.isFull() << endl;

    cout << "Value at index 1 is: " << myStack.peek(1) << endl;
    
    // edtting second item from 20 to 100
    myStack.edit(1, 100);
    // popping last item (number 40) from the stack.
    myStack.pop();

    cout << "Displaying stack items: " << endl;
    myStack.display();

    return 0;
};