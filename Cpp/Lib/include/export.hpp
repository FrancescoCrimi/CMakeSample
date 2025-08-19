#ifndef MYLIBCPP_EXPORT_H
#define MYLIBCPP_EXPORT_H

// Su Windows utilizziamo __declspec(dllexport)/__declspec(dllimport)
#if defined(_WIN32) || defined(_WIN64)
    #ifdef MYLIBCPP_EXPORTS
        // Durante la compilazione della DLL
        #define MYLIBCPP_API __declspec(dllexport)
    #else
        // Quando la DLL viene utilizzata
        #define MYLIBCPP_API __declspec(dllimport)
    #endif
#else
    // Su altre piattaforme non sono necessarie direttive particolari
    #define MYLIBCPP_API
#endif

#endif // MYLIBCPP_EXPORT_H
