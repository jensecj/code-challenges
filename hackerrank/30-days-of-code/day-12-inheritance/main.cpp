#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Person{
protected:
  string firstName;
  string lastName;
  int id;
public:
  Person(string firstName, string lastName, int identification){
    this->firstName = firstName;
    this->lastName = lastName;
    this->id = identification;
  }
  void printPerson(){
    cout<< "Name: "<< lastName << ", "<< firstName <<"\nID: "<< id << "\n";
  }
};

class Student :  public Person {
private:
  vector<int> testScores;
public:
  Student(string firstName, string lastName, int id, vector<int> scores) : Person(firstName, lastName, id) {
    this->testScores = scores;
  }

  char calculate() {
    float avg = accumulate(testScores.begin(), testScores.end(), 0.0) / testScores.size();

    if(avg < 40) return 'T';
    else if(40 <= avg && avg < 55) return 'D';
    else if(55 <= avg && avg < 70) return 'P';
    else if(70 <= avg && avg < 80) return 'A';
    else if(80 <= avg && avg < 90) return 'E';
    else if(90 <= avg && avg <= 100) return 'O';

    return '0';
  }
};

int main() {
  string firstName;
  string lastName;
  int id;
  int numScores;

  cin >> firstName >> lastName >> id >> numScores;

  vector<int> scores;

  for(int i = 0; i < numScores; i++){
    int tmpScore;
    cin >> tmpScore;
    scores.push_back(tmpScore);
  }

  Student* s = new Student(firstName, lastName, id, scores);

  s->printPerson();

  cout << "Grade: " << s->calculate() << "\n";
}
