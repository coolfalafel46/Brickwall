
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

    vector<string> keys;
    string penis;
    cout << "(c) Brickwall - 2025 DKM Community\n";
    getline(cin,input);

    cout << input + "\n";


    std::ifstream filepath(input);
    json data = json::parse(filepath);
    
    map<string, int> jitems;

    for (auto& tempdata : data.items()) {
    

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


    return 0;
}
