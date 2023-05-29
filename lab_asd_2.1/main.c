#include <stdio.h>
#include <math.h>

double recurDepth(double x, int n, double curr, double res, int i) {
    if (n == 0) {

        return res;
    }

    else {

        curr *= (2 * i - 1) * (x - 1) * (x - 1) / ((2 * i + 1) * (x + 1) * (x + 1));
        res += curr;
        res = recurDepth(x, n - 1, curr, res, i + 1);

    }
    return res;
}

double RESULT = 0;

double recurReturn(double x, int n) {

    double i = -1;
    if (n == 0) {

        i = (x - 1) / (x + 1);
    }
    else {

        i = recurReturn(x, n - 1) * (2 * n - 1) * (x - 1) * (x - 1) / ((2 * n + 1) * (x + 1) * (x + 1));
    }

    RESULT += i;

    return i;
}

double recurBoth(double x, int i, int k, double curr) {
    double res = 0;
    if (i == k + 1) {

        return res + (x - 1) / (x + 1);
    }
    else {

        curr *= (2 * i - 1) * (x - 1) * (x - 1) / ((2 * i + 1) * (x + 1) * (x + 1));
        res = recurBoth(x, i + 1, k, curr);
    }

    res += curr;
    return res;
}

double recurCycle(double x, int n) {
    double curr, res;
    curr = res = (x - 1) / (x + 1);

    for (int i = 1; i <= n; i++) {

        curr *= (2 * i - 1) * (x - 1) * (x - 1) / ((2 * i + 1) * (x + 1) * (x + 1));
        res += curr;
    }

    return res;
}

int main()
{
    int n;
    double x, resDepth, resReturn, resBoth, resCycle;
    double mistakeDepth, mistakeReturn, mistakeBoth, mistakeCycle;

    printf("Enter x: ");
    scanf_s("%lf", &x);
    printf("Enter n: ");
    scanf_s("%d", &n);

    if (x > 0 && n > 1) {
        double resMath = log(x) / 2;
        resDepth = recurDepth(x, n, (x - 1) / (x + 1), (x - 1) / (x + 1), 1);
        resReturn = recurReturn(x, n);
        resBoth = recurBoth(x, 1, n, (x - 1) / (x + 1));
        resCycle = recurCycle(x, n);

        printf("\nMath res = %.12lf\n", resMath);

        printf("\nDepth res = %.12lf", resDepth);
        mistakeDepth = resMath - resDepth;
        printf("\nDepth mistake = %.12lf\n", mistakeDepth);

        printf("\nReturn res = %.12lf", RESULT);
        mistakeReturn = resMath - RESULT;
        printf("\nReturn mistake = %.12lf\n", mistakeReturn);

        printf("\nBoth res = %.12lf", resBoth);
        mistakeBoth = resMath - resBoth;
        printf("\nBoth mistake = %.12lf\n", mistakeBoth);

        printf("\nCycle res = %.12lf", resCycle);
        mistakeCycle = resMath - resCycle;
        printf("\nCycle mistake = %.12lf\n", mistakeCycle);
    }
    else {
        printf("\nx must be greater than 0;");
        printf("\nn must be greater than 1;\n");
    }

    return 0;
}