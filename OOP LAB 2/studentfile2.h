#include <./studentfile.h>
#include <cstring>
int namecompare(Student a, Student b)
{   
    if(!strcmp(a.get_name(),b.get_name()))
        return 0;
    if(strcmp(a.get_name(),b.get_name())>0)
        return 1;
    if(strcmp(a.get_name(),b.get_name())<0)
        return -1;
}
int engcompare(Student a, Student b)
{
    if(a.get_eng()>b.get_eng())
        return 1;
    if(a.get_eng()<b.get_eng())
        return -1;
    return 0;
}
int matecompare(Student a, Student b)
{
    if(a.get_eng()>b.get_eng())
        return 1;
    if(a.get_eng()<b.get_eng())
        return -1;
    return 0;
}
int hiscompare(Student a, Student b)
{
    if(a.get_eng()>b.get_eng())
        return 1;
    if(a.get_eng()<b.get_eng())
        return -1;
    return 0;
}
int avg(Student a, Student b)
{
    if(a.get_eng()>b.get_eng())
        return 1;
    if(a.get_eng()<b.get_eng())
        return -1;
    return 0;
}