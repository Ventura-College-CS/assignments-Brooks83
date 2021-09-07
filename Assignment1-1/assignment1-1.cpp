#include <iostream>
#include <string>
#include <fstream>
#include <vector>
// gite


struct Student 
{
    int id, total, scores[2];
    double avg;
    char name[10];
};


void findStudent()
{
    while (1)
    {
        std::fstream sfile("Students.bin");     //  Had to redeclare per loop, couldn't find a way to optimize this
        std::string inputID, checkID, name;
        int total, scores[2];
        double avg;

        std::cout << "Enter a student ID (Enter [Q] to quit): ";
        std::cin >> inputID;
        if (inputID == "Q" || inputID == "q")
            return;

        while (sfile >> checkID >> name >> scores[0] >> scores[1] >> total >> avg)   //  Run through bin per line to check then print data
        {
            if (checkID == inputID)
            {
                std::cout << "Name: " << name << "\nScore 1: " << scores[0] << "\nScore 2: " << scores[1] 
                    << "\nTotal Score: " << total << "\nAverage Score: " << avg << std::endl;
            }
        }
    }
}


int main()
{

    std::ifstream file("Students.txt");
    std::string line;
    std::vector<Student> students;


    //  Read txt file, create structs and fill vector
    Student s;
    students.push_back(s);
    for (int i = 0; file >> students[i].id >> students[i].name >> students[i].scores[0] >> students[i].scores[1]; i++)
    {
        Student s;
        students.push_back(s);
        students[i].total = students[i].scores[0] + students[i].scores[1];
        students[i].avg = students[i].total / 2.0;
    }


    //  Write to bin (with formatting)
    std::fstream bin("Students.bin");
    for (int i = 0; i < students.size() - 1; i++)
    {
        //  Ugly but necessary
        bin << students[i].id << " " << students[i].name << " " << students[i].scores[0] << " " << students[i].scores[1] 
            << " " << students[i].total << " " << students[i].avg;
        if (i < students.size() - 2)
            bin << '\n';
    }


    findStudent();


    return 0;
}