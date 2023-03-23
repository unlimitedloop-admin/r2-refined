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
//      File name       : signature_object.h
//
//      Author          : u7
//
//      Last update     : 2023/03/23
//
//      File version    : 2
//
//
/**************************************************************/

/*
 * =============================================================
 *  FILE DESCRIPTION
 * =============================================================
 * Singleton pattern matter class.
**/



#ifndef _R2R_APP_MODELS_SIGNATURE_OBJECT_H_
#define _R2R_APP_MODELS_SIGNATURE_OBJECT_H_

/* SOURCES */
namespace models {

    /// <summary>
    /// Singleton pattern exclusive class.
    /// </summary>
    /// <typeparam name="T">Specifies the class that you want to make impossible to imitate</typeparam>
    template <class T>
    class SignatureObject {
    private:
        SignatureObject(const SignatureObject& args) = delete;
        SignatureObject& operator=(const SignatureObject& args) = delete;
        SignatureObject(SignatureObject&&) = delete;
        SignatureObject& operator=(SignatureObject&&) = delete;

    protected:
        SignatureObject() {};
        virtual ~SignatureObject() {};

    public:
        // NOTE : Compile-time instance retrieval available only in singleton pattern.
        static T* getInstance(void) {
            static T obj;
            return &obj;
        }
    };

    template <class T>
    using Singleton = SignatureObject<T>;

}  // namespace models

#endif // !_R2R_APP_MODELS_SIGNATURE_OBJECT_H_