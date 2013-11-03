#pragma once
#include "stdafx.h"
#include <listeneradapter.h>

namespace colubris {
	class webhost_listener {
	public:
		webhost_listener();
		bool start();
		bool stop();

		static void on_cfgmgr_connected(void *context);
		static void on_cfgmgr_disconnected(void *context, HRESULT hr);
		static void on_cfgmgr_init_complete(void *context);

		static void on_app_created(void *context, LPCWSTR app_key, LPCWSTR path, DWORD site_id, LPCWSTR apppool_id, PBYTE bindings, DWORD num_bindings, BOOL requests_blocked);
		static void on_app_deleted(void *context, LPCWSTR app_key);
		static void on_app_bindings_changed(void *context, LPCWSTR app_key, PBYTE bindings, DWORD num_bindings);
		static void on_app_apppool_changed(void *context, LPCWSTR app_key, LPCWSTR apppool_id);
		static void on_app_requests_blocked_changed(void *context, LPCWSTR app_key, BOOL requests_blocked);
		
		static void on_apppool_created(void *context, LPCWSTR apppool_id, PSID sid);
		static void on_apppool_deleted(void *context, LPCWSTR appoool_id);
		static void on_apppool_identity_changed(void *context, LPCWSTR apppool_id, PSID sid);
		static void on_apppool_state_changed(void *context, LPCWSTR apppool_id, BOOL enabled);
		static void on_apppool_can_open_lci(void *context, LPCWSTR apppool_id, DWORD channel_id);
		static void on_apppool_allstop(void *context, LPCWSTR apppool_id, DWORD channel_id);

	private:
		typedef struct context
		{
			UUID id;
			DWORD protocol_handle;
		};

		WEBHOST_LISTENER_CALLBACKS _whl_callbacks;
		context *_current_context;

		void init_callbacks();

		void on_cfgmgr_connected_impl(void *context);
		void on_cfgmgr_disconnected_impl(void *context, HRESULT hr);
		void on_cfgmgr_init_complete_impl(void *context);
		void on_app_created_impl(void *context, const wchar_t *app_key, const wchar_t *path, unsigned long site_id, const wchar_t *apppool_id, unsigned char *bindings, unsigned long num_bindings, bool requests_blocked);
		void on_app_deleted_impl(void *context, const wchar_t *app_key);
		void on_app_bindings_changed_impl(void *context, const wchar_t *app_key, unsigned char *bindings, unsigned long num_bindings);
		void on_app_apppool_changed_impl(void *context, const wchar_t *app_key, const wchar_t *apppool_id);
		void on_app_requests_blocked_impl(void *context, const wchar_t *app_key, bool requests_blocked);
		void on_apppool_created_impl(void *context, const wchar_t *apppool_id);
		void on_apppool_deleted_impl(void *context, const wchar_t *appoool_id);
		void on_apppool_identity_changed_impl(void *context, const wchar_t *apppool_id, void *sid);
		void on_apppool_state_changed_impl(void *context, const wchar_t *apppool_id, bool enabled);
		void on_apppool_can_open_lci_impl(void *context, const wchar_t *apppool_id, unsigned long channel_id);
		void on_apppool_allstop_impl(void *context, const wchar_t *apppool_id, unsigned long channel_id);
	};
}