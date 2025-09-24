#include <iostream>
#include <string>

char assign_letter(double score);

int main(){
    char grade = assign_letter(89.9);
    std::cout << "Grade: " << grade;
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