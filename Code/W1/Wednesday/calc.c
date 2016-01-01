#include <stdio.h>

int main () {
    double x,y;
    char op;
    double rv;
    int a,b;
	while (1) {
        printf("\nenter number 1:  ");
        scanf("%lf",&x);
        printf("\nenter number 2:  ");
        scanf("%lf",&y);
        printf("\nenter operator (+ - * / ^ %% M(max) m(min)):  ");
        scanf(" %c",&op); //it wont wait for scanf unless space is put before %c (dont remove it!)
        
        switch (op) {
            case '+':
                rv = x + y;
                break;
            case '-':
                rv = x - y;
                break;
            case '*':
                rv = x * y;
                break;
            case '/':
                rv = x / y;
                break;
            case '^':
                rv = 1;
                int i;
                for (i = 0; i < y; i++) {
                    rv *= x; //use for loop b/c math.h's pow() not working
                }
                break;
            case '%':
                a = (int) x;
                b = (int) y;
                rv = a % b;
                break;
            case 'M':
                if (x == y) rv = x;
                else if (x > y) rv = x;
                else rv = y;
                break;
            case 'm':
                if (x == y) rv = x;
                else if (x > y) rv = y;
                else rv = x;
        }
	    printf("\n%.3lf %c %.3lf = %.3lf\n\n", x, op, y, rv);
    }
	return 0;
}
