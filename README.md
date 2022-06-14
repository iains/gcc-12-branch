# This is a branch of GCC 12-1 with experimental support for AArch64 (Arm64) on Darwin.

The branch is recommended for (and has been tested on) powerpc, i686, x86_64 and aarch64 Darwin from Darwin9 (Mac OSX 10.5) through Darwin21 (macOS 12) (for architectures relevant to each version).  The branch has also been tested to build cross-compilers between x86_64 and aarch64 and on aarch64-linux-gnu without regressions.

The support for Aarch64 (Arm64) remains experimental but is adequate now for many programs (and self-bootstrap).

Please see README for general information on the GCC sources.

Please see the GCC 12.1 release documentation for the implementation status of core language features.

Please see gcc/config/aarch64/darwinpcs.md for a description of the macOS AArch64 (Arm64) ABI support.

**Please report issues for this branch to:
https://github.com/iains/gcc-12-branch/issues**

**_The current release is GCC-12.1-darwin-r1. (June 2022)_**

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
