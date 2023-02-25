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
//      File name       : app_engine.h
//
//      Author          : u7
//
//      Last update     : 2023/02/25
//
//      File version    : 3 
//
//
/**************************************************************/

/*
 * =============================================================
 *  FILE DESCRIPTION
 * =============================================================
 * app engine.header
**/



#ifndef _R2R_FORMS_TERMINAL_APP_ENGINE_H_
#define _R2R_FORMS_TERMINAL_APP_ENGINE_H_

/* INCLUDES */
// PROJECT USING HEADER
#include "src/protocol/evaluation.h"
#include "src/app/models/cursor.h"



/* SOURCES */
namespace terminal {

    /* using namespace */
    using namespace protocol;



    /// <summary>
    /// Application engine gateway class.
    /// </summary>
    class AppEngine final {
    private:
        /// <summary>
        /// The signal of executing the main programs.
        /// </summary>
        Evaluate period_ = Evaluate::PROC_FAILED;

        /// <summary>
        /// Substance of the main program.
        /// </summary>
        models::implements::ICursor* sequence_ = nullptr;

        /// <summary>
        /// This is the frontgate entrance of the main program sequencer.
        /// </summary>
        /// <param name="ticket">Run mode enum value</param>
        /// <returns>Return true if the process is successful, false otherwise</returns>
        bool Receptions(RunMode ticket);


    public:
        AppEngine() {}
        AppEngine(const AppEngine&) = delete;
        ~AppEngine();

        /// <summary>
        /// Initialize the substance program.
        /// </summary>
        /// <param name="indicator">Run mode</param>
        /// <returns>Return true if the process is successful, false otherwise</returns>
        bool Initialize(RunMode indicator) const;

        /// <summary>
        /// Execute the event loop processing of the substance program.
        /// </summary>
        /// <param name="indicator">Run mode</param>
        void eventLoop(RunMode indicator);

        /// <summary>
        /// Finalize the substance program.
        /// </summary>
        /// <param name="">Void</param>
        void Finalize(void) const;

    };

}  // namespace terminal

#endif // !_R2R_FORMS_TERMINAL_APP_ENGINE_H_