#include "./studentfile.h"

void Student::Init()
{

}
void Student::set_name(char* name)
{
    this->student=name;
}
void Student::set_mate(float x)
{
    this->mathematics=x;
}
void Student::set_eng(float x)
{
    this->english=x;
}
void Student::set_his(float x)
{
    this->history=x;
}
void Student::average()
{
    average_grade = (this->mathematics+this->english)/2;
}
char * Student::get_name()
{
    return this->student;
}
float Student::get_eng()
{
    return this->english;
}
float Student::get_avg()
{
    return this->average_grade;
}
float Student::get_his()
{
    return this->history;
}
float Student::get_mate()
{
    return this->mathematics;
}