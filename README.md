# Mandel-Function-In-C-MEX
This piece of code in an implementation of the Mandelbrot set (https://en.wikipedia.org/wiki/Mandelbrot_set). <br />
The whole idea is to compare the function implemented in the `func_mandel.m` file with our implementation in <br />
the C language (`func_mandel_MEX.c`). If both are exactly the same, then the difference should be zero.
<br />
<br />

In order to run the code, execute the following commands:
1. Create the MEX fucntion: `mex -R2018a func_mandel_MEX.c`.
2. Run the test: `mandel_test`.

<br />
<br />

This will produce an output similar to the one below:
<br />
<br />
![plot](https://github.com/felipeary91/Mandel-Function-In-C-MEX/blob/main/Mandel_Function.png?raw=true)

<br />
<br />

**Note:** Some of the files used in this implementation were provided as part of the course "Using C with MATLAB" <br />
taught at the University of Oulu, in 2022.
