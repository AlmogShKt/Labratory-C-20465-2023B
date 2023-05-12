#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "complex.h"

/**

Function to print the complex number in the format a + bi.
@param complex_number The complex number to print.
**/
void print_comp(ComplexNumber complex_number) {

    printf("%.2f + (%.2f)i\n", complex_number.real_number, complex_number.imaginary_number);
}

/**

Function to initialize the complex number with real and imaginary numbers.
@param complex_number Pointer to the complex number to initialize.
@param real_number The real number to assign.
@param imaginary_number The imaginary number to assign.
**/
void read_comp(ComplexNumber *complex_number, float real_number, float imaginary_number) {
    complex_number->real_number = real_number;
    complex_number->imaginary_number = imaginary_number;
}

/**

Function to add two complex numbers and print the result.
@param number1 The first complex number.
@param number2 The second complex number.
**/
void add_comp(ComplexNumber number1, ComplexNumber number2) {
    ComplexNumber new_complex_number;
    new_complex_number.real_number = number1.real_number + number2.real_number;
    new_complex_number.imaginary_number = number1.imaginary_number + number2.imaginary_number;
    print_comp(new_complex_number);
}

/**

Function to subtract two complex numbers and print the result.
@param number1 The first complex number.
@param number2 The second complex number.
**/
void sub_comp(ComplexNumber number1, ComplexNumber number2) {
    ComplexNumber new_complex_number;
    new_complex_number.real_number = number1.real_number - number2.real_number;
    new_complex_number.imaginary_number = number1.imaginary_number - number2.imaginary_number;
    print_comp(new_complex_number);
}

/**

Function to multiply a complex number by a real number and print the result.
@param number1 The complex number to multiply.
@param real_number The real number to multiply by.
**/
void mult_comp_real(ComplexNumber number1, float real_number) {
    ComplexNumber new_complex_number;
    new_complex_number.real_number = number1.real_number * real_number;
    new_complex_number.imaginary_number = number1.imaginary_number * real_number;
    print_comp(new_complex_number);
}

/**

Function to multiply a complex number by an imaginary number and print the result.
@param number1 The complex number to multiply.
@param img_number The imaginary number to multiply by.
**/
void mult_comp_img(ComplexNumber number1, float img_number) {
    ComplexNumber new_complex_number;
    new_complex_number.real_number = (number1.imaginary_number * img_number) * -1;
    new_complex_number.imaginary_number = number1.real_number * img_number;
    print_comp(new_complex_number);
}

/**

Function to multiply two complex numbers and print the result.
@param number1 The first complex number.
@param number2 The second complex number.
**/
void mult_comp_comp(ComplexNumber number1, ComplexNumber number2) {
    ComplexNumber new_complex_number;
    new_complex_number.real_number = number1.real_number * number2.real_number
                                     + -1 * (number1.imaginary_number * number2.imaginary_number);
    new_complex_number.imaginary_number =
            number1.real_number * number2.imaginary_number + number2.real_number * number1.imaginary_number;
    print_comp(new_complex_number);
}

/**

Function to calculate the absolute value of a complex number and print the result.
@param number The complex number to calculate the absolute value of.
**/
void abs_comp(ComplexNumber number) {
    ComplexNumber new_complex_number;
    new_complex_number.real_number = sqrt(
            number.real_number * number.real_number + number.imaginary_number * number.imaginary_number);
    new_complex_number.imaginary_number = 0;
    print_comp(new_complex_number);
}
