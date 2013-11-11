#pragma once
#include "api.hpp"
#include <Windows.h>

namespace colubris {
	class COLUBRISLISTENER_API webhost_interface
	{
	public:
		typedef HRESULT(__stdcall *fn_close_all_listener_channel_instances_t)(DWORD protocol_handle, LPCWSTR apppool_id, DWORD channel_id);
		typedef HRESULT(__stdcall *fn_get_version_t)(DWORD *major_version, DWORD *minor_version);
		typedef HRESULT(__stdcall *fn_open_listener_channel_instance_t)(DWORD protocol_handle, LPCWSTR apppool_id, DWORD channel_id, PBYTE channel_blob, DWORD channel_blob_byte_count);
		typedef HRESULT(__stdcall *fn_register_protocol_t)(LPCWSTR protocol_id, void *listener_callbacks, void *context, DWORD *protocol_handle);
		typedef HRESULT(__stdcall *fn_unregister_protocol_t)(DWORD protocol_handle);

		fn_close_all_listener_channel_instances_t close_all_listener_channel_instances;
		fn_get_version_t get_version;
		fn_open_listener_channel_instance_t open_listener_channel_instance;
		fn_register_protocol_t register_protocol;
		fn_unregister_protocol_t unregister_protocol;
	};
}