#include<iostream>

using namespace std;

//declaration of stack structure

struct Stack{
    int TOP;
    int cap;
    int *array;
};

//function for creating stack

struct Stack* createStack(/*int size*/){
    struct Stack *stack=new struct Stack;
    stack->TOP=-1;
    //stack->cap=size;
    stack->array=new int;
    return stack;
}

bool isEmpty(struct Stack *s){
    if(s->TOP==-1){
        return true;
    }
    else 
        return false;
}

bool isFull(struct Stack *s){
    if(s->TOP==s->cap-1){
        return true;
    }
    else 
        return false;
}

//function to push element in stack

void push(struct Stack* s,int item){
    if(!isFull(s)){
        s->TOP++;
        s->array[s->TOP]=item;
    }
}

int pop(struct Stack* s){
    if(!isEmpty(s)){
        int item;
        item=s->array[s->TOP];
        s->TOP--;
        return item;
    }
    return (-1);
}

int main(){
    struct Stack *stack;
    stack=createStack(/*2*/);
    int choice,value;

    do   
    {
           
            cout << "Enter the operation on stack." << endl;
            cout << "1. Push " << endl
                  << "2. POP " << endl
                   << "3. Exit" << endl;
            cin >> choice;
            system("clear");
        switch(choice){
            case 1:{
                cout << "Enter the element to push." << endl;
                cin >> value;
                push(stack,value);
                break;
            }

            case 2:{
                 value=pop(stack);
                if(value==-1){
                    cout << "Stack is empty." << endl << endl << endl;
                    }
                    else{
                        cout << "Value at top of stack is " << value << endl << endl << endl;
                    }
                
                break;
            }

            case 3:
            exit (0);
        }
        //cout << "Do you want to continue?   [Y/N]" << endl; 
    } while(cin.get());
}