/*
    Παράδειγμα 5: Ποια είναι η έξοδος του παρακάτω προγράμματος;
*/

#include <stdio.h>
#include <math.h>

int main(void)
{
	float a = 3.123;
	if (a == 3.123){
		printf ("Yes \n");
    }
	else{
		printf ("No \n");
    }
	return 0;
}

/*
    WE NEVER COMPARE FLOATING POINTS FOR EQUALITY. In order to do that
    we check if the absolute value of the difference is smaller than a 
    lower limit (precision) we have decided beforehand. E.g.

    #include <stdio.h>
    #include <math.h>

    int main(void)
    {
        float a = 3.123;
        if (fabs(a - 3.123) < 1e-6){
            printf ("Yes \n");
        }
        else{
            printf ("No \n");
        }
        return 0;
    }
*/