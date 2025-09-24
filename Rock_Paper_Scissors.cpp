#include <iostream>
#include <random>
#include <string>

int player_option();

int main(){
    int result = player_option();
    std::cout << "Result: " << result << std::endl;
    
    return 0;
}

int player_option(){

    std::string option;
    std::cout << "Please enter in rock, paper, or scissors (Q to quit): ";
    std::cin >> option;
    
    while (option != "rock" && option != "paper" && option != "scissors" && option != "Q"){
        std::cout << "Invalid choice, please try again." << std::endl;
        std::cout << "Please enter in rock, paper, or scissors (Q to quit): ";
        std::cin >> option;
    }

    if (option == "rock"){
        return 1;
    }
    else if (option == "paper"){
        return 2;
    }
    else if (option == "scissors"){
        return 3;
    }
    else{
        return 0;
    }
        
    }