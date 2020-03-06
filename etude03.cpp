#include <iostream>
#include <cstdlib>
#include <string>
#include <istream>
#include <sstream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <bitset>

using namespace std;

struct Scenario {
    vector<int> numbers;
    int target_value;
    char order_mode;
    string output;
};

int main () { 

    // parse input and create Scenarios
    cout << "Give input, enter 'Done' when finished:" << endl;

    vector<Scenario> scenarios;
    string line;
    Scenario s;
    int line_number = 0;
    char termination_key[] = "Done";
    bool terminate = false;

    while (!terminate && getline(cin, line)) {
        line_number++;
        stringstream ss(line);

        if (strcmp(line.c_str(), termination_key) == 0) {
            terminate = true;
        }

        // input from first line
        if (line_number % 2 == 1) {
            int number;
            s.numbers.clear();
            while (ss >> number) {
                s.numbers.push_back(number);
            }
        }
        else {
            // input from second line
            int target_value;
            char order_mode;
            ss >> target_value;
            ss >> order_mode;
            s.target_value = target_value;
            s.order_mode = order_mode;
        }

        if (!terminate && line_number % 2 == 0) {
            scenarios.push_back(s);
        }
    } 


    // do computation
    for (Scenario sc: scenarios) {
        bool solution_found = false;

        // iterate through all permutations of list of numbers
        vector<int> vec_numbers = sc.numbers;
        int len = vec_numbers.size();
        int numbers[len];
        copy(vec_numbers.begin(), vec_numbers.end(), numbers);
        sort(numbers, numbers + len);

        int num_operators = len - 1;

        
        if (sc.order_mode == 'L') {
            // do all permutations of [+/*, +/*, ...] using a binary string where 0='+', 1='*'
            int sum = numbers[0];
            for (int j = 0; j < 2^num_operators; j++) {
                string binary = bitset<num_operators>(j).to_string();

                // compute sum by looping through all operators and performing operations
                for (int k = 0; k < num_operators; k++) {
                    char op = binary[k];
                    if (op == '0') { // '+'
                        sum += numbers[k+1];
                    } 
                    else { // '*'
                        sum *= numbers[k+1];
                    }
                }
            }
            if (sum == sc.target_value) {
                // FOUND SOLUTION, SAVE PERMUTATIONS AND CONVERT AND SAVE TO SC.OUTPUT
                // BREAK
            }
        }
        else { // normal order of operations
            int sum = 0;
            for (int j = 0; j < 2^num_operators; j++) {
                string binary = bitset<num_operators(j).to_string();

                // compute sum
                for (int k = 0; k < num_operators; k++) { // pass for *
                    
                }
                for (int k = 0; k < num_operators; k++) { // pass for +

                }
            }
        }
            
      

        if (solution_found) {
            // add string for output to output vector
        }
        else {
            // add string for IMPOSSIBLE to output vector
        }

    }



    /*  TESTING FOR SCENARIO OBJECT AND INPUT READING
    while (!scenarios.empty()) {
        reverse(scenarios.begin(), scenarios.end());
        Scenario s = scenarios.back();
        scenarios.pop_back();

        vector<int> numbers = s.numbers;
        for (int i = 0; i < numbers.size(); i++) {
            cout << numbers[i] << " ";
        }
        cout << endl;
        cout << "target: " << s.target_value << endl;
        cout << "mode: " << s.order_mode << endl;
 
    }
    */
    


    return 0;
}