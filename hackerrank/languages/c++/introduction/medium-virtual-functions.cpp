/*
  tags: implementation, c++
  task: implement the spec (the classes, person, professor, and student)
*/
#include <iostream>
#include <string>

using namespace std;

class Person {
protected:
  string name;
  int age;
public:
  virtual void getdata() = 0;
  virtual void putdata() = 0;
};

class Student : public Person {
private:
  int marks[6];
  static int student_id;
  const int cur_id;
public:
  Student() : cur_id(student_id++) {}

  void getdata() {
    cin >> name;
    cin >> age;
    for (int i = 0; i < 6; i++)
      cin >> marks[i];
  }
  void putdata() {
    int sum = 0;
    for(auto& i : marks)
      sum += i;

    cout << name << " " << age << " " << sum << " " << cur_id << endl;
  }
}; int Student::student_id = 1;

class Professor : public Person {
private:
  int publications;
  static int prof_id;
  const int cur_id;
public:
  Professor() : cur_id(prof_id++) {}

  void getdata() {
    cin >> name;
    cin >> age;
    cin >> publications;
  }
  void putdata() {
    cout << name << " " << age << " " << publications << " " << cur_id << endl;
  }
}; int Professor::prof_id = 1;

int main() {
}
