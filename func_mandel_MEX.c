// mex -R2018a func_mandel_MEX.c
// Just a simple template, you need to modify almost everything below!!!
#define NEXTRA_PARAMETERS 1
#include "COMPLEX_VECTOR_IN_REAL_VECTOR_OUT.h"
double absolute(complex double a, size_t numb_elements);

void MATLAB_main(double* output, mxComplexDouble* input, size_t numb_elements, double maxIterations)
{   
    //Creating z_local and allocating it on the heap
    complex double *z_local;
    z_local = (complex double*)calloc(numb_elements, sizeof(complex double));

    //Creating inside and allocating it on the heap
    double *inside;
    inside = (double*)calloc(numb_elements, sizeof(double));

    //Populating z_local and inside
    for (int i=0; i < numb_elements; i++) {
        z_local[i] = input[i].real + I*input[i].imag;
        inside[i] = 0;
    }

    //Declaring internal variable z0
    complex double z0;

    //Iterating
    for (int j=0; j <= maxIterations; j++) {
        for(int k=0; k < numb_elements; k++) {

            //Saving current input element in z0
            z0 = input[k].real + I*input[k].imag;
            
            //Computing z^2 + z0
            z_local[k] = cpow(z_local[k], 2) + z0;

            //Checking if it's necessary to increase the inside
            if (cabs(z_local[k]) <= 2) {
                inside[k] += 1;
            }
        }
        
        //Saving the output value
        for (int l=0; l < numb_elements; l++) {
            output[l] = inside[l];
        }
    }

    //Freeing resources
    free(z_local);
    free(inside);
}
