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
//      File name       : cursor_driver.cc
//
//      Author          : u7
//
//
//
//
//
//
/**************************************************************/

/*
 * =============================================================
 *  FILE DESCRIPTION
 * =============================================================
 * It's for verification.
**/



/* INCLUDES */
// PRIMARY HEADER
#include "cursor_driver.h"
// GENERAL USING HEADER
#include <DxLib.h>
// PROJECT USING HEADER
#include "src/protocol/evaluation.h"
#include "src/protocol/process_code_hard.h"
#include "src/protocol/message_box.h"
#include "src/app/input/inputkey.h"

#include "src/app/input/key_binding.h"
#include "src/database/tables/MST_NES_PALETTE.h"

#include "src/app/component/CX/C0_sample1/sample_component.h"




/* SOURCES */
namespace sequence {

    /* using namespace */
    using namespace DB;
    using namespace protocol;
    using namespace input;
    using namespace component;




    CursorDriver::CursorDriver() {
        container_ = new SampleComponent1();
    }


    CursorDriver::~CursorDriver() {
        if (nullptr != container_) {
            delete container_;
            container_ = nullptr;
        }
        MST_NES_PALETTE::tr_0x0F();
    }


    Evaluate CursorDriver::Service(Evaluate evals) {
        // Update the gamepad key information.
        if (!GController()->updateJoyBtnStateKey()) {
            setStaticProcessCode(0x001EA1ULL, STATIC_ERR_DOMINATOR);
            return Evaluate::PROC_FAILED;
        }

        // ■ BEGIN TEST CODE >>>
        container_->doComponentScene(this);
        if (nullptr == container_) {
            return Evaluate::PROC_QUIT;
        }
        // ■ END TEST CODE.


        return Evaluate::PROC_SUCCEED;
    }


    void CursorDriver::Exceptions(void) {
    }



    bool CursorDriver::changeComponents(implements::IComponents* object) {
        if (nullptr != container_) {
            delete container_;
            container_ = object;
        }
        return true;
    }

}  // namespace sequence