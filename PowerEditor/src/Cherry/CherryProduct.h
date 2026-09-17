// Cherry++ product identity and isolation contract.
//
// Keep user-facing Cherry++ constants here instead of scattering literals through
// the inherited Notepad++ codebase. Internal Notepad++/NPP symbols are retained
// where they are part of the upstream implementation or plugin compatibility API.

#pragma once

#include <cstddef>
#include <string>

namespace cherry::product
{
	inline constexpr wchar_t displayName[] = L"Cherry++";
	inline constexpr wchar_t executableName[] = L"cherry++.exe";
	inline constexpr wchar_t appDataDirectory[] = L"Cherry++";
	inline constexpr wchar_t windowClassName[] = L"Cherry++";
	inline constexpr wchar_t projectUrl[] = L"https://github.com/paddman/cherry-plus-plus";

	inline constexpr char version[] = "0.1.0-dev";
	inline constexpr wchar_t versionW[] = L"0.1.0-dev";

	// Used only when explicitly importing settings. Cherry++ must not silently read
	// or write the legacy directory during normal startup.
	inline constexpr wchar_t legacyAppDataDirectory[] = L"Notepad++";
}

// The inherited settings resolver appends the literal "Notepad++" to AppData.
// This overload is force-included by the Cherry++ build and intercepts only that
// product-folder literal. All other pathAppend calls fall through unchanged.
std::wstring pathAppend(std::wstring& strDest, const std::wstring& str2append);

template <std::size_t N>
std::wstring pathAppend(std::wstring& strDest, const wchar_t (&str2append)[N])
{
	std::wstring productAwarePath{ str2append };
	if (productAwarePath == cherry::product::legacyAppDataDirectory)
		productAwarePath = cherry::product::appDataDirectory;
	return pathAppend(strDest, productAwarePath);
}
