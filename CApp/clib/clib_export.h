#ifndef CLIB_EXPORT_H
#define CLIB_EXPORT_H

// Su Windows utilizziamo __declspec(dllexport)/__declspec(dllimport)
#ifdef _WIN32
    #ifdef CLIB_EXPORTS
        // Durante la compilazione della DLL
        #define CLIB_API __declspec(dllexport)
    #else
        // Quando la DLL viene utilizzata
        #define CLIB_API __declspec(dllimport)
    #endif
#else
    // Su altre piattaforme non sono necessarie direttive particolari
    #define CLIB_API
#endif

#endif // CLIB_EXPORT_H
