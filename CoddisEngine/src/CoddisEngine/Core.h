#pragma once
#ifdef CODDIS_PLATFORM_WINDOWS
#ifdef CODDIS_BUILD_DLL
#define CODDIS_API __declspec(dllexport)
#else
#define CODDIS_API __declspec(dllimport)
#endif
#else
#error Coddio Cazzo fai senza windows!
#endif