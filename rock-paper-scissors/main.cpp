#include <iostream>
#include <cstdlib>
#include <unistd.h>
using namespace std;

char idle = 'Y';
string player;

void greetings(){
    cout << "---------------------------" << endl;
    cout << "Welcome to my JAN KEN POM program" << endl;
    cout << "---------------------------" << endl;
    cout << "Choose one (B,G,K):";
    cin >> player;
}

string computerChoose(){
    srand((unsigned) time(NULL));
    int randomNumber = 1 + rand() % 10; 
    if(randomNumber >= 1 && randomNumber < 4){
        return "Batu";
    } else if(randomNumber >= 4 && randomNumber < 7){
        return "Gunting";
    } else if(randomNumber >= 7 && randomNumber < 10){
        return "Kertas";
    } else{
        return "Error";
    }
}

string playerChoose(){
    if(player == "B"){
        return "Batu";
    } else if(player == "G"){
        return "Gunting";
    } else if(player == "K"){
        return "Kertas";
    } else{
        return "Error";
    }
}

string automaticPlayer(int randomNumber){ 
    if(randomNumber >= 1 && randomNumber < 4){
        player = "B";
        return player;
    } else if(randomNumber >= 4 && randomNumber < 7){
        player = "G";
        return player;
    } else if(randomNumber >= 7 && randomNumber < 10){
        player = "K";
        return player;
    }
    
    return "";
}

string determination(){
    if(computerChoose() == playerChoose()){
        return "Draw";
    } else if(computerChoose() == "Gunting" && playerChoose() == "Kertas"){
        return "Computer Wins";
    } else if(computerChoose() == "Batu" && playerChoose() == "Gunting"){
        return "Computer Wins";
    } else if(computerChoose() == "Kertas" && playerChoose() == "Batu"){
        return "Computer Wins";
    } else if(playerChoose() == "Gunting" && computerChoose() == "Kertas"){
        return "Human Wins";
    } else if(playerChoose() == "Batu" && computerChoose() == "Gunting"){
        return "Human Wins";
    } else if(playerChoose() == "Kertas" && computerChoose() == "Batu"){
        return "Human Wins";
    } else{
        return "Error";
    }
}

void result(){
    cout << "---------------------------" << endl;
    cout << "Computer Chose: " << computerChoose() << endl;
    cout << "Human Chose: " << playerChoose() << endl;
    cout << "Result: " << determination() << endl;
}

void again(){
    cout << "-----------------------" << endl;
    cout << "Play Again? (Y/N): ";
    cin >> idle;
    if(idle == 'Y'){
        idle == true;
    } else if(idle == 'N'){
        idle == false;
        cout << "-----------------------" << endl;
        cout << "Thank you for playing with Us" << endl;
    } else {
        cout << "Wrong Command" << endl;
        again();
    }
}

int main(){  
    // If you want to play with real human 
    // while(idle == 'Y'){
    //     greetings();
    //     computerChoose();
    //     playerChoose();
    //     result();
    //     again();
    // } 

    // If you want to play with bot 
    srand((unsigned) time(NULL));
    int limit;
    cout << "Input test limit: ";
    cin >> limit;
    for(int i = 1; i <= limit; i++){
        int randomNumber = 1 + rand() % 10;
        automaticPlayer(randomNumber);
        computerChoose();
        playerChoose();
        result(); 
        cout << "Test Number : " << i << endl;
        sleep(1);
    }
    return 0;
}