#include <malloc.h>
#include <string.h>

typedef enum {
    f = 0,
    t
} boolean;

typedef enum {
    masc = 0,
    fem
} sex;

typedef struct{
    unsigned char day;
    unsigned char mon;
    unsigned int yea;
} birthDay;

typedef struct{
    char name[40];
    sex s;
    birthDay* born;
} people;

boolean validateBday(birthDay* bday){
    //only sample
    if(bday->day > 31){
        return f;
    }
    if(bday->mon > 12){
        return f;
    }

    return t;
};

birthDay* birthDay_constructor(unsigned char day, unsigned char month, unsigned int year){
    birthDay* bday = malloc(sizeof(birthDay));
    bday->day = day;
    bday->mon = month;
    bday->yea = year;

    if(validateBday(bday)){
        return bday;
    }

    return 0;
};

people* people_constructor(char* name, sex s, birthDay* bday){
    people* pe = malloc(sizeof(people));
    memcpy(pe->name, name, 40);
    pe->s = s;

    if(bday == 0){
        return 0;
    }

    pe->born = bday;

    return pe;
};

people* people_constructor2(char* name, sex s, unsigned char day, unsigned char month, unsigned int year){
    people* pe = malloc(sizeof(people));
    memcpy(pe->name, name, 40);
    pe->s = s;
    birthDay* bday = birthDay_constructor(day, month, year);
    if(bday == 0){
        return 0;
    }
    pe->born = bday;

    return pe;
};

char * bday_to_string(birthDay* bday){

    if(!bday){
        return "invalid object";
    }

    char * str = calloc(11, sizeof(char));

    sprintf(str,"%d/%d/%d", bday->mon, bday->day, bday->yea);

    return str;
}

char * people_to_string(people* p){

    if(!p){
        return "invalid object";
    }

    char * str = calloc(90, sizeof(char));

    sprintf(str,"Name: %s, sex: %s, bday: %s", p->name, p->s ? "fem" : "masc", bday_to_string(p->born));

    return str;
}
