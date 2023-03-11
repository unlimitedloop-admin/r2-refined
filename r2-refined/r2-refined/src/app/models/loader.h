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
//      File name       : loader.h
//
//      Author          : u7
//
//      Last update     : 2023/03/11
//
//      File version    : 1
//
//
/**************************************************************/

/*
 * =============================================================
 *  FILE DESCRIPTION
 * =============================================================
 * This is a variable abstract function for pulling material files and storing them in memory.
**/



#ifndef _R2R_APP_MODELS_LOADER_H_
#define _R2R_APP_MODELS_LOADER_H_

/* INCLUDES */
// C++ SYSTEM HEADER
#include <string>



/* SOURCES */
namespace models {

    namespace extends {

        /// <summary>
        /// Abstract class for file loaders.
        /// </summary>
        class Loader {

        private:
            /// <summary>
            /// Filepath.
            /// </summary>
            std::string files_;

        protected:
            explicit Loader() {
                files_ = { "" };
            }

            ~Loader() {
                files_.clear();
                files_.shrink_to_fit();
            }

            /// <summary>
            /// Set the filepath.
            /// </summary>
            /// <param name="filepath">Filepath(fullpath required)</param>
            void setFile(std::string filepath) {
                files_ = filepath;
            }

            /// <summary>
            /// Get the filepath.
            /// </summary>
            /// <param name="">Void</param>
            /// <returns>String filepath</returns>
            std::string getFile(void) {
                return files_;
            }

        };

    }  // namespace extends

}  // namespace models

#endif // !_R2R_APP_MODELS_LOADER_H_