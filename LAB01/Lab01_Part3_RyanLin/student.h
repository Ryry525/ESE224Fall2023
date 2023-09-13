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

    //Getter Method
    string getName() const;
    int getRoll_n() const;
    int getMarks() const;
    double getPercent() const;

    //setter Method
    void setName(const string& newName);
    void setRoll_n(int newRoll_n);
    void setMark(int newMark);
    void setPercent(double percent);
    void ranking(Student s2);
};
 #endif