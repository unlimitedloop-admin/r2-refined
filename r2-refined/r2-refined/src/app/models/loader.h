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
//      Last update     : 2023/04/01
//
//      File version    : 2
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
#include <cstdint>
#include <vector>
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
            std::vector<std::string> files_;

        protected:
            explicit Loader() {
                files_ = { "" };
            }

            explicit Loader(const uint8_t num) {
                files_.resize(num);
            }

            ~Loader() {
                files_.clear();
                files_.shrink_to_fit();
            }

            /// <summary>
            /// Set the filepath.
            /// </summary>
            /// <param name="filepath">Filepath(fullpath required)</param>
            /// <param name="num">Vector array number</param>
            void setFile(const std::string filepath, const size_t num = 0) {
                if (num + 1 <= files_.size()) { files_[num] = filepath; }
            }

            /// <summary>
            /// Get the filepath.
            /// </summary>
            /// <param name="num">Vector array number</param>
            /// <returns>String filepath</returns>
            std::string getFile(const size_t num = 0) const {
                if (num + 1 <= files_.size()) { return files_[num]; }
                else { return ""; }
            }

        };

    }  // namespace extends

}  // namespace models

#endif // !_R2R_APP_MODELS_LOADER_H_