
// © 30012023 Omer Tariq <omertariq@kaist.ac.kr>
//hier functions

#include "foo.h"

void sum_sub_function(din_t *in1, din_t *in2, dout_t *out_sum, dout_t *out_sub)
{
	//dereference the pointer variables in the main function
	*out_sum = *in1 + *in2;
	*out_sub = *in1 - *in2;
}

void shift_func(din_t *in1, din_t *in2, dout_t *out1, dout_t *out2)
{
	//dereference the pointer variables in the main function
	*out1 = *in1 >> 1; //in1 is right shift by 1
	*out2 = *in2 >> 2; //in2 is right shift by 2
}

//main function
void foo(din_t A, din_t B, dout_t *C, dout_t *D)
{
	dint_t apb, ahb;
	sum_sub_function(&A, &B, &apb, &ahb); //provide address of arguments as the definition has parameters as pointers
#ifndef __SYNTHESIS__
	FILE *fp1;
	char filename[255];
	sprintf(filename, "Out_apb_%03d.dat", apb); //formating string for min 3 digital output (%03d)
	fp1=fopen(filename, "w");
	fprintf(fp1, "%d \n", apb);
	fclose(fp1);

#endif
	shift_func(&apb, &ahb, C, D);
}






