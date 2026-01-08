# Changelog

All notable changes to this project will be documented in this file.

## [1.2.0] - 2026-01-08
### Fixed
- Fixed error that made the tester crash if the header wasn't called "ft_printf.h"

## [1.1.0] - 2025-12-24
### Added
- **Auto-Updater**: The script now checks for updates automatically on startup.
- **Developer Mode**: Added a warning when running the tester from a non-main branch.
- **Library Check**: Improved forbidden function detection by analyzing internal library symbols to avoid false positives.

### Fixed
- Fixed compilation logic when testing single functions inside the static library.

## [1.0.0] - 2025-12-21
### Added
- Initial release of the ft_printf Tester.
- Support for all mandatory conversions (%c, %s, %p, %d, %i, %u, %x, %X, %%).
- Full Bonus support (flags: -, 0, ., #, +, space).
- Norminette check integration.