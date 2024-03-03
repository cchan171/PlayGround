/**
@file advanced_input_output.cpp

@brief
    Advanced Cpp standard input/output demos
    

@par 
    Common Header Files:
        <iostream>: Provides definitions for formatted input and output from/to streams
        <iomanip>: Provides definitions for manipulators used to format stream I/O
    Common Stream Files:
        std::ios -> Provides basic support for formatted and unformatted I/O operations.
        std::ifstream -> Provides for high-level input operations on file based streams.
        std::ofstream -> Provides for high-level output operations on file based streams.
        std::fstream -> Provides for high-level I/O operations on file based streams. Derived from std::ofstream and std::ifstream.
        std::stringstream -> Provides for high-level I/O operations on memory based strings. Derived from std::istringstream, std::ostringstream.
    Global Stream Objects:
        std::cin -> Standard input stream, instance of std::istream
        std::cout -> Standard output stream, instance of std::ostream
        std::cerr -> Standard error stream, instance of std::ostream (unbuffered)
        std::clog -> Standard log stream, instance of std::ostream (unbuffered)
    Common Stream Manipulators:
        <Boolean>:
            std::boolalpha, std::noboolalpha
        <Integer>:
            std::dec, std::hex, std::oct, std::showbase, std::noshowbase, std::showpos, std::noshowpos, std::uppercase, std::nouppercase
        <Floating Point>:
            std::fixed, std::scientific, std::setprecision, std::showpoint, std::noshowpoint, std::showpos, std::noshowpos
        <Field Width, Justification & Fill>:
            std::setw, std::left, std::right, std::internal, std::setfill
        <Others>
            std::endl, std::flush, std::skipws, std::noskipws, std::ws

$Author: $

$Date: Feb. 27, 2024$

$Revision: vA0-1$

$Source: $

@par history:
    $Log: $

*/
#include <iostream>
// #include <fstream>
#include <iomanip>
#include <string>

int main() {
    /* Stream Manipulator */
    std::cout.width(10);
    std::cout << "||" << std::endl;
    std::cout << std::setw(10) << std::endl;

    /* Formatting Boolean Types */ 
    std::cout << std::noboolalpha;  // all the following will be int boolean
    // std::cout.setf(std::ios::noboolalpha);   // Method version
    std::cout << (10 == 10) << std::endl;   // 1
    std::cout << (10 == 20) << std::endl;   // 0
    std::cout << std::boolalpha;    // all the following will be string boolean 
    // std::cout.setf(std::ios::boolalpha);     // Method version
    std::cout << (10 == 10) << std::endl;   // true
    std::cout << (10 == 20) << std::endl;   // false
    std::cout << std::resetiosflags(std::ios::boolalpha);   // reset to the default flag

    /* Formatting Integer Types */
    int num {255};                              // 255
    // set base
    std::cout << std::dec << num << std::endl;  // 255  // decimal by default
    std::cout << std::hex << num << std::endl;  // ff   // hexadecimal
    std::cout << std::oct << num << std::endl;  // 377  // octal
    // show base
    std::cout << std::showbase; // std::noshowbase
    std::cout << std::dec << num << std::endl;  // 255  // decimal by default
    std::cout << std::hex << num << std::endl;  // 0xff // hexadecimal, with 0x prefix
    std::cout << std::oct << num << std::endl;  // 0377 // octal, with 0 prefix
    // show base uppercase
    std::cout << std::showbase << std::uppercase;
    std::cout << std::hex << num << std::endl;  // 0XFF // hexadecimal, with 0x prefix
    std::cout << std::noshowbase << std::nouppercase;
    // display positive sign
    std::cout << std::showpos;  // std::noshowpos   // taggle back
    int num1 {255}, num2 {-255};
    std::cout << num1 << std::endl;             // +255
    std::cout << num2 << std::endl;             // -255
    std::cout << std::noshowpos;

    /* Setting/Resetting Integer Types */
    // using setf
    std::cout.setf(std::ios::showbase);
    std::cout.setf(std::ios::uppercase);
    std::cout.setf(std::ios::showpos);
    // reset to defaults
    std::cout << std::resetiosflags(std::ios::basefield);
    std::cout << std::resetiosflags(std::ios::showbase);
    std::cout << std::resetiosflags(std::ios::showpos);
    std::cout << std::resetiosflags(std::ios::uppercase);

    /* Floating Point Types Precisions */
    double num3 {123456789.987654321};
    double num4 {1234.5678};
    std::cout << num4 << std::endl;     // 1234.57
    std::cout << num3 << std::endl;     // 1.23457e+008     // Default precision is 6
    // set precision with roundings
    std::cout << std::setprecision(9);  
    std::cout << num3 << std::endl;     // 123456790        // rounding occurs
    // fixed precision from decimal point
    std::cout << std::fixed;
    std::cout << num3 << std::endl;     // 123456789.987654 // display 6 digits from the decimal point
    std::cout << std::setprecision(3) << std::fixed;
    std::cout << num3 << std::endl;     // 123456789.988    // display 3 digits from the decimal point
    // scientific 
    std::cout << std::setprecision(3)
              << std::scientific;       // set preicions with scientific notation
    std::cout << num3 << std::endl;     // 1.23e+008        // display precison 3
    // display positive sign
    std::cout << std::setprecision(3)
              << std::fixed
              << std::showpos;
    std::cout << num3 << std::endl;     // +123456789.988
    std::cout << std::resetiosflags(std::ios::floatfield);
    std::cout << std::resetiosflags(std::ios::showpos);
    // std::cout.unsetf(std::ios::scientific | std::ios::fixed);
    // show trailing zeros
    std::cout << std::setprecision(6);
    double num5 {12.34};
    std::cout << num5 << std::endl;      // 12.34
    std::cout << std::showpoint;
    std::cout << num5 << std::endl;      // 12.3400      // trailing up to precision; which is default as 6

    /* Field Width, Alignment & Fill */
    // default
    double num6 {1234.5678};
    std::string hello {"Hello"};
    std::cout << num6 << std::endl;
    std::cout << hello << std::endl;
    /* 
    1234.57
    Hello
    */
    // setw // create a field width of 10 for the next data item only
    std::cout << std::setw(10) << num6
              << hello
              << std::endl;
    /*  right-most for num6; no apply to hello
    1234567890123456789012345678901234567890
       1234.57Hello
    */
    std::cout << std::setw(10) << num6
              << std::setw(10) << hello
              << std::setw(10) << hello
              << std::endl;
    /*  right-most for num6; no apply to hello
    1234567890123456789012345678901234567890
       1234.57     Hello     Hello
    */
    std::cout << std::setw(10)
              << std::left
              << num6        // only affects num!
              << hello << std::endl;
    /*  right-most for num6; no apply to hello
    1234567890123456789012345678901234567890
    1234.57   Hello
    */
    std::cout << std::setw(10) << num6
              << std::setw(10) << std::right << hello
              << std::setw(15) << std::right << hello
              << std::endl;
    /*  right-most for num6; no apply to hello
    1234567890123456789012345678901234567890
       1234.57     Hello          Hello
    */
    std::cout << std::setfill('-');
    std::cout << std::setw(10) << num6
              << hello << std::endl;
    /*  right-most for num6; no apply to hello
    1234567890123456789012345678901234567890
    ---1234.57Hello
    */
    std::cout << std::setfill('*');
    std::cout << std::setw(10) << num6  // both setfill and setw goes to num6 var
              << std::setfill('-') << std::setw(10) << hello
              << std::setw(15) << hello << std::endl;   // since setfill is still in the same statement, both hello vars have setfill, but with separate setw
    /*  right-most for num6; no apply to hello
    1234567890123456789012345678901234567890
    ***1234.57-----Hello----------Hello
    */

    return 0;
}