#pragma once

#ifdef handle_lib_SHARED_DEFINE
#   ifndef HANDLE_LIB_EXPORT
#       ifdef handle_lib_EXPORTS
#           if defined _WIN32 
#               define HANDLE_LIB_EXPORT __declspec(dllexport)
#           elif defined __GNUC__ || defined __clang__
#               define HANDLE_LIB_EXPORT __attribute__((visibility("default")))
#           endif
#       else
#           if defined _WIN32 
#               define HANDLE_LIB_EXPORT __declspec(dllimport)
#           elif defined __GNUC__ || defined __clang__
#               define HANDLE_LIB_EXPORT __attribute__((visibility("default")))
#           endif
#       endif
#   endif
#   ifndef HANDLE_LIB_NO_EXPORT
#       if defined _WIN32 
#           define HANDLE_LIB_NO_EXPORT
#       elif defined __GNUC__ || defined __clang__
#           define HANDLE_LIB_NO_EXPORT __attribute__((visibility("hidden")))
#       endif
#   endif
#else 
#   define HANDLE_LIB_EXPORT
#   define HANDLE_LIB_NO_EXPORT
#endif

#ifndef HANDLE_LIB_DEPRECATED
#   if defined _WIN32 
#       define HANDLE_LIB_DEPRECATED __declspec(deprecated)
#   elif defined __GNUC__ || defined __clang__
#       define HANDLE_LIB_DEPRECATED __attribute__ ((__deprecated__))
#   endif
#endif

#ifndef HANDLE_LIB_DEPRECATED_EXPORT
#  define HANDLE_LIB_DEPRECATED_EXPORT HANDLE_LIB_EXPORT HANDLE_LIB_DEPRECATED
#endif

#ifndef HANDLE_LIB_DEPRECATED_NO_EXPORT
#  define HANDLE_LIB_DEPRECATED_NO_EXPORT HANDLE_LIB_NO_EXPORT HANDLE_LIB_DEPRECATED
#endif

#define DEFINE_NO_DEPRECATED 0
#if DEFINE_NO_DEPRECATED
# define HANDLE_LIB_NO_DEPRECATED
#endif
