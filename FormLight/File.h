#pragma once
#ifndef __FILE_H
#define __FILE_H

#include <string>
#include <fstream>

#ifdef _WIN32
struct _WIN32_FIND_DATAA;
union _ULARGE_INTEGER;
struct _SYSTEMTIME;
#else
#include <sys/stat.h>
#endif

class File
{
public:
	static std::string TrimExtension(const std::string filename);
	static std::string GetExtension(const std::string filename);
	static std::string AddSuffix(const std::string filename, const std::string suffix);
	static std::string TrimDir(const std::string filename);
	static std::string GetParentDir(const std::string path);
	static bool Exists(const std::string filename);

#ifdef _WIN32
	struct FindHandle;

	static bool GetFiles(const std::string dir, FindHandle* hfind, uint32_t wantedattr, uint32_t unwantedattr, _WIN32_FIND_DATAA* fdata);

	static bool GetFiles(const std::string dir, FindHandle* hfind, _WIN32_FIND_DATAA* fdata);

	static bool GetDirectories(const std::string dir, FindHandle* hfind, _WIN32_FIND_DATAA* fdata);

	static bool RecursiveFileSearch(const std::string& dir, _WIN32_FIND_DATAA &fdata, std::string& file);

	static bool Find(std::string& file);

	static bool GetLastWriteTime(const std::string filename, _ULARGE_INTEGER* time);
	static bool GetLastWriteTime(const std::string filename, _SYSTEMTIME* time);
#else
	static bool GetLastWriteTime(const std::string filename, time_t* time);
	static bool GetLastWriteTime(const std::string filename, struct tm** time);
#endif
};

class DateTime
{
public:
#ifdef _WIN32
	static _ULARGE_INTEGER FromBinary(uint64_t time);
	static bool Equals(_ULARGE_INTEGER t0, _ULARGE_INTEGER t1);
#else
#endif
};

#endif