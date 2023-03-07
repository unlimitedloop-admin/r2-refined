/**************************************************************/
//
//
//      r2-refined project
//
//      File name       : sample_component.h
//
//
/**************************************************************/

/*
 * =============================================================
 *  FILE DESCRIPTION
 * =============================================================
 * sample file.
**/


#ifndef _R2R_APP_COMPONENT_SAMPLE_COMPONENT_H_
#define _R2R_APP_COMPONENT_SAMPLE_COMPONENT_H_


#include "src/app/models/components.h"
#include "src/app/models/radar.h"




namespace component {

    using namespace models;


    class SampleComponent1 : public implements::IComponents {

    private:
        bool abnormality_;

    public:
        SampleComponent1();
        ~SampleComponent1();

        bool doComponentScene(implements::IRadar* object) override;

    };


    class SampleComponent2 : public implements::IComponents {

    private:
        bool abnormality_;

    public:
        SampleComponent2();
        ~SampleComponent2();

        bool doComponentScene(implements::IRadar* object) override;

    };


    class SampleComponent3 : public implements::IComponents {

    private:
        bool abnormality_;

    public:
        SampleComponent3();
        ~SampleComponent3();

        bool doComponentScene(implements::IRadar* object) override;

    };

}  // namespace component

#endif // !_R2R_APP_COMPONENT_SAMPLE_COMPONENT_H_