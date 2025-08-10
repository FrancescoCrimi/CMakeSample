#ifndef CLIB_EXPORT_H
#define CLIB_EXPORT_H

#if defined(_WIN32) || defined(__CYGWIN__)
  #ifdef MYLIBC_SHARED
    #ifdef MYLIBC_EXPORTS
      #define MYLIBC_API __declspec(dllexport)
    #else
      #define MYLIBC_API __declspec(dllimport)
    #endif
  #else
    #define MYLIBC_API
  #endif
#else
  #ifdef MYLIBC_SHARED
    #define MYLIBC_API __attribute__((visibility("default")))
  #else
    #define MYLIBC_API
  #endif
#endif

#endif // CLIB_EXPORT_H
