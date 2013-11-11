#pragma once
#include <listeneradapter.h>
#include "api.hpp"

class webhost_interface;

namespace colubris {
	class COLUBRISLISTENER_API webhost_listener
	{
	public:
		webhost_listener(webhost_interface *webhost);
		

		bool start();
		bool stop();

		void on_cfgmgr_connected_impl();
		void on_cfgmgr_disconnected_impl(HRESULT hr);
		void on_cfgmgr_init_complete_impl();

		void on_app_created_impl(const wchar_t *app_key, const wchar_t *path, unsigned long site_id, const wchar_t *apppool_id, unsigned char *bindings, unsigned long num_bindings, bool requests_blocked);
		void on_app_deleted_impl(const wchar_t *app_key);
		void on_app_bindings_changed_impl(const wchar_t *app_key, unsigned char *bindings, unsigned long num_bindings);
		void on_app_apppool_changed_impl(const wchar_t *app_key, const wchar_t *apppool_id);
		void on_app_requests_blocked_changed_impl(const wchar_t *app_key, bool requests_blocked);

		void on_apppool_created_impl(const wchar_t *apppool_id, void *sid);
		void on_apppool_deleted_impl(const wchar_t *appoool_id);
		void on_apppool_identity_changed_impl(const wchar_t *apppool_id, void *sid);
		void on_apppool_state_changed_impl(const wchar_t *apppool_id, bool enabled);
		void on_apppool_can_open_lci_impl(const wchar_t *apppool_id, unsigned long channel_id);
		void on_apppool_allstop_impl(const wchar_t *apppool_id, unsigned long channel_id);

	private:
		webhost_interface *_webhost;
		WEBHOST_LISTENER_CALLBACKS _whl_callbacks;
		unsigned long _protocol_handle;
		void init_callbacks();
	};
}