#include <ctime>  
#include <cmath>

using namespace std;

bool eval(double A, double B, int ope, double answer){
    /*evaluate the equation and compares it to the answer given by the player. 
    returns true if the answers is correct and false if the answer is wrong*/
    double temp = 0,rounded=0;

    if(ope == 0){
        /*this fucntion will subtract  A to B and compare the two answer and then return a true or false*/
        temp = A - B;
        if(temp == answer){
            return true;
        }
        else{
            return false;
        }
    }
    else if(ope == 1){
        /*this fucntion will add  A to B and compare the two answer and then return a true or false*/
        temp = A + B;
        if(temp == answer){
            return true;
        }
        else{
            return false;
        }
    }
    else if(ope == 2){
        /*this fucntion will Divide A to B and compare the two answer and then return a true or false*/
        temp = A/B;
        rounded = ceil(temp * 100)/100; // rounds up the 2nd decimal number
        if(rounded  == answer){
            return true;
        }
        else{
            return false;
        }
    }
    else if(ope == 3){
        /*this fucntion will multiply A to B and compare the two answer and then return a true or false*/
        temp = A * B;
        if(temp == answer){
            return true;
        }
        else{
            return false;
        }
         
    }
}

int randomizerB(){
    /* return an a value betweem 0 to 3*/
    srand(time(0));
    return rand() % 4;
}

int randomizer(int i){
    /* the number of integers randomized will depend on the paramater i*/
    if(i==0){
        /*Returns a randomized one integer that ranges from 1 - 9*/
        return 1+(rand() % 10);
    }
    else if(i==1){
        /*Returns a randomized two integer that ranges from 10 - 99*/
        return 10+(rand() % 100);
        
    }
    else if(i==2){
        /*Returns a randomized three integer that ranges from 100 - 999*/
        return 100+(rand() % 1000);

    }
}

void howTo(){
    /*Explains the game*/
    cout << "------ HOW TO PLAY ------" <<endl;
    cout << "This game is about who can solve the fastest." << endl;
    cout << "The player must input the correct answer to the equation." << endl;
    cout << "If the answer is wrong, the equation will re - randomize until the answer is correct." << endl;
    cout << "BONUS: ALWAYS round up the 2nd decimal number if the quotient exceeds two decimal numbers.\n" << endl;
}