class Student
{
    char* student;
    float mathematics,english,history;
    float average_grade;
public:
    void Init();
    void set_name(char* name);
    void set_mate(float x);
    void set_eng(float x);
    void set_his(float x);
    void average();
    char* get_name();
    float get_mate();
    float get_eng();
    float get_his();
    float get_avg();

};