# This is a branch of GCC 12-3 with experimental support for AArch64 (Arm64) on Darwin.

The branch is recommended for (and has been tested on) powerpc, i686, x86_64 and aarch64 Darwin from Darwin9 (Mac OSX 10.5) through Darwin22 (macOS 13)

The support for Aarch64 (Arm64) remains experimental but is adequate now for many programs (and self-bootstrap).

Please see README for general information on the GCC sources.

Please see the general GCC 12.3 release documentation for the implementation status of core language features.

Please see gcc/config/aarch64/darwinpcs.md for a description of the macOS AArch64 (Arm64) ABI support.

**Please report issues for this branch to:
https://github.com/iains/gcc-12-branch/issues**

**_The current release is GCC-12.3-darwin-r0. (May 2023)_**

This release includes:
 * All upstream fixes since 12.2.
 * All fixes from GCC-12.1-darwin-r1
 * A fix for handling non-bootstrap builds with clang (issue #18).
 * Some local fixes for building and testing D.
 * Some fixes for handling newer SDKs with unguarded blocks use and Apple-local deprecations of some Posix interfaces.
 * libsanitizer is disabled on Darwin22+ pending a solution to locating dyld in the shared cache.

**_The current release is GCC-12.2-darwin-r0. (August 2022)_**

This release includes:
 * All upstream fixes since 12.1.
 * Improves the build to omit runpaths from the runtime libraries.
 * A fix for PR106435 which improves the handling of cross-TU global initializers for thread-local variables.
 * Fixes for builds and testing (include Ada) on Darwin8 (MacOSX 10.4, Tiger).

**_GCC-12.1-darwin-r1. (June 2022)_**

This release:
 * Fixes a critical bug in the Arm64 port (related to Issue #3, which is unfixed in Xcode toolchains in common use).
 * Adds a new configure option ```--with-darwin-extra-rpath=``` which allows a distribution to prepend a run path to the list automatically added by the compiler.  This is to allow for cases where the distribution refers to installed libraries using symlinks from outside the installation paths.
 * Resolves a potential issue with library references where a minor GCC version is replaced by the next and the old version is deleted.
 * Amends some of the system version processing to handle changes expected in macOS 13+.
 * Improves interoperability with clang in mixed code projects.

Thanks to contributors and testers.

**_GCC-12.1-darwin-r0. (May 2022)_**

Test results : https://github.com/iains/gcc-12-branch/issues/1#issuecomment-1120194463

Thanks to:
 * 'FX' (https://github.com/fxcoudert) for the main part of the ```__float128``` support, many test fixes and help in testing this release more widely.
 * Andrew Burgess (while at Embecosm) for the work on heap based trampolines.
 * Maxim Blinov  (Embecosm) for work on modifications to GCC's function lowering code to enable better support of the Darwin Arm64 ABI.

Iain Sandoe.
