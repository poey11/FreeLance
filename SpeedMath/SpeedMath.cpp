#include <iomanip>
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <chrono>

#include "func.h"   
#include "menu.h"

using namespace std;

/*TODO
    Finish designing the start menu (put it in the menu.h file)
    Finish designing the gameOver / retry menu (put it in the menu.h file)
*/

int main(){
    int start = 0, diff = 0,C=0;
    double A =0,B=0, answer =0,highestTime =0, currentTime=0, prevQuickTime=0;;
    bool MenuisRunning = true, gameIsRunning = false,gameStart = false, roundStart = false, isAnswerCorrect = false, validAnswer = false, retry = false;
    const char* modes[3] = {"Easy", "Medium", "Hard"};
    char stop;
    char operators[4] = {'-', '+', '/', '*'};
    

    while(MenuisRunning == true){
        /*start menu*/
        startMenu();
        cout << "[1] Start" << endl;
        cout << "[2] Quit" << endl;
        cout << "[> ";
        cin >> start;

        if(start == 1){
            /*if the player wants to start the game*/
            MenuisRunning = false;
            gameIsRunning = true;
        }
        else if(start == 2){
            /*if the player wants to quit the game*/
            MenuisRunning = false;
            system("cls");
            cout<<endl;
        }
        else{
            /*if the player enters an invalid input*/
            cout << "\nInvalid Choice!!!" << endl;
            cout << "Press any button to continue"<< endl;
            getch();
            system("cls");
        }
    }

    while(gameIsRunning == true){    
        /*Shows the difficulty Menu and instructions*/   
        system("cls");
        howTo();

        cout << "Pick a difficulty: "<< endl;
        cout << "[1] Easy" <<endl;
        cout << "[2] Medium" <<endl;
        cout << "[3] Hard" <<endl;
        cout << "[> ";
        cin >> diff;
        cout << endl;

        if(diff < 1 || diff > 3){
            cout << "Invalid Choice!!!" << endl;
            cout << "Press any button to continue"<< endl;
            getch();

        }
        else{
            gameStart = true; // enable the actual the game
            system("cls");
            diff--;
        } 
        
        while(gameStart == true){
            /*The actual game*/
            cout << "You have Choosen "<<modes[diff] << " Difficulty...."<<endl;
            cout << "The Timer will start after you begin the game...." << endl;
            cout << "Press any button to Start....\n"<<endl;
            getch();
            
            roundStart = true;
            auto start = chrono::system_clock::now();//timer starts

            /*prints out the equation with numbering*/
            for(int i = 0; i < 10; i++){
                while(roundStart == true){
                    /*Prevents the player to proceed as long as the answer is wrong*/
                    srand(time(0));
                    A = randomizer(diff);
                    B = randomizer(diff);
                    C = randomizerB();
                    if(validAnswer == false){
                        cout << "["<<i+1<<"] " << A <<" " << operators[C] << " " << B << " = ?"<<endl;
                        cout << "[> ";
                        cin >> answer;
                        isAnswerCorrect = eval(A,B,C,answer);// validates the player answer
                        if(isAnswerCorrect == true){
                            // if the answer is correct, procceds to the next question
                            validAnswer = true;
                            roundStart = false;
                        }
                        else{
                            system("cls");
                            cout << "Incorrect Answer. Try Again" << endl;
                        }
                    }
                }
                
                system("cls");
                roundStart = true;
                validAnswer = false;
            }

            auto end = chrono::system_clock::now();//timer ends
            chrono::duration<double> elapsed_seconds = end-start; //subtracts end time with the starting time to get the elapsed time
            currentTime = elapsed_seconds.count(); 

            while(retry == false){
                /*When the player finishes the 10 equations, will be prompt to retry the game*/
                gameOver();
                cout << "You Got A Time of : " << setprecision(4)<<currentTime << " Seconds!!\n" <<endl;
                if(highestTime == 0 ){
                    /*if there is no quickest time yet, sets the current time as the quickest*/
                    highestTime = currentTime;
                    cout << "Quickest Time: " << setprecision(4)<< highestTime <<endl;
                    cout << "Current Time: "<< setprecision(4)<< currentTime << endl;
                }
                else if(currentTime < highestTime){
                    /*if the player beats the quickest time, updates the quickest time and prev quickest time*/
                    prevQuickTime = highestTime;
                    highestTime = currentTime;
                    cout << "Congratulation You Were the Quickest!!" << endl;
                    cout << "Quickest Time: " << setprecision(4)<< highestTime << " Seconds"<<endl;
                    cout << "Previous Quickest Time:  " << setprecision(4)<< prevQuickTime << " Seconds"<<endl;
                    cout << "Current Time: "<< setprecision(4)<< currentTime  << " Seconds" << endl;
                }
                else{
                    /*if the player wasnt able to beat the quickest time*/
                    cout << "Quickest Time: " <<  setprecision(4)<< highestTime  << " Seconds"<<endl;
                    cout << "Current Time: "<< setprecision(4)<< currentTime  << " Seconds"<< endl;
                }

                cout << "\nWould You like to try again? (Y/N)" << endl;
                cout << "[> ";
                cin >> stop;
                
                if(stop == 'Y' || stop == 'y'){
                    /*Resets the whole game*/
                    gameStart = false;
                    retry = true;
                }
                else if( stop == 'N' || stop == 'n'){
                    /*Exit the game*/
                    gameStart = false;
                    gameIsRunning = false;
                    retry = true;

                }
                else{
                    /*if the player inputted an invalid choice*/
                    cout << "INVALID CHOICE..."<<endl;
                    cout <<"Press any button to continue" << endl;
                    getch();
                }
                system("cls");
            }
                retry = false;
            
        }
        
    }
    exit();
    cout << "Thank You for Playing Speed Math!!!!" << endl;
    cout << "Press any button to exit the Game." << endl;
    getch();

    

    return 0;
    
}