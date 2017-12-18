#include "File.h"
#include <cstring>


#ifdef UNICODE
const wchar_t* GetLastSlash(const wchar_t* str)
{
	const wchar_t* sp = wcsrchr(str, '/');
	const wchar_t* bsp = wcsrchr(str, '\\');
	return sp > bsp ? sp : bsp;
}
#else
const char* GetLastSlash(const char* str)
{
	const char* sp = strrchr(str, '/');
	const char* bsp = strrchr(str, '\\');
	return sp > bsp ? sp : bsp;
}
#endif

void* _realloc(void* memory, size_t memorysize, size_t newsize)
{
	char* newmemory = new char[newsize];
	if (memorysize < newsize)
		newsize = memorysize; // newsize = min(newsize, memorysize)
	if (memory && newsize)
		memcpy(newmemory, memory, newsize);
	delete[](char*)memory;
	return (void*)newmemory;
}

//-----------------------------------------------------------------------------
// Name: TrimExtension
// Desc: Trim filepath by ".*"
//-----------------------------------------------------------------------------
std::string File::TrimExtension(const std::string filename)
#ifdef UNICODE
{
	const wchar_t* ptpos = wcsrchr(filename.c_str(), '.');
	if (!ptpos)
		return std::string("");

	int len = ptpos - filename.c_str();
	wchar_t* chars = new wchar_t[len + 1];
	memcpy(chars, filename.c_str(), (len + 1) * sizeof(wchar_t));
	chars[len] = '\0';
	return std::string(chars);
}
#else
{
	const char* ptpos = strrchr(filename.c_str(), '.');
	if (!ptpos)
		return std::string("");

	int len = ptpos - filename.c_str();
	char* chars = new char[len + 1];
	memcpy(chars, filename.c_str(), (len + 1) * sizeof(char));
	chars[len] = '\0';
	return std::string(chars);
}
#endif

//-----------------------------------------------------------------------------
// Name: GetExtension
// Desc: Get filepath at the last '.'
//-----------------------------------------------------------------------------
std::string File::GetExtension(const std::string filename)
#ifdef UNICODE
{
	const wchar_t* ptpos = wcsrchr(filename.c_str(), '.');
	if (!ptpos)
		return std::string("");
	else
		return std::string(ptpos + 1);
}
#else
{
	const char* ptpos = strrchr(filename.c_str(), '.');
	if (!ptpos)
		return std::string("");
	else
		return std::string(ptpos + 1);
}
#endif

//-----------------------------------------------------------------------------
// Name: AddSuffix
// Desc: Add the given string before the last '.'
//-----------------------------------------------------------------------------
std::string File::AddSuffix(const std::string filename, const std::string suffix)
{
	return TrimExtension(filename) + suffix + "." + GetExtension(filename);
}

//-----------------------------------------------------------------------------
// Name: TrimDir
// Desc: Trim filepath by directory ("*\\")
//-----------------------------------------------------------------------------
std::string File::TrimDir(const std::string filename)
#ifdef UNICODE
{
	// Run _tcsrchr() ignoring last character (for directories ending with '\\')
	std::string shortened_filename = filename;
	shortened_filename[shortened_filename.length() - 1] = '\0';
	const wchar_t* slpos = GetLastSlash(shortened_filename.c_str());

	if (!slpos)
		return std::string();
	else
		return std::string(slpos + 1);
}
#else
{
	// Run _tcsrchr() ignoring last character (for directories ending with '\\')
	std::string shortened_filename = filename;
	shortened_filename[shortened_filename.length() - 1] = '\0';
	const char* slpos = GetLastSlash(shortened_filename.c_str());

	if (!slpos)
		return std::string();
	else
		return std::string(slpos + 1);
}
#endif

//-----------------------------------------------------------------------------
// Name: GetParentDir
// Desc: Get parent directory and return if there is any
//-----------------------------------------------------------------------------
std::string File::GetParentDir(const std::string path)
#ifdef UNICODE
{
	// Run _tcsrchr() ignoring last character (for directories ending with '\\')
	std::string shortened_path = path;
	shortened_path[shortened_path.length() - 1] = '\0';
	const wchar_t* slpos = GetLastSlash(shortened_path.c_str());

	if (!slpos)
		return std::string();

	slpos++; // Keep trailing slash

	int len = slpos - path.c_str();
	wchar_t* chars = new wchar_t[len + 1];
	memcpy(chars, chars, len * sizeof(wchar_t));
	chars[len] = '\0';
	return std::string(chars);
}
#else
{
	// Run _tcsrchr() ignoring last character (for directories ending with '\\')
	std::string shortened_path = path;
	shortened_path[shortened_path.length() - 1] = '\0';
	const char* slpos = GetLastSlash(shortened_path.c_str());

	if (!slpos)
		return std::string();

	slpos++; // Keep trailing slash

	int len = slpos - path.c_str();
	char* chars = new char[len + 1];
	memcpy(chars, chars, len * sizeof(char));
	chars[len] = '\0';
	return std::string(chars);
}
#endif

//-----------------------------------------------------------------------------
// Name: Exists
// Desc: Check if the filepath points to a file that exists and is readable
//-----------------------------------------------------------------------------
bool File::Exists(const std::string filename)
{
	if (filename.empty())
		return false;

	std::ifstream fs(filename.c_str());
	bool good = fs.good();
	fs.close();

	return good;
}

#ifdef _WIN32
#include <Windows.h>

struct File::FindHandle
{
	friend class File;
private:
	HANDLE h;
public:
	FindHandle() { h = NULL; }
	~FindHandle() { Release(); }
	void Release() { if (h) { FindClose(h); h = NULL; } }
};

//-----------------------------------------------------------------------------
// Name: GetFiles
// Desc: Get files and directories filtered by wanted and unwanted attributes
//-----------------------------------------------------------------------------
bool File::GetFiles(const std::string dir, FindHandle* hfind, uint32_t wantedattr, uint32_t unwantedattr, WIN32_FIND_DATA* fdata)
{
	if (wantedattr == 0x0)
		wantedattr = 0xFFFFFFFF;

	if (hfind->h == NULL)
	{
		// Compose query string
		LPTSTR querystr;
		if (!dir.c_str()) // Relative path; directory is empty
		{
			querystr = new TCHAR[2];
			querystr[0] = '*';
			querystr[1] = '\0';
		}
		else if (dir[dir.length() - 1] == '\\')
		{
			querystr = new TCHAR[dir.length() + 2];
			memcpy(querystr, dir.c_str(), dir.length() * sizeof(TCHAR));
			querystr[dir.length()] = '*';
			querystr[dir.length() + 1] = '\0';
		}
		else
		{
			querystr = new TCHAR[dir.length() + 3];
			memcpy(querystr, dir.c_str(), dir.length() * sizeof(TCHAR));
			querystr[dir.length()] = '\\';
			querystr[dir.length() + 1] = '*';
			querystr[dir.length() + 2] = '\0';
		}

		// Find first file
		hfind->h = FindFirstFile(querystr[0] == '\\' ? querystr + 1 : querystr, fdata);
		delete[] querystr;
		if (hfind->h == INVALID_HANDLE_VALUE)
		{
			hfind->h = NULL;
			return false;
		}

		if ((fdata->dwFileAttributes & wantedattr) && !(fdata->dwFileAttributes & unwantedattr) &&
			strcmp(fdata->cFileName, "..") != 0 && strcmp(fdata->cFileName, ".") != 0)
			return true;
	}

	while (FindNextFile(hfind->h, fdata))
		if ((fdata->dwFileAttributes & wantedattr) && !(fdata->dwFileAttributes & unwantedattr) &&
			strcmp(fdata->cFileName, "..") != 0 && strcmp(fdata->cFileName, ".") != 0)
			return true;

	// Release finished find handle
	if (hfind->h == INVALID_HANDLE_VALUE)
		hfind->h = NULL;
	else
		hfind->Release();

	return false;
}

//-----------------------------------------------------------------------------
// Name: GetFiles
// Desc: Get files
//-----------------------------------------------------------------------------
bool File::GetFiles(const std::string dir, FindHandle* hfind, WIN32_FIND_DATA* fdata)
{
	return GetFiles(dir, hfind, NULL, FILE_ATTRIBUTE_DIRECTORY, fdata);
}

//-----------------------------------------------------------------------------
// Name: GetDirectories
// Desc: Get directories
//-----------------------------------------------------------------------------
bool File::GetDirectories(const std::string dir, FindHandle* hfind, WIN32_FIND_DATA* fdata)
{
	return GetFiles(dir, hfind, FILE_ATTRIBUTE_DIRECTORY, NULL, fdata);
}

bool File::RecursiveFileSearch(const std::string& dir, WIN32_FIND_DATA &fdata, std::string& file)
{
	File::FindHandle hdirfind;
	while (File::GetDirectories(dir, &hdirfind, &fdata))
	{
		std::string newdir = dir + fdata.cFileName + '\\';

		File::FindHandle hfilefind;
		while (File::GetFiles(newdir, &hfilefind, &fdata))
			if (strcmp(fdata.cFileName, file.c_str()) == 0)
			{
				file = newdir + file;
				return true;
			}

		if (RecursiveFileSearch(newdir, fdata, file))
			return true;
	}

	return false;
}

//-----------------------------------------------------------------------------
// Name: Find
// Desc: Find file inside it's subdirectories
//-----------------------------------------------------------------------------
bool File::Find(std::string& file)
{
	std::string dir;
	if ((dir = GetParentDir(file)).empty())
		dir = std::string(); // Relative path; directory is empty
	dir = TrimDir(dir);

	// Search in original directory
	WIN32_FIND_DATA fdata;
	File::FindHandle hfilefind;
	while (GetFiles(dir, &hfilefind, &fdata))
		if (strcmp(fdata.cFileName, file.c_str()) == 0)
			return true; // File found in the original directory

	// Search in subdirectories
	return RecursiveFileSearch(dir, fdata, file);
}

//-----------------------------------------------------------------------------
// Name: GetLastWriteTime
// Desc: Check when the file was last modified
//-----------------------------------------------------------------------------
bool File::GetLastWriteTime(const std::string filename, ULARGE_INTEGER* time)
{
	if (filename.empty())
		return false;

	WIN32_FIND_DATA data;
	HANDLE findhdl = FindFirstFile(filename.c_str(), &data);
	if (findhdl == INVALID_HANDLE_VALUE)
		return false;

	memcpy(time, &data.ftLastWriteTime, sizeof(ULARGE_INTEGER));

	FindClose(findhdl);
	return true;
}
bool File::GetLastWriteTime(const std::string filename, LPSYSTEMTIME time)
{
	if (filename.empty())
		return false;

	WIN32_FIND_DATA data;
	HANDLE findhdl = FindFirstFile(filename.c_str(), &data);
	if (findhdl == INVALID_HANDLE_VALUE)
		return false;

	if (!FileTimeToSystemTime(&data.ftLastWriteTime, time))
	{
		FindClose(findhdl);
		return false;
	}

	FindClose(findhdl);
	return true;
}

_ULARGE_INTEGER DateTime::FromBinary(uint64_t time)
{
	ULARGE_INTEGER lint;
	lint.QuadPart = (ULONGLONG)time;
	return lint;
}
bool DateTime::Equals(_ULARGE_INTEGER t0, _ULARGE_INTEGER t1)
{
	return t0.QuadPart == t1.QuadPart;
}

#else
#include <sys/stat.h>

//-----------------------------------------------------------------------------
// Name: GetLastWriteTime
// Desc: Check when the file was last modified
//-----------------------------------------------------------------------------
bool File::GetLastWriteTime(const std::string filename, time_t* time)
{
	if (filename.empty())
		return false;

	struct stat fileattr;
	stat(filename.c_str(), &fileattr);
	*time = fileattr.st_mtime;

	return true;
}
bool File::GetLastWriteTime(const std::string filename, struct tm** time)
{
	if (filename.empty())
		return false;

	struct stat fileattr;
	stat(filename.c_str(), &fileattr);
	*time = localtime(&fileattr.st_mtime);

	return true;
}
#endif