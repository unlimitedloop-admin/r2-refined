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
#include "src/app/matter/sprite/sprite_property.h"

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
        (void)writeStatusLog(L"サンプルコンポーネント1を開始します。");
        DivGraphParam params = { 16, 4, 4, 32, 32 };
        sprite_.Push(L"Metall", L"assets/3_sprite/sample_graphic.png", &params);
        sprite_.status_[L"Metall"].type = sprite::Assist::Automatic;
        sprite_.status_[L"Metall"].chip = 0;
        sprite_.status_[L"Metall"].axis.SetX(100i16);
        sprite_.status_[L"Metall"].axis.SetY(100i16);
        params = { 200, 20, 10, 32, 32 };
        sprite_.Push(L"Rockman", L"assets/3_sprite/rockman_allsprite_01.png", &params);
        sprite_.status_[L"Rockman"].type = sprite::Assist::Inferior;
        sprite_.status_[L"Rockman"].chip = 0;
        sprite_.status_[L"Rockman"].axis.SetX(97i16);
        sprite_.status_[L"Rockman"].axis.SetY(72i16);
        MST_NES_PALETTE::tr_0x00();
    }


    SampleComponent1::~SampleComponent1() {}


    bool SampleComponent1::doComponentScene(implements::IRadar* object) {
        size_t* a = &sprite_.status_[L"Metall"].chip;
        if (1 == GetKey(JPBTN::RIGHT)) {
            if (3 > *a) { ++(*a); }
        }
        else if (1 == GetKey(JPBTN::LEFT)) {
            if (0 < *a) { --(*a); }
        }
        sprite_.Draw(L"Metall");
        sprite_.Draw(L"Rockman");


        if (1 == GetKey(JPBTN::START)) {
            if (!object->changeComponents(new SampleComponent2())) {
                return false;
            }
        }
        return true;
    }


    bool SampleComponent1::anomalyDetector(void) { return false; }


    SampleComponent2::SampleComponent2() : abnormality_(false) {
        (void)writeStatusLog(L"サンプルコンポーネント2を開始します。");
        background_.loadStructure(L"assets/1_Mapdata/demostage_mapdata.bin", 2);
        DivGraphParam params = { 128, 16, 8, 16, 16 };
        background_.loadTexture(L"assets/2_BG/demostage_BG.png", &params);
        MST_NES_PALETTE::tr_0x01();
    }


    SampleComponent2::~SampleComponent2() {}


    bool SampleComponent2::doComponentScene(implements::IRadar* object) {
        if (!background_.mappingOn()) {
            return false;
        }   // 背景タイルを指定、引数は第一から順にマップ番号、VRAM上の左上に位置するX座標、Y座標を指定
        
        
        if (1 == GetKey(JPBTN::START)) {
            if (!object->changeComponents(new SampleComponent3())) {
                return false;
            }
        }
        return true;
    }


    bool SampleComponent2::anomalyDetector(void) { return false; }


    SampleComponent3::SampleComponent3() : abnormality_(false), track_(0i16) {
        (void)writeStatusLog(L"サンプルコンポーネント3を開始します。");
        TrackChannelParam params = {
            L"assets/5_music/sampleBGM/Pulse1.wav"
            , L"assets/5_music/sampleBGM/Pulse2.wav"
            , L"assets/5_music/sampleBGM/Triangle.wav"
            , L"assets/5_music/sampleBGM/Noise.wav"
            , L"assets/5_music/sampleBGM/DeltaPCM.wav"
        };
        sound_.Push(L"01", &params);
        params = {
            L"assets/5_music/sampleBGM2(+DPCM)/Pulse1.wav"
            , L"assets/5_music/sampleBGM2(+DPCM)/Pulse2.wav"
            , L"assets/5_music/sampleBGM2(+DPCM)/Triangle.wav"
            , L"assets/5_music/sampleBGM2(+DPCM)/Noise.wav"
            , L"assets/5_music/sampleBGM2(+DPCM)/DeltaPCM.wav"
        };
        sound_.Push(L"02", &params);
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


        if (1 == GetKey(JPBTN::RIGHT)) { track_++; }
        else if (1 == GetKey(JPBTN::LEFT)) { track_--; }
        if (track_ % 2) {
            music_ = L"01";
        }
        else {
            music_ = L"02";
        }

        if (1 == GetKey(JPBTN::START)) {
            if (sound_.checkNowPlaying(music_)) {
                if (!sound_.allChannelStop(music_)) { return false; }
                music_ = L"Off";
            }
            else {
                if (!sound_.allTrackStop()) { return false; }
                if (!sound_.allChannelGo(music_)) { return false; }
            }
        }

        if (1 == GetKey(JPBTN::A)) {
            if (0 == sound_.getVolume(music_, L"APU_CH_SQUARE_1")) {
                if (!sound_.volumeControl(music_, L"APU_CH_SQUARE_1", 100)) { return false; }
                vol_[0] = L"On";
            }
            else {
                if (!sound_.volumeControl(music_, L"APU_CH_SQUARE_1", 0)) { return false; }
                vol_[0] = L"Off";
            }
        }
        if (1 == GetKey(JPBTN::B)) {
            if (0 == sound_.getVolume(music_, L"APU_CH_SQUARE_2")) {
                if (!sound_.volumeControl(music_, L"APU_CH_SQUARE_2", 100)) { return false; }
                vol_[1] = L"On";
            }
            else {
                if (!sound_.volumeControl(music_, L"APU_CH_SQUARE_2", 0)) { return false; }
                vol_[1] = L"Off";
            }
        }
        if (1 == GetKey(JPBTN::X)) {
            if (0 == sound_.getVolume(music_, L"APU_CH_TRIANGLE")) {
                if (!sound_.volumeControl(music_, L"APU_CH_TRIANGLE", 100)) { return false; }
                vol_[2] = L"On";
            }
            else {
                if (!sound_.volumeControl(music_, L"APU_CH_TRIANGLE", 0)) { return false; }
                vol_[2] = L"Off";
            }
        }
        if (1 == GetKey(JPBTN::Y)) {
            if (0 == sound_.getVolume(music_, L"APU_CH_NOISE_BG")) {
                if (!sound_.volumeControl(music_, L"APU_CH_NOISE_BG", 100)) { return false; }
                vol_[3] = L"On";
            }
            else {
                if (!sound_.volumeControl(music_, L"APU_CH_NOISE_BG", 0)) { return false; }
                vol_[3] = L"Off";
            }
        }
        if (1 == GetKey(JPBTN::L)) {
            if (0 == sound_.getVolume(music_, L"APU_CH_DELTAPCM")) {
                if (!sound_.volumeControl(music_, L"APU_CH_DELTAPCM", 100)) { return false; }
                vol_[4] = L"On";
            }
            else {
                if (!sound_.volumeControl(music_, L"APU_CH_DELTAPCM", 0)) { return false; }
                vol_[4] = L"Off";
            }
        }


        DxLib::DrawFormatString(2, 2, DxLib::GetColor(0xFF, 0xFF, 0xFF), L"BGM : ◀ %s ▶", (L"No." + music_).c_str());
        DxLib::DrawFormatString(2, 22, DxLib::GetColor(0x90, 0xFF, 0xFF), L"PULSE 1  ch : %s", vol_[0].c_str());
        DxLib::DrawFormatString(2, 42, DxLib::GetColor(0x90, 0xFF, 0xFF), L"PULSE 2  ch : %s", vol_[1].c_str());
        DxLib::DrawFormatString(2, 62, DxLib::GetColor(0x90, 0xFF, 0xFF), L"TRIANGLE ch : %s", vol_[2].c_str());
        DxLib::DrawFormatString(2, 82, DxLib::GetColor(0x90, 0xFF, 0xFF), L"NOISE    ch : %s", vol_[3].c_str());
        DxLib::DrawFormatString(2, 102, DxLib::GetColor(0x90, 0xFF, 0xFF), L"DELTAPCM ch : %s", vol_[4].c_str());

        return true;
    }


    bool SampleComponent3::anomalyDetector(void) { return false; }


}  // namespace component