#include "ran_functions.h"

using namespace std;

unsigned int genRandm_ui() {
	/* The static is VERY IMPORTANT to generate different number */
	static uniform_int_distribution<unsigned> u(0, 9);
	static default_random_engine e;
	return u(e);
}