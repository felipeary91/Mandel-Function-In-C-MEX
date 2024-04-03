#include "mex.h"
#include <stdio.h>
#include <complex.h>
#include <tgmath.h>
#include <omp.h>

#if NEXTRA_PARAMETERS == 0
void MATLAB_main(double *, mxComplexDouble *, size_t);
#elif NEXTRA_PARAMETERS == 1
void MATLAB_main(double *, mxComplexDouble *, size_t, double);
#elif NEXTRA_PARAMETERS == 2
void MATLAB_main(double *, mxComplexDouble *, size_t, double, double);
#elif NEXTRA_PARAMETERS == 3
void MATLAB_main(double *, mxComplexDouble *, size_t, double, double, double);
#elif NEXTRA_PARAMETERS == 4
void MATLAB_main(double *, mxComplexDouble *, size_t, double, double, double, double);
#elif NEXTRA_PARAMETERS == 5
void MATLAB_main(double *, mxComplexDouble *, size_t, double, double, double, double, double);
#elif NEXTRA_PARAMETERS == 6
void MATLAB_main(double *, mxComplexDouble *, size_t, double, double, double, double, double, double);
#elif NEXTRA_PARAMETERS == 7
void MATLAB_main(double *, mxComplexDouble *, size_t, double, double, double, double, double, double, double);
#endif

/* The gateway function */
#include "mex.h"

/* the gateway function */
void mexFunction(int nlhs, mxArray* plhs[], int nrhs, const mxArray* prhs[]) {
    
    #if NEXTRA_PARAMETERS > 0
    double multiplier[NEXTRA_PARAMETERS]; /* input scalars */
    #endif
    
    mxComplexDouble *y;
    mxDouble *z;
    size_t mrows, ncols, numb_elements;
    
    if (nrhs != (1 + NEXTRA_PARAMETERS) )
        mexErrMsgIdAndTxt("MATLAB:xtimesy:invalidNumInputs", "Invalid number of inputs.");
    if (nlhs != 1)
        mexErrMsgIdAndTxt("MATLAB:xtimesy:invalidNumOutputs", "One output required.");
    
    if (!mxIsDouble(prhs[0]) || !mxIsComplex(prhs[0])) {
        mexErrMsgIdAndTxt("MATLAB:xtimesy:fieldNotRealMatrix",
                "First input argument must be complex double vector.");
    }
    
    for (int i = 0; i < NEXTRA_PARAMETERS; i++)
    {
        /* make sure the input argument is scalar */
        if( !mxIsDouble(prhs[i+1]) || mxIsComplex(prhs[i+1]) || mxGetNumberOfElements(prhs[i+1])!=1 )
            mexErrMsgIdAndTxt("MyToolbox:arrayProduct:notScalar","Parameters must be real scalars.");
    }
    
    #if NEXTRA_PARAMETERS > 0
    for (int i = 0; i < NEXTRA_PARAMETERS; i++)
        multiplier[i] = mxGetScalar(prhs[i+1]); /* get the value of the scalar inputs  */
    #endif
    
    /*  create a pointer to the input matrix y */
    y = mxGetComplexDoubles(prhs[0]);
    
    /*  get the dimensions of the matrix input y */
    mrows = mxGetM(prhs[0]);
    ncols = mxGetN(prhs[0]);
    
    if (mrows != 1 && ncols != 1)
        mexErrMsgIdAndTxt("MATLAB:xtimesy:invalidNumInputs", "Input must be a row or column vector.");
    
    if (mrows == 1)
        numb_elements = ncols; 
    else
        numb_elements = mrows;
    
    /*  set the output pointer to the output matrix */
    //plhs[0] = mxCreateDoubleMatrix((mwSize)mrows, (mwSize)ncols, mxREAL);
    plhs[0] =  mxCreateDoubleMatrix(mrows, ncols, mxREAL);
    
    /*  create a C pointer to a copy of the output matrix */
    z = mxGetDoubles(plhs[0]);
        
#if NEXTRA_PARAMETERS == 0
    MATLAB_main(z, y, numb_elements);
#elif NEXTRA_PARAMETERS == 1
    MATLAB_main(z, y, numb_elements, multiplier[0]);
#elif NEXTRA_PARAMETERS == 2
    MATLAB_main(z, y, numb_elements, multiplier[0],multiplier[1]);
#elif NEXTRA_PARAMETERS == 3
    MATLAB_main(z, y, numb_elements, multiplier[0],multiplier[1], multiplier[2]);
#elif NEXTRA_PARAMETERS == 4
    MATLAB_main(z, y, numb_elements, multiplier[0],multiplier[1], multiplier[2], multiplier[3]);
#elif NEXTRA_PARAMETERS == 5
    MATLAB_main(z, y, numb_elements, multiplier[0],multiplier[1], multiplier[2], multiplier[3], multiplier[4]);
#elif NEXTRA_PARAMETERS == 6
    MATLAB_main(z, y, numb_elements, multiplier[0],multiplier[1], multiplier[2], multiplier[3], multiplier[4], multiplier[5]);
#elif NEXTRA_PARAMETERS == 7
    MATLAB_main(z, y, numb_elements, multiplier[0],multiplier[1], multiplier[2], multiplier[3], multiplier[4], multiplier[5], multiplier[6]);
#endif
}