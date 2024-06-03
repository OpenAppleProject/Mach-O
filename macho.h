/*
MIT License

Copyright (c) 2024 The Open Apple Project

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/
#ifndef MACHO_H
#define MACHO_H

// Integer defines, instead of using stdint 
typedef unsigned char                               u8;
typedef unsigned short                              u16;
typedef unsigned int                                u32;
typedef unsigned long long                          u64;
typedef signed char                                 i8;
typedef short int                                   i16;
typedef int                                         i32;
typedef long int                                    i64;

// Apple specific typedefs based on <mach/machine.h>
typedef i32                                         cpu_type_t;
typedef i32                                         cpu_subtype_t;

// File headers for 32-bit and 64-bit
typedef struct {
    u32 magic;
    cpu_type_t cputype;
    cpu_subtype_t cpusubtype;
    u32 filetype;
    u32 ncmds;
    u32 sizeofcmds;
    u32 flags;
} macho64_hdr;

typedef struct {
    u32 magic;
    cpu_type_t cputype;
    cpu_subtype_t cpusubtype;
    u32 filetype;
    u32 ncmds;
    u32 sizeofcmds;
    u32 flags;
    u32 reserved;
} macho32_hdr;

// Special magic for both 32 and 64-bit
#define MACHO32_MAGIC                               0xFEEDFACE
#define MACHO64_MAGIC                               0xFEEDFACF
#define MACHO32_CIGAM                               0XCEFAEDFE // NXSwapInt(MACHO32_MAGIC)
#define MACHO64_CIGAM                               0xCFFAEDFE // NXSwapInt(MACHO64_MAGIC)

// File type defs
#define MACHO_FILE_TYPE_OBJECT                      0x1
#define MACHO_FILE_TYPE_EXECUTE                     0x2
#define MACHO_FILE_TYPE_FVMLIB                      0x3
#define MACHO_FILE_TYPE_CORE                        0x4
#define MACHO_FILE_TYPE_PRELOAD                     0x5
#define MACHO_FILE_TYPE_DYLIB                       0x6
#define MACHO_FILE_TYPE_DYLINKER                    0x7
#define MACHO_FILE_TYPE_BUNDLE                      0x8
#define MACHO_FILE_TYPE_DYLIB_STUB                  0x9
#define MACHO_FILE_TYPE_DSYM                        0xA
#define MACHO_FILE_TYPE_KEXT_BUNDLE                 0xB
#define MACHO_FILE_TYPE_FILESET                     0xC

// File flags
#define MACHO_FLAG_NOUNDEFS                         0x1
#define MACHO_FLAG_INCRLINK                         0x2
#define MACHO_FLAG_DYLDLINK                         0x4
#define MACHO_FLAG_BINDATLOAD                       0x8
#define MACHO_FLAG_PREBOUND                         0x10
#define MACHO_FLAG_SPLIT_SEGS                       0x20
#define MACHO_FLAG_LAZY_INIT                        0x40
#define MACHO_FLAG_TWOLEVEL                         0x80
#define MACHO_FLAG_FORCE_FLAT                       0x100
#define MACHO_FLAG_NOMULTIDEFS                      0x200
#define MACHO_FLAG_NOFIXPREBINDING                  0x400
#define MACHO_FLAG_PREBINDABLE                      0x800
#define MACHO_FLAG_ALLMODSBOUND                     0x1000
#define MACHO_FLAG_SUBSECTIONS_VIA_SYMBOLS          0x2000
#define MACHO_FLAG_CANONICAL                        0x4000
#define MACHO_FLAG_WEAK_DEFINES                     0x8000
#define MACHO_FLAG_BINDS_TO_WEAK                    0x10000
#define MACHO_FLAG_ALLOW_STACK_EXECUTION            0x20000
#define MACHO_FLAG_ROOT_SAFE                        0x40000
#define MACHO_FLAG_SETUID_SAFE                      0x80000
#define MACHO_FLAG_NO_REEXPORTED_DYLIBS             0x100000
#define MACHO_FLAG_PIE                              0x200000
#define MACHO_FLAG_DEAD_STRIPPABLE_DYLIB            0x400000
#define MACHO_FLAG_HAS_TLV_DESCRIPTORS              0x800000
#define MACHO_FLAG_NO_HEAP_EXECUTION                0x1000000
#define MACHO_FLAG_APP_EXTENSION_SAFE               0x02000000
#define MACHO_FLAG_NLIST_OUTOFSYNC_WITH_DYLDINFO    0x04000000
#define MACHO_FLAG_SIM_SUPPORT                      0x08000000
#define MACHO_FLAG_DYLIB_IN_CACHE                   0x80000000


#endif // MACHO_H