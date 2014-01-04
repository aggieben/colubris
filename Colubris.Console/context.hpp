#pragma once
#include "Colubris.Listener.hpp"

struct colubris_context
{
	colubris::webhost_interface *webhost;
	colubris::webhost_listener *listener;
};