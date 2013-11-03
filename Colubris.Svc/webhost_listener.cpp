#include "stdafx.h"
#include "webhost_listener.hpp"

colubris::webhost_listener::webhost_listener()
{
	init_callbacks();
}

bool colubris::webhost_listener::start()
{
	if (_current_context != nullptr)
	{
		OutputDebugString(L"unexpected context");
		return false;
	}
	
	_current_context = new context();
	UuidCreate(&_current_context->id);
	//HRESULT hr = WebhostRegisterProtocol(L"protocol", &_whl_callbacks, _current_context, )
}

bool colubris::webhost_listener::stop()
{
	return true;
}

void colubris::webhost_listener::on_cfgmgr_connected(void *context)
{
}

void colubris::webhost_listener::on_cfgmgr_disconnected(void *context, HRESULT hr)
{
}

void colubris::webhost_listener::on_cfgmgr_init_complete(void *context)
{
}

void colubris::webhost_listener::on_app_created(void *context, LPCWSTR app_key, LPCWSTR path, DWORD site_id, LPCWSTR apppool_id, PBYTE bindings, DWORD num_bindings, BOOL requests_blocked)
{
}

void colubris::webhost_listener::on_app_deleted(void *context, LPCWSTR app_key)
{
}

void colubris::webhost_listener::on_app_bindings_changed(void *context, LPCWSTR app_key, PBYTE bindings, DWORD num_bindings)
{
}

void colubris::webhost_listener::on_app_apppool_changed(void *context, LPCWSTR app_key, LPCWSTR apppool_id)
{
}

void colubris::webhost_listener::on_app_requests_blocked_changed(void *context, LPCWSTR app_key, BOOL requests_blocked)
{
}

void colubris::webhost_listener::on_apppool_created(void *context, LPCWSTR apppool_id, PSID sid)
{
}

void colubris::webhost_listener::on_apppool_deleted(void *context, LPCWSTR appoool_id)
{
}

void colubris::webhost_listener::on_apppool_identity_changed(void *context, LPCWSTR apppool_id, PSID sid)
{
}

void colubris::webhost_listener::on_apppool_state_changed(void *context, LPCWSTR apppool_id, BOOL enabled)
{
}

void colubris::webhost_listener::on_apppool_can_open_lci(void *context, LPCWSTR apppool_id, DWORD channel_id)
{
}

void colubris::webhost_listener::on_apppool_allstop(void *context, LPCWSTR apppool_id, DWORD channel_id)
{
}

// Private member functions

void colubris::webhost_listener::init_callbacks()
{
	_whl_callbacks.pfnWebhostListenerApplicationAppPoolChanged = &colubris::webhost_listener::on_app_apppool_changed;
	_whl_callbacks.pfnWebhostListenerApplicationBindingsChanged = &colubris::webhost_listener::on_app_bindings_changed;
	_whl_callbacks.pfnWebhostListenerApplicationCreated = &colubris::webhost_listener::on_app_created;
	_whl_callbacks.pfnWebhostListenerApplicationDeleted = &colubris::webhost_listener::on_app_deleted;
	_whl_callbacks.pfnWebhostListenerApplicationPoolAllListenerChannelInstancesStopped = &colubris::webhost_listener::on_apppool_allstop;
	_whl_callbacks.pfnWebhostListenerApplicationPoolCanOpenNewListenerChannelInstance = &colubris::webhost_listener::on_apppool_can_open_lci;
	_whl_callbacks.pfnWebhostListenerApplicationPoolCreated = &colubris::webhost_listener::on_apppool_created;
	_whl_callbacks.pfnWebhostListenerApplicationPoolDeleted = &colubris::webhost_listener::on_apppool_deleted;
	_whl_callbacks.pfnWebhostListenerApplicationPoolIdentityChanged = &colubris::webhost_listener::on_apppool_identity_changed;
	_whl_callbacks.pfnWebhostListenerApplicationPoolStateChanged = &colubris::webhost_listener::on_apppool_state_changed;
	_whl_callbacks.pfnWebhostListenerApplicationRequestsBlockedChanged = &colubris::webhost_listener::on_app_requests_blocked_changed;
	_whl_callbacks.pfnWebhostListenerConfigManagerConnected = &colubris::webhost_listener::on_cfgmgr_connected;
	_whl_callbacks.pfnWebhostListenerConfigManagerDisconnected = &colubris::webhost_listener::on_cfgmgr_disconnected;
	_whl_callbacks.pfnWebhostListenerConfigManagerInitializationCompleted = &colubris::webhost_listener::on_cfgmgr_init_complete;
}

void colubris::webhost_listener::on_cfgmgr_connected_impl(void *context)
{

}

void colubris::webhost_listener::on_cfgmgr_disconnected_impl(void *context, HRESULT hr)
{

}

void colubris::webhost_listener::on_cfgmgr_init_complete_impl(void *context)
{

}

void colubris::webhost_listener::on_app_created_impl(void *context, const wchar_t *app_key, const wchar_t *path, unsigned long site_id, const wchar_t *apppool_id, unsigned char *bindings, unsigned long num_bindings, bool requests_blocked)
{

}

void colubris::webhost_listener::on_app_deleted_impl(void *context, const wchar_t *app_key)
{

}

void colubris::webhost_listener::on_app_bindings_changed_impl(void *context, const wchar_t *app_key, unsigned char *bindings, unsigned long num_bindings)
{

}

void colubris::webhost_listener::on_app_apppool_changed_impl(void *context, const wchar_t *app_key, const wchar_t *apppool_id)
{

}

void colubris::webhost_listener::on_app_requests_blocked_impl(void *context, const wchar_t *app_key, bool requests_blocked)
{

}

void colubris::webhost_listener::on_apppool_created_impl(void *context, const wchar_t *apppool_id)
{

}

void colubris::webhost_listener::on_apppool_deleted_impl(void *context, const wchar_t *appoool_id)
{

}

void colubris::webhost_listener::on_apppool_identity_changed_impl(void *context, const wchar_t *apppool_id, void *sid)
{

}

void colubris::webhost_listener::on_apppool_state_changed_impl(void *context, const wchar_t *apppool_id, bool enabled)
{

}

void colubris::webhost_listener::on_apppool_can_open_lci_impl(void *context, const wchar_t *apppool_id, unsigned long channel_id)
{

}

void colubris::webhost_listener::on_apppool_allstop_impl(void *context, const wchar_t *apppool_id, unsigned long channel_id)
{

}