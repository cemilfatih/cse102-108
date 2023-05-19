#include <stdio.h>


int main() {
    int yaş, deneyim;
    double maaş;

    printf("Enter age of the employer: ");
    scanf("%d", &yaş);

    printf("Enter years of experience: ");
    scanf("%d", &deneyim);

    if (yaş < 20 && deneyim <= 10) {
        maaş = 10000;
    }
    else if (yaş >= 20 && yaş <= 50 && deneyim > 10) {
        maaş = 20000;
    }
    else if (yaş >= 20 && yaş <= 50 && deneyim < 10) {
        maaş = 15000;
    }
    else if (yaş > 50 && deneyim <= 10) {
        maaş = 20000;
    }
    else if (yaş > 50 && deneyim > 10) {
        maaş = 25000;
    }
    else {
        printf("Dostum çocuk işçi legal değil /ERROR\n");
        return 0;
    }

    printf("Maaş: %.2lf\n", maaş);
    return 0;
}


