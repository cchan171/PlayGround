/**
@file primitive_datatypes.cpp

@brief
    Basic datatypes with sizes and their syntaxes.

@par 
    char // one byte; 8 bits
    char16_t // 2 bytes; 16 bits
    char32_t // 4 bytes; 32 bits
    wchar_t // largest available char set

    short // 2 bytes; 16 bits
    int // 16 bits or 32 bits; >= short
    long // 32 bits
    long long // 64 bits

    unsigned short // 16 bits
    unsigned // 16 bits
    unsigned long // 32 bits
    unsigned long long // 64 bits

    float // 1.2 x 10^-38 ~ 3.4 x 10^38
    double // 2.2 x 10^-308 ~ 1.8 x 10^308
    long double //3.3 x 10^-4932 ~ 1.2 x 10^4932

    bool // usually 8 bits // 0~false, non-zero~true
    sizeof() // size of bytes of a type or variable

$Author: $

$Date: Mar. 2, 2024$

$Revision: vA0-1$

$Source: $

@par history:
    $Log: $

*/
#include <iostream>
#include <iomanip>

int main() {
    /* initializations */
    // C-like initialization
    int age1 = 21;
    // C++ constructor initialization
    int age2 (21);
    // C++ 11-up list initialization, not allow for narrowing
    int age3 {21};
    std::cout << "age1 = " << age1 << ", age2 = " << age2 << ", age3 = " << age3 << std::endl;

    /* Basic datatypes */
    std::cout << std::setfill('=') << "boolean type" << std::endl;
    bool bool_var {};
    std::cout << "size of bool = " << sizeof(bool_var) << " bytes" << std::endl;

    std::cout << "char types" ;
    char char_var {};
    std::cout << "size of char = " << sizeof(char_var) << " bytes" << std::endl;
    
    char16_t char16_t_var {};
    std::cout << "size of char16_t = " << sizeof(char16_t_var) << " bytes" << std::endl;
    
    char32_t char32_t_var {};
    std::cout << "size of char32_t = " << sizeof(char32_t_var) << " bytes" << std::endl;
    
    wchar_t wchar_t_var {};
    std::cout << "size of wchar_t = " << sizeof(wchar_t_var) << " bytes" << std::endl;
    
    short short_var {};
    std::cout << "size of short = " << sizeof(short_var) << " bytes" << std::endl;
    
    int int_var {};
    std::cout << "size of int = " << sizeof(int_var) << " bytes" << std::endl;
    
    long long_var {};
    std::cout << "size of long = " << sizeof(long_var) << " bytes" << std::endl;
    
    long long llong_var {};
    std::cout << "size of long long = " << sizeof(llong_var) << " bytes" << std::endl;
    
    unsigned short ushort_var {};
    std::cout << "size of unsigned short = " << sizeof(ushort_var) << " bytes" << std::endl;
    
    unsigned uint_var {};   // == unsigned int
    std::cout << "size of unsigned int = " << sizeof(uint_var) << " bytes" << std::endl;
    
    unsigned long ulong_var {};
    std::cout << "size of unsigned long = " << sizeof(ulong_var) << " bytes" << std::endl;
    
    unsigned long long ullong_var {};
    std::cout << "size of unsigned long long = " << sizeof(ullong_var) << " bytes" << std::endl;
    
    float float_var {};
    std::cout << "size of float = " << sizeof(float_var) << " bytes" << std::endl;
    
    double double_var {};
    std::cout << "size of double = " << sizeof(double_var) << " bytes" << std::endl;
    
    long double ldouble_var {};
    std::cout << "size of long double = " << sizeof(ldouble_var) << " bytes" << std::endl;

    return 0;
}