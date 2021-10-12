#include <string>
#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

//what D.va meeds for defense matrix
float total_damage(int& botsCount, int botsPower[], float bossPower) 
{
    float sum = 0;

    for (int i = 0; i < botsCount; i++)
    {
        sum += botsPower[i];
    }

    return (sum + bossPower);
    
}


template <typename T>
T missle_power(T a)
{
    return 3*(a);
}

//defense
void load_dva(float& defense_power, float total_damage) //not getting called
{
    if (total_damage > defense_power)
    {
        defense_power = total_damage;
    }

}

//attack
void load_dva(int& micromissile, double power_to_win) //not getting called
{
    float target;
    target = ceil(power_to_win/100);
    if (micromissile < target)
    {
        micromissile = target;
    }
}

int main()
{

    int botsCount;
    float bossPower;
    int micromissile;
    float defensepower;
    float matrixPowerRequired;
    double power_to_win; //variable that takes 3*(matrixPowerRequired)
    int sum_of_bot; //variable to input for missle_power function for sum of all regular bots

    //Open file
    string combatFileName = "combat.txt";
    ifstream combatFile(combatFileName);
    string line;

    //Check file open
    if (!combatFile.is_open())
    {
        cout << "File fail to open." << endl;
        return 0;      
    }

    if (combatFile.is_open())
    {
        //getting values from file
        combatFile >> botsCount;
        int botsPower[botsCount]; // I dont know why this wont work 

        //logic to get combat.txt second line values
        for (int i = 0; i < botsCount; i++)
        {
           combatFile >> botsPower[i];
        }

        //logic to get sum of regular robots
        for (int i = 0; i < botsCount; i++)
        {
            sum_of_bot += botsPower[i];
        }

        //extract other values of combat.txt
        combatFile >> bossPower; 
        combatFile >> micromissile;
        combatFile >> defensepower;

        //calculating matrix power required
        matrixPowerRequired = total_damage(botsCount, botsPower, bossPower);
        power_to_win = missle_power(matrixPowerRequired);

        //display the logic for missle power
        cout << "3X Power needed to kill boss bot: " << missle_power(bossPower) << endl; //float
        cout << "3X Power needed to kill regular bot: " << missle_power(sum_of_bot) << endl;  //int
        cout << "3X Power needed to kill regular bot + boss bot: " << power_to_win << endl; //gloat     
        
    }
  
    //change values for dvas battle
    load_dva(defensepower, matrixPowerRequired); //update defense needed for dva mech suit
    load_dva(micromissile, power_to_win); //load micromissle
   

    //checking to see if we got right values from file
    //will be deleted after confirmation that everything is working correctly
    cout << "botsCount: " << botsCount << endl;
    cout << "boss: " << bossPower << endl;
    cout << "micromissile: " << micromissile << endl;
    cout << "defensepower: " << defensepower << endl;
    cout << "total damage: " << matrixPowerRequired << endl;


    //Report
    ofstream report;
    report.open("report.txt", ios::out | ios::app);
    if(!report.is_open())
    {
        cout << "File fail to open." << endl; 
    }
    else
    {
        report << "D.Va's Combat Report" << endl;
        report << "Combat with " << botsCount << " enemy bots and one enemy boss with power " << bossPower << endl;
        report << "Loaded mech with " << micromissile << " micro missiles and the defense matrix with power " << defensepower << endl;
        report << "Ready for combat!";
        
    }
    
    //close the streams
    combatFile.close();
    report.close();
    return 0;
}
