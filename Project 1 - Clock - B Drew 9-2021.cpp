#include <iostream>
using namespace std;

void DisplayClock(int& clock12Hour, int& clock24Hour, int& clockMin, int& clockSec) {
    //Display 12 Hour Clock
    cout << "12 - Hour Clock" << endl;
    
    //Add a 0 if number between 0 & 9
    if (clock12Hour < 10) {
        cout << "0" << clock12Hour << ":";
    }
    else {
        cout << clock12Hour << ":";
    }
    
    //Display minutes
    if (clockMin < 10) {
        cout << "0" << clockMin << ":";
    }
    else {
        cout << clockMin << ":";
    }

    //Display seconds
    if (clockSec < 10) {
        cout << "0" << clockSec << " ";
    }
    else {
        cout << clockSec << " ";
    }

    //Checks 24 Hour clock to determine AM or PM
    if (clock24Hour > 11) {
        cout << "PM" << endl;
    }
    else {
        cout << "AM" << endl;
    }
    cout << endl;

    //Display 24 Hour Clock
    cout << "24 - Hour Clock" << endl;
    
    //Add a 0 if number between 0 & 9
    if (clock24Hour < 10) {
        cout << "0" << clock24Hour << ":";
    }
    else {
        cout << clock24Hour << ":";
    }

    //Display minutes
    if (clockMin < 10) {
        cout << "0" << clockMin << ":";
    }
    else {
        cout << clockMin << ":";
    }

    //Display seconds
    if (clockSec < 10) {
        cout << "0" << clockSec << endl;
    }
    else {
        cout << clockSec << endl;
    }
    cout << endl;
}

int MenuDisplay() {
    int userInput;
    //Display Menu Options
    cout << "1 - Add One Hour" << endl;
    cout << "2 - Add One Minute" << endl;
    cout << "3 - Add One Second" << endl;
    cout << "4 - End Program" << endl;
    
    //Prompt user to choose
    cout << "Please choose one menu option: ";	
    cin >> userInput;
    cout << endl;

    return userInput;
}

void AddHour(int& clock12Hour, int& clock24Hour) {
    //Add One Hour
    clock12Hour = clock12Hour + 1;
    clock24Hour = clock24Hour + 1;

    //Check 12 Hour Clock to make sure it doesn't go over 12
    if (clock12Hour > 12) {
        clock12Hour = clock12Hour - 12;
    }

    //Check 24 Hour Clock to make sure it doesn't go over 23
    if (clock24Hour > 23) {
        clock24Hour = 0;
    }
}

void AddMin(int& clockMin, int& clock12Hour, int& clock24Hour) {
    //Add one minute
    clockMin = clockMin + 1;

    //Checks to see if minute goes over 60
    if (clockMin == 60) {
        clockMin = 0;
        AddHour(clock12Hour, clock24Hour);
    }
}

void AddSec(int& clockSec, int& clockMin, int& clock12Hour, int& clock24Hour) {
    //Add one second
    clockSec = clockSec + 1;

    //Checks to see if second goes over 60
    if (clockSec = 60) {
        clockSec = 0;
        AddMin(clockMin, clock12Hour, clock24Hour);
    }
}

int main() {
    //Initiate variables
    int clock12Hour = 6;
    int clock24Hour = 18;
    int clockMin = 3;
    int clockSec = 59;
    int loopInput = 0;

    //Create Loop for program
    while (loopInput != 4) {
        //Display clock
        DisplayClock(clock12Hour, clock24Hour, clockMin, clockSec);
        
        //Display Menu
        loopInput = MenuDisplay();

        //Implement the correct function for input
        if (loopInput == 1) {
            AddHour(clock12Hour, clock24Hour);
        }
        else if (loopInput == 2) {
            AddMin(clockMin, clock12Hour, clock24Hour);
        }
        else if (loopInput == 3) {
            AddSec(clockSec, clockMin, clock12Hour, clock24Hour);
        }
        //No need to add last else since I will want the program to end or prompt for a different input
    }


}
