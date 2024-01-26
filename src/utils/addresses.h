#pragma once
#include "platform.h"
#include "stdint.h"
#include "utils/module.h"
#include "utlstring.h"


struct Signature {
	const char *data = nullptr;
	size_t length = 0;

	template<size_t N>
	Signature(const char(&str)[N]) {
		data = str;
		length = N - 1;
	}
};
#define DECLARE_SIG(name, sig) inline const Signature name = Signature(sig);

namespace modules
{
	inline CModule *server;
	void Initialize();
}

namespace sigs
{
#ifdef _WIN32
	DECLARE_SIG(Weapon_IsLegacyModel, "\x48\x8B\xC4\x48\x89\x70\x2A\x55\x48\x8D\x68");
#else
	DECLARE_SIG(Weapon_IsLegacyModel, "\x48\x85\xFF\x0F\x84\x2A\x2A\x2A\x2A\x55\x31\xC0\x48\x89\xE5\x41\x56");
#endif
}