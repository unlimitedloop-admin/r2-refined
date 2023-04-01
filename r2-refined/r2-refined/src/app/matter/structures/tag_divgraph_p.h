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
//      File name       : tag_divgraph_p.h
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
 * This parameter is only used by the DxLib function 'DivGraph'.
**/



#ifndef _R2R_APP_MATTER_STRUCTURES_TAG_DIVGRAPH_P_H_
#define _R2R_APP_MATTER_STRUCTURES_TAG_DIVGRAPH_P_H_

/* SOURCES */
namespace matter {

    typedef struct tagDivGraphParam {
    public:
        size_t all_num;
        size_t x_num;
        size_t y_num;
        size_t x_size;
        size_t y_size;
    } DivGraphParam, * LPDivGraphParam;

}  // namespace matter

#endif // !_R2R_APP_MATTER_STRUCTURES_TAG_DIVGRAPH_P_H_