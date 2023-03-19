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

#include "src/app/matter/sprite/sprite_bank.h"
#include "src/app/matter/structures/tag_divgraph_p.h"


namespace component {

    using namespace DB;
    using namespace traceable;
    using namespace input;
    using namespace matter;
    using namespace models;


    SampleComponent1::SampleComponent1() : abnormality_(false) {
        (void)writeStatusLog("サンプルコンポーネント1を開始します。");
        DivGraphParam params = { 16, 4, 4, 32, 32 };
        sprite_.Push("Metall", "assets/3_sprite/sample_graphic.png", &params);
        params = { 200, 20, 10, 32, 32 };
        sprite_.Push("Rockman", "assets/3_sprite/rockman_allsprite_01.png", &params);
        MST_NES_PALETTE::tr_0x00();
    }


    SampleComponent1::~SampleComponent1() {}


    bool SampleComponent1::doComponentScene(implements::IRadar* object) {
        // ★ sample code has begin ..:｡*ﾟ:.｡*ﾟ..:｡*ﾟ:.｡*ﾟ..:｡*ﾟ..:｡*ﾟ:.｡*ﾟ..:｡*ﾟ..:｡*ﾟ:.｡*ﾟ..:｡*ﾟ:.｡*ﾟ..:｡*ﾟ..:｡*ﾟ:.｡*ﾟ..:｡*ﾟ

        if (1 == GetKey(JPBTN::RIGHT)) {
            if (3 > t_num_) { ++t_num_; }
        }
        else if (1 == GetKey(JPBTN::LEFT)) {
            if (0 < t_num_) { --t_num_; }
        }
        sprite_.Draw("Metall", t_num_, 100, 100, true);
        sprite_.Draw("Rockman", t_num_, 97, 72, true);

        // ★ sample code up to this ..:｡*ﾟ:.｡*ﾟ..:｡*ﾟ:.｡*ﾟ..:｡*ﾟ..:｡*ﾟ:.｡*ﾟ..:｡*ﾟ..:｡*ﾟ:.｡*ﾟ..:｡*ﾟ:.｡*ﾟ..:｡*ﾟ..:｡*ﾟ:.｡*ﾟ..:｡*ﾟ


        if (1 == GetKey(JPBTN::START)) {
            if (!object->changeComponents(new SampleComponent2())) {
                return false;
            }
        }
        return true;
    }


    SampleComponent2::SampleComponent2() : abnormality_(false) {
        (void)writeStatusLog("サンプルコンポーネント2を開始します。");
        background_.loadStructure("assets/1_Mapdata/demostage_mapdata.bin", 2);
        DivGraphParam params = { 128, 16, 8, 16, 16 };
        background_.loadTexture("assets/2_BG/demostage_BG.png", &params);
        MST_NES_PALETTE::tr_0x01();
    }


    SampleComponent2::~SampleComponent2() {}


    bool SampleComponent2::doComponentScene(implements::IRadar* object) {
        
        if (!background_.mappingOn(1, 0, 0)) {
            return false;
        }   // 背景タイルを指定、引数は第一から順にマップ番号、VRAM上の左上に位置するX座標、Y座標を指定
        
        
        
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