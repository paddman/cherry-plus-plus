# Cherry++

Cherry++ is a fast native Windows text and code editor derived from the Notepad++ codebase.
The project keeps the mature Scintilla/editor foundation and plugin compatibility where practical,
while developing its own product identity, configuration namespace, UX, and future developer tooling.

> **Current development milestone:** Cherry++ v0.1 — Product Isolation

## v0.1 goals

Cherry++ v0.1 establishes a clean boundary between Cherry++ and upstream Notepad++:

- Cherry++ product name and Windows application identity
- Cherry++-owned version namespace (`0.1.x`)
- isolated per-user settings under `%APPDATA%\Cherry++`
- portable mode remains supported through the existing local-configuration mechanism
- Cherry++ and Notepad++ can be installed and used side-by-side without sharing user configuration
- preserve the existing Notepad++ plugin API as the compatibility baseline
- document the exact upstream baseline and sync policy

The v0.1 work intentionally avoids large editor-engine rewrites. Product-specific code should be
kept behind a small Cherry++ layer so future upstream synchronization remains manageable.

## Direction

After product isolation, the planned development sequence is:

1. **v0.2** — Command Palette, Quick Open, Workspace
2. **v0.3** — Git integration, Tasks, Problems, bottom panel
3. **v0.4** — Language Server Protocol (LSP), symbols, diagnostics, intelligent completion
4. **v0.5** — Cherry++ Plugin API v2 and optional AI providers
5. **v1.0** — stable release/update pipeline, recovery, hardening, documentation

## Upstream relationship

Cherry++ is derived from the open-source Notepad++ project. Upstream fixes and security updates are
expected to continue flowing into Cherry++ while Cherry++-specific features remain isolated as much
as possible. See [UPSTREAM.md](UPSTREAM.md) for the sync policy.

Cherry++ is not the official Notepad++ distribution and should not present itself as one.

## Supported OS

Cherry++ currently follows the Windows platform support inherited from the upstream codebase.
See [SUPPORTED_SYSTEM.md](SUPPORTED_SYSTEM.md) for the current baseline.

## Build

The existing Windows build system remains the v0.1 build baseline. See [BUILD.md](BUILD.md).

## License

Cherry++ is distributed under the [GNU General Public License](LICENSE), consistent with the
upstream project. Existing upstream copyright and license notices are retained in inherited source
files.

## Credits

Cherry++ is built on the work of the Notepad++ project, Scintilla, and their contributors.
Upstream project: https://github.com/notepad-plus-plus/notepad-plus-plus
