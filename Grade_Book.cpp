#include <iostream>
#include <string>
#include <fstream>

char assign_letter(double score);
int read_data(std::ifstream& file, std::string names_arr[], int tests_arr[]);

// I did not know how I could make a const global variable for the number of test scores before I had read the text file.
int num_tests;
// Because this project mandates the use of partially filled arrays, I opted to set the student size at 1,000 and the number of tests at 100 as these seemed reasonable.
const int MAX_STUDENTS = 1000;
const int MAX_TESTS = 100;

std::string names[MAX_STUDENTS] = {};
int test_scores[MAX_STUDENTS][MAX_TESTS] = {};
double test_averages[MAX_STUDENTS];

int main(){

    std::ifstream grades_file;
    grades_file.open("StudentGrades.txt");
    read_data(grades_file, names[], test_scores[MAX_TESTS]);


    std::string test = "Hello";

    
    return 0;
}

char assign_letter(double score){
    char grade;
    if (score > 90.0){
        grade = 'A';
    }
    else if (score > 80.0 && score < 90.0){
        grade = 'B';
    }
    else if (score > 70.0 && score < 80.0){
        grade = 'C';
    }
    else if (score > 60.0 && score < 70.0){
        grade = 'D';
    }
    else{
        grade = 'F';
    }
    return grade;
}

int read_data(std::ifstream& file, std::string names_arr[], int tests_arr[][MAX_TESTS]){
    std::string part;
    int student_count = 0;
    int tests_count = 0;
    while (file >> part){
        std::cout << "Part: " << part;
        if (typeid(part).name() != "i"){
            names[student_count] = part;
            student_count++;
        }
        else{
            int int_part = stoi(part);
            test_scores[student_count-1][tests_count] = int_part;
            tests_count++;
        }
    }
    return student_count;
}
 
void grade_report(std::string names_arr[], double averages_arr[]){
    
}