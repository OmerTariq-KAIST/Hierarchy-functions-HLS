#include "foo.h"
int main() {
	// Data storage
	int a[NUM_TRANS], b[NUM_TRANS];
	int c_expected[NUM_TRANS], d_expected[NUM_TRANS];
	int c[NUM_TRANS], d[NUM_TRANS];

	//Function data (to/from function)
	int a_actual, b_actual;
	int c_actual, d_actual;

	// Misc
	int	retval=0, i, i_trans, tmp;
	FILE *fp;

	// Load input data from files
	fp=fopen("inA.dat","r");
	for (i=0; i<NUM_TRANS; i++){
		fscanf(fp, "%d", &tmp);
		a[i] = tmp;
	}
	fclose(fp);

	fp=fopen("inB.dat","r");
	for (i=0; i<NUM_TRANS; i++){
		fscanf(fp, "%d", &tmp);
		b[i] = tmp;
	}
	fclose(fp);

	// Execute the function multiple times (multiple transactions)
	for(i_trans=0; i_trans<NUM_TRANS-1; i_trans++){

		//Apply next data values
		a_actual = a[i_trans];
		b_actual = b[i_trans];

	//calling the main function
    foo(a_actual, b_actual, &c_actual, &d_actual); //foo(A, B, *C, *D)

    //Store outputs
			c[i_trans] = c_actual;
			d[i_trans] = d_actual;
	}

	// Load expected output data from files
	fp=fopen("outC.golden.dat","r");
	for (i=0; i<NUM_TRANS; i++){
		fscanf(fp, "%d", &tmp);
		c_expected[i] = tmp;
	}
	fclose(fp);

	fp=fopen("outD.golden.dat","r");
	for (i=0; i<NUM_TRANS; i++){
		fscanf(fp, "%d", &tmp);
		d_expected[i] = tmp;
	}
	fclose(fp);

	// Check outputs against expected ** comparison between actual and expected
	for (i = 0; i < NUM_TRANS-1; ++i) {
		if(c[i] != c_expected[i]){
			retval = 1;
		}
		if(d[i] != d_expected[i]){
			retval = 1;
		}
	}

	// Print Results
	if(retval == 0){
		printf("    *** *** *** *** \n");
		printf("    Results are good \n");
		printf("    *** *** *** *** \n");
	} else {
		printf("    *** *** *** *** \n");
		printf("    Mismatch: retval=%d \n", retval);
		printf("    *** *** *** *** \n");
	}

	// Return 0 if outputs are correct
	return retval;
}
