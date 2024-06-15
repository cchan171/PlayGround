/**
@file array_example.cpp

@brief
    A Compound data types or data structures.
        - All elements are the same type.
        - All elements can be accessed directly.
    Two types of array:
        - C-type array.
        - STL array.
    C-type array:
        - Fixed size
        - Same type
        - Contiguously in memory
        - "No checking if Out-Of-Bounds"
@par 
    

$Author: Willie Chang $

$Date: Apr. 21, 2024$

$Revision: vA0-1$

$Source: URL:https://www.udemy.com/course/beginning-c-plus-plus-programming/learn/lecture/9535386#overview $

@par history:
    $Log: $

*/
#include <iostream>
#include <array>

int main() {
    /* Declarations */
    // element_type arr_name[constant_number_of_elements];
    int test_scores [5];
    int high_score_per_level [10];
    
    const int days_in_yrs {365};    // declare a const var
    double hi_temp[days_in_yrs];    // apply the const to the size

    /* Initialization */
}