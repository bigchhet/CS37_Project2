#include <string>
#include <iostream>
#include <fstream>
#include <cmath>



using namespace std;

#pragma region 

#pragma endregion
//total damage function
/*takes in an array of ints storing bots' power, the number of bots, 
and a float indicating the boss' power. 
It would return a float telling us the total damage all enemies would give D.Va. 
That would then be how much power D.Va needs for her defense matrix system.*/

float total_damage(int, int[], float);

//missle power function
/*which takes in an int or a float as the parameter indicating the power of 
the enemy and return 3 times the parameter value as the power needed for the missile system. 
Note that this function would only take one number at a time, and the reason that the value 
could be an int or a float is that the power for the enemy bot is an int 
and for the enemy boss is a float. 
The return value would match the type of the parameter*/
template <typename T, typename U>
T missle_power(T botsPower, U boss)
{
    return 3*(botsPower+boss);
}


//load_dva function
/*Load Defense Matrix: The function will take two parameters, the current defense matrix power(read from file) 
and the total damage from all enemies which was returned from total_damage function. 
The function will update the value of the defense matrix power, therefore you will need to pass 
defense matrix power in by reference. Inside this function you want to first check how much 
damage the current defense matrix can absorb(the defense matrix power). 
If the total damage from enemies is less than the current defense matrix power then we don't 
change it, if it's larger, we update the defense matrix power with the total damage from enemies.*/
void load_dva(float total_damage, float defense_matrix)
{

}

//load_dva function
/*Load Micro Missiles: Similar to the load_dva function above, this load_dva function will also take two parameters: 
the number of micro missiles we currently have in the mech(read from file) and 
the missile power needed that we calculated from step 2 in main(). This function will modify 
the number of micro missiles so make sure you pass in the number of micro missiles by reference. 
Inside this function, you want to update the number of micro missiles loaded in our mech. 
The number of micro missiles needed is equal to micro missile power (from step 2) divided by 100. 
Make sure you round this up to an integer, you can use ceil() from <cmath> to round up. 
For example, ceil(23.6) would return integer 24. Make sure you include <cmath> to use the 
function ceil. Again, if the number of missiles needed is less than the current missiles loaded 
in the mech then we don't need to change it, but if it's larger, we update the number of micro 
missiles in our mech.*/
void load_dva(int micromissile, int missle_power)
{

}

int main()
{
    
    //initialze variables
    string s1 = "D.Va's Combat Report:";
    string s2 = "Combat with ";
    string s3 = " enemies.";
    string s4 = "Loaded mech with: ";
    string s5 = " missles.";
    string s6 = "Ready for combat!";

    int botsCount;
    float boss;
    int micromissile = 10;
    int defensepower;

    //prompt user to enter document combat.txt
    string combatFileName = "combat.txt";

    //Open file
    ifstream combatFile(combatFileName);

    //Check file open
    if (!combatFile.is_open())
    {
        cout << "File fail to open." << endl;
        return 0;      
    }

    
    //getting values from file
    combatFile >> botsCount;
    int botsPower[botsCount]; // I dont know why this wont work 
    combatFile >> boss; 
    combatFile >> micromissile;
    combatFile >> defensepower;

    float total_damage = botsCount + sizeof(botsPower) + boss;

    //checking to see if we got right values from file
    cout << "botsCount: " << botsCount << endl;
    cout << "boss: " << boss << endl;
    cout << "micromissile: " << micromissile << endl;
    cout << "defensepower: " << defensepower << endl;


    //4.Report
    return 0;
}