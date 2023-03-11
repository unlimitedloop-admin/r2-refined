/**************************************************************/
//
//
//      r2-refined project
//
//      File name       : sample_component.cc
//
//
/**************************************************************/

/*
 * =============================================================
 *  FILE DESCRIPTION
 * =============================================================
 * sample file.
**/


#include "sample_component.h"
#include "src/traceable/output_logs.h"
#include "src/database/tables/MST_NES_PALETTE.h"
#include "src/app/input/inputkey.h"

#include "src/app/matter/sprite/sprite_loader.h"




namespace component {

    using namespace DB;
    using namespace traceable;
    using namespace input;
    using namespace matter;


    SampleComponent1::SampleComponent1() : abnormality_(false), sprite_("assets/3_sprite/sample_graphic.png") {
        (void)writeStatusLog("サンプルコンポーネント1を開始します。");
        MST_NES_PALETTE::tr_0x00();
        sprite_.Unzip(16, 4, 4, 32, 32);
    }


    SampleComponent1::~SampleComponent1() {}


    bool SampleComponent1::doComponentScene(implements::IRadar* object) {
        if (1 == GetKey(JPBTN::START)) {
            if (!object->changeComponents(new SampleComponent2())) {
                return false;
            }
        }

        // ★ sample code has begin ..:｡*ﾟ:.｡*ﾟ..:｡*ﾟ:.｡*ﾟ..:｡*ﾟ..:｡*ﾟ:.｡*ﾟ..:｡*ﾟ..:｡*ﾟ:.｡*ﾟ..:｡*ﾟ:.｡*ﾟ..:｡*ﾟ..:｡*ﾟ:.｡*ﾟ..:｡*ﾟ

        if (1 == GetKey(JPBTN::RIGHT)) {
            if (3 > t_num_) { ++t_num_; }
        }
        else if (1 == GetKey(JPBTN::LEFT)) {
            if (0 < t_num_) { --t_num_; }
        }
        sprite_.Use(100, 100, t_num_, true);

        // ★ sample code up to this ..:｡*ﾟ:.｡*ﾟ..:｡*ﾟ:.｡*ﾟ..:｡*ﾟ..:｡*ﾟ:.｡*ﾟ..:｡*ﾟ..:｡*ﾟ:.｡*ﾟ..:｡*ﾟ:.｡*ﾟ..:｡*ﾟ..:｡*ﾟ:.｡*ﾟ..:｡*ﾟ

        return true;
    }


    SampleComponent2::SampleComponent2() : abnormality_(false) {
        (void)writeStatusLog("サンプルコンポーネント2を開始します。");
        MST_NES_PALETTE::tr_0x01();
    }


    SampleComponent2::~SampleComponent2() {}


    bool SampleComponent2::doComponentScene(implements::IRadar* object) {
        if (1 == GetKey(JPBTN::START)) {
            if (!object->changeComponents(new SampleComponent3())) {
                return false;
            }
        }
        return true;
    }


    SampleComponent3::SampleComponent3() : abnormality_(false) {
        (void)writeStatusLog("サンプルコンポーネント3を開始します。");
        MST_NES_PALETTE::tr_0x02();
    }


    SampleComponent3::~SampleComponent3() {}


    bool SampleComponent3::doComponentScene(implements::IRadar* object) {
        if (1 == GetKey(JPBTN::START)) {
            if (!object->changeComponents(nullptr)) {
                return false;
            }
        }
        return true;
    }

}  // namespace component