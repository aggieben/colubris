#include "stdafx.h"
#include "webhost_default.hpp"

HINSTANCE colubris::webhost_default::_dll_handle;

colubris::webhost_default::webhost_default()
{
	if (nullptr == _dll_handle)
	{
		if (nullptr == (_dll_handle = LoadLibrary(L"whbhstipm.dll")))
		{
			throw new std::runtime_error("failed to load Webhost IPM DLL");
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