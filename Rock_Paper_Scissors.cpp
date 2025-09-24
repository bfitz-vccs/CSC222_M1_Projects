#include <iostream>
#include <random>
#include <string>

int player_option();
int winner(int player_choice, int computer_choice);
void score_updater(int winner, int &player_wins, int &computer_wins);
void tournament_winner(int player_wins, int computer_wins);

int player_score = 0;
int computer_score = 0;

int main(){
    int player_input;
    do{
        std::cout << "Welcome to the Rock, Paper Scissors tournament against the computer!" << std::endl;
        player_input = player_option();

        std::random_device engine;
        std::uniform_int_distribution<int>choice(1, 3);
        int computer_choice = choice(engine);

        switch(computer_choice){
            case 1:
                std::cout << "Computer chose rock.";
                break;
            case 2:
                std::cout << "Computer chose paper.";
                break;
            case 3:
                std::cout << "Computer chose scissors.";
                break;
        }

        int result = winner(player_input, computer_choice);
        switch(result){
            case 1:
                std::cout << " Player wins!" << std::endl;;
                break;
            case 2:
                std::cout << " Computer wins!" << std::endl;
                break;
            case 3:
                std::cout << " Draw!" << std::endl;
                break;
        }
        score_updater(result, player_score, computer_score);

    }
    while (player_input != 0);

    std::cout << "\n" << std::endl;
    tournament_winner(player_score, computer_score);
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

int winner(int player, int computer){
    int outcome;
    if (player == computer){
        outcome = 3;
    }
    else if (player == 1 && computer == 2){
        outcome = 2;
    }
    else if (player == 2 && computer == 3){
        outcome = 2;
    }
    else if (player == 3 && computer == 1){
        outcome = 2;
    }
    else if (player == 2 && computer == 1){
        outcome = 1;
    }
    else if (player == 3 && computer == 2){
        outcome = 1;
    }
    else if (player == 1 && computer == 3){
        outcome = 1;
    }
    return outcome;
}

void score_updater(int winner, int &player_wins, int &computer_wins){
    switch (winner){
        case 1:
            player_wins++;
            break;
        case 2:
            computer_wins++;
            break;
    }
}

void tournament_winner(int player_wins, int computer_wins){
    std::cout << "Player score: " << player_wins << std::endl;
    std::cout << "Computer score: " << computer_wins << std::endl;
    if (player_wins > computer_wins){
        std::cout << "Player wins the tournament!" << std::endl;
    }
    else if (player_wins < computer_wins){
        std::cout << "Computer wins the tournament!" << std::endl;
    }
    else{
        std::cout << "The player's score and the computer's score are tied, it's a draw!" << std::endl;
    }
}
