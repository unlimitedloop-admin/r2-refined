/**************************************************************/
//
//
//      Copyright (c) 2023 UNLIMITED LOOP ROOT-ONE
//
//
//      This software(and source code) is completely Unlicense.
//      see "LICENSE.md".
//
//
/**************************************************************/
//
//
//      r2-refined project
//
//      File name       : env_params.cc
//
//      Author          : u7
//
//      Last update     : 2023/02/09
//
//      File version    : 1
//
//
/**************************************************************/

/*
 * =============================================================
 *  FILE DESCRIPTION
 * =============================================================
 * Load environment variables as system parameters.
**/



/* INCLUDES */
// C++ SYSTEM HEADER
#include <fstream>
#include <sstream>
#include <string>
#include <map>



/* SOURCES */
namespace {

    // This map contains environment variable values and labels.
    std::map<std::string, std::string> env_params;

}  // plain namespace



namespace protocol {

    __int8 loadParameterFromEnv(const char* file_path) {
        const auto kSymbols = '$';
        try {
            std::string str_key, str_value;
            std::ifstream fs(file_path);
            if (!fs) return 1;

            while (std::getline(fs, str_key)) {
                if (kSymbols == str_key[0]) {
                    std::stringstream ss{ str_key };
                    std::getline(ss, str_key, ' ');
                    std::getline(ss, str_value);
                    env_params[str_key] = str_value;
                }
            }
            return 0;
        }
        catch (const std::exception& e) {
            return -1;
        }
    }


    bool getParameter(const char* label, std::string* byref_args) {
        auto itr = env_params.find(label);
        if (itr != env_params.end()) {
            *byref_args = env_params[label];
            return true;
        }
        else {
            return false;
        }
    }


    bool existsEnvParams(void) {
        if (env_params.empty()) { return false; }
        return true;
    }

}  // namespace protocol