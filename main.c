#include "object.c"
#include <stdio.h>

int main(){
    birthDay* bday = birthDay_constructor(20,11,1995);

    people* jake = people_constructor("Jake Amatsukan", masc, bday);

    people* jake2 = people_constructor2("Jake Amatsukan", masc, 20, 11, 1995);

    printf("bday = %s\n",bday_to_string(bday));
    printf("jake = %s\n", people_to_string(jake));
    printf("jake2 = %s\n", people_to_string(jake2));

    printf("\ninvalid states:\n\n");

    bday = birthDay_constructor(32,11,1995);

    jake = people_constructor("Jake Amatsukan", masc, bday);

    jake2 = people_constructor2("Jake Amatsukan", masc, 20, 13, 1995);

    printf("bday = %s\n",bday_to_string(bday));
    printf("jake = %s\n", people_to_string(jake));
    printf("jake2 = %s\n", people_to_string(jake2));

    return 0;
}
