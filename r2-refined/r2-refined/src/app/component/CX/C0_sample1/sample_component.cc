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

#include "src/app/matter/structures/tag_track_channel_p.h"
#include "src/database/tables/MST_APU_CHANNELS.h"

#include <DxLib.h>





namespace component {

    using namespace DB;
    using namespace traceable;
    using namespace input;
    using namespace matter;
    using namespace models;

    constexpr bool MAIN_PROGRAM_EXIT = true;


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
        if (1 == GetKey(JPBTN::RIGHT)) {
            if (3 > t_num_) { ++t_num_; }
        }
        else if (1 == GetKey(JPBTN::LEFT)) {
            if (0 < t_num_) { --t_num_; }
        }
        sprite_.Draw("Metall", t_num_, 100, 100, true);
        sprite_.Draw("Rockman", t_num_, 97, 72, true);


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
        if (!background_.mappingOn(2, 0, 0)) {
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
        TrackChannelParam params = {
            "assets/5_music/sampleBGM/Pulse1.wav"
            , "assets/5_music/sampleBGM/Pulse2.wav"
            , "assets/5_music/sampleBGM/Triangle.wav"
            , "assets/5_music/sampleBGM/Noise.wav"
            , "assets/5_music/sampleBGM/DeltaPCM.wav"
        };
        sound_.Push("BGM_1", &params);
        MST_NES_PALETTE::tr_0x02();
    }


    SampleComponent3::~SampleComponent3() {}


    bool SampleComponent3::doComponentScene(implements::IRadar* object) {
        if (1 == GetKey(JPBTN::BACK)) {
            if (!object->changeComponents(nullptr)) {
                return false;
            }
            return MAIN_PROGRAM_EXIT;
        }

        if (1 == GetKey(JPBTN::START)) {
            if (sound_.checkNowPlaying("BGM_1")) {
                if (!sound_.allChannelStop("BGM_1")) { return false; }
                music_ = "Off";
            }
            else {
                if (!sound_.allChannelGo("BGM_1")) { return false; }
                music_ = "On";
            }
        }

        if (1 == GetKey(JPBTN::A)) {
            if (0 == sound_.getVolume("BGM_1", "APU_CH_SQUARE_1")) {
                if (!sound_.volumeControl("BGM_1", "APU_CH_SQUARE_1", 100)) { return false; }
                vol_[0] = "On";
            }
            else {
                if (!sound_.volumeControl("BGM_1", "APU_CH_SQUARE_1", 0)) { return false; }
                vol_[0] = "Off";
            }
        }
        if (1 == GetKey(JPBTN::B)) {
            if (0 == sound_.getVolume("BGM_1", "APU_CH_SQUARE_2")) {
                if (!sound_.volumeControl("BGM_1", "APU_CH_SQUARE_2", 100)) { return false; }
                vol_[1] = "On";
            }
            else {
                if (!sound_.volumeControl("BGM_1", "APU_CH_SQUARE_2", 0)) { return false; }
                vol_[1] = "Off";
            }
        }
        if (1 == GetKey(JPBTN::X)) {
            if (0 == sound_.getVolume("BGM_1", "APU_CH_TRIANGLE")) {
                if (!sound_.volumeControl("BGM_1", "APU_CH_TRIANGLE", 100)) { return false; }
                vol_[2] = "On";
            }
            else {
                if (!sound_.volumeControl("BGM_1", "APU_CH_TRIANGLE", 0)) { return false; }
                vol_[2] = "Off";
            }
        }
        if (1 == GetKey(JPBTN::Y)) {
            if (0 == sound_.getVolume("BGM_1", "APU_CH_NOISE_BG")) {
                if (!sound_.volumeControl("BGM_1", "APU_CH_NOISE_BG", 100)) { return false; }
                vol_[3] = "On";
            }
            else {
                if (!sound_.volumeControl("BGM_1", "APU_CH_NOISE_BG", 0)) { return false; }
                vol_[3] = "Off";
            }
        }


        DxLib::DrawFormatString(2, 2, DxLib::GetColor(0xFF, 0xFF, 0xFF), "BGM : %s", music_.c_str());
        DxLib::DrawFormatString(2, 22, DxLib::GetColor(0x90, 0xFF, 0xFF), "PULSE 1  ch : %s", vol_[0].c_str());
        DxLib::DrawFormatString(2, 42, DxLib::GetColor(0x90, 0xFF, 0xFF), "PULSE 2  ch : %s", vol_[1].c_str());
        DxLib::DrawFormatString(2, 62, DxLib::GetColor(0x90, 0xFF, 0xFF), "TRIANGLE ch : %s", vol_[2].c_str());
        DxLib::DrawFormatString(2, 82, DxLib::GetColor(0x90, 0xFF, 0xFF), "NOISE    ch : %s", vol_[3].c_str());

        return true;
    }

}  // namespace component