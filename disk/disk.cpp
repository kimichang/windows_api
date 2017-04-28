// disk.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
using namespace std;

char* ConvertLPWSTRToLPSTR(LPWSTR lpwszStrIn)
{
	LPSTR pszOut = NULL;
	if (lpwszStrIn != NULL)
	{
		int nInputStrLen = wcslen(lpwszStrIn);

		// Double NULL Termination
		int nOutputStrLen = WideCharToMultiByte(CP_ACP, 0, lpwszStrIn, nInputStrLen, NULL, 0, 0, 0) + 2;
		pszOut = new char[nOutputStrLen];

		if (pszOut)
		{
			memset(pszOut, 0x00, nOutputStrLen);
			WideCharToMultiByte(CP_ACP, 0, lpwszStrIn, nInputStrLen, pszOut, nOutputStrLen, 0, 0);
		}
	}
	return pszOut;
}

int _tmain(int argc, _TCHAR* argv[])
{

	DWORD dwSize = MAX_PATH;
	
	TCHAR szLogicalDrives[MAX_PATH] = { 0 };
//	LPWSTR szLogicalDrive = CA2W()
	
	DWORD dwResult = GetLogicalDriveStrings(dwSize, szLogicalDrives);


	if (dwResult > 0 && dwResult <= MAX_PATH) {
		TCHAR* szSingleDrive = szLogicalDrives;
		while (*szSingleDrive){
		
			cout << " Drive : " << ConvertLPWSTRToLPSTR(szSingleDrive) << endl;
			szSingleDrive += wcslen(szSingleDrive) + 1;
		}
	}
	return 0;
}

