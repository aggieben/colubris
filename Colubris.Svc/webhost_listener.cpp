#include "stdafx.h"
#include "webhost_listener.hpp"

colubris::webhost_listener::webhost_listener()
{
	init_callbacks();
	_protocol_handle = 0;
}

bool colubris::webhost_listener::start()
{
	HRESULT hr = WebhostRegisterProtocol(L"protocol", &_whl_callbacks, this, &this->_protocol_handle);
	if (hr != S_OK)
	{
		// handle error here
	}
}

bool colubris::webhost_listener::stop()
{
	return true;
}

void colubris::webhost_listener::on_cfgmgr_connected_impl()
{

}

void colubris::webhost_listener::on_cfgmgr_disconnected_impl(HRESULT hr)
{

}

void colubris::webhost_listener::on_cfgmgr_init_complete_impl()
{

}

void colubris::webhost_listener::on_app_created_impl(const wchar_t *app_key, const wchar_t *path, unsigned long site_id, const wchar_t *apppool_id, unsigned char *bindings, unsigned long num_bindings, bool requests_blocked)
{

}

void colubris::webhost_listener::on_app_deleted_impl(const wchar_t *app_key)
{

}

void colubris::webhost_listener::on_app_bindings_changed_impl(const wchar_t *app_key, unsigned char *bindings, unsigned long num_bindings)
{

}

void colubris::webhost_listener::on_app_apppool_changed_impl(const wchar_t *app_key, const wchar_t *apppool_id)
{

}

void colubris::webhost_listener::on_app_requests_blocked_changed_impl(const wchar_t *app_key, bool requests_blocked)
{

}

void colubris::webhost_listener::on_apppool_created_impl(const wchar_t *apppool_id, void *sid)
{

}

void colubris::webhost_listener::on_apppool_deleted_impl(const wchar_t *appoool_id)
{

}

void colubris::webhost_listener::on_apppool_identity_changed_impl(const wchar_t *apppool_id, void *sid)
{

}

void colubris::webhost_listener::on_apppool_state_changed_impl(const wchar_t *apppool_id, bool enabled)
{

}

void colubris::webhost_listener::on_apppool_can_open_lci_impl(const wchar_t *apppool_id, unsigned long channel_id)
{

}

void colubris::webhost_listener::on_apppool_allstop_impl(const wchar_t *apppool_id, unsigned long channel_id)
{

}

// Private member functions

void colubris::webhost_listener::init_callbacks()
{
	// ConfigManager callbacks
	_whl_callbacks.pfnWebhostListenerConfigManagerConnected = [](void *context)
	{
		auto _this = static_cast<colubris::webhost_listener *>(context);
		(_this->*&colubris::webhost_listener::on_cfgmgr_connected_impl)();
	};

	_whl_callbacks.pfnWebhostListenerConfigManagerDisconnected = [](void *context, HRESULT hr)
	{
		auto _this = static_cast<colubris::webhost_listener *>(context);
		(_this->*&colubris::webhost_listener::on_cfgmgr_disconnected_impl)(hr);
	};

	_whl_callbacks.pfnWebhostListenerConfigManagerInitializationCompleted = [](void *context)
	{
		auto _this = static_cast<colubris::webhost_listener *>(context);
		(_this->*&colubris::webhost_listener::on_cfgmgr_init_complete_impl)();
	};

	// Application callbacks
	_whl_callbacks.pfnWebhostListenerApplicationCreated = [](void *context, LPCWSTR app_key, LPCWSTR path, DWORD site_id, LPCWSTR apppool_id, PBYTE bindings, DWORD num_bindings, BOOL requests_blocked)
	{
		auto _this = static_cast<colubris::webhost_listener *>(context);
		(_this->*&colubris::webhost_listener::on_app_created_impl)(app_key, path, site_id, apppool_id, bindings, num_bindings, static_cast<bool>(requests_blocked));
	};

	_whl_callbacks.pfnWebhostListenerApplicationDeleted = [](void *context, LPCWSTR app_key)
	{
		auto _this = static_cast<colubris::webhost_listener *>(context);
		(_this->*&colubris::webhost_listener::on_app_deleted_impl)(app_key);
	};

	_whl_callbacks.pfnWebhostListenerApplicationBindingsChanged = [](void *context, LPCWSTR app_key, PBYTE bindings, DWORD num_bindings)
	{
		auto _this = static_cast<colubris::webhost_listener *>(context);
		(_this->*&colubris::webhost_listener::on_app_bindings_changed_impl)(app_key, bindings, num_bindings);
	};

	_whl_callbacks.pfnWebhostListenerApplicationAppPoolChanged = [](void *context, LPCWSTR app_key, LPCWSTR apppool_id)
	{
		auto _this = static_cast<colubris::webhost_listener *>(context);
		(_this->*&colubris::webhost_listener::on_app_apppool_changed_impl)(app_key, apppool_id);
	};

	_whl_callbacks.pfnWebhostListenerApplicationRequestsBlockedChanged = [](void *context, LPCWSTR app_key, BOOL requests_blocked)
	{
		auto _this = static_cast<colubris::webhost_listener *>(context);
		(_this->*&colubris::webhost_listener::on_app_requests_blocked_changed_impl)(app_key, requests_blocked);
	};

	// AppPool Callbacks
	_whl_callbacks.pfnWebhostListenerApplicationPoolCreated = [](void *context, LPCWSTR apppool_id, PSID sid)
	{
		auto _this = static_cast<colubris::webhost_listener *>(context);
		(_this->*&colubris::webhost_listener::on_apppool_created_impl)(apppool_id, sid);
	};
	
	_whl_callbacks.pfnWebhostListenerApplicationPoolDeleted = [](void *context, LPCWSTR apppool_id)
	{
		auto _this = static_cast<colubris::webhost_listener *>(context);
		(_this->*&colubris::webhost_listener::on_apppool_deleted_impl)(apppool_id);
	};

	_whl_callbacks.pfnWebhostListenerApplicationPoolIdentityChanged = [](void *context, LPCWSTR apppool_id, PSID sid)
	{
		auto _this = static_cast<colubris::webhost_listener *>(context);
		(_this->*&colubris::webhost_listener::on_apppool_identity_changed_impl)(apppool_id, sid);
	};

	_whl_callbacks.pfnWebhostListenerApplicationPoolStateChanged = [](void *context, LPCWSTR apppool_id, BOOL enabled)
	{
		auto _this = static_cast<colubris::webhost_listener *>(context);
		(_this->*&colubris::webhost_listener::on_apppool_state_changed_impl)(apppool_id, enabled);
	};

	_whl_callbacks.pfnWebhostListenerApplicationPoolCanOpenNewListenerChannelInstance = [](void *context, LPCWSTR apppool_id, DWORD channel_id)
	{
		auto _this = static_cast<colubris::webhost_listener *>(context);
		(_this->*&colubris::webhost_listener::on_apppool_can_open_lci_impl)(apppool_id, channel_id);
	};

	_whl_callbacks.pfnWebhostListenerApplicationPoolAllListenerChannelInstancesStopped = [](void *context, LPCWSTR apppool_id, DWORD channel_id)
	{
		auto _this = static_cast<colubris::webhost_listener *>(context);
		(_this->*&colubris::webhost_listener::on_apppool_allstop_impl)(apppool_id, channel_id);
	};
}