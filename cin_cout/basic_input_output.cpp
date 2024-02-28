/**
@file basic_input_output.cpp

@brief
    Basic Cpp standard input/output demos

@par


$Author: Willie Chang$

$Date: Feb. 22, 2024$

$Revision: A0-1$

$Source: $

@par history:
    $Log: $

*/
#include <iostream>
#include <string>
// #include <bits/stdc++.h>

int main() {
    std::string name;
    std::cout << "Enter your name: ";   // no need for flushes here, before cin
    
    std::getline(std::cin, name);
    std::cout << "You name is " << name << "!" << std::endl;

    return 0;
}