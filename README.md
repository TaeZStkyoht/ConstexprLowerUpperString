# ConstexprLowerUpperString
Simple constexpr lower/upper string like object creator.

# Installation
```bash
mkdir build
cd build
cmake [-DBUILD_EXAMPLES=ON] ..
make install
```
# Usage
```C++
#include <ConstexprLowerUpperString/ConstexprLowerUpperString.h>

static constexpr auto lowerVal = ConstexprLowerUpperString::CLUStringHelper::CreateLower("SoMeThInG");
static constexpr auto upperVal = ConstexprLowerUpperString::CLUStringHelper::CreateUpper("SoMeThInG");
```
see also: https://github.com/TaeZStkyoht/ConstexprLowerUpperString/blob/main/examples/src/main.cpp
# Uninstallation
In the build directory:
```bash
xargs rm < install_manifest.txt
```
