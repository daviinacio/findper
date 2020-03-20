/*
    ____    __ ___    _ _     __ _ _ __  _ __  ___
   |  _  \ / _` | \  / / |   / _` |  _ \|  _ \/ __|
   | |_ ) | (_| |\ \/ /| |  | (_| | |_) | |_) \__ \
   |____ / \__,_| \__/ |_|   \__,_|  __/|  __/|___/
         copyright 2020    v0.0.1 |_|   |_|  alpha

 *          name: FindPer
 *        author: daviinacio
 *   description: Quick way to find product price change percent
 *       license: MIT

**/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define ARG_NULL -1

#define ERROR_MISSING_ARGS 0
#define ERROR_INVALID_ARGS_NUMBER 1

#define HELP_MAIN 0

using namespace std;


string app_name;

void show_error(int code){
    switch(code){
        case ERROR_MISSING_ARGS:
            cout << app_name << ": Missing arguments" << endl;
            break;

        case ERROR_INVALID_ARGS_NUMBER:
            cout << app_name << ": Invalid argument value" << endl;
            cout << "valid: Number major than zero" << endl;
            break;
    };
}

void show_help(int code){
    switch(code){
        case HELP_MAIN:
            cout << "   -c           Current value" << endl;
            cout << "   -f           Final value" << endl;
            cout << "   -h           Show help" << endl;
            break;
    };
}

int validate(double arg){
    if(arg == ARG_NULL || arg <= 0)
        return 1;

    return 0;
}

// Variables
double current_value = ARG_NULL;
double final_value = ARG_NULL;
double result = 0;

int main(int argc, char *argv[]){
    vector<string> args;
    vector<string>::iterator it;
    int argi = 0;

    app_name = string(argv[0]);

    if(argc > 1)
        args.assign(argv + 1, argv + argc);

    else {
        show_error(ERROR_MISSING_ARGS);
        show_help(HELP_MAIN);
        return 1;
    }

    /*  ARGUMENTS   *   ARGUMENTS   *  ARGUMENTS    */

    // Help
    if(find(args.begin(), args.end(), "-h") != args.end()){
        show_help(HELP_MAIN);
    }

    // Find current value
    if((it = find(args.begin(), args.end(), "-c")) != args.end()){
        argi = distance(args.begin(), it);

        current_value = strtof(args[argi + 1].c_str(), 0);

        if(validate(current_value) == 1){
            show_error(ERROR_INVALID_ARGS_NUMBER);
            return 1;
        }
    }

    // Find final value
    if((it = find(args.begin(), args.end(), "-f")) != args.end()){
        argi = distance(args.begin(), it);

        final_value = strtof(args[argi + 1].c_str(), 0);

        if(validate(final_value) == 1){
            show_error(ERROR_INVALID_ARGS_NUMBER);
            return 1;
        }
    }

    /* RESULT */
    if(validate(current_value) == 0 && validate(final_value) == 0){
        result = ((final_value / current_value) - 1) * 100;

        cout << "Result: " << result << "%" << endl;
    }

    return 0;
}

