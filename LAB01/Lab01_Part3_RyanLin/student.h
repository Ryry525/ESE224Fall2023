 #ifndef STUDENT_H
 #define STUDENT_H
 #include <string>
 using namespace std;
class Student
{
private:
    string name;
    int roll_n;
    int mark;
    double percent;
public:
    //constructor
    Student();
    
    void getPercent();
    void comparison(Student s2);
       
    void getDetails();
    void displayDetails();
};
 #endif