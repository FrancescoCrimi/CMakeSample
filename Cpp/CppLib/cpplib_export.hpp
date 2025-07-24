#ifndef CPPLIB_EXPORT_H
#define CPPLIB_EXPORT_H

// Su Windows utilizziamo __declspec(dllexport)/__declspec(dllimport)
#if defined(_WIN32) || defined(_WIN64)
    #ifdef CPPLIB_EXPORTS
        // Durante la compilazione della DLL
        #define CPPLIB_API __declspec(dllexport)
    #else
        // Quando la DLL viene utilizzata
        #define CPPLIB_API __declspec(dllimport)
    #endif
#else
    // Su altre piattaforme non sono necessarie direttive particolari
    #define CPPLIB_API
#endif

#endif // CPPLIB_EXPORT_H
