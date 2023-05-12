#ifndef LABRATORY_C_20465_2023B_COMPLEX_H
#define LABRATORY_C_20465_2023B_COMPLEX_H

#endif

typedef struct {
    float real_number;
    float imaginary_number;
} ComplexNumber;

void print_comp(ComplexNumber complex_number);

void read_comp(ComplexNumber *complex_number, float real_number, float imahinary_number);

void add_comp(ComplexNumber number1, ComplexNumber number2);

void sub_comp(ComplexNumber number1, ComplexNumber number2);

void mult_comp_real(ComplexNumber number1, float real_number);

void mult_comp_img(ComplexNumber number1, float img_number);

void mult_comp_comp(ComplexNumber number1, ComplexNumber number2);

void abs_comp(ComplexNumber number);


