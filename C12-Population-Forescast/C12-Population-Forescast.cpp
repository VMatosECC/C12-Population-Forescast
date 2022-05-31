// C12-Population-Forescast.cpp

#include <fstream>
#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
//---------------------------------------------
struct Population
{
    int     year;
    double  people;
    int     change;
};
//----------------------------------------------

void createDB(vector<Population>& vDB);
void processQueries(vector<Population>& vDB);

int main()
{
    vector<Population> vDB;
    createDB(vDB);
    processQueries(vDB);
}

//--------------------------------------------------
//User-defined methods

void createDB(vector<Population>& vDB)
{
    fstream myfile("c:/temp/USA-Census-Bureau-Population-Projection-Zero-Immigration.txt",
                  ios::in);
    if (!myfile) 
    {
        cout << "Error - file not found\n";
        exit(1);
    }

    Population p;
    while (myfile >> p.year)
    {
        myfile >> p.people >> p.change;
        vDB.push_back(p);
    }
    myfile.close();
    
}

void processQueries(vector<Population>& vDB)
{
    cout << fixed << setprecision(1) << showpoint;
    //Q1. find point of inflexion (year in which population stops growing)
    for (int i = 1; i < vDB.size(); i++)
    {
        if (vDB[i - 1].change > 0 && vDB[i].change < 0)
        {
            cout << "Inflexion year: " << vDB[i].year
                << ", Population size: "  << 1000000*(vDB[i].people)
                << " Change: " << 1000 * vDB[i].change << endl;
            break;
        }
    }
}