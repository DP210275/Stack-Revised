//David Pittman
//CSCI 330
//Implementing a stack/Improving the Stack

#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <utility>
#include <exception>
#include "Stack.h"


void TryPop(StackNodeT* stack) {
    StackNodeT* temp {stack};
    try{
        if(temp == nullptr){
            throw std::logic_error ("Pop attempted on Empty Stack");
        }
    } catch(const std::logic_error& le) {
        std::cout << "Logic Error: " << le.what() << std::endl; 
    }
    return;
}

void TryTop(StackNodeT* stack){
    StackNodeT* temp{stack};
    try {
        if (temp == nullptr){
            throw std::logic_error("Top attempted on Empty Stack");  
        }
    } catch(const std::logic_error& le) {
        std::cout << "Logic Error: " << le.what() << std::endl; 
    }
    return;
}

void FreeNodes(StackNodeT* stack) {
    StackNodeT* temp {stack};
    while (temp != nullptr) {
        stack = stack->link;
        delete temp;
        temp = stack;
        }
    }

void CopyNodes(StackNodeT* fromStack, StackNodeT* & toStack) {
    StackNodeT* rhsCurrent {fromStack};
    StackNodeT* lhsCurrent {nullptr};

    if (fromStack != nullptr) {
        toStack = new StackNodeT;
        toStack->data = rhsCurrent->data;
        rhsCurrent = rhsCurrent->link;
        lhsCurrent = toStack;
        while(rhsCurrent != nullptr) {
            lhsCurrent->link = new StackNodeT;
            lhsCurrent = lhsCurrent->link;
            lhsCurrent->data = rhsCurrent->data;
            rhsCurrent = rhsCurrent->link;
        }
        lhsCurrent->link = nullptr;
    }
}
StackT::StackT() :  stack(nullptr),
                    size(0) {

}

StackT::StackT(const StackT& rhs) :
    stack(nullptr),
    size(rhs.size) {

    CopyNodes(rhs.stack, stack);
}


StackT::~StackT() {
    FreeNodes(stack);
}

StackT& StackT::operator=(const StackT& rhs){
    if(this != &rhs) {
        FreeNodes(stack);
        stack = nullptr;
        size = rhs.size;

        CopyNodes(rhs.stack, stack);
    }
    return *this;
}

StackT::StackT(StackT&& other) noexcept {
    size = std::exchange(other.size, 0);
    stack = std::exchange(other.stack, nullptr);
}

StackT& StackT::operator=(StackT&& rhs) noexcept {
    if (this != &rhs) {
        size = std::exchange(rhs.size, 0);
        stack = std::exchange(rhs.stack, stack);
    }
    return *this;
}

void StackT::Push(ItemT newItem) {
    StackNodeT* newNode = new StackNodeT;
    newNode->link = stack;
    newNode->data = newItem;
    stack = newNode;
    size++;
}
void StackT::Pop(){
    if (IsEmpty()){
        TryPop(stack);
        //throw std::logic_error ("Pop attempted on Empty Stack");  
    } else {
        StackNodeT* temp {stack};
        stack = stack->link;
        delete temp;
        size--;   
    }
 
}

ItemT StackT::Top() const {
    if(IsEmpty()){
        TryTop(stack);
        //throw std::logic_error("Top attempted on Empty Stack");
    } else {
        return stack->data;
    }
    return 0;
}

size_t StackT::Size() const {
    return size;
}

bool StackT::IsEmpty() const {
    return (size == 0);
}
