// CreateNewProcess.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <Windows.h>
#include <iostream>

using namespace std;

int main()
{
    // Initialize the STARTUPINFO structure
    
    STARTUPINFO si = { sizeof(si) }; // Set the size of the structure
    PROCESS_INFORMATION pi; // Structure to hold process information

    // Specify the name of the application to create
    wchar_t name[] = L"Notepad.exe";

    // Create the new process
    BOOL created = CreateProcess(
        nullptr,        // Application name (nullptr to use command line)
        name,           // Command line (the executable to run)
        nullptr,        // Process attributes (default)
        nullptr,        // Thread attributes (default)
        FALSE,          // Inherit handles (FALSE means no inheritance)
        0,              // Creation flags (default)
        nullptr,        // Environment block (default)
        nullptr,        // Current directory (default)
        &si,            // Pointer to STARTUPINFO structure
        &pi             // Pointer to PROCESS_INFORMATION structure
    );

    // Check if the process was created successfully
    if (!created)
    {
        // If creation failed, get the error code
        DWORD dwErrorCode = GetLast
