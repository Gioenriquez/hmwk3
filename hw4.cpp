#include <iostream>

using namespace std;

int main() 
{
    int prior, honeycomb, dandelion, coal, toadstool;
    bool valid_input = false;
    while (!valid_input) {
        cout << "Select a potion crafting priority:" << endl;
        cout << "1. Minor Mana" << endl;
        cout << "2. Minor Healing" << endl;
        cin >> prior;
        if (prior == 1 || prior == 2) {
            valid_input = true;
        } else {
            cout << "Invalid input." << endl;
        }
    }
    cout << "How many Honeycombs do you have?" << endl;
    cin >> honeycomb;
    cout << "How many Dandelions do you have?" << endl;
    cin >> dandelion;
    cout << "How many Coal do you have?" << endl;
    cin >> coal;
    cout << "How many Toadstools do you have?" << endl;
    cin >> toadstool;
    int prior_num, other_num;
    if (prior == 1) {
        prior_num = min(honeycomb / 3, min(dandelion / 2, coal));
        other_num = min(honeycomb - 3 * prior_num, dandelion - 2 * prior_num) / 2;
        other_num = min(other_num, toadstool / 2);
    } else {
        prior_num = min(honeycomb / 2, min(dandelion / 3, toadstool));
        other_num = min(honeycomb - 2 * prior_num, dandelion - 3 * prior_num);
        other_num = min(other_num, toadstool / 2);
    }
       
    cout << "You can make " << prior_num << " " << (prior == 1 ? "Mana" : "Healing") << " potion(s) and " << other_num << " " << (prior == 1 ? "Healing" : "Mana") << " potion(s)." << endl;
    return 0;
}
