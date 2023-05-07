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
//      File name       : setup_instance.cc
//
//      Author          : u7
//
//      Last update     : 2023/05/07
//
//      File version    : 2
//
//
/**************************************************************/

/*
 * =============================================================
 *  FILE DESCRIPTION
 * =============================================================
 * Implement a proof-of-concept instance read for an action scene program.
**/



/* INCLUDES */
// PRIMARY HEADER
#include "setup_instance.h"
// PROJECT USING HEADER
#include "src/traceable/output_logs.h"
#include "src/app/models/component_state_context.h"
#include "src/app/route/region/C1_sample2_component.h"
#include "src/app/matter/sprite/sprite_property.h"
#include "src/app/matter/BG/BG_property.h"
#include "src/app/matter/blending/dealer.h"
#include "src/app/matter/structures/tag_divgraph_p.h"




/* SOURCES */
namespace component {
    
    namespace C1_sample2 {

        namespace state {

            /* using namespace */
            using namespace traceable;



            SetupInstanceState::SetupInstanceState(matter::blending::Dealer* mat_impl) {
                mat_ = mat_impl;
                (void)writeStatusLog(L"C1_sample2::SetupInstanceStateを開始します。");
            }


            SetupInstanceState::~SetupInstanceState() {
                (void)writeStatusLog(L"C1_sample2::SetupInstanceStateを終了します。");
            }


            bool SetupInstanceState::doAction(implements::IComponentStateContext* context) {
                using namespace matter;
                
                // TODO : Converted to BG map table.
                mat_->BG.loadStructure(L"assets/1_Mapdata/demostage_mapdata.bin", 2);
                DivGraphParam params = { 128, 16, 8, 16, 16 };
                mat_->BG.loadTexture(L"assets/2_BG/demostage_BG.png", &params);
                mat_->BG.setGrids(0, static_cast<BG::diorama>(1));
                mat_->BG.setVertexX(0ui64, 0i16);
                mat_->BG.setVertexY(0ui64, 0i16);
                mat_->BG.setGrids(1, static_cast<BG::diorama>(2));
                mat_->BG.setVertexX(1ui64, 256i16);
                mat_->BG.setVertexY(1ui64, 0i16);


                // TODO : Converted to sprite bank table.
                params = { 200, 20, 10, 32, 32 };
                mat_->SPRITE.Push(L"Rockman", L"assets/3_sprite/rockman_allsprite_01.png", &params);
                mat_->SPRITE.status_[L"Rockman"].type = sprite::Assist::Superior;
                mat_->SPRITE.status_[L"Rockman"].chip = 0;
                mat_->SPRITE.status_[L"Rockman"].axis.SetX(97i16);
                mat_->SPRITE.status_[L"Rockman"].axis.SetY(72i16);

                context->setComponentState(route::region::C1Sample2Component().getStates(this, mat_));
                return true;
            }

        }  // namespace state

    }  // namespace C1_sample2

}  // namespace component