// Example program
#include <iostream>
#include <string>
#include <vector>

class Human
{
  private:
    std::string name, gender;
    int age;
  public:
    Human(std::string name, int age, std::string gender)
    {
        this->name = name;
        this->age = age;
        this->gender = gender;
    }
    void displayData()
    {
      std::cout<<"Name: "<<this->name<<"\n";
      std::cout<<"Age: "<<this->age<<"\n";
      std::cout<<"Gender: "<<this->gender<<"\n";
    }
};

class Student: public Human
{
  private:
    std::vector<int> marks;
  public:
    Student(std::string name, int age, std::string gender, std::vector<int> marks): Human(name, age, gender)
    {
      this->marks = marks;    
    };
    float get_average_mark()
    {
        // Number of marks
        unsigned int count_marks = this->marks.size();
        // Summ of all marks
        unsigned int sum_marks = 0;
        // Average mark.
        float average_mark;

        for (unsigned int i = 0; i < count_marks; ++i) {
            sum_marks += this->marks[i];
        }

        average_mark = (float) sum_marks / (float) count_marks;
        return average_mark;
    };
};

int main()
{
  //Human *human = new Human("Pavlo", 27, "Male");
  //human->displayData();
  
  std::vector<int> marks;
  marks.push_back(5);
  marks.push_back(4);
  marks.push_back(4);
  marks.push_back(3);
  marks.push_back(5);
  marks.push_back(4);
  marks.push_back(4);
  marks.push_back(2);
  marks.push_back(4);
  marks.push_back(3);
  Student *student = new Student("Ivan", 22, "Male", marks);
  student->displayData();
  std::cout<<"Average mark: "<<student->get_average_mark();
}
