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
        // This declaration must move up above the while loop.
        
       // It is better to check the file open status with the below code.
//         if ( sfile.fail())
// 		{
// 			std::cerr << "File Open Error\n";
// 			exit(0);
// 		}
       
        
        std::string inputID, checkID, name;
        // In your binary file Students.bin
        // ID was written with the Integer format.
        // Thus when you read back it, we need the "int" type.
        
        
        
        int total, scores[2];
        double avg;

        std::cout << "Enter a student ID (Enter [Q] to quit): ";
        std::cin >> inputID;
        // inputID should be an integer becuase we need to compare it to checkID.
        
        if (inputID == "Q" || inputID == "q")
            return;

        while (sfile >> checkID >> name >> scores[0] >> scores[1] >> total >> avg)   //  Run through bin per line to check then print data
        {
        
        // sfile >> checkID >> name >> scores[0] >> scores[1] >> total >> avg
        // ----> this line is very critical
        // This statement cause an error. You use it as a condition, thus the loop could not make any iteration.
            
        // The reason why it has error: Your binary file was created in this way according to the line 
//              bin << students[i].id << " " << students[i].name << " " << students[i].scores[0] << " " << students[i].scores[1] 
//             << " " << students[i].total << " " << students[i].avg;
            // thus, your bin file has
            // 4 bytes integer + 1 byte ASCII code for " " + 10 bytes char for name + ( 2 x (4 bytes integer for scores ) ) + 4 bytes integer + 8 bytes double
            
            // This format is completely different to the format that was used in sfile >> .... in the While loop 
            // It is the reason.
            
            // Suggested solution
            // When you write the struct Student, just use the Struct format to write it as binary.
            // for exmaple,
            // after ther for-loop
            // s.write((char *)&s, sizeof(s));
            // that's it to write a struct as a binary format
            
            
            
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
    // this is really great idea to manage the Sturct Student
    // Array is also convenient to manage the Student in this assignment.
    
    

    //  Read txt file, create structs and fill vector
    Student s;
    students.push_back(s);
    
    // Recommend to use the vector in this way.
    // Student s;
    // Fill up the field values first. eg, s.id / s.name / s.score[i] / ...
    // and then push_back(s).
  
      
    // Student s;
//     while( file >> s.id >> s.name >> s.scores[0] >> s.scores[1])
//     {
//         s.total = s.scores[0] + s.scores[1];
//         s.avg = s.total / 2.0;
//         students.push_back(s);
//     }
    
    
    
    
    for (int i = 0; file >> students[i].id >> students[i].name >> students[i].scores[0] >> students[i].scores[1]; i++)
    {
        Student s; // no need. already declared at line 92.
        
        students.push_back(s);
        students[i].total = students[i].scores[0] + students[i].scores[1];
        students[i].avg = students[i].total / 2.0;
    }

  
    
    
    
    

    //  Write to bin (with formatting)
    std::fstream bin("Students.bin");
    for (int i = 0; i < students.size() - 1; i++)
    {
        //  Ugly but necessary
        
        
        // recommend to use write function
        
        // bin.write( (char *)&s, sizeof(s)); 
        
        // this will write the struct student as a bin format.
        
        bin << students[i].id << " " << students[i].name << " " << students[i].scores[0] << " " << students[i].scores[1] 
            << " " << students[i].total << " " << students[i].avg;
        if (i < students.size() - 2)
            bin << '\n';
    }


    findStudent();


    return 0;
}
