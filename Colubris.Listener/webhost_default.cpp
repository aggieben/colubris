#include "stdafx.h"
#include "webhost_default.hpp"
#include <sstream>
#include <string>
#include <strsafe.h>
#include <iostream>

HINSTANCE colubris::webhost_default::_dll_handle;

colubris::webhost_default::webhost_default()
{
	if (nullptr == _dll_handle)
	{
		DWORD err;
		LPCTSTR msg = nullptr;
		std::stringstream ss;

		TCHAR inetsrvPath[512];
		GetSystemDirectory(inetsrvPath, 500);
		StringCchCat(inetsrvPath, 512, L"\\inetsrv");
		if (!SetDllDirectory(inetsrvPath))
		{
			err = GetLastError();
			FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, err, 0, (LPWSTR)&msg, 0, NULL);
			std::wstring lastError(msg);
			ss << "failed to load WebhostIPM DLL: " << std::string(lastError.begin(), lastError.end());
			std::cerr << ss.str();
			throw std::runtime_error(ss.str());
		}

		if (nullptr == (_dll_handle = LoadLibrary(L"wbhstipm.dll")))
		{
			DWORD err = GetLastError();
			LPCTSTR msg = nullptr;
			FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM, NULL, err, 0, (LPWSTR)&msg, 0, NULL);
			std::wstring lastError(msg);

			std::stringstream ss;
			ss << "failed to load Webhost IPM DLL: " << std::string(lastError.begin(), lastError.end());
			throw std::runtime_error(ss.str());
		}
	}

	if (nullptr ==
		(close_all_listener_channel_instances = reinterpret_cast<fn_close_all_listener_channel_instances_t>(
		GetProcAddress(_dll_handle, "WebhostCloseAllListenerChannelInstances"))))
	{
		throw new std::runtime_error("failed to assign webhost_default::close_all_listener_channel_instances");
	}

	if (nullptr == (get_version = reinterpret_cast<fn_get_version_t>(GetProcAddress(_dll_handle, "WebhostGetVersion"))))
	{
		throw new std::runtime_error("failed to assign webhost_default::get_version");
	}

	if (nullptr == (open_listener_channel_instance = reinterpret_cast<fn_open_listener_channel_instance_t>(GetProcAddress(_dll_handle, "WebhostOpenListenerChannelInstance"))))
	{
		throw new std::runtime_error("failed to assign webhost_default::open_listener_channel_instance");
	}

	if (nullptr == (register_protocol = reinterpret_cast<fn_register_protocol_t>(GetProcAddress(_dll_handle, "WebhostRegisterProtocol"))))
	{
		throw new std::runtime_error("failed to assign webhost_default::register_protocol.");
	}

	if (nullptr == (unregister_protocol = reinterpret_cast<fn_unregister_protocol_t>(GetProcAddress(_dll_handle, "WebhostUnregisterProtocol"))))
	{
		throw new std::runtime_error("failed to assign webhost_default::unregister_protocol");
	}
}