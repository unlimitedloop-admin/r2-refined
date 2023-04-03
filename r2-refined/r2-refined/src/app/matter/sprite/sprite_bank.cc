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
//      File name       : sprite_bank.cc
//
//      Author          : u7
//
//      Last update     : 2023/04/03
//
//      File version    : 3
//
//
/**************************************************************/

/*
 * =============================================================
 *  FILE DESCRIPTION
 * =============================================================
 * Implements that manages sprite bank class.
**/



/* INCLUDES */
// PRIMARY HEADER
#include "sprite_bank.h"
// C++ SYSTEM HEADER
#include <string>
// PROJECT USING HEADER
#include "src/app/matter/sprite/diecast.h"
#include "src/app/matter/sprite/clay_diecast.h"
#include "src/app/matter/structures/tag_divgraph_p.h"



/* SOURCES */
namespace matter {

    namespace sprite {

        SpriteBank::SpriteBank() {
            objects_ = {};
        }


        SpriteBank::SpriteBank(const SpriteBank& cc) {
            objects_ = cc.objects_;
        }


        SpriteBank::~SpriteBank() {
            auto begin = objects_.begin(), end = objects_.end();
            for (auto& itr = begin; itr != end; itr++) {
                delete itr->second;
                itr->second = nullptr;
            }
        }


        bool SpriteBank::Push(const std::wstring name, const std::wstring filepath, const LPDivGraphParam params) {
            extends::Diecast* factory = new ClayDiecast();
            objects_[name] = factory->Create(filepath);
            if (!objects_[name]->Unzip(params->all_num, params->x_num, params->y_num, params->x_size, params->y_size)) { return false; }
            delete factory;
            return true;
        }


        bool SpriteBank::Draw(const std::wstring name, const size_t tile_num, const __int16 x, const __int16 y, const bool transparent) const {
            if (auto itr = objects_.find(name); itr != end(objects_)) {
                return itr->second->Use(x, y, tile_num, transparent);
            }
        }

    }  // namespace sprite

}  // namespace matter