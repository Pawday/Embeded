# Embedded platform

---

<img src="./media/LLVMEMB.svg" alt="Chip with LLVM dragon" width=300>

## [**LLVM**](https://github.com/llvm/llvm-project) and [**CMake**](https://github.com/Kitware/CMake) embedded infrastructure.

The set of embedded libraries adopted to cmake or written 
from scratch without any assembly language (for now and hopefully in the future)


### Motivation
There are many toolchains and IDEs for embedded development

For example:

| Platform | Compilers | IDEs                                     |
|----------|-----------|------------------------------------------|
| AVR      | avr-gcc   | Atmel Studio<br/>  Arduino IDE           |
| STM32    | arm-gcc   | STM32CubeIDE <br/> Arduino IDE partially |
| MIPS     | mips-gcc  | Eclipse with plugins                     |



Notice that for every platform, you need their own based on [GNU GCC](https://gcc.gnu.org/) compiler

What does this lead to?

Every ${platform}-gcc toolchain comes with their own C library,
possibly unnecessary runtime libraries
* pthread
* stdio (can you guess what's output device is uses? I'm not)

and tons of assembly sources and non-portable [autotools](https://www.gnu.org/software/autoconf/autoconf.html) scripts


> I'm using Windows, how to run ./configure on it?
> > Just download [MSYS](https://www.msys2.org/) or [MINGW](https://www.mingw-w64.org/)
> 
> I have __glibc-1.2.42.5.2.52.dll__ not found
> 
> > Run the shell
> 
> ".." not recognized as an internal or external command
> > We don't support Windows natively

What about **IDE** support?

There is no way **Linux guys** think about it

So, every manufacture makes its own IDE targeting specifically __this__ makefiles setup

Don't even try to modify it

> #### What's the solution?
[**CMake**](https://github.com/Kitware/CMake) — the build system generator

It can generate project files for many building systems, including [MSBuild](https://learn.microsoft.com/en-us/visualstudio/msbuild/msbuild)
(Microsoft Visual Studio)

And that project is all about cross-building from anywhere via those tools

- No incompatible GNU utils
- No library duplication (look to [LLVM C library](https://libc.llvm.org/))
- Massive IDE support
- Full library flow control (no transitive glibc pthread unwind)


### Goals

CMAKE
- [ ] clang triple selection
- [ ] CMAKE_\<LANG>_COMPILE_OBJECT for multiple targets in the same config
- [ ] Support all of CMAKE_BUILD_TYPE
- [ ] deal with CMAKE_TOOLSET for MSBuild (it's not the CMAKE_TOOLCHAIN)
- [ ] popular flashing tools detection

LLVM
- [ ] Linking without linker scripts
- [ ] C++ (i mean section to libunwind mapping)
- [ ] Only LLVM Bytecode (be careful with aggressive LTO)
- [ ] Other languages ([Rust](https://www.rust-lang.org/), [Kotlin Native](https://kotlinlang.org/docs/native-overview.html))

Targets
- [ ] AVR
- [ ] STM32

Standard libraries
- [ ] LLVM libc
- [ ] LLVM libc++
- [ ] LLVM libunwind (aka libexception or libcallstack)

Platform libraries
- [ ] STM32 HAL
- [ ] AVR HAL
- [ ] Arduino HAL

## Remark

It all sounds good and wonderfully, but it's actually **A HUGE AMOUNT OF WORK**

I'm definitely not able to deal with all of that by alone

If you like the idea, give it a start on GitHub and share it with an experienced Embedded Software Engineer

I believe it's the future of embedded software development.  