/*
    ____    __ ___    _ _     __ _ _ __  _ __  ___
   |  _  \ / _` | \  / / |   / _` |  _ \|  _ \/ __|
   | |_ ) | (_| |\ \/ /| |  | (_| | |_) | |_) \__ \
   |____ / \__,_| \__/ |_|   \__,_|  __/|  __/|___/
         copyright 2020           |_|   |_|

 *          name: FindPer
 *        author: daviinacio
 *   description: Quick way to find product price change percent
 *       license: MIT

**/

// App informations
#define APP_NAME "findper"
#define APP_VERSION "0.0.1"
#define APP_AUTHOR "daviinacio"
#define APP_COPYRIGHT "daviapps (c) 2020"

// Includes
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define ARG_NULL -1

#define ERROR_MISSING_ARGS 0
#define ERROR_INVALID_ARGS_NUMBER 1
#define ERROR_INVALID_PARAMETERS 2

#define HELP_MAIN 0
#define HELP_GETTING_STARTED 1

using namespace std;


//string app_name;

void show_error(int code){
    switch(code){
        case ERROR_MISSING_ARGS:
            cout << APP_NAME << ": Missing arguments" << endl;
            break;

        case ERROR_INVALID_ARGS_NUMBER:
            cout << APP_NAME << ": Invalid argument value" << endl;
            cout << "valid: Number major than zero" << endl;
            break;

        case ERROR_INVALID_PARAMETERS:
            cout << APP_NAME << ": Invalid parameters" << endl;
            break;
    };
}

void show_help(int code){
    switch(code){
        case HELP_MAIN:
            cout << "   -c           Current value" << endl;
            cout << "   -f           Final value" << endl;
            cout << "   -p           Percentage" << endl;
            cout << endl;
            cout << "   -h           Show help" << endl;
            cout << "   -v           Show version" << endl;
            break;
        
        case HELP_GETTING_STARTED:
            cout << "Calculate profit margin:" << endl;
            cout << "   -c 4        Current value" << endl;
            cout << "   -f 10       Final value" << endl;
            cout << endl;
            cout << "Calculate final value:" << endl;
            cout << "   -c 4        Current value" << endl;
            cout << "   -p 150      Percentage" << endl;
            break;
    };
}

void show_version(){
    cout << APP_NAME << " version " << APP_VERSION << endl;
}

int validate(double arg){
    if(arg == ARG_NULL || arg <= 0)
        return 1;

    return 0;
}

// Variables
double current_value = ARG_NULL;
double final_value = ARG_NULL;
double percentage = ARG_NULL;
double result = 0;

int main(int argc, char *argv[]){
    vector<string> args;
    vector<string>::iterator it;
    int argi = 0;

    //app_name = string(argv[0]);

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
        return 0;
    }

    // Version
    if(find(args.begin(), args.end(), "-v") != args.end()){
        show_version();
        return 0;
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

    // Find percentage
    if((it = find(args.begin(), args.end(), "-p")) != args.end()){
        argi = distance(args.begin(), it);

        percentage = strtof(args[argi + 1].c_str(), 0);

        if(validate(percentage) == 1){
            show_error(ERROR_INVALID_ARGS_NUMBER);
            return 1;
        }
    }

    /*  RESULT   *  RESULT   *    RESULT   *   RESULT   *   RESULT  */
    if(validate(current_value) == 0 && validate(final_value) == 0){
        result = ((final_value / current_value) - 1) * 100;

        cout << "Result: " << result << "%" << endl;
    }
    else
    if(validate(current_value) == 0 && validate(percentage) == 0){
        result = current_value + (current_value * (percentage / 100));

        cout << "Result: R$" << result << endl;
    }
    else {
        show_error(ERROR_INVALID_PARAMETERS);
        show_help(HELP_GETTING_STARTED);
        return 1;
    }

    return 0;
}

