// wall.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include "includes\nlohmann\json.hpp"

using namespace std;
using json = nlohmann::json;

int main()
{
    string input;
    //json tempdata = json::object();
    vector<string> keys;
    string penis;
    cout << "(c) Brickwall - 2025 DKM Community\n";
    //getline(cin,input);
    input = R"(C:\Users\superiorFexin\Desktop\testing.json)";
    cout << input + "\n";


    std::ifstream filepath(input);
    json data = json::parse(filepath);
    
    map<string, int> jitems;

    for (auto& tempdata : data.items()) {
    
        //cout << tempdata.key() << "\n";
        /*cout << tempdata.value().dump() << "\n"; */
        //cout << tempdata.value() << "\n";

        //aaa blyat koroche suka shtuki
        for (auto& j : tempdata.value().items()) {
        
            if (jitems.find(j.key()) == jitems.end()) {
                jitems[j.key()] =1;
            }
            else {
                jitems[j.key()]++;
            }
            
        }
        
    }
    
    for (auto it = jitems.begin(); it != jitems.end(); ++it)
    {
        // Add the key to the vector
        //keys.push_back(it->first);
        cout << it->first << "(" << jitems[it->first] <<")" << "\n";
        
    }
    getline(cin, penis);
    if (jitems.find(penis) == jitems.end()) {
        cout << "idi nahuy" << "\n";
    }
    else {
        cout << penis << "\n";
        for (auto& tempdata : data.items()) {
            cout << "-> In object: " << tempdata.key() << " = "<< tempdata.value()[penis] << "\n";
        }
    }

    /*for (int i = 0; i < data.size(); i++) {
    
        cout << data[i] << "\n";

    }*/

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
