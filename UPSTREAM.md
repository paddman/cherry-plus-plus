# Cherry++ upstream policy

Cherry++ is derived from the Notepad++ codebase and intentionally keeps upstream synchronization
as a first-class maintenance requirement.

## v0.1 baseline

The `feature/cherry-v0.1-product-isolation` branch was created from Cherry++ `master` at:

`be80edcfdcacaa10fe55ae91276efd73e2bb0359`

This commit is the reproducible baseline for the v0.1 product-isolation work.

## Rules for Cherry++ changes

1. Prefer new Cherry++ code under `PowerEditor/src/Cherry/`.
2. Avoid renaming inherited Notepad++ C++ classes or plugin API symbols merely for branding.
   Those names are implementation/compatibility details and mass-renaming them creates unnecessary
   upstream merge conflicts.
3. Product-facing identity must come from the Cherry++ product layer rather than scattered literals.
4. Keep inherited license and copyright headers intact.
5. Pull security fixes, correctness fixes, Scintilla updates, and useful upstream editor improvements
   regularly.
6. Resolve upstream conflicts in the Cherry++ integration layer whenever possible rather than
   permanently forking core editor behavior.

## Compatibility boundary

The existing Notepad++ plugin API is the v0.1 compatibility baseline. Internal types such as
`Notepad_plus`, `NppParameters`, `NPPM_*`, and related plugin messages may retain their inherited
names. User-facing branding, executable metadata, configuration directories, update endpoints, and
future Cherry++ APIs must use Cherry++ identity.

## Sync procedure

When synchronizing upstream:

1. record the upstream commit/tag being imported;
2. merge or rebase it into an integration branch;
3. resolve conflicts without removing Cherry++ product isolation;
4. build x64 and run smoke tests;
5. verify Cherry++ and Notepad++ still run side-by-side with separate user settings;
6. record the new baseline here or in the release notes.
