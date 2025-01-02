
#if __COVERITY__
#if !defined(COVERITY_COMPAT_444796f5c87569ee11c7bd44b5db7139)
#define COVERITY_COMPAT_444796f5c87569ee11c7bd44b5db7139

/*
  Copyright (c) 2023 Synopsys, Inc. All rights reserved worldwide.
  The information contained in this file is the proprietary and confidential
  information of Synopsys, Inc. and its licensors, and is supplied subject to,
  and may be used only by Synopsys customers in accordance with the terms and
  conditions of a previously executed license agreement between Synopsys and
  that customer.
*/


/* DO NOT MODIFY THE CONTENTS OF THIS FILE */


#if defined(__cplusplus)
extern "C" {
#endif

/*
  This shouldn't happen in practice. However, some of our test cases don't
  predefine these appropriately, so we default to something sensible.
*/
#if !defined(__clang_major__) && !defined(__clang_minor__)
#define __clang_major__ 3
#define __clang_minor__ 4
#endif

/*
  When compiling with optimizations enabled, the GNU C library (glibc) string.h
  header file provides implementations for some C standard library functions
  such as strcmp() via function-like macro definitions.  These macro definitions
  prevent analysis from using Coverity provided models and from recognizing some
  kinds of defects.  Other compiler configurations use Coverity's #nodef
  facility to suppress these macros, but #nodef is not currently supported with
  the Clang based frontend.  Defining __NO_STRING_INLINES prevents string.h from
  defining these macros.
*/
#define __NO_STRING_INLINES


/*
  Mac OS X and GNU C library (glibc) standard headers provide implementations of
  some C standard library functions via function-like macro definitions when
  _FORTIFY_SOURCE is defined as a number larger than 0.  By default, Mac OS X
  feature headers define _FORTIFY_SOURCE as 2 for Mac OS X 10.5 and above.
  These macro definitions prevent analysis from using Coverity provided models
  and from recognizing some kinds of defects.  Other compiler configurations use
  Coverity's #nodef facility to suppress these macros, but #nodef is not
  currently supported with the Clang based frontend.  Defining _FORTIFY_SOURCE
  as 0 prevents these macros from being defined.
*/
#define _FORTIFY_SOURCE 0

/*
  Determine whether we are actually configuring an Apple Clang build.
  Apple Clang versions 2.1 and earlier did not define the
  __apple_build_version__ macro.  This heuristic would fail for LLVM Clang
  releases earlier than 2.2, which are not supported.
*/
#if defined(__apple_build_version__)
#define __coverity_assume_xcode__ 1
#else // defined(__apple_build_version__)
#define __coverity_assume_xcode__ ((__clang_major__ < 2) || \
    ((__clang_major__ == 2) && (__clang_minor__ <= 1)))
#endif // !defined(__apple_build_version__)


/*************************************
 *********** APPLE CLANG *************
 *************************************/

/*
  Apple's Clang distribution does not retain the values of the LLVM Clang
  distribution for the __clang_major__ and __clang_minor__ predefined macros.
  Rather, they are defined to match Apple's version branding.  For example, the
  distribution of Clang provided with Xcode 4.1 defines these macros as '2' and
  '1' respectively despite the distribution having derived from the LLVM Clang
  3.0 release which sets them to '3' and '0' respectively.  This header file
  depends on the ability to detect the version of Clang to emulate based on
  predefined macros.  Recent versions of Apple's Clang distribution predefine
  the __apple_build_version__ macro which enables recognition of Apple's
  distribution.  __coverity_clang_major__ and __coverity_clang_minor__ are
  set based on the presence of __apple_build_version__ and mapped values for
  the __clang_major__ and __clang_minor__ macros.
*/
#if __coverity_assume_xcode__
    /* Apple's Clang distribution */
    #if __clang_major__ >= 13
         /* Assume derivation from LLVM Clang 12.0 */
        #define __coverity_clang_major__ 12
        #define __coverity_clang_minor__ 0
    #elif __clang_major__ >= 12
        #if (__clang_minor__ == 0) && (__clang_patchlevel__ >= 5)
             /* Assume derivation from LLVM Clang 11.0 */
             #define __coverity_clang_major__ 11
             #define __coverity_clang_minor__ 0
        #else
             /* Assume derivation from LLVM Clang 10.0 */
             #define __coverity_clang_major__ 10
             #define __coverity_clang_minor__ 0
        #endif
    #elif __clang_major__ >= 11
         /* Assume derivation from LLVM Clang 9.0 */
        #define __coverity_clang_major__ 9
        #define __coverity_clang_minor__ 0
    #elif __clang_major__ >= 10
         /* Assume derivation from LLVM Clang 6.0 */
        #define __coverity_clang_major__ 6
        #define __coverity_clang_minor__ 0
    #elif __clang_major__ >= 9
        /* Assume derivation from LLVM Clang 4.0 */
        #define __coverity_clang_major__ 4
        #define __coverity_clang_minor__ 0
    #elif __clang_major__ >= 8
        /* Assume derivation from LLVM Clang 3.8 */
        #define __coverity_clang_major__ 3
        #define __coverity_clang_minor__ 8
    #elif __clang_major__ >= 7
        #if __clang_minor__ >= 3
            /* Assume derivation from LLVM Clang 3.8 */
            #define __coverity_clang_major__ 3
            #define __coverity_clang_minor__ 8
        #else
            /* Assume derivation from LLVM Clang 3.7 */
            #define __coverity_clang_major__ 3
            #define __coverity_clang_minor__ 7
        #endif
    #elif __clang_major__ >= 6
        #if __clang_minor__ >= 3
            /* Assume derivation from LLVM Clang 3.6 */
            #define __coverity_clang_major__ 3
            #define __coverity_clang_minor__ 6
        #else
            /* Assume derivation from LLVM Clang 3.5 */
            #define __coverity_clang_major__ 3
            #define __coverity_clang_minor__ 5
        #endif
    #elif __clang_major__ >= 5
        #if __clang_minor__ >= 1
            /* Assume derivation from LLVM Clang 3.4 */
            #define __coverity_clang_major__ 3
            #define __coverity_clang_minor__ 4
        #else
            /* Assume derivation from LLVM Clang 3.3 */
            #define __coverity_clang_major__ 3
            #define __coverity_clang_minor__ 3
        #endif
    #elif __clang_major__ >= 4
        #if __clang_minor__ >= 2
            /* Assume derivation from LLVM Clang 3.2 */
            #define __coverity_clang_major__ 3
            #define __coverity_clang_minor__ 2
        #else
            /* Assume derivation from LLVM Clang 3.1 */
            #define __coverity_clang_major__ 3
            #define __coverity_clang_minor__ 1
        #endif
    #elif __clang_major__ >= 3
        #if __clang_minor__ >= 1
            /* Assume derivation from LLVM Clang 3.1 */
            #define __coverity_clang_major__ 3
            #define __coverity_clang_minor__ 1
        #else
            /* Assume derivation from LLVM Clang 3.0 */
            #define __coverity_clang_major__ 3
            #define __coverity_clang_minor__ 0
        #endif
    #else
        #if (__clang_major__ >= 2) || \
            ((__clang_major__ == 1) && (__clang_minor__ > 7))
            /* Assume Apple Clang version 2.1 derived from LLVM Clang 3.0 */
            #define __coverity_clang_major__ 3
            #define __coverity_clang_minor__ 0
        #else
            /* Assume Apple Clang version 1.7 derived from LLVM Clang 2.9 */
            #define __coverity_clang_major__ 2
            #define __coverity_clang_minor__ 9
        #endif
    #endif
#else /* } { */
    /* Assume LLVM Clang distribution */
    #define __coverity_clang_major__ __clang_major__
    #define __coverity_clang_minor__ __clang_minor__
#endif /* } */

/* Encode a version pair as a single integer. */
#define __cov_encode_ver(maj, min) ((maj) * 100 + (min))

/*
 * Compare two version pairs. Roughly equivalent to:
 * (version 0) op (version 1)
 * where `op` is a relational operator.
 */
#define __cov_compare_versions(maj0, min0, maj1, min1, op) \
    ((__cov_encode_ver(maj1, min1) - __cov_encode_ver(maj0, min0)) op 0)

/*
 * Compare the given version against the coverity compatibility
 * version with the given relational operator.
 */
#define __cov_comp_clang_compat_ver(maj, min, op) \
    (__cov_compare_versions( \
        maj, min, \
        __coverity_clang_major__, __coverity_clang_minor__, \
        op \
    ))

/*
 * Compare the given version against the native version with the given
 * relational operator.
 */
#define __cov_comp_clang_native_ver(maj, min, op) \
    (__cov_compare_versions( \
        maj, min, \
        __clang_major__, __clang_minor__, \
        op \
    ))

#define __cov_clang_version_lt(maj, min) \
    __cov_comp_clang_compat_ver((maj), (min), <)
#define __cov_clang_version_gt(maj, min) \
    __cov_comp_clang_compat_ver((maj), (min), >)
#define __cov_clang_version_le(maj, min) \
    __cov_comp_clang_compat_ver((maj), (min), <=)
#define __cov_clang_version_ge(maj, min) \
    __cov_comp_clang_compat_ver((maj), (min), >=)

#define __cov_xcode_version_lt(maj, min) \
    (__coverity_assume_xcode__ && \
     __cov_comp_clang_native_ver((maj), (min), <))
#define __cov_xcode_version_gt(maj, min) \
    (__coverity_assume_xcode__ && \
     __cov_comp_clang_native_ver((maj), (min), >))
#define __cov_xcode_version_le(maj, min) \
    (__coverity_assume_xcode__ && \
     __cov_comp_clang_native_ver((maj), (min), <=))
#define __cov_xcode_version_ge(maj, min) \
    (__coverity_assume_xcode__ && \
     __cov_comp_clang_native_ver((maj), (min), >=))


/* Clang 14 removes ia32 builtins and replaces them with elsewise suffix
 * This causes older versions of clang to have builtin mismatch unless
 * we provide acceptable prototypes. */
#if (__coverity_clang_major__ < 14)
/* Internal data types for implementing the intrinsics.  */
typedef int __cov_v2si __attribute__ ((__vector_size__ (8)));
typedef short __cov_v4hi __attribute__ ((__vector_size__ (8)));
typedef char __cov_v8qi __attribute__ ((__vector_size__ (8)));
typedef long long __cov_v1di __attribute__ ((__vector_size__ (8)));
typedef char __cov_v64qi __attribute__((__vector_size__(64)));
typedef double __cov_m512d __attribute__((__vector_size__(64), __may_alias__));
typedef float __cov_m512 __attribute__((__vector_size__(64), __may_alias__));
typedef int __cov_v16si __attribute__((__vector_size__(64)));
typedef long long __cov_m512i __attribute__((__vector_size__(64), __may_alias__));
typedef long long __cov_v8di __attribute__((__vector_size__(64)));
typedef short __cov_v32hi __attribute__((__vector_size__(64)));
typedef unsigned char __cov_mmask8;
typedef unsigned short __cov_mmask16;
typedef unsigned long __cov_mmask32;
typedef unsigned long long __cov_mmask64;

/* The Intel API is flexible enough that we must allow aliasing with other
vector types, and their scalar components.  */
typedef float __cov_m128 __attribute__ ((__vector_size__ (16), __may_alias__));
/* Internal data types for implementing the intrinsics.  */
typedef int __cov_v4si __attribute__ ((__vector_size__ (16)));
typedef float __cov_v2sf __attribute__ ((__vector_size__ (8)));

/* SSE2 */
typedef long long __cov_v2di __attribute__ ((__vector_size__ (16)));
typedef short __cov_v8hi __attribute__ ((__vector_size__ (16)));
typedef char __cov_v16qi __attribute__ ((__vector_size__ (16)));

/* The Intel API is flexible enough that we must allow aliasing with other
vector types, and their scalar components.  */
typedef long long __cov_m128i __attribute__ ((__vector_size__ (16), __may_alias__));
typedef double __cov_m128d __attribute__ ((__vector_size__ (16), __may_alias__));

typedef long long  __cov_v4di  __attribute__ ((__vector_size__ (32)));
typedef int        __cov_v8si  __attribute__ ((__vector_size__ (32)));
typedef short      __cov_v16hi __attribute__ ((__vector_size__ (32)));
typedef char       __cov_v32qi __attribute__ ((__vector_size__ (32)));
typedef float      __cov_m256  __attribute__ ((__vector_size__ (32),
                                              __may_alias__));
typedef long long  __cov_m256i __attribute__ ((__vector_size__ (32),
                                               __may_alias__));
typedef double     __cov_m256d __attribute__ ((__vector_size__ (32),
                                               __may_alias__));

__cov_v16qi __builtin_ia32_pmaxub128 (__cov_v16qi, __cov_v16qi);
__cov_v8hi __builtin_ia32_pmaxsw128 (__cov_v8hi, __cov_v8hi);
__cov_v16qi __builtin_ia32_pminub128 (__cov_v16qi, __cov_v16qi);
__cov_v8hi __builtin_ia32_pminsw128 (__cov_v8hi, __cov_v8hi);
__cov_v16qi __builtin_ia32_pmaxsb128 (__cov_v16qi, __cov_v16qi);
__cov_v4si __builtin_ia32_pmaxsd128 (__cov_v4si, __cov_v4si);
__cov_v4si __builtin_ia32_pmaxud128 (__cov_v4si, __cov_v4si);
__cov_v8hi __builtin_ia32_pmaxuw128 (__cov_v8hi, __cov_v8hi);
__cov_v16qi __builtin_ia32_pminsb128 (__cov_v16qi, __cov_v16qi);
__cov_v4si __builtin_ia32_pminsd128 (__cov_v4si, __cov_v4si);
__cov_v4si __builtin_ia32_pminud128 (__cov_v4si, __cov_v4si);
__cov_v8hi __builtin_ia32_pminuw128 (__cov_v8hi, __cov_v8hi);
__cov_v32qi __builtin_ia32_pmaxsb256(__cov_v32qi,__cov_v32qi);
__cov_v16hi __builtin_ia32_pmaxsw256(__cov_v16hi,__cov_v16hi);
__cov_v8si __builtin_ia32_pmaxsd256(__cov_v8si,__cov_v8si);
__cov_v32qi __builtin_ia32_pmaxub256(__cov_v32qi,__cov_v32qi);
__cov_v16hi __builtin_ia32_pmaxuw256(__cov_v16hi,__cov_v16hi);
__cov_v8si __builtin_ia32_pmaxud256(__cov_v8si,__cov_v8si);
__cov_v32qi __builtin_ia32_pminsb256(__cov_v32qi,__cov_v32qi);
__cov_v16hi __builtin_ia32_pminsw256(__cov_v16hi,__cov_v16hi);
__cov_v8si __builtin_ia32_pminsd256(__cov_v8si,__cov_v8si);
__cov_v32qi __builtin_ia32_pminub256(__cov_v32qi,__cov_v32qi);
__cov_v16hi __builtin_ia32_pminuw256(__cov_v16hi,__cov_v16hi);
__cov_v8si __builtin_ia32_pminud256(__cov_v8si,__cov_v8si);
__cov_v2di __builtin_ia32_pmaxsq128(__cov_v2di,__cov_v2di);
__cov_v2di __builtin_ia32_pmaxuq128(__cov_v2di,__cov_v2di);
__cov_v2di __builtin_ia32_pminsq128(__cov_v2di,__cov_v2di);
__cov_v2di __builtin_ia32_pminuq128(__cov_v2di,__cov_v2di);
__cov_v4di __builtin_ia32_pmaxsq256(__cov_v4di,__cov_v4di);
__cov_v4di __builtin_ia32_pmaxuq256(__cov_v4di,__cov_v4di);
__cov_v4di __builtin_ia32_pminsq256(__cov_v4di,__cov_v4di);
__cov_v4di __builtin_ia32_pminuq256(__cov_v4di,__cov_v4di);

__cov_v64qi __builtin_ia32_pmaxsb512(__cov_v64qi,__cov_v64qi);
__cov_v64qi __builtin_ia32_pmaxub512(__cov_v64qi,__cov_v64qi);
__cov_v64qi __builtin_ia32_pminsb512(__cov_v64qi,__cov_v64qi);
__cov_v64qi __builtin_ia32_pminub512(__cov_v64qi,__cov_v64qi);
__cov_v32hi __builtin_ia32_pmaxsw512(__cov_v32hi,__cov_v32hi);
__cov_v32hi __builtin_ia32_pmaxuw512(__cov_v32hi,__cov_v32hi);
__cov_v32hi __builtin_ia32_pminsw512(__cov_v32hi,__cov_v32hi);
__cov_v32hi __builtin_ia32_pminuw512(__cov_v32hi,__cov_v32hi);

__cov_m512i __builtin_ia32_pmaxsd512(__cov_v16si,__cov_v16si);
__cov_m512i __builtin_ia32_pmaxsq512(__cov_v8di,__cov_v8di);
__cov_m512i __builtin_ia32_pmaxud512(__cov_v16si,__cov_v16si);
__cov_m512i __builtin_ia32_pmaxuq512(__cov_v8di,__cov_v8di);
__cov_m512i __builtin_ia32_pminsd512(__cov_v16si,__cov_v16si);
__cov_m512i __builtin_ia32_pminsq512(__cov_v8di,__cov_v8di);
__cov_m512i __builtin_ia32_pminud512(__cov_v16si,__cov_v16si);
__cov_m512i __builtin_ia32_pminuq512(__cov_v8di,__cov_v8di);

__cov_v16qi __builtin_ia32_pabsb128 (__cov_v16qi);
__cov_v4si __builtin_ia32_pabsd128 (__cov_v4si);
__cov_v8hi __builtin_ia32_pabsw128 (__cov_v8hi);
__cov_v2di __builtin_ia32_pabsq128 (__cov_v2di);

__cov_v32qi __builtin_ia32_pabsb256(__cov_v32qi);
__cov_v16hi __builtin_ia32_pabsw256(__cov_v16hi);
__cov_v8si __builtin_ia32_pabsd256(__cov_v8si);
__cov_v4di __builtin_ia32_pabsq256(__cov_v4di);

__cov_m512i __builtin_ia32_pabsd512(__cov_v16si);
__cov_m512i __builtin_ia32_pabsq512(__cov_v8di);
__cov_v64qi __builtin_ia32_pabsb512(__cov_v64qi);
__cov_v32hi __builtin_ia32_pabsw512(__cov_v32hi);

extern int __builtin_ia32_reduce_and_d512(__cov_m512i);
extern long long __builtin_ia32_reduce_and_q512(__cov_m512i);
extern int __builtin_ia32_reduce_or_d512(__cov_m512i);
extern long long __builtin_ia32_reduce_or_q512(__cov_m512i);
extern int __builtin_ia32_reduce_smax_d512(__cov_m512i);
extern long long __builtin_ia32_reduce_smax_q512(__cov_m512i);
extern int __builtin_ia32_reduce_smin_d512(__cov_m512i);
extern long long __builtin_ia32_reduce_smin_q512(__cov_m512i);
extern unsigned int  __builtin_ia32_reduce_umax_d512(__cov_m512i);
extern unsigned long long __builtin_ia32_reduce_umax_q512(__cov_m512i);
extern unsigned int __builtin_ia32_reduce_umin_d512(__cov_m512i);
extern unsigned long long __builtin_ia32_reduce_umin_q512(__cov_m512i);
#endif


/*
 * These types are used for builtins whose prototypes
 * depend on the C++ bool or size_t constructs, which
 * aren't normally available in C.
 */
#define __cov_compat_bool __typeof(1==1)
#define __cov_compat_size_t __typeof(sizeof(0))
#define __cov_compat_wchar_t __typeof(L'\0')

/*
  The following builtins were never present in any LLVM Clang release, but
  did appear briefly in the LLVM Clang source code.  They are added here
  for compatibility with other Clang releases such as for the PS4.
*/
/* Removed in revision 110771 { */
extern signed int __attribute__((vector_size(32)))
__coverity__builtin_ia32_si256_si(
    signed int __attribute__((vector_size(16))));
#define __builtin_ia32_si256_si(P1) \
    __coverity__builtin_ia32_si256_si((P1))

extern float __attribute__((vector_size(32)))
__coverity__builtin_ia32_ps256_ps(
    float __attribute__((vector_size(16))));
#define __builtin_ia32_ps256_ps(P1) \
    __coverity__builtin_ia32_ps256_ps((P1))

extern double __attribute__((vector_size(32)))
__coverity__builtin_ia32_pd256_pd(
    double __attribute__((vector_size(16))));
#define __builtin_ia32_pd256_pd(P1) \
    __coverity__builtin_ia32_pd256_pd((P1))

extern signed int __attribute__((vector_size(16)))
__coverity__builtin_ia32_si_si256(
    signed int __attribute__((vector_size(32))));
#define __builtin_ia32_si_si256(P1) \
    __coverity__builtin_ia32_si_si256((P1))

extern float __attribute__((vector_size(16)))
__coverity__builtin_ia32_ps_ps256(
    float __attribute__((vector_size(32))));
#define __builtin_ia32_ps_ps256(P1) \
    __coverity__builtin_ia32_ps_ps256((P1))

extern double __attribute__((vector_size(16)))
__coverity__builtin_ia32_pd_pd256(
    double __attribute__((vector_size(32))));
#define __builtin_ia32_pd_pd256(P1) \
    __coverity__builtin_ia32_pd_pd256((P1))
/* } Removed in revision 110771 */


/*************************************
 ************* CLANG 3.0 *************
 *************************************/

/*
 * This was removed in revision 131300 in clang 3.0, but
 * some vendors still include it.
 */
#if __cov_clang_version_le(3,0) /* { */

extern char __attribute__((vector_size(16)))
__coverity__builtin_ia32_loaddqu(const char *);
#define __builtin_ia32_loaddqu(P1) \
    __coverity__builtin_ia32_loaddqu((P1))

#endif /* } clang <= 3.0 */

/* The following builtins were present in Clang 2.9, but removed in Clang 3.0 */
#if __cov_clang_version_lt(3, 0) /* { */

/* Removed in revision 131300 { */

extern float __attribute__((vector_size(16)))
__coverity__builtin_ia32_loadups(const float *);
#define __builtin_ia32_loadups(P1) \
    __coverity__builtin_ia32_loadups((P1))

extern double __attribute__((vector_size(16)))
__coverity__builtin_ia32_loadupd(const double *);
#define __builtin_ia32_loadupd(P1) \
    __coverity__builtin_ia32_loadupd((P1))

/* } Removed in revision 131300 */

#endif /* } clang < 3.0 */


/*************************************
 ************* CLANG 3.1 *************
 *************************************/

/* The following builtins were present in Clang 3.0, but removed in Clang 3.1 */
#if __cov_clang_version_le(3, 0) /* { */

/* Removed in revision 154579 { */
#define __atomic_compare_exchange_strong(P1, P2, P3, P4, P5) \
    __c11_atomic_compare_exchange_strong((P1), (P2), (P3), (P4), (P5))

#define __atomic_compare_exchange_weak(P1, P2, P3, P4, P5) \
    __c11_atomic_compare_exchange_weak((P1), (P2), (P3), (P4), (P5))
/* } Removed in revision 154579 */

/* Removed in revision 148919 { */
extern long long __attribute__((__vector_size__(32)))
__coverity__builtin_ia32_loaddqu256(const char *p);
#define __builtin_ia32_loaddqu256(P1) \
    __coverity__builtin_ia32_loaddqu256((P1))

extern double __attribute__((__vector_size__(32)))
__coverity__builtin_ia32_loadupd256(const double *p);
#define __builtin_ia32_loadupd256(P1) \
    __coverity__builtin_ia32_loadupd256((P1))

extern float __attribute__((__vector_size__(32)))
__coverity__builtin_ia32_loadups256(const float *p);
#define __builtin_ia32_loadups256(P1) \
    __coverity__builtin_ia32_loadups256((P1))
/* } Removed in revision 148919 */

/* Removed in revision 146969 { */
extern char __attribute__((vector_size(16)))
__coverity__builtin_ia32_pcmpeqb128(
    char __attribute__((vector_size(16))) p1,
    char __attribute__((vector_size(16))) p2);
#define __builtin_ia32_pcmpeqb128(P1, P2) \
    __coverity__builtin_ia32_pcmpeqb128((P1), (P2))

extern signed int __attribute__((vector_size(16)))
__coverity__builtin_ia32_pcmpeqd128(
    signed int __attribute__((vector_size(16))) p1,
    signed int __attribute__((vector_size(16))) p2);
#define __builtin_ia32_pcmpeqd128(P1, P2) \
    __coverity__builtin_ia32_pcmpeqd128((P1), (P2))

extern signed short __attribute__((vector_size(16)))
__coverity__builtin_ia32_pcmpeqw128(
    signed short __attribute__((vector_size(16))) p1,
    signed short __attribute__((vector_size(16))) p2);
#define __builtin_ia32_pcmpeqw128(P1, P2) \
    __coverity__builtin_ia32_pcmpeqw128((P1), (P2))

extern char __attribute__((vector_size(16)))
__coverity__builtin_ia32_pcmpgtb128(
    char __attribute__((vector_size(16))) p1,
    char __attribute__((vector_size(16))) p2);
#define __builtin_ia32_pcmpgtb128(P1,P2) \
    __coverity__builtin_ia32_pcmpgtb128((P1), (P2))

extern signed int __attribute__((vector_size(16)))
__coverity__builtin_ia32_pcmpgtd128(
    signed int __attribute__((vector_size(16))) p1,
    signed int __attribute__((vector_size(16))) p2);
#define __builtin_ia32_pcmpgtd128(P1, P2) \
    __coverity__builtin_ia32_pcmpgtd128((P1), (P2))

extern signed short __attribute__((vector_size(16)))
__coverity__builtin_ia32_pcmpgtw128(
    signed short __attribute__((vector_size(16))) p1,
    signed short __attribute__((vector_size(16))) p2);
#define __builtin_ia32_pcmpgtw128(P1, P2) \
    __coverity__builtin_ia32_pcmpgtw128((P1), (P2))

extern long long __attribute__((__vector_size__(16)))
__coverity__builtin_ia32_pcmpeqq(
    long long __attribute__((__vector_size__(16))) p1,
    long long __attribute__((__vector_size__(16))) p2);
#define __builtin_ia32_pcmpeqq(P1, P2) \
    __coverity__builtin_ia32_pcmpeqq((P1), (P2))

extern long long __attribute__((__vector_size__(16)))
__coverity__builtin_ia32_pcmpgtq(
    long long __attribute__((__vector_size__(16))) p1,
    long long __attribute__((__vector_size__(16))) p2);
#define __builtin_ia32_pcmpgtq(P1, P2) \
    __coverity__builtin_ia32_pcmpgtq((P1), (P2))
/* } Removed in revision 146969 */

/* Removed in revision 144073 { */
extern int
__coverity__builtin_ia32_pcmpestria128(
    char __attribute__((vector_size(16))) p1,
    int p2,
    char __attribute__((vector_size(16))) p3,
    int p4,
    char p5);
#define __builtin_ia32_pcmpestria128(P1, P2, P3, P4, P5) \
    __coverity__builtin_ia32_pcmpestria128((P1), (P2), (P3), (P4), (P5))

extern int
__coverity__builtin_ia32_pcmpestric128(
    char __attribute__((vector_size(16))) p1,
    int p2,
    char __attribute__((vector_size(16))) p3,
    int p4,
    char p5);
#define __builtin_ia32_pcmpestric128(P1, P2, P3, P4, P5) \
    __coverity__builtin_ia32_pcmpestric128((P1), (P2), (P3), (P4), (P5))

extern int
__coverity__builtin_ia32_pcmpestrio128(
    char __attribute__((vector_size(16))) p1,
    int p2,
    char __attribute__((vector_size(16))) p3,
    int p4,
    char p5);
#define __builtin_ia32_pcmpestrio128(P1, P2, P3, P4, P5) \
    __coverity__builtin_ia32_pcmpestrio128((P1), (P2), (P3), (P4), (P5))

extern int
__coverity__builtin_ia32_pcmpestris128(
    char __attribute__((vector_size(16))) p1,
    int p2,
    char __attribute__((vector_size(16))) p3,
    int p4,
    char p5);
#define __builtin_ia32_pcmpestris128(P1, P2, P3, P4, P5) \
    __coverity__builtin_ia32_pcmpestris128((P1), (P2), (P3), (P4), (P5))

extern int
__coverity__builtin_ia32_pcmpestriz128(
    char __attribute__((vector_size(16))) p1,
    int p2,
    char __attribute__((vector_size(16))) p3,
    int p4,
    char p5);
#define __builtin_ia32_pcmpestriz128(P1, P2, P3, P4, P5) \
    __coverity__builtin_ia32_pcmpestriz128((P1), (P2), (P3), (P4), (P5))

extern int
__coverity__builtin_ia32_pcmpistria128(
    char __attribute__((vector_size(16))) p1,
    int p2,
    char __attribute__((vector_size(16))) p3,
    int p4,
    char p5);
#define __builtin_ia32_pcmpistria128(P1, P2, P3, P4, P5) \
    __coverity__builtin_ia32_pcmpistria128((P1), (P2), (P3), (P4), (P5))

extern int
__coverity__builtin_ia32_pcmpistric128(
    char __attribute__((vector_size(16))) p1,
    int p2,
    char __attribute__((vector_size(16))) p3,
    int p4,
    char p5);
#define __builtin_ia32_pcmpistric128(P1, P2, P3, P4, P5) \
    __coverity__builtin_ia32_pcmpistric128((P1), (P2), (P3), (P4), (P5))

extern int
__coverity__builtin_ia32_pcmpistrio128(
    char __attribute__((vector_size(16))) p1,
    int p2,
    char __attribute__((vector_size(16))) p3,
    int p4,
    char p5);
#define __builtin_ia32_pcmpistrio128(P1, P2, P3, P4, P5) \
    __coverity__builtin_ia32_pcmpistrio128((P1), (P2), (P3), (P4), (P5))

extern int
__coverity__builtin_ia32_pcmpistris128(
    char __attribute__((vector_size(16))) p1,
    int p2,
    char __attribute__((vector_size(16))) p3,
    int p4,
    char p5);
#define __builtin_ia32_pcmpistris128(P1, P2, P3, P4, P5) \
    __coverity__builtin_ia32_pcmpistris128((P1), (P2), (P3), (P4), (P5))

extern int
__coverity__builtin_ia32_pcmpistriz128(
    char __attribute__((vector_size(16))) p1,
    int p2,
    char __attribute__((vector_size(16))) p3,
    int p4,
    char p5);
#define __builtin_ia32_pcmpistriz128(P1, P2, P3, P4, P5) \
    __coverity__builtin_ia32_pcmpistriz128((P1), (P2), (P3), (P4), (P5))

/* } Removed in revision 144073 */

/* Removed in revision 149233 { */
extern float __attribute__((vector_size(8)))
__coverity__builtin_ia32_pfrsqrtit1(
    float __attribute__((vector_size(8))) p1,
    float __attribute__((vector_size(8))) p2);
#define __builtin_ia32_pfrsqrtit1(P1, P2) \
    __coverity__builtin_ia32_pfrsqrtit1((P1), (P2))
/* } Removed in revision 149233 */

/* Removed in revision 150056 { */
extern double __attribute__((vector_size(16)))
__coverity__builtin_ia32_vpermilpd(
    double __attribute__((vector_size(16))) p1,
    char c);
#define __builtin_ia32_vpermilpd(P1, P2) \
    __coverity__builtin_ia32_vpermilpd((P1), (P2))

extern float __attribute__((vector_size(16)))
__coverity__builtin_ia32_vpermilps(
    float __attribute__((vector_size(16))) p1,
    char c);
#define __builtin_ia32_vpermilps(P1, P2) \
    __coverity__builtin_ia32_vpermilps((P1), (P2))

extern double __attribute__((vector_size(32)))
__coverity__builtin_ia32_vpermilpd256(
    double __attribute__((vector_size(32))) p1,
    char c);
#define __builtin_ia32_vpermilpd256(P1, P2) \
    __coverity__builtin_ia32_vpermilpd256((P1), (P2))

extern float __attribute__((vector_size(32)))
__coverity__builtin_ia32_vpermilps256(
    float __attribute__((vector_size(32))) p1,
    char c);
#define __builtin_ia32_vpermilps256(P1, P2) \
    __coverity__builtin_ia32_vpermilps256((P1), (P2))
/* } Removed in revision 150056 */

/* The final argument to these was changed to be a constexpr some time between
 * release 3.0 and 3.1, but smmintrin.h prior to 3.1 uses a const function
 * parameter.
 * { */

extern double __attribute__((vector_size(16)))
__coverity__builtin_ia32_blendpd(
    double __attribute__((vector_size(16))),
    double __attribute__((vector_size(16))),
    const int);
#define __builtin_ia32_blendpd(P1, P2, P3) \
    __coverity__builtin_ia32_blendpd((P1), (P2), (P3))

extern float __attribute__((vector_size(16)))
__coverity__builtin_ia32_blendps(
    float __attribute__((vector_size(16))),
    float __attribute__((vector_size(16))),
    const int);
#define __builtin_ia32_blendps(P1, P2, P3) \
    __coverity__builtin_ia32_blendps((P1), (P2), (P3))

extern short __attribute__((vector_size(16)))
__coverity__builtin_ia32_pblendw128(
    short __attribute__((vector_size(16))),
    short __attribute__((vector_size(16))),
    const int);
#define __builtin_ia32_pblendw128(P1, P2, P3) \
    __coverity__builtin_ia32_pblendw128((P1), (P2), (P3))

/* } Changed to take a constexpr arg. */

#endif /* } clang <= 3.0 */

/*
 * Clang 3.0 and earlier do not diagnose calls to the following builtins that
 * pass non-constant expressions where constant expressions are required.
 * Clang 3.1 and later do.  The following compatibility signatures are present
 * to enable compilation of Clang 3.0 provided headers.
 */
#if __cov_clang_version_le(3, 0) /* { */

// Signature: "V4dV4dIi"
extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_roundpd256(
    double __attribute__((vector_size(32))) p0,
    int p1);
#define __builtin_ia32_roundpd256(P0, P1) \
    __coverity___builtin_ia32_roundpd256((P0), (P1))

// Signature: "V8fV8fIi"
extern float __attribute__((vector_size(32)))
__coverity___builtin_ia32_roundps256(
    float __attribute__((vector_size(32))) p0,
    int p1);
#define __builtin_ia32_roundps256(P0, P1) \
    __coverity___builtin_ia32_roundps256((P0), (P1))

// Signature: "V4dV4dV4dIc"
extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_vperm2f128_pd256(
    double __attribute__((vector_size(32))) p0,
    double __attribute__((vector_size(32))) p1,
    char p2);
#define __builtin_ia32_vperm2f128_pd256(P0, P1, P2) \
    __coverity___builtin_ia32_vperm2f128_pd256((P0), (P1), (P2))

// Signature: "V8fV8fV8fIc"
extern float __attribute__((vector_size(32)))
__coverity___builtin_ia32_vperm2f128_ps256(
    float __attribute__((vector_size(32))) p0,
    float __attribute__((vector_size(32))) p1,
    char p2);
#define __builtin_ia32_vperm2f128_ps256(P0, P1, P2) \
    __coverity___builtin_ia32_vperm2f128_ps256((P0), (P1), (P2))

// Signature: "V8iV8iV8iIc"
extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_vperm2f128_si256(
    long long __attribute__((vector_size(32))) p0,
    long long __attribute__((vector_size(32))) p1,
    char p2);
#define __builtin_ia32_vperm2f128_si256(P0, P1, P2) \
    __coverity___builtin_ia32_vperm2f128_si256((P0), (P1), (P2))

#endif /* } clang <= 3.0 */


/*************************************
 ************* CLANG 3.2 *************
 *************************************/

/* The following builtins were present in Clang 3.1, but removed in Clang 3.2 */
#if __cov_clang_version_le(3,1) /* { */

/* Removed in revision 156630 { */
extern long long
__coverity__builtin_A2_addpsat(long long p1, long long p2);
#define __builtin_A2_addpsat(P1, P2) \
    __coverity__builtin_A2_addpsat((P1), (P2))

extern long long
__coverity__builtin_A2_addsp(int p1, long long p2);
#define __builtin_A2_addsp(P1, P2) \
    __coverity__builtin_A2_addsp((P1), (P2))

extern long long
__coverity__builtin_A2_maxp(long long p1, long long p2);
#define __builtin_A2_maxp(P1, P2) \
    __coverity__builtin_A2_maxp((P1), (P2))

extern long long
__coverity__builtin_A2_maxup(long long p1, long long p2);
#define __builtin_A2_maxup(P1, P2) \
    __coverity__builtin_A2_maxup((P1), (P2))

extern int
__coverity__builtin_M2_vradduh(long long p1, long long p2);
#define __builtin_M2_vradduh(P1, P2) \
    __coverity__builtin_M2_vradduh((P1), (P2))

extern long long
__coverity__builtin_M2_vrcmpys_acc_s1(long long p1, long long p2, int p3);
#define __builtin_M2_vrcmpys_acc_s1(P1, P2, P3) \
    __coverity__builtin_M2_vrcmpys_acc_s1((P1), (P2), (P3))

extern long long
__coverity__builtin_M2_vrcmpys_s1(long long p1, int p2);
#define __builtin_M2_vrcmpys_s1(P1, P2) \
    __coverity__builtin_M2_vrcmpys_s1((P1), (P2))

extern int
__coverity__builtin_M2_vrcmpys_s1rp(long long p1, int p2);
#define __builtin_M2_vrcmpys_s1rp(P1, P2) \
    __coverity__builtin_M2_vrcmpys_s1rp((P1), (P2))
/* } Removed in revision 156630 */

/* Removed in revision 155924 { */
extern void
__coverity__builtin_ia32_storelv4si(
    signed int __attribute__((vector_size(8))) *p1,
    signed long long __attribute__((vector_size(16))) p2);
#define __builtin_ia32_storelv4si(P1, P2) \
    __coverity__builtin_ia32_storelv4si((P1), (P2))
/* } Removed in revision 155924 */

#endif /* } clang <= 3.1 */


/* No builtins present in Clang 3.2 were removed in Clang 3.3 */

/*************************************
 ************* CLANG 3.4 *************
 *************************************/

/* The following builtins were present in Clang 3.3, but removed in Clang 3.4 */
#if __cov_clang_version_le(3, 3) /* { */

/* Modified in revision 188609. The argument was changed from V2LLiC* to
 * V2LLi.
 * { */

extern long long int __attribute__((vector_size(32)))
__coverity__builtin_ia32_vbroadcastsi256(
    const long long int __attribute__((vector_size(16))) *);
#define __builtin_ia32_vbroadcastsi256(P1) \
    __coverity__builtin_ia32_vbroadcastsi256((P1))

/* } Modified in revision 188609. */

#endif /* } clang <= 3.3 */

/*************************************
 *** APPLE/LLVM divergent section ****
 *************************************/

// For Clang versions above LLVM Clang 3.4, we must treat Apple Clang derivatives
// of those versions separately, because Apple Clang uses hybridized versions of the
// LLVM Clang compiler.  Once Apple Clang and LLVM Clang have their own headers
// (bug 83552), each builtin definition should only appear once in each header.

// While most of the definitions below are contingent on Apple Clang versions,
// some of them are contingent on LLVM Clang versions if referring to older
// LLVM Clang versions that are used with those particular builtin signatures
// earlier in this header file.

#if __coverity_assume_xcode__


/*************************************
 ******** APPLE CLANG 6.0-6.2 ********
 *************************************/

// builtin signatures required for emulating Apple Clang 6.0
#if __cov_xcode_version_le(6, 0) /* { */

extern float __attribute__((__vector_size__(16)))
__coverity__builtin_ia32_vbroadcastss(float const *__a);
#define __builtin_ia32_vbroadcastss(P1) \
    __coverity__builtin_ia32_vbroadcastss((P1))

extern float __attribute__((__vector_size__(32)))
__coverity__builtin_ia32_vbroadcastss256(float const *__a);
#define __builtin_ia32_vbroadcastss256(P1) \
    __coverity__builtin_ia32_vbroadcastss256((P1))

extern double __attribute__((__vector_size__(32)))
__coverity__builtin_ia32_vbroadcastsd256(double const *__a);
#define __builtin_ia32_vbroadcastsd256(P1) \
    __coverity__builtin_ia32_vbroadcastsd256((P1))
#endif /* } xcode <= 6.0 */


/* The following builtins were present in Apple Clang 5, but their signatures
   were changed in Apple Clang 6.3.  These signatures are required for emulating
   pre-6.3 Apple Clang. */
#if __cov_xcode_version_le(6, 2) /* { */

extern char __attribute__((__vector_size__(16)))
__coverity__builtin_msa_sld_b(char __attribute__((__vector_size__(16))) __a, unsigned int __b);
#define __builtin_msa_sld_b(P1, P2) \
    __coverity__builtin_msa_sld_b((P1), (P2))

extern long long int __attribute__((__vector_size__(16)))
__coverity__builtin_msa_sld_d(long long int __attribute__((__vector_size__(16))) __a, unsigned int __b);
#define __builtin_msa_sld_d(P1, P2) \
    __coverity__builtin_msa_sld_d((P1), (P2))

extern short __attribute__((__vector_size__(16)))
__coverity__builtin_msa_sld_h(short __attribute__((__vector_size__(16))) __a, unsigned int __b);
#define __builtin_msa_sld_h(P1, P2) \
    __coverity__builtin_msa_sld_h((P1), (P2))

extern int __attribute__((__vector_size__(16)))
__coverity__builtin_msa_sld_w(int __attribute__((__vector_size__(16))) __a, unsigned int __b);
#define __builtin_msa_sld_w(P1, P2) \
    __coverity__builtin_msa_sld_w((P1), (P2))

extern char __attribute__((__vector_size__(16)))
__coverity__builtin_msa_sldi_b(char __attribute__((__vector_size__(16))) __a, unsigned int __b);
#define __builtin_msa_sldi_b(P1, P2) \
    __coverity__builtin_msa_sldi_b((P1), (P2))

extern long long int __attribute__((__vector_size__(16)))
__coverity__builtin_msa_sldi_d(long long int __attribute__((__vector_size__(16))) __a, unsigned int __b);
#define __builtin_msa_sldi_d(P1, P2) \
    __coverity__builtin_msa_sldi_d((P1), (P2))

extern short __attribute__((__vector_size__(16)))
__coverity__builtin_msa_sldi_h(short __attribute__((__vector_size__(16))) __a, unsigned int __b);
#define __builtin_msa_sldi_h(P1, P2) \
    __coverity__builtin_msa_sldi_h((P1), (P2))

extern int __attribute__((__vector_size__(16)))
__coverity__builtin_msa_sldi_w(int __attribute__((__vector_size__(16))) __a, unsigned int __b);
#define __builtin_msa_sldi_w(P1, P2) \
    __coverity__builtin_msa_sldi_w((P1), (P2))

extern float __attribute__((__vector_size__(8)))
__coverity__builtin_neon_vcvt_f32_f64(short __attribute__((__vector_size__(16))) __a, unsigned int __b);
#define __builtin_neon_vcvt_f32_f64(P1, P2) \
    __coverity__builtin_neon_vcvt_f32_f64((P1), (P2))

#endif /* } xcode <= 6.2 */


/*************************************
 ****** APPLE CLANG 6.3 & 6.4 ********
 *************************************/

// No builtins present in Apple Clang 6.2 were removed in Apple Clang 6.3 or 6.4

/* These builtins had parameters added in Apple Clang 6.4.  The definitions
   that follow emulate the versions that existed in 6.3 and earlier. */
#if __cov_xcode_version_le(6, 3) /* { */

extern double __coverity__builtin_amdgpu_div_fmas(double __a, double __b, double __C);
#define __builtin_amdgpu_div_fmas(P1, P2, P3) \
    __coverity__builtin_amdgpu_div_fmas((P1), (P2), (P3))

extern float __coverity__builtin_amdgpu_div_fmasf(float __a, float __b, float __C);
#define __builtin_amdgpu_div_fmasf(P1, P2, P3) \
    __coverity__builtin_amdgpu_div_fmasf((P1), (P2), (P3))

extern double __coverity__nvvm_add_rm_d(double __a);
#define __nvvm_add_rm_d(P1) __coverity__nvvm_add_rm_d((P1))

extern float __coverity__nvvm_add_rm_f(float __a);
#define __nvvm_add_rm_f(P1) __coverity__nvvm_add_rm_f((P1))

extern float __coverity__nvvm_add_rm_ftz_f(float __a);
#define __nvvm_add_rm_ftz_f(P1) __coverity__nvvm_add_rm_ftz_f((P1))

extern double __coverity__nvvm_add_rn_d(double __a);
#define __nvvm_add_rn_d(P1) __coverity__nvvm_add_rn_d((P1))

extern float __coverity__nvvm_add_rn_f(float __a);
#define __nvvm_add_rn_f(P1) __coverity__nvvm_add_rn_f((P1))

extern float __coverity__nvvm_add_rn_ftz_f(float __a);
#define __nvvm_add_rn_ftz_f(P1) __coverity__nvvm_add_rn_ftz_f((P1))

extern double __coverity__nvvm_add_rp_d(double __a);
#define __nvvm_add_rp_d(P1) __coverity__nvvm_add_rp_d((P1))

extern float __coverity__nvvm_add_rp_f(float __a);
#define __nvvm_add_rp_f(P1) __coverity__nvvm_add_rp_f((P1))

extern float __coverity__nvvm_add_rp_ftz_f(float __a);
#define __nvvm_add_rp_ftz_f(P1) __coverity__nvvm_add_rp_ftz_f((P1))

extern double __coverity__nvvm_add_rz_d(double __a);
#define __nvvm_add_rz_d(P1) __coverity__nvvm_add_rz_d((P1))

extern float __coverity__nvvm_add_rz_f(float __a);
#define __nvvm_add_rz_f(P1) __coverity__nvvm_add_rz_f((P1))

extern float __coverity__nvvm_add_rz_ftz_f(float __a);
#define __nvvm_add_rz_ftz_f(P1) __coverity__nvvm_add_rz_ftz_f((P1))

extern int __coverity__nvvm_sad_i(int __a, int __b);
#define __nvvm_add_sad_i(P1, P2) __coverity__nvvm_sad_i((P1), (P2))

extern unsigned int __coverity__nvvm_sad_ui(unsigned int __a, unsigned int __b);
#define __nvvm_add_sad_ui(P1, P2) __coverity__nvvm_sad_ui((P1), (P2))

/* The following definitions all changed in the last parameter from int to
 * const-reducing char in LLVM Clang 3.6.  These are all prototypes with that
 * last int.  Note that the first three also changed from 3.0 to 3.1., so
 * we can only define these for between LLVM Clang 3.1 and 3.5 (inclusive). */
#if    (__coverity_clang_major__ == 3 && __coverity_clang_minor__ >= 1) /* { */
extern double __attribute__((vector_size(16)))
__coverity__builtin_ia32_blendpd(
    double __attribute__((vector_size(16))),
    double __attribute__((vector_size(16))),
    int);
#define __builtin_ia32_blendpd(P1, P2, P3) \
    __coverity__builtin_ia32_blendpd((P1), (P2), (P3))

extern float __attribute__((vector_size(16)))
__coverity__builtin_ia32_blendps(
    float __attribute__((vector_size(16))),
    float __attribute__((vector_size(16))),
    int);
#define __builtin_ia32_blendps(P1, P2, P3) \
    __coverity__builtin_ia32_blendps((P1), (P2), (P3))

extern short __attribute__((vector_size(16)))
__coverity__builtin_ia32_pblendw128(
    short __attribute__((vector_size(16))),
    short __attribute__((vector_size(16))),
    int);
#define __builtin_ia32_pblendw128(P1, P2, P3) \
    __coverity__builtin_ia32_pblendw128((P1), (P2), (P3))

#endif /* (__coverity_clang_major__ == 3 && __coverity_clang_minor__ >= 1) } */

extern double __attribute__((vector_size(32)))
__coverity__builtin_ia32_blendpd256(
    double __attribute__((vector_size(32))),
    double __attribute__((vector_size(32))),
    int);
#define __builtin_ia32_blendpd256(P1, P2, P3) \
    __coverity__builtin_ia32_blendpd256((P1), (P2), (P3))

extern float __attribute__((vector_size(32)))
__coverity__builtin_ia32_blendps256(
    float __attribute__((vector_size(32))),
    float __attribute__((vector_size(32))),
    int);
#define __builtin_ia32_blendps256(P1, P2, P3) \
    __coverity__builtin_ia32_blendps256((P1), (P2), (P3))

extern double __attribute__((vector_size(16)))
__coverity__builtin_ia32_dppd(
    double __attribute__((vector_size(16))),
    double __attribute__((vector_size(16))),
    int);
#define __builtin_ia32_dppd(P1, P2, P3) \
    __coverity__builtin_ia32_dppd((P1), (P2), (P3))

extern float __attribute__((vector_size(16)))
__coverity__builtin_ia32_dpps(
    float __attribute__((vector_size(16))),
    float __attribute__((vector_size(16))),
    int);
#define __builtin_ia32_dpps(P1, P2, P3) \
    __coverity__builtin_ia32_dpps((P1), (P2), (P3))

extern float __attribute__((vector_size(32)))
__coverity__builtin_ia32_dpps256(
    float __attribute__((vector_size(32))),
    float __attribute__((vector_size(32))),
    int);
#define __builtin_ia32_dpps256(P1, P2, P3) \
    __coverity__builtin_ia32_dpps256((P1), (P2), (P3))

extern float __attribute__((vector_size(16)))
__coverity__builtin_ia32_insertps128(
    float __attribute__((vector_size(16))),
    float __attribute__((vector_size(16))),
    int);
#define __builtin_ia32_insertps128(P1, P2, P3) \
    __coverity__builtin_ia32_insertps128((P1), (P2), (P3))

extern char __attribute__((vector_size(16)))
__coverity__builtin_ia32_mpsadbw128(
    char __attribute__((vector_size(16))),
    char __attribute__((vector_size(16))),
    int);
#define __builtin_ia32_mpsadbw128(P1, P2, P3) \
    __coverity__builtin_ia32_mpsadbw128((P1), (P2), (P3))

extern char __attribute__((vector_size(32)))
__coverity__builtin_ia32_mpsadbw256(
    char __attribute__((vector_size(32))),
    char __attribute__((vector_size(32))),
    int);
#define __builtin_ia32_mpsadbw256(P1, P2, P3) \
    __coverity__builtin_ia32_mpsadbw256((P1), (P2), (P3))

extern int __attribute__((vector_size(16)))
__coverity__builtin_ia32_pblendd128(
    int __attribute__((vector_size(16))),
    int __attribute__((vector_size(16))),
    int);
#define __builtin_ia32_pblendd128(P1, P2, P3) \
    __coverity__builtin_ia32_pblendd128((P1), (P2), (P3))

extern int __attribute__((vector_size(32)))
__coverity__builtin_ia32_pblendd256(
    int __attribute__((vector_size(32))),
    int __attribute__((vector_size(32))),
    int);
#define __builtin_ia32_pblendd256(P1, P2, P3) \
    __coverity__builtin_ia32_pblendd256((P1), (P2), (P3))

extern short __attribute__((vector_size(32)))
__coverity__builtin_ia32_pblendw256(
    short __attribute__((vector_size(32))),
    short __attribute__((vector_size(32))),
    int);
#define __builtin_ia32_pblendw256(P1, P2, P3) \
    __coverity__builtin_ia32_pblendw256((P1), (P2), (P3))

#endif /* } xcode <= 6.3 */


/*************************************
 ********* APPLE CLANG 7.0 ***********
 *************************************/

/* The following builtins were present in Apple Clang 6.4, but removed
   in Apple Clang 7.0.  They're required to emulate pre-7.0 Apple Clang. */
#if __cov_xcode_version_lt(7, 0) /* { */


/* This changed in Apple Clang 5.1 but was removed in Apple Clang 7.0.
 * The pre-5.1 signature is defined further above, in common code that maps
 * the older definitions to pre-LLVM Clang 3.4.  This is the signature of the
 * intrinsic from Apple Clang 5.1 to 6.4. */
#if __cov_xcode_version_ge(5, 1) /* { */

extern long long int __attribute__((vector_size(32)))
__coverity__builtin_ia32_vbroadcastsi256(
    const long long int __attribute__((vector_size(16))));
#define __builtin_ia32_vbroadcastsi256(P1) \
    __coverity__builtin_ia32_vbroadcastsi256((P1))

#endif /* } xcode >= 5.1 */

/* The next eight also changed from Apple Clang 6.3 to 6.4, so we define
 * define these to emulate the 6.4 versions in Apple Clang version 7.0 */
#if __cov_xcode_version_ge(6, 4) /* { */

extern double __attribute__((vector_size(16)))
__coverity__builtin_ia32_blendpd(
    double __attribute__((vector_size(16))),
    double __attribute__((vector_size(16))),
    char);
#define __builtin_ia32_blendpd(P1, P2, P3) \
    __coverity__builtin_ia32_blendpd((P1), (P2), (P3))

extern float __attribute__((vector_size(16)))
__coverity__builtin_ia32_blendps(
    float __attribute__((vector_size(16))),
    float __attribute__((vector_size(16))),
    char);
#define __builtin_ia32_blendps(P1, P2, P3) \
    __coverity__builtin_ia32_blendps((P1), (P2), (P3))

extern double __attribute__((vector_size(32)))
__coverity__builtin_ia32_blendpd256(
    double __attribute__((vector_size(32))),
    double __attribute__((vector_size(32))),
    char);
#define __builtin_ia32_blendpd256(P1, P2, P3) \
    __coverity__builtin_ia32_blendpd256((P1), (P2), (P3))

extern float __attribute__((vector_size(32)))
__coverity__builtin_ia32_blendps256(
    float __attribute__((vector_size(32))),
    float __attribute__((vector_size(32))),
    char);
#define __builtin_ia32_blendps256(P1, P2, P3) \
    __coverity__builtin_ia32_blendps256((P1), (P2), (P3))

extern int __attribute__((vector_size(16)))
__coverity__builtin_ia32_pblendd128(
    int __attribute__((vector_size(16))),
    int __attribute__((vector_size(16))),
    char);
#define __builtin_ia32_pblendd128(P1, P2, P3) \
    __coverity__builtin_ia32_pblendd128((P1), (P2), (P3))

extern int __attribute__((vector_size(32)))
__coverity__builtin_ia32_pblendd256(
    int __attribute__((vector_size(32))),
    int __attribute__((vector_size(32))),
    char);
#define __builtin_ia32_pblendd256(P1, P2, P3) \
    __coverity__builtin_ia32_pblendd256((P1), (P2), (P3))

extern short __attribute__((vector_size(16)))
__coverity__builtin_ia32_pblendw128(
    short __attribute__((vector_size(16))),
    short __attribute__((vector_size(16))),
    char);
#define __builtin_ia32_pblendw128(P1, P2, P3) \
    __coverity__builtin_ia32_pblendw128((P1), (P2), (P3))

extern short __attribute__((vector_size(32)))
__coverity__builtin_ia32_pblendw256(
    short __attribute__((vector_size(32))),
    short __attribute__((vector_size(32))),
    char);
#define __builtin_ia32_pblendw256(P1, P2, P3) \
    __coverity__builtin_ia32_pblendw256((P1), (P2), (P3))

#endif /* } xcode >= 6.4 */

extern long long int __attribute__((vector_size(16)))
__coverity__builtin_ia32_pslldqi128(
    long long int __attribute__((vector_size(16))),
    int);
#define __builtin_ia32_pslldqi128(P1, P2) \
    __coverity__builtin_ia32_pslldqi128((P1), (P2))

extern long long int __attribute__((vector_size(16)))
__coverity__builtin_ia32_psrldqi128(
    long long int __attribute__((vector_size(16))),
    int);
#define __builtin_ia32_psrldqi128(P1, P2) \
    __coverity__builtin_ia32_pslldqi128((P1), (P2))

/* These builtins had parameters changed in Apple Clang 7.0.  The definitions
   that follow emulate the pre-7.0 versions. */

extern int __attribute__((vector_size(64)))
__coverity__builtin_ia32_alignd512_mask(
    int __attribute__((vector_size(64))),
    int __attribute__((vector_size(64))),
    unsigned char,
    int __attribute__((vector_size(64))),
    unsigned char);
#define __builtin_ia32_alignd512_mask(P1, P2, P3, P4, P5) \
    __coverity__builtin_ia32_alignd512_mask((P1), (P2), (P3), (P4), (P5))

extern long long int __attribute__((vector_size(64)))
__coverity__builtin_ia32_alignq512_mask(
    long long int __attribute__((vector_size(64))),
    long long int __attribute__((vector_size(64))),
    unsigned char,
    long long int __attribute__((vector_size(64))),
    unsigned char);
#define __builtin_ia32_alignq512_mask(P1, P2, P3, P4, P5) \
    __coverity__builtin_ia32_alignq512_mask((P1), (P2), (P3), (P4), (P5))

extern long long int __coverity__ldrexd(long long int*);
#define __ldrexd(P1) __coverity__ldrexd(P1)

#endif /* } xcode < 7.0 */

/* The extract and insert builtins were included in Apple Clang 7.0,
   even though they weren't included in LLVM Clang 3.7. */
#if __cov_xcode_version_le(7,1) /* { */
extern long long int __attribute__((vector_size(16)))
__coverity__builtin_ia32_extract128i256(
    long long int __attribute__((vector_size(32))),
    char);
#define __builtin_ia32_extract128i256(P1, P2) \
    __coverity__builtin_ia32_extract128i256((P1), (P2))

extern long long int __attribute__((vector_size(32)))
__coverity__builtin_ia32_insert128i256(
    long long int __attribute__((vector_size(32))),
    long long int __attribute__((vector_size(16))),
    char);
#define __builtin_ia32_insert128i256(P1, P2, P3) \
    __coverity__builtin_ia32_insert128i256((P1), (P2), (P3))

extern double __attribute__((vector_size(16)))
__coverity__builtin_ia32_vextractf128_pd256(
    double __attribute__((vector_size(32))),
    char);
#define __builtin_ia32_vextractf128_pd256(P1, P2) \
    __coverity__builtin_ia32_vextractf128_pd256((P1), (P2))

extern float __attribute__((vector_size(16)))
__coverity__builtin_ia32_vextractf128_ps256(
    float __attribute__((vector_size(32))),
    char);
#define __builtin_ia32_vextractf128_ps256(P1, P2) \
    __coverity__builtin_ia32_vextractf128_ps256((P1), (P2))

extern int __attribute__((vector_size(16)))
__coverity__builtin_ia32_vextractf128_si256(
    int __attribute__((vector_size(32))),
    char);
#define __builtin_ia32_vextractf128_si256(P1, P2) \
    __coverity__builtin_ia32_vextractf128_si256((P1), (P2))

extern double __attribute__((vector_size(32)))
__coverity__builtin_ia32_vinsertf128_pd256(
    double __attribute__((vector_size(32))),
    double __attribute__((vector_size(16))),
    char);
#define __builtin_ia32_vinsertf128_pd256(P1, P2, P3) \
    __coverity__builtin_ia32_vinsertf128_pd256((P1), (P2), (P3))

extern float __attribute__((vector_size(32)))
__coverity__builtin_ia32_vinsertf128_ps256(
    float __attribute__((vector_size(32))),
    float __attribute__((vector_size(16))),
    char);
#define __builtin_ia32_vinsertf128_ps256(P1, P2, P3) \
    __coverity__builtin_ia32_vinsertf128_ps256((P1), (P2), (P3))

extern int __attribute__((vector_size(32)))
__coverity__builtin_ia32_vinsertf128_si256(
    int __attribute__((vector_size(32))),
    int __attribute__((vector_size(16))),
    char);
#define __builtin_ia32_vinsertf128_si256(P1, P2, P3) \
    __coverity__builtin_ia32_vinsertf128_si256((P1), (P2), (P3))

extern double __attribute__((vector_size(64)))
__coverity__builtin_ia32_vfmsubpd512_mask(
    double __attribute__((vector_size(64))),
    double __attribute__((vector_size(64))),
    double __attribute__((vector_size(64))),
    unsigned char,
    int);
#define __builtin_ia32_vfmsubpd512_mask(P1, P2, P3, P4, P5) \
    __coverity__builtin_ia32_vfmsubpd512_mask((P1), (P2), (P3), (P4), (P5))

extern float __attribute__((vector_size(64)))
__coverity__builtin_ia32_vfmsubps512_mask(
    float __attribute__((vector_size(64))),
    float __attribute__((vector_size(64))),
    float __attribute__((vector_size(64))),
    unsigned short,
    int);
#define __builtin_ia32_vfmsubps512_mask(P1, P2, P3, P4, P5) \
    __coverity__builtin_ia32_vfmsubps512_mask((P1), (P2), (P3), (P4), (P5))

#endif /* } xcode <= 7.1 */


// There were no meaningful modifications to builtins from Apple Clang 10 to
// Apple Clang 11. Any modifications were handled during the Clang 9.0 upgrade.
#if __cov_xcode_version_le(11,0) /* { */
#endif /* } xcode <= 11.0 */

#else  // __coverity_assume_xcode__


// These are the LLVM Clang (non-Apple) definitions

/*************************************
 ************* CLANG 3.5 *************
 *************************************/

/* The following builtins were present in Clang 3.4, but removed in Clang 3.5 */
#if __cov_clang_version_le(3, 4) /* { */

extern float __attribute__((__vector_size__(16)))
__coverity__builtin_ia32_vbroadcastss(float const *__a);
#define __builtin_ia32_vbroadcastss(P1) \
    __coverity__builtin_ia32_vbroadcastss((P1))

extern float __attribute__((__vector_size__(32)))
__coverity__builtin_ia32_vbroadcastss256(float const *__a);
#define __builtin_ia32_vbroadcastss256(P1) \
    __coverity__builtin_ia32_vbroadcastss256((P1))

extern double __attribute__((__vector_size__(32)))
__coverity__builtin_ia32_vbroadcastsd256(double const *__a);
#define __builtin_ia32_vbroadcastsd256(P1) \
    __coverity__builtin_ia32_vbroadcastsd256((P1))

/* The following builtins were present in Clang 3.4, but their signatures were
   changed in Clang 3.5.  These are the 3.4 signatures. */

extern char __attribute__((__vector_size__(16)))
__coverity__builtin_msa_sld_b(char __attribute__((__vector_size__(16))) __a, unsigned int __b);
#define __builtin_msa_sld_b(P1, P2) \
    __coverity__builtin_msa_sld_b((P1), (P2))

extern long long int __attribute__((__vector_size__(16)))
__coverity__builtin_msa_sld_d(long long int __attribute__((__vector_size__(16))) __a, unsigned int __b);
#define __builtin_msa_sld_d(P1, P2) \
    __coverity__builtin_msa_sld_d((P1), (P2))

extern short __attribute__((__vector_size__(16)))
__coverity__builtin_msa_sld_h(short __attribute__((__vector_size__(16))) __a, unsigned int __b);
#define __builtin_msa_sld_h(P1, P2) \
    __coverity__builtin_msa_sld_h((P1), (P2))

extern int __attribute__((__vector_size__(16)))
__coverity__builtin_msa_sld_w(int __attribute__((__vector_size__(16))) __a, unsigned int __b);
#define __builtin_msa_sld_w(P1, P2) \
    __coverity__builtin_msa_sld_w((P1), (P2))

extern char __attribute__((__vector_size__(16)))
__coverity__builtin_msa_sldi_b(char __attribute__((__vector_size__(16))) __a, unsigned int __b);
#define __builtin_msa_sldi_b(P1, P2) \
    __coverity__builtin_msa_sldi_b((P1), (P2))

extern long long int __attribute__((__vector_size__(16)))
__coverity__builtin_msa_sldi_d(long long int __attribute__((__vector_size__(16))) __a, unsigned int __b);
#define __builtin_msa_sldi_d(P1, P2) \
    __coverity__builtin_msa_sldi_d((P1), (P2))

extern short __attribute__((__vector_size__(16)))
__coverity__builtin_msa_sldi_h(short __attribute__((__vector_size__(16))) __a, unsigned int __b);
#define __builtin_msa_sldi_h(P1, P2) \
    __coverity__builtin_msa_sldi_h((P1), (P2))

extern int __attribute__((__vector_size__(16)))
__coverity__builtin_msa_sldi_w(int __attribute__((__vector_size__(16))) __a, unsigned int __b);
#define __builtin_msa_sldi_w(P1, P2) \
    __coverity__builtin_msa_sldi_w((P1), (P2))

extern float __attribute__((__vector_size__(8)))
__coverity__builtin_neon_vcvt_f32_f64(short __attribute__((__vector_size__(16))) __a, unsigned int __b);
#define __builtin_neon_vcvt_f32_f64(P1, P2) \
    __coverity__builtin_neon_vcvt_f32_f64((P1), (P2))

#endif /* } clang <= 3.4 */


/*************************************
 ************* CLANG 3.6 *************
 *************************************/

/* No builtins present in Clang 3.5 were removed in Clang 3.6 */
#if __cov_clang_version_le(3, 5) /* { */
/* These builtins had parameters added in Clang 3.6.  The definitions
   that follow emulate the 3.5 versions. */

extern double __coverity__builtin_amdgpu_div_fmas(double __a, double __b, double __C);
#define __builtin_amdgpu_div_fmas(P1, P2, P3) \
    __coverity__builtin_amdgpu_div_fmas((P1), (P2), (P3))

extern float __coverity__builtin_amdgpu_div_fmasf(float __a, float __b, float __C);
#define __builtin_amdgpu_div_fmasf(P1, P2, P3) \
    __coverity__builtin_amdgpu_div_fmasf((P1), (P2), (P3))

extern double __coverity__nvvm_add_rm_d(double __a);
#define __nvvm_add_rm_d(P1) __coverity__nvvm_add_rm_d((P1))

extern float __coverity__nvvm_add_rm_f(float __a);
#define __nvvm_add_rm_f(P1) __coverity__nvvm_add_rm_f((P1))

extern float __coverity__nvvm_add_rm_ftz_f(float __a);
#define __nvvm_add_rm_ftz_f(P1) __coverity__nvvm_add_rm_ftz_f((P1))

extern double __coverity__nvvm_add_rn_d(double __a);
#define __nvvm_add_rn_d(P1) __coverity__nvvm_add_rn_d((P1))

extern float __coverity__nvvm_add_rn_f(float __a);
#define __nvvm_add_rn_f(P1) __coverity__nvvm_add_rn_f((P1))

extern float __coverity__nvvm_add_rn_ftz_f(float __a);
#define __nvvm_add_rn_ftz_f(P1) __coverity__nvvm_add_rn_ftz_f((P1))

extern double __coverity__nvvm_add_rp_d(double __a);
#define __nvvm_add_rp_d(P1) __coverity__nvvm_add_rp_d((P1))

extern float __coverity__nvvm_add_rp_f(float __a);
#define __nvvm_add_rp_f(P1) __coverity__nvvm_add_rp_f((P1))

extern float __coverity__nvvm_add_rp_ftz_f(float __a);
#define __nvvm_add_rp_ftz_f(P1) __coverity__nvvm_add_rp_ftz_f((P1))

extern double __coverity__nvvm_add_rz_d(double __a);
#define __nvvm_add_rz_d(P1) __coverity__nvvm_add_rz_d((P1))

extern float __coverity__nvvm_add_rz_f(float __a);
#define __nvvm_add_rz_f(P1) __coverity__nvvm_add_rz_f((P1))

extern float __coverity__nvvm_add_rz_ftz_f(float __a);
#define __nvvm_add_rz_ftz_f(P1) __coverity__nvvm_add_rz_ftz_f((P1))

extern int __coverity__nvvm_sad_i(int __a, int __b);
#define __nvvm_add_sad_i(P1, P2) __coverity__nvvm_sad_i((P1), (P2))

extern unsigned int __coverity__nvvm_sad_ui(unsigned int __a, unsigned int __b);
#define __nvvm_add_sad_ui(P1, P2) __coverity__nvvm_sad_ui((P1), (P2))

/* The following definitions all changed in the last parameter from int to
 * const-reducing char in 3.6.  These are all prototypes with that last int.
 * Note that the first three also changed from 3.0 to 3.1., so we can
 * only define these for between 3.1 and 3.5 (inclusive). */
#if    (__coverity_clang_major__ == 3 && __coverity_clang_minor__ >= 1) /* { */
extern double __attribute__((vector_size(16)))
__coverity__builtin_ia32_blendpd(
    double __attribute__((vector_size(16))),
    double __attribute__((vector_size(16))),
    int);
#define __builtin_ia32_blendpd(P1, P2, P3) \
    __coverity__builtin_ia32_blendpd((P1), (P2), (P3))

extern float __attribute__((vector_size(16)))
__coverity__builtin_ia32_blendps(
    float __attribute__((vector_size(16))),
    float __attribute__((vector_size(16))),
    int);
#define __builtin_ia32_blendps(P1, P2, P3) \
    __coverity__builtin_ia32_blendps((P1), (P2), (P3))

extern short __attribute__((vector_size(16)))
__coverity__builtin_ia32_pblendw128(
    short __attribute__((vector_size(16))),
    short __attribute__((vector_size(16))),
    int);
#define __builtin_ia32_pblendw128(P1, P2, P3) \
    __coverity__builtin_ia32_pblendw128((P1), (P2), (P3))

#endif /* (__coverity_clang_major__ == 3 && __coverity_clang_minor__ >= 1) } */

extern double __attribute__((vector_size(32)))
__coverity__builtin_ia32_blendpd256(
    double __attribute__((vector_size(32))),
    double __attribute__((vector_size(32))),
    int);
#define __builtin_ia32_blendpd256(P1, P2, P3) \
    __coverity__builtin_ia32_blendpd256((P1), (P2), (P3))

extern float __attribute__((vector_size(32)))
__coverity__builtin_ia32_blendps256(
    float __attribute__((vector_size(32))),
    float __attribute__((vector_size(32))),
    int);
#define __builtin_ia32_blendps256(P1, P2, P3) \
    __coverity__builtin_ia32_blendps256((P1), (P2), (P3))

extern double __attribute__((vector_size(16)))
__coverity__builtin_ia32_dppd(
    double __attribute__((vector_size(16))),
    double __attribute__((vector_size(16))),
    int);
#define __builtin_ia32_dppd(P1, P2, P3) \
    __coverity__builtin_ia32_dppd((P1), (P2), (P3))

extern float __attribute__((vector_size(16)))
__coverity__builtin_ia32_dpps(
    float __attribute__((vector_size(16))),
    float __attribute__((vector_size(16))),
    int);
#define __builtin_ia32_dpps(P1, P2, P3) \
    __coverity__builtin_ia32_dpps((P1), (P2), (P3))

extern float __attribute__((vector_size(32)))
__coverity__builtin_ia32_dpps256(
    float __attribute__((vector_size(32))),
    float __attribute__((vector_size(32))),
    int);
#define __builtin_ia32_dpps256(P1, P2, P3) \
    __coverity__builtin_ia32_dpps256((P1), (P2), (P3))

extern float __attribute__((vector_size(16)))
__coverity__builtin_ia32_insertps128(
    float __attribute__((vector_size(16))),
    float __attribute__((vector_size(16))),
    int);
#define __builtin_ia32_insertps128(P1, P2, P3) \
    __coverity__builtin_ia32_insertps128((P1), (P2), (P3))

extern char __attribute__((vector_size(16)))
__coverity__builtin_ia32_mpsadbw128(
    char __attribute__((vector_size(16))),
    char __attribute__((vector_size(16))),
    int);
#define __builtin_ia32_mpsadbw128(P1, P2, P3) \
    __coverity__builtin_ia32_mpsadbw128((P1), (P2), (P3))

extern char __attribute__((vector_size(32)))
__coverity__builtin_ia32_mpsadbw256(
    char __attribute__((vector_size(32))),
    char __attribute__((vector_size(32))),
    int);
#define __builtin_ia32_mpsadbw256(P1, P2, P3) \
    __coverity__builtin_ia32_mpsadbw256((P1), (P2), (P3))

extern int __attribute__((vector_size(16)))
__coverity__builtin_ia32_pblendd128(
    int __attribute__((vector_size(16))),
    int __attribute__((vector_size(16))),
    int);
#define __builtin_ia32_pblendd128(P1, P2, P3) \
    __coverity__builtin_ia32_pblendd128((P1), (P2), (P3))

extern int __attribute__((vector_size(32)))
__coverity__builtin_ia32_pblendd256(
    int __attribute__((vector_size(32))),
    int __attribute__((vector_size(32))),
    int);
#define __builtin_ia32_pblendd256(P1, P2, P3) \
    __coverity__builtin_ia32_pblendd256((P1), (P2), (P3))

extern short __attribute__((vector_size(32)))
__coverity__builtin_ia32_pblendw256(
    short __attribute__((vector_size(32))),
    short __attribute__((vector_size(32))),
    int);
#define __builtin_ia32_pblendw256(P1, P2, P3) \
    __coverity__builtin_ia32_pblendw256((P1), (P2), (P3))

#endif /* } clang <= 3.5 */

/*************************************
 ************* CLANG 3.7 *************
 *************************************/

#if __cov_clang_version_le(3, 6) /* { */

/* The following builtins were present in Clang 3.6, but removed in Clang 3.7 */

/* This changed in 3.4 but was removed in 3.7.  The pre-3.4 signature is defined above.
 * This is the signature of the unfortunate identity-crisis-stricken intrinsic from 3.4 to 3.6. */
#if    (__coverity_clang_major__ == 3 && __coverity_clang_minor__ >= 4) /* { */

extern long long int __attribute__((vector_size(32)))
__coverity__builtin_ia32_vbroadcastsi256(
    const long long int __attribute__((vector_size(16))));
#define __builtin_ia32_vbroadcastsi256(P1) \
    __coverity__builtin_ia32_vbroadcastsi256((P1))

#endif /* (__coverity_clang_major__ == 3 && __coverity_clang_minor__ >= 4) } */

/* Note that the next eight also changed from 3.5 to 3.6, so we can
 * only define these for 3.6. */
#if    (__coverity_clang_major__ == 3 && __coverity_clang_minor__ == 6) /* { */

extern double __attribute__((vector_size(16)))
__coverity__builtin_ia32_blendpd(
    double __attribute__((vector_size(16))),
    double __attribute__((vector_size(16))),
    char);
#define __builtin_ia32_blendpd(P1, P2, P3) \
    __coverity__builtin_ia32_blendpd((P1), (P2), (P3))

extern float __attribute__((vector_size(16)))
__coverity__builtin_ia32_blendps(
    float __attribute__((vector_size(16))),
    float __attribute__((vector_size(16))),
    char);
#define __builtin_ia32_blendps(P1, P2, P3) \
    __coverity__builtin_ia32_blendps((P1), (P2), (P3))

extern double __attribute__((vector_size(32)))
__coverity__builtin_ia32_blendpd256(
    double __attribute__((vector_size(32))),
    double __attribute__((vector_size(32))),
    char);
#define __builtin_ia32_blendpd256(P1, P2, P3) \
    __coverity__builtin_ia32_blendpd256((P1), (P2), (P3))

extern float __attribute__((vector_size(32)))
__coverity__builtin_ia32_blendps256(
    float __attribute__((vector_size(32))),
    float __attribute__((vector_size(32))),
    char);
#define __builtin_ia32_blendps256(P1, P2, P3) \
    __coverity__builtin_ia32_blendps256((P1), (P2), (P3))

extern int __attribute__((vector_size(16)))
__coverity__builtin_ia32_pblendd128(
    int __attribute__((vector_size(16))),
    int __attribute__((vector_size(16))),
    char);
#define __builtin_ia32_pblendd128(P1, P2, P3) \
    __coverity__builtin_ia32_pblendd128((P1), (P2), (P3))

extern int __attribute__((vector_size(32)))
__coverity__builtin_ia32_pblendd256(
    int __attribute__((vector_size(32))),
    int __attribute__((vector_size(32))),
    char);
#define __builtin_ia32_pblendd256(P1, P2, P3) \
    __coverity__builtin_ia32_pblendd256((P1), (P2), (P3))

extern short __attribute__((vector_size(16)))
__coverity__builtin_ia32_pblendw128(
    short __attribute__((vector_size(16))),
    short __attribute__((vector_size(16))),
    char);
#define __builtin_ia32_pblendw128(P1, P2, P3) \
    __coverity__builtin_ia32_pblendw128((P1), (P2), (P3))

extern short __attribute__((vector_size(32)))
__coverity__builtin_ia32_pblendw256(
    short __attribute__((vector_size(32))),
    short __attribute__((vector_size(32))),
    char);
#define __builtin_ia32_pblendw256(P1, P2, P3) \
    __coverity__builtin_ia32_pblendw256((P1), (P2), (P3))

#endif /* (__coverity_clang_major__ == 3 && __coverity_clang_minor__ == 6) } */

extern long long int __attribute__((vector_size(16)))
__coverity__builtin_ia32_extract128i256(
    long long int __attribute__((vector_size(32))),
    char);
#define __builtin_ia32_extract128i256(P1, P2) \
    __coverity__builtin_ia32_extract128i256((P1), (P2))

extern long long int __attribute__((vector_size(32)))
__coverity__builtin_ia32_insert128i256(
    long long int __attribute__((vector_size(32))),
    long long int __attribute__((vector_size(16))),
    char);
#define __builtin_ia32_insert128i256(P1, P2, P3) \
    __coverity__builtin_ia32_insert128i256((P1), (P2), (P3))

extern long long int __attribute__((vector_size(16)))
__coverity__builtin_ia32_pslldqi128(
    long long int __attribute__((vector_size(16))),
    int);
#define __builtin_ia32_pslldqi128(P1, P2) \
    __coverity__builtin_ia32_pslldqi128((P1), (P2))

extern long long int __attribute__((vector_size(16)))
__coverity__builtin_ia32_psrldqi128(
    long long int __attribute__((vector_size(16))),
    int);
#define __builtin_ia32_psrldqi128(P1, P2) \
    __coverity__builtin_ia32_pslldqi128((P1), (P2))

extern double __attribute__((vector_size(16)))
__coverity__builtin_ia32_vextractf128_pd256(
    double __attribute__((vector_size(32))),
    char);
#define __builtin_ia32_vextractf128_pd256(P1, P2) \
    __coverity__builtin_ia32_vextractf128_pd256((P1), (P2))

extern float __attribute__((vector_size(16)))
__coverity__builtin_ia32_vextractf128_ps256(
    float __attribute__((vector_size(32))),
    char);
#define __builtin_ia32_vextractf128_ps256(P1, P2) \
    __coverity__builtin_ia32_vextractf128_ps256((P1), (P2))

extern int __attribute__((vector_size(16)))
__coverity__builtin_ia32_vextractf128_si256(
    int __attribute__((vector_size(32))),
    char);
#define __builtin_ia32_vextractf128_si256(P1, P2) \
    __coverity__builtin_ia32_vextractf128_si256((P1), (P2))

extern double __attribute__((vector_size(32)))
__coverity__builtin_ia32_vinsertf128_pd256(
    double __attribute__((vector_size(32))),
    double __attribute__((vector_size(16))),
    char);
#define __builtin_ia32_vinsertf128_pd256(P1, P2, P3) \
    __coverity__builtin_ia32_vinsertf128_pd256((P1), (P2), (P3))

extern float __attribute__((vector_size(32)))
__coverity__builtin_ia32_vinsertf128_ps256(
    float __attribute__((vector_size(32))),
    float __attribute__((vector_size(16))),
    char);
#define __builtin_ia32_vinsertf128_ps256(P1, P2, P3) \
    __coverity__builtin_ia32_vinsertf128_ps256((P1), (P2), (P3))

extern int __attribute__((vector_size(32)))
__coverity__builtin_ia32_vinsertf128_si256(
    int __attribute__((vector_size(32))),
    int __attribute__((vector_size(16))),
    char);
#define __builtin_ia32_vinsertf128_si256(P1, P2, P3) \
    __coverity__builtin_ia32_vinsertf128_si256((P1), (P2), (P3))

extern double __attribute__((vector_size(64)))
__coverity__builtin_ia32_vfmsubpd512_mask(
    double __attribute__((vector_size(64))),
    double __attribute__((vector_size(64))),
    double __attribute__((vector_size(64))),
    unsigned char,
    int);
#define __builtin_ia32_vfmsubpd512_mask(P1, P2, P3, P4, P5) \
    __coverity__builtin_ia32_vfmsubpd512_mask((P1), (P2), (P3), (P4), (P5))

extern float __attribute__((vector_size(64)))
__coverity__builtin_ia32_vfmsubps512_mask(
    float __attribute__((vector_size(64))),
    float __attribute__((vector_size(64))),
    float __attribute__((vector_size(64))),
    unsigned short,
    int);
#define __builtin_ia32_vfmsubps512_mask(P1, P2, P3, P4, P5) \
    __coverity__builtin_ia32_vfmsubps512_mask((P1), (P2), (P3), (P4), (P5))

/* These builtins had parameters changed in Clang 3.7.  The definitions
   that follow emulate the 3.6 versions. */

extern int __attribute__((vector_size(64)))
__coverity__builtin_ia32_alignd512_mask(
    int __attribute__((vector_size(64))),
    int __attribute__((vector_size(64))),
    unsigned char,
    int __attribute__((vector_size(64))),
    unsigned char);
#define __builtin_ia32_alignd512_mask(P1, P2, P3, P4, P5) \
    __coverity__builtin_ia32_alignd512_mask((P1), (P2), (P3), (P4), (P5))

extern long long int __attribute__((vector_size(64)))
__coverity__builtin_ia32_alignq512_mask(
    long long int __attribute__((vector_size(64))),
    long long int __attribute__((vector_size(64))),
    unsigned char,
    long long int __attribute__((vector_size(64))),
    unsigned char);
#define __builtin_ia32_alignq512_mask(P1, P2, P3, P4, P5) \
    __coverity__builtin_ia32_alignq512_mask((P1), (P2), (P3), (P4), (P5))

extern long long int __coverity__ldrexd(long long int*);
#define __ldrexd(P1) __coverity__ldrexd(P1)

#endif /* } clang <= 3.6 */

#endif // __coverity_assume_xcode__

/*************************************
 ***** LLVM 3.7 & APPLE CLANG 7.0 ****
 *************************************/

/* These are a set of 55 prototypes that differ in LLVM 3.7 / Apple Clang 7.0 from their
   predecessor only by requiring an int parameter to reduce to a constant at compile time.
   We thus must define the non-constant-reducing prototypes for emulating earlier versions.
   Rather than quote these 55 prototypes twice, we just make the #if statement bigger.
   Note these were generated by the simple proto_generator.awk script. */

#if (!__coverity_assume_xcode__ && __cov_clang_version_le(3, 6)) || \
    __cov_xcode_version_lt(7, 0) /* { */

extern unsigned char
__coverity__builtin_ia32_cmppd512_mask(
    double __attribute__((vector_size(64))) __a,
    double __attribute__((vector_size(64))) __b,
    const int __c,
    unsigned char __d,
    int __e);
#define __builtin_ia32_cmppd512_mask(P0, P1, P2, P3, P4) \
    __coverity__builtin_ia32_cmppd512_mask((P0), (P1), (P2), (P3), (P4))

extern unsigned short
__coverity__builtin_ia32_cmpps512_mask(
    float __attribute__((vector_size(64))) __a,
    float __attribute__((vector_size(64))) __b,
    const int __c,
    unsigned short __d,
    int __e);
#define __builtin_ia32_cmpps512_mask(P0, P1, P2, P3, P4) \
    __coverity__builtin_ia32_cmpps512_mask((P0), (P1), (P2), (P3), (P4))

extern float __attribute__((vector_size(64)))
__coverity__builtin_ia32_cvtdq2ps512_mask(
    int __attribute__((vector_size(64))) __a,
    float __attribute__((vector_size(64))) __b,
    unsigned short __c,
    const int __d);
#define __builtin_ia32_cvtdq2ps512_mask(P0, P1, P2, P3) \
    __coverity__builtin_ia32_cvtdq2ps512_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(32)))
__coverity__builtin_ia32_cvtpd2dq512_mask(
    double __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(32))) __b,
    unsigned char __c,
    const int __d);
#define __builtin_ia32_cvtpd2dq512_mask(P0, P1, P2, P3) \
    __coverity__builtin_ia32_cvtpd2dq512_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(32)))
__coverity__builtin_ia32_cvtpd2ps512_mask(
    double __attribute__((vector_size(64))) __a,
    float __attribute__((vector_size(32))) __b,
    unsigned char __c,
    const int __d);
#define __builtin_ia32_cvtpd2ps512_mask(P0, P1, P2, P3) \
    __coverity__builtin_ia32_cvtpd2ps512_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(32)))
__coverity__builtin_ia32_cvtpd2udq512_mask(
    double __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(32))) __b,
    unsigned char __c,
    const int __d);
#define __builtin_ia32_cvtpd2udq512_mask(P0, P1, P2, P3) \
    __coverity__builtin_ia32_cvtpd2udq512_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(64)))
__coverity__builtin_ia32_cvtps2dq512_mask(
    float __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    unsigned short __c,
    const int __d);
#define __builtin_ia32_cvtps2dq512_mask(P0, P1, P2, P3) \
    __coverity__builtin_ia32_cvtps2dq512_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(64)))
__coverity__builtin_ia32_cvtps2udq512_mask(
    float __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    unsigned short __c,
    const int __d);
#define __builtin_ia32_cvtps2udq512_mask(P0, P1, P2, P3) \
    __coverity__builtin_ia32_cvtps2udq512_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(32)))
__coverity__builtin_ia32_cvttpd2dq512_mask(
    double __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(32))) __b,
    unsigned char __c,
    const int __d);
#define __builtin_ia32_cvttpd2dq512_mask(P0, P1, P2, P3) \
    __coverity__builtin_ia32_cvttpd2dq512_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(32)))
__coverity__builtin_ia32_cvttpd2udq512_mask(
    double __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(32))) __b,
    unsigned char __c,
    const int __d);
#define __builtin_ia32_cvttpd2udq512_mask(P0, P1, P2, P3) \
    __coverity__builtin_ia32_cvttpd2udq512_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(64)))
__coverity__builtin_ia32_cvttps2dq512_mask(
    float __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    unsigned short __c,
    const int __d);
#define __builtin_ia32_cvttps2dq512_mask(P0, P1, P2, P3) \
    __coverity__builtin_ia32_cvttps2dq512_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(64)))
__coverity__builtin_ia32_cvttps2udq512_mask(
    float __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    unsigned short __c,
    const int __d);
#define __builtin_ia32_cvttps2udq512_mask(P0, P1, P2, P3) \
    __coverity__builtin_ia32_cvttps2udq512_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(64)))
__coverity__builtin_ia32_cvtudq2ps512_mask(
    int __attribute__((vector_size(64))) __a,
    float __attribute__((vector_size(64))) __b,
    unsigned short __c,
    const int __d);
#define __builtin_ia32_cvtudq2ps512_mask(P0, P1, P2, P3) \
    __coverity__builtin_ia32_cvtudq2ps512_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(32)))
__coverity__builtin_ia32_gatherdiv16sf(
    float __attribute__((vector_size(32))) __a,
    const void *__b,
    long long int __attribute__((vector_size(64))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_gatherdiv16sf(P0, P1, P2, P3, P4) \
    __coverity__builtin_ia32_gatherdiv16sf((P0), (P1), (P2), (P3), (P4))

extern int __attribute__((vector_size(32)))
__coverity__builtin_ia32_gatherdiv16si(
    int __attribute__((vector_size(32))) __a,
    const void *__b,
    long long int __attribute__((vector_size(64))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_gatherdiv16si(P0, P1, P2, P3, P4) \
    __coverity__builtin_ia32_gatherdiv16si((P0), (P1), (P2), (P3), (P4))

extern double __attribute__((vector_size(64)))
__coverity__builtin_ia32_gatherdiv8df(
    double __attribute__((vector_size(64))) __a,
    const void *__b,
    long long int __attribute__((vector_size(64))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_gatherdiv8df(P0, P1, P2, P3, P4) \
    __coverity__builtin_ia32_gatherdiv8df((P0), (P1), (P2), (P3), (P4))

extern long long int __attribute__((vector_size(64)))
__coverity__builtin_ia32_gatherdiv8di(
    long long int __attribute__((vector_size(64))) __a,
    const void *__b,
    long long int __attribute__((vector_size(64))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_gatherdiv8di(P0, P1, P2, P3, P4) \
    __coverity__builtin_ia32_gatherdiv8di((P0), (P1), (P2), (P3), (P4))

extern void
__coverity__builtin_ia32_gatherpfdpd(
    unsigned char __a,
    int __attribute__((vector_size(32))) __b,
    const void *__c,
    const int __d,
    const int __e);
#define __builtin_ia32_gatherpfdpd(P0, P1, P2, P3, P4) \
    __coverity__builtin_ia32_gatherpfdpd((P0), (P1), (P2), (P3), (P4))

extern void
__coverity__builtin_ia32_gatherpfdps(
    unsigned short __a,
    int __attribute__((vector_size(64))) __b,
    const void *__c,
    const int __d,
    const int __e);
#define __builtin_ia32_gatherpfdps(P0, P1, P2, P3, P4) \
    __coverity__builtin_ia32_gatherpfdps((P0), (P1), (P2), (P3), (P4))

extern void
__coverity__builtin_ia32_gatherpfqpd(
    unsigned char __a,
    long long int __attribute__((vector_size(64))) __b,
    const void *__c,
    const int __d,
    const int __e);
#define __builtin_ia32_gatherpfqpd(P0, P1, P2, P3, P4) \
    __coverity__builtin_ia32_gatherpfqpd((P0), (P1), (P2), (P3), (P4))

extern void
__coverity__builtin_ia32_gatherpfqps(
    unsigned char __a,
    long long int __attribute__((vector_size(64))) __b,
    const void *__c,
    const int __d,
    const int __e);
#define __builtin_ia32_gatherpfqps(P0, P1, P2, P3, P4) \
    __coverity__builtin_ia32_gatherpfqps((P0), (P1), (P2), (P3), (P4))

extern float __attribute__((vector_size(64)))
__coverity__builtin_ia32_gathersiv16sf(
    float __attribute__((vector_size(64))) __a,
    const void *__b,
    unsigned short __c,
    const int __d);
#define __builtin_ia32_gathersiv16sf(P0, P1, P2, P3) \
    __coverity__builtin_ia32_gathersiv16sf((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(64)))
__coverity__builtin_ia32_gathersiv16si(
    int __attribute__((vector_size(64))) __a,
    const void *__b,
    unsigned short __c,
    const int __d);
#define __builtin_ia32_gathersiv16si(P0, P1, P2, P3) \
    __coverity__builtin_ia32_gathersiv16si((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(64)))
__coverity__builtin_ia32_gathersiv8df(
    double __attribute__((vector_size(64))) __a,
    const void *__b,
    int __attribute__((vector_size(32))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_gathersiv8df(P0, P1, P2, P3, P4) \
    __coverity__builtin_ia32_gathersiv8df((P0), (P1), (P2), (P3), (P4))

extern long long int __attribute__((vector_size(64)))
__coverity__builtin_ia32_gathersiv8di(
    long long int __attribute__((vector_size(64))) __a,
    const void *__b,
    int __attribute__((vector_size(32))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_gathersiv8di(P0, P1, P2, P3, P4) \
    __coverity__builtin_ia32_gathersiv8di((P0), (P1), (P2), (P3), (P4))

extern double __attribute__((vector_size(64)))
__coverity__builtin_ia32_maxpd512_mask(
    double __attribute__((vector_size(64))) __a,
    double __attribute__((vector_size(64))) __b,
    double __attribute__((vector_size(64))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_maxpd512_mask(P0, P1, P2, P3, P4) \
    __coverity__builtin_ia32_maxpd512_mask((P0), (P1), (P2), (P3), (P4))

extern float __attribute__((vector_size(64)))
__coverity__builtin_ia32_maxps512_mask(
    float __attribute__((vector_size(64))) __a,
    float __attribute__((vector_size(64))) __b,
    float __attribute__((vector_size(64))) __c,
    unsigned short __d,
    const int __e);
#define __builtin_ia32_maxps512_mask(P0, P1, P2, P3, P4) \
    __coverity__builtin_ia32_maxps512_mask((P0), (P1), (P2), (P3), (P4))

extern double __attribute__((vector_size(64)))
__coverity__builtin_ia32_minpd512_mask(
    double __attribute__((vector_size(64))) __a,
    double __attribute__((vector_size(64))) __b,
    double __attribute__((vector_size(64))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_minpd512_mask(P0, P1, P2, P3, P4) \
    __coverity__builtin_ia32_minpd512_mask((P0), (P1), (P2), (P3), (P4))

extern float __attribute__((vector_size(64)))
__coverity__builtin_ia32_minps512_mask(
    float __attribute__((vector_size(64))) __a,
    float __attribute__((vector_size(64))) __b,
    float __attribute__((vector_size(64))) __c,
    unsigned short __d,
    const int __e);
#define __builtin_ia32_minps512_mask(P0, P1, P2, P3, P4) \
    __coverity__builtin_ia32_minps512_mask((P0), (P1), (P2), (P3), (P4))

extern double __attribute__((vector_size(64)))
__coverity__builtin_ia32_rcp28pd_mask(
    double __attribute__((vector_size(64))) __a,
    double __attribute__((vector_size(64))) __b,
    unsigned char __c,
    const int __d);
#define __builtin_ia32_rcp28pd_mask(P0, P1, P2, P3) \
    __coverity__builtin_ia32_rcp28pd_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(64)))
__coverity__builtin_ia32_rcp28ps_mask(
    float __attribute__((vector_size(64))) __a,
    float __attribute__((vector_size(64))) __b,
    unsigned short __c,
    const int __d);
#define __builtin_ia32_rcp28ps_mask(P0, P1, P2, P3) \
    __coverity__builtin_ia32_rcp28ps_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(64)))
__coverity__builtin_ia32_rndscalepd_mask(
    double __attribute__((vector_size(64))) __a,
    const int __b,
    double __attribute__((vector_size(64))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_rndscalepd_mask(P0, P1, P2, P3, P4) \
    __coverity__builtin_ia32_rndscalepd_mask((P0), (P1), (P2), (P3), (P4))

extern float __attribute__((vector_size(64)))
__coverity__builtin_ia32_rndscaleps_mask(
    float __attribute__((vector_size(64))) __a,
    const int __b,
    float __attribute__((vector_size(64))) __c,
    unsigned short __d,
    const int __e);
#define __builtin_ia32_rndscaleps_mask(P0, P1, P2, P3, P4) \
    __coverity__builtin_ia32_rndscaleps_mask((P0), (P1), (P2), (P3), (P4))

extern double __attribute__((vector_size(64)))
__coverity__builtin_ia32_rsqrt28pd_mask(
    double __attribute__((vector_size(64))) __a,
    double __attribute__((vector_size(64))) __b,
    unsigned char __c,
    const int __d);
#define __builtin_ia32_rsqrt28pd_mask(P0, P1, P2, P3) \
    __coverity__builtin_ia32_rsqrt28pd_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(64)))
__coverity__builtin_ia32_rsqrt28ps_mask(
    float __attribute__((vector_size(64))) __a,
    float __attribute__((vector_size(64))) __b,
    unsigned short __c,
    const int __d);
#define __builtin_ia32_rsqrt28ps_mask(P0, P1, P2, P3) \
    __coverity__builtin_ia32_rsqrt28ps_mask((P0), (P1), (P2), (P3))

extern void
__coverity__builtin_ia32_scatterdiv16sf(
    void *__a,
    unsigned char __b,
    long long int __attribute__((vector_size(64))) __c,
    float __attribute__((vector_size(32))) __d,
    const int __e);
#define __builtin_ia32_scatterdiv16sf(P0, P1, P2, P3, P4) \
    __coverity__builtin_ia32_scatterdiv16sf((P0), (P1), (P2), (P3), (P4))

extern void
__coverity__builtin_ia32_scatterdiv16si(
    void *__a,
    unsigned char __b,
    long long int __attribute__((vector_size(64))) __c,
    int __attribute__((vector_size(32))) __d,
    const int __e);
#define __builtin_ia32_scatterdiv16si(P0, P1, P2, P3, P4) \
    __coverity__builtin_ia32_scatterdiv16si((P0), (P1), (P2), (P3), (P4))

extern void
__coverity__builtin_ia32_scatterdiv8df(
    void *__a,
    unsigned char __b,
    long long int __attribute__((vector_size(64))) __c,
    double __attribute__((vector_size(64))) __d,
    const int __e);
#define __builtin_ia32_scatterdiv8df(P0, P1, P2, P3, P4) \
    __coverity__builtin_ia32_scatterdiv8df((P0), (P1), (P2), (P3), (P4))

extern void
__coverity__builtin_ia32_scatterdiv8di(
    void *__a,
    unsigned char __b,
    long long int __attribute__((vector_size(64))) __c,
    long long int __attribute__((vector_size(64))) __d,
    const int __e);
#define __builtin_ia32_scatterdiv8di(P0, P1, P2, P3, P4) \
    __coverity__builtin_ia32_scatterdiv8di((P0), (P1), (P2), (P3), (P4))

extern void
__coverity__builtin_ia32_scatterpfdpd(
    unsigned char __a,
    int __attribute__((vector_size(32))) __b,
    void *__c,
    const int __d,
    const int __e);
#define __builtin_ia32_scatterpfdpd(P0, P1, P2, P3, P4) \
    __coverity__builtin_ia32_scatterpfdpd((P0), (P1), (P2), (P3), (P4))

extern void
__coverity__builtin_ia32_scatterpfdps(
    unsigned short __a,
    int __attribute__((vector_size(64))) __b,
    void *__c,
    const int __d,
    const int __e);
#define __builtin_ia32_scatterpfdps(P0, P1, P2, P3, P4) \
    __coverity__builtin_ia32_scatterpfdps((P0), (P1), (P2), (P3), (P4))

extern void
__coverity__builtin_ia32_scatterpfqpd(
    unsigned char __a,
    long long int __attribute__((vector_size(64))) __b,
    void *__c,
    const int __d,
    const int __e);
#define __builtin_ia32_scatterpfqpd(P0, P1, P2, P3, P4) \
    __coverity__builtin_ia32_scatterpfqpd((P0), (P1), (P2), (P3), (P4))

extern void
__coverity__builtin_ia32_scatterpfqps(
    unsigned char __a,
    long long int __attribute__((vector_size(64))) __b,
    void *__c,
    const int __d,
    const int __e);
#define __builtin_ia32_scatterpfqps(P0, P1, P2, P3, P4) \
    __coverity__builtin_ia32_scatterpfqps((P0), (P1), (P2), (P3), (P4))

extern void
__coverity__builtin_ia32_scattersiv16sf(
    void *__a,
    unsigned short __b,
    int __attribute__((vector_size(64))) __c,
    float __attribute__((vector_size(64))) __d,
    const int __e);
#define __builtin_ia32_scattersiv16sf(P0, P1, P2, P3, P4) \
    __coverity__builtin_ia32_scattersiv16sf((P0), (P1), (P2), (P3), (P4))

extern void
__coverity__builtin_ia32_scattersiv16si(
    void *__a,
    unsigned short __b,
    int __attribute__((vector_size(64))) __c,
    int __attribute__((vector_size(64))) __d,
    const int __e);
#define __builtin_ia32_scattersiv16si(P0, P1, P2, P3, P4) \
    __coverity__builtin_ia32_scattersiv16si((P0), (P1), (P2), (P3), (P4))

extern void
__coverity__builtin_ia32_scattersiv8df(
    void *__a,
    unsigned char __b,
    int __attribute__((vector_size(32))) __c,
    double __attribute__((vector_size(64))) __d,
    const int __e);
#define __builtin_ia32_scattersiv8df(P0, P1, P2, P3, P4) \
    __coverity__builtin_ia32_scattersiv8df((P0), (P1), (P2), (P3), (P4))

extern void
__coverity__builtin_ia32_scattersiv8di(
    void *__a,
    unsigned char __b,
    int __attribute__((vector_size(32))) __c,
    long long int __attribute__((vector_size(64))) __d,
    const int __e);
#define __builtin_ia32_scattersiv8di(P0, P1, P2, P3, P4) \
    __coverity__builtin_ia32_scattersiv8di((P0), (P1), (P2), (P3), (P4))

extern double __attribute__((vector_size(64)))
__coverity__builtin_ia32_sqrtpd512_mask(
    double __attribute__((vector_size(64))) __a,
    double __attribute__((vector_size(64))) __b,
    unsigned char __c,
    const int __d);
#define __builtin_ia32_sqrtpd512_mask(P0, P1, P2, P3) \
    __coverity__builtin_ia32_sqrtpd512_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(64)))
__coverity__builtin_ia32_sqrtps512_mask(
    float __attribute__((vector_size(64))) __a,
    float __attribute__((vector_size(64))) __b,
    unsigned short __c,
    const int __d);
#define __builtin_ia32_sqrtps512_mask(P0, P1, P2, P3) \
    __coverity__builtin_ia32_sqrtps512_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(64)))
__coverity__builtin_ia32_vcvtph2ps512_mask(
    short __attribute__((vector_size(32))) __a,
    float __attribute__((vector_size(64))) __b,
    unsigned short __c,
    const int __d);
#define __builtin_ia32_vcvtph2ps512_mask(P0, P1, P2, P3) \
    __coverity__builtin_ia32_vcvtph2ps512_mask((P0), (P1), (P2), (P3))

extern short __attribute__((vector_size(32)))
__coverity__builtin_ia32_vcvtps2ph512_mask(
    float __attribute__((vector_size(64))) __a,
    const int __b,
    short __attribute__((vector_size(32))) __c,
    unsigned short __d);
#define __builtin_ia32_vcvtps2ph512_mask(P0, P1, P2, P3) \
    __coverity__builtin_ia32_vcvtps2ph512_mask((P0), (P1), (P2), (P3))

#endif /* } clang <= 3.6 || xcode < 7.0 */

/*************************************
 ************ Clang 3.8 **************
 *************************************/

#if (__cov_clang_version_lt(3, 8)) /* { */

/* These prototypes were removed in clang 3.8. { */

extern char __attribute__((vector_size(16)))
__coverity___builtin_ia32_pbroadcastb128(
    char __attribute__((vector_size(16))) __a);
#define __builtin_ia32_pbroadcastb128(P0) \
    __coverity___builtin_ia32_pbroadcastb128((P0))

extern char __attribute__((vector_size(32)))
__coverity___builtin_ia32_pbroadcastb256(
    char __attribute__((vector_size(16))) __a);
#define __builtin_ia32_pbroadcastb256(P0) \
    __coverity___builtin_ia32_pbroadcastb256((P0))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_pbroadcastd128(
    int __attribute__((vector_size(16))) __a);
#define __builtin_ia32_pbroadcastd128(P0) \
    __coverity___builtin_ia32_pbroadcastd128((P0))

extern int __attribute__((vector_size(32)))
__coverity___builtin_ia32_pbroadcastd256(
    int __attribute__((vector_size(16))) __a);
#define __builtin_ia32_pbroadcastd256(P0) \
    __coverity___builtin_ia32_pbroadcastd256((P0))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pbroadcastq128(
    long long __attribute__((vector_size(16))) __a);
#define __builtin_ia32_pbroadcastq128(P0) \
    __coverity___builtin_ia32_pbroadcastq128((P0))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pbroadcastq256(
    long long __attribute__((vector_size(16))) __a);
#define __builtin_ia32_pbroadcastq256(P0) \
    __coverity___builtin_ia32_pbroadcastq256((P0))

extern short __attribute__((vector_size(16)))
__coverity___builtin_ia32_pbroadcastw128(
    short __attribute__((vector_size(16))) __a);
#define __builtin_ia32_pbroadcastw128(P0) \
    __coverity___builtin_ia32_pbroadcastw128((P0))

extern short __attribute__((vector_size(32)))
__coverity___builtin_ia32_pbroadcastw256(
    short __attribute__((vector_size(16))) __a);
#define __builtin_ia32_pbroadcastw256(P0) \
    __coverity___builtin_ia32_pbroadcastw256((P0))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmovsxbd128(
    char __attribute__((vector_size(16))) __a);
#define __builtin_ia32_pmovsxbd128(P0) \
    __coverity___builtin_ia32_pmovsxbd128((P0))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmovsxbq128(
    char __attribute__((vector_size(16))) __a);
#define __builtin_ia32_pmovsxbq128(P0) \
    __coverity___builtin_ia32_pmovsxbq128((P0))

extern short __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmovsxbw128(
    char __attribute__((vector_size(16))) __a);
#define __builtin_ia32_pmovsxbw128(P0) \
    __coverity___builtin_ia32_pmovsxbw128((P0))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmovsxdq128(
    int __attribute__((vector_size(16))) __a);
#define __builtin_ia32_pmovsxdq128(P0) \
    __coverity___builtin_ia32_pmovsxdq128((P0))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmovsxwd128(
    short __attribute__((vector_size(16))) __a);
#define __builtin_ia32_pmovsxwd128(P0) \
    __coverity___builtin_ia32_pmovsxwd128((P0))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmovsxwq128(
    short __attribute__((vector_size(16))) __a);
#define __builtin_ia32_pmovsxwq128(P0) \
    __coverity___builtin_ia32_pmovsxwq128((P0))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_rcp14sd_mask(
    double __attribute__((vector_size(16))) __a,
    double __attribute__((vector_size(16))) __b,
    double __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_rcp14sd_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_rcp14sd_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_rcp14ss_mask(
    float __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_rcp14ss_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_rcp14ss_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_rcp28sd_mask(
    double __attribute__((vector_size(16))) __a,
    double __attribute__((vector_size(16))) __b,
    double __attribute__((vector_size(16))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_rcp28sd_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_rcp28sd_mask((P0), (P1), (P2), (P3), (P4))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_rcp28ss_mask(
    float __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_rcp28ss_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_rcp28ss_mask((P0), (P1), (P2), (P3), (P4))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_rsqrt14sd_mask(
    double __attribute__((vector_size(16))) __a,
    double __attribute__((vector_size(16))) __b,
    double __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_rsqrt14sd_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_rsqrt14sd_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_rsqrt14ss_mask(
    float __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_rsqrt14ss_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_rsqrt14ss_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_rsqrt28sd_mask(
    double __attribute__((vector_size(16))) __a,
    double __attribute__((vector_size(16))) __b,
    double __attribute__((vector_size(16))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_rsqrt28sd_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_rsqrt28sd_mask((P0), (P1), (P2), (P3), (P4))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_rsqrt28ss_mask(
    float __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_rsqrt28ss_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_rsqrt28ss_mask((P0), (P1), (P2), (P3), (P4))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_vbroadcastsd_pd256(
    double __attribute__((vector_size(16))) __a);
#define __builtin_ia32_vbroadcastsd_pd256(P0) \
    __coverity___builtin_ia32_vbroadcastsd_pd256((P0))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_vbroadcastss_ps(
    float __attribute__((vector_size(16))) __a);
#define __builtin_ia32_vbroadcastss_ps(P0) \
    __coverity___builtin_ia32_vbroadcastss_ps((P0))

extern float __attribute__((vector_size(32)))
__coverity___builtin_ia32_vbroadcastss_ps256(
    float __attribute__((vector_size(16))) __a);
#define __builtin_ia32_vbroadcastss_ps256(P0) \
    __coverity___builtin_ia32_vbroadcastss_ps256((P0))

#if !defined(__ARM_NEON__) && !defined(__ARM_NEON) && !defined(__AARCH_FEATURE_ADVSIMD) /* { */
extern signed char __attribute__((vector_size(8)))
__coverity___builtin_neon_vcvt_f16_v(
    signed char __attribute__((vector_size(16))) __a,
    int __b);
#define __builtin_neon_vcvt_f16_v(P0, P1) \
    __coverity___builtin_neon_vcvt_f16_v((P0), (P1))
#endif /* } !defined(__ARM_NEON__) && !defined(__AARCH_FEATURE_ADVSIMD) */

/* } These builtins were modified in clang 3.8. { */

#ifdef __arm__
extern void
__coverity___builtin_arm_mcr(
    unsigned int __a,
    unsigned int __b,
    unsigned int __c,
    unsigned int __d,
    unsigned int __e,
    unsigned int __f);
#define __builtin_arm_mcr(P0, P1, P2, P3, P4, P5) \
    __coverity___builtin_arm_mcr((P0), (P1), (P2), (P3), (P4), (P5))

extern void
__coverity___builtin_arm_mcr2(
    unsigned int __a,
    unsigned int __b,
    unsigned int __c,
    unsigned int __d,
    unsigned int __e,
    unsigned int __f);
#define __builtin_arm_mcr2(P0, P1, P2, P3, P4, P5) \
    __coverity___builtin_arm_mcr2((P0), (P1), (P2), (P3), (P4), (P5))

extern void
__coverity___builtin_arm_mcrr(
    const unsigned int __a,
    const unsigned int __b,
    unsigned int __c,
    unsigned int __d,
    const unsigned int __e);
#define __builtin_arm_mcrr(P0, P1, P2, P3, P4) \
    __coverity___builtin_arm_mcrr((P0), (P1), (P2), (P3), (P4))

extern void
__coverity___builtin_arm_mcrr2(
    const unsigned int __a,
    const unsigned int __b,
    unsigned int __c,
    unsigned int __d,
    const unsigned int __e);
#define __builtin_arm_mcrr2(P0, P1, P2, P3, P4) \
    __coverity___builtin_arm_mcrr2((P0), (P1), (P2), (P3), (P4))

extern unsigned int
__coverity___builtin_arm_mrc(
    unsigned int __a,
    unsigned int __b,
    unsigned int __c,
    unsigned int __d,
    unsigned int __e);
#define __builtin_arm_mrc(P0, P1, P2, P3, P4) \
    __coverity___builtin_arm_mrc((P0), (P1), (P2), (P3), (P4))

extern unsigned int
__coverity___builtin_arm_mrc2(
    unsigned int __a,
    unsigned int __b,
    unsigned int __c,
    unsigned int __d,
    unsigned int __e);
#define __builtin_arm_mrc2(P0, P1, P2, P3, P4) \
    __coverity___builtin_arm_mrc2((P0), (P1), (P2), (P3), (P4))

#endif /* __arm__ */

/*
 * These builtins were modified between 3.6 and 3.7 as well as between
 * 3.7 and 3.8.
 */
#if __cov_clang_version_ge(3, 7) /* { */

extern int __attribute__((vector_size(64)))
__coverity___builtin_ia32_alignd512_mask(
    int __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    char __c,
    int __attribute__((vector_size(64))) __d,
    unsigned short __e);
#define __builtin_ia32_alignd512_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_alignd512_mask((P0), (P1), (P2), (P3), (P4))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_alignq512_mask(
    long long __attribute__((vector_size(64))) __a,
    long long __attribute__((vector_size(64))) __b,
    char __c,
    long long __attribute__((vector_size(64))) __d,
    unsigned char __e);
#define __builtin_ia32_alignq512_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_alignq512_mask((P0), (P1), (P2), (P3), (P4))

#endif /* } clang >= 3.7 */

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_extractf32x4_mask(
    float __attribute__((vector_size(64))) __a,
    const char __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_extractf32x4_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_extractf32x4_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_extractf64x4_mask(
    double __attribute__((vector_size(64))) __a,
    const char __b,
    double __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_extractf64x4_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_extractf64x4_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_gatherd_d(
    int __attribute__((vector_size(16))) __a,
    const int __attribute__((vector_size(16)))*__b,
    int __attribute__((vector_size(16))) __c,
    int __attribute__((vector_size(16))) __d,
    const char __e);
#define __builtin_ia32_gatherd_d(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_gatherd_d((P0), (P1), (P2), (P3), (P4))

extern int __attribute__((vector_size(32)))
__coverity___builtin_ia32_gatherd_d256(
    int __attribute__((vector_size(32))) __a,
    const int __attribute__((vector_size(32)))*__b,
    int __attribute__((vector_size(32))) __c,
    int __attribute__((vector_size(32))) __d,
    const char __e);
#define __builtin_ia32_gatherd_d256(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_gatherd_d256((P0), (P1), (P2), (P3), (P4))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_gatherd_pd(
    double __attribute__((vector_size(16))) __a,
    const double __attribute__((vector_size(16)))*__b,
    int __attribute__((vector_size(16))) __c,
    double __attribute__((vector_size(16))) __d,
    const char __e);
#define __builtin_ia32_gatherd_pd(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_gatherd_pd((P0), (P1), (P2), (P3), (P4))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_gatherd_pd256(
    double __attribute__((vector_size(32))) __a,
    const double __attribute__((vector_size(32)))*__b,
    int __attribute__((vector_size(16))) __c,
    double __attribute__((vector_size(32))) __d,
    const char __e);
#define __builtin_ia32_gatherd_pd256(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_gatherd_pd256((P0), (P1), (P2), (P3), (P4))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_gatherd_ps(
    float __attribute__((vector_size(16))) __a,
    const float __attribute__((vector_size(16)))*__b,
    int __attribute__((vector_size(16))) __c,
    float __attribute__((vector_size(16))) __d,
    const char __e);
#define __builtin_ia32_gatherd_ps(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_gatherd_ps((P0), (P1), (P2), (P3), (P4))

extern float __attribute__((vector_size(32)))
__coverity___builtin_ia32_gatherd_ps256(
    float __attribute__((vector_size(32))) __a,
    const float __attribute__((vector_size(32)))*__b,
    int __attribute__((vector_size(32))) __c,
    float __attribute__((vector_size(32))) __d,
    const char __e);
#define __builtin_ia32_gatherd_ps256(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_gatherd_ps256((P0), (P1), (P2), (P3), (P4))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_gatherd_q(
    long long __attribute__((vector_size(16))) __a,
    const long long __attribute__((vector_size(16)))*__b,
    int __attribute__((vector_size(16))) __c,
    long long __attribute__((vector_size(16))) __d,
    const char __e);
#define __builtin_ia32_gatherd_q(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_gatherd_q((P0), (P1), (P2), (P3), (P4))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_gatherd_q256(
    long long __attribute__((vector_size(32))) __a,
    const long long __attribute__((vector_size(32)))*__b,
    int __attribute__((vector_size(16))) __c,
    long long __attribute__((vector_size(32))) __d,
    const char __e);
#define __builtin_ia32_gatherd_q256(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_gatherd_q256((P0), (P1), (P2), (P3), (P4))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_gatherq_d(
    int __attribute__((vector_size(16))) __a,
    const int __attribute__((vector_size(16)))*__b,
    long long __attribute__((vector_size(16))) __c,
    int __attribute__((vector_size(16))) __d,
    const char __e);
#define __builtin_ia32_gatherq_d(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_gatherq_d((P0), (P1), (P2), (P3), (P4))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_gatherq_d256(
    int __attribute__((vector_size(16))) __a,
    const int __attribute__((vector_size(16)))*__b,
    long long __attribute__((vector_size(32))) __c,
    int __attribute__((vector_size(16))) __d,
    const char __e);
#define __builtin_ia32_gatherq_d256(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_gatherq_d256((P0), (P1), (P2), (P3), (P4))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_gatherq_pd(
    double __attribute__((vector_size(16))) __a,
    const double __attribute__((vector_size(16)))*__b,
    long long __attribute__((vector_size(16))) __c,
    double __attribute__((vector_size(16))) __d,
    const char __e);
#define __builtin_ia32_gatherq_pd(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_gatherq_pd((P0), (P1), (P2), (P3), (P4))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_gatherq_pd256(
    double __attribute__((vector_size(32))) __a,
    const double __attribute__((vector_size(32)))*__b,
    long long __attribute__((vector_size(32))) __c,
    double __attribute__((vector_size(32))) __d,
    const char __e);
#define __builtin_ia32_gatherq_pd256(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_gatherq_pd256((P0), (P1), (P2), (P3), (P4))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_gatherq_ps(
    float __attribute__((vector_size(16))) __a,
    const float __attribute__((vector_size(16)))*__b,
    long long __attribute__((vector_size(16))) __c,
    float __attribute__((vector_size(16))) __d,
    const char __e);
#define __builtin_ia32_gatherq_ps(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_gatherq_ps((P0), (P1), (P2), (P3), (P4))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_gatherq_ps256(
    float __attribute__((vector_size(16))) __a,
    const float __attribute__((vector_size(16)))*__b,
    long long __attribute__((vector_size(32))) __c,
    float __attribute__((vector_size(16))) __d,
    const char __e);
#define __builtin_ia32_gatherq_ps256(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_gatherq_ps256((P0), (P1), (P2), (P3), (P4))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_gatherq_q(
    long long __attribute__((vector_size(16))) __a,
    const long long __attribute__((vector_size(16)))*__b,
    long long __attribute__((vector_size(16))) __c,
    long long __attribute__((vector_size(16))) __d,
    const char __e);
#define __builtin_ia32_gatherq_q(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_gatherq_q((P0), (P1), (P2), (P3), (P4))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_gatherq_q256(
    long long __attribute__((vector_size(32))) __a,
    const long long __attribute__((vector_size(32)))*__b,
    long long __attribute__((vector_size(32))) __c,
    long long __attribute__((vector_size(32))) __d,
    const char __e);
#define __builtin_ia32_gatherq_q256(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_gatherq_q256((P0), (P1), (P2), (P3), (P4))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_maskloadpd(
    const double __attribute__((vector_size(16)))*__a,
    double __attribute__((vector_size(16))) __b);
#define __builtin_ia32_maskloadpd(P0, P1) \
    __coverity___builtin_ia32_maskloadpd((P0), (P1))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_maskloadpd256(
    const double __attribute__((vector_size(32)))*__a,
    double __attribute__((vector_size(32))) __b);
#define __builtin_ia32_maskloadpd256(P0, P1) \
    __coverity___builtin_ia32_maskloadpd256((P0), (P1))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_maskloadps(
    const float __attribute__((vector_size(16)))*__a,
    float __attribute__((vector_size(16))) __b);
#define __builtin_ia32_maskloadps(P0, P1) \
    __coverity___builtin_ia32_maskloadps((P0), (P1))

extern float __attribute__((vector_size(32)))
__coverity___builtin_ia32_maskloadps256(
    const float __attribute__((vector_size(32)))*__a,
    float __attribute__((vector_size(32))) __b);
#define __builtin_ia32_maskloadps256(P0, P1) \
    __coverity___builtin_ia32_maskloadps256((P0), (P1))

extern void
__coverity___builtin_ia32_maskstorepd(
    double __attribute__((vector_size(16)))*__a,
    double __attribute__((vector_size(16))) __b,
    double __attribute__((vector_size(16))) __c);
#define __builtin_ia32_maskstorepd(P0, P1, P2) \
    __coverity___builtin_ia32_maskstorepd((P0), (P1), (P2))

extern void
__coverity___builtin_ia32_maskstorepd256(
    double __attribute__((vector_size(32)))*__a,
    double __attribute__((vector_size(32))) __b,
    double __attribute__((vector_size(32))) __c);
#define __builtin_ia32_maskstorepd256(P0, P1, P2) \
    __coverity___builtin_ia32_maskstorepd256((P0), (P1), (P2))

extern void
__coverity___builtin_ia32_maskstoreps(
    float __attribute__((vector_size(16)))*__a,
    float __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c);
#define __builtin_ia32_maskstoreps(P0, P1, P2) \
    __coverity___builtin_ia32_maskstoreps((P0), (P1), (P2))

extern void
__coverity___builtin_ia32_maskstoreps256(
    float __attribute__((vector_size(32)))*__a,
    float __attribute__((vector_size(32))) __b,
    float __attribute__((vector_size(32))) __c);
#define __builtin_ia32_maskstoreps256(P0, P1, P2) \
    __coverity___builtin_ia32_maskstoreps256((P0), (P1), (P2))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_movntdqa(
    long long __attribute__((vector_size(16)))*__a);
#define __builtin_ia32_movntdqa(P0) \
    __coverity___builtin_ia32_movntdqa((P0))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_movntdqa256(
    long long __attribute__((vector_size(32)))*__a);
#define __builtin_ia32_movntdqa256(P0) \
    __coverity___builtin_ia32_movntdqa256((P0))

extern float __attribute__((vector_size(32)))
__coverity___builtin_ia32_permvarsf256(
    float __attribute__((vector_size(32))) __a,
    float __attribute__((vector_size(32))) __b);
#define __builtin_ia32_permvarsf256(P0, P1) \
    __coverity___builtin_ia32_permvarsf256((P0), (P1))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_roundpd(
    double __attribute__((vector_size(16))) __a,
    int __b);
#define __builtin_ia32_roundpd(P0, P1) \
    __coverity___builtin_ia32_roundpd((P0), (P1))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_roundps(
    float __attribute__((vector_size(16))) __a,
    int __b);
#define __builtin_ia32_roundps(P0, P1) \
    __coverity___builtin_ia32_roundps((P0), (P1))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_roundsd(
    double __attribute__((vector_size(16))) __a,
    double __attribute__((vector_size(16))) __b,
    int __c);
#define __builtin_ia32_roundsd(P0, P1, P2) \
    __coverity___builtin_ia32_roundsd((P0), (P1), (P2))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_roundss(
    float __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    int __c);
#define __builtin_ia32_roundss(P0, P1, P2) \
    __coverity___builtin_ia32_roundss((P0), (P1), (P2))

#if !defined(__ARM_NEON__) && !defined(__ARM_NEON) && !defined(__AARCH_FEATURE_ADVSIMD) /* { */
extern float __attribute__((vector_size(16)))
__coverity___builtin_neon_vcvt_f32_f16(
    signed char __attribute__((vector_size(8))) __a,
    int __b);
#define __builtin_neon_vcvt_f32_f16(P0, P1) \
    __coverity___builtin_neon_vcvt_f32_f16((P0), (P1))
#endif /* } !defined(__ARM_NEON__) && !defined(__AARCH_FEATURE_ADVSIMD) */

extern long
__coverity___builtin_ptx_read_clock64();
#define __builtin_ptx_read_clock64() \
    __coverity___builtin_ptx_read_clock64()

extern int
__coverity___builtin_signbit(
    double __a);
#define __builtin_signbit(P0) \
    __coverity___builtin_signbit((P0))

/* } */
#endif /* } clang < 3.8 */

/*************************************
 *************** NEON ****************
 *************************************/

/*
 * Loosen up the error checking on some of the arm neon intrinsics, native clang
 * has restrictions on the possible values of the constant integral parameter
 * to the neon intrinsics but some clang versions have headers that seem to
 * contradict the list of allowed values.
 */
#if defined(__ARM_NEON__) || defined(__ARM_NEON) || defined(__AARCH_FEATURE_ADVSIMD) /* { */
/* Define primitive types used in the neon builtin API */
typedef signed char             __cov_int8_t;
typedef unsigned char           __cov_uint8_t;
typedef short int               __cov_int16_t;
typedef unsigned short int      __cov_uint16_t;
typedef float __cov_float32_t;

#ifdef __aarch64__
typedef __fp16 __cov_float16_t;
typedef double __cov_float64_t;
#else
typedef __cov_uint16_t __cov_float16_t;
#endif

#ifdef __aarch64__
typedef __cov_uint8_t __cov_poly8_t;
typedef __cov_uint16_t __cov_poly16_t;
#else
typedef __cov_int8_t __cov_poly8_t;
typedef __cov_int16_t __cov_poly16_t;
#endif

/* Define neon intrinsic vector types built from primitive types */
typedef __attribute__((neon_vector_type(8)))  __cov_int8_t    __cov_neon_int8x8_t;
typedef __attribute__((neon_vector_type(16))) __cov_int8_t    __cov_neon_int8x16_t;
typedef __attribute__((neon_vector_type(4)))  __cov_float16_t __cov_neon_float16x4_t;
typedef __attribute__((neon_vector_type(2)))  __cov_float32_t __cov_neon_float32x2_t;
typedef __attribute__((neon_vector_type(4)))  __cov_float32_t __cov_neon_float32x4_t;

__cov_neon_float32x2_t
__coverity__builtin_neon_vabd_v(
    __cov_neon_int8x8_t,
    __cov_neon_int8x8_t,
    int);
#define __builtin_neon_vabd_v(P1, P2, P3) \
    __coverity__builtin_neon_vabd_v((P1), (P2), (P3))


__cov_neon_float32x4_t
__coverity__builtin_neon_vabdq_v(
    __cov_neon_int8x16_t,
    __cov_neon_int8x16_t,
    int);
#define __builtin_neon_vabdq_v(P1, P2, P3) \
    __coverity__builtin_neon_vabdq_v((P1), (P2), (P3))

__cov_neon_int8x8_t
__coverity__builtin_neon_vabs_v(
    __cov_neon_int8x8_t,
    int);
#define __builtin_neon_vabs_v(P1, P2) \
    __coverity__builtin_neon_vabs_v((P1), (P2))

__cov_neon_int8x16_t
__coverity__builtin_neon_vabsq_v(
    __cov_neon_int8x16_t,
    int);
#define __builtin_neon_vabsq_v(P1, P2) \
    __coverity__builtin_neon_vabsq_v((P1), (P2))


__cov_neon_int8x8_t
__coverity__builtin_neon_vbsl_v(
    __cov_neon_int8x8_t,
    __cov_neon_int8x8_t,
    __cov_neon_int8x8_t,
    int);
#define __builtin_neon_vbsl_v(P1, P2, P3, P4) \
    __coverity__builtin_neon_vbsl_v((P1), (P2), (P3), (P4))

__cov_neon_float32x4_t
__coverity__builtin_neon_vbslq_v(
    __cov_neon_int8x16_t,
    __cov_neon_int8x16_t,
    __cov_neon_int8x16_t,
    int);

__cov_neon_float16x4_t
__coverity__builtin_neon_vcvt_f16_v(
    __cov_neon_int8x16_t,
    int);
#define __builtin_neon_vcvt_f16_v(P1, P2) \
    __coverity__builtin_neon_vcvt_f16_v((P1), (P2))

#define __builtin_neon_vbslq_v(P1, P2, P3, P4)                  \
    __coverity__builtin_neon_vbslq_v((P1), (P2), (P3), (P4))

__cov_neon_float32x4_t
__coverity__builtin_neon_vcvt_f32_f16(
    __cov_neon_int8x8_t,
    int);
#define __builtin_neon_vcvt_f32_f16(P1, P2) \
    __coverity__builtin_neon_vcvt_f32_f16((P1), (P2))

__cov_neon_float16x4_t
__coverity__builtin_neon_vcvt_f16_f32(
    __cov_neon_float32x4_t,
    int);
#define __builtin_neon_vcvt_f16_f32(P1, P2) \
    __coverity__builtin_neon_vcvt_f16_f32((P1), (P2))

__cov_neon_float32x2_t
__coverity__builtin_neon_vfma_v(
    __cov_neon_int8x8_t,
    __cov_neon_int8x8_t,
    __cov_neon_int8x8_t,
    int);
#define __builtin_neon_vfma_v(P1, P2, P3, P4) \
    __coverity__builtin_neon_vfma_v((P1), (P2), (P3), (P4))

__cov_neon_float32x4_t
__coverity__builtin_neon_vfmaq_v(
    __cov_neon_int8x16_t,
    __cov_neon_int8x16_t,
    __cov_neon_int8x16_t,
    int);
#define __builtin_neon_vfmaq_v(P1, P2, P3, P4) \
    __coverity__builtin_neon_vfmaq_v((P1), (P2), (P3), (P4))

__cov_neon_float32x2_t
__coverity__builtin_neon_vmax_v(
    __cov_neon_int8x8_t,
    __cov_neon_int8x8_t,
    int);
#define __builtin_neon_vmax_v(P1, P2, P3) \
    __coverity__builtin_neon_vmax_v((P1), (P2), (P3))

__cov_neon_float32x4_t
__coverity__builtin_neon_vmaxq_v(
    __cov_neon_int8x16_t,
    __cov_neon_int8x16_t,
    int);
#define __builtin_neon_vmaxq_v(P1, P2, P3) \
    __coverity__builtin_neon_vmaxq_v((P1), (P2), (P3))

__cov_neon_float32x2_t
__coverity__builtin_neon_vmin_v(
    __cov_neon_int8x8_t,
    __cov_neon_int8x8_t,
    int);
#define __builtin_neon_vmin_v(P1, P2, P3) \
    __coverity__builtin_neon_vmin_v((P1), (P2), (P3))

__cov_neon_float32x4_t
__coverity__builtin_neon_vminq_v(
    __cov_neon_int8x16_t,
    __cov_neon_int8x16_t,
    int);
#define __builtin_neon_vminq_v(P1, P2, P3) \
    __coverity__builtin_neon_vminq_v((P1), (P2), (P3))

__cov_neon_float32x2_t
__coverity__builtin_neon_vpadd_v(
    __cov_neon_int8x8_t,
    __cov_neon_int8x8_t,
    int);
#define __builtin_neon_vpadd_v(P1, P2, P3) \
    __coverity__builtin_neon_vpadd_v((P1), (P2), (P3))

__cov_neon_float32x2_t
__coverity__builtin_neon_vpmax_v(
    __cov_neon_int8x8_t,
    __cov_neon_int8x8_t,
    int);
#define __builtin_neon_vpmax_v(P1, P2, P3) \
    __coverity__builtin_neon_vpmax_v((P1), (P2), (P3))

__cov_neon_float32x2_t
__coverity__builtin_neon_vpmin_v(
    __cov_neon_int8x8_t,
    __cov_neon_int8x8_t,
    int);
#define __builtin_neon_vpmin_v(P1, P2, P3) \
    __coverity__builtin_neon_vpmin_v((P1), (P2), (P3))

__cov_neon_float32x2_t
__coverity__builtin_neon_vrecpe_v(
    __cov_neon_int8x8_t,
    int);
#define __builtin_neon_vrecpe_v(P1, P2) \
    __coverity__builtin_neon_vrecpe_v((P1), (P2))

__cov_neon_float32x4_t
__coverity__builtin_neon_vrecpeq_v(
    __cov_neon_int8x16_t,
    int);
#define __builtin_neon_vrecpeq_v(P1, P2) \
    __coverity__builtin_neon_vrecpeq_v((P1), (P2))

__cov_neon_float32x2_t
__coverity__builtin_neon_vrecps_v(
    __cov_neon_int8x8_t,
    __cov_neon_int8x8_t,
    int);
#define __builtin_neon_vrecps_v(P1, P2, P3) \
    __coverity__builtin_neon_vrecps_v((P1), (P2), (P3))

__cov_neon_float32x4_t
__coverity__builtin_neon_vrecpsq_v(
    __cov_neon_int8x16_t,
    __cov_neon_int8x16_t,
    int);
#define __builtin_neon_vrecpsq_v(P1, P2, P3) \
    __coverity__builtin_neon_vrecpsq_v((P1), (P2), (P3))

__cov_neon_float32x2_t
__coverity__builtin_neon_vrsqrte_v(
    __cov_neon_int8x8_t,
    int);
#define __builtin_neon_vrsqrte_v(P1, P2) \
    __coverity__builtin_neon_vrsqrte_v((P1), (P2))

__cov_neon_float32x4_t
__coverity__builtin_neon_vrsqrteq_v(
    __cov_neon_int8x16_t,
    int);
#define __builtin_neon_vrsqrteq_v(P1, P2) \
    __coverity__builtin_neon_vrsqrteq_v((P1), (P2))

__cov_neon_float32x2_t
__coverity__builtin_neon_vrsqrts_v(
    __cov_neon_int8x8_t,
    __cov_neon_int8x8_t,
    int);
#define __builtin_neon_vrsqrts_v(P1, P2, P3) \
    __coverity__builtin_neon_vrsqrts_v((P1), (P2), (P3))

__cov_neon_float32x4_t
__coverity__builtin_neon_vrsqrtsq_v(
    __cov_neon_int8x16_t,
    __cov_neon_int8x16_t,
    int);
#define __builtin_neon_vrsqrtsq_v(P1, P2, P3) \
    __coverity__builtin_neon_vrsqrtsq_v((P1), (P2), (P3))

void
__coverity__builtin_neon_vtrn_v(
    void *,
    __cov_neon_int8x8_t,
    __cov_neon_int8x8_t,
    int);
#define __builtin_neon_vtrn_v(P1, P2, P3, P4) \
    __coverity__builtin_neon_vtrn_v((P1), (P2), (P3), (P4))

void
__coverity__builtin_neon_vtrnq_v(
    void *, __cov_neon_int8x16_t,
    __cov_neon_int8x16_t,
    int);
#define __builtin_neon_vtrnq_v(P1, P2, P3, P4) \
    __coverity__builtin_neon_vtrnq_v((P1), (P2), (P3), (P4))

void
__coverity__builtin_neon_vuzp_v(
    void *,
    __cov_neon_int8x8_t,
    __cov_neon_int8x8_t,
    int);
#define __builtin_neon_vuzp_v(P1, P2, P3, P4) \
    __coverity__builtin_neon_vuzp_v((P1), (P2), (P3), (P4))

void
__coverity__builtin_neon_vuzpq_v(
    void *,
    __cov_neon_int8x16_t,
    __cov_neon_int8x16_t,
    int);
#define __builtin_neon_vuzpq_v(P1, P2, P3, P4) \
    __coverity__builtin_neon_vuzpq_v((P1), (P2), (P3), (P4))

void
__coverity__builtin_neon_vzip_v(void *, __cov_neon_int8x8_t,
    __cov_neon_int8x8_t,
    int);
#define __builtin_neon_vzip_v(P1, P2, P3, P4) \
    __coverity__builtin_neon_vzip_v((P1), (P2), (P3), (P4))

void
__coverity__builtin_neon_vzipq_v(
    void *,
    __cov_neon_int8x16_t,
    __cov_neon_int8x16_t,
    int);
#define __builtin_neon_vzipq_v(P1, P2, P3, P4) \
    __coverity__builtin_neon_vzipq_v((P1), (P2), (P3), (P4))

#endif /* } defined(__ARM_NEON__) || defined(__AARCH_FEATURE_ADVSIMD) */

/*************************************
 ************ Clang 3.9 **************
 *************************************/

#if (__cov_clang_version_lt(3, 9)) /* { */
/* These intrinsics were removed in clang 3.9. { */
/* Some but not all of these intrinsics were removed in Xcode 8.0. { */

/* clang < 3.9 || Xcode < 8.0 */
#if !(__cov_xcode_version_ge(8, 0)) /* { */
extern double
__coverity___builtin_HEXAGON_F2_dfadd(
    double __a,
    double __b);
#define __builtin_HEXAGON_F2_dfadd(P0, P1) \
    __coverity___builtin_HEXAGON_F2_dfadd((P0), (P1))

extern double
__coverity___builtin_HEXAGON_F2_dffixupd(
    double __a,
    double __b);
#define __builtin_HEXAGON_F2_dffixupd(P0, P1) \
    __coverity___builtin_HEXAGON_F2_dffixupd((P0), (P1))

extern double
__coverity___builtin_HEXAGON_F2_dffixupn(
    double __a,
    double __b);
#define __builtin_HEXAGON_F2_dffixupn(P0, P1) \
    __coverity___builtin_HEXAGON_F2_dffixupn((P0), (P1))

extern double
__coverity___builtin_HEXAGON_F2_dffixupr(
    double __a);
#define __builtin_HEXAGON_F2_dffixupr(P0) \
    __coverity___builtin_HEXAGON_F2_dffixupr((P0))

extern double
__coverity___builtin_HEXAGON_F2_dffma(
    double __a,
    double __b,
    double __c);
#define __builtin_HEXAGON_F2_dffma(P0, P1, P2) \
    __coverity___builtin_HEXAGON_F2_dffma((P0), (P1), (P2))

extern double
__coverity___builtin_HEXAGON_F2_dffma_lib(
    double __a,
    double __b,
    double __c);
#define __builtin_HEXAGON_F2_dffma_lib(P0, P1, P2) \
    __coverity___builtin_HEXAGON_F2_dffma_lib((P0), (P1), (P2))

extern double
__coverity___builtin_HEXAGON_F2_dffma_sc(
    double __a,
    double __b,
    double __c,
    int __d);
#define __builtin_HEXAGON_F2_dffma_sc(P0, P1, P2, P3) \
    __coverity___builtin_HEXAGON_F2_dffma_sc((P0), (P1), (P2), (P3))

extern double
__coverity___builtin_HEXAGON_F2_dffms(
    double __a,
    double __b,
    double __c);
#define __builtin_HEXAGON_F2_dffms(P0, P1, P2) \
    __coverity___builtin_HEXAGON_F2_dffms((P0), (P1), (P2))

extern double
__coverity___builtin_HEXAGON_F2_dffms_lib(
    double __a,
    double __b,
    double __c);
#define __builtin_HEXAGON_F2_dffms_lib(P0, P1, P2) \
    __coverity___builtin_HEXAGON_F2_dffms_lib((P0), (P1), (P2))

extern double
__coverity___builtin_HEXAGON_F2_dfmax(
    double __a,
    double __b);
#define __builtin_HEXAGON_F2_dfmax(P0, P1) \
    __coverity___builtin_HEXAGON_F2_dfmax((P0), (P1))

extern double
__coverity___builtin_HEXAGON_F2_dfmin(
    double __a,
    double __b);
#define __builtin_HEXAGON_F2_dfmin(P0, P1) \
    __coverity___builtin_HEXAGON_F2_dfmin((P0), (P1))

extern double
__coverity___builtin_HEXAGON_F2_dfmpy(
    double __a,
    double __b);
#define __builtin_HEXAGON_F2_dfmpy(P0, P1) \
    __coverity___builtin_HEXAGON_F2_dfmpy((P0), (P1))

extern double
__coverity___builtin_HEXAGON_F2_dfsub(
    double __a,
    double __b);
#define __builtin_HEXAGON_F2_dfsub(P0, P1) \
    __coverity___builtin_HEXAGON_F2_dfsub((P0), (P1))

extern __cov_compat_bool
__coverity___builtin_amdgpu_class(
    double __a,
    int __b);
#define __builtin_amdgpu_class(P0, P1) \
    __coverity___builtin_amdgpu_class((P0), (P1))

extern __cov_compat_bool
__coverity___builtin_amdgpu_classf(
    float __a,
    int __b);
#define __builtin_amdgpu_classf(P0, P1) \
    __coverity___builtin_amdgpu_classf((P0), (P1))

extern double
__coverity___builtin_amdgpu_div_fixup(
    double __a,
    double __b,
    double __c);
#define __builtin_amdgpu_div_fixup(P0, P1, P2) \
    __coverity___builtin_amdgpu_div_fixup((P0), (P1), (P2))

extern float
__coverity___builtin_amdgpu_div_fixupf(
    float __a,
    float __b,
    float __c);
#define __builtin_amdgpu_div_fixupf(P0, P1, P2) \
    __coverity___builtin_amdgpu_div_fixupf((P0), (P1), (P2))

extern double
__coverity___builtin_amdgpu_div_scale(
    double __a,
    double __b,
    __cov_compat_bool __c,
    __cov_compat_bool* __d);
#define __builtin_amdgpu_div_scale(P0, P1, P2, P3) \
    __coverity___builtin_amdgpu_div_scale((P0), (P1), (P2), (P3))

extern float
__coverity___builtin_amdgpu_div_scalef(
    float __a,
    float __b,
    __cov_compat_bool __c,
    __cov_compat_bool* __d);
#define __builtin_amdgpu_div_scalef(P0, P1, P2, P3) \
    __coverity___builtin_amdgpu_div_scalef((P0), (P1), (P2), (P3))

extern double
__coverity___builtin_amdgpu_ldexp(
    double __a,
    int __b);
#define __builtin_amdgpu_ldexp(P0, P1) \
    __coverity___builtin_amdgpu_ldexp((P0), (P1))

extern float
__coverity___builtin_amdgpu_ldexpf(
    float __a,
    int __b);
#define __builtin_amdgpu_ldexpf(P0, P1) \
    __coverity___builtin_amdgpu_ldexpf((P0), (P1))

extern double
__coverity___builtin_amdgpu_rcp(
    double __a);
#define __builtin_amdgpu_rcp(P0) \
    __coverity___builtin_amdgpu_rcp((P0))

extern float
__coverity___builtin_amdgpu_rcpf(
    float __a);
#define __builtin_amdgpu_rcpf(P0) \
    __coverity___builtin_amdgpu_rcpf((P0))

extern double
__coverity___builtin_amdgpu_rsq(
    double __a);
#define __builtin_amdgpu_rsq(P0) \
    __coverity___builtin_amdgpu_rsq((P0))

extern double
__coverity___builtin_amdgpu_rsq_clamped(
    double __a);
#define __builtin_amdgpu_rsq_clamped(P0) \
    __coverity___builtin_amdgpu_rsq_clamped((P0))

extern float
__coverity___builtin_amdgpu_rsq_clampedf(
    float __a);
#define __builtin_amdgpu_rsq_clampedf(P0) \
    __coverity___builtin_amdgpu_rsq_clampedf((P0))

extern float
__coverity___builtin_amdgpu_rsqf(
    float __a);
#define __builtin_amdgpu_rsqf(P0) \
    __coverity___builtin_amdgpu_rsqf((P0))

extern double
__coverity___builtin_amdgpu_trig_preop(
    double __a,
    int __b);
#define __builtin_amdgpu_trig_preop(P0, P1) \
    __coverity___builtin_amdgpu_trig_preop((P0), (P1))

extern float
__coverity___builtin_amdgpu_trig_preopf(
    float __a,
    int __b);
#define __builtin_amdgpu_trig_preopf(P0, P1) \
    __coverity___builtin_amdgpu_trig_preopf((P0), (P1))

#endif /* } clang < 3.9 || Xcode < 8.0 */

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_addsd_round(
    double __attribute__((vector_size(16))) __a,
    double __attribute__((vector_size(16))) __b,
    double __attribute__((vector_size(16))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_addsd_round(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_addsd_round((P0), (P1), (P2), (P3), (P4))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_addss_round(
    float __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_addss_round(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_addss_round((P0), (P1), (P2), (P3), (P4))

extern char __attribute__((vector_size(16)))
__coverity___builtin_ia32_blendmb_128_mask(
    char __attribute__((vector_size(16))) __a,
    char __attribute__((vector_size(16))) __b,
    unsigned short __c);
#define __builtin_ia32_blendmb_128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_blendmb_128_mask((P0), (P1), (P2))

extern char __attribute__((vector_size(32)))
__coverity___builtin_ia32_blendmb_256_mask(
    char __attribute__((vector_size(32))) __a,
    char __attribute__((vector_size(32))) __b,
    unsigned int __c);
#define __builtin_ia32_blendmb_256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_blendmb_256_mask((P0), (P1), (P2))

extern char __attribute__((vector_size(64)))
__coverity___builtin_ia32_blendmb_512_mask(
    char __attribute__((vector_size(64))) __a,
    char __attribute__((vector_size(64))) __b,
    unsigned long long __c);
#define __builtin_ia32_blendmb_512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_blendmb_512_mask((P0), (P1), (P2))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_blendmd_128_mask(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    unsigned char __c);
#define __builtin_ia32_blendmd_128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_blendmd_128_mask((P0), (P1), (P2))

extern int __attribute__((vector_size(32)))
__coverity___builtin_ia32_blendmd_256_mask(
    int __attribute__((vector_size(32))) __a,
    int __attribute__((vector_size(32))) __b,
    unsigned char __c);
#define __builtin_ia32_blendmd_256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_blendmd_256_mask((P0), (P1), (P2))

extern int __attribute__((vector_size(64)))
__coverity___builtin_ia32_blendmd_512_mask(
    int __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    unsigned short __c);
#define __builtin_ia32_blendmd_512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_blendmd_512_mask((P0), (P1), (P2))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_blendmpd_128_mask(
    double __attribute__((vector_size(16))) __a,
    double __attribute__((vector_size(16))) __b,
    unsigned char __c);
#define __builtin_ia32_blendmpd_128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_blendmpd_128_mask((P0), (P1), (P2))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_blendmpd_256_mask(
    double __attribute__((vector_size(32))) __a,
    double __attribute__((vector_size(32))) __b,
    unsigned char __c);
#define __builtin_ia32_blendmpd_256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_blendmpd_256_mask((P0), (P1), (P2))

extern double __attribute__((vector_size(64)))
__coverity___builtin_ia32_blendmpd_512_mask(
    double __attribute__((vector_size(64))) __a,
    double __attribute__((vector_size(64))) __b,
    unsigned char __c);
#define __builtin_ia32_blendmpd_512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_blendmpd_512_mask((P0), (P1), (P2))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_blendmps_128_mask(
    float __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    unsigned char __c);
#define __builtin_ia32_blendmps_128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_blendmps_128_mask((P0), (P1), (P2))

extern float __attribute__((vector_size(32)))
__coverity___builtin_ia32_blendmps_256_mask(
    float __attribute__((vector_size(32))) __a,
    float __attribute__((vector_size(32))) __b,
    unsigned char __c);
#define __builtin_ia32_blendmps_256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_blendmps_256_mask((P0), (P1), (P2))

extern float __attribute__((vector_size(64)))
__coverity___builtin_ia32_blendmps_512_mask(
    float __attribute__((vector_size(64))) __a,
    float __attribute__((vector_size(64))) __b,
    unsigned short __c);
#define __builtin_ia32_blendmps_512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_blendmps_512_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_blendmq_128_mask(
    long long __attribute__((vector_size(16))) __a,
    long long __attribute__((vector_size(16))) __b,
    unsigned char __c);
#define __builtin_ia32_blendmq_128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_blendmq_128_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_blendmq_256_mask(
    long long __attribute__((vector_size(32))) __a,
    long long __attribute__((vector_size(32))) __b,
    unsigned char __c);
#define __builtin_ia32_blendmq_256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_blendmq_256_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_blendmq_512_mask(
    long long __attribute__((vector_size(64))) __a,
    long long __attribute__((vector_size(64))) __b,
    unsigned char __c);
#define __builtin_ia32_blendmq_512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_blendmq_512_mask((P0), (P1), (P2))

extern short __attribute__((vector_size(16)))
__coverity___builtin_ia32_blendmw_128_mask(
    short __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b,
    unsigned char __c);
#define __builtin_ia32_blendmw_128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_blendmw_128_mask((P0), (P1), (P2))

extern short __attribute__((vector_size(32)))
__coverity___builtin_ia32_blendmw_256_mask(
    short __attribute__((vector_size(32))) __a,
    short __attribute__((vector_size(32))) __b,
    unsigned short __c);
#define __builtin_ia32_blendmw_256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_blendmw_256_mask((P0), (P1), (P2))

extern short __attribute__((vector_size(64)))
__coverity___builtin_ia32_blendmw_512_mask(
    short __attribute__((vector_size(64))) __a,
    short __attribute__((vector_size(64))) __b,
    unsigned int __c);
#define __builtin_ia32_blendmw_512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_blendmw_512_mask((P0), (P1), (P2))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_cvtdq2pd(
    int __attribute__((vector_size(16))) __a);
#define __builtin_ia32_cvtdq2pd(P0) \
    __coverity___builtin_ia32_cvtdq2pd((P0))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_cvtdq2pd256(
    int __attribute__((vector_size(16))) __a);
#define __builtin_ia32_cvtdq2pd256(P0) \
    __coverity___builtin_ia32_cvtdq2pd256((P0))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_cvtps2pd(
    float __attribute__((vector_size(16))) __a);
#define __builtin_ia32_cvtps2pd(P0) \
    __coverity___builtin_ia32_cvtps2pd((P0))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_cvtps2pd256(
    float __attribute__((vector_size(16))) __a);
#define __builtin_ia32_cvtps2pd256(P0) \
    __coverity___builtin_ia32_cvtps2pd256((P0))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_divsd_round(
    double __attribute__((vector_size(16))) __a,
    double __attribute__((vector_size(16))) __b,
    double __attribute__((vector_size(16))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_divsd_round(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_divsd_round((P0), (P1), (P2), (P3), (P4))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_divss_round(
    float __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_divss_round(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_divss_round((P0), (P1), (P2), (P3), (P4))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_maxsd_round(
    double __attribute__((vector_size(16))) __a,
    double __attribute__((vector_size(16))) __b,
    double __attribute__((vector_size(16))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_maxsd_round(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_maxsd_round((P0), (P1), (P2), (P3), (P4))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_maxss_round(
    float __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_maxss_round(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_maxss_round((P0), (P1), (P2), (P3), (P4))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_minsd_round(
    double __attribute__((vector_size(16))) __a,
    double __attribute__((vector_size(16))) __b,
    double __attribute__((vector_size(16))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_minsd_round(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_minsd_round((P0), (P1), (P2), (P3), (P4))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_minss_round(
    float __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_minss_round(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_minss_round((P0), (P1), (P2), (P3), (P4))

extern void
__coverity___builtin_ia32_movntdq(
    long long __attribute__((vector_size(16)))* __a,
    long long __attribute__((vector_size(16))) __b);
#define __builtin_ia32_movntdq(P0, P1) \
    __coverity___builtin_ia32_movntdq((P0), (P1))

extern void
__coverity___builtin_ia32_movntdq256(
    long long __attribute__((vector_size(32)))* __a,
    long long __attribute__((vector_size(32))) __b);
#define __builtin_ia32_movntdq256(P0, P1) \
    __coverity___builtin_ia32_movntdq256((P0), (P1))

extern void
__coverity___builtin_ia32_movntpd(
    double* __a,
    double __attribute__((vector_size(16))) __b);
#define __builtin_ia32_movntpd(P0, P1) \
    __coverity___builtin_ia32_movntpd((P0), (P1))

extern void
__coverity___builtin_ia32_movntpd256(
    double* __a,
    double __attribute__((vector_size(32))) __b);
#define __builtin_ia32_movntpd256(P0, P1) \
    __coverity___builtin_ia32_movntpd256((P0), (P1))

extern void
__coverity___builtin_ia32_movntps(
    float* __a,
    float __attribute__((vector_size(16))) __b);
#define __builtin_ia32_movntps(P0, P1) \
    __coverity___builtin_ia32_movntps((P0), (P1))

extern void
__coverity___builtin_ia32_movntps256(
    float* __a,
    float __attribute__((vector_size(32))) __b);
#define __builtin_ia32_movntps256(P0, P1) \
    __coverity___builtin_ia32_movntps256((P0), (P1))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_mulsd_round(
    double __attribute__((vector_size(16))) __a,
    double __attribute__((vector_size(16))) __b,
    double __attribute__((vector_size(16))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_mulsd_round(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_mulsd_round((P0), (P1), (P2), (P3), (P4))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_mulss_round(
    float __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_mulss_round(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_mulss_round((P0), (P1), (P2), (P3), (P4))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_pandd128_mask(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    int __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_pandd128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pandd128_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(32)))
__coverity___builtin_ia32_pandd256_mask(
    int __attribute__((vector_size(32))) __a,
    int __attribute__((vector_size(32))) __b,
    int __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_pandd256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pandd256_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(64)))
__coverity___builtin_ia32_pandd512_mask(
    int __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    int __attribute__((vector_size(64))) __c,
    unsigned short __d);
#define __builtin_ia32_pandd512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pandd512_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_pandnd128_mask(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    int __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_pandnd128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pandnd128_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(32)))
__coverity___builtin_ia32_pandnd256_mask(
    int __attribute__((vector_size(32))) __a,
    int __attribute__((vector_size(32))) __b,
    int __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_pandnd256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pandnd256_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(64)))
__coverity___builtin_ia32_pandnd512_mask(
    int __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    int __attribute__((vector_size(64))) __c,
    unsigned short __d);
#define __builtin_ia32_pandnd512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pandnd512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pandnq128_mask(
    long long __attribute__((vector_size(16))) __a,
    long long __attribute__((vector_size(16))) __b,
    long long __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_pandnq128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pandnq128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pandnq256_mask(
    long long __attribute__((vector_size(32))) __a,
    long long __attribute__((vector_size(32))) __b,
    long long __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_pandnq256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pandnq256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_pandnq512_mask(
    long long __attribute__((vector_size(64))) __a,
    long long __attribute__((vector_size(64))) __b,
    long long __attribute__((vector_size(64))) __c,
    unsigned char __d);
#define __builtin_ia32_pandnq512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pandnq512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pandq128_mask(
    long long __attribute__((vector_size(16))) __a,
    long long __attribute__((vector_size(16))) __b,
    long long __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_pandq128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pandq128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pandq256_mask(
    long long __attribute__((vector_size(32))) __a,
    long long __attribute__((vector_size(32))) __b,
    long long __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_pandq256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pandq256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_pandq512_mask(
    long long __attribute__((vector_size(64))) __a,
    long long __attribute__((vector_size(64))) __b,
    long long __attribute__((vector_size(64))) __c,
    unsigned char __d);
#define __builtin_ia32_pandq512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pandq512_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmovsxbd256(
    char __attribute__((vector_size(16))) __a);
#define __builtin_ia32_pmovsxbd256(P0) \
    __coverity___builtin_ia32_pmovsxbd256((P0))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmovsxbq256(
    char __attribute__((vector_size(16))) __a);
#define __builtin_ia32_pmovsxbq256(P0) \
    __coverity___builtin_ia32_pmovsxbq256((P0))

extern short __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmovsxbw256(
    char __attribute__((vector_size(16))) __a);
#define __builtin_ia32_pmovsxbw256(P0) \
    __coverity___builtin_ia32_pmovsxbw256((P0))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmovsxdq256(
    int __attribute__((vector_size(16))) __a);
#define __builtin_ia32_pmovsxdq256(P0) \
    __coverity___builtin_ia32_pmovsxdq256((P0))

extern int __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmovsxwd256(
    short __attribute__((vector_size(16))) __a);
#define __builtin_ia32_pmovsxwd256(P0) \
    __coverity___builtin_ia32_pmovsxwd256((P0))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmovsxwq256(
    short __attribute__((vector_size(16))) __a);
#define __builtin_ia32_pmovsxwq256(P0) \
    __coverity___builtin_ia32_pmovsxwq256((P0))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmovzxbd128(
    char __attribute__((vector_size(16))) __a);
#define __builtin_ia32_pmovzxbd128(P0) \
    __coverity___builtin_ia32_pmovzxbd128((P0))

extern int __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmovzxbd256(
    char __attribute__((vector_size(16))) __a);
#define __builtin_ia32_pmovzxbd256(P0) \
    __coverity___builtin_ia32_pmovzxbd256((P0))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmovzxbq128(
    char __attribute__((vector_size(16))) __a);
#define __builtin_ia32_pmovzxbq128(P0) \
    __coverity___builtin_ia32_pmovzxbq128((P0))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmovzxbq256(
    char __attribute__((vector_size(16))) __a);
#define __builtin_ia32_pmovzxbq256(P0) \
    __coverity___builtin_ia32_pmovzxbq256((P0))

extern short __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmovzxbw128(
    char __attribute__((vector_size(16))) __a);
#define __builtin_ia32_pmovzxbw128(P0) \
    __coverity___builtin_ia32_pmovzxbw128((P0))

extern short __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmovzxbw256(
    char __attribute__((vector_size(16))) __a);
#define __builtin_ia32_pmovzxbw256(P0) \
    __coverity___builtin_ia32_pmovzxbw256((P0))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmovzxdq128(
    int __attribute__((vector_size(16))) __a);
#define __builtin_ia32_pmovzxdq128(P0) \
    __coverity___builtin_ia32_pmovzxdq128((P0))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmovzxdq256(
    int __attribute__((vector_size(16))) __a);
#define __builtin_ia32_pmovzxdq256(P0) \
    __coverity___builtin_ia32_pmovzxdq256((P0))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmovzxwd128(
    short __attribute__((vector_size(16))) __a);
#define __builtin_ia32_pmovzxwd128(P0) \
    __coverity___builtin_ia32_pmovzxwd128((P0))

extern int __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmovzxwd256(
    short __attribute__((vector_size(16))) __a);
#define __builtin_ia32_pmovzxwd256(P0) \
    __coverity___builtin_ia32_pmovzxwd256((P0))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmovzxwq128(
    short __attribute__((vector_size(16))) __a);
#define __builtin_ia32_pmovzxwq128(P0) \
    __coverity___builtin_ia32_pmovzxwq128((P0))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmovzxwq256(
    short __attribute__((vector_size(16))) __a);
#define __builtin_ia32_pmovzxwq256(P0) \
    __coverity___builtin_ia32_pmovzxwq256((P0))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmulld128(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b);
#define __builtin_ia32_pmulld128(P0, P1) \
    __coverity___builtin_ia32_pmulld128((P0), (P1))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_pord128_mask(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    int __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_pord128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pord128_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(32)))
__coverity___builtin_ia32_pord256_mask(
    int __attribute__((vector_size(32))) __a,
    int __attribute__((vector_size(32))) __b,
    int __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_pord256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pord256_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(64)))
__coverity___builtin_ia32_pord512_mask(
    int __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    int __attribute__((vector_size(64))) __c,
    unsigned short __d);
#define __builtin_ia32_pord512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pord512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_porq128_mask(
    long long __attribute__((vector_size(16))) __a,
    long long __attribute__((vector_size(16))) __b,
    long long __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_porq128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_porq128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_porq256_mask(
    long long __attribute__((vector_size(32))) __a,
    long long __attribute__((vector_size(32))) __b,
    long long __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_porq256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_porq256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_porq512_mask(
    long long __attribute__((vector_size(64))) __a,
    long long __attribute__((vector_size(64))) __b,
    long long __attribute__((vector_size(64))) __c,
    unsigned char __d);
#define __builtin_ia32_porq512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_porq512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pslldqi256(
    long long __attribute__((vector_size(32))) __a,
    const int __b);
#define __builtin_ia32_pslldqi256(P0, P1) \
    __coverity___builtin_ia32_pslldqi256((P0), (P1))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_psrldqi256(
    long long __attribute__((vector_size(32))) __a,
    const int __b);
#define __builtin_ia32_psrldqi256(P0, P1) \
    __coverity___builtin_ia32_psrldqi256((P0), (P1))

extern char __attribute__((vector_size(16)))
__coverity___builtin_ia32_punpckhbw128_mask(
    char __attribute__((vector_size(16))) __a,
    char __attribute__((vector_size(16))) __b,
    char __attribute__((vector_size(16))) __c,
    unsigned short __d);
#define __builtin_ia32_punpckhbw128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_punpckhbw128_mask((P0), (P1), (P2), (P3))

extern char __attribute__((vector_size(32)))
__coverity___builtin_ia32_punpckhbw256_mask(
    char __attribute__((vector_size(32))) __a,
    char __attribute__((vector_size(32))) __b,
    char __attribute__((vector_size(32))) __c,
    unsigned int __d);
#define __builtin_ia32_punpckhbw256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_punpckhbw256_mask((P0), (P1), (P2), (P3))

extern char __attribute__((vector_size(64)))
__coverity___builtin_ia32_punpckhbw512_mask(
    char __attribute__((vector_size(64))) __a,
    char __attribute__((vector_size(64))) __b,
    char __attribute__((vector_size(64))) __c,
    unsigned long long __d);
#define __builtin_ia32_punpckhbw512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_punpckhbw512_mask((P0), (P1), (P2), (P3))

extern short __attribute__((vector_size(16)))
__coverity___builtin_ia32_punpckhwd128_mask(
    short __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b,
    short __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_punpckhwd128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_punpckhwd128_mask((P0), (P1), (P2), (P3))

extern short __attribute__((vector_size(32)))
__coverity___builtin_ia32_punpckhwd256_mask(
    short __attribute__((vector_size(32))) __a,
    short __attribute__((vector_size(32))) __b,
    short __attribute__((vector_size(32))) __c,
    unsigned short __d);
#define __builtin_ia32_punpckhwd256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_punpckhwd256_mask((P0), (P1), (P2), (P3))

extern short __attribute__((vector_size(64)))
__coverity___builtin_ia32_punpckhwd512_mask(
    short __attribute__((vector_size(64))) __a,
    short __attribute__((vector_size(64))) __b,
    short __attribute__((vector_size(64))) __c,
    unsigned int __d);
#define __builtin_ia32_punpckhwd512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_punpckhwd512_mask((P0), (P1), (P2), (P3))

extern char __attribute__((vector_size(16)))
__coverity___builtin_ia32_punpcklbw128_mask(
    char __attribute__((vector_size(16))) __a,
    char __attribute__((vector_size(16))) __b,
    char __attribute__((vector_size(16))) __c,
    unsigned short __d);
#define __builtin_ia32_punpcklbw128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_punpcklbw128_mask((P0), (P1), (P2), (P3))

extern char __attribute__((vector_size(32)))
__coverity___builtin_ia32_punpcklbw256_mask(
    char __attribute__((vector_size(32))) __a,
    char __attribute__((vector_size(32))) __b,
    char __attribute__((vector_size(32))) __c,
    unsigned int __d);
#define __builtin_ia32_punpcklbw256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_punpcklbw256_mask((P0), (P1), (P2), (P3))

extern char __attribute__((vector_size(64)))
__coverity___builtin_ia32_punpcklbw512_mask(
    char __attribute__((vector_size(64))) __a,
    char __attribute__((vector_size(64))) __b,
    char __attribute__((vector_size(64))) __c,
    unsigned long long __d);
#define __builtin_ia32_punpcklbw512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_punpcklbw512_mask((P0), (P1), (P2), (P3))

extern short __attribute__((vector_size(16)))
__coverity___builtin_ia32_punpcklwd128_mask(
    short __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b,
    short __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_punpcklwd128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_punpcklwd128_mask((P0), (P1), (P2), (P3))

extern short __attribute__((vector_size(32)))
__coverity___builtin_ia32_punpcklwd256_mask(
    short __attribute__((vector_size(32))) __a,
    short __attribute__((vector_size(32))) __b,
    short __attribute__((vector_size(32))) __c,
    unsigned short __d);
#define __builtin_ia32_punpcklwd256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_punpcklwd256_mask((P0), (P1), (P2), (P3))

extern short __attribute__((vector_size(64)))
__coverity___builtin_ia32_punpcklwd512_mask(
    short __attribute__((vector_size(64))) __a,
    short __attribute__((vector_size(64))) __b,
    short __attribute__((vector_size(64))) __c,
    unsigned int __d);
#define __builtin_ia32_punpcklwd512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_punpcklwd512_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_pxord128_mask(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    int __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_pxord128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pxord128_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(32)))
__coverity___builtin_ia32_pxord256_mask(
    int __attribute__((vector_size(32))) __a,
    int __attribute__((vector_size(32))) __b,
    int __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_pxord256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pxord256_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(64)))
__coverity___builtin_ia32_pxord512_mask(
    int __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    int __attribute__((vector_size(64))) __c,
    unsigned short __d);
#define __builtin_ia32_pxord512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pxord512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pxorq128_mask(
    long long __attribute__((vector_size(16))) __a,
    long long __attribute__((vector_size(16))) __b,
    long long __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_pxorq128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pxorq128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pxorq256_mask(
    long long __attribute__((vector_size(32))) __a,
    long long __attribute__((vector_size(32))) __b,
    long long __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_pxorq256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pxorq256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_pxorq512_mask(
    long long __attribute__((vector_size(64))) __a,
    long long __attribute__((vector_size(64))) __b,
    long long __attribute__((vector_size(64))) __c,
    unsigned char __d);
#define __builtin_ia32_pxorq512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pxorq512_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_rcp14sd(
    double __attribute__((vector_size(16))) __a,
    double __attribute__((vector_size(16))) __b,
    double __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_rcp14sd(P0, P1, P2, P3) \
    __coverity___builtin_ia32_rcp14sd((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_rcp14ss(
    float __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_rcp14ss(P0, P1, P2, P3) \
    __coverity___builtin_ia32_rcp14ss((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_rcp28sd_round(
    double __attribute__((vector_size(16))) __a,
    double __attribute__((vector_size(16))) __b,
    double __attribute__((vector_size(16))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_rcp28sd_round(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_rcp28sd_round((P0), (P1), (P2), (P3), (P4))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_rcp28ss_round(
    float __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_rcp28ss_round(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_rcp28ss_round((P0), (P1), (P2), (P3), (P4))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_rsqrt14sd(
    double __attribute__((vector_size(16))) __a,
    double __attribute__((vector_size(16))) __b,
    double __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_rsqrt14sd(P0, P1, P2, P3) \
    __coverity___builtin_ia32_rsqrt14sd((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_rsqrt14ss(
    float __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_rsqrt14ss(P0, P1, P2, P3) \
    __coverity___builtin_ia32_rsqrt14ss((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_rsqrt28sd_round(
    double __attribute__((vector_size(16))) __a,
    double __attribute__((vector_size(16))) __b,
    double __attribute__((vector_size(16))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_rsqrt28sd_round(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_rsqrt28sd_round((P0), (P1), (P2), (P3), (P4))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_rsqrt28ss_round(
    float __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_rsqrt28ss_round(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_rsqrt28ss_round((P0), (P1), (P2), (P3), (P4))

extern void
__coverity___builtin_ia32_storedqu(
    char* __a,
    char __attribute__((vector_size(16))) __b);
#define __builtin_ia32_storedqu(P0, P1) \
    __coverity___builtin_ia32_storedqu((P0), (P1))

extern void
__coverity___builtin_ia32_storedqu256(
    char* __a,
    char __attribute__((vector_size(32))) __b);
#define __builtin_ia32_storedqu256(P0, P1) \
    __coverity___builtin_ia32_storedqu256((P0), (P1))

extern void
__coverity___builtin_ia32_storeupd(
    double* __a,
    double __attribute__((vector_size(16))) __b);
#define __builtin_ia32_storeupd(P0, P1) \
    __coverity___builtin_ia32_storeupd((P0), (P1))

extern void
__coverity___builtin_ia32_storeupd256(
    double* __a,
    double __attribute__((vector_size(32))) __b);
#define __builtin_ia32_storeupd256(P0, P1) \
    __coverity___builtin_ia32_storeupd256((P0), (P1))

extern void
__coverity___builtin_ia32_storeups(
    float* __a,
    float __attribute__((vector_size(16))) __b);
#define __builtin_ia32_storeups(P0, P1) \
    __coverity___builtin_ia32_storeups((P0), (P1))

extern void
__coverity___builtin_ia32_storeups256(
    float* __a,
    float __attribute__((vector_size(32))) __b);
#define __builtin_ia32_storeups256(P0, P1) \
    __coverity___builtin_ia32_storeups256((P0), (P1))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_subsd_round(
    double __attribute__((vector_size(16))) __a,
    double __attribute__((vector_size(16))) __b,
    double __attribute__((vector_size(16))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_subsd_round(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_subsd_round((P0), (P1), (P2), (P3), (P4))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_subss_round(
    float __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_subss_round(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_subss_round((P0), (P1), (P2), (P3), (P4))

extern float __attribute__((vector_size(64)))
__coverity___builtin_ia32_vcvtph2ps512(
    short __attribute__((vector_size(32))) __a);
#define __builtin_ia32_vcvtph2ps512(P0) \
    __coverity___builtin_ia32_vcvtph2ps512((P0))

extern short __attribute__((vector_size(32)))
__coverity___builtin_ia32_vcvtps2ph512(
    float __attribute__((vector_size(64))) __a,
    const int __b);
#define __builtin_ia32_vcvtps2ph512(P0, P1) \
    __coverity___builtin_ia32_vcvtps2ph512((P0), (P1))

/* clang < 3.9 || Xcode < 8.0 */
#if !(__cov_xcode_version_ge(8, 0)) /* { */
extern signed char __attribute__((vector_size(8)))
__coverity___builtin_neon_vfms_v(
    signed char __attribute__((vector_size(8))) __a,
    signed char __attribute__((vector_size(8))) __b,
    signed char __attribute__((vector_size(8))) __c,
    int __d);
#define __builtin_neon_vfms_v(P0, P1, P2, P3) \
    __coverity___builtin_neon_vfms_v((P0), (P1), (P2), (P3))

extern signed char __attribute__((vector_size(16)))
__coverity___builtin_neon_vfmsq_v(
    signed char __attribute__((vector_size(16))) __a,
    signed char __attribute__((vector_size(16))) __b,
    signed char __attribute__((vector_size(16))) __c,
    int __d);
#define __builtin_neon_vfmsq_v(P0, P1, P2, P3) \
    __coverity___builtin_neon_vfmsq_v((P0), (P1), (P2), (P3))

extern void
__coverity___builtin_ptx_bar_sync(
    int __a);
#define __builtin_ptx_bar_sync(P0) \
    __coverity___builtin_ptx_bar_sync((P0))

extern int
__coverity___builtin_ptx_read_clock();
#define __builtin_ptx_read_clock() \
    __coverity___builtin_ptx_read_clock()

extern int
__coverity___builtin_ptx_read_ctaid_w();
#define __builtin_ptx_read_ctaid_w() \
    __coverity___builtin_ptx_read_ctaid_w()

extern int
__coverity___builtin_ptx_read_ctaid_x();
#define __builtin_ptx_read_ctaid_x() \
    __coverity___builtin_ptx_read_ctaid_x()

extern int
__coverity___builtin_ptx_read_ctaid_y();
#define __builtin_ptx_read_ctaid_y() \
    __coverity___builtin_ptx_read_ctaid_y()

extern int
__coverity___builtin_ptx_read_ctaid_z();
#define __builtin_ptx_read_ctaid_z() \
    __coverity___builtin_ptx_read_ctaid_z()

extern int
__coverity___builtin_ptx_read_gridid();
#define __builtin_ptx_read_gridid() \
    __coverity___builtin_ptx_read_gridid()

extern int
__coverity___builtin_ptx_read_laneid();
#define __builtin_ptx_read_laneid() \
    __coverity___builtin_ptx_read_laneid()

extern int
__coverity___builtin_ptx_read_lanemask_eq();
#define __builtin_ptx_read_lanemask_eq() \
    __coverity___builtin_ptx_read_lanemask_eq()

extern int
__coverity___builtin_ptx_read_lanemask_ge();
#define __builtin_ptx_read_lanemask_ge() \
    __coverity___builtin_ptx_read_lanemask_ge()

extern int
__coverity___builtin_ptx_read_lanemask_gt();
#define __builtin_ptx_read_lanemask_gt() \
    __coverity___builtin_ptx_read_lanemask_gt()

extern int
__coverity___builtin_ptx_read_lanemask_le();
#define __builtin_ptx_read_lanemask_le() \
    __coverity___builtin_ptx_read_lanemask_le()

extern int
__coverity___builtin_ptx_read_lanemask_lt();
#define __builtin_ptx_read_lanemask_lt() \
    __coverity___builtin_ptx_read_lanemask_lt()

extern int
__coverity___builtin_ptx_read_nctaid_w();
#define __builtin_ptx_read_nctaid_w() \
    __coverity___builtin_ptx_read_nctaid_w()

extern int
__coverity___builtin_ptx_read_nctaid_x();
#define __builtin_ptx_read_nctaid_x() \
    __coverity___builtin_ptx_read_nctaid_x()

extern int
__coverity___builtin_ptx_read_nctaid_y();
#define __builtin_ptx_read_nctaid_y() \
    __coverity___builtin_ptx_read_nctaid_y()

extern int
__coverity___builtin_ptx_read_nctaid_z();
#define __builtin_ptx_read_nctaid_z() \
    __coverity___builtin_ptx_read_nctaid_z()

extern int
__coverity___builtin_ptx_read_nsmid();
#define __builtin_ptx_read_nsmid() \
    __coverity___builtin_ptx_read_nsmid()

extern int
__coverity___builtin_ptx_read_ntid_w();
#define __builtin_ptx_read_ntid_w() \
    __coverity___builtin_ptx_read_ntid_w()

extern int
__coverity___builtin_ptx_read_ntid_x();
#define __builtin_ptx_read_ntid_x() \
    __coverity___builtin_ptx_read_ntid_x()

extern int
__coverity___builtin_ptx_read_ntid_y();
#define __builtin_ptx_read_ntid_y() \
    __coverity___builtin_ptx_read_ntid_y()

extern int
__coverity___builtin_ptx_read_ntid_z();
#define __builtin_ptx_read_ntid_z() \
    __coverity___builtin_ptx_read_ntid_z()

extern int
__coverity___builtin_ptx_read_nwarpid();
#define __builtin_ptx_read_nwarpid() \
    __coverity___builtin_ptx_read_nwarpid()

extern int
__coverity___builtin_ptx_read_pm0();
#define __builtin_ptx_read_pm0() \
    __coverity___builtin_ptx_read_pm0()

extern int
__coverity___builtin_ptx_read_pm1();
#define __builtin_ptx_read_pm1() \
    __coverity___builtin_ptx_read_pm1()

extern int
__coverity___builtin_ptx_read_pm2();
#define __builtin_ptx_read_pm2() \
    __coverity___builtin_ptx_read_pm2()

extern int
__coverity___builtin_ptx_read_pm3();
#define __builtin_ptx_read_pm3() \
    __coverity___builtin_ptx_read_pm3()

extern int
__coverity___builtin_ptx_read_smid();
#define __builtin_ptx_read_smid() \
    __coverity___builtin_ptx_read_smid()

extern int
__coverity___builtin_ptx_read_tid_w();
#define __builtin_ptx_read_tid_w() \
    __coverity___builtin_ptx_read_tid_w()

extern int
__coverity___builtin_ptx_read_tid_x();
#define __builtin_ptx_read_tid_x() \
    __coverity___builtin_ptx_read_tid_x()

extern int
__coverity___builtin_ptx_read_tid_y();
#define __builtin_ptx_read_tid_y() \
    __coverity___builtin_ptx_read_tid_y()

extern int
__coverity___builtin_ptx_read_tid_z();
#define __builtin_ptx_read_tid_z() \
    __coverity___builtin_ptx_read_tid_z()

extern int
__coverity___builtin_ptx_read_warpid();
#define __builtin_ptx_read_warpid() \
    __coverity___builtin_ptx_read_warpid()

extern __cov_compat_size_t
__coverity___builtin_wasm_memory_size();
#define __builtin_wasm_memory_size() \
    __coverity___builtin_wasm_memory_size()

extern void
__coverity___nvvm_bar0();
#define __nvvm_bar0() \
    __coverity___nvvm_bar0()

/* } These prototypes were changed by clang 3.9. { */

extern void
__coverity___builtin_arm_cdp(
    unsigned int __a,
    unsigned int __b,
    unsigned int __c,
    unsigned int __d,
    unsigned int __e,
    unsigned int __f);
#define __builtin_arm_cdp(P0, P1, P2, P3, P4, P5) \
    __coverity___builtin_arm_cdp((P0), (P1), (P2), (P3), (P4), (P5))

extern void
__coverity___builtin_arm_cdp2(
    unsigned int __a,
    unsigned int __b,
    unsigned int __c,
    unsigned int __d,
    unsigned int __e,
    unsigned int __f);
#define __builtin_arm_cdp2(P0, P1, P2, P3, P4, P5) \
    __coverity___builtin_arm_cdp2((P0), (P1), (P2), (P3), (P4), (P5))

extern long long*
__coverity___builtin_circ_ldd(
    long long* __a,
    long long* __b,
    int __c,
    int __d);
#define __builtin_circ_ldd(P0, P1, P2, P3) \
    __coverity___builtin_circ_ldd((P0), (P1), (P2), (P3))

#endif /* } clang < 3.9 || Xcode < 8.0 */

extern double __attribute__((vector_size(64)))
__coverity___builtin_ia32_loadapd512_mask(
    const void* __a,
    double __attribute__((vector_size(64))) __b,
    unsigned char __c);
#define __builtin_ia32_loadapd512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_loadapd512_mask((P0), (P1), (P2))

extern float __attribute__((vector_size(64)))
__coverity___builtin_ia32_loadaps512_mask(
    const void* __a,
    float __attribute__((vector_size(64))) __b,
    unsigned short __c);
#define __builtin_ia32_loadaps512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_loadaps512_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_loaddqudi512_mask(
    const void* __a,
    long long __attribute__((vector_size(64))) __b,
    unsigned char __c);
#define __builtin_ia32_loaddqudi512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_loaddqudi512_mask((P0), (P1), (P2))

extern int __attribute__((vector_size(64)))
__coverity___builtin_ia32_loaddqusi512_mask(
    const void* __a,
    int __attribute__((vector_size(64))) __b,
    unsigned short __c);
#define __builtin_ia32_loaddqusi512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_loaddqusi512_mask((P0), (P1), (P2))

extern double __attribute__((vector_size(64)))
__coverity___builtin_ia32_loadupd512_mask(
    const void* __a,
    double __attribute__((vector_size(64))) __b,
    unsigned char __c);
#define __builtin_ia32_loadupd512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_loadupd512_mask((P0), (P1), (P2))

extern float __attribute__((vector_size(64)))
__coverity___builtin_ia32_loadups512_mask(
    const void* __a,
    float __attribute__((vector_size(64))) __b,
    unsigned short __c);
#define __builtin_ia32_loadups512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_loadups512_mask((P0), (P1), (P2))

extern char __attribute__((vector_size(16)))
__coverity___builtin_ia32_palignr128(
    char __attribute__((vector_size(16))) __a,
    char __attribute__((vector_size(16))) __b,
    const char __c);
#define __builtin_ia32_palignr128(P0, P1, P2) \
    __coverity___builtin_ia32_palignr128((P0), (P1), (P2))

extern char __attribute__((vector_size(32)))
__coverity___builtin_ia32_palignr256(
    char __attribute__((vector_size(32))) __a,
    char __attribute__((vector_size(32))) __b,
    const char __c);
#define __builtin_ia32_palignr256(P0, P1, P2) \
    __coverity___builtin_ia32_palignr256((P0), (P1), (P2))

extern void
__coverity___builtin_ia32_storeapd512_mask(
    void* __a,
    double __attribute__((vector_size(64))) __b,
    unsigned char __c);
#define __builtin_ia32_storeapd512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_storeapd512_mask((P0), (P1), (P2))

extern void
__coverity___builtin_ia32_storeaps512_mask(
    void* __a,
    float __attribute__((vector_size(64))) __b,
    unsigned short __c);
#define __builtin_ia32_storeaps512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_storeaps512_mask((P0), (P1), (P2))

extern void
__coverity___builtin_ia32_storedqudi512_mask(
    void* __a,
    long long __attribute__((vector_size(64))) __b,
    unsigned char __c);
#define __builtin_ia32_storedqudi512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_storedqudi512_mask((P0), (P1), (P2))

extern void
__coverity___builtin_ia32_storedqusi512_mask(
    void* __a,
    int __attribute__((vector_size(64))) __b,
    unsigned short __c);
#define __builtin_ia32_storedqusi512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_storedqusi512_mask((P0), (P1), (P2))

extern void
__coverity___builtin_ia32_storeupd512_mask(
    void* __a,
    double __attribute__((vector_size(64))) __b,
    unsigned char __c);
#define __builtin_ia32_storeupd512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_storeupd512_mask((P0), (P1), (P2))

extern void
__coverity___builtin_ia32_storeups512_mask(
    void* __a,
    float __attribute__((vector_size(64))) __b,
    unsigned short __c);
#define __builtin_ia32_storeups512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_storeups512_mask((P0), (P1), (P2))

/* } These prototypes were modified in clang 3.6 and removed in clang 3.9. { */
#if (!__coverity_assume_xcode__ && __cov_clang_version_gt(3, 5)) || \
    (__cov_xcode_version_gt(6, 3) && __cov_xcode_version_lt(8, 0))

extern double
__coverity___builtin_amdgpu_div_fmas(
    double __a,
    double __b,
    double __c,
    __cov_compat_bool __d);
#define __builtin_amdgpu_div_fmas(P0, P1, P2, P3) \
    __coverity___builtin_amdgpu_div_fmas((P0), (P1), (P2), (P3))

extern float
__coverity___builtin_amdgpu_div_fmasf(
    float __a,
    float __b,
    float __c,
    __cov_compat_bool __d);
#define __builtin_amdgpu_div_fmasf(P0, P1, P2, P3) \
    __coverity___builtin_amdgpu_div_fmasf((P0), (P1), (P2), (P3))

#endif /* } Clang > 3.5 || 6.3 < xcode < 8.0 */

/* } These builtins were modified in clang 3.8 and again in clang 3.9. { */
#if (__cov_clang_version_ge(3, 8)) && (!__cov_xcode_version_ge(8, 0))
extern void
__coverity___builtin_arm_mcrr(
    const unsigned int __a,
    const unsigned int __b,
    unsigned int __c,
    unsigned int __d,
    const unsigned int __e);
#define __builtin_arm_mcrr(P0, P1, P2, P3, P4) \
    __coverity___builtin_arm_mcrr((P0), (P1), (P2), (P3), (P4))

extern void
__coverity___builtin_arm_mcrr2(
    const unsigned int __a,
    const unsigned int __b,
    unsigned int __c,
    unsigned int __d,
    const unsigned int __e);
#define __builtin_arm_mcrr2(P0, P1, P2, P3, P4) \
    __coverity___builtin_arm_mcrr2((P0), (P1), (P2), (P3), (P4))
#endif /* } Clang >= 3.8 && !(xcode >= 8.0) */

/* } These builtins were modified in clang 3.7 and again in clang 3.9. { */
#if (!__coverity_assume_xcode__ && __cov_clang_version_gt(3, 6)) || \
    __cov_xcode_version_ge(7, 0) /* { */

extern float __attribute__((vector_size(32)))
__coverity___builtin_ia32_gatherdiv16sf(
    float __attribute__((vector_size(32))) __a,
    const void* __b,
    long long __attribute__((vector_size(64))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_gatherdiv16sf(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_gatherdiv16sf((P0), (P1), (P2), (P3), (P4))

extern int __attribute__((vector_size(32)))
__coverity___builtin_ia32_gatherdiv16si(
    int __attribute__((vector_size(32))) __a,
    const void* __b,
    long long __attribute__((vector_size(64))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_gatherdiv16si(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_gatherdiv16si((P0), (P1), (P2), (P3), (P4))

extern double __attribute__((vector_size(64)))
__coverity___builtin_ia32_gatherdiv8df(
    double __attribute__((vector_size(64))) __a,
    const void* __b,
    long long __attribute__((vector_size(64))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_gatherdiv8df(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_gatherdiv8df((P0), (P1), (P2), (P3), (P4))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_gatherdiv8di(
    long long __attribute__((vector_size(64))) __a,
    const void* __b,
    long long __attribute__((vector_size(64))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_gatherdiv8di(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_gatherdiv8di((P0), (P1), (P2), (P3), (P4))

extern void
__coverity___builtin_ia32_gatherpfdpd(
    unsigned char __a,
    int __attribute__((vector_size(32))) __b,
    const void* __c,
    const int __d,
    const int __e);
#define __builtin_ia32_gatherpfdpd(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_gatherpfdpd((P0), (P1), (P2), (P3), (P4))

extern void
__coverity___builtin_ia32_gatherpfdps(
    unsigned short __a,
    int __attribute__((vector_size(64))) __b,
    const void* __c,
    const int __d,
    const int __e);
#define __builtin_ia32_gatherpfdps(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_gatherpfdps((P0), (P1), (P2), (P3), (P4))

extern void
__coverity___builtin_ia32_gatherpfqpd(
    unsigned char __a,
    long long __attribute__((vector_size(64))) __b,
    const void* __c,
    const int __d,
    const int __e);
#define __builtin_ia32_gatherpfqpd(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_gatherpfqpd((P0), (P1), (P2), (P3), (P4))

extern void
__coverity___builtin_ia32_gatherpfqps(
    unsigned char __a,
    long long __attribute__((vector_size(64))) __b,
    const void* __c,
    const int __d,
    const int __e);
#define __builtin_ia32_gatherpfqps(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_gatherpfqps((P0), (P1), (P2), (P3), (P4))

extern float __attribute__((vector_size(64)))
__coverity___builtin_ia32_gathersiv16sf(
    float __attribute__((vector_size(64))) __a,
    const void* __b,
    unsigned short __c,
    const int __d);
#define __builtin_ia32_gathersiv16sf(P0, P1, P2, P3) \
    __coverity___builtin_ia32_gathersiv16sf((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(64)))
__coverity___builtin_ia32_gathersiv16si(
    int __attribute__((vector_size(64))) __a,
    const void* __b,
    unsigned short __c,
    const int __d);
#define __builtin_ia32_gathersiv16si(P0, P1, P2, P3) \
    __coverity___builtin_ia32_gathersiv16si((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(64)))
__coverity___builtin_ia32_gathersiv8df(
    double __attribute__((vector_size(64))) __a,
    const void* __b,
    int __attribute__((vector_size(32))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_gathersiv8df(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_gathersiv8df((P0), (P1), (P2), (P3), (P4))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_gathersiv8di(
    long long __attribute__((vector_size(64))) __a,
    const void* __b,
    int __attribute__((vector_size(32))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_gathersiv8di(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_gathersiv8di((P0), (P1), (P2), (P3), (P4))

extern void
__coverity___builtin_ia32_scatterdiv16sf(
    void* __a,
    unsigned char __b,
    long long __attribute__((vector_size(64))) __c,
    float __attribute__((vector_size(32))) __d,
    const int __e);
#define __builtin_ia32_scatterdiv16sf(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_scatterdiv16sf((P0), (P1), (P2), (P3), (P4))

extern void
__coverity___builtin_ia32_scatterdiv16si(
    void* __a,
    unsigned char __b,
    long long __attribute__((vector_size(64))) __c,
    int __attribute__((vector_size(32))) __d,
    const int __e);
#define __builtin_ia32_scatterdiv16si(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_scatterdiv16si((P0), (P1), (P2), (P3), (P4))

extern void
__coverity___builtin_ia32_scatterdiv2df(
    void* __a,
    unsigned char __b,
    long long __attribute__((vector_size(16))) __c,
    double __attribute__((vector_size(16))) __d,
    const int __e);
#define __builtin_ia32_scatterdiv2df(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_scatterdiv2df((P0), (P1), (P2), (P3), (P4))

extern void
__coverity___builtin_ia32_scatterdiv2di(
    void* __a,
    unsigned char __b,
    long long __attribute__((vector_size(16))) __c,
    long long __attribute__((vector_size(16))) __d,
    const int __e);
#define __builtin_ia32_scatterdiv2di(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_scatterdiv2di((P0), (P1), (P2), (P3), (P4))

extern void
__coverity___builtin_ia32_scatterdiv4df(
    void* __a,
    unsigned char __b,
    long long __attribute__((vector_size(32))) __c,
    double __attribute__((vector_size(32))) __d,
    const int __e);
#define __builtin_ia32_scatterdiv4df(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_scatterdiv4df((P0), (P1), (P2), (P3), (P4))

extern void
__coverity___builtin_ia32_scatterdiv4di(
    void* __a,
    unsigned char __b,
    long long __attribute__((vector_size(32))) __c,
    long long __attribute__((vector_size(32))) __d,
    const int __e);
#define __builtin_ia32_scatterdiv4di(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_scatterdiv4di((P0), (P1), (P2), (P3), (P4))

extern void
__coverity___builtin_ia32_scatterdiv4sf(
    void* __a,
    unsigned char __b,
    long long __attribute__((vector_size(16))) __c,
    float __attribute__((vector_size(16))) __d,
    const int __e);
#define __builtin_ia32_scatterdiv4sf(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_scatterdiv4sf((P0), (P1), (P2), (P3), (P4))

extern void
__coverity___builtin_ia32_scatterdiv4si(
    void* __a,
    unsigned char __b,
    long long __attribute__((vector_size(16))) __c,
    int __attribute__((vector_size(16))) __d,
    const int __e);
#define __builtin_ia32_scatterdiv4si(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_scatterdiv4si((P0), (P1), (P2), (P3), (P4))

extern void
__coverity___builtin_ia32_scatterdiv8df(
    void* __a,
    unsigned char __b,
    long long __attribute__((vector_size(64))) __c,
    double __attribute__((vector_size(64))) __d,
    const int __e);
#define __builtin_ia32_scatterdiv8df(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_scatterdiv8df((P0), (P1), (P2), (P3), (P4))

extern void
__coverity___builtin_ia32_scatterdiv8di(
    void* __a,
    unsigned char __b,
    long long __attribute__((vector_size(64))) __c,
    long long __attribute__((vector_size(64))) __d,
    const int __e);
#define __builtin_ia32_scatterdiv8di(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_scatterdiv8di((P0), (P1), (P2), (P3), (P4))

extern void
__coverity___builtin_ia32_scatterdiv8sf(
    void* __a,
    unsigned char __b,
    long long __attribute__((vector_size(32))) __c,
    float __attribute__((vector_size(16))) __d,
    const int __e);
#define __builtin_ia32_scatterdiv8sf(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_scatterdiv8sf((P0), (P1), (P2), (P3), (P4))

extern void
__coverity___builtin_ia32_scatterdiv8si(
    void* __a,
    unsigned char __b,
    long long __attribute__((vector_size(32))) __c,
    int __attribute__((vector_size(16))) __d,
    const int __e);
#define __builtin_ia32_scatterdiv8si(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_scatterdiv8si((P0), (P1), (P2), (P3), (P4))

extern void
__coverity___builtin_ia32_scatterpfdpd(
    unsigned char __a,
    int __attribute__((vector_size(32))) __b,
    void* __c,
    const int __d,
    const int __e);
#define __builtin_ia32_scatterpfdpd(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_scatterpfdpd((P0), (P1), (P2), (P3), (P4))

extern void
__coverity___builtin_ia32_scatterpfdps(
    unsigned short __a,
    int __attribute__((vector_size(64))) __b,
    void* __c,
    const int __d,
    const int __e);
#define __builtin_ia32_scatterpfdps(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_scatterpfdps((P0), (P1), (P2), (P3), (P4))

extern void
__coverity___builtin_ia32_scatterpfqpd(
    unsigned char __a,
    long long __attribute__((vector_size(64))) __b,
    void* __c,
    const int __d,
    const int __e);
#define __builtin_ia32_scatterpfqpd(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_scatterpfqpd((P0), (P1), (P2), (P3), (P4))

extern void
__coverity___builtin_ia32_scatterpfqps(
    unsigned char __a,
    long long __attribute__((vector_size(64))) __b,
    void* __c,
    const int __d,
    const int __e);
#define __builtin_ia32_scatterpfqps(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_scatterpfqps((P0), (P1), (P2), (P3), (P4))

extern void
__coverity___builtin_ia32_scattersiv16sf(
    void* __a,
    unsigned short __b,
    int __attribute__((vector_size(64))) __c,
    float __attribute__((vector_size(64))) __d,
    const int __e);
#define __builtin_ia32_scattersiv16sf(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_scattersiv16sf((P0), (P1), (P2), (P3), (P4))

extern void
__coverity___builtin_ia32_scattersiv16si(
    void* __a,
    unsigned short __b,
    int __attribute__((vector_size(64))) __c,
    int __attribute__((vector_size(64))) __d,
    const int __e);
#define __builtin_ia32_scattersiv16si(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_scattersiv16si((P0), (P1), (P2), (P3), (P4))

extern void
__coverity___builtin_ia32_scattersiv2df(
    void* __a,
    unsigned char __b,
    int __attribute__((vector_size(16))) __c,
    double __attribute__((vector_size(16))) __d,
    const int __e);
#define __builtin_ia32_scattersiv2df(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_scattersiv2df((P0), (P1), (P2), (P3), (P4))

extern void
__coverity___builtin_ia32_scattersiv2di(
    void* __a,
    unsigned char __b,
    int __attribute__((vector_size(16))) __c,
    long long __attribute__((vector_size(16))) __d,
    const int __e);
#define __builtin_ia32_scattersiv2di(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_scattersiv2di((P0), (P1), (P2), (P3), (P4))

extern void
__coverity___builtin_ia32_scattersiv4df(
    void* __a,
    unsigned char __b,
    int __attribute__((vector_size(16))) __c,
    double __attribute__((vector_size(32))) __d,
    const int __e);
#define __builtin_ia32_scattersiv4df(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_scattersiv4df((P0), (P1), (P2), (P3), (P4))

extern void
__coverity___builtin_ia32_scattersiv4di(
    void* __a,
    unsigned char __b,
    int __attribute__((vector_size(16))) __c,
    long long __attribute__((vector_size(32))) __d,
    const int __e);
#define __builtin_ia32_scattersiv4di(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_scattersiv4di((P0), (P1), (P2), (P3), (P4))

extern void
__coverity___builtin_ia32_scattersiv4sf(
    void* __a,
    unsigned char __b,
    int __attribute__((vector_size(16))) __c,
    float __attribute__((vector_size(16))) __d,
    const int __e);
#define __builtin_ia32_scattersiv4sf(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_scattersiv4sf((P0), (P1), (P2), (P3), (P4))

extern void
__coverity___builtin_ia32_scattersiv4si(
    void* __a,
    unsigned char __b,
    int __attribute__((vector_size(16))) __c,
    int __attribute__((vector_size(16))) __d,
    const int __e);
#define __builtin_ia32_scattersiv4si(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_scattersiv4si((P0), (P1), (P2), (P3), (P4))

extern void
__coverity___builtin_ia32_scattersiv8df(
    void* __a,
    unsigned char __b,
    int __attribute__((vector_size(32))) __c,
    double __attribute__((vector_size(64))) __d,
    const int __e);
#define __builtin_ia32_scattersiv8df(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_scattersiv8df((P0), (P1), (P2), (P3), (P4))

extern void
__coverity___builtin_ia32_scattersiv8di(
    void* __a,
    unsigned char __b,
    int __attribute__((vector_size(32))) __c,
    long long __attribute__((vector_size(64))) __d,
    const int __e);
#define __builtin_ia32_scattersiv8di(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_scattersiv8di((P0), (P1), (P2), (P3), (P4))

extern void
__coverity___builtin_ia32_scattersiv8sf(
    void* __a,
    unsigned char __b,
    int __attribute__((vector_size(32))) __c,
    float __attribute__((vector_size(32))) __d,
    const int __e);
#define __builtin_ia32_scattersiv8sf(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_scattersiv8sf((P0), (P1), (P2), (P3), (P4))

extern void
__coverity___builtin_ia32_scattersiv8si(
    void* __a,
    unsigned char __b,
    int __attribute__((vector_size(32))) __c,
    int __attribute__((vector_size(32))) __d,
    const int __e);
#define __builtin_ia32_scattersiv8si(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_scattersiv8si((P0), (P1), (P2), (P3), (P4))

#endif /* } */

/* } This builtin was modified in clang 3.8 and removed in clang 3.9 { */
#if (__cov_clang_version_ge(3, 8)) && (!__cov_xcode_version_ge(8, 0)) /* { */
extern long long
__coverity___builtin_ptx_read_clock64();
#define __builtin_ptx_read_clock64() \
    __coverity___builtin_ptx_read_clock64()
#endif /* } Clang >= 3.8 && !(xcode >= 8.0) */
#endif /* } clang < 3.9 */


/*************************************
 ************ Clang 4.0 **************
 *************************************/

#if (__cov_clang_version_lt(4, 0)) /* { */

#if !(__cov_xcode_version_gt(8, 1)) /* { */
extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmaddubsw128_mask(
    char __attribute__((vector_size(16))) __a,
    char __attribute__((vector_size(16))) __b,
    short __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_pmaddubsw128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmaddubsw128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmaddubsw256_mask(
    char __attribute__ ((vector_size(32))) __a,
    char __attribute__ ((vector_size(32))) __b,
    short __attribute__ ((vector_size(32))) __c,
    unsigned short __u);
#define __builtin_ia32_pmaddubsw256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmaddubsw256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmaddwd128_mask(
    short __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b,
    int __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_pmaddwd128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmaddwd128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmaddwd256_mask(
    short __attribute__ ((vector_size(32))) __a,
    short __attribute__ ((vector_size(32))) __b,
    int __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_pmaddwd256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmaddwd256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmulhrsw128_mask(
    short __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b,
    short __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_pmulhrsw128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmulhrsw128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmulhrsw256_mask(
    short __attribute__ ((vector_size(32))) __a,
    short __attribute__ ((vector_size(32))) __b,
    short __attribute__ ((vector_size(32))) __c,
    unsigned short __u);
#define __builtin_ia32_pmulhrsw256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmulhrsw256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmulhuw128_mask(
    short __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b,
    short __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_pmulhuw128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmulhuw128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmulhuw256_mask(
    short __attribute__ ((vector_size(32))) __a,
    short __attribute__ ((vector_size(32))) __b,
    short __attribute__ ((vector_size(32))) __c,
    unsigned short __u);
#define __builtin_ia32_pmulhuw256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmulhuw256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmulhw128_mask(
    short __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b,
    short __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_pmulhw128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmulhw128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmulhw256_mask(
    short __attribute__ ((vector_size(32))) __a,
    short __attribute__ ((vector_size(32))) __b,
    short __attribute__ ((vector_size(32))) __c,
    unsigned short __u);
#define __builtin_ia32_pmulhw256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmulhw256_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_addpd128_mask(
    double __attribute__ ((vector_size(16))) __a,
    double __attribute__ ((vector_size(16))) __b,
    double __attribute__ ((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_addpd128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_addpd128_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_addpd256_mask(
    double __attribute__ ((vector_size(32))) __a,
    double __attribute__ ((vector_size(32))) __b,
    double __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_addpd256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_addpd256_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_addps128_mask(
    float __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_addps128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_addps128_mask((P0), (P1), (P2), (P3))

extern float __attribute__ ((vector_size(32)))
__coverity___builtin_ia32_addps256_mask(
    float __attribute__ ((vector_size(32))) __a,
    float __attribute__ ((vector_size(32))) __b,
    float __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_addps256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_addps256_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_cvtdq2pd128_mask(
    int __attribute__((vector_size(16))) __a,
    double __attribute__ ((vector_size(16))) __b,
    unsigned char __u);
#define __builtin_ia32_cvtdq2pd128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_cvtdq2pd128_mask((P0), (P1), (P2))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_cvtdq2pd256_mask(
    int __attribute__((vector_size(16))) __a,
    double __attribute__ ((vector_size(32))) __b,
    unsigned char __u);
#define __builtin_ia32_cvtdq2pd256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_cvtdq2pd256_mask((P0), (P1), (P2))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_cvtudq2pd128_mask(
    int __attribute__((vector_size(16))) __a,
    double __attribute__ ((vector_size(16))) __b,
    unsigned char __u);
#define __builtin_ia32_cvtudq2pd128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_cvtudq2pd128_mask((P0), (P1), (P2))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_cvtudq2pd256_mask(
    int __attribute__((vector_size(16))) __a,
    double __attribute__ ((vector_size(32))) __b,
    unsigned char __u);
#define __builtin_ia32_cvtudq2pd256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_cvtudq2pd256_mask((P0), (P1), (P2))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_divpd_mask(
    double __attribute__ ((vector_size(16))) __a,
    double __attribute__ ((vector_size(16))) __b,
    double __attribute__ ((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_divpd_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_divpd_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_divpd256_mask(
    double __attribute__ ((vector_size(32))) __a,
    double __attribute__ ((vector_size(32))) __b,
    double __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_divpd256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_divpd256_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_divps_mask(
    float __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_divps_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_divps_mask((P0), (P1), (P2), (P3))

extern float __attribute__ ((vector_size(32)))
__coverity___builtin_ia32_divps256_mask(
    float __attribute__ ((vector_size(32))) __a,
    float __attribute__ ((vector_size(32))) __b,
    float __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_divps256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_divps256_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_maxpd_mask(
    double __attribute__ ((vector_size(16))) __a,
    double __attribute__ ((vector_size(16))) __b,
    double __attribute__ ((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_maxpd_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_maxpd_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_maxpd256_mask(
    double __attribute__ ((vector_size(32))) __a,
    double __attribute__ ((vector_size(32))) __b,
    double __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_maxpd256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_maxpd256_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_maxps_mask(
    float __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_maxps_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_maxps_mask((P0), (P1), (P2), (P3))

extern float __attribute__ ((vector_size(32)))
__coverity___builtin_ia32_maxps256_mask(
    float __attribute__ ((vector_size(32))) __a,
    float __attribute__ ((vector_size(32))) __b,
    float __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_maxps256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_maxps256_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_minpd_mask(
    double __attribute__ ((vector_size(16))) __a,
    double __attribute__ ((vector_size(16))) __b,
    double __attribute__ ((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_minpd_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_minpd_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_minpd256_mask(
    double __attribute__ ((vector_size(32))) __a,
    double __attribute__ ((vector_size(32))) __b,
    double __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_minpd256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_minpd256_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_minps_mask(
    float __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_minps_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_minps_mask((P0), (P1), (P2), (P3))

extern float __attribute__ ((vector_size(32)))
__coverity___builtin_ia32_minps256_mask(
    float __attribute__ ((vector_size(32))) __a,
    float __attribute__ ((vector_size(32))) __b,
    float __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_minps256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_minps256_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_mulpd_mask(
    double __attribute__ ((vector_size(16))) __a,
    double __attribute__ ((vector_size(16))) __b,
    double __attribute__ ((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_mulpd_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_mulpd_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_mulpd256_mask(
    double __attribute__ ((vector_size(32))) __a,
    double __attribute__ ((vector_size(32))) __b,
    double __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_mulpd256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_mulpd256_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_mulps_mask(
    float __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_mulps_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_mulps_mask((P0), (P1), (P2), (P3))

extern float __attribute__ ((vector_size(32)))
__coverity___builtin_ia32_mulps256_mask(
    float __attribute__ ((vector_size(32))) __a,
    float __attribute__ ((vector_size(32))) __b,
    float __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_mulps256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_mulps256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pabsd128_mask(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    unsigned char __u);
#define __builtin_ia32_pabsd128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pabsd128_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pabsd256_mask(
    int __attribute__ ((vector_size(32))) __a,
    int __attribute__ ((vector_size(32))) __b,
    unsigned char __u);
#define __builtin_ia32_pabsd256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pabsd256_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmaxsd128_mask(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    int __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_pmaxsd128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmaxsd128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmaxsd256_mask(
    int __attribute__ ((vector_size(32))) __a,
    int __attribute__ ((vector_size(32))) __b,
    int __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_pmaxsd256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmaxsd256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmaxud128_mask(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    int __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_pmaxud128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmaxud128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmaxud256_mask(
    int __attribute__ ((vector_size(32))) __a,
    int __attribute__ ((vector_size(32))) __b,
    int __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_pmaxud256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmaxud256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pminsd128_mask(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    int __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_pminsd128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pminsd128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pminsd256_mask(
    int __attribute__ ((vector_size(32))) __a,
    int __attribute__ ((vector_size(32))) __b,
    int __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_pminsd256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pminsd256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pminud128_mask(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    int __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_pminud128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pminud128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pminud256_mask(
    int __attribute__ ((vector_size(32))) __a,
    int __attribute__ ((vector_size(32))) __b,
    int __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_pminud256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pminud256_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_sqrtpd128_mask(
    double __attribute__ ((vector_size(16))) __a,
    double __attribute__ ((vector_size(16))) __b,
    unsigned char __u);
#define __builtin_ia32_sqrtpd128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_sqrtpd128_mask((P0), (P1), (P2))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_sqrtpd256_mask(
    double __attribute__ ((vector_size(32))) __a,
    double __attribute__ ((vector_size(32))) __b,
    unsigned char __u);
#define __builtin_ia32_sqrtpd256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_sqrtpd256_mask((P0), (P1), (P2))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_sqrtps128_mask(
    float __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    unsigned char __u);
#define __builtin_ia32_sqrtps128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_sqrtps128_mask((P0), (P1), (P2))

extern float __attribute__ ((vector_size(32)))
__coverity___builtin_ia32_sqrtps256_mask(
    float __attribute__ ((vector_size(32))) __a,
    float __attribute__ ((vector_size(32))) __b,
    unsigned char __u);
#define __builtin_ia32_sqrtps256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_sqrtps256_mask((P0), (P1), (P2))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_subpd128_mask(
    double __attribute__ ((vector_size(16))) __a,
    double __attribute__ ((vector_size(16))) __b,
    double __attribute__ ((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_subpd128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_subpd128_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_subpd256_mask(
    double __attribute__ ((vector_size(32))) __a,
    double __attribute__ ((vector_size(32))) __b,
    double __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_subpd256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_subpd256_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_subps128_mask(
    float __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_subps128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_subps128_mask((P0), (P1), (P2), (P3))

extern float __attribute__ ((vector_size(32)))
__coverity___builtin_ia32_subps256_mask(
    float __attribute__ ((vector_size(32))) __a,
    float __attribute__ ((vector_size(32))) __b,
    float __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_subps256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_subps256_mask((P0), (P1), (P2), (P3))

#endif /* } !(xcode > 8.1) */

/* Removed in Clang 4.0 */
extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_paddq512_mask(
    long long __attribute__((vector_size(64))) __a,
    long long __attribute__((vector_size(64))) __b,
    long long __attribute__((vector_size(64))) __w,
    unsigned char __u);
#define __builtin_ia32_paddq512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_paddq512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_psubq512_mask(
    long long __attribute__((vector_size(64))) __a,
    long long __attribute__((vector_size(64))) __b,
    long long __attribute__((vector_size(64))) __w,
    unsigned char __u);
#define __builtin_ia32_psubq512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psubq512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_paddd512_mask(
    int __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    int __attribute__((vector_size(64))) __w,
    unsigned short __u);
#define __builtin_ia32_paddd512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_paddd512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_psubd512_mask(
    int __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    int __attribute__((vector_size(64))) __w,
    unsigned short __u);
#define __builtin_ia32_psubd512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psubd512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_pmuldq512_mask(
    int __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    long long __attribute__((vector_size(64))) __w,
    unsigned char __u);
#define __builtin_ia32_pmuldq512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmuldq512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_pmuludq512_mask(
    int __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    long long __attribute__((vector_size(64))) __w,
    unsigned char __u);
#define __builtin_ia32_pmuludq512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmuludq512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_pmulld512_mask(
    int __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    int __attribute__((vector_size(64))) __w,
    unsigned short __u);
#define __builtin_ia32_pmulld512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmulld512_mask((P0), (P1), (P2), (P3))


extern double __attribute__((vector_size(64)))
__coverity___builtin_ia32_cvtdq2pd512_mask(
    int __attribute__ ((vector_size(32))) __a,
    double __attribute__((vector_size(64))) __b,
    unsigned char __u);
#define __builtin_ia32_cvtdq2pd512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_cvtdq2pd512_mask((P0), (P1), (P2))

extern double __attribute__((vector_size(64)))
__coverity___builtin_ia32_cvtudq2pd512_mask(
    int __attribute__ ((vector_size(32))) __a,
    double __attribute__((vector_size(64))) __b,
    unsigned char __u);
#define __builtin_ia32_cvtudq2pd512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_cvtudq2pd512_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_paddb512_mask(
    char __attribute__ ((vector_size(64))) __a,
    char __attribute__ ((vector_size(64))) __b,
    char __attribute__ ((vector_size(64))) __c,
    unsigned long long __u);
#define __builtin_ia32_paddb512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_paddb512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_psubb512_mask(
    char __attribute__ ((vector_size(64))) __a,
    char __attribute__ ((vector_size(64))) __b,
    char __attribute__ ((vector_size(64))) __c,
    unsigned long long __u);
#define __builtin_ia32_psubb512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psubb512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_paddw512_mask(
    short __attribute__ ((vector_size(64))) __a,
    short __attribute__ ((vector_size(64))) __b,
    short __attribute__ ((vector_size(64))) __c,
    unsigned int __u);
#define __builtin_ia32_paddw512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_paddw512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_psubw512_mask(
    short __attribute__ ((vector_size(64))) __a,
    short __attribute__ ((vector_size(64))) __b,
    short __attribute__ ((vector_size(64))) __c,
    unsigned int __u);
#define __builtin_ia32_psubw512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psubw512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_pmullw512_mask(
    short __attribute__ ((vector_size(64))) __a,
    short __attribute__ ((vector_size(64))) __b,
    short __attribute__ ((vector_size(64))) __c,
    unsigned int __u);
#define __builtin_ia32_pmullw512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmullw512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_pshufb512_mask(
    char __attribute__ ((vector_size(64))) __a,
    char __attribute__ ((vector_size(64))) __b,
    char __attribute__ ((vector_size(64))) __c,
    unsigned long long __u);
#define __builtin_ia32_pshufb512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pshufb512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_pmullq512_mask(
    long long __attribute__((vector_size(64))) __a,
    long long __attribute__((vector_size(64))) __b,
    long long __attribute__((vector_size(64))) __c,
    unsigned char __u);
#define __builtin_ia32_pmullq512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmullq512_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(64)))
__coverity___builtin_ia32_xorpd512_mask(
    double __attribute__((vector_size(64))) __a,
    double __attribute__((vector_size(64))) __b,
    double __attribute__((vector_size(64))) __c,
    unsigned char __u);
#define __builtin_ia32_xorpd512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_xorpd512_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(64)))
__coverity___builtin_ia32_xorps512_mask(
    float __attribute__((vector_size(64))) __a,
    float __attribute__((vector_size(64))) __b,
    float __attribute__((vector_size(64))) __c,
    unsigned short __u);
#define __builtin_ia32_xorps512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_xorps512_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(64)))
__coverity___builtin_ia32_orpd512_mask(
    double __attribute__((vector_size(64))) __a,
    double __attribute__((vector_size(64))) __b,
    double __attribute__((vector_size(64))) __c,
    unsigned char __u);
#define __builtin_ia32_orpd512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_orpd512_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(64)))
__coverity___builtin_ia32_orps512_mask(
    float __attribute__((vector_size(64))) __a,
    float __attribute__((vector_size(64))) __b,
    float __attribute__((vector_size(64))) __c,
    unsigned short __u);
#define __builtin_ia32_orps512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_orps512_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(64)))
__coverity___builtin_ia32_andpd512_mask(
    double __attribute__((vector_size(64))) __a,
    double __attribute__((vector_size(64))) __b,
    double __attribute__((vector_size(64))) __c,
    unsigned char __u);
#define __builtin_ia32_andpd512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_andpd512_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(64)))
__coverity___builtin_ia32_andps512_mask(
    float __attribute__((vector_size(64))) __a,
    float __attribute__((vector_size(64))) __b,
    float __attribute__((vector_size(64))) __c,
    unsigned short __u);
#define __builtin_ia32_andps512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_andps512_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(64)))
__coverity___builtin_ia32_andnps512_mask(
    float __attribute__((vector_size(64))) __a,
    float __attribute__((vector_size(64))) __b,
    float __attribute__((vector_size(64))) __c,
    unsigned short __u);
#define __builtin_ia32_andnps512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_andnps512_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(64)))
__coverity___builtin_ia32_andnpd512_mask(
    double __attribute__((vector_size(64))) __a,
    double __attribute__((vector_size(64))) __b,
    double __attribute__((vector_size(64))) __c,
    unsigned char __u);
#define __builtin_ia32_andnpd512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_andnpd512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_paddd256_mask(
    int __attribute__ ((vector_size(32))) __a,
    int __attribute__ ((vector_size(32))) __b,
    int __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_paddd256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_paddd256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_paddq256_mask(
    long long __attribute__ ((vector_size(32))) __a,
    long long __attribute__ ((vector_size(32))) __b,
    long long __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_paddq256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_paddq256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_psubd256_mask(
    int __attribute__ ((vector_size(32))) __a,
    int __attribute__ ((vector_size(32))) __b,
    int __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_psubd256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psubd256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_psubq256_mask(
    long long __attribute__ ((vector_size(32))) __a,
    long long __attribute__ ((vector_size(32))) __b,
    long long __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_psubq256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psubq256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_paddd128_mask(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    int __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_paddd128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_paddd128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_paddq128_mask(
    long long __attribute__ ((vector_size(16))) __a,
    long long __attribute__ ((vector_size(16))) __b,
    long long __attribute__ ((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_paddq128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_paddq128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_psubd128_mask(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    int __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_psubd128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psubd128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_psubq128_mask(
    long long __attribute__ ((vector_size(16))) __a,
    long long __attribute__ ((vector_size(16))) __b,
    long long __attribute__ ((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_psubq128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psubq128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmuldq256_mask(
    int __attribute__ ((vector_size(32))) __a,
    int __attribute__ ((vector_size(32))) __b,
    long long __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_pmuldq256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmuldq256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmuldq128_mask(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    long long __attribute__ ((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_pmuldq128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmuldq128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmuludq256_mask(
    int __attribute__ ((vector_size(32))) __a,
    int __attribute__ ((vector_size(32))) __b,
    long long __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_pmuludq256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmuludq256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmuludq128_mask(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    long long __attribute__ ((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_pmuludq128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmuludq128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmulld256_mask(
    int __attribute__ ((vector_size(32))) __a,
    int __attribute__ ((vector_size(32))) __b,
    int __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_pmulld256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmulld256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmulld128_mask(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    int __attribute__((vector_size(16))) __c,
    unsigned short __u);
#define __builtin_ia32_pmulld128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmulld128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_paddb256_mask(
    char __attribute__ ((vector_size(32))) __a,
    char __attribute__ ((vector_size(32))) __b,
    char __attribute__ ((vector_size(32))) __c,
    unsigned int __u);
#define __builtin_ia32_paddb256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_paddb256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_paddw256_mask(
    short __attribute__ ((vector_size(32))) __a,
    short __attribute__ ((vector_size(32))) __b,
    short __attribute__ ((vector_size(32))) __c,
    unsigned short __u);
#define __builtin_ia32_paddw256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_paddw256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_psubb256_mask(
    char __attribute__ ((vector_size(32))) __a,
    char __attribute__ ((vector_size(32))) __b,
    char __attribute__ ((vector_size(32))) __c,
    unsigned int __u);
#define __builtin_ia32_psubb256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psubb256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_psubw256_mask(
    short __attribute__ ((vector_size(32))) __a,
    short __attribute__ ((vector_size(32))) __b,
    short __attribute__ ((vector_size(32))) __c,
    unsigned short __u);
#define __builtin_ia32_psubw256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psubw256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_paddb128_mask(
    char __attribute__((vector_size(16))) __a,
    char __attribute__((vector_size(16))) __b,
    char __attribute__((vector_size(16))) __c,
    unsigned short __u);
#define __builtin_ia32_paddb128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_paddb128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_paddw128_mask(
    short __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b,
    short __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_paddw128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_paddw128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_psubb128_mask(
    char __attribute__((vector_size(16))) __a,
    char __attribute__((vector_size(16))) __b,
    char __attribute__((vector_size(16))) __c,
    unsigned short __u);
#define __builtin_ia32_psubb128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psubb128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_psubw128_mask(
    short __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b,
    short __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_psubw128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psubw128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmullw256_mask(
    short __attribute__ ((vector_size(32))) __a,
    short __attribute__ ((vector_size(32))) __b,
    short __attribute__ ((vector_size(32))) __c,
    unsigned short __u);
#define __builtin_ia32_pmullw256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmullw256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmullw128_mask(
    short __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b,
    short __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_pmullw128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmullw128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pabsb128_mask(
    char __attribute__((vector_size(16))) __a,
    char __attribute__((vector_size(16))) __b,
    unsigned short __u);
#define __builtin_ia32_pabsb128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pabsb128_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pabsb256_mask(
    char __attribute__ ((vector_size(32))) __a,
    char __attribute__ ((vector_size(32))) __b,
    unsigned int __u);
#define __builtin_ia32_pabsb256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pabsb256_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pabsw128_mask(
    short __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b,
    unsigned char __u);
#define __builtin_ia32_pabsw128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pabsw128_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pabsw256_mask(
    short __attribute__ ((vector_size(32))) __a,
    short __attribute__ ((vector_size(32))) __b,
    unsigned short __u);
#define __builtin_ia32_pabsw256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pabsw256_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_packssdw128_mask(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    short __attribute__((vector_size(16))) __c,
    unsigned short __M);
#define __builtin_ia32_packssdw128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_packssdw128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_packssdw256_mask(
    int __attribute__ ((vector_size(32))) __a,
    int __attribute__ ((vector_size(32))) __b,
    short __attribute__ ((vector_size(32))) __c,
    unsigned short __M);
#define __builtin_ia32_packssdw256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_packssdw256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_packsswb128_mask(
    short __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b,
    char __attribute__((vector_size(16))) __c,
    unsigned short __M);
#define __builtin_ia32_packsswb128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_packsswb128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_packsswb256_mask(
    short __attribute__ ((vector_size(32))) __a,
    short __attribute__ ((vector_size(32))) __b,
    char __attribute__ ((vector_size(32))) __c,
    unsigned int __M);
#define __builtin_ia32_packsswb256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_packsswb256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_packusdw128_mask(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    short __attribute__((vector_size(16))) __c,
    unsigned short __M);
#define __builtin_ia32_packusdw128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_packusdw128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_packusdw256_mask(
    int __attribute__ ((vector_size(32))) __a,
    int __attribute__ ((vector_size(32))) __b,
    short __attribute__ ((vector_size(32))) __c,
    unsigned short __M);
#define __builtin_ia32_packusdw256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_packusdw256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_packuswb128_mask(
    short __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b,
    char __attribute__((vector_size(16))) __c,
    unsigned short __M);
#define __builtin_ia32_packuswb128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_packuswb128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_packuswb256_mask(
    short __attribute__ ((vector_size(32))) __a,
    short __attribute__ ((vector_size(32))) __b,
    char __attribute__ ((vector_size(32))) __c,
    unsigned int __M);
#define __builtin_ia32_packuswb256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_packuswb256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_paddsb128_mask(
    char __attribute__((vector_size(16))) __a,
    char __attribute__((vector_size(16))) __b,
    char __attribute__((vector_size(16))) __c,
    unsigned short __u);
#define __builtin_ia32_paddsb128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_paddsb128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_paddsb256_mask(
    char __attribute__ ((vector_size(32))) __a,
    char __attribute__ ((vector_size(32))) __b,
    char __attribute__ ((vector_size(32))) __c,
    unsigned int __u);
#define __builtin_ia32_paddsb256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_paddsb256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_paddsw128_mask(
    short __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b,
    short __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_paddsw128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_paddsw128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_paddsw256_mask(
    short __attribute__ ((vector_size(32))) __a,
    short __attribute__ ((vector_size(32))) __b,
    short __attribute__ ((vector_size(32))) __c,
    unsigned short __u);
#define __builtin_ia32_paddsw256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_paddsw256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_paddusb128_mask(
    char __attribute__((vector_size(16))) __a,
    char __attribute__((vector_size(16))) __b,
    char __attribute__((vector_size(16))) __c,
    unsigned short __u);
#define __builtin_ia32_paddusb128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_paddusb128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_paddusb256_mask(
    char __attribute__ ((vector_size(32))) __a,
    char __attribute__ ((vector_size(32))) __b,
    char __attribute__ ((vector_size(32))) __c,
    unsigned int __u);
#define __builtin_ia32_paddusb256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_paddusb256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_paddusw128_mask(
    short __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b,
    short __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_paddusw128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_paddusw128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_paddusw256_mask(
    short __attribute__ ((vector_size(32))) __a,
    short __attribute__ ((vector_size(32))) __b,
    short __attribute__ ((vector_size(32))) __c,
    unsigned short __u);
#define __builtin_ia32_paddusw256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_paddusw256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pavgb128_mask(
    char __attribute__((vector_size(16))) __a,
    char __attribute__((vector_size(16))) __b,
    char __attribute__((vector_size(16))) __c,
    unsigned short __u);
#define __builtin_ia32_pavgb128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pavgb128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pavgb256_mask(
    char __attribute__ ((vector_size(32))) __a,
    char __attribute__ ((vector_size(32))) __b,
    char __attribute__ ((vector_size(32))) __c,
    unsigned int __u);
#define __builtin_ia32_pavgb256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pavgb256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pavgw128_mask(
    short __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b,
    short __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_pavgw128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pavgw128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pavgw256_mask(
    short __attribute__ ((vector_size(32))) __a,
    short __attribute__ ((vector_size(32))) __b,
    short __attribute__ ((vector_size(32))) __c,
    unsigned short __u);
#define __builtin_ia32_pavgw256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pavgw256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmaxsb128_mask(
    char __attribute__((vector_size(16))) __a,
    char __attribute__((vector_size(16))) __b,
    char __attribute__((vector_size(16))) __c,
    unsigned short __u);
#define __builtin_ia32_pmaxsb128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmaxsb128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmaxsb256_mask(
    char __attribute__ ((vector_size(32))) __a,
    char __attribute__ ((vector_size(32))) __b,
    char __attribute__ ((vector_size(32))) __c,
    unsigned int __u);
#define __builtin_ia32_pmaxsb256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmaxsb256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmaxsw128_mask(
    short __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b,
    short __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_pmaxsw128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmaxsw128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmaxsw256_mask(
    short __attribute__ ((vector_size(32))) __a,
    short __attribute__ ((vector_size(32))) __b,
    short __attribute__ ((vector_size(32))) __c,
    unsigned short __u);
#define __builtin_ia32_pmaxsw256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmaxsw256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmaxub128_mask(
    char __attribute__((vector_size(16))) __a,
    char __attribute__((vector_size(16))) __b,
    char __attribute__((vector_size(16))) __c,
    unsigned short __u);
#define __builtin_ia32_pmaxub128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmaxub128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmaxub256_mask(
    char __attribute__ ((vector_size(32))) __a,
    char __attribute__ ((vector_size(32))) __b,
    char __attribute__ ((vector_size(32))) __c,
    unsigned int __u);
#define __builtin_ia32_pmaxub256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmaxub256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmaxuw128_mask(
    short __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b,
    short __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_pmaxuw128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmaxuw128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmaxuw256_mask(
    short __attribute__ ((vector_size(32))) __a,
    short __attribute__ ((vector_size(32))) __b,
    short __attribute__ ((vector_size(32))) __c,
    unsigned short __u);
#define __builtin_ia32_pmaxuw256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmaxuw256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pminsb128_mask(
    char __attribute__((vector_size(16))) __a,
    char __attribute__((vector_size(16))) __b,
    char __attribute__((vector_size(16))) __c,
    unsigned short __u);
#define __builtin_ia32_pminsb128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pminsb128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pminsb256_mask(
    char __attribute__ ((vector_size(32))) __a,
    char __attribute__ ((vector_size(32))) __b,
    char __attribute__ ((vector_size(32))) __c,
    unsigned int __u);
#define __builtin_ia32_pminsb256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pminsb256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pminsw128_mask(
    short __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b,
    short __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_pminsw128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pminsw128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pminsw256_mask(
    short __attribute__ ((vector_size(32))) __a,
    short __attribute__ ((vector_size(32))) __b,
    short __attribute__ ((vector_size(32))) __c,
    unsigned short __u);
#define __builtin_ia32_pminsw256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pminsw256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pminub128_mask(
    char __attribute__((vector_size(16))) __a,
    char __attribute__((vector_size(16))) __b,
    char __attribute__((vector_size(16))) __c,
    unsigned short __u);
#define __builtin_ia32_pminub128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pminub128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pminub256_mask(
    char __attribute__ ((vector_size(32))) __a,
    char __attribute__ ((vector_size(32))) __b,
    char __attribute__ ((vector_size(32))) __c,
    unsigned int __u);
#define __builtin_ia32_pminub256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pminub256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pminuw128_mask(
    short __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b,
    short __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_pminuw128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pminuw128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pminuw256_mask(
    short __attribute__ ((vector_size(32))) __a,
    short __attribute__ ((vector_size(32))) __b,
    short __attribute__ ((vector_size(32))) __c,
    unsigned short __u);
#define __builtin_ia32_pminuw256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pminuw256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pshufb128_mask(
    char __attribute__((vector_size(16))) __a,
    char __attribute__((vector_size(16))) __b,
    char __attribute__((vector_size(16))) __c,
    unsigned short __u);
#define __builtin_ia32_pshufb128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pshufb128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pshufb256_mask(
    char __attribute__ ((vector_size(32))) __a,
    char __attribute__ ((vector_size(32))) __b,
    char __attribute__ ((vector_size(32))) __c,
    unsigned int __u);
#define __builtin_ia32_pshufb256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pshufb256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_psubsb128_mask(
    char __attribute__((vector_size(16))) __a,
    char __attribute__((vector_size(16))) __b,
    char __attribute__((vector_size(16))) __c,
    unsigned short __u);
#define __builtin_ia32_psubsb128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psubsb128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_psubsb256_mask(
    char __attribute__ ((vector_size(32))) __a,
    char __attribute__ ((vector_size(32))) __b,
    char __attribute__ ((vector_size(32))) __c,
    unsigned int __u);
#define __builtin_ia32_psubsb256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psubsb256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_psubsw128_mask(
    short __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b,
    short __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_psubsw128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psubsw128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_psubsw256_mask(
    short __attribute__ ((vector_size(32))) __a,
    short __attribute__ ((vector_size(32))) __b,
    short __attribute__ ((vector_size(32))) __c,
    unsigned short __u);
#define __builtin_ia32_psubsw256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psubsw256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_psubusb128_mask(
    char __attribute__((vector_size(16))) __a,
    char __attribute__((vector_size(16))) __b,
    char __attribute__((vector_size(16))) __c,
    unsigned short __u);
#define __builtin_ia32_psubusb128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psubusb128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_psubusb256_mask(
    char __attribute__ ((vector_size(32))) __a,
    char __attribute__ ((vector_size(32))) __b,
    char __attribute__ ((vector_size(32))) __c,
    unsigned int __u);
#define __builtin_ia32_psubusb256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psubusb256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_psubusw128_mask(
    short __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b,
    short __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_psubusw128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psubusw128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_psubusw256_mask(
    short __attribute__ ((vector_size(32))) __a,
    short __attribute__ ((vector_size(32))) __b,
    short __attribute__ ((vector_size(32))) __c,
    unsigned short __u);
#define __builtin_ia32_psubusw256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psubusw256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmullq256_mask(
    long long __attribute__ ((vector_size(32))) __a,
    long long __attribute__ ((vector_size(32))) __b,
    long long __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_pmullq256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmullq256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmullq128_mask(
    long long __attribute__ ((vector_size(16))) __a,
    long long __attribute__ ((vector_size(16))) __b,
    long long __attribute__ ((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_pmullq128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmullq128_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_andnpd256_mask(
    double __attribute__ ((vector_size(32))) __a,
    double __attribute__ ((vector_size(32))) __b,
    double __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_andnpd256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_andnpd256_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_andnpd128_mask(
    double __attribute__ ((vector_size(16))) __a,
    double __attribute__ ((vector_size(16))) __b,
    double __attribute__ ((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_andnpd128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_andnpd128_mask((P0), (P1), (P2), (P3))

extern float __attribute__ ((vector_size(32)))
__coverity___builtin_ia32_andnps256_mask(
    float __attribute__ ((vector_size(32))) __a,
    float __attribute__ ((vector_size(32))) __b,
    float __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_andnps256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_andnps256_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_andnps128_mask(
    float __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_andnps128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_andnps128_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_andpd256_mask(
    double __attribute__ ((vector_size(32))) __a,
    double __attribute__ ((vector_size(32))) __b,
    double __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_andpd256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_andpd256_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_andpd128_mask(
    double __attribute__ ((vector_size(16))) __a,
    double __attribute__ ((vector_size(16))) __b,
    double __attribute__ ((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_andpd128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_andpd128_mask((P0), (P1), (P2), (P3))

extern float __attribute__ ((vector_size(32)))
__coverity___builtin_ia32_andps256_mask(
    float __attribute__ ((vector_size(32))) __a,
    float __attribute__ ((vector_size(32))) __b,
    float __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_andps256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_andps256_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_andps128_mask(
    float __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_andps128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_andps128_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_xorpd256_mask(
    double __attribute__ ((vector_size(32))) __a,
    double __attribute__ ((vector_size(32))) __b,
    double __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_xorpd256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_xorpd256_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_xorpd128_mask(
    double __attribute__ ((vector_size(16))) __a,
    double __attribute__ ((vector_size(16))) __b,
    double __attribute__ ((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_xorpd128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_xorpd128_mask((P0), (P1), (P2), (P3))

extern float __attribute__ ((vector_size(32)))
__coverity___builtin_ia32_xorps256_mask(
    float __attribute__ ((vector_size(32))) __a,
    float __attribute__ ((vector_size(32))) __b,
    float __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_xorps256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_xorps256_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_xorps128_mask(
    float __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_xorps128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_xorps128_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_orpd256_mask(
    double __attribute__ ((vector_size(32))) __a,
    double __attribute__ ((vector_size(32))) __b,
    double __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_orpd256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_orpd256_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_orpd128_mask(
    double __attribute__ ((vector_size(16))) __a,
    double __attribute__ ((vector_size(16))) __b,
    double __attribute__ ((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_orpd128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_orpd128_mask((P0), (P1), (P2), (P3))

extern float __attribute__ ((vector_size(32)))
__coverity___builtin_ia32_orps256_mask(
    float __attribute__ ((vector_size(32))) __a,
    float __attribute__ ((vector_size(32))) __b,
    float __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_orps256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_orps256_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_orps128_mask(
    float __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_orps128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_orps128_mask((P0), (P1), (P2), (P3))

void __coverity___builtin_ia32_fxsave64(void *p);
#define __builtin_ia32_fxsave64(P0) \
    __coverity___builtin_ia32_fxsave64((P0))

void __coverity___builtin_ia32_fxsave(void *p);
#define __builtin_ia32_fxsave(P0) \
    __coverity___builtin_ia32_fxsave((P0))

void __coverity___builtin_ia32_fxrstor64(void *p);
#define __builtin_ia32_fxrstor64(P0) \
    __coverity___builtin_ia32_fxrstor64((P0))

void __coverity___builtin_ia32_fxrstor(void *p);
#define __builtin_ia32_fxrstor(P0) \
    __coverity___builtin_ia32_fxrstor((P0))

extern long long __attribute__((__vector_size__(64)))
__coverity___builtin_ia32_pmovsxbd512_mask(
    char __attribute__((vector_size(16))) __a,
    int __attribute__((__vector_size__(64))) __b,
    unsigned short __u);
#define __builtin_ia32_pmovsxbd512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pmovsxbd512_mask((P0), (P1), (P2))

extern long long __attribute__((__vector_size__(64)))
__coverity___builtin_ia32_pmovsxbq512_mask(
    char __attribute__((vector_size(16))) __a,
    long long __attribute__((__vector_size__(64))) __b,
    unsigned char __u);
#define __builtin_ia32_pmovsxbq512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pmovsxbq512_mask((P0), (P1), (P2))

extern long long __attribute__((__vector_size__(64)))
__coverity___builtin_ia32_pmovsxdq512_mask(
    int __attribute__ ((vector_size(32))) __a,
    long long __attribute__((__vector_size__(64))) __b,
    unsigned char __u);
#define __builtin_ia32_pmovsxdq512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pmovsxdq512_mask((P0), (P1), (P2))

extern long long __attribute__((__vector_size__(64)))
__coverity___builtin_ia32_pmovsxwd512_mask(
    short __attribute__ ((vector_size(32))) __a,
    int __attribute__((__vector_size__(64))) __b,
    unsigned short __u);
#define __builtin_ia32_pmovsxwd512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pmovsxwd512_mask((P0), (P1), (P2))

extern long long __attribute__((__vector_size__(64)))
__coverity___builtin_ia32_pmovsxwq512_mask(
    short __attribute__((vector_size(16))) __a,
    long long __attribute__((__vector_size__(64))) __b,
    unsigned char __u);
#define __builtin_ia32_pmovsxwq512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pmovsxwq512_mask((P0), (P1), (P2))

extern long long __attribute__((__vector_size__(64)))
__coverity___builtin_ia32_pmovzxbd512_mask(
    char __attribute__((vector_size(16))) __a,
    int __attribute__((__vector_size__(64))) __b,
    unsigned short __u);
#define __builtin_ia32_pmovzxbd512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pmovzxbd512_mask((P0), (P1), (P2))

extern long long __attribute__((__vector_size__(64)))
__coverity___builtin_ia32_pmovzxbq512_mask(
    char __attribute__((vector_size(16))) __a,
    long long __attribute__((__vector_size__(64))) __b,
    unsigned char __u);
#define __builtin_ia32_pmovzxbq512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pmovzxbq512_mask((P0), (P1), (P2))

extern long long __attribute__((__vector_size__(64)))
__coverity___builtin_ia32_pmovzxdq512_mask(
    int __attribute__ ((vector_size(32))) __a,
    long long __attribute__((__vector_size__(64))) __b,
    unsigned char __u);
#define __builtin_ia32_pmovzxdq512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pmovzxdq512_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmovsxbd128_mask(
    char __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    unsigned char __u);
#define __builtin_ia32_pmovsxbd128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pmovsxbd128_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmovsxbd256_mask(
    char __attribute__((vector_size(16))) __a,
    int __attribute__ ((vector_size(32))) __b,
    unsigned char __u);
#define __builtin_ia32_pmovsxbd256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pmovsxbd256_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmovsxbq128_mask(
    char __attribute__((vector_size(16))) __a,
    long long __attribute__ ((vector_size(16))) __b,
    unsigned char __u);
#define __builtin_ia32_pmovsxbq128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pmovsxbq128_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmovsxbq256_mask(
    char __attribute__((vector_size(16))) __a,
    long long __attribute__ ((vector_size(32))) __b,
    unsigned char __u);
#define __builtin_ia32_pmovsxbq256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pmovsxbq256_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmovsxdq128_mask(
    int __attribute__((vector_size(16))) __a,
    long long __attribute__ ((vector_size(16))) __b,
    unsigned char __u);
#define __builtin_ia32_pmovsxdq128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pmovsxdq128_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmovsxdq256_mask(
    int __attribute__((vector_size(16))) __a,
    long long __attribute__ ((vector_size(32))) __b,
    unsigned char __u);
#define __builtin_ia32_pmovsxdq256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pmovsxdq256_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmovsxwd128_mask(
    short __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    unsigned char __u);
#define __builtin_ia32_pmovsxwd128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pmovsxwd128_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmovsxwd256_mask(
    short __attribute__((vector_size(16))) __a,
    int __attribute__ ((vector_size(32))) __b,
    unsigned char __u);
#define __builtin_ia32_pmovsxwd256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pmovsxwd256_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmovsxwq128_mask(
    short __attribute__((vector_size(16))) __a,
    long long __attribute__ ((vector_size(16))) __b,
    unsigned char __u);
#define __builtin_ia32_pmovsxwq128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pmovsxwq128_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmovsxwq256_mask(
    short __attribute__((vector_size(16))) __a,
    long long __attribute__ ((vector_size(32))) __b,
    unsigned char __u);
#define __builtin_ia32_pmovsxwq256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pmovsxwq256_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmovzxbd128_mask(
    char __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    unsigned char __u);
#define __builtin_ia32_pmovzxbd128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pmovzxbd128_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmovzxbd256_mask(
    char __attribute__((vector_size(16))) __a,
    int __attribute__ ((vector_size(32))) __b,
    unsigned char __u);
#define __builtin_ia32_pmovzxbd256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pmovzxbd256_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmovzxbq128_mask(
    char __attribute__((vector_size(16))) __a,
    long long __attribute__ ((vector_size(16))) __b,
    unsigned char __u);
#define __builtin_ia32_pmovzxbq128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pmovzxbq128_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmovzxbq256_mask(
    char __attribute__((vector_size(16))) __a,
    long long __attribute__ ((vector_size(32))) __b,
    unsigned char __u);
#define __builtin_ia32_pmovzxbq256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pmovzxbq256_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmovzxdq128_mask(
    int __attribute__((vector_size(16))) __a,
    long long __attribute__ ((vector_size(16))) __b,
    unsigned char __u);
#define __builtin_ia32_pmovzxdq128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pmovzxdq128_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmovzxdq256_mask(
    int __attribute__((vector_size(16))) __a,
    long long __attribute__ ((vector_size(32))) __b,
    unsigned char __u);
#define __builtin_ia32_pmovzxdq256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pmovzxdq256_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmovzxwd128_mask(
    short __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    unsigned char __u);
#define __builtin_ia32_pmovzxwd128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pmovzxwd128_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmovzxwd256_mask(
    short __attribute__((vector_size(16))) __a,
    int __attribute__ ((vector_size(32))) __b,
    unsigned char __u);
#define __builtin_ia32_pmovzxwd256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pmovzxwd256_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmovzxwq128_mask(
    short __attribute__((vector_size(16))) __a,
    long long __attribute__ ((vector_size(16))) __b,
    unsigned char __u);
#define __builtin_ia32_pmovzxwq128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pmovzxwq128_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmovzxwq256_mask(
    short __attribute__((vector_size(16))) __a,
    long long __attribute__ ((vector_size(32))) __b,
    unsigned char __u);
#define __builtin_ia32_pmovzxwq256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pmovzxwq256_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pslld128_mask(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    int __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_pslld128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pslld128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pslld256_mask(
    int __attribute__ ((vector_size(32))) __a,
    int __attribute__((vector_size(16))) __b,
    int __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_pslld256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pslld256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_psllq128_mask(
    long long __attribute__ ((vector_size(16))) __a,
    long long __attribute__ ((vector_size(16))) __b,
    long long __attribute__ ((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_psllq128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psllq128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_psllq256_mask(
    long long __attribute__ ((vector_size(32))) __a,
    long long __attribute__ ((vector_size(16))) __b,
    long long __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_psllq256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psllq256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_psllv2di_mask(
    long long __attribute__ ((vector_size(16))) __a,
    long long __attribute__ ((vector_size(16))) __b,
    long long __attribute__ ((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_psllv2di_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psllv2di_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_psllv4di_mask(
    long long __attribute__ ((vector_size(32))) __a,
    long long __attribute__ ((vector_size(32))) __b,
    long long __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_psllv4di_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psllv4di_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_psllv4si_mask(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    int __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_psllv4si_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psllv4si_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_psllv8si_mask(
    int __attribute__ ((vector_size(32))) __a,
    int __attribute__ ((vector_size(32))) __b,
    int __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_psllv8si_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psllv8si_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_psrlv2di_mask(
    long long __attribute__ ((vector_size(16))) __a,
    long long __attribute__ ((vector_size(16))) __b,
    long long __attribute__ ((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_psrlv2di_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psrlv2di_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_psrlv4di_mask(
    long long __attribute__ ((vector_size(32))) __a,
    long long __attribute__ ((vector_size(32))) __b,
    long long __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_psrlv4di_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psrlv4di_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_psrlv4si_mask(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    int __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_psrlv4si_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psrlv4si_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_psrlv8si_mask(
    int __attribute__ ((vector_size(32))) __a,
    int __attribute__ ((vector_size(32))) __b,
    int __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_psrlv8si_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psrlv8si_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_psrld128_mask(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    int __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_psrld128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psrld128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_psrld256_mask(
    int __attribute__ ((vector_size(32))) __a,
    int __attribute__((vector_size(16))) __b,
    int __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_psrld256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psrld256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_psrlq128_mask(
    long long __attribute__ ((vector_size(16))) __a,
    long long __attribute__ ((vector_size(16))) __b,
    long long __attribute__ ((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_psrlq128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psrlq128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_psrlq256_mask(
    long long __attribute__ ((vector_size(32))) __a,
    long long __attribute__ ((vector_size(16))) __b,
    long long __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_psrlq256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psrlq256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_psrav4si_mask(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    int __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_psrav4si_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psrav4si_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_psrav8si_mask(
    int __attribute__ ((vector_size(32))) __a,
    int __attribute__ ((vector_size(32))) __b,
    int __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_psrav8si_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psrav8si_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((__vector_size__(64)))
__coverity___builtin_ia32_pmovzxwd512_mask(
    short __attribute__ ((vector_size(32))) __a,
    int __attribute__((__vector_size__(64))) __b,
    unsigned short __u);
#define __builtin_ia32_pmovzxwd512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pmovzxwd512_mask((P0), (P1), (P2))

extern long long __attribute__((__vector_size__(64)))
__coverity___builtin_ia32_pmovzxwq512_mask(
    short __attribute__((vector_size(16))) __a,
    long long __attribute__((__vector_size__(64))) __b,
    unsigned char __u);
#define __builtin_ia32_pmovzxwq512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pmovzxwq512_mask((P0), (P1), (P2))

extern long long __attribute__((__vector_size__(64)))
__coverity___builtin_ia32_pslld512_mask(
    int __attribute__((__vector_size__(64))) __a,
    int __attribute__((vector_size(16))) __b,
    int __attribute__((__vector_size__(64))) __c,
    unsigned short __u);
#define __builtin_ia32_pslld512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pslld512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((__vector_size__(64)))
__coverity___builtin_ia32_psllq512_mask(
    long long __attribute__((__vector_size__(64))) __a,
    long long __attribute__ ((vector_size(16))) __b,
    long long __attribute__((__vector_size__(64))) __c,
    unsigned char __u);
#define __builtin_ia32_psllq512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psllq512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((__vector_size__(64)))
__coverity___builtin_ia32_psllv16si_mask(
    int __attribute__((__vector_size__(64))) __a,
    int __attribute__((__vector_size__(64))) __b,
    int __attribute__((__vector_size__(64))) __c,
    unsigned short __u);
#define __builtin_ia32_psllv16si_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psllv16si_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((__vector_size__(64)))
__coverity___builtin_ia32_psllv8di_mask(
    long long __attribute__((__vector_size__(64))) __a,
    long long __attribute__((__vector_size__(64))) __b,
    long long __attribute__((__vector_size__(64))) __c,
    unsigned char __u);
#define __builtin_ia32_psllv8di_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psllv8di_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((__vector_size__(64)))
__coverity___builtin_ia32_psrad512_mask(
    int __attribute__((__vector_size__(64))) __a,
    int __attribute__((vector_size(16))) __b,
    int __attribute__((__vector_size__(64))) __c,
    unsigned short __u);
#define __builtin_ia32_psrad512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psrad512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((__vector_size__(64)))
__coverity___builtin_ia32_psraq512_mask(
    long long __attribute__((__vector_size__(64))) __a,
    long long __attribute__ ((vector_size(16))) __b,
    long long __attribute__((__vector_size__(64))) __c,
    unsigned char __u);
#define __builtin_ia32_psraq512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psraq512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((__vector_size__(64)))
__coverity___builtin_ia32_psrav16si_mask(
    int __attribute__((__vector_size__(64))) __a,
    int __attribute__((__vector_size__(64))) __b,
    int __attribute__((__vector_size__(64))) __c,
    unsigned short __u);
#define __builtin_ia32_psrav16si_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psrav16si_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((__vector_size__(64)))
__coverity___builtin_ia32_psrav8di_mask(
    long long __attribute__((__vector_size__(64))) __a,
    long long __attribute__((__vector_size__(64))) __b,
    long long __attribute__((__vector_size__(64))) __c,
    unsigned char __u);
#define __builtin_ia32_psrav8di_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psrav8di_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((__vector_size__(64)))
__coverity___builtin_ia32_psrld512_mask(
    int __attribute__((__vector_size__(64))) __a,
    int __attribute__((vector_size(16))) __b,
    int __attribute__((__vector_size__(64))) __c,
    unsigned short __u);
#define __builtin_ia32_psrld512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psrld512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((__vector_size__(64)))
__coverity___builtin_ia32_psrlq512_mask(
    long long __attribute__((__vector_size__(64))) __a,
    long long __attribute__ ((vector_size(16))) __b,
    long long __attribute__((__vector_size__(64))) __c,
    unsigned char __u);
#define __builtin_ia32_psrlq512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psrlq512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((__vector_size__(64)))
__coverity___builtin_ia32_psrlv16si_mask(
    int __attribute__((__vector_size__(64))) __a,
    int __attribute__((__vector_size__(64))) __b,
    int __attribute__((__vector_size__(64))) __c,
    unsigned short __u);
#define __builtin_ia32_psrlv16si_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psrlv16si_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((__vector_size__(64)))
__coverity___builtin_ia32_psrlv8di_mask(
    long long __attribute__((__vector_size__(64))) __a,
    long long __attribute__((__vector_size__(64))) __b,
    long long __attribute__((__vector_size__(64))) __c,
    unsigned char __u);
#define __builtin_ia32_psrlv8di_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psrlv8di_mask((P0), (P1), (P2), (P3))

extern double __attribute__((__vector_size__(64)))
__coverity___builtin_ia32_vpermilvarpd512_mask(
    double __attribute__((__vector_size__(64))) __a,
    long long __attribute__((__vector_size__(64))) __b,
    double __attribute__((__vector_size__(64))) __c,
    unsigned char __u);
#define __builtin_ia32_vpermilvarpd512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermilvarpd512_mask((P0), (P1), (P2), (P3))

extern float __attribute__((__vector_size__(64)))
__coverity___builtin_ia32_vpermilvarps512_mask(
    float __attribute__((__vector_size__(64))) __a,
    int __attribute__((__vector_size__(64))) __b,
    float __attribute__((__vector_size__(64))) __c,
    unsigned short __u);
#define __builtin_ia32_vpermilvarps512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermilvarps512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_psravq128_mask(
    long long __attribute__ ((vector_size(16))) __a,
    long long __attribute__ ((vector_size(16))) __b,
    long long __attribute__ ((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_psravq128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psravq128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_psravq256_mask(
    long long __attribute__ ((vector_size(32))) __a,
    long long __attribute__ ((vector_size(32))) __b,
    long long __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_psravq256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psravq256_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpermilvarpd_mask(
    double __attribute__ ((vector_size(16))) __a,
    long long __attribute__ ((vector_size(16))) __b,
    double __attribute__ ((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_vpermilvarpd_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermilvarpd_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpermilvarpd256_mask(
    double __attribute__ ((vector_size(32))) __a,
    long long __attribute__ ((vector_size(32))) __b,
    double __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_vpermilvarpd256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermilvarpd256_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpermilvarps_mask(
    float __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_vpermilvarps_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermilvarps_mask((P0), (P1), (P2), (P3))

extern float __attribute__ ((vector_size(32)))
__coverity___builtin_ia32_vpermilvarps256_mask(
    float __attribute__ ((vector_size(32))) __a,
    int __attribute__ ((vector_size(32))) __b,
    float __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_vpermilvarps256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermilvarps256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_psrad128_mask(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    int __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_psrad128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psrad128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_psrad256_mask(
    int __attribute__ ((vector_size(32))) __a,
    int __attribute__((vector_size(16))) __b,
    int __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_psrad256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psrad256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_psraq128_mask(
    long long __attribute__ ((vector_size(16))) __a,
    long long __attribute__ ((vector_size(16))) __b,
    long long __attribute__ ((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_psraq128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psraq128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_psraq256_mask(
    long long __attribute__ ((vector_size(32))) __a,
    long long __attribute__ ((vector_size(16))) __b,
    long long __attribute__ ((vector_size(32))) __c,
    unsigned char __u);
#define __builtin_ia32_psraq256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psraq256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((__vector_size__(64)))
__coverity___builtin_ia32_pmovsxbw512_mask(
    char __attribute__ ((vector_size(32))) __a,
    short __attribute__((__vector_size__(64))) __b,
    unsigned int __u);
#define __builtin_ia32_pmovsxbw512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pmovsxbw512_mask((P0), (P1), (P2))

extern long long __attribute__((__vector_size__(64)))
__coverity___builtin_ia32_pmovzxbw512_mask(
    char __attribute__ ((vector_size(32))) __a,
    short __attribute__((__vector_size__(64))) __b,
    unsigned int __u);
#define __builtin_ia32_pmovzxbw512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pmovzxbw512_mask((P0), (P1), (P2))

extern long long __attribute__((__vector_size__(64)))
__coverity___builtin_ia32_psllv32hi_mask(
    short __attribute__((__vector_size__(64))) __a,
    short __attribute__((__vector_size__(64))) __b,
    short __attribute__((__vector_size__(64))) __c,
    unsigned int __u);
#define __builtin_ia32_psllv32hi_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psllv32hi_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((__vector_size__(64)))
__coverity___builtin_ia32_psllw512_mask(
    short __attribute__((__vector_size__(64))) __a,
    short __attribute__((vector_size(16))) __b,
    short __attribute__((__vector_size__(64))) __c,
    unsigned int __u);
#define __builtin_ia32_psllw512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psllw512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((__vector_size__(64)))
__coverity___builtin_ia32_psrlv32hi_mask(
    short __attribute__((__vector_size__(64))) __a,
    short __attribute__((__vector_size__(64))) __b,
    short __attribute__((__vector_size__(64))) __c,
    unsigned int __u);
#define __builtin_ia32_psrlv32hi_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psrlv32hi_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((__vector_size__(64)))
__coverity___builtin_ia32_psrav32hi_mask(
    short __attribute__((__vector_size__(64))) __a,
    short __attribute__((__vector_size__(64))) __b,
    short __attribute__((__vector_size__(64))) __c,
    unsigned int __u);
#define __builtin_ia32_psrav32hi_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psrav32hi_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((__vector_size__(64)))
__coverity___builtin_ia32_psraw512_mask(
    short __attribute__((__vector_size__(64))) __a,
    short __attribute__((vector_size(16))) __b,
    short __attribute__((__vector_size__(64))) __c,
    unsigned int __u);
#define __builtin_ia32_psraw512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psraw512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((__vector_size__(64)))
__coverity___builtin_ia32_psrlw512_mask(
    short __attribute__((__vector_size__(64))) __a,
    short __attribute__((vector_size(16))) __b,
    short __attribute__((__vector_size__(64))) __c,
    unsigned int __u);
#define __builtin_ia32_psrlw512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psrlw512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmovsxbw128_mask(
    char __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b,
    unsigned char __u);
#define __builtin_ia32_pmovsxbw128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pmovsxbw128_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmovsxbw256_mask(
    char __attribute__((vector_size(16))) __a,
    short __attribute__ ((vector_size(32))) __b,
    unsigned short __u);
#define __builtin_ia32_pmovsxbw256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pmovsxbw256_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmovzxbw128_mask(
    char __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b,
    unsigned char __u);
#define __builtin_ia32_pmovzxbw128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pmovzxbw128_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmovzxbw256_mask(
    char __attribute__((vector_size(16))) __a,
    short __attribute__ ((vector_size(32))) __b,
    unsigned short __u);
#define __builtin_ia32_pmovzxbw256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pmovzxbw256_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_psllv16hi_mask(
    short __attribute__ ((vector_size(32))) __a,
    short __attribute__ ((vector_size(32))) __b,
    short __attribute__ ((vector_size(32))) __c,
    unsigned short __u);
#define __builtin_ia32_psllv16hi_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psllv16hi_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_psllv8hi_mask(
    short __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b,
    short __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_psllv8hi_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psllv8hi_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_psllw128_mask(
    short __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b,
    short __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_psllw128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psllw128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_psllw256_mask(
    short __attribute__ ((vector_size(32))) __a,
    short __attribute__((vector_size(16))) __b,
    short __attribute__ ((vector_size(32))) __c,
    unsigned short __u);
#define __builtin_ia32_psllw256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psllw256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_psrlv16hi_mask(
    short __attribute__ ((vector_size(32))) __a,
    short __attribute__ ((vector_size(32))) __b,
    short __attribute__ ((vector_size(32))) __c,
    unsigned short __u);
#define __builtin_ia32_psrlv16hi_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psrlv16hi_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_psrlv8hi_mask(
    short __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b,
    short __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_psrlv8hi_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psrlv8hi_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_psrav16hi_mask(
    short __attribute__ ((vector_size(32))) __a,
    short __attribute__ ((vector_size(32))) __b,
    short __attribute__ ((vector_size(32))) __c,
    unsigned short __u);
#define __builtin_ia32_psrav16hi_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psrav16hi_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_psrav8hi_mask(
    short __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b,
    short __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_psrav8hi_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psrav8hi_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_psraw128_mask(
    short __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b,
    short __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_psraw128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psraw128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_psraw256_mask(
    short __attribute__ ((vector_size(32))) __a,
    short __attribute__((vector_size(16))) __b,
    short __attribute__ ((vector_size(32))) __c,
    unsigned short __u);
#define __builtin_ia32_psraw256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psraw256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_psrlw128_mask(
    short __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b,
    short __attribute__((vector_size(16))) __c,
    unsigned char __u);
#define __builtin_ia32_psrlw128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psrlw128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_psrlw256_mask(
    short __attribute__ ((vector_size(32))) __a,
    short __attribute__((vector_size(16))) __b,
    short __attribute__ ((vector_size(32))) __c,
    unsigned short __u);
#define __builtin_ia32_psrlw256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psrlw256_mask((P0), (P1), (P2), (P3))

#endif /* } clang < 4.0 */


/*************************************
 ************ Clang 5.0 **************
 *************************************/

#if (__cov_clang_version_lt(5, 0)) /* { */

/* Signatures changed in Clang 5.0 { */

/* Clang 5.0 introduced a new 'N' type signature that specifies an 'int'
 * type for LP64 targets and a 'long' type for LLP64 targets.  The signatures
 * of a number of builtins were changed to use the new 'N' type signature in
 * place of 'L' and therefore show up in audits of changed builtin functions.
 * In practice, there is little impact to callers (the change was made to
 * maintain consistent behavior for Microsoft extensions on LP64 and LLP64
 * targets).  Compatibility signatures are therefore not defined here.  This
 * change was made in r305875:
 *   http://llvm.org/viewvc/llvm-project?view=revision&revision=305875
 * The signatures of the following builtins were impacted:
 *   _BitScanForward
 *   _BitScanForward64
 *   _BitScanReverse
 *   _BitScanReverse64
 *   _InterlockedAnd
 *   _InterlockedCompareExchange
 *   _InterlockedDecrement
 *   _InterlockedExchange
 *   _InterlockedExchangeAdd
 *   _InterlockedExchangeSub
 *   _InterlockedIncrement
 *   _InterlockedOr
 *   _InterlockedXor
 *   __exception_code
 *   __readfsdword
 *   _byteswap_ulong
 *   _exception_code
 *   _lrotl
 *   _lrotr
 */

/* The signatures of a number of builtins were altered to reflect a requirement
 * that one of the operands is an integral constant expression.  Prior to this
 * change invocations that passed a non-constant expression were not rejected
 * with an error message, but triggered assertion failures later.  Since these
 * builtins effectively required callers to adhere to the new signatures,
 * compatibility signatures are not defined here.  These changes were made in
 * r305401 and r297584:
 *   http://llvm.org/viewvc/llvm-project?view=revision&revision=305401
 *   http://llvm.org/viewvc/llvm-project?view=revision&revision=297584
 * The signatures of the following builtins were impacted:
 *   __builtin_altivec_vcfsx
 *   __builtin_altivec_vcfux
 *   __builtin_altivec_vctsxs
 *   __builtin_altivec_vctuxs
 *   __builtin_ia32_gather3div2df
 *   __builtin_ia32_gather3div2di
 *   __builtin_ia32_gather3div4df
 *   __builtin_ia32_gather3div4di
 *   __builtin_ia32_gather3div4sf
 *   __builtin_ia32_gather3div4si
 *   __builtin_ia32_gather3div8sf
 *   __builtin_ia32_gather3div8si
 *   __builtin_ia32_gather3siv2df
 *   __builtin_ia32_gather3siv2di
 *   __builtin_ia32_gather3siv4df
 *   __builtin_ia32_gather3siv4di
 *   __builtin_ia32_gather3siv4sf
 *   __builtin_ia32_gather3siv4si
 *   __builtin_ia32_gather3siv8sf
 *   __builtin_ia32_gather3siv8si
 */

/* The signature of __builtin_arm_usat was corrected to mark the first parameter
 * as 'int' rather than 'unsigned int'.  This signature change does not break
 * existing callers, so no compatibility signature is defined here.  This change
 * was made in r302131:
 *   http://llvm.org/viewvc/llvm-project?view=revision&revision=302131
 */

/* The signature of __builtin_coro_end was changed to return 'bool' instead of
 * 'void'.  This signature change does not break existing callers, so no
 * compatibility signature is defined here.  This change was made in r297224:
 *   http://llvm.org/viewvc/llvm-project?view=revision&revision=297224
 */

/* The signature of __builtin_wasm_grow_memory was changed to return 'size_t'
 * instead of 'void'.  This signature change does not break existing callers,
 * so no compatibility signature is defined here.  This change was made in
 * r292324:
 *   http://llvm.org/viewvc/llvm-project?view=revision&revision=292324
 */

/* } Changed in Clang 5.0 */

/* These prototypes were removed in Clang 5.0 { */

/* These builtins were removed in r292329:
 *   http://llvm.org/viewvc/llvm-project?view=revision&revision=292329
 * { */

// Signature: "V8fV4fV8fUc"
extern float __attribute__((vector_size(32)))
__coverity___builtin_ia32_broadcastf32x4_256_mask(
    float __attribute__ ((vector_size(16))) p0,
    float __attribute__ ((vector_size(32))) p1,
    unsigned char p2);
#define __builtin_ia32_broadcastf32x4_256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_broadcastf32x4_256_mask((P0), (P1), (P2))

// Signature: "V16fV4fV16fUs"
extern float __attribute__((vector_size(64)))
__coverity___builtin_ia32_broadcastf32x4_512(
    float __attribute__ ((vector_size(16))) p0,
    float __attribute__ ((vector_size(64))) p1,
    unsigned short p2);
#define __builtin_ia32_broadcastf32x4_512(P0, P1, P2) \
    __coverity___builtin_ia32_broadcastf32x4_512((P0), (P1), (P2))

// Signature: "V16fV8fV16fUs"
extern float __attribute__((vector_size(64)))
__coverity___builtin_ia32_broadcastf32x8_512_mask(
    float __attribute__ ((vector_size(32))) p0,
    float __attribute__ ((vector_size(64))) p1,
    unsigned short p2);
#define __builtin_ia32_broadcastf32x8_512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_broadcastf32x8_512_mask((P0), (P1), (P2))

// Signature: "V4dV2dV4dUc"
extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_broadcastf64x2_256_mask(
    double __attribute__ ((vector_size(16))) p0,
    double __attribute__ ((vector_size(32))) p1,
    unsigned char p2);
#define __builtin_ia32_broadcastf64x2_256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_broadcastf64x2_256_mask((P0), (P1), (P2))

// Signature: "V8dV2dV8dUc"
extern double __attribute__((vector_size(64)))
__coverity___builtin_ia32_broadcastf64x2_512_mask(
    double __attribute__ ((vector_size(16))) p0,
    double __attribute__ ((vector_size(64))) p1,
    unsigned char p2);
#define __builtin_ia32_broadcastf64x2_512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_broadcastf64x2_512_mask((P0), (P1), (P2))

// Signature: "V8dV4dV8dUc"
extern double __attribute__((vector_size(64)))
__coverity___builtin_ia32_broadcastf64x4_512(
    double __attribute__ ((vector_size(32))) p0,
    double __attribute__ ((vector_size(64))) p1,
    unsigned char p2);
#define __builtin_ia32_broadcastf64x4_512(P0, P1, P2) \
    __coverity___builtin_ia32_broadcastf64x4_512((P0), (P1), (P2))

// Signature: "V8iV4iV8iUc"
extern int __attribute__((vector_size(32)))
__coverity___builtin_ia32_broadcasti32x4_256_mask(
    int __attribute__ ((vector_size(16))) p0,
    int __attribute__ ((vector_size(32))) p1,
    unsigned char p2);
#define __builtin_ia32_broadcasti32x4_256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_broadcasti32x4_256_mask((P0), (P1), (P2))

// Signature: "V16iV4iV16iUs"
extern int __attribute__((vector_size(64)))
__coverity___builtin_ia32_broadcasti32x4_512(
    int __attribute__ ((vector_size(16))) p0,
    int __attribute__ ((vector_size(64))) p1,
    unsigned short p2);
#define __builtin_ia32_broadcasti32x4_512(P0, P1, P2) \
    __coverity___builtin_ia32_broadcasti32x4_512((P0), (P1), (P2))

// Signature: "V16iV8iV16iUs"
extern int __attribute__((vector_size(64)))
__coverity___builtin_ia32_broadcasti32x8_512_mask(
    int __attribute__ ((vector_size(32))) p0,
    int __attribute__ ((vector_size(64))) p1,
    unsigned short p2);
#define __builtin_ia32_broadcasti32x8_512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_broadcasti32x8_512_mask((P0), (P1), (P2))

// Signature: "V4LLiV2LLiV4LLiUc"
extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_broadcasti64x2_256_mask(
    long long __attribute__ ((vector_size(16))) p0,
    long long __attribute__ ((vector_size(32))) p1,
    unsigned char p2);
#define __builtin_ia32_broadcasti64x2_256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_broadcasti64x2_256_mask((P0), (P1), (P2))

// Signature: "V8LLiV2LLiV8LLiUc"
extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_broadcasti64x2_512_mask(
    long long __attribute__ ((vector_size(16))) p0,
    long long __attribute__ ((vector_size(64))) p1,
    unsigned char p2);
#define __builtin_ia32_broadcasti64x2_512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_broadcasti64x2_512_mask((P0), (P1), (P2))

// Signature: "V8LLiV4LLiV8LLiUc"
extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_broadcasti64x4_512(
    long long __attribute__ ((vector_size(32))) p0,
    long long __attribute__ ((vector_size(64))) p1,
    unsigned char p2);
#define __builtin_ia32_broadcasti64x4_512(P0, P1, P2) \
    __coverity___builtin_ia32_broadcasti64x4_512((P0), (P1), (P2))

/* } */

/* These builtins were removed in r300326:
 *   http://llvm.org/viewvc/llvm-project?view=revision&revision=300326
 * { */

#if (__cov_clang_version_ge(3, 8)) /* { */

/* The signatures of __builtin_ia32_movntdqa and __builtin_ia32_movntdqa256 were
 * previously changed in Clang 3.8.  For Clang versions older than 3.8,
 * compatibility signatures have already been declared.  The signatures declared
 * here correspond to Clang 3.8-4.0.
 */

// Signature: "V2LLiV2LLiC*"
extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_movntdqa(
    const long long __attribute__ ((vector_size(16))) *p0);
#define __builtin_ia32_movntdqa(P0) \
    __coverity___builtin_ia32_movntdqa((P0))

// The signature of __builtin_ia32_movntdqa256 chaanged in Clang 3.8, so for
// Clang versions older than that, a compatibility signature has already been
// declared.
// Signature: "V4LLiV4LLiC*"
extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_movntdqa256(
    const long long __attribute__((vector_size(32))) *p0);
#define __builtin_ia32_movntdqa256(P0) \
    __coverity___builtin_ia32_movntdqa256((P0))

#endif /* } clang >= 3.8 */

// Signature: "V8LLiV8LLi*"
extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_movntdqa512(
    long long __attribute__ ((vector_size(64))) *p0);
#define __builtin_ia32_movntdqa512(P0) \
    __coverity___builtin_ia32_movntdqa512((P0))

/* } */

/* These builtins were removed in r295291:
 *   http://llvm.org/viewvc/llvm-project?view=revision&revision=295291
 * { */

// Signature: "V32sV16iV16iV32sUi"
extern short __attribute__((vector_size(64)))
__coverity___builtin_ia32_packssdw512_mask(
    int __attribute__ ((vector_size(64))) p0,
    int __attribute__ ((vector_size(64))) p1,
    short __attribute__ ((vector_size(64))) p2,
    unsigned int p3);
#define __builtin_ia32_packssdw512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_packssdw512_mask((P0), (P1), (P2), (P3))

// Signature: "V64cV32sV32sV64cULLi"
extern char __attribute__((vector_size(64)))
__coverity___builtin_ia32_packsswb512_mask(
    short __attribute__ ((vector_size(64))) p0,
    short __attribute__ ((vector_size(64))) p1,
    char __attribute__ ((vector_size(64))) p2,
    unsigned long long p3);
#define __builtin_ia32_packsswb512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_packsswb512_mask((P0), (P1), (P2), (P3))

// Signature: "V32sV16iV16iV32sUi"
extern short __attribute__((vector_size(64)))
__coverity___builtin_ia32_packusdw512_mask(
    int __attribute__ ((vector_size(64))) p0,
    int __attribute__ ((vector_size(64))) p1,
    short __attribute__ ((vector_size(64))) p2,
    unsigned int p3);
#define __builtin_ia32_packusdw512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_packusdw512_mask((P0), (P1), (P2), (P3))

// Signature: "V64cV32sV32sV64cULLi"
extern char __attribute__((vector_size(64)))
__coverity___builtin_ia32_packuswb512_mask(
    short __attribute__ ((vector_size(64))) p0,
    short __attribute__ ((vector_size(64))) p1,
    char __attribute__ ((vector_size(64))) p2,
    unsigned long long p3);
#define __builtin_ia32_packuswb512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_packuswb512_mask((P0), (P1), (P2), (P3))

/* } */

/* These builtins were removed in r295570:
 *   http://llvm.org/viewvc/llvm-project?view=revision&revision=295570
 * { */

// Signature: "V2LLiV2LLiV2LLiV2LLi"
extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpcmov(
    long long __attribute__ ((vector_size(16))) p0,
    long long __attribute__ ((vector_size(16))) p1,
    long long __attribute__ ((vector_size(16))) p2);
#define __builtin_ia32_vpcmov(P0, P1, P2) \
    __coverity___builtin_ia32_vpcmov((P0), (P1), (P2))

// Signature: "V4LLiV4LLiV4LLiV4LLi"
extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpcmov_256(
    long long __attribute__ ((vector_size(32))) p0,
    long long __attribute__ ((vector_size(32))) p1,
    long long __attribute__ ((vector_size(32))) p2);
#define __builtin_ia32_vpcmov_256(P0, P1, P2) \
    __coverity___builtin_ia32_vpcmov_256((P0), (P1), (P2))

/* } */

/* These builtins were removed in r292694:
 *   http://llvm.org/viewvc/llvm-project?view=revision&revision=292694
 * { */

// Signature: "ii"
extern int __coverity___nvvm_abs_i(int p0);
#define __nvvm_abs_i(P0) \
    __coverity___nvvm_abs_i((P0))

// Signature: "LLiLLi"
extern long long __coverity___nvvm_abs_ll(long long p0);
#define __nvvm_abs_ll(P0) \
    __coverity___nvvm_abs_ll((P0))

// Signature: "UiUi"
extern unsigned int __coverity___nvvm_brev32(unsigned int p0);
#define __nvvm_brev32(P0) \
    __coverity___nvvm_brev32((P0))

// Signature: "ULLiULLi"
extern unsigned long long __coverity___nvvm_brev64(unsigned long long p0);
#define __nvvm_brev64(P0) \
    __coverity___nvvm_brev64((P0))

// Signature: "ii"
extern int __coverity___nvvm_clz_i(int p0);
#define __nvvm_clz_i(P0) \
    __coverity___nvvm_clz_i((P0))

// Signature: "iLLi"
extern int __coverity___nvvm_clz_ll(long long p0);
#define __nvvm_clz_ll(P0) \
    __coverity___nvvm_clz_ll((P0))

// Signature: "fUs"
extern float __coverity___nvvm_h2f(unsigned short p0);
#define __nvvm_h2f(P0) \
    __coverity___nvvm_h2f((P0))

// Signature: "iii"
extern int __coverity___nvvm_max_i(int p0, int p1);
#define __nvvm_max_i(P0, P1) \
    __coverity___nvvm_max_i((P0), (P1))

// Signature: "LLiLLiLLi"
extern long long __coverity___nvvm_max_ll(long long p0, long long p1);
#define __nvvm_max_ll(P0, P1) \
    __coverity___nvvm_max_ll((P0), (P1))

// Signature: "UiUiUi"
extern unsigned int __coverity___nvvm_max_ui(unsigned int p0, unsigned int p1);
#define __nvvm_max_ui(P0, P1) \
    __coverity___nvvm_max_ui((P0), (P1))

// Signature: "ULLiULLiULLi"
extern unsigned long long __coverity___nvvm_max_ull(
    unsigned long long p0,
    unsigned long long p1);
#define __nvvm_max_ull(P0, P1) \
    __coverity___nvvm_max_ull((P0), (P1))

// Signature: "iii"
extern int __coverity___nvvm_min_i(int p0, int p1);
#define __nvvm_min_i(P0, P1) \
    __coverity___nvvm_min_i((P0), (P1))

// Signature: "LLiLLiLLi"
extern long long __coverity___nvvm_min_ll(long long p0, long long p1);
#define __nvvm_min_ll(P0, P1) \
    __coverity___nvvm_min_ll((P0), (P1))

// Signature: "UiUiUi"
extern unsigned int __coverity___nvvm_min_ui(unsigned int p0, unsigned int p1);
#define __nvvm_min_ui(P0, P1) \
    __coverity___nvvm_min_ui((P0), (P1))

// Signature: "ULLiULLiULLi"
extern unsigned long long __coverity___nvvm_min_ull(
    unsigned long long p0,
    unsigned long long p1);
#define __nvvm_min_ull(P0, P1) \
    __coverity___nvvm_min_ull((P0), (P1))

// Signature: "ii"
extern int __coverity___nvvm_popc_i(int p0);
#define __nvvm_popc_i(P0) \
    __coverity___nvvm_popc_i((P0))

// Signature: "iLLi"
extern int __coverity___nvvm_popc_ll(long long p0);
#define __nvvm_popc_ll(P0) \
    __coverity___nvvm_popc_ll((P0))

/* } */

/* } Removed in Clang 5.0 */

#endif /* } clang < 5.0 */


/* Clang 5.0.1 removed __builtin_ia32_pbroadcastq512_mem_mask due to deficient
 * backend support for 32-bit targets.  Support may be re-introduced at some
 * point in the future.  In the meantime, the following compatibility signature
 * is provided for all prior Clang versions (including Clang 5.0.0).
 * This builtin was removed in r313392:
 *   http://llvm.org/viewvc/llvm-project?view=revision&revision=313392
 * { */

// Signature: "V8LLiLLiV8LLiUc"
extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_pbroadcastq512_mem_mask(
    long long p0,
    long long __attribute__((vector_size(64))) p1,
    unsigned char p2);
#define __builtin_ia32_pbroadcastq512_mem_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pbroadcastq512_mem_mask((P0), (P1), (P2))

/* } */


/*************************************
 ************ Clang 6.0 **************
 *************************************/

#if (__cov_clang_version_lt(6, 0)) /* { */

/* Signatures changed in Clang 6.0 { */

/* The signature of __builtin_ia32_clflushopt was corrected to declare the first
 * parameter as 'const void*' rather than 'char*'.  This change was made in
 * r315470:
 *   http://llvm.org/viewvc/llvm-project?view=revision&revision=315470
 * { */

// Signature: vvC*
void __coverity___builtin_ia32_clflushopt(const void *p0);
#define __builtin_ia32_clflushopt(P0) \
    __coverity___builtin_ia32_clflushopt((P0))

/* } */

/* The signatures of get_kernel_preferred_work_group_size_multiple and
 * get_kernel_work_group_size were corrected to return 'unsigned int' rather
 * than 'int'.  This signature change does not break existing callers, so no
 * compatibility signature is defined here.  This change was made in r309678:
 *   http://llvm.org/viewvc/llvm-project?view=revision&revision=309678
 */

/* } Changed in Clang 6.0 */

/* These prototypes were removed in Clang 6.0 { */

/* These builtins were removed in r320609:
 *   http://llvm.org/viewvc/llvm-project?view=revision&revision=320609
 * { */

// Signature: ii
int
__coverity___builtin_SI_to_SXTHI_asrh(
    int p0);
#define __builtin_SI_to_SXTHI_asrh(P0) \
    __coverity___builtin_SI_to_SXTHI_asrh((P0))

// Signature: V16iV16iLLii
int __attribute__ ((vector_size(64)))
__coverity___builtin_HEXAGON_V6_vlutb(
    int __attribute__ ((vector_size(64))) p0,
    long long p1,
    int p2);
#define __builtin_HEXAGON_V6_vlutb(P0, P1, P2) \
    __coverity___builtin_HEXAGON_V6_vlutb((P0), (P1), (P2))

// Signature: V32iV32iLLii
int __attribute__ ((vector_size(128)))
__coverity___builtin_HEXAGON_V6_vlutb_128B(
    int __attribute__ ((vector_size(128))) p0,
    long long p1,
    int p2);
#define __builtin_HEXAGON_V6_vlutb_128B(P0, P1, P2) \
    __coverity___builtin_HEXAGON_V6_vlutb_128B((P0), (P1), (P2))

// Signature: V16iV16iV16iLLii
int __attribute__ ((vector_size(64)))
__coverity___builtin_HEXAGON_V6_vlutb_acc(
    int __attribute__ ((vector_size(64))) p0,
    int __attribute__ ((vector_size(64))) p1,
    long long p2,
    int p3);
#define __builtin_HEXAGON_V6_vlutb_acc(P0, P1, P2, P3) \
    __coverity___builtin_HEXAGON_V6_vlutb_acc((P0), (P1), (P2), (P3))

// Signature: V32iV32iV32iLLii
int __attribute__ ((vector_size(128)))
__coverity___builtin_HEXAGON_V6_vlutb_acc_128B(
    int __attribute__ ((vector_size(128))) p0,
    int __attribute__ ((vector_size(128))) p1,
    long long p2,
    int p3);
#define __builtin_HEXAGON_V6_vlutb_acc_128B(P0, P1, P2, P3) \
    __coverity___builtin_HEXAGON_V6_vlutb_acc_128B((P0), (P1), (P2), (P3))

// Signature: V32iV32iLLii
int __attribute__ ((vector_size(128)))
__coverity___builtin_HEXAGON_V6_vlutb_dv(
    int __attribute__ ((vector_size(128))) p0,
    long long p1,
    int p2);
#define __builtin_HEXAGON_V6_vlutb_dv(P0, P1, P2) \
    __coverity___builtin_HEXAGON_V6_vlutb_dv((P0), (P1), (P2))

// Signature: V64iV64iLLii
int __attribute__ ((vector_size(256)))
__coverity___builtin_HEXAGON_V6_vlutb_dv_128B(
    int __attribute__ ((vector_size(256))) p0,
    long long p1,
    int p2);
#define __builtin_HEXAGON_V6_vlutb_dv_128B(P0, P1, P2) \
    __coverity___builtin_HEXAGON_V6_vlutb_dv_128B((P0), (P1), (P2))

// Signature: V32iV32iV32iLLii
int __attribute__ ((vector_size(128)))
__coverity___builtin_HEXAGON_V6_vlutb_dv_acc(
    int __attribute__ ((vector_size(128))) p0,
    int __attribute__ ((vector_size(128))) p1,
    long long p2,
    int p3);
#define __builtin_HEXAGON_V6_vlutb_dv_acc(P0, P1, P2, P3) \
    __coverity___builtin_HEXAGON_V6_vlutb_dv_acc((P0), (P1), (P2), (P3))

// Signature: V64iV64iV64iLLii
int __attribute__ ((vector_size(256)))
__coverity___builtin_HEXAGON_V6_vlutb_dv_acc_128B(
    int __attribute__ ((vector_size(256))) p0,
    int __attribute__ ((vector_size(256))) p1,
    long long p2,
    int p3);
#define __builtin_HEXAGON_V6_vlutb_dv_acc_128B(P0, P1, P2, P3) \
    __coverity___builtin_HEXAGON_V6_vlutb_dv_acc_128B((P0), (P1), (P2), (P3))

/* } */

/* These builtins were removed in r312135:
 *   http://llvm.org/viewvc/llvm-project?view=revision&revision=312135
 * { */

// Signature: V8fV4fV8fUc
float __attribute__ ((vector_size(32)))
__coverity___builtin_ia32_broadcastf32x2_256_mask(
    float __attribute__ ((vector_size(16))) p0,
    float __attribute__ ((vector_size(32))) p1,
    unsigned char p2);
#define __builtin_ia32_broadcastf32x2_256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_broadcastf32x2_256_mask((P0), (P1), (P2))

// Signature: V16fV4fV16fUs
float __attribute__ ((vector_size(64)))
__coverity___builtin_ia32_broadcastf32x2_512_mask(
    float __attribute__ ((vector_size(16))) p0,
    float __attribute__ ((vector_size(64))) p1,
    unsigned short p2);
#define __builtin_ia32_broadcastf32x2_512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_broadcastf32x2_512_mask((P0), (P1), (P2))

// Signature: V4iV4iV4iUc
int __attribute__ ((vector_size(16)))
__coverity___builtin_ia32_broadcasti32x2_128_mask(
    int __attribute__ ((vector_size(16))) p0,
    int __attribute__ ((vector_size(16))) p1,
    unsigned char p2);
#define __builtin_ia32_broadcasti32x2_128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_broadcasti32x2_128_mask((P0), (P1), (P2))

// Signature: V8iV4iV8iUc
int __attribute__ ((vector_size(32)))
__coverity___builtin_ia32_broadcasti32x2_256_mask(
    int __attribute__ ((vector_size(16))) p0,
    int __attribute__ ((vector_size(32))) p1,
    unsigned char p2);
#define __builtin_ia32_broadcasti32x2_256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_broadcasti32x2_256_mask((P0), (P1), (P2))

// Signature: V16iV4iV16iUs
int __attribute__ ((vector_size(64)))
__coverity___builtin_ia32_broadcasti32x2_512_mask(
    int __attribute__ ((vector_size(16))) p0,
    int __attribute__ ((vector_size(64))) p1,
    unsigned short p2);
#define __builtin_ia32_broadcasti32x2_512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_broadcasti32x2_512_mask((P0), (P1), (P2))

/* } */

/* These builtins were removed in r317456:
 *   http://llvm.org/viewvc/llvm-project?view=revision&revision=317456
 * { */

// Signature: V2LLiUc
long long __attribute__ ((vector_size(16)))
__coverity___builtin_ia32_broadcastmb128(
    unsigned char p0);
#define __builtin_ia32_broadcastmb128(P0) \
    __coverity___builtin_ia32_broadcastmb128((P0))

// Signature: V4LLiUc
long long __attribute__ ((vector_size(32)))
__coverity___builtin_ia32_broadcastmb256(
    unsigned char p0);
#define __builtin_ia32_broadcastmb256(P0) \
    __coverity___builtin_ia32_broadcastmb256((P0))

// Signature: V8LLiUc
long long __attribute__ ((vector_size(64)))
__coverity___builtin_ia32_broadcastmb512(
    unsigned char p0);
#define __builtin_ia32_broadcastmb512(P0) \
    __coverity___builtin_ia32_broadcastmb512((P0))

// Signature: V4iUs
int __attribute__ ((vector_size(16)))
__coverity___builtin_ia32_broadcastmw128(
    unsigned short p0);
#define __builtin_ia32_broadcastmw128(P0) \
    __coverity___builtin_ia32_broadcastmw128((P0))

// Signature: V8iUs
int __attribute__ ((vector_size(32)))
__coverity___builtin_ia32_broadcastmw256(
    unsigned short p0);
#define __builtin_ia32_broadcastmw256(P0) \
    __coverity___builtin_ia32_broadcastmw256((P0))

// Signature: V16iUs
int __attribute__ ((vector_size(64)))
__coverity___builtin_ia32_broadcastmw512(
    unsigned short p0);
#define __builtin_ia32_broadcastmw512(P0) \
    __coverity___builtin_ia32_broadcastmw512((P0))

/* } */

/* These builtins were removed in r313011:
 *   http://llvm.org/viewvc/llvm-project?view=revision&revision=313011
 * { */

// Signature: V16cV16cV16c
char __attribute__ ((vector_size(16)))
__coverity___builtin_ia32_pavgb128(
    char __attribute__ ((vector_size(16))) p0,
    char __attribute__ ((vector_size(16))) p1);
#define __builtin_ia32_pavgb128(P0, P1) \
    __coverity___builtin_ia32_pavgb128((P0), (P1))

// Signature: V32cV32cV32c
char __attribute__ ((vector_size(32)))
__coverity___builtin_ia32_pavgb256(
    char __attribute__ ((vector_size(32))) p0,
    char __attribute__ ((vector_size(32))) p1);
#define __builtin_ia32_pavgb256(P0, P1) \
    __coverity___builtin_ia32_pavgb256((P0), (P1))

// Signature: V64cV64cV64cV64cULLi
char __attribute__ ((vector_size(64)))
__coverity___builtin_ia32_pavgb512_mask(
    char __attribute__ ((vector_size(64))) p0,
    char __attribute__ ((vector_size(64))) p1,
    char __attribute__ ((vector_size(64))) p2,
    unsigned long long p3);
#define __builtin_ia32_pavgb512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pavgb512_mask((P0), (P1), (P2), (P3))

// Signature: V8sV8sV8s
short __attribute__ ((vector_size(16)))
__coverity___builtin_ia32_pavgw128(
    short __attribute__ ((vector_size(16))) p0,
    short __attribute__ ((vector_size(16))) p1);
#define __builtin_ia32_pavgw128(P0, P1) \
    __coverity___builtin_ia32_pavgw128((P0), (P1))

// Signature: V16sV16sV16s
short __attribute__ ((vector_size(32)))
__coverity___builtin_ia32_pavgw256(
    short __attribute__ ((vector_size(32))) p0,
    short __attribute__ ((vector_size(32))) p1);
#define __builtin_ia32_pavgw256(P0, P1) \
    __coverity___builtin_ia32_pavgw256((P0), (P1))

// Signature: V32sV32sV32sV32sUi
short __attribute__ ((vector_size(64)))
__coverity___builtin_ia32_pavgw512_mask(
    short __attribute__ ((vector_size(64))) p0,
    short __attribute__ ((vector_size(64))) p1,
    short __attribute__ ((vector_size(64))) p2,
    unsigned int p3);
#define __builtin_ia32_pavgw512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pavgw512_mask((P0), (P1), (P2), (P3))

/* } */

/* These builtins were removed in r313624:
 *   http://llvm.org/viewvc/llvm-project?view=revision&revision=313624
 * { */

// Signature: V16ccV16cUs
char __attribute__ ((vector_size(16)))
__coverity___builtin_ia32_pbroadcastb128_gpr_mask(
    char p0,
    char __attribute__ ((vector_size(16))) p1,
    unsigned short p2);
#define __builtin_ia32_pbroadcastb128_gpr_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pbroadcastb128_gpr_mask((P0), (P1), (P2))

// Signature: V32ccV32cUi
char __attribute__ ((vector_size(32)))
__coverity___builtin_ia32_pbroadcastb256_gpr_mask(
    char p0,
    char __attribute__ ((vector_size(32))) p1,
    unsigned int p2);
#define __builtin_ia32_pbroadcastb256_gpr_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pbroadcastb256_gpr_mask((P0), (P1), (P2))

// Signature: V64ccV64cULLi
char __attribute__ ((vector_size(64)))
__coverity___builtin_ia32_pbroadcastb512_gpr_mask(
    char p0,
    char __attribute__ ((vector_size(64))) p1,
    unsigned long long p2);
#define __builtin_ia32_pbroadcastb512_gpr_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pbroadcastb512_gpr_mask((P0), (P1), (P2))

// Signature: V4iiV4iUc
int __attribute__ ((vector_size(16)))
__coverity___builtin_ia32_pbroadcastd128_gpr_mask(
    int p0,
    int __attribute__ ((vector_size(16))) p1,
    unsigned char p2);
#define __builtin_ia32_pbroadcastd128_gpr_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pbroadcastd128_gpr_mask((P0), (P1), (P2))

// Signature: V8iiV8iUc
int __attribute__ ((vector_size(32)))
__coverity___builtin_ia32_pbroadcastd256_gpr_mask(
    int p0,
    int __attribute__ ((vector_size(32))) p1,
    unsigned char p2);
#define __builtin_ia32_pbroadcastd256_gpr_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pbroadcastd256_gpr_mask((P0), (P1), (P2))

// Signature: V16iiV16iUs
int __attribute__ ((vector_size(64)))
__coverity___builtin_ia32_pbroadcastd512_gpr_mask(
    int p0,
    int __attribute__ ((vector_size(64))) p1,
    unsigned short p2);
#define __builtin_ia32_pbroadcastd512_gpr_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pbroadcastd512_gpr_mask((P0), (P1), (P2))

// Signature: V8ssV8sUc
short __attribute__ ((vector_size(16)))
__coverity___builtin_ia32_pbroadcastw128_gpr_mask(
    short p0,
    short __attribute__ ((vector_size(16))) p1,
    unsigned char p2);
#define __builtin_ia32_pbroadcastw128_gpr_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pbroadcastw128_gpr_mask((P0), (P1), (P2))

// Signature: V16shV16sUs
short __attribute__ ((vector_size(32)))
__coverity___builtin_ia32_pbroadcastw256_gpr_mask(
    short p0,
    short __attribute__ ((vector_size(32))) p1,
    unsigned short p2);
#define __builtin_ia32_pbroadcastw256_gpr_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pbroadcastw256_gpr_mask((P0), (P1), (P2))

// Signature: V32shV32sUi
short __attribute__ ((vector_size(64)))
__coverity___builtin_ia32_pbroadcastw512_gpr_mask(
    short p0,
    short __attribute__ ((vector_size(64))) p1,
    unsigned int p2);
#define __builtin_ia32_pbroadcastw512_gpr_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pbroadcastw512_gpr_mask((P0), (P1), (P2))

// Signature: V2LLiULLiV2LLiUc
long long __attribute__ ((vector_size(16)))
__coverity___builtin_ia32_pbroadcastq128_gpr_mask(
    unsigned long long p0,
    long long __attribute__ ((vector_size(16))) p1,
    unsigned char p2);
#define __builtin_ia32_pbroadcastq128_gpr_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pbroadcastq128_gpr_mask((P0), (P1), (P2))

// Signature: V4LLiULLiV4LLiUc
long long __attribute__ ((vector_size(32)))
__coverity___builtin_ia32_pbroadcastq256_gpr_mask(
    unsigned long long p0,
    long long __attribute__ ((vector_size(32))) p1,
    unsigned char p2);
#define __builtin_ia32_pbroadcastq256_gpr_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pbroadcastq256_gpr_mask((P0), (P1), (P2))

// Signature: V8LLiLLiV8LLiUc
long long __attribute__ ((vector_size(64)))
__coverity___builtin_ia32_pbroadcastq512_gpr_mask(
    long long p0,
    long long __attribute__ ((vector_size(64))) p1,
    unsigned char p2);
#define __builtin_ia32_pbroadcastq512_gpr_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pbroadcastq512_gpr_mask((P0), (P1), (P2))

/* } */

/* These builtins were removed in r317506:
 *   http://llvm.org/viewvc/llvm-project?view=revision&revision=317506
 * { */

// Signature: sV16cV16cs
short
__coverity___builtin_ia32_pcmpeqb128_mask(
    char __attribute__ ((vector_size(16))) p0,
    char __attribute__ ((vector_size(16))) p1,
    short p2);
#define __builtin_ia32_pcmpeqb128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pcmpeqb128_mask((P0), (P1), (P2))

// Signature: iV32cV32ci
int
__coverity___builtin_ia32_pcmpeqb256_mask(
    char __attribute__ ((vector_size(32))) p0,
    char __attribute__ ((vector_size(32))) p1,
    int p2);
#define __builtin_ia32_pcmpeqb256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pcmpeqb256_mask((P0), (P1), (P2))

// Signature: LLiV64cV64cLLi
long long
__coverity___builtin_ia32_pcmpeqb512_mask(
    char __attribute__ ((vector_size(64))) p0,
    char __attribute__ ((vector_size(64))) p1,
    long long p2);
#define __builtin_ia32_pcmpeqb512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pcmpeqb512_mask((P0), (P1), (P2))

// Signature: cV4iV4ic
char
__coverity___builtin_ia32_pcmpeqd128_mask(
    int __attribute__ ((vector_size(16))) p0,
    int __attribute__ ((vector_size(16))) p1,
    char p2);
#define __builtin_ia32_pcmpeqd128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pcmpeqd128_mask((P0), (P1), (P2))

// Signature: cV8iV8ic
char
__coverity___builtin_ia32_pcmpeqd256_mask(
    int __attribute__ ((vector_size(32))) p0,
    int __attribute__ ((vector_size(32))) p1,
    char p2);
#define __builtin_ia32_pcmpeqd256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pcmpeqd256_mask((P0), (P1), (P2))

// Signature: sV16iV16is
short
__coverity___builtin_ia32_pcmpeqd512_mask(
    int __attribute__ ((vector_size(64))) p0,
    int __attribute__ ((vector_size(64))) p1,
    short p2);
#define __builtin_ia32_pcmpeqd512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pcmpeqd512_mask((P0), (P1), (P2))

// Signature: cV2LLiV2LLic
char
__coverity___builtin_ia32_pcmpeqq128_mask(
    long long __attribute__ ((vector_size(16))) p0,
    long long __attribute__ ((vector_size(16))) p1,
    char p2);
#define __builtin_ia32_pcmpeqq128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pcmpeqq128_mask((P0), (P1), (P2))

// Signature: cV4LLiV4LLic
char
__coverity___builtin_ia32_pcmpeqq256_mask(
    long long __attribute__ ((vector_size(32))) p0,
    long long __attribute__ ((vector_size(32))) p1,
    char p2);
#define __builtin_ia32_pcmpeqq256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pcmpeqq256_mask((P0), (P1), (P2))

// Signature: cV8LLiV8LLic
char
__coverity___builtin_ia32_pcmpeqq512_mask(
    long long __attribute__ ((vector_size(64))) p0,
    long long __attribute__ ((vector_size(64))) p1,
    char p2);
#define __builtin_ia32_pcmpeqq512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pcmpeqq512_mask((P0), (P1), (P2))

// Signature: cV8sV8sc
char
__coverity___builtin_ia32_pcmpeqw128_mask(
    short __attribute__ ((vector_size(16))) p0,
    short __attribute__ ((vector_size(16))) p1,
    char p2);
#define __builtin_ia32_pcmpeqw128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pcmpeqw128_mask((P0), (P1), (P2))

// Signature: sV16sV16ss
short
__coverity___builtin_ia32_pcmpeqw256_mask(
    short __attribute__ ((vector_size(32))) p0,
    short __attribute__ ((vector_size(32))) p1,
    short p2);
#define __builtin_ia32_pcmpeqw256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pcmpeqw256_mask((P0), (P1), (P2))

// Signature: iV32sV32si
int
__coverity___builtin_ia32_pcmpeqw512_mask(
    short __attribute__ ((vector_size(64))) p0,
    short __attribute__ ((vector_size(64))) p1,
    int p2);
#define __builtin_ia32_pcmpeqw512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pcmpeqw512_mask((P0), (P1), (P2))

// Signature: sV16cV16cs
short
__coverity___builtin_ia32_pcmpgtb128_mask(
    char __attribute__ ((vector_size(16))) p0,
    char __attribute__ ((vector_size(16))) p1,
    short p2);
#define __builtin_ia32_pcmpgtb128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pcmpgtb128_mask((P0), (P1), (P2))

// Signature: iV32cV32ci
int
__coverity___builtin_ia32_pcmpgtb256_mask(
    char __attribute__ ((vector_size(32))) p0,
    char __attribute__ ((vector_size(32))) p1,
    int p2);
#define __builtin_ia32_pcmpgtb256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pcmpgtb256_mask((P0), (P1), (P2))

// Signature: LLiV64cV64cLLi
long long
__coverity___builtin_ia32_pcmpgtb512_mask(
    char __attribute__ ((vector_size(64))) p0,
    char __attribute__ ((vector_size(64))) p1,
    long long p2);
#define __builtin_ia32_pcmpgtb512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pcmpgtb512_mask((P0), (P1), (P2))

// Signature: cV4iV4ic
char
__coverity___builtin_ia32_pcmpgtd128_mask(
    int __attribute__ ((vector_size(16))) p0,
    int __attribute__ ((vector_size(16))) p1,
    char p2);
#define __builtin_ia32_pcmpgtd128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pcmpgtd128_mask((P0), (P1), (P2))

// Signature: cV8iV8ic
char
__coverity___builtin_ia32_pcmpgtd256_mask(
    int __attribute__ ((vector_size(32))) p0,
    int __attribute__ ((vector_size(32))) p1,
    char p2);
#define __builtin_ia32_pcmpgtd256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pcmpgtd256_mask((P0), (P1), (P2))

// Signature: sV16iV16is
short
__coverity___builtin_ia32_pcmpgtd512_mask(
    int __attribute__ ((vector_size(64))) p0,
    int __attribute__ ((vector_size(64))) p1,
    short p2);
#define __builtin_ia32_pcmpgtd512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pcmpgtd512_mask((P0), (P1), (P2))

// Signature: cV2LLiV2LLic
char
__coverity___builtin_ia32_pcmpgtq128_mask(
    long long __attribute__ ((vector_size(16))) p0,
    long long __attribute__ ((vector_size(16))) p1,
    char p2);
#define __builtin_ia32_pcmpgtq128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pcmpgtq128_mask((P0), (P1), (P2))

// Signature: cV4LLiV4LLic
char
__coverity___builtin_ia32_pcmpgtq256_mask(
    long long __attribute__ ((vector_size(32))) p0,
    long long __attribute__ ((vector_size(32))) p1,
    char p2);
#define __builtin_ia32_pcmpgtq256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pcmpgtq256_mask((P0), (P1), (P2))

// Signature: cV8LLiV8LLic
char
__coverity___builtin_ia32_pcmpgtq512_mask(
    long long __attribute__ ((vector_size(64))) p0,
    long long __attribute__ ((vector_size(64))) p1,
    char p2);
#define __builtin_ia32_pcmpgtq512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pcmpgtq512_mask((P0), (P1), (P2))

// Signature: cV8sV8sc
char
__coverity___builtin_ia32_pcmpgtw128_mask(
    short __attribute__ ((vector_size(16))) p0,
    short __attribute__ ((vector_size(16))) p1,
    char p2);
#define __builtin_ia32_pcmpgtw128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pcmpgtw128_mask((P0), (P1), (P2))

// Signature: sV16sV16ss
short
__coverity___builtin_ia32_pcmpgtw256_mask(
    short __attribute__ ((vector_size(32))) p0,
    short __attribute__ ((vector_size(32))) p1,
    short p2);
#define __builtin_ia32_pcmpgtw256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pcmpgtw256_mask((P0), (P1), (P2))

// Signature: iV32sV32si
int
__coverity___builtin_ia32_pcmpgtw512_mask(
    short __attribute__ ((vector_size(64))) p0,
    short __attribute__ ((vector_size(64))) p1,
    int p2);
#define __builtin_ia32_pcmpgtw512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pcmpgtw512_mask((P0), (P1), (P2))

/* } */

/* These builtins were removed in r318035:
 *   http://llvm.org/viewvc/llvm-project?view=revision&revision=318035
 * { */

// Signature: UsV16cV16cUs
unsigned short
__coverity___builtin_ia32_ptestmb128(
    char __attribute__ ((vector_size(16))) p0,
    char __attribute__ ((vector_size(16))) p1,
    unsigned short p2);
#define __builtin_ia32_ptestmb128(P0, P1, P2) \
    __coverity___builtin_ia32_ptestmb128((P0), (P1), (P2))

// Signature: UiV32cV32cUi
unsigned int
__coverity___builtin_ia32_ptestmb256(
    char __attribute__ ((vector_size(32))) p0,
    char __attribute__ ((vector_size(32))) p1,
    unsigned int p2);
#define __builtin_ia32_ptestmb256(P0, P1, P2) \
    __coverity___builtin_ia32_ptestmb256((P0), (P1), (P2))

// Signature: ULLiV64cV64cULLi
unsigned long long
__coverity___builtin_ia32_ptestmb512(
    char __attribute__ ((vector_size(64))) p0,
    char __attribute__ ((vector_size(64))) p1,
    unsigned long long p2);
#define __builtin_ia32_ptestmb512(P0, P1, P2) \
    __coverity___builtin_ia32_ptestmb512((P0), (P1), (P2))

// Signature: UcV4iV4iUc
unsigned char
__coverity___builtin_ia32_ptestmd128(
    int __attribute__ ((vector_size(16))) p0,
    int __attribute__ ((vector_size(16))) p1,
    unsigned char p2);
#define __builtin_ia32_ptestmd128(P0, P1, P2) \
    __coverity___builtin_ia32_ptestmd128((P0), (P1), (P2))

// Signature: UcV8iV8iUc
unsigned char
__coverity___builtin_ia32_ptestmd256(
    int __attribute__ ((vector_size(32))) p0,
    int __attribute__ ((vector_size(32))) p1,
    unsigned char p2);
#define __builtin_ia32_ptestmd256(P0, P1, P2) \
    __coverity___builtin_ia32_ptestmd256((P0), (P1), (P2))

// Signature: UsV16iV16iUs
unsigned short
__coverity___builtin_ia32_ptestmd512(
    int __attribute__ ((vector_size(64))) p0,
    int __attribute__ ((vector_size(64))) p1,
    unsigned short p2);
#define __builtin_ia32_ptestmd512(P0, P1, P2) \
    __coverity___builtin_ia32_ptestmd512((P0), (P1), (P2))

// Signature: UcV2LLiV2LLiUc
unsigned char
__coverity___builtin_ia32_ptestmq128(
    long long __attribute__ ((vector_size(16))) p0,
    long long __attribute__ ((vector_size(16))) p1,
    unsigned char p2);
#define __builtin_ia32_ptestmq128(P0, P1, P2) \
    __coverity___builtin_ia32_ptestmq128((P0), (P1), (P2))

// Signature: UcV4LLiV4LLiUc
unsigned char
__coverity___builtin_ia32_ptestmq256(
    long long __attribute__ ((vector_size(32))) p0,
    long long __attribute__ ((vector_size(32))) p1,
    unsigned char p2);
#define __builtin_ia32_ptestmq256(P0, P1, P2) \
    __coverity___builtin_ia32_ptestmq256((P0), (P1), (P2))

// Signature: UcV8LLiV8LLiUc
unsigned char
__coverity___builtin_ia32_ptestmq512(
    long long __attribute__ ((vector_size(64))) p0,
    long long __attribute__ ((vector_size(64))) p1,
    unsigned char p2);
#define __builtin_ia32_ptestmq512(P0, P1, P2) \
    __coverity___builtin_ia32_ptestmq512((P0), (P1), (P2))

// Signature: UcV8sV8sUc
unsigned char
__coverity___builtin_ia32_ptestmw128(
    short __attribute__ ((vector_size(16))) p0,
    short __attribute__ ((vector_size(16))) p1,
    unsigned char p2);
#define __builtin_ia32_ptestmw128(P0, P1, P2) \
    __coverity___builtin_ia32_ptestmw128((P0), (P1), (P2))

// Signature: UsV16sV16sUs
unsigned short
__coverity___builtin_ia32_ptestmw256(
    short __attribute__ ((vector_size(32))) p0,
    short __attribute__ ((vector_size(32))) p1,
    unsigned short p2);
#define __builtin_ia32_ptestmw256(P0, P1, P2) \
    __coverity___builtin_ia32_ptestmw256((P0), (P1), (P2))

// Signature: UiV32sV32sUi
unsigned int
__coverity___builtin_ia32_ptestmw512(
    short __attribute__ ((vector_size(64))) p0,
    short __attribute__ ((vector_size(64))) p1,
    unsigned int p2);
#define __builtin_ia32_ptestmw512(P0, P1, P2) \
    __coverity___builtin_ia32_ptestmw512((P0), (P1), (P2))

// Signature: UsV16cV16cUs
unsigned short
__coverity___builtin_ia32_ptestnmb128(
    char __attribute__ ((vector_size(16))) p0,
    char __attribute__ ((vector_size(16))) p1,
    unsigned short p2);
#define __builtin_ia32_ptestnmb128(P0, P1, P2) \
    __coverity___builtin_ia32_ptestnmb128((P0), (P1), (P2))

// Signature: UiV32cV32cUi
unsigned int
__coverity___builtin_ia32_ptestnmb256(
    char __attribute__ ((vector_size(32))) p0,
    char __attribute__ ((vector_size(32))) p1,
    unsigned int p2);
#define __builtin_ia32_ptestnmb256(P0, P1, P2) \
    __coverity___builtin_ia32_ptestnmb256((P0), (P1), (P2))

// Signature: ULLiV64cV64cULLi
unsigned long long
__coverity___builtin_ia32_ptestnmb512(
    char __attribute__ ((vector_size(64))) p0,
    char __attribute__ ((vector_size(64))) p1,
    unsigned long long p2);
#define __builtin_ia32_ptestnmb512(P0, P1, P2) \
    __coverity___builtin_ia32_ptestnmb512((P0), (P1), (P2))

// Signature: UcV4iV4iUc
unsigned char
__coverity___builtin_ia32_ptestnmd128(
    int __attribute__ ((vector_size(16))) p0,
    int __attribute__ ((vector_size(16))) p1,
    unsigned char p2);
#define __builtin_ia32_ptestnmd128(P0, P1, P2) \
    __coverity___builtin_ia32_ptestnmd128((P0), (P1), (P2))

// Signature: UcV8iV8iUc
unsigned char
__coverity___builtin_ia32_ptestnmd256(
    int __attribute__ ((vector_size(32))) p0,
    int __attribute__ ((vector_size(32))) p1,
    unsigned char p2);
#define __builtin_ia32_ptestnmd256(P0, P1, P2) \
    __coverity___builtin_ia32_ptestnmd256((P0), (P1), (P2))

// Signature: UsV16iV16iUs
unsigned short
__coverity___builtin_ia32_ptestnmd512(
    int __attribute__ ((vector_size(64))) p0,
    int __attribute__ ((vector_size(64))) p1,
    unsigned short p2);
#define __builtin_ia32_ptestnmd512(P0, P1, P2) \
    __coverity___builtin_ia32_ptestnmd512((P0), (P1), (P2))

// Signature: UcV2LLiV2LLiUc
unsigned char
__coverity___builtin_ia32_ptestnmq128(
    long long __attribute__ ((vector_size(16))) p0,
    long long __attribute__ ((vector_size(16))) p1,
    unsigned char p2);
#define __builtin_ia32_ptestnmq128(P0, P1, P2) \
    __coverity___builtin_ia32_ptestnmq128((P0), (P1), (P2))

// Signature: UcV4LLiV4LLiUc
unsigned char
__coverity___builtin_ia32_ptestnmq256(
    long long __attribute__ ((vector_size(32))) p0,
    long long __attribute__ ((vector_size(32))) p1,
    unsigned char p2);
#define __builtin_ia32_ptestnmq256(P0, P1, P2) \
    __coverity___builtin_ia32_ptestnmq256((P0), (P1), (P2))

// Signature: UcV8LLiV8LLiUc
unsigned char
__coverity___builtin_ia32_ptestnmq512(
    long long __attribute__ ((vector_size(64))) p0,
    long long __attribute__ ((vector_size(64))) p1,
    unsigned char p2);
#define __builtin_ia32_ptestnmq512(P0, P1, P2) \
    __coverity___builtin_ia32_ptestnmq512((P0), (P1), (P2))

// Signature: UcV8sV8sUc
unsigned char
__coverity___builtin_ia32_ptestnmw128(
    short __attribute__ ((vector_size(16))) p0,
    short __attribute__ ((vector_size(16))) p1,
    unsigned char p2);
#define __builtin_ia32_ptestnmw128(P0, P1, P2) \
    __coverity___builtin_ia32_ptestnmw128((P0), (P1), (P2))

// Signature: UsV16sV16sUs
unsigned short
__coverity___builtin_ia32_ptestnmw256(
    short __attribute__ ((vector_size(32))) p0,
    short __attribute__ ((vector_size(32))) p1,
    unsigned short p2);
#define __builtin_ia32_ptestnmw256(P0, P1, P2) \
    __coverity___builtin_ia32_ptestnmw256((P0), (P1), (P2))

// Signature: UiV32sV32sUi
unsigned int
__coverity___builtin_ia32_ptestnmw512(
    short __attribute__ ((vector_size(64))) p0,
    short __attribute__ ((vector_size(64))) p1,
    unsigned int p2);
#define __builtin_ia32_ptestnmw512(P0, P1, P2) \
    __coverity___builtin_ia32_ptestnmw512((P0), (P1), (P2))

/* } */

/* These builtins were removed in r317873:
 *   http://llvm.org/viewvc/llvm-project?view=revision&revision=317873
 * { */

// Signature: V2dV2dV2dV2d
double __attribute__ ((vector_size(16)))
__coverity___builtin_ia32_vfmsubaddpd(
    double __attribute__ ((vector_size(16))) p0,
    double __attribute__ ((vector_size(16))) p1,
    double __attribute__ ((vector_size(16))) p2);
#define __builtin_ia32_vfmsubaddpd(P0, P1, P2) \
    __coverity___builtin_ia32_vfmsubaddpd((P0), (P1), (P2))

// Signature: V4dV4dV4dV4d
double __attribute__ ((vector_size(32)))
__coverity___builtin_ia32_vfmsubaddpd256(
    double __attribute__ ((vector_size(32))) p0,
    double __attribute__ ((vector_size(32))) p1,
    double __attribute__ ((vector_size(32))) p2);
#define __builtin_ia32_vfmsubaddpd256(P0, P1, P2) \
    __coverity___builtin_ia32_vfmsubaddpd256((P0), (P1), (P2))

// Signature: V4fV4fV4fV4f
float __attribute__ ((vector_size(16)))
__coverity___builtin_ia32_vfmsubaddps(
    float __attribute__ ((vector_size(16))) p0,
    float __attribute__ ((vector_size(16))) p1,
    float __attribute__ ((vector_size(16))) p2);
#define __builtin_ia32_vfmsubaddps(P0, P1, P2) \
    __coverity___builtin_ia32_vfmsubaddps((P0), (P1), (P2))

// Signature: V8fV8fV8fV8f
float __attribute__ ((vector_size(32)))
__coverity___builtin_ia32_vfmsubaddps256(
    float __attribute__ ((vector_size(32))) p0,
    float __attribute__ ((vector_size(32))) p1,
    float __attribute__ ((vector_size(32))) p2);
#define __builtin_ia32_vfmsubaddps256(P0, P1, P2) \
    __coverity___builtin_ia32_vfmsubaddps256((P0), (P1), (P2))

// Signature: V2dV2dV2dV2d
double __attribute__ ((vector_size(16)))
__coverity___builtin_ia32_vfmsubpd(
    double __attribute__ ((vector_size(16))) p0,
    double __attribute__ ((vector_size(16))) p1,
    double __attribute__ ((vector_size(16))) p2);
#define __builtin_ia32_vfmsubpd(P0, P1, P2) \
    __coverity___builtin_ia32_vfmsubpd((P0), (P1), (P2))

// Signature: V4dV4dV4dV4d
double __attribute__ ((vector_size(32)))
__coverity___builtin_ia32_vfmsubpd256(
    double __attribute__ ((vector_size(32))) p0,
    double __attribute__ ((vector_size(32))) p1,
    double __attribute__ ((vector_size(32))) p2);
#define __builtin_ia32_vfmsubpd256(P0, P1, P2) \
    __coverity___builtin_ia32_vfmsubpd256((P0), (P1), (P2))

// Signature: V4fV4fV4fV4f
float __attribute__ ((vector_size(16)))
__coverity___builtin_ia32_vfmsubps(
    float __attribute__ ((vector_size(16))) p0,
    float __attribute__ ((vector_size(16))) p1,
    float __attribute__ ((vector_size(16))) p2);
#define __builtin_ia32_vfmsubps(P0, P1, P2) \
    __coverity___builtin_ia32_vfmsubps((P0), (P1), (P2))

// Signature: V8fV8fV8fV8f
float __attribute__ ((vector_size(32)))
__coverity___builtin_ia32_vfmsubps256(
    float __attribute__ ((vector_size(32))) p0,
    float __attribute__ ((vector_size(32))) p1,
    float __attribute__ ((vector_size(32))) p2);
#define __builtin_ia32_vfmsubps256(P0, P1, P2) \
    __coverity___builtin_ia32_vfmsubps256((P0), (P1), (P2))

// Signature: V2dV2dV2dV2d
double __attribute__ ((vector_size(16)))
__coverity___builtin_ia32_vfnmaddpd(
    double __attribute__ ((vector_size(16))) p0,
    double __attribute__ ((vector_size(16))) p1,
    double __attribute__ ((vector_size(16))) p2);
#define __builtin_ia32_vfnmaddpd(P0, P1, P2) \
    __coverity___builtin_ia32_vfnmaddpd((P0), (P1), (P2))

// Signature: V4fV4fV4fV4f
float __attribute__ ((vector_size(16)))
__coverity___builtin_ia32_vfnmaddps(
    float __attribute__ ((vector_size(16))) p0,
    float __attribute__ ((vector_size(16))) p1,
    float __attribute__ ((vector_size(16))) p2);
#define __builtin_ia32_vfnmaddps(P0, P1, P2) \
    __coverity___builtin_ia32_vfnmaddps((P0), (P1), (P2))

// Signature: V2dV2dV2dV2d
double __attribute__ ((vector_size(16)))
__coverity___builtin_ia32_vfnmsubpd(
    double __attribute__ ((vector_size(16))) p0,
    double __attribute__ ((vector_size(16))) p1,
    double __attribute__ ((vector_size(16))) p2);
#define __builtin_ia32_vfnmsubpd(P0, P1, P2) \
    __coverity___builtin_ia32_vfnmsubpd((P0), (P1), (P2))

// Signature: V4dV4dV4dV4d
double __attribute__ ((vector_size(32)))
__coverity___builtin_ia32_vfnmsubpd256(
    double __attribute__ ((vector_size(32))) p0,
    double __attribute__ ((vector_size(32))) p1,
    double __attribute__ ((vector_size(32))) p2);
#define __builtin_ia32_vfnmsubpd256(P0, P1, P2) \
    __coverity___builtin_ia32_vfnmsubpd256((P0), (P1), (P2))

// Signature: V4fV4fV4fV4f
float __attribute__ ((vector_size(16)))
__coverity___builtin_ia32_vfnmsubps(
    float __attribute__ ((vector_size(16))) p0,
    float __attribute__ ((vector_size(16))) p1,
    float __attribute__ ((vector_size(16))) p2);
#define __builtin_ia32_vfnmsubps(P0, P1, P2) \
    __coverity___builtin_ia32_vfnmsubps((P0), (P1), (P2))

// Signature: V8fV8fV8fV8f
float __attribute__ ((vector_size(32)))
__coverity___builtin_ia32_vfnmsubps256(
    float __attribute__ ((vector_size(32))) p0,
    float __attribute__ ((vector_size(32))) p1,
    float __attribute__ ((vector_size(32))) p2);
#define __builtin_ia32_vfnmsubps256(P0, P1, P2) \
    __coverity___builtin_ia32_vfnmsubps256((P0), (P1), (P2))

/* } */

/* These builtins were removed in r317766:
 *   http://llvm.org/viewvc/llvm-project?view=revision&revision=317766
 * { */

// Signature: V4fV4fV4fV4f
float __attribute__ ((vector_size(16)))
__coverity___builtin_ia32_vfnmaddss(
    float __attribute__ ((vector_size(16))) p0,
    float __attribute__ ((vector_size(16))) p1,
    float __attribute__ ((vector_size(16))) p2);
#define __builtin_ia32_vfnmaddss(P0, P1, P2) \
    __coverity___builtin_ia32_vfnmaddss((P0), (P1), (P2))

// Signature: V2dV2dV2dV2d
double __attribute__ ((vector_size(16)))
__coverity___builtin_ia32_vfnmaddsd(
    double __attribute__ ((vector_size(16))) p0,
    double __attribute__ ((vector_size(16))) p1,
    double __attribute__ ((vector_size(16))) p2);
#define __builtin_ia32_vfnmaddsd(P0, P1, P2) \
    __coverity___builtin_ia32_vfnmaddsd((P0), (P1), (P2))

// Signature: V2dV2dV2dV2d
double __attribute__ ((vector_size(16)))
__coverity___builtin_ia32_vfnmsubsd(
    double __attribute__ ((vector_size(16))) p0,
    double __attribute__ ((vector_size(16))) p1,
    double __attribute__ ((vector_size(16))) p2);
#define __builtin_ia32_vfnmsubsd(P0, P1, P2) \
    __coverity___builtin_ia32_vfnmsubsd((P0), (P1), (P2))

// Signature: V4fV4fV4fV4f
float __attribute__ ((vector_size(16)))
__coverity___builtin_ia32_vfnmsubss(
    float __attribute__ ((vector_size(16))) p0,
    float __attribute__ ((vector_size(16))) p1,
    float __attribute__ ((vector_size(16))) p2);
#define __builtin_ia32_vfnmsubss(P0, P1, P2) \
    __coverity___builtin_ia32_vfnmsubss((P0), (P1), (P2))

// Signature: V2dV2dV2dV2d
double __attribute__ ((vector_size(16)))
__coverity___builtin_ia32_vfmsubsd(
    double __attribute__ ((vector_size(16))) p0,
    double __attribute__ ((vector_size(16))) p1,
    double __attribute__ ((vector_size(16))) p2);
#define __builtin_ia32_vfmsubsd(P0, P1, P2) \
    __coverity___builtin_ia32_vfmsubsd((P0), (P1), (P2))

// Signature: V4fV4fV4fV4f
float __attribute__ ((vector_size(16)))
__coverity___builtin_ia32_vfmsubss(
    float __attribute__ ((vector_size(16))) p0,
    float __attribute__ ((vector_size(16))) p1,
    float __attribute__ ((vector_size(16))) p2);
#define __builtin_ia32_vfmsubss(P0, P1, P2) \
    __coverity___builtin_ia32_vfmsubss((P0), (P1), (P2))

/* } */

/* } Removed in Clang 6.0 */

#endif /* } clang < 6.0 */

// XCode 10 - No changes from Clang 6


/*************************************
 ************ Clang 7.0 **************
 *************************************/

#if (__cov_clang_version_lt(7, 0)) /* { */

/* Signatures changed in Clang 7.0 { */

extern unsigned char*
__coverity___builtin_amdgcn_dispatch_ptr();
#define __builtin_amdgcn_dispatch_ptr() \
    __coverity___builtin_amdgcn_dispatch_ptr()

extern unsigned char*
__coverity___builtin_amdgcn_implicitarg_ptr();
#define __builtin_amdgcn_implicitarg_ptr() \
    __coverity___builtin_amdgcn_implicitarg_ptr()

extern unsigned char*
__coverity___builtin_amdgcn_kernarg_segment_ptr();
#define __builtin_amdgcn_kernarg_segment_ptr() \
    __coverity___builtin_amdgcn_kernarg_segment_ptr()

extern char*
__coverity___builtin_brev_ldb(
    char* __a,
    char* __b,
    int __c);
#define __builtin_brev_ldb(P0, P1, P2) \
    __coverity___builtin_brev_ldb((P0), (P1), (P2))

extern long long*
__coverity___builtin_brev_ldd(
    long long* __a,
    long long* __b,
    int __c);
#define __builtin_brev_ldd(P0, P1, P2) \
    __coverity___builtin_brev_ldd((P0), (P1), (P2))

extern short*
__coverity___builtin_brev_ldh(
    short* __a,
    short* __b,
    int __c);
#define __builtin_brev_ldh(P0, P1, P2) \
    __coverity___builtin_brev_ldh((P0), (P1), (P2))

extern unsigned char*
__coverity___builtin_brev_ldub(
    unsigned char* __a,
    unsigned char* __b,
    int __c);
#define __builtin_brev_ldub(P0, P1, P2) \
    __coverity___builtin_brev_ldub((P0), (P1), (P2))

extern unsigned short*
__coverity___builtin_brev_lduh(
    unsigned short* __a,
    unsigned short* __b,
    int __c);
#define __builtin_brev_lduh(P0, P1, P2) \
    __coverity___builtin_brev_lduh((P0), (P1), (P2))

extern int*
__coverity___builtin_brev_ldw(
    int* __a,
    int* __b,
    int __c);
#define __builtin_brev_ldw(P0, P1, P2) \
    __coverity___builtin_brev_ldw((P0), (P1), (P2))

extern char*
__coverity___builtin_brev_stb(
    char* __a,
    int __b,
    int __c);
#define __builtin_brev_stb(P0, P1, P2) \
    __coverity___builtin_brev_stb((P0), (P1), (P2))

extern long long*
__coverity___builtin_brev_std(
    long long* __a,
    long long __b,
    int __c);
#define __builtin_brev_std(P0, P1, P2) \
    __coverity___builtin_brev_std((P0), (P1), (P2))

extern short*
__coverity___builtin_brev_sth(
    short* __a,
    int __b,
    int __c);
#define __builtin_brev_sth(P0, P1, P2) \
    __coverity___builtin_brev_sth((P0), (P1), (P2))

extern short*
__coverity___builtin_brev_sthhi(
    short* __a,
    int __b,
    int __c);
#define __builtin_brev_sthhi(P0, P1, P2) \
    __coverity___builtin_brev_sthhi((P0), (P1), (P2))

extern int*
__coverity___builtin_brev_stw(
    int* __a,
    int __b,
    int __c);
#define __builtin_brev_stw(P0, P1, P2) \
    __coverity___builtin_brev_stw((P0), (P1), (P2))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_expandloaddf128_mask(
    double __attribute__((vector_size(16)))* __a,
    double __attribute__((vector_size(16))) __b,
    unsigned char __c);
#define __builtin_ia32_expandloaddf128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_expandloaddf128_mask((P0), (P1), (P2))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_expandloaddf256_mask(
    double __attribute__((vector_size(32)))* __a,
    double __attribute__((vector_size(32))) __b,
    unsigned char __c);
#define __builtin_ia32_expandloaddf256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_expandloaddf256_mask((P0), (P1), (P2))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_expandloaddi128_mask(
    long long __attribute__((vector_size(16)))* __a,
    long long __attribute__((vector_size(16))) __b,
    unsigned char __c);
#define __builtin_ia32_expandloaddi128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_expandloaddi128_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_expandloaddi256_mask(
    long long __attribute__((vector_size(32)))* __a,
    long long __attribute__((vector_size(32))) __b,
    unsigned char __c);
#define __builtin_ia32_expandloaddi256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_expandloaddi256_mask((P0), (P1), (P2))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_expandloadsf128_mask(
    float __attribute__((vector_size(16)))* __a,
    float __attribute__((vector_size(16))) __b,
    unsigned char __c);
#define __builtin_ia32_expandloadsf128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_expandloadsf128_mask((P0), (P1), (P2))

extern float __attribute__((vector_size(32)))
__coverity___builtin_ia32_expandloadsf256_mask(
    float __attribute__((vector_size(32)))* __a,
    float __attribute__((vector_size(32))) __b,
    unsigned char __c);
#define __builtin_ia32_expandloadsf256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_expandloadsf256_mask((P0), (P1), (P2))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_expandloadsi128_mask(
    int __attribute__((vector_size(16)))* __a,
    int __attribute__((vector_size(16))) __b,
    unsigned char __c);
#define __builtin_ia32_expandloadsi128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_expandloadsi128_mask((P0), (P1), (P2))

extern int __attribute__((vector_size(32)))
__coverity___builtin_ia32_expandloadsi256_mask(
    int __attribute__((vector_size(32)))* __a,
    int __attribute__((vector_size(32))) __b,
    unsigned char __c);
#define __builtin_ia32_expandloadsi256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_expandloadsi256_mask((P0), (P1), (P2))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_getmantpd128_mask(
    double __attribute__((vector_size(16))) __a,
    int __b,
    double __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_getmantpd128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_getmantpd128_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_getmantpd256_mask(
    double __attribute__((vector_size(32))) __a,
    int __b,
    double __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_getmantpd256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_getmantpd256_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(64)))
__coverity___builtin_ia32_getmantpd512_mask(
    double __attribute__((vector_size(64))) __a,
    int __b,
    double __attribute__((vector_size(64))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_getmantpd512_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_getmantpd512_mask((P0), (P1), (P2), (P3), (P4))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_getmantps128_mask(
    float __attribute__((vector_size(16))) __a,
    int __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_getmantps128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_getmantps128_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(32)))
__coverity___builtin_ia32_getmantps256_mask(
    float __attribute__((vector_size(32))) __a,
    int __b,
    float __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_getmantps256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_getmantps256_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(64)))
__coverity___builtin_ia32_getmantps512_mask(
    float __attribute__((vector_size(64))) __a,
    int __b,
    float __attribute__((vector_size(64))) __c,
    unsigned short __d,
    const int __e);
#define __builtin_ia32_getmantps512_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_getmantps512_mask((P0), (P1), (P2), (P3), (P4))

extern double __attribute__((vector_size(64)))
__coverity___builtin_ia32_loadsd128_mask(
    double __attribute__((vector_size(64)))* __a,
    double __attribute__((vector_size(64))) __b,
    unsigned char __c);
#define __builtin_ia32_loadsd128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_loadsd128_mask((P0), (P1), (P2))

extern float __attribute__((vector_size(64)))
__coverity___builtin_ia32_loadss128_mask(
    float __attribute__((vector_size(64)))* __a,
    float __attribute__((vector_size(64))) __b,
    unsigned short __c);
#define __builtin_ia32_loadss128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_loadss128_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_permti256(
    long long __attribute__((vector_size(32))) __a,
    long long __attribute__((vector_size(32))) __b,
    const char __c);
#define __builtin_ia32_permti256(P0, P1, P2) \
    __coverity___builtin_ia32_permti256((P0), (P1), (P2))

extern void
__coverity___builtin_ia32_storesd128_mask(
    double __attribute__((vector_size(64)))* __a,
    double __attribute__((vector_size(64))) __b,
    unsigned char __c);
#define __builtin_ia32_storesd128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_storesd128_mask((P0), (P1), (P2))

extern void
__coverity___builtin_ia32_storess128_mask(
    float __attribute__((vector_size(64)))* __a,
    float __attribute__((vector_size(64))) __b,
    unsigned short __c);
#define __builtin_ia32_storess128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_storess128_mask((P0), (P1), (P2))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_vperm2f128_pd256(
    double __attribute__((vector_size(32))) __a,
    double __attribute__((vector_size(32))) __b,
    const char __c);
#define __builtin_ia32_vperm2f128_pd256(P0, P1, P2) \
    __coverity___builtin_ia32_vperm2f128_pd256((P0), (P1), (P2))

extern float __attribute__((vector_size(32)))
__coverity___builtin_ia32_vperm2f128_ps256(
    float __attribute__((vector_size(32))) __a,
    float __attribute__((vector_size(32))) __b,
    const char __c);
#define __builtin_ia32_vperm2f128_ps256(P0, P1, P2) \
    __coverity___builtin_ia32_vperm2f128_ps256((P0), (P1), (P2))

// Modified in Clang 3. Modified again in Clang 7
// Extra check to make sure we use the right version
#if (__cov_clang_version_gt(3,0))

extern int __attribute__((vector_size(32)))
__coverity___builtin_ia32_vperm2f128_si256(
    int __attribute__((vector_size(32))) __a,
    int __attribute__((vector_size(32))) __b,
    const char __c);
#define __builtin_ia32_vperm2f128_si256(P0, P1, P2) \
    __coverity___builtin_ia32_vperm2f128_si256((P0), (P1), (P2))
#endif

/* } Changed in Clang 7.0 */

/* Removed in Clang 7.0 { */
extern double __attribute__((vector_size(64)))
__coverity___builtin_ia32_addpd512_mask(
    double __attribute__((vector_size(64))) __a,
    double __attribute__((vector_size(64))) __b,
    double __attribute__((vector_size(64))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_addpd512_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_addpd512_mask((P0), (P1), (P2), (P3), (P4))

extern float __attribute__((vector_size(64)))
__coverity___builtin_ia32_addps512_mask(
    float __attribute__((vector_size(64))) __a,
    float __attribute__((vector_size(64))) __b,
    float __attribute__((vector_size(64))) __c,
    unsigned short __d,
    const int __e);
#define __builtin_ia32_addps512_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_addps512_mask((P0), (P1), (P2), (P3), (P4))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_cvtdq2ps(
    int __attribute__((vector_size(16))) __a);
#define __builtin_ia32_cvtdq2ps(P0) \
    __coverity___builtin_ia32_cvtdq2ps((P0))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_cvtdq2ps128_mask(
    int __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    unsigned char __c);
#define __builtin_ia32_cvtdq2ps128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_cvtdq2ps128_mask((P0), (P1), (P2))

extern float __attribute__((vector_size(32)))
__coverity___builtin_ia32_cvtdq2ps256(
    int __attribute__((vector_size(32))) __a);
#define __builtin_ia32_cvtdq2ps256(P0) \
    __coverity___builtin_ia32_cvtdq2ps256((P0))

extern float __attribute__((vector_size(32)))
__coverity___builtin_ia32_cvtdq2ps256_mask(
    int __attribute__((vector_size(32))) __a,
    float __attribute__((vector_size(32))) __b,
    unsigned char __c);
#define __builtin_ia32_cvtdq2ps256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_cvtdq2ps256_mask((P0), (P1), (P2))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_cvtpd2dq256_mask(
    double __attribute__((vector_size(32))) __a,
    int __attribute__((vector_size(16))) __b,
    unsigned char __c);
#define __builtin_ia32_cvtpd2dq256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_cvtpd2dq256_mask((P0), (P1), (P2))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_cvtpd2ps256_mask(
    double __attribute__((vector_size(32))) __a,
    float __attribute__((vector_size(16))) __b,
    unsigned char __c);
#define __builtin_ia32_cvtpd2ps256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_cvtpd2ps256_mask((P0), (P1), (P2))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_cvtps2dq128_mask(
    float __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    unsigned char __c);
#define __builtin_ia32_cvtps2dq128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_cvtps2dq128_mask((P0), (P1), (P2))

extern int __attribute__((vector_size(32)))
__coverity___builtin_ia32_cvtps2dq256_mask(
    float __attribute__((vector_size(32))) __a,
    int __attribute__((vector_size(32))) __b,
    unsigned char __c);
#define __builtin_ia32_cvtps2dq256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_cvtps2dq256_mask((P0), (P1), (P2))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_cvtps2pd128_mask(
    float __attribute__((vector_size(16))) __a,
    double __attribute__((vector_size(16))) __b,
    unsigned char __c);
#define __builtin_ia32_cvtps2pd128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_cvtps2pd128_mask((P0), (P1), (P2))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_cvtps2pd256_mask(
    float __attribute__((vector_size(16))) __a,
    double __attribute__((vector_size(32))) __b,
    unsigned char __c);
#define __builtin_ia32_cvtps2pd256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_cvtps2pd256_mask((P0), (P1), (P2))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_cvtqq2pd128_mask(
    long long __attribute__((vector_size(16))) __a,
    double __attribute__((vector_size(16))) __b,
    unsigned char __c);
#define __builtin_ia32_cvtqq2pd128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_cvtqq2pd128_mask((P0), (P1), (P2))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_cvtqq2pd256_mask(
    long long __attribute__((vector_size(32))) __a,
    double __attribute__((vector_size(32))) __b,
    unsigned char __c);
#define __builtin_ia32_cvtqq2pd256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_cvtqq2pd256_mask((P0), (P1), (P2))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_cvttpd2dq256_mask(
    double __attribute__((vector_size(32))) __a,
    int __attribute__((vector_size(16))) __b,
    unsigned char __c);
#define __builtin_ia32_cvttpd2dq256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_cvttpd2dq256_mask((P0), (P1), (P2))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_cvttps2dq128_mask(
    float __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    unsigned char __c);
#define __builtin_ia32_cvttps2dq128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_cvttps2dq128_mask((P0), (P1), (P2))

extern int __attribute__((vector_size(32)))
__coverity___builtin_ia32_cvttps2dq256_mask(
    float __attribute__((vector_size(32))) __a,
    int __attribute__((vector_size(32))) __b,
    unsigned char __c);
#define __builtin_ia32_cvttps2dq256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_cvttps2dq256_mask((P0), (P1), (P2))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_cvtudq2ps128_mask(
    int __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    unsigned char __c);
#define __builtin_ia32_cvtudq2ps128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_cvtudq2ps128_mask((P0), (P1), (P2))

extern float __attribute__((vector_size(32)))
__coverity___builtin_ia32_cvtudq2ps256_mask(
    int __attribute__((vector_size(32))) __a,
    float __attribute__((vector_size(32))) __b,
    unsigned char __c);
#define __builtin_ia32_cvtudq2ps256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_cvtudq2ps256_mask((P0), (P1), (P2))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_cvtuqq2pd128_mask(
    long long __attribute__((vector_size(16))) __a,
    double __attribute__((vector_size(16))) __b,
    unsigned char __c);
#define __builtin_ia32_cvtuqq2pd128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_cvtuqq2pd128_mask((P0), (P1), (P2))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_cvtuqq2pd256_mask(
    long long __attribute__((vector_size(32))) __a,
    double __attribute__((vector_size(32))) __b,
    unsigned char __c);
#define __builtin_ia32_cvtuqq2pd256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_cvtuqq2pd256_mask((P0), (P1), (P2))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_cvtusi2sd32(
    double __attribute__((vector_size(16))) __a,
    unsigned int __b);
#define __builtin_ia32_cvtusi2sd32(P0, P1) \
    __coverity___builtin_ia32_cvtusi2sd32((P0), (P1))

extern short __attribute__((vector_size(16)))
__coverity___builtin_ia32_dbpsadbw128_mask(
    char __attribute__((vector_size(16))) __a,
    char __attribute__((vector_size(16))) __b,
    const int __c,
    short __attribute__((vector_size(16))) __d,
    unsigned char __e);
#define __builtin_ia32_dbpsadbw128_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_dbpsadbw128_mask((P0), (P1), (P2), (P3), (P4))

extern short __attribute__((vector_size(32)))
__coverity___builtin_ia32_dbpsadbw256_mask(
    char __attribute__((vector_size(32))) __a,
    char __attribute__((vector_size(32))) __b,
    const int __c,
    short __attribute__((vector_size(32))) __d,
    unsigned short __e);
#define __builtin_ia32_dbpsadbw256_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_dbpsadbw256_mask((P0), (P1), (P2), (P3), (P4))

extern short __attribute__((vector_size(64)))
__coverity___builtin_ia32_dbpsadbw512_mask(
    char __attribute__((vector_size(64))) __a,
    char __attribute__((vector_size(64))) __b,
    const int __c,
    short __attribute__((vector_size(64))) __d,
    unsigned int __e);
#define __builtin_ia32_dbpsadbw512_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_dbpsadbw512_mask((P0), (P1), (P2), (P3), (P4))

extern double __attribute__((vector_size(64)))
__coverity___builtin_ia32_divpd512_mask(
    double __attribute__((vector_size(64))) __a,
    double __attribute__((vector_size(64))) __b,
    double __attribute__((vector_size(64))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_divpd512_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_divpd512_mask((P0), (P1), (P2), (P3), (P4))

extern float __attribute__((vector_size(64)))
__coverity___builtin_ia32_divps512_mask(
    float __attribute__((vector_size(64))) __a,
    float __attribute__((vector_size(64))) __b,
    float __attribute__((vector_size(64))) __c,
    unsigned short __d,
    const int __e);
#define __builtin_ia32_divps512_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_divps512_mask((P0), (P1), (P2), (P3), (P4))

// Modified in 3.7 and XCode 7. Removed in Clang 7
// Extra check to make sure we use the right version
#if ( __cov_clang_version_ge(3, 7) || __cov_xcode_version_ge(7, 0))
extern double __attribute__((vector_size(64)))
__coverity___builtin_ia32_maxpd512_mask(
    double __attribute__((vector_size(64))) __a,
    double __attribute__((vector_size(64))) __b,
    double __attribute__((vector_size(64))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_maxpd512_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_maxpd512_mask((P0), (P1), (P2), (P3), (P4))

extern float __attribute__((vector_size(64)))
__coverity___builtin_ia32_maxps512_mask(
    float __attribute__((vector_size(64))) __a,
    float __attribute__((vector_size(64))) __b,
    float __attribute__((vector_size(64))) __c,
    unsigned short __d,
    const int __e);
#define __builtin_ia32_maxps512_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_maxps512_mask((P0), (P1), (P2), (P3), (P4))

extern double __attribute__((vector_size(64)))
__coverity___builtin_ia32_minpd512_mask(
    double __attribute__((vector_size(64))) __a,
    double __attribute__((vector_size(64))) __b,
    double __attribute__((vector_size(64))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_minpd512_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_minpd512_mask((P0), (P1), (P2), (P3), (P4))

extern float __attribute__((vector_size(64)))
__coverity___builtin_ia32_minps512_mask(
    float __attribute__((vector_size(64))) __a,
    float __attribute__((vector_size(64))) __b,
    float __attribute__((vector_size(64))) __c,
    unsigned short __d,
    const int __e);
#define __builtin_ia32_minps512_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_minps512_mask((P0), (P1), (P2), (P3), (P4))
#endif

extern double __attribute__((vector_size(64)))
__coverity___builtin_ia32_mulpd512_mask(
    double __attribute__((vector_size(64))) __a,
    double __attribute__((vector_size(64))) __b,
    double __attribute__((vector_size(64))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_mulpd512_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_mulpd512_mask((P0), (P1), (P2), (P3), (P4))

extern float __attribute__((vector_size(64)))
__coverity___builtin_ia32_mulps512_mask(
    float __attribute__((vector_size(64))) __a,
    float __attribute__((vector_size(64))) __b,
    float __attribute__((vector_size(64))) __c,
    unsigned short __d,
    const int __e);
#define __builtin_ia32_mulps512_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_mulps512_mask((P0), (P1), (P2), (P3), (P4))

extern char __attribute__((vector_size(64)))
__coverity___builtin_ia32_pabsb512_mask(
    char __attribute__((vector_size(64))) __a,
    char __attribute__((vector_size(64))) __b,
    unsigned long long __c);
#define __builtin_ia32_pabsb512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pabsb512_mask((P0), (P1), (P2))

extern int __attribute__((vector_size(64)))
__coverity___builtin_ia32_pabsd512_mask(
    int __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    unsigned short __c);
#define __builtin_ia32_pabsd512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pabsd512_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pabsq128_mask(
    long long __attribute__((vector_size(16))) __a,
    long long __attribute__((vector_size(16))) __b,
    unsigned char __c);
#define __builtin_ia32_pabsq128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pabsq128_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pabsq256_mask(
    long long __attribute__((vector_size(32))) __a,
    long long __attribute__((vector_size(32))) __b,
    unsigned char __c);
#define __builtin_ia32_pabsq256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pabsq256_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_pabsq512_mask(
    long long __attribute__((vector_size(64))) __a,
    long long __attribute__((vector_size(64))) __b,
    unsigned char __c);
#define __builtin_ia32_pabsq512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pabsq512_mask((P0), (P1), (P2))

extern short __attribute__((vector_size(64)))
__coverity___builtin_ia32_pabsw512_mask(
    short __attribute__((vector_size(64))) __a,
    short __attribute__((vector_size(64))) __b,
    unsigned int __c);
#define __builtin_ia32_pabsw512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pabsw512_mask((P0), (P1), (P2))

extern char __attribute__((vector_size(64)))
__coverity___builtin_ia32_palignr512_mask(
    char __attribute__((vector_size(64))) __a,
    char __attribute__((vector_size(64))) __b,
    const int __c,
    char __attribute__((vector_size(64))) __d,
    unsigned long long __e);
#define __builtin_ia32_palignr512_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_palignr512_mask((P0), (P1), (P2), (P3), (P4))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_permvardf256_mask(
    double __attribute__((vector_size(32))) __a,
    long long __attribute__((vector_size(32))) __b,
    double __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_permvardf256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_permvardf256_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(64)))
__coverity___builtin_ia32_permvardf512_mask(
    double __attribute__((vector_size(64))) __a,
    long long __attribute__((vector_size(64))) __b,
    double __attribute__((vector_size(64))) __c,
    unsigned char __d);
#define __builtin_ia32_permvardf512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_permvardf512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_permvardi256_mask(
    long long __attribute__((vector_size(32))) __a,
    long long __attribute__((vector_size(32))) __b,
    long long __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_permvardi256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_permvardi256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_permvardi512_mask(
    long long __attribute__((vector_size(64))) __a,
    long long __attribute__((vector_size(64))) __b,
    long long __attribute__((vector_size(64))) __c,
    unsigned char __d);
#define __builtin_ia32_permvardi512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_permvardi512_mask((P0), (P1), (P2), (P3))

extern short __attribute__((vector_size(16)))
__coverity___builtin_ia32_permvarhi128_mask(
    short __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b,
    short __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_permvarhi128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_permvarhi128_mask((P0), (P1), (P2), (P3))

extern short __attribute__((vector_size(32)))
__coverity___builtin_ia32_permvarhi256_mask(
    short __attribute__((vector_size(32))) __a,
    short __attribute__((vector_size(32))) __b,
    short __attribute__((vector_size(32))) __c,
    unsigned short __d);
#define __builtin_ia32_permvarhi256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_permvarhi256_mask((P0), (P1), (P2), (P3))

extern short __attribute__((vector_size(64)))
__coverity___builtin_ia32_permvarhi512_mask(
    short __attribute__((vector_size(64))) __a,
    short __attribute__((vector_size(64))) __b,
    short __attribute__((vector_size(64))) __c,
    unsigned int __d);
#define __builtin_ia32_permvarhi512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_permvarhi512_mask((P0), (P1), (P2), (P3))

extern char __attribute__((vector_size(16)))
__coverity___builtin_ia32_permvarqi128_mask(
    char __attribute__((vector_size(16))) __a,
    char __attribute__((vector_size(16))) __b,
    char __attribute__((vector_size(16))) __c,
    unsigned short __d);
#define __builtin_ia32_permvarqi128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_permvarqi128_mask((P0), (P1), (P2), (P3))

extern char __attribute__((vector_size(32)))
__coverity___builtin_ia32_permvarqi256_mask(
    char __attribute__((vector_size(32))) __a,
    char __attribute__((vector_size(32))) __b,
    char __attribute__((vector_size(32))) __c,
    unsigned int __d);
#define __builtin_ia32_permvarqi256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_permvarqi256_mask((P0), (P1), (P2), (P3))

extern char __attribute__((vector_size(64)))
__coverity___builtin_ia32_permvarqi512_mask(
    char __attribute__((vector_size(64))) __a,
    char __attribute__((vector_size(64))) __b,
    char __attribute__((vector_size(64))) __c,
    unsigned long long __d);
#define __builtin_ia32_permvarqi512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_permvarqi512_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(32)))
__coverity___builtin_ia32_permvarsf256_mask(
    float __attribute__((vector_size(32))) __a,
    int __attribute__((vector_size(32))) __b,
    float __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_permvarsf256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_permvarsf256_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(64)))
__coverity___builtin_ia32_permvarsf512_mask(
    float __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    float __attribute__((vector_size(64))) __c,
    unsigned short __d);
#define __builtin_ia32_permvarsf512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_permvarsf512_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(32)))
__coverity___builtin_ia32_permvarsi256_mask(
    int __attribute__((vector_size(32))) __a,
    int __attribute__((vector_size(32))) __b,
    int __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_permvarsi256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_permvarsi256_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(64)))
__coverity___builtin_ia32_permvarsi512_mask(
    int __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    int __attribute__((vector_size(64))) __c,
    unsigned short __d);
#define __builtin_ia32_permvarsi512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_permvarsi512_mask((P0), (P1), (P2), (P3))

extern short __attribute__((vector_size(64)))
__coverity___builtin_ia32_pmaddubsw512_mask(
    char __attribute__((vector_size(64))) __a,
    char __attribute__((vector_size(64))) __b,
    short __attribute__((vector_size(64))) __c,
    unsigned int __d);
#define __builtin_ia32_pmaddubsw512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmaddubsw512_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(64)))
__coverity___builtin_ia32_pmaddwd512_mask(
    short __attribute__((vector_size(64))) __a,
    short __attribute__((vector_size(64))) __b,
    int __attribute__((vector_size(64))) __c,
    unsigned short __d);
#define __builtin_ia32_pmaddwd512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmaddwd512_mask((P0), (P1), (P2), (P3))

extern char __attribute__((vector_size(64)))
__coverity___builtin_ia32_pmaxsb512_mask(
    char __attribute__((vector_size(64))) __a,
    char __attribute__((vector_size(64))) __b,
    char __attribute__((vector_size(64))) __c,
    unsigned long long __d);
#define __builtin_ia32_pmaxsb512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmaxsb512_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(64)))
__coverity___builtin_ia32_pmaxsd512_mask(
    int __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    int __attribute__((vector_size(64))) __c,
    unsigned short __d);
#define __builtin_ia32_pmaxsd512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmaxsd512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmaxsq128_mask(
    long long __attribute__((vector_size(16))) __a,
    long long __attribute__((vector_size(16))) __b,
    long long __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_pmaxsq128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmaxsq128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmaxsq256_mask(
    long long __attribute__((vector_size(32))) __a,
    long long __attribute__((vector_size(32))) __b,
    long long __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_pmaxsq256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmaxsq256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_pmaxsq512_mask(
    long long __attribute__((vector_size(64))) __a,
    long long __attribute__((vector_size(64))) __b,
    long long __attribute__((vector_size(64))) __c,
    unsigned char __d);
#define __builtin_ia32_pmaxsq512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmaxsq512_mask((P0), (P1), (P2), (P3))

extern short __attribute__((vector_size(64)))
__coverity___builtin_ia32_pmaxsw512_mask(
    short __attribute__((vector_size(64))) __a,
    short __attribute__((vector_size(64))) __b,
    short __attribute__((vector_size(64))) __c,
    unsigned int __d);
#define __builtin_ia32_pmaxsw512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmaxsw512_mask((P0), (P1), (P2), (P3))

extern char __attribute__((vector_size(64)))
__coverity___builtin_ia32_pmaxub512_mask(
    char __attribute__((vector_size(64))) __a,
    char __attribute__((vector_size(64))) __b,
    char __attribute__((vector_size(64))) __c,
    unsigned long long __d);
#define __builtin_ia32_pmaxub512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmaxub512_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(64)))
__coverity___builtin_ia32_pmaxud512_mask(
    int __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    int __attribute__((vector_size(64))) __c,
    unsigned short __d);
#define __builtin_ia32_pmaxud512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmaxud512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmaxuq128_mask(
    long long __attribute__((vector_size(16))) __a,
    long long __attribute__((vector_size(16))) __b,
    long long __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_pmaxuq128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmaxuq128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pmaxuq256_mask(
    long long __attribute__((vector_size(32))) __a,
    long long __attribute__((vector_size(32))) __b,
    long long __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_pmaxuq256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmaxuq256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_pmaxuq512_mask(
    long long __attribute__((vector_size(64))) __a,
    long long __attribute__((vector_size(64))) __b,
    long long __attribute__((vector_size(64))) __c,
    unsigned char __d);
#define __builtin_ia32_pmaxuq512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmaxuq512_mask((P0), (P1), (P2), (P3))

extern short __attribute__((vector_size(64)))
__coverity___builtin_ia32_pmaxuw512_mask(
    short __attribute__((vector_size(64))) __a,
    short __attribute__((vector_size(64))) __b,
    short __attribute__((vector_size(64))) __c,
    unsigned int __d);
#define __builtin_ia32_pmaxuw512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmaxuw512_mask((P0), (P1), (P2), (P3))

extern char __attribute__((vector_size(64)))
__coverity___builtin_ia32_pminsb512_mask(
    char __attribute__((vector_size(64))) __a,
    char __attribute__((vector_size(64))) __b,
    char __attribute__((vector_size(64))) __c,
    unsigned long long __d);
#define __builtin_ia32_pminsb512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pminsb512_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(64)))
__coverity___builtin_ia32_pminsd512_mask(
    int __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    int __attribute__((vector_size(64))) __c,
    unsigned short __d);
#define __builtin_ia32_pminsd512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pminsd512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pminsq128_mask(
    long long __attribute__((vector_size(16))) __a,
    long long __attribute__((vector_size(16))) __b,
    long long __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_pminsq128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pminsq128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pminsq256_mask(
    long long __attribute__((vector_size(32))) __a,
    long long __attribute__((vector_size(32))) __b,
    long long __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_pminsq256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pminsq256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_pminsq512_mask(
    long long __attribute__((vector_size(64))) __a,
    long long __attribute__((vector_size(64))) __b,
    long long __attribute__((vector_size(64))) __c,
    unsigned char __d);
#define __builtin_ia32_pminsq512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pminsq512_mask((P0), (P1), (P2), (P3))

extern short __attribute__((vector_size(64)))
__coverity___builtin_ia32_pminsw512_mask(
    short __attribute__((vector_size(64))) __a,
    short __attribute__((vector_size(64))) __b,
    short __attribute__((vector_size(64))) __c,
    unsigned int __d);
#define __builtin_ia32_pminsw512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pminsw512_mask((P0), (P1), (P2), (P3))

extern char __attribute__((vector_size(64)))
__coverity___builtin_ia32_pminub512_mask(
    char __attribute__((vector_size(64))) __a,
    char __attribute__((vector_size(64))) __b,
    char __attribute__((vector_size(64))) __c,
    unsigned long long __d);
#define __builtin_ia32_pminub512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pminub512_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(64)))
__coverity___builtin_ia32_pminud512_mask(
    int __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    int __attribute__((vector_size(64))) __c,
    unsigned short __d);
#define __builtin_ia32_pminud512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pminud512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_pminuq128_mask(
    long long __attribute__((vector_size(16))) __a,
    long long __attribute__((vector_size(16))) __b,
    long long __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_pminuq128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pminuq128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_pminuq256_mask(
    long long __attribute__((vector_size(32))) __a,
    long long __attribute__((vector_size(32))) __b,
    long long __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_pminuq256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pminuq256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_pminuq512_mask(
    long long __attribute__((vector_size(64))) __a,
    long long __attribute__((vector_size(64))) __b,
    long long __attribute__((vector_size(64))) __c,
    unsigned char __d);
#define __builtin_ia32_pminuq512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pminuq512_mask((P0), (P1), (P2), (P3))

extern short __attribute__((vector_size(64)))
__coverity___builtin_ia32_pminuw512_mask(
    short __attribute__((vector_size(64))) __a,
    short __attribute__((vector_size(64))) __b,
    short __attribute__((vector_size(64))) __c,
    unsigned int __d);
#define __builtin_ia32_pminuw512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pminuw512_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmovqd256_mask(
    long long __attribute__((vector_size(32))) __a,
    int __attribute__((vector_size(16))) __b,
    unsigned char __c);
#define __builtin_ia32_pmovqd256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pmovqd256_mask((P0), (P1), (P2))

extern char __attribute__((vector_size(16)))
__coverity___builtin_ia32_pmovwb256_mask(
    short __attribute__((vector_size(32))) __a,
    char __attribute__((vector_size(16))) __b,
    unsigned short __c);
#define __builtin_ia32_pmovwb256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_pmovwb256_mask((P0), (P1), (P2))

extern short __attribute__((vector_size(64)))
__coverity___builtin_ia32_pmulhrsw512_mask(
    short __attribute__((vector_size(64))) __a,
    short __attribute__((vector_size(64))) __b,
    short __attribute__((vector_size(64))) __c,
    unsigned int __d);
#define __builtin_ia32_pmulhrsw512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmulhrsw512_mask((P0), (P1), (P2), (P3))

extern short __attribute__((vector_size(64)))
__coverity___builtin_ia32_pmulhuw512_mask(
    short __attribute__((vector_size(64))) __a,
    short __attribute__((vector_size(64))) __b,
    short __attribute__((vector_size(64))) __c,
    unsigned int __d);
#define __builtin_ia32_pmulhuw512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmulhuw512_mask((P0), (P1), (P2), (P3))

extern short __attribute__((vector_size(64)))
__coverity___builtin_ia32_pmulhw512_mask(
    short __attribute__((vector_size(64))) __a,
    short __attribute__((vector_size(64))) __b,
    short __attribute__((vector_size(64))) __c,
    unsigned int __d);
#define __builtin_ia32_pmulhw512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_pmulhw512_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_prold128_mask(
    int __attribute__((vector_size(16))) __a,
    const int __b,
    int __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_prold128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_prold128_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(32)))
__coverity___builtin_ia32_prold256_mask(
    int __attribute__((vector_size(32))) __a,
    const int __b,
    int __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_prold256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_prold256_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(64)))
__coverity___builtin_ia32_prold512_mask(
    int __attribute__((vector_size(64))) __a,
    const int __b,
    int __attribute__((vector_size(64))) __c,
    unsigned short __d);
#define __builtin_ia32_prold512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_prold512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_prolq128_mask(
    long long __attribute__((vector_size(16))) __a,
    const int __b,
    long long __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_prolq128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_prolq128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_prolq256_mask(
    long long __attribute__((vector_size(32))) __a,
    const int __b,
    long long __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_prolq256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_prolq256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_prolq512_mask(
    long long __attribute__((vector_size(64))) __a,
    const int __b,
    long long __attribute__((vector_size(64))) __c,
    unsigned char __d);
#define __builtin_ia32_prolq512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_prolq512_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_prolvd128_mask(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    int __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_prolvd128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_prolvd128_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(32)))
__coverity___builtin_ia32_prolvd256_mask(
    int __attribute__((vector_size(32))) __a,
    int __attribute__((vector_size(32))) __b,
    int __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_prolvd256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_prolvd256_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(64)))
__coverity___builtin_ia32_prolvd512_mask(
    int __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    int __attribute__((vector_size(64))) __c,
    unsigned short __d);
#define __builtin_ia32_prolvd512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_prolvd512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_prolvq128_mask(
    long long __attribute__((vector_size(16))) __a,
    long long __attribute__((vector_size(16))) __b,
    long long __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_prolvq128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_prolvq128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_prolvq256_mask(
    long long __attribute__((vector_size(32))) __a,
    long long __attribute__((vector_size(32))) __b,
    long long __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_prolvq256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_prolvq256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_prolvq512_mask(
    long long __attribute__((vector_size(64))) __a,
    long long __attribute__((vector_size(64))) __b,
    long long __attribute__((vector_size(64))) __c,
    unsigned char __d);
#define __builtin_ia32_prolvq512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_prolvq512_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_prord128_mask(
    int __attribute__((vector_size(16))) __a,
    const int __b,
    int __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_prord128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_prord128_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(32)))
__coverity___builtin_ia32_prord256_mask(
    int __attribute__((vector_size(32))) __a,
    const int __b,
    int __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_prord256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_prord256_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(64)))
__coverity___builtin_ia32_prord512_mask(
    int __attribute__((vector_size(64))) __a,
    int __b,
    int __attribute__((vector_size(64))) __c,
    unsigned short __d);
#define __builtin_ia32_prord512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_prord512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_prorq128_mask(
    long long __attribute__((vector_size(16))) __a,
    const int __b,
    long long __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_prorq128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_prorq128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_prorq256_mask(
    long long __attribute__((vector_size(32))) __a,
    const int __b,
    long long __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_prorq256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_prorq256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_prorq512_mask(
    long long __attribute__((vector_size(64))) __a,
    int __b,
    long long __attribute__((vector_size(64))) __c,
    unsigned char __d);
#define __builtin_ia32_prorq512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_prorq512_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_prorvd128_mask(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    int __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_prorvd128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_prorvd128_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(32)))
__coverity___builtin_ia32_prorvd256_mask(
    int __attribute__((vector_size(32))) __a,
    int __attribute__((vector_size(32))) __b,
    int __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_prorvd256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_prorvd256_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(64)))
__coverity___builtin_ia32_prorvd512_mask(
    int __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    int __attribute__((vector_size(64))) __c,
    unsigned short __d);
#define __builtin_ia32_prorvd512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_prorvd512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_prorvq128_mask(
    long long __attribute__((vector_size(16))) __a,
    long long __attribute__((vector_size(16))) __b,
    long long __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_prorvq128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_prorvq128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_prorvq256_mask(
    long long __attribute__((vector_size(32))) __a,
    long long __attribute__((vector_size(32))) __b,
    long long __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_prorvq256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_prorvq256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_prorvq512_mask(
    long long __attribute__((vector_size(64))) __a,
    long long __attribute__((vector_size(64))) __b,
    long long __attribute__((vector_size(64))) __c,
    unsigned char __d);
#define __builtin_ia32_prorvq512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_prorvq512_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(32)))
__coverity___builtin_ia32_shuf_f32x4_256_mask(
    float __attribute__((vector_size(32))) __a,
    float __attribute__((vector_size(32))) __b,
    const int __c,
    float __attribute__((vector_size(32))) __d,
    unsigned char __e);
#define __builtin_ia32_shuf_f32x4_256_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_shuf_f32x4_256_mask((P0), (P1), (P2), (P3), (P4))

extern float __attribute__((vector_size(64)))
__coverity___builtin_ia32_shuf_f32x4_mask(
    float __attribute__((vector_size(64))) __a,
    float __attribute__((vector_size(64))) __b,
    const int __c,
    float __attribute__((vector_size(64))) __d,
    unsigned short __e);
#define __builtin_ia32_shuf_f32x4_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_shuf_f32x4_mask((P0), (P1), (P2), (P3), (P4))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_shuf_f64x2_256_mask(
    double __attribute__((vector_size(32))) __a,
    double __attribute__((vector_size(32))) __b,
    const int __c,
    double __attribute__((vector_size(32))) __d,
    unsigned char __e);
#define __builtin_ia32_shuf_f64x2_256_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_shuf_f64x2_256_mask((P0), (P1), (P2), (P3), (P4))

extern double __attribute__((vector_size(64)))
__coverity___builtin_ia32_shuf_f64x2_mask(
    double __attribute__((vector_size(64))) __a,
    double __attribute__((vector_size(64))) __b,
    const int __c,
    double __attribute__((vector_size(64))) __d,
    unsigned char __e);
#define __builtin_ia32_shuf_f64x2_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_shuf_f64x2_mask((P0), (P1), (P2), (P3), (P4))

extern int __attribute__((vector_size(32)))
__coverity___builtin_ia32_shuf_i32x4_256_mask(
    int __attribute__((vector_size(32))) __a,
    int __attribute__((vector_size(32))) __b,
    const int __c,
    int __attribute__((vector_size(32))) __d,
    unsigned char __e);
#define __builtin_ia32_shuf_i32x4_256_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_shuf_i32x4_256_mask((P0), (P1), (P2), (P3), (P4))

extern int __attribute__((vector_size(64)))
__coverity___builtin_ia32_shuf_i32x4_mask(
    int __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    const int __c,
    int __attribute__((vector_size(64))) __d,
    unsigned short __e);
#define __builtin_ia32_shuf_i32x4_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_shuf_i32x4_mask((P0), (P1), (P2), (P3), (P4))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_shuf_i64x2_256_mask(
    long long __attribute__((vector_size(32))) __a,
    long long __attribute__((vector_size(32))) __b,
    const int __c,
    long long __attribute__((vector_size(32))) __d,
    unsigned char __e);
#define __builtin_ia32_shuf_i64x2_256_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_shuf_i64x2_256_mask((P0), (P1), (P2), (P3), (P4))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_shuf_i64x2_mask(
    long long __attribute__((vector_size(64))) __a,
    long long __attribute__((vector_size(64))) __b,
    const int __c,
    long long __attribute__((vector_size(64))) __d,
    unsigned char __e);
#define __builtin_ia32_shuf_i64x2_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_shuf_i64x2_mask((P0), (P1), (P2), (P3), (P4))

// Modified in Version 3.7 and Xcode 7. Removed in Clang 7
// Extra check to ensure we use the right version
#if ( __cov_clang_version_ge(3, 7) || __cov_xcode_version_ge(7, 0))
extern double __attribute__((vector_size(64)))
__coverity___builtin_ia32_sqrtpd512_mask(
    double __attribute__((vector_size(64))) __a,
    double __attribute__((vector_size(64))) __b,
    unsigned char __c,
    const int __d);
#define __builtin_ia32_sqrtpd512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_sqrtpd512_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(64)))
__coverity___builtin_ia32_sqrtps512_mask(
    float __attribute__((vector_size(64))) __a,
    float __attribute__((vector_size(64))) __b,
    unsigned short __c,
    const int __d);
#define __builtin_ia32_sqrtps512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_sqrtps512_mask((P0), (P1), (P2), (P3))
#endif

extern double __attribute__((vector_size(64)))
__coverity___builtin_ia32_subpd512_mask(
    double __attribute__((vector_size(64))) __a,
    double __attribute__((vector_size(64))) __b,
    double __attribute__((vector_size(64))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_subpd512_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_subpd512_mask((P0), (P1), (P2), (P3), (P4))

extern float __attribute__((vector_size(64)))
__coverity___builtin_ia32_subps512_mask(
    float __attribute__((vector_size(64))) __a,
    float __attribute__((vector_size(64))) __b,
    float __attribute__((vector_size(64))) __c,
    unsigned short __d,
    const int __e);
#define __builtin_ia32_subps512_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_subps512_mask((P0), (P1), (P2), (P3), (P4))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_vbroadcastf128_pd256(
    const double __attribute__((vector_size(16)))* __a);
#define __builtin_ia32_vbroadcastf128_pd256(P0) \
    __coverity___builtin_ia32_vbroadcastf128_pd256((P0))

extern float __attribute__((vector_size(32)))
__coverity___builtin_ia32_vbroadcastf128_ps256(
    const float __attribute__((vector_size(16)))* __a);
#define __builtin_ia32_vbroadcastf128_ps256(P0) \
    __coverity___builtin_ia32_vbroadcastf128_ps256((P0))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_vfmaddpd128_mask(
    double __attribute__((vector_size(16))) __a,
    double __attribute__((vector_size(16))) __b,
    double __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vfmaddpd128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfmaddpd128_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_vfmaddpd128_mask3(
    double __attribute__((vector_size(16))) __a,
    double __attribute__((vector_size(16))) __b,
    double __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vfmaddpd128_mask3(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfmaddpd128_mask3((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_vfmaddpd128_maskz(
    double __attribute__((vector_size(16))) __a,
    double __attribute__((vector_size(16))) __b,
    double __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vfmaddpd128_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfmaddpd128_maskz((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_vfmaddpd256_mask(
    double __attribute__((vector_size(32))) __a,
    double __attribute__((vector_size(32))) __b,
    double __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vfmaddpd256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfmaddpd256_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_vfmaddpd256_mask3(
    double __attribute__((vector_size(32))) __a,
    double __attribute__((vector_size(32))) __b,
    double __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vfmaddpd256_mask3(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfmaddpd256_mask3((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_vfmaddpd256_maskz(
    double __attribute__((vector_size(32))) __a,
    double __attribute__((vector_size(32))) __b,
    double __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vfmaddpd256_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfmaddpd256_maskz((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_vfmaddps128_mask(
    float __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vfmaddps128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfmaddps128_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_vfmaddps128_mask3(
    float __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vfmaddps128_mask3(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfmaddps128_mask3((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_vfmaddps128_maskz(
    float __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vfmaddps128_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfmaddps128_maskz((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(32)))
__coverity___builtin_ia32_vfmaddps256_mask(
    float __attribute__((vector_size(32))) __a,
    float __attribute__((vector_size(32))) __b,
    float __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vfmaddps256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfmaddps256_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(32)))
__coverity___builtin_ia32_vfmaddps256_mask3(
    float __attribute__((vector_size(32))) __a,
    float __attribute__((vector_size(32))) __b,
    float __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vfmaddps256_mask3(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfmaddps256_mask3((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(32)))
__coverity___builtin_ia32_vfmaddps256_maskz(
    float __attribute__((vector_size(32))) __a,
    float __attribute__((vector_size(32))) __b,
    float __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vfmaddps256_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfmaddps256_maskz((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_vfmaddsubpd128_mask(
    double __attribute__((vector_size(16))) __a,
    double __attribute__((vector_size(16))) __b,
    double __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vfmaddsubpd128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfmaddsubpd128_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_vfmaddsubpd128_mask3(
    double __attribute__((vector_size(16))) __a,
    double __attribute__((vector_size(16))) __b,
    double __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vfmaddsubpd128_mask3(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfmaddsubpd128_mask3((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_vfmaddsubpd128_maskz(
    double __attribute__((vector_size(16))) __a,
    double __attribute__((vector_size(16))) __b,
    double __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vfmaddsubpd128_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfmaddsubpd128_maskz((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_vfmaddsubpd256_mask(
    double __attribute__((vector_size(32))) __a,
    double __attribute__((vector_size(32))) __b,
    double __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vfmaddsubpd256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfmaddsubpd256_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_vfmaddsubpd256_mask3(
    double __attribute__((vector_size(32))) __a,
    double __attribute__((vector_size(32))) __b,
    double __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vfmaddsubpd256_mask3(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfmaddsubpd256_mask3((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_vfmaddsubpd256_maskz(
    double __attribute__((vector_size(32))) __a,
    double __attribute__((vector_size(32))) __b,
    double __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vfmaddsubpd256_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfmaddsubpd256_maskz((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_vfmaddsubps128_mask(
    float __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vfmaddsubps128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfmaddsubps128_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_vfmaddsubps128_mask3(
    float __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vfmaddsubps128_mask3(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfmaddsubps128_mask3((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_vfmaddsubps128_maskz(
    float __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vfmaddsubps128_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfmaddsubps128_maskz((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(32)))
__coverity___builtin_ia32_vfmaddsubps256_mask(
    float __attribute__((vector_size(32))) __a,
    float __attribute__((vector_size(32))) __b,
    float __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vfmaddsubps256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfmaddsubps256_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(32)))
__coverity___builtin_ia32_vfmaddsubps256_mask3(
    float __attribute__((vector_size(32))) __a,
    float __attribute__((vector_size(32))) __b,
    float __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vfmaddsubps256_mask3(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfmaddsubps256_mask3((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(32)))
__coverity___builtin_ia32_vfmaddsubps256_maskz(
    float __attribute__((vector_size(32))) __a,
    float __attribute__((vector_size(32))) __b,
    float __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vfmaddsubps256_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfmaddsubps256_maskz((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_vfmsubaddpd128_mask3(
    double __attribute__((vector_size(16))) __a,
    double __attribute__((vector_size(16))) __b,
    double __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vfmsubaddpd128_mask3(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfmsubaddpd128_mask3((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_vfmsubaddpd256_mask3(
    double __attribute__((vector_size(32))) __a,
    double __attribute__((vector_size(32))) __b,
    double __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vfmsubaddpd256_mask3(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfmsubaddpd256_mask3((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_vfmsubaddps128_mask3(
    float __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vfmsubaddps128_mask3(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfmsubaddps128_mask3((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(32)))
__coverity___builtin_ia32_vfmsubaddps256_mask3(
    float __attribute__((vector_size(32))) __a,
    float __attribute__((vector_size(32))) __b,
    float __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vfmsubaddps256_mask3(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfmsubaddps256_mask3((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_vfmsubpd128_mask3(
    double __attribute__((vector_size(16))) __a,
    double __attribute__((vector_size(16))) __b,
    double __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vfmsubpd128_mask3(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfmsubpd128_mask3((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_vfmsubpd256_mask3(
    double __attribute__((vector_size(32))) __a,
    double __attribute__((vector_size(32))) __b,
    double __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vfmsubpd256_mask3(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfmsubpd256_mask3((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_vfmsubps128_mask3(
    float __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vfmsubps128_mask3(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfmsubps128_mask3((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(32)))
__coverity___builtin_ia32_vfmsubps256_mask3(
    float __attribute__((vector_size(32))) __a,
    float __attribute__((vector_size(32))) __b,
    float __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vfmsubps256_mask3(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfmsubps256_mask3((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_vfnmaddpd128_mask(
    double __attribute__((vector_size(16))) __a,
    double __attribute__((vector_size(16))) __b,
    double __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vfnmaddpd128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfnmaddpd128_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_vfnmaddpd256(
    double __attribute__((vector_size(32))) __a,
    double __attribute__((vector_size(32))) __b,
    double __attribute__((vector_size(32))) __c);
#define __builtin_ia32_vfnmaddpd256(P0, P1, P2) \
    __coverity___builtin_ia32_vfnmaddpd256((P0), (P1), (P2))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_vfnmaddpd256_mask(
    double __attribute__((vector_size(32))) __a,
    double __attribute__((vector_size(32))) __b,
    double __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vfnmaddpd256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfnmaddpd256_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(64)))
__coverity___builtin_ia32_vfnmaddpd512_mask(
    double __attribute__((vector_size(64))) __a,
    double __attribute__((vector_size(64))) __b,
    double __attribute__((vector_size(64))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_vfnmaddpd512_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_vfnmaddpd512_mask((P0), (P1), (P2), (P3), (P4))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_vfnmaddps128_mask(
    float __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vfnmaddps128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfnmaddps128_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(32)))
__coverity___builtin_ia32_vfnmaddps256(
    float __attribute__((vector_size(32))) __a,
    float __attribute__((vector_size(32))) __b,
    float __attribute__((vector_size(32))) __c);
#define __builtin_ia32_vfnmaddps256(P0, P1, P2) \
    __coverity___builtin_ia32_vfnmaddps256((P0), (P1), (P2))

extern float __attribute__((vector_size(32)))
__coverity___builtin_ia32_vfnmaddps256_mask(
    float __attribute__((vector_size(32))) __a,
    float __attribute__((vector_size(32))) __b,
    float __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vfnmaddps256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfnmaddps256_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(64)))
__coverity___builtin_ia32_vfnmaddps512_mask(
    float __attribute__((vector_size(64))) __a,
    float __attribute__((vector_size(64))) __b,
    float __attribute__((vector_size(64))) __c,
    unsigned short __d,
    const int __e);
#define __builtin_ia32_vfnmaddps512_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_vfnmaddps512_mask((P0), (P1), (P2), (P3), (P4))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_vfnmsubpd128_mask(
    double __attribute__((vector_size(16))) __a,
    double __attribute__((vector_size(16))) __b,
    double __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vfnmsubpd128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfnmsubpd128_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_vfnmsubpd128_mask3(
    double __attribute__((vector_size(16))) __a,
    double __attribute__((vector_size(16))) __b,
    double __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vfnmsubpd128_mask3(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfnmsubpd128_mask3((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_vfnmsubpd256_mask(
    double __attribute__((vector_size(32))) __a,
    double __attribute__((vector_size(32))) __b,
    double __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vfnmsubpd256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfnmsubpd256_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_vfnmsubpd256_mask3(
    double __attribute__((vector_size(32))) __a,
    double __attribute__((vector_size(32))) __b,
    double __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vfnmsubpd256_mask3(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfnmsubpd256_mask3((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(64)))
__coverity___builtin_ia32_vfnmsubpd512_mask(
    double __attribute__((vector_size(64))) __a,
    double __attribute__((vector_size(64))) __b,
    double __attribute__((vector_size(64))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_vfnmsubpd512_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_vfnmsubpd512_mask((P0), (P1), (P2), (P3), (P4))

extern double __attribute__((vector_size(64)))
__coverity___builtin_ia32_vfnmsubpd512_mask3(
    double __attribute__((vector_size(64))) __a,
    double __attribute__((vector_size(64))) __b,
    double __attribute__((vector_size(64))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_vfnmsubpd512_mask3(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_vfnmsubpd512_mask3((P0), (P1), (P2), (P3), (P4))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_vfnmsubps128_mask(
    float __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vfnmsubps128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfnmsubps128_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_vfnmsubps128_mask3(
    float __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vfnmsubps128_mask3(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfnmsubps128_mask3((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(32)))
__coverity___builtin_ia32_vfnmsubps256_mask(
    float __attribute__((vector_size(32))) __a,
    float __attribute__((vector_size(32))) __b,
    float __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vfnmsubps256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfnmsubps256_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(32)))
__coverity___builtin_ia32_vfnmsubps256_mask3(
    float __attribute__((vector_size(32))) __a,
    float __attribute__((vector_size(32))) __b,
    float __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vfnmsubps256_mask3(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vfnmsubps256_mask3((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(64)))
__coverity___builtin_ia32_vfnmsubps512_mask(
    float __attribute__((vector_size(64))) __a,
    float __attribute__((vector_size(64))) __b,
    float __attribute__((vector_size(64))) __c,
    unsigned short __d,
    const int __e);
#define __builtin_ia32_vfnmsubps512_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_vfnmsubps512_mask((P0), (P1), (P2), (P3), (P4))

extern float __attribute__((vector_size(64)))
__coverity___builtin_ia32_vfnmsubps512_mask3(
    float __attribute__((vector_size(64))) __a,
    float __attribute__((vector_size(64))) __b,
    float __attribute__((vector_size(64))) __c,
    unsigned short __d,
    const int __e);
#define __builtin_ia32_vfnmsubps512_mask3(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_vfnmsubps512_mask3((P0), (P1), (P2), (P3), (P4))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_vfnmsubsd3_mask3(
    double __attribute__((vector_size(16))) __a,
    double __attribute__((vector_size(16))) __b,
    double __attribute__((vector_size(16))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_vfnmsubsd3_mask3(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_vfnmsubsd3_mask3((P0), (P1), (P2), (P3), (P4))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_vfnmsubss3_mask3(
    float __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __d,
    const int __e);
#define __builtin_ia32_vfnmsubss3_mask3(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_vfnmsubss3_mask3((P0), (P1), (P2), (P3), (P4))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpdpbusd128_mask(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    int __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vpdpbusd128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpdpbusd128_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpdpbusd128_maskz(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    int __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vpdpbusd128_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpdpbusd128_maskz((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpdpbusd256_mask(
    int __attribute__((vector_size(32))) __a,
    int __attribute__((vector_size(32))) __b,
    int __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vpdpbusd256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpdpbusd256_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpdpbusd256_maskz(
    int __attribute__((vector_size(32))) __a,
    int __attribute__((vector_size(32))) __b,
    int __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vpdpbusd256_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpdpbusd256_maskz((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpdpbusd512_mask(
    int __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    int __attribute__((vector_size(64))) __c,
    unsigned short __d);
#define __builtin_ia32_vpdpbusd512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpdpbusd512_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpdpbusd512_maskz(
    int __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    int __attribute__((vector_size(64))) __c,
    unsigned short __d);
#define __builtin_ia32_vpdpbusd512_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpdpbusd512_maskz((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpdpbusds128_mask(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    int __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vpdpbusds128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpdpbusds128_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpdpbusds128_maskz(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    int __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vpdpbusds128_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpdpbusds128_maskz((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpdpbusds256_mask(
    int __attribute__((vector_size(32))) __a,
    int __attribute__((vector_size(32))) __b,
    int __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vpdpbusds256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpdpbusds256_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpdpbusds256_maskz(
    int __attribute__((vector_size(32))) __a,
    int __attribute__((vector_size(32))) __b,
    int __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vpdpbusds256_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpdpbusds256_maskz((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpdpbusds512_mask(
    int __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    int __attribute__((vector_size(64))) __c,
    unsigned short __d);
#define __builtin_ia32_vpdpbusds512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpdpbusds512_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpdpbusds512_maskz(
    int __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    int __attribute__((vector_size(64))) __c,
    unsigned short __d);
#define __builtin_ia32_vpdpbusds512_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpdpbusds512_maskz((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpdpwssd128_mask(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    int __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vpdpwssd128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpdpwssd128_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpdpwssd128_maskz(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    int __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vpdpwssd128_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpdpwssd128_maskz((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpdpwssd256_mask(
    int __attribute__((vector_size(32))) __a,
    int __attribute__((vector_size(32))) __b,
    int __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vpdpwssd256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpdpwssd256_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpdpwssd256_maskz(
    int __attribute__((vector_size(32))) __a,
    int __attribute__((vector_size(32))) __b,
    int __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vpdpwssd256_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpdpwssd256_maskz((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpdpwssd512_mask(
    int __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    int __attribute__((vector_size(64))) __c,
    unsigned short __d);
#define __builtin_ia32_vpdpwssd512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpdpwssd512_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpdpwssd512_maskz(
    int __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    int __attribute__((vector_size(64))) __c,
    unsigned short __d);
#define __builtin_ia32_vpdpwssd512_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpdpwssd512_maskz((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpdpwssds128_mask(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    int __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vpdpwssds128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpdpwssds128_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpdpwssds128_maskz(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    int __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vpdpwssds128_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpdpwssds128_maskz((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpdpwssds256_mask(
    int __attribute__((vector_size(32))) __a,
    int __attribute__((vector_size(32))) __b,
    int __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vpdpwssds256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpdpwssds256_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpdpwssds256_maskz(
    int __attribute__((vector_size(32))) __a,
    int __attribute__((vector_size(32))) __b,
    int __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vpdpwssds256_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpdpwssds256_maskz((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpdpwssds512_mask(
    int __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    int __attribute__((vector_size(64))) __c,
    unsigned short __d);
#define __builtin_ia32_vpdpwssds512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpdpwssds512_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpdpwssds512_maskz(
    int __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    int __attribute__((vector_size(64))) __c,
    unsigned short __d);
#define __builtin_ia32_vpdpwssds512_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpdpwssds512_maskz((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpermi2vard128_mask(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    int __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vpermi2vard128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermi2vard128_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpermi2vard256_mask(
    int __attribute__((vector_size(32))) __a,
    int __attribute__((vector_size(32))) __b,
    int __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vpermi2vard256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermi2vard256_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpermi2vard512_mask(
    int __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    int __attribute__((vector_size(64))) __c,
    unsigned short __d);
#define __builtin_ia32_vpermi2vard512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermi2vard512_mask((P0), (P1), (P2), (P3))

extern short __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpermi2varhi128_mask(
    short __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b,
    short __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vpermi2varhi128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermi2varhi128_mask((P0), (P1), (P2), (P3))

extern short __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpermi2varhi256_mask(
    short __attribute__((vector_size(32))) __a,
    short __attribute__((vector_size(32))) __b,
    short __attribute__((vector_size(32))) __c,
    unsigned short __d);
#define __builtin_ia32_vpermi2varhi256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermi2varhi256_mask((P0), (P1), (P2), (P3))

extern short __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpermi2varhi512_mask(
    short __attribute__((vector_size(64))) __a,
    short __attribute__((vector_size(64))) __b,
    short __attribute__((vector_size(64))) __c,
    unsigned int __d);
#define __builtin_ia32_vpermi2varhi512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermi2varhi512_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpermi2varpd128_mask(
    double __attribute__((vector_size(16))) __a,
    long long __attribute__((vector_size(16))) __b,
    double __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vpermi2varpd128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermi2varpd128_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpermi2varpd256_mask(
    double __attribute__((vector_size(32))) __a,
    long long __attribute__((vector_size(32))) __b,
    double __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vpermi2varpd256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermi2varpd256_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpermi2varpd512_mask(
    double __attribute__((vector_size(64))) __a,
    long long __attribute__((vector_size(64))) __b,
    double __attribute__((vector_size(64))) __c,
    unsigned char __d);
#define __builtin_ia32_vpermi2varpd512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermi2varpd512_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpermi2varps128_mask(
    float __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vpermi2varps128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermi2varps128_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpermi2varps256_mask(
    float __attribute__((vector_size(32))) __a,
    int __attribute__((vector_size(32))) __b,
    float __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vpermi2varps256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermi2varps256_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpermi2varps512_mask(
    float __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    float __attribute__((vector_size(64))) __c,
    unsigned short __d);
#define __builtin_ia32_vpermi2varps512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermi2varps512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpermi2varq128_mask(
    long long __attribute__((vector_size(16))) __a,
    long long __attribute__((vector_size(16))) __b,
    long long __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vpermi2varq128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermi2varq128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpermi2varq256_mask(
    long long __attribute__((vector_size(32))) __a,
    long long __attribute__((vector_size(32))) __b,
    long long __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vpermi2varq256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermi2varq256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpermi2varq512_mask(
    long long __attribute__((vector_size(64))) __a,
    long long __attribute__((vector_size(64))) __b,
    long long __attribute__((vector_size(64))) __c,
    unsigned char __d);
#define __builtin_ia32_vpermi2varq512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermi2varq512_mask((P0), (P1), (P2), (P3))

extern char __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpermi2varqi128_mask(
    char __attribute__((vector_size(16))) __a,
    char __attribute__((vector_size(16))) __b,
    char __attribute__((vector_size(16))) __c,
    unsigned short __d);
#define __builtin_ia32_vpermi2varqi128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermi2varqi128_mask((P0), (P1), (P2), (P3))

extern char __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpermi2varqi256_mask(
    char __attribute__((vector_size(32))) __a,
    char __attribute__((vector_size(32))) __b,
    char __attribute__((vector_size(32))) __c,
    unsigned int __d);
#define __builtin_ia32_vpermi2varqi256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermi2varqi256_mask((P0), (P1), (P2), (P3))

extern char __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpermi2varqi512_mask(
    char __attribute__((vector_size(64))) __a,
    char __attribute__((vector_size(64))) __b,
    char __attribute__((vector_size(64))) __c,
    unsigned long long __d);
#define __builtin_ia32_vpermi2varqi512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermi2varqi512_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpermt2vard128_mask(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    int __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vpermt2vard128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermt2vard128_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpermt2vard128_maskz(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    int __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vpermt2vard128_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermt2vard128_maskz((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpermt2vard256_mask(
    int __attribute__((vector_size(32))) __a,
    int __attribute__((vector_size(32))) __b,
    int __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vpermt2vard256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermt2vard256_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpermt2vard256_maskz(
    int __attribute__((vector_size(32))) __a,
    int __attribute__((vector_size(32))) __b,
    int __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vpermt2vard256_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermt2vard256_maskz((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpermt2vard512_mask(
    int __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    int __attribute__((vector_size(64))) __c,
    unsigned short __d);
#define __builtin_ia32_vpermt2vard512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermt2vard512_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpermt2vard512_maskz(
    int __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    int __attribute__((vector_size(64))) __c,
    unsigned short __d);
#define __builtin_ia32_vpermt2vard512_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermt2vard512_maskz((P0), (P1), (P2), (P3))

extern short __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpermt2varhi128_mask(
    short __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b,
    short __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vpermt2varhi128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermt2varhi128_mask((P0), (P1), (P2), (P3))

extern short __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpermt2varhi128_maskz(
    short __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b,
    short __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vpermt2varhi128_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermt2varhi128_maskz((P0), (P1), (P2), (P3))

extern short __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpermt2varhi256_mask(
    short __attribute__((vector_size(32))) __a,
    short __attribute__((vector_size(32))) __b,
    short __attribute__((vector_size(32))) __c,
    unsigned short __d);
#define __builtin_ia32_vpermt2varhi256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermt2varhi256_mask((P0), (P1), (P2), (P3))

extern short __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpermt2varhi256_maskz(
    short __attribute__((vector_size(32))) __a,
    short __attribute__((vector_size(32))) __b,
    short __attribute__((vector_size(32))) __c,
    unsigned short __d);
#define __builtin_ia32_vpermt2varhi256_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermt2varhi256_maskz((P0), (P1), (P2), (P3))

extern short __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpermt2varhi512_mask(
    short __attribute__((vector_size(64))) __a,
    short __attribute__((vector_size(64))) __b,
    short __attribute__((vector_size(64))) __c,
    unsigned int __d);
#define __builtin_ia32_vpermt2varhi512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermt2varhi512_mask((P0), (P1), (P2), (P3))

extern short __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpermt2varhi512_maskz(
    short __attribute__((vector_size(64))) __a,
    short __attribute__((vector_size(64))) __b,
    short __attribute__((vector_size(64))) __c,
    unsigned int __d);
#define __builtin_ia32_vpermt2varhi512_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermt2varhi512_maskz((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpermt2varpd128_mask(
    long long __attribute__((vector_size(16))) __a,
    double __attribute__((vector_size(16))) __b,
    double __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vpermt2varpd128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermt2varpd128_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpermt2varpd128_maskz(
    long long __attribute__((vector_size(16))) __a,
    double __attribute__((vector_size(16))) __b,
    double __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vpermt2varpd128_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermt2varpd128_maskz((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpermt2varpd256_mask(
    long long __attribute__((vector_size(32))) __a,
    double __attribute__((vector_size(32))) __b,
    double __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vpermt2varpd256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermt2varpd256_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpermt2varpd256_maskz(
    long long __attribute__((vector_size(32))) __a,
    double __attribute__((vector_size(32))) __b,
    double __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vpermt2varpd256_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermt2varpd256_maskz((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpermt2varpd512_mask(
    long long __attribute__((vector_size(64))) __a,
    double __attribute__((vector_size(64))) __b,
    double __attribute__((vector_size(64))) __c,
    unsigned char __d);
#define __builtin_ia32_vpermt2varpd512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermt2varpd512_mask((P0), (P1), (P2), (P3))

extern double __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpermt2varpd512_maskz(
    long long __attribute__((vector_size(64))) __a,
    double __attribute__((vector_size(64))) __b,
    double __attribute__((vector_size(64))) __c,
    unsigned char __d);
#define __builtin_ia32_vpermt2varpd512_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermt2varpd512_maskz((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpermt2varps128_mask(
    int __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vpermt2varps128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermt2varps128_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpermt2varps128_maskz(
    int __attribute__((vector_size(16))) __a,
    float __attribute__((vector_size(16))) __b,
    float __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vpermt2varps128_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermt2varps128_maskz((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpermt2varps256_mask(
    int __attribute__((vector_size(32))) __a,
    float __attribute__((vector_size(32))) __b,
    float __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vpermt2varps256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermt2varps256_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpermt2varps256_maskz(
    int __attribute__((vector_size(32))) __a,
    float __attribute__((vector_size(32))) __b,
    float __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vpermt2varps256_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermt2varps256_maskz((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpermt2varps512_mask(
    int __attribute__((vector_size(64))) __a,
    float __attribute__((vector_size(64))) __b,
    float __attribute__((vector_size(64))) __c,
    unsigned short __d);
#define __builtin_ia32_vpermt2varps512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermt2varps512_mask((P0), (P1), (P2), (P3))

extern float __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpermt2varps512_maskz(
    int __attribute__((vector_size(64))) __a,
    float __attribute__((vector_size(64))) __b,
    float __attribute__((vector_size(64))) __c,
    unsigned short __d);
#define __builtin_ia32_vpermt2varps512_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermt2varps512_maskz((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpermt2varq128_mask(
    long long __attribute__((vector_size(16))) __a,
    long long __attribute__((vector_size(16))) __b,
    long long __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vpermt2varq128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermt2varq128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpermt2varq128_maskz(
    long long __attribute__((vector_size(16))) __a,
    long long __attribute__((vector_size(16))) __b,
    long long __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vpermt2varq128_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermt2varq128_maskz((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpermt2varq256_mask(
    long long __attribute__((vector_size(32))) __a,
    long long __attribute__((vector_size(32))) __b,
    long long __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vpermt2varq256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermt2varq256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpermt2varq256_maskz(
    long long __attribute__((vector_size(32))) __a,
    long long __attribute__((vector_size(32))) __b,
    long long __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vpermt2varq256_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermt2varq256_maskz((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpermt2varq512_mask(
    long long __attribute__((vector_size(64))) __a,
    long long __attribute__((vector_size(64))) __b,
    long long __attribute__((vector_size(64))) __c,
    unsigned char __d);
#define __builtin_ia32_vpermt2varq512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermt2varq512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpermt2varq512_maskz(
    long long __attribute__((vector_size(64))) __a,
    long long __attribute__((vector_size(64))) __b,
    long long __attribute__((vector_size(64))) __c,
    unsigned char __d);
#define __builtin_ia32_vpermt2varq512_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermt2varq512_maskz((P0), (P1), (P2), (P3))

extern char __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpermt2varqi128_mask(
    char __attribute__((vector_size(16))) __a,
    char __attribute__((vector_size(16))) __b,
    char __attribute__((vector_size(16))) __c,
    unsigned short __d);
#define __builtin_ia32_vpermt2varqi128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermt2varqi128_mask((P0), (P1), (P2), (P3))

extern char __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpermt2varqi128_maskz(
    char __attribute__((vector_size(16))) __a,
    char __attribute__((vector_size(16))) __b,
    char __attribute__((vector_size(16))) __c,
    unsigned short __d);
#define __builtin_ia32_vpermt2varqi128_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermt2varqi128_maskz((P0), (P1), (P2), (P3))

extern char __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpermt2varqi256_mask(
    char __attribute__((vector_size(32))) __a,
    char __attribute__((vector_size(32))) __b,
    char __attribute__((vector_size(32))) __c,
    unsigned int __d);
#define __builtin_ia32_vpermt2varqi256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermt2varqi256_mask((P0), (P1), (P2), (P3))

extern char __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpermt2varqi256_maskz(
    char __attribute__((vector_size(32))) __a,
    char __attribute__((vector_size(32))) __b,
    char __attribute__((vector_size(32))) __c,
    unsigned int __d);
#define __builtin_ia32_vpermt2varqi256_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermt2varqi256_maskz((P0), (P1), (P2), (P3))

extern char __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpermt2varqi512_mask(
    char __attribute__((vector_size(64))) __a,
    char __attribute__((vector_size(64))) __b,
    char __attribute__((vector_size(64))) __c,
    unsigned long long __d);
#define __builtin_ia32_vpermt2varqi512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermt2varqi512_mask((P0), (P1), (P2), (P3))

extern char __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpermt2varqi512_maskz(
    char __attribute__((vector_size(64))) __a,
    char __attribute__((vector_size(64))) __b,
    char __attribute__((vector_size(64))) __c,
    unsigned long long __d);
#define __builtin_ia32_vpermt2varqi512_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpermt2varqi512_maskz((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_vplzcntd_128_mask(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    unsigned char __c);
#define __builtin_ia32_vplzcntd_128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_vplzcntd_128_mask((P0), (P1), (P2))

extern int __attribute__((vector_size(32)))
__coverity___builtin_ia32_vplzcntd_256_mask(
    int __attribute__((vector_size(32))) __a,
    int __attribute__((vector_size(32))) __b,
    unsigned char __c);
#define __builtin_ia32_vplzcntd_256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_vplzcntd_256_mask((P0), (P1), (P2))

extern int __attribute__((vector_size(64)))
__coverity___builtin_ia32_vplzcntd_512_mask(
    int __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    unsigned short __c);
#define __builtin_ia32_vplzcntd_512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_vplzcntd_512_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_vplzcntq_128_mask(
    long long __attribute__((vector_size(16))) __a,
    long long __attribute__((vector_size(16))) __b,
    unsigned char __c);
#define __builtin_ia32_vplzcntq_128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_vplzcntq_128_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_vplzcntq_256_mask(
    long long __attribute__((vector_size(32))) __a,
    long long __attribute__((vector_size(32))) __b,
    unsigned char __c);
#define __builtin_ia32_vplzcntq_256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_vplzcntq_256_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_vplzcntq_512_mask(
    long long __attribute__((vector_size(64))) __a,
    long long __attribute__((vector_size(64))) __b,
    unsigned char __c);
#define __builtin_ia32_vplzcntq_512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_vplzcntq_512_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpmadd52huq128_mask(
    long long __attribute__((vector_size(16))) __a,
    long long __attribute__((vector_size(16))) __b,
    long long __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vpmadd52huq128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpmadd52huq128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpmadd52huq128_maskz(
    long long __attribute__((vector_size(16))) __a,
    long long __attribute__((vector_size(16))) __b,
    long long __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vpmadd52huq128_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpmadd52huq128_maskz((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpmadd52huq256_mask(
    long long __attribute__((vector_size(32))) __a,
    long long __attribute__((vector_size(32))) __b,
    long long __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vpmadd52huq256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpmadd52huq256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpmadd52huq256_maskz(
    long long __attribute__((vector_size(32))) __a,
    long long __attribute__((vector_size(32))) __b,
    long long __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vpmadd52huq256_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpmadd52huq256_maskz((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpmadd52huq512_mask(
    long long __attribute__((vector_size(64))) __a,
    long long __attribute__((vector_size(64))) __b,
    long long __attribute__((vector_size(64))) __c,
    unsigned char __d);
#define __builtin_ia32_vpmadd52huq512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpmadd52huq512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpmadd52huq512_maskz(
    long long __attribute__((vector_size(64))) __a,
    long long __attribute__((vector_size(64))) __b,
    long long __attribute__((vector_size(64))) __c,
    unsigned char __d);
#define __builtin_ia32_vpmadd52huq512_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpmadd52huq512_maskz((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpmadd52luq128_mask(
    long long __attribute__((vector_size(16))) __a,
    long long __attribute__((vector_size(16))) __b,
    long long __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vpmadd52luq128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpmadd52luq128_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpmadd52luq128_maskz(
    long long __attribute__((vector_size(16))) __a,
    long long __attribute__((vector_size(16))) __b,
    long long __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vpmadd52luq128_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpmadd52luq128_maskz((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpmadd52luq256_mask(
    long long __attribute__((vector_size(32))) __a,
    long long __attribute__((vector_size(32))) __b,
    long long __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vpmadd52luq256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpmadd52luq256_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpmadd52luq256_maskz(
    long long __attribute__((vector_size(32))) __a,
    long long __attribute__((vector_size(32))) __b,
    long long __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vpmadd52luq256_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpmadd52luq256_maskz((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpmadd52luq512_mask(
    long long __attribute__((vector_size(64))) __a,
    long long __attribute__((vector_size(64))) __b,
    long long __attribute__((vector_size(64))) __c,
    unsigned char __d);
#define __builtin_ia32_vpmadd52luq512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpmadd52luq512_mask((P0), (P1), (P2), (P3))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpmadd52luq512_maskz(
    long long __attribute__((vector_size(64))) __a,
    long long __attribute__((vector_size(64))) __b,
    long long __attribute__((vector_size(64))) __c,
    unsigned char __d);
#define __builtin_ia32_vpmadd52luq512_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpmadd52luq512_maskz((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpshldd128_mask(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    const int __c,
    int __attribute__((vector_size(16))) __d,
    unsigned char __e);
#define __builtin_ia32_vpshldd128_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_vpshldd128_mask((P0), (P1), (P2), (P3), (P4))

extern int __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpshldd256_mask(
    int __attribute__((vector_size(32))) __a,
    int __attribute__((vector_size(32))) __b,
    const int __c,
    int __attribute__((vector_size(32))) __d,
    unsigned char __e);
#define __builtin_ia32_vpshldd256_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_vpshldd256_mask((P0), (P1), (P2), (P3), (P4))

extern int __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpshldd512_mask(
    int __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    const int __c,
    int __attribute__((vector_size(64))) __d,
    unsigned short __e);
#define __builtin_ia32_vpshldd512_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_vpshldd512_mask((P0), (P1), (P2), (P3), (P4))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpshldq128_mask(
    long long __attribute__((vector_size(16))) __a,
    long long __attribute__((vector_size(16))) __b,
    const int __c,
    long long __attribute__((vector_size(16))) __d,
    unsigned char __e);
#define __builtin_ia32_vpshldq128_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_vpshldq128_mask((P0), (P1), (P2), (P3), (P4))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpshldq256_mask(
    long long __attribute__((vector_size(32))) __a,
    long long __attribute__((vector_size(32))) __b,
    const int __c,
    long long __attribute__((vector_size(32))) __d,
    unsigned char __e);
#define __builtin_ia32_vpshldq256_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_vpshldq256_mask((P0), (P1), (P2), (P3), (P4))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpshldq512_mask(
    long long __attribute__((vector_size(64))) __a,
    long long __attribute__((vector_size(64))) __b,
    const int __c,
    long long __attribute__((vector_size(64))) __d,
    unsigned char __e);
#define __builtin_ia32_vpshldq512_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_vpshldq512_mask((P0), (P1), (P2), (P3), (P4))

extern short __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpshldw128_mask(
    short __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b,
    const int __c,
    short __attribute__((vector_size(16))) __d,
    unsigned char __e);
#define __builtin_ia32_vpshldw128_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_vpshldw128_mask((P0), (P1), (P2), (P3), (P4))

extern short __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpshldw256_mask(
    short __attribute__((vector_size(32))) __a,
    short __attribute__((vector_size(32))) __b,
    const int __c,
    short __attribute__((vector_size(32))) __d,
    unsigned short __e);
#define __builtin_ia32_vpshldw256_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_vpshldw256_mask((P0), (P1), (P2), (P3), (P4))

extern short __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpshldw512_mask(
    short __attribute__((vector_size(64))) __a,
    short __attribute__((vector_size(64))) __b,
    const int __c,
    short __attribute__((vector_size(64))) __d,
    unsigned int __e);
#define __builtin_ia32_vpshldw512_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_vpshldw512_mask((P0), (P1), (P2), (P3), (P4))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpshrdd128_mask(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    const int __c,
    int __attribute__((vector_size(16))) __d,
    unsigned char __e);
#define __builtin_ia32_vpshrdd128_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_vpshrdd128_mask((P0), (P1), (P2), (P3), (P4))

extern int __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpshrdd256_mask(
    int __attribute__((vector_size(32))) __a,
    int __attribute__((vector_size(32))) __b,
    const int __c,
    int __attribute__((vector_size(32))) __d,
    unsigned char __e);
#define __builtin_ia32_vpshrdd256_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_vpshrdd256_mask((P0), (P1), (P2), (P3), (P4))

extern int __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpshrdd512_mask(
    int __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    const int __c,
    int __attribute__((vector_size(64))) __d,
    unsigned short __e);
#define __builtin_ia32_vpshrdd512_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_vpshrdd512_mask((P0), (P1), (P2), (P3), (P4))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpshrdq128_mask(
    long long __attribute__((vector_size(16))) __a,
    long long __attribute__((vector_size(16))) __b,
    const int __c,
    long long __attribute__((vector_size(16))) __d,
    unsigned char __e);
#define __builtin_ia32_vpshrdq128_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_vpshrdq128_mask((P0), (P1), (P2), (P3), (P4))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpshrdq256_mask(
    long long __attribute__((vector_size(32))) __a,
    long long __attribute__((vector_size(32))) __b,
    const int __c,
    long long __attribute__((vector_size(32))) __d,
    unsigned char __e);
#define __builtin_ia32_vpshrdq256_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_vpshrdq256_mask((P0), (P1), (P2), (P3), (P4))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpshrdq512_mask(
    long long __attribute__((vector_size(64))) __a,
    long long __attribute__((vector_size(64))) __b,
    const int __c,
    long long __attribute__((vector_size(64))) __d,
    unsigned char __e);
#define __builtin_ia32_vpshrdq512_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_vpshrdq512_mask((P0), (P1), (P2), (P3), (P4))

extern short __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpshrdw128_mask(
    short __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b,
    const int __c,
    short __attribute__((vector_size(16))) __d,
    unsigned char __e);
#define __builtin_ia32_vpshrdw128_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_vpshrdw128_mask((P0), (P1), (P2), (P3), (P4))

extern short __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpshrdw256_mask(
    short __attribute__((vector_size(32))) __a,
    short __attribute__((vector_size(32))) __b,
    const int __c,
    short __attribute__((vector_size(32))) __d,
    unsigned short __e);
#define __builtin_ia32_vpshrdw256_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_vpshrdw256_mask((P0), (P1), (P2), (P3), (P4))

extern short __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpshrdw512_mask(
    short __attribute__((vector_size(64))) __a,
    short __attribute__((vector_size(64))) __b,
    const int __c,
    short __attribute__((vector_size(64))) __d,
    unsigned int __e);
#define __builtin_ia32_vpshrdw512_mask(P0, P1, P2, P3, P4) \
    __coverity___builtin_ia32_vpshrdw512_mask((P0), (P1), (P2), (P3), (P4))

extern double
__coverity___nvvm_atom_add_g_d(
    volatile double* __a,
    double __b);
#define __nvvm_atom_add_g_d(P0, P1) \
    __coverity___nvvm_atom_add_g_d((P0), (P1))

extern float
__coverity___nvvm_atom_add_g_f(
    volatile float* __a,
    float __b);
#define __nvvm_atom_add_g_f(P0, P1) \
    __coverity___nvvm_atom_add_g_f((P0), (P1))

extern int
__coverity___nvvm_atom_add_g_i(
    volatile int* __a,
    int __b);
#define __nvvm_atom_add_g_i(P0, P1) \
    __coverity___nvvm_atom_add_g_i((P0), (P1))

extern long
__coverity___nvvm_atom_add_g_l(
    volatile long* __a,
    long __b);
#define __nvvm_atom_add_g_l(P0, P1) \
    __coverity___nvvm_atom_add_g_l((P0), (P1))

extern long long
__coverity___nvvm_atom_add_g_ll(
    volatile long long* __a,
    long long __b);
#define __nvvm_atom_add_g_ll(P0, P1) \
    __coverity___nvvm_atom_add_g_ll((P0), (P1))

extern double
__coverity___nvvm_atom_add_s_d(
    volatile double* __a,
    double __b);
#define __nvvm_atom_add_s_d(P0, P1) \
    __coverity___nvvm_atom_add_s_d((P0), (P1))

extern float
__coverity___nvvm_atom_add_s_f(
    volatile float* __a,
    float __b);
#define __nvvm_atom_add_s_f(P0, P1) \
    __coverity___nvvm_atom_add_s_f((P0), (P1))

extern int
__coverity___nvvm_atom_add_s_i(
    volatile int* __a,
    int __b);
#define __nvvm_atom_add_s_i(P0, P1) \
    __coverity___nvvm_atom_add_s_i((P0), (P1))

extern long
__coverity___nvvm_atom_add_s_l(
    volatile long* __a,
    long __b);
#define __nvvm_atom_add_s_l(P0, P1) \
    __coverity___nvvm_atom_add_s_l((P0), (P1))

extern long long
__coverity___nvvm_atom_add_s_ll(
    volatile long long* __a,
    long long __b);
#define __nvvm_atom_add_s_ll(P0, P1) \
    __coverity___nvvm_atom_add_s_ll((P0), (P1))

extern int
__coverity___nvvm_atom_and_g_i(
    volatile int* __a,
    int __b);
#define __nvvm_atom_and_g_i(P0, P1) \
    __coverity___nvvm_atom_and_g_i((P0), (P1))

extern long
__coverity___nvvm_atom_and_g_l(
    volatile long* __a,
    long __b);
#define __nvvm_atom_and_g_l(P0, P1) \
    __coverity___nvvm_atom_and_g_l((P0), (P1))

extern long long
__coverity___nvvm_atom_and_g_ll(
    volatile long long* __a,
    long long __b);
#define __nvvm_atom_and_g_ll(P0, P1) \
    __coverity___nvvm_atom_and_g_ll((P0), (P1))

extern int
__coverity___nvvm_atom_and_s_i(
    volatile int* __a,
    int __b);
#define __nvvm_atom_and_s_i(P0, P1) \
    __coverity___nvvm_atom_and_s_i((P0), (P1))

extern long
__coverity___nvvm_atom_and_s_l(
    volatile long* __a,
    long __b);
#define __nvvm_atom_and_s_l(P0, P1) \
    __coverity___nvvm_atom_and_s_l((P0), (P1))

extern long long
__coverity___nvvm_atom_and_s_ll(
    volatile long long* __a,
    long long __b);
#define __nvvm_atom_and_s_ll(P0, P1) \
    __coverity___nvvm_atom_and_s_ll((P0), (P1))

extern int
__coverity___nvvm_atom_cas_g_i(
    volatile int* __a,
    int __b,
    int __c);
#define __nvvm_atom_cas_g_i(P0, P1, P2) \
    __coverity___nvvm_atom_cas_g_i((P0), (P1), (P2))

extern long
__coverity___nvvm_atom_cas_g_l(
    volatile long* __a,
    long __b,
    long __c);
#define __nvvm_atom_cas_g_l(P0, P1, P2) \
    __coverity___nvvm_atom_cas_g_l((P0), (P1), (P2))

extern long long
__coverity___nvvm_atom_cas_g_ll(
    volatile long long* __a,
    long long __b,
    long long __c);
#define __nvvm_atom_cas_g_ll(P0, P1, P2) \
    __coverity___nvvm_atom_cas_g_ll((P0), (P1), (P2))

extern int
__coverity___nvvm_atom_cas_s_i(
    volatile int* __a,
    int __b,
    int __c);
#define __nvvm_atom_cas_s_i(P0, P1, P2) \
    __coverity___nvvm_atom_cas_s_i((P0), (P1), (P2))

extern long
__coverity___nvvm_atom_cas_s_l(
    volatile long* __a,
    long __b,
    long __c);
#define __nvvm_atom_cas_s_l(P0, P1, P2) \
    __coverity___nvvm_atom_cas_s_l((P0), (P1), (P2))

extern long long
__coverity___nvvm_atom_cas_s_ll(
    volatile long long* __a,
    long long __b,
    long long __c);
#define __nvvm_atom_cas_s_ll(P0, P1, P2) \
    __coverity___nvvm_atom_cas_s_ll((P0), (P1), (P2))

extern unsigned int
__coverity___nvvm_atom_dec_g_ui(
    volatile unsigned int* __a,
    unsigned int __b);
#define __nvvm_atom_dec_g_ui(P0, P1) \
    __coverity___nvvm_atom_dec_g_ui((P0), (P1))

extern unsigned int
__coverity___nvvm_atom_dec_s_ui(
    volatile unsigned int* __a,
    unsigned int __b);
#define __nvvm_atom_dec_s_ui(P0, P1) \
    __coverity___nvvm_atom_dec_s_ui((P0), (P1))

extern unsigned int
__coverity___nvvm_atom_inc_g_ui(
    volatile unsigned int* __a,
    unsigned int __b);
#define __nvvm_atom_inc_g_ui(P0, P1) \
    __coverity___nvvm_atom_inc_g_ui((P0), (P1))

extern unsigned int
__coverity___nvvm_atom_inc_s_ui(
    volatile unsigned int* __a,
    unsigned int __b);
#define __nvvm_atom_inc_s_ui(P0, P1) \
    __coverity___nvvm_atom_inc_s_ui((P0), (P1))

extern int
__coverity___nvvm_atom_max_g_i(
    volatile int* __a,
    int __b);
#define __nvvm_atom_max_g_i(P0, P1) \
    __coverity___nvvm_atom_max_g_i((P0), (P1))

extern long
__coverity___nvvm_atom_max_g_l(
    volatile long* __a,
    long __b);
#define __nvvm_atom_max_g_l(P0, P1) \
    __coverity___nvvm_atom_max_g_l((P0), (P1))

extern long long
__coverity___nvvm_atom_max_g_ll(
    volatile long long* __a,
    long long __b);
#define __nvvm_atom_max_g_ll(P0, P1) \
    __coverity___nvvm_atom_max_g_ll((P0), (P1))

extern unsigned int
__coverity___nvvm_atom_max_g_ui(
    volatile unsigned int* __a,
    unsigned int __b);
#define __nvvm_atom_max_g_ui(P0, P1) \
    __coverity___nvvm_atom_max_g_ui((P0), (P1))

extern unsigned long
__coverity___nvvm_atom_max_g_ul(
    volatile unsigned long* __a,
    unsigned long __b);
#define __nvvm_atom_max_g_ul(P0, P1) \
    __coverity___nvvm_atom_max_g_ul((P0), (P1))

extern unsigned long long
__coverity___nvvm_atom_max_g_ull(
    volatile unsigned long long* __a,
    unsigned long long __b);
#define __nvvm_atom_max_g_ull(P0, P1) \
    __coverity___nvvm_atom_max_g_ull((P0), (P1))

extern int
__coverity___nvvm_atom_max_s_i(
    volatile int* __a,
    int __b);
#define __nvvm_atom_max_s_i(P0, P1) \
    __coverity___nvvm_atom_max_s_i((P0), (P1))

extern long
__coverity___nvvm_atom_max_s_l(
    volatile long* __a,
    long __b);
#define __nvvm_atom_max_s_l(P0, P1) \
    __coverity___nvvm_atom_max_s_l((P0), (P1))

extern long long
__coverity___nvvm_atom_max_s_ll(
    volatile long long* __a,
    long long __b);
#define __nvvm_atom_max_s_ll(P0, P1) \
    __coverity___nvvm_atom_max_s_ll((P0), (P1))

extern unsigned int
__coverity___nvvm_atom_max_s_ui(
    volatile unsigned int* __a,
    unsigned int __b);
#define __nvvm_atom_max_s_ui(P0, P1) \
    __coverity___nvvm_atom_max_s_ui((P0), (P1))

extern unsigned long
__coverity___nvvm_atom_max_s_ul(
    volatile unsigned long* __a,
    unsigned long __b);
#define __nvvm_atom_max_s_ul(P0, P1) \
    __coverity___nvvm_atom_max_s_ul((P0), (P1))

extern unsigned long long
__coverity___nvvm_atom_max_s_ull(
    volatile unsigned long long* __a,
    unsigned long long __b);
#define __nvvm_atom_max_s_ull(P0, P1) \
    __coverity___nvvm_atom_max_s_ull((P0), (P1))

extern int
__coverity___nvvm_atom_min_g_i(
    volatile int* __a,
    int __b);
#define __nvvm_atom_min_g_i(P0, P1) \
    __coverity___nvvm_atom_min_g_i((P0), (P1))

extern long
__coverity___nvvm_atom_min_g_l(
    volatile long* __a,
    long __b);
#define __nvvm_atom_min_g_l(P0, P1) \
    __coverity___nvvm_atom_min_g_l((P0), (P1))

extern long long
__coverity___nvvm_atom_min_g_ll(
    volatile long long* __a,
    long long __b);
#define __nvvm_atom_min_g_ll(P0, P1) \
    __coverity___nvvm_atom_min_g_ll((P0), (P1))

extern unsigned int
__coverity___nvvm_atom_min_g_ui(
    volatile unsigned int* __a,
    unsigned int __b);
#define __nvvm_atom_min_g_ui(P0, P1) \
    __coverity___nvvm_atom_min_g_ui((P0), (P1))

extern unsigned long
__coverity___nvvm_atom_min_g_ul(
    volatile unsigned long* __a,
    unsigned long __b);
#define __nvvm_atom_min_g_ul(P0, P1) \
    __coverity___nvvm_atom_min_g_ul((P0), (P1))

extern unsigned long long
__coverity___nvvm_atom_min_g_ull(
    volatile unsigned long long* __a,
    unsigned long long __b);
#define __nvvm_atom_min_g_ull(P0, P1) \
    __coverity___nvvm_atom_min_g_ull((P0), (P1))

extern int
__coverity___nvvm_atom_min_s_i(
    volatile int* __a,
    int __b);
#define __nvvm_atom_min_s_i(P0, P1) \
    __coverity___nvvm_atom_min_s_i((P0), (P1))

extern long
__coverity___nvvm_atom_min_s_l(
    volatile long* __a,
    long __b);
#define __nvvm_atom_min_s_l(P0, P1) \
    __coverity___nvvm_atom_min_s_l((P0), (P1))

extern long long
__coverity___nvvm_atom_min_s_ll(
    volatile long long* __a,
    long long __b);
#define __nvvm_atom_min_s_ll(P0, P1) \
    __coverity___nvvm_atom_min_s_ll((P0), (P1))

extern unsigned int
__coverity___nvvm_atom_min_s_ui(
    volatile unsigned int* __a,
    unsigned int __b);
#define __nvvm_atom_min_s_ui(P0, P1) \
    __coverity___nvvm_atom_min_s_ui((P0), (P1))

extern unsigned long
__coverity___nvvm_atom_min_s_ul(
    volatile unsigned long* __a,
    unsigned long __b);
#define __nvvm_atom_min_s_ul(P0, P1) \
    __coverity___nvvm_atom_min_s_ul((P0), (P1))

extern unsigned long long
__coverity___nvvm_atom_min_s_ull(
    volatile unsigned long long* __a,
    unsigned long long __b);
#define __nvvm_atom_min_s_ull(P0, P1) \
    __coverity___nvvm_atom_min_s_ull((P0), (P1))

extern int
__coverity___nvvm_atom_or_g_i(
    volatile int* __a,
    int __b);
#define __nvvm_atom_or_g_i(P0, P1) \
    __coverity___nvvm_atom_or_g_i((P0), (P1))

extern long
__coverity___nvvm_atom_or_g_l(
    volatile long* __a,
    long __b);
#define __nvvm_atom_or_g_l(P0, P1) \
    __coverity___nvvm_atom_or_g_l((P0), (P1))

extern long long
__coverity___nvvm_atom_or_g_ll(
    volatile long long* __a,
    long long __b);
#define __nvvm_atom_or_g_ll(P0, P1) \
    __coverity___nvvm_atom_or_g_ll((P0), (P1))

extern int
__coverity___nvvm_atom_or_s_i(
    volatile int* __a,
    int __b);
#define __nvvm_atom_or_s_i(P0, P1) \
    __coverity___nvvm_atom_or_s_i((P0), (P1))

extern long
__coverity___nvvm_atom_or_s_l(
    volatile long* __a,
    long __b);
#define __nvvm_atom_or_s_l(P0, P1) \
    __coverity___nvvm_atom_or_s_l((P0), (P1))

extern long long
__coverity___nvvm_atom_or_s_ll(
    volatile long long* __a,
    long long __b);
#define __nvvm_atom_or_s_ll(P0, P1) \
    __coverity___nvvm_atom_or_s_ll((P0), (P1))

extern int
__coverity___nvvm_atom_sub_g_i(
    volatile int* __a,
    int __b);
#define __nvvm_atom_sub_g_i(P0, P1) \
    __coverity___nvvm_atom_sub_g_i((P0), (P1))

extern long
__coverity___nvvm_atom_sub_g_l(
    volatile long* __a,
    long __b);
#define __nvvm_atom_sub_g_l(P0, P1) \
    __coverity___nvvm_atom_sub_g_l((P0), (P1))

extern long long
__coverity___nvvm_atom_sub_g_ll(
    volatile long long* __a,
    long long __b);
#define __nvvm_atom_sub_g_ll(P0, P1) \
    __coverity___nvvm_atom_sub_g_ll((P0), (P1))

extern int
__coverity___nvvm_atom_sub_s_i(
    volatile int* __a,
    int __b);
#define __nvvm_atom_sub_s_i(P0, P1) \
    __coverity___nvvm_atom_sub_s_i((P0), (P1))

extern long
__coverity___nvvm_atom_sub_s_l(
    volatile long* __a,
    long __b);
#define __nvvm_atom_sub_s_l(P0, P1) \
    __coverity___nvvm_atom_sub_s_l((P0), (P1))

extern long long
__coverity___nvvm_atom_sub_s_ll(
    volatile long long* __a,
    long long __b);
#define __nvvm_atom_sub_s_ll(P0, P1) \
    __coverity___nvvm_atom_sub_s_ll((P0), (P1))

extern int
__coverity___nvvm_atom_xchg_g_i(
    volatile int* __a,
    int __b);
#define __nvvm_atom_xchg_g_i(P0, P1) \
    __coverity___nvvm_atom_xchg_g_i((P0), (P1))

extern long
__coverity___nvvm_atom_xchg_g_l(
    volatile long* __a,
    long __b);
#define __nvvm_atom_xchg_g_l(P0, P1) \
    __coverity___nvvm_atom_xchg_g_l((P0), (P1))

extern long long
__coverity___nvvm_atom_xchg_g_ll(
    volatile long long* __a,
    long long __b);
#define __nvvm_atom_xchg_g_ll(P0, P1) \
    __coverity___nvvm_atom_xchg_g_ll((P0), (P1))

extern int
__coverity___nvvm_atom_xchg_s_i(
    volatile int* __a,
    int __b);
#define __nvvm_atom_xchg_s_i(P0, P1) \
    __coverity___nvvm_atom_xchg_s_i((P0), (P1))

extern long
__coverity___nvvm_atom_xchg_s_l(
    volatile long* __a,
    long __b);
#define __nvvm_atom_xchg_s_l(P0, P1) \
    __coverity___nvvm_atom_xchg_s_l((P0), (P1))

extern long long
__coverity___nvvm_atom_xchg_s_ll(
    volatile long long* __a,
    long long __b);
#define __nvvm_atom_xchg_s_ll(P0, P1) \
    __coverity___nvvm_atom_xchg_s_ll((P0), (P1))

extern int
__coverity___nvvm_atom_xor_g_i(
    volatile int* __a,
    int __b);
#define __nvvm_atom_xor_g_i(P0, P1) \
    __coverity___nvvm_atom_xor_g_i((P0), (P1))

extern long
__coverity___nvvm_atom_xor_g_l(
    volatile long* __a,
    long __b);
#define __nvvm_atom_xor_g_l(P0, P1) \
    __coverity___nvvm_atom_xor_g_l((P0), (P1))

extern long long
__coverity___nvvm_atom_xor_g_ll(
    volatile long long* __a,
    long long __b);
#define __nvvm_atom_xor_g_ll(P0, P1) \
    __coverity___nvvm_atom_xor_g_ll((P0), (P1))

extern int
__coverity___nvvm_atom_xor_s_i(
    volatile int* __a,
    int __b);
#define __nvvm_atom_xor_s_i(P0, P1) \
    __coverity___nvvm_atom_xor_s_i((P0), (P1))

extern long
__coverity___nvvm_atom_xor_s_l(
    volatile long* __a,
    long __b);
#define __nvvm_atom_xor_s_l(P0, P1) \
    __coverity___nvvm_atom_xor_s_l((P0), (P1))

extern long long
__coverity___nvvm_atom_xor_s_ll(
    volatile long long* __a,
    long long __b);
#define __nvvm_atom_xor_s_ll(P0, P1) \
    __coverity___nvvm_atom_xor_s_ll((P0), (P1))

/* } Removed in Clang 7.0 */
#endif // clang < 7.0

// XCode 10 - No changes from Clang 6


/*************************************
 ************ Clang 8.0 **************
 *************************************/

#if (__cov_clang_version_lt(8, 0)) /* { */

/* Signatures changed in Clang 8.0 { */

/* Clang 8 updated the signatures of many builtins, but an audit found no
 * changes that were likely to break existing callers.  The changes fell into
 * a few categories:
 *   1) Changing a void return type to non-void.
 *   2) Changing a pointer to non-void type to pointer to void.
 *   3) Adding address space qualification to pointer types.
 *   4) Marking parameters as requiring constant expression arguments.
 */

/* } Changed in Clang 8.0 */

/* Removed in Clang 8.0 { */

extern int
__coverity___builtin_HEXAGON_A6_vcmpbeq_notany_128B(
    long long int __a,
    long long int __b);
#define __builtin_HEXAGON_A6_vcmpbeq_notany_128B(P0, P1) \
    __coverity___builtin_HEXAGON_A6_vcmpbeq_notany_128B((P0), (P1))

extern long long int
__coverity___builtin_HEXAGON_S2_cabacencbin(
    long long int __a,
    long long int __b,
    int __c);
#define __builtin_HEXAGON_S2_cabacencbin(P0, P1, P2) \
    __coverity___builtin_HEXAGON_S2_cabacencbin((P0), (P1), (P2))

extern void
__coverity___builtin_eni(
    int __a);
#define __builtin_eni(P0) \
    __coverity___builtin_eni((P0))

extern void
__coverity___builtin_flushd(
    volatile void* __a);
#define __builtin_flushd(P0) \
    __coverity___builtin_flushd((P0))

extern void
__coverity___builtin_flushda(
    volatile void* __a);
#define __builtin_flushda(P0) \
    __coverity___builtin_flushda((P0))

extern unsigned char
__coverity___builtin_ia32_addcarry_u32(
    unsigned char __a,
    unsigned int __b,
    unsigned int __c,
    unsigned int* __d);
#define __builtin_ia32_addcarry_u32(P0, P1, P2, P3) \
    __coverity___builtin_ia32_addcarry_u32((P0), (P1), (P2), (P3))

extern unsigned char
__coverity___builtin_ia32_addcarry_u64(
    unsigned char __a,
    unsigned long long int __b,
    unsigned long long int __c,
    unsigned long long int* __d);
#define __builtin_ia32_addcarry_u64(P0, P1, P2, P3) \
    __coverity___builtin_ia32_addcarry_u64((P0), (P1), (P2), (P3))

extern char __attribute__((vector_size(64)))
__coverity___builtin_ia32_paddsb512_mask(
    char __attribute__((vector_size(64))) __a,
    char __attribute__((vector_size(64))) __b,
    char __attribute__((vector_size(64))) __c,
    unsigned long long int __d);
#define __builtin_ia32_paddsb512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_paddsb512_mask((P0), (P1), (P2), (P3))

extern short __attribute__((vector_size(64)))
__coverity___builtin_ia32_paddsw512_mask(
    short __attribute__((vector_size(64))) __a,
    short __attribute__((vector_size(64))) __b,
    short __attribute__((vector_size(64))) __c,
    unsigned int __d);
#define __builtin_ia32_paddsw512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_paddsw512_mask((P0), (P1), (P2), (P3))

extern char __attribute__((vector_size(64)))
__coverity___builtin_ia32_paddusb512_mask(
    char __attribute__((vector_size(64))) __a,
    char __attribute__((vector_size(64))) __b,
    char __attribute__((vector_size(64))) __c,
    unsigned long long int __d);
#define __builtin_ia32_paddusb512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_paddusb512_mask((P0), (P1), (P2), (P3))

extern short __attribute__((vector_size(64)))
__coverity___builtin_ia32_paddusw512_mask(
    short __attribute__((vector_size(64))) __a,
    short __attribute__((vector_size(64))) __b,
    short __attribute__((vector_size(64))) __c,
    unsigned int __d);
#define __builtin_ia32_paddusw512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_paddusw512_mask((P0), (P1), (P2), (P3))

extern char __attribute__((vector_size(64)))
__coverity___builtin_ia32_psubsb512_mask(
    char __attribute__((vector_size(64))) __a,
    char __attribute__((vector_size(64))) __b,
    char __attribute__((vector_size(64))) __c,
    unsigned long long int __d);
#define __builtin_ia32_psubsb512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psubsb512_mask((P0), (P1), (P2), (P3))

extern short __attribute__((vector_size(64)))
__coverity___builtin_ia32_psubsw512_mask(
    short __attribute__((vector_size(64))) __a,
    short __attribute__((vector_size(64))) __b,
    short __attribute__((vector_size(64))) __c,
    unsigned int __d);
#define __builtin_ia32_psubsw512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psubsw512_mask((P0), (P1), (P2), (P3))

extern char __attribute__((vector_size(64)))
__coverity___builtin_ia32_psubusb512_mask(
    char __attribute__((vector_size(64))) __a,
    char __attribute__((vector_size(64))) __b,
    char __attribute__((vector_size(64))) __c,
    unsigned long long int __d);
#define __builtin_ia32_psubusb512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psubusb512_mask((P0), (P1), (P2), (P3))

extern short __attribute__((vector_size(64)))
__coverity___builtin_ia32_psubusw512_mask(
    short __attribute__((vector_size(64))) __a,
    short __attribute__((vector_size(64))) __b,
    short __attribute__((vector_size(64))) __c,
    unsigned int __d);
#define __builtin_ia32_psubusw512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_psubusw512_mask((P0), (P1), (P2), (P3))

extern char __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpmultishiftqb128_mask(
    char __attribute__((vector_size(16))) __a,
    char __attribute__((vector_size(16))) __b,
    char __attribute__((vector_size(16))) __c,
    unsigned short __d);
#define __builtin_ia32_vpmultishiftqb128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpmultishiftqb128_mask((P0), (P1), (P2), (P3))

extern char __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpmultishiftqb256_mask(
    char __attribute__((vector_size(32))) __a,
    char __attribute__((vector_size(32))) __b,
    char __attribute__((vector_size(32))) __c,
    unsigned int __d);
#define __builtin_ia32_vpmultishiftqb256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpmultishiftqb256_mask((P0), (P1), (P2), (P3))

extern char __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpmultishiftqb512_mask(
    char __attribute__((vector_size(64))) __a,
    char __attribute__((vector_size(64))) __b,
    char __attribute__((vector_size(64))) __c,
    unsigned long long int __d);
#define __builtin_ia32_vpmultishiftqb512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpmultishiftqb512_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpshldvd128_mask(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    int __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vpshldvd128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpshldvd128_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpshldvd128_maskz(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    int __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vpshldvd128_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpshldvd128_maskz((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpshldvd256_mask(
    int __attribute__((vector_size(32))) __a,
    int __attribute__((vector_size(32))) __b,
    int __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vpshldvd256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpshldvd256_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpshldvd256_maskz(
    int __attribute__((vector_size(32))) __a,
    int __attribute__((vector_size(32))) __b,
    int __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vpshldvd256_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpshldvd256_maskz((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpshldvd512_mask(
    int __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    int __attribute__((vector_size(64))) __c,
    unsigned short __d);
#define __builtin_ia32_vpshldvd512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpshldvd512_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpshldvd512_maskz(
    int __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    int __attribute__((vector_size(64))) __c,
    unsigned short __d);
#define __builtin_ia32_vpshldvd512_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpshldvd512_maskz((P0), (P1), (P2), (P3))

extern long long int __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpshldvq128_mask(
    long long int __attribute__((vector_size(16))) __a,
    long long int __attribute__((vector_size(16))) __b,
    long long int __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vpshldvq128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpshldvq128_mask((P0), (P1), (P2), (P3))

extern long long int __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpshldvq128_maskz(
    long long int __attribute__((vector_size(16))) __a,
    long long int __attribute__((vector_size(16))) __b,
    long long int __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vpshldvq128_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpshldvq128_maskz((P0), (P1), (P2), (P3))

extern long long int __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpshldvq256_mask(
    long long int __attribute__((vector_size(32))) __a,
    long long int __attribute__((vector_size(32))) __b,
    long long int __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vpshldvq256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpshldvq256_mask((P0), (P1), (P2), (P3))

extern long long int __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpshldvq256_maskz(
    long long int __attribute__((vector_size(32))) __a,
    long long int __attribute__((vector_size(32))) __b,
    long long int __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vpshldvq256_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpshldvq256_maskz((P0), (P1), (P2), (P3))

extern long long int __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpshldvq512_mask(
    long long int __attribute__((vector_size(64))) __a,
    long long int __attribute__((vector_size(64))) __b,
    long long int __attribute__((vector_size(64))) __c,
    unsigned char __d);
#define __builtin_ia32_vpshldvq512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpshldvq512_mask((P0), (P1), (P2), (P3))

extern long long int __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpshldvq512_maskz(
    long long int __attribute__((vector_size(64))) __a,
    long long int __attribute__((vector_size(64))) __b,
    long long int __attribute__((vector_size(64))) __c,
    unsigned char __d);
#define __builtin_ia32_vpshldvq512_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpshldvq512_maskz((P0), (P1), (P2), (P3))

extern short __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpshldvw128_mask(
    short __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b,
    short __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vpshldvw128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpshldvw128_mask((P0), (P1), (P2), (P3))

extern short __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpshldvw128_maskz(
    short __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b,
    short __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vpshldvw128_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpshldvw128_maskz((P0), (P1), (P2), (P3))

extern short __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpshldvw256_mask(
    short __attribute__((vector_size(32))) __a,
    short __attribute__((vector_size(32))) __b,
    short __attribute__((vector_size(32))) __c,
    unsigned short __d);
#define __builtin_ia32_vpshldvw256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpshldvw256_mask((P0), (P1), (P2), (P3))

extern short __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpshldvw256_maskz(
    short __attribute__((vector_size(32))) __a,
    short __attribute__((vector_size(32))) __b,
    short __attribute__((vector_size(32))) __c,
    unsigned short __d);
#define __builtin_ia32_vpshldvw256_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpshldvw256_maskz((P0), (P1), (P2), (P3))

extern short __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpshldvw512_mask(
    short __attribute__((vector_size(64))) __a,
    short __attribute__((vector_size(64))) __b,
    short __attribute__((vector_size(64))) __c,
    unsigned int __d);
#define __builtin_ia32_vpshldvw512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpshldvw512_mask((P0), (P1), (P2), (P3))

extern short __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpshldvw512_maskz(
    short __attribute__((vector_size(64))) __a,
    short __attribute__((vector_size(64))) __b,
    short __attribute__((vector_size(64))) __c,
    unsigned int __d);
#define __builtin_ia32_vpshldvw512_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpshldvw512_maskz((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpshrdvd128_mask(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    int __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vpshrdvd128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpshrdvd128_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpshrdvd128_maskz(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    int __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vpshrdvd128_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpshrdvd128_maskz((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpshrdvd256_mask(
    int __attribute__((vector_size(32))) __a,
    int __attribute__((vector_size(32))) __b,
    int __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vpshrdvd256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpshrdvd256_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpshrdvd256_maskz(
    int __attribute__((vector_size(32))) __a,
    int __attribute__((vector_size(32))) __b,
    int __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vpshrdvd256_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpshrdvd256_maskz((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpshrdvd512_mask(
    int __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    int __attribute__((vector_size(64))) __c,
    unsigned short __d);
#define __builtin_ia32_vpshrdvd512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpshrdvd512_mask((P0), (P1), (P2), (P3))

extern int __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpshrdvd512_maskz(
    int __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    int __attribute__((vector_size(64))) __c,
    unsigned short __d);
#define __builtin_ia32_vpshrdvd512_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpshrdvd512_maskz((P0), (P1), (P2), (P3))

extern long long int __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpshrdvq128_mask(
    long long int __attribute__((vector_size(16))) __a,
    long long int __attribute__((vector_size(16))) __b,
    long long int __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vpshrdvq128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpshrdvq128_mask((P0), (P1), (P2), (P3))

extern long long int __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpshrdvq128_maskz(
    long long int __attribute__((vector_size(16))) __a,
    long long int __attribute__((vector_size(16))) __b,
    long long int __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vpshrdvq128_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpshrdvq128_maskz((P0), (P1), (P2), (P3))

extern long long int __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpshrdvq256_mask(
    long long int __attribute__((vector_size(32))) __a,
    long long int __attribute__((vector_size(32))) __b,
    long long int __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vpshrdvq256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpshrdvq256_mask((P0), (P1), (P2), (P3))

extern long long int __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpshrdvq256_maskz(
    long long int __attribute__((vector_size(32))) __a,
    long long int __attribute__((vector_size(32))) __b,
    long long int __attribute__((vector_size(32))) __c,
    unsigned char __d);
#define __builtin_ia32_vpshrdvq256_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpshrdvq256_maskz((P0), (P1), (P2), (P3))

extern long long int __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpshrdvq512_mask(
    long long int __attribute__((vector_size(64))) __a,
    long long int __attribute__((vector_size(64))) __b,
    long long int __attribute__((vector_size(64))) __c,
    unsigned char __d);
#define __builtin_ia32_vpshrdvq512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpshrdvq512_mask((P0), (P1), (P2), (P3))

extern long long int __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpshrdvq512_maskz(
    long long int __attribute__((vector_size(64))) __a,
    long long int __attribute__((vector_size(64))) __b,
    long long int __attribute__((vector_size(64))) __c,
    unsigned char __d);
#define __builtin_ia32_vpshrdvq512_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpshrdvq512_maskz((P0), (P1), (P2), (P3))

extern short __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpshrdvw128_mask(
    short __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b,
    short __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vpshrdvw128_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpshrdvw128_mask((P0), (P1), (P2), (P3))

extern short __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpshrdvw128_maskz(
    short __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b,
    short __attribute__((vector_size(16))) __c,
    unsigned char __d);
#define __builtin_ia32_vpshrdvw128_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpshrdvw128_maskz((P0), (P1), (P2), (P3))

extern short __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpshrdvw256_mask(
    short __attribute__((vector_size(32))) __a,
    short __attribute__((vector_size(32))) __b,
    short __attribute__((vector_size(32))) __c,
    unsigned short __d);
#define __builtin_ia32_vpshrdvw256_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpshrdvw256_mask((P0), (P1), (P2), (P3))

extern short __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpshrdvw256_maskz(
    short __attribute__((vector_size(32))) __a,
    short __attribute__((vector_size(32))) __b,
    short __attribute__((vector_size(32))) __c,
    unsigned short __d);
#define __builtin_ia32_vpshrdvw256_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpshrdvw256_maskz((P0), (P1), (P2), (P3))

extern short __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpshrdvw512_mask(
    short __attribute__((vector_size(64))) __a,
    short __attribute__((vector_size(64))) __b,
    short __attribute__((vector_size(64))) __c,
    unsigned int __d);
#define __builtin_ia32_vpshrdvw512_mask(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpshrdvw512_mask((P0), (P1), (P2), (P3))

extern short __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpshrdvw512_maskz(
    short __attribute__((vector_size(64))) __a,
    short __attribute__((vector_size(64))) __b,
    short __attribute__((vector_size(64))) __c,
    unsigned int __d);
#define __builtin_ia32_vpshrdvw512_maskz(P0, P1, P2, P3) \
    __coverity___builtin_ia32_vpshrdvw512_maskz((P0), (P1), (P2), (P3))

extern int
__coverity___builtin_ldbio(
    const volatile void* __a);
#define __builtin_ldbio(P0) \
    __coverity___builtin_ldbio((P0))

extern int
__coverity___builtin_ldbuio(
    const volatile void* __a);
#define __builtin_ldbuio(P0) \
    __coverity___builtin_ldbuio((P0))

extern int
__coverity___builtin_ldex(
    const volatile void* __a);
#define __builtin_ldex(P0) \
    __coverity___builtin_ldex((P0))

extern int
__coverity___builtin_ldhio(
    const volatile void* __a);
#define __builtin_ldhio(P0) \
    __coverity___builtin_ldhio((P0))

extern int
__coverity___builtin_ldhuio(
    const volatile void* __a);
#define __builtin_ldhuio(P0) \
    __coverity___builtin_ldhuio((P0))

extern int
__coverity___builtin_ldsex(
    const volatile void* __a);
#define __builtin_ldsex(P0) \
    __coverity___builtin_ldsex((P0))

extern int
__coverity___builtin_ldwio(
    const volatile void* __a);
#define __builtin_ldwio(P0) \
    __coverity___builtin_ldwio((P0))

extern int
__coverity___builtin_ldwuio(
    int __a);
#define __builtin_ldwuio(P0) \
    __coverity___builtin_ldwuio((P0))

extern int
__coverity___builtin_rdctl(
    int __a);
#define __builtin_rdctl(P0) \
    __coverity___builtin_rdctl((P0))

extern int
__coverity___builtin_rdprs(
    int __a,
    int __b);
#define __builtin_rdprs(P0, P1) \
    __coverity___builtin_rdprs((P0), (P1))

extern void
__coverity___builtin_stbio(
    volatile void* __a,
    int __b);
#define __builtin_stbio(P0, P1) \
    __coverity___builtin_stbio((P0), (P1))

extern int
__coverity___builtin_stex(
    volatile void* __a,
    int __b);
#define __builtin_stex(P0, P1) \
    __coverity___builtin_stex((P0), (P1))

extern void
__coverity___builtin_sthio(
    volatile void* __a,
    int __b);
#define __builtin_sthio(P0, P1) \
    __coverity___builtin_sthio((P0), (P1))

extern int
__coverity___builtin_stsex(
    const volatile void* __a,
    int __b);
#define __builtin_stsex(P0, P1) \
    __coverity___builtin_stsex((P0), (P1))

extern void
__coverity___builtin_stwio(
    volatile void* __a,
    int __b);
#define __builtin_stwio(P0, P1) \
    __coverity___builtin_stwio((P0), (P1))

extern void
__coverity___builtin_sync();
#define __builtin_sync() \
    __coverity___builtin_sync()

extern __cov_compat_size_t
__coverity___builtin_wasm_current_memory();
#define __builtin_wasm_current_memory() \
    __coverity___builtin_wasm_current_memory()

extern __cov_compat_size_t
__coverity___builtin_wasm_grow_memory(
    __cov_compat_size_t __a);
#define __builtin_wasm_grow_memory(P0) \
    __coverity___builtin_wasm_grow_memory((P0))

extern __cov_compat_size_t
__coverity___builtin_wasm_mem_grow(
    int __a,
    __cov_compat_size_t __b);
#define __builtin_wasm_mem_grow(P0, P1) \
    __coverity___builtin_wasm_mem_grow((P0), (P1))

extern __cov_compat_size_t
__coverity___builtin_wasm_mem_size(
    int __a);
#define __builtin_wasm_mem_size(P0) \
    __coverity___builtin_wasm_mem_size((P0))

extern void
__coverity___builtin_wrctl(
    int __a,
    int __b);
#define __builtin_wrctl(P0, P1) \
    __coverity___builtin_wrctl((P0), (P1))

extern int
__coverity___builtin_wrpie(
    int __a);
#define __builtin_wrpie(P0) \
    __coverity___builtin_wrpie((P0))

/* } Removed in Clang 8.0 */
#endif // clang < 8.0


/*************************************
 ************ Clang 9.0 **************
 *************************************/

#if (__cov_clang_version_lt(9, 0)) /* { */

/* Signatures changed in Clang 9.0 { */

/* Clang 9 updated the signatures of many builtins, but an audit found no
 * changes that were likely to break existing callers.  The changes fell into
 * a few categories:
 *   1) Introduction of 'O' specifier to deal with different integer sizes on OpenCL.
 *   2) Introduction of 'Z' specifier to represent a fixed-width 32-bit integer.
 */

extern unsigned int
__coverity___builtin_bitreverse32(
    unsigned int __a);
#define __builtin_bitreverse32(P0) \
    __coverity___builtin_bitreverse32((P0))

extern unsigned int
__coverity___builtin_bswap32(
    unsigned int __a);
#define __builtin_bswap32(P0) \
    __coverity___builtin_bswap32((P0))

extern unsigned int
__coverity___builtin_rotateleft32(
    unsigned int __a,
    unsigned int __b);
#define __builtin_rotateleft32(P0, P1) \
    __coverity___builtin_rotateleft32((P0), (P1))

extern unsigned int
__coverity___builtin_rotateright32(
    unsigned int __a,
    unsigned int __b);
#define __builtin_rotateright32(P0, P1) \
    __coverity___builtin_rotateright32((P0), (P1))

extern int
__coverity___builtin_bcmp(
    void* __a,
    void* __b,
    __cov_compat_size_t __c);
#define __builtin_bcmp(P0, P1, P2) \
    __coverity___builtin_bcmp((P0), (P1), (P2))

extern unsigned long long
__coverity___builtin_neon_vsqaddd_u64(
    unsigned long long __a,
    unsigned long long __b);
#define __builtin_neon_vsqaddd_u64(P0, P1) \
    __coverity___builtin_neon_vsqaddd_u64((P0), (P1))

extern unsigned short
__coverity___builtin_neon_vsqaddh_u16(
    unsigned short __a,
    unsigned short __b);
#define __builtin_neon_vsqaddh_u16(P0, P1) \
    __coverity___builtin_neon_vsqaddh_u16((P0), (P1))

extern unsigned int
__coverity___builtin_neon_vsqadds_u32(
    unsigned int __a,
    unsigned int __b);
#define __builtin_neon_vsqadds_u32(P0, P1) \
    __coverity___builtin_neon_vsqadds_u32((P0), (P1))

extern long long
__coverity___builtin_neon_vuqaddd_s64(
    long long __a,
    long long __b);
#define __builtin_neon_vuqaddd_s64(P0, P1) \
    __coverity___builtin_neon_vuqaddd_s64((P0), (P1))

extern short
__coverity___builtin_neon_vuqaddh_s16(
    short __a,
    short __b);
#define __builtin_neon_vuqaddh_s16(P0, P1) \
    __coverity___builtin_neon_vuqaddh_s16((P0), (P1))

extern int
__coverity___builtin_neon_vuqadds_s32(
    int __a,
    int __b);
#define __builtin_neon_vuqadds_s32(P0, P1) \
    __coverity___builtin_neon_vuqadds_s32((P0), (P1))

extern void
__coverity___builtin_wasm_throw(
    unsigned int __a,
    void* __b);
#define __builtin_wasm_throw(P0, P1) \
    __coverity___builtin_wasm_throw((P0), (P1))

/* } Changed in Clang 9.0 */

/* Removed in Clang 9.0 { */

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_cvtqq2ps256_mask(
    long long __attribute__((vector_size(32))) __a,
    float __attribute__((vector_size(16))) __b,
    unsigned char __c);
#define __builtin_ia32_cvtqq2ps256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_cvtqq2ps256_mask((P0), (P1), (P2))

extern float __attribute__((vector_size(16)))
__coverity___builtin_ia32_cvtuqq2ps256_mask(
    long long __attribute__((vector_size(32))) __a,
    float __attribute__((vector_size(16))) __b,
    unsigned char __c);
#define __builtin_ia32_cvtuqq2ps256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_cvtuqq2ps256_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpconflictdi_128_mask(
    long long __attribute__((vector_size(16))) __a,
    long long __attribute__((vector_size(16))) __b,
    unsigned char __c);
#define __builtin_ia32_vpconflictdi_128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_vpconflictdi_128_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpconflictdi_256_mask(
    long long __attribute__((vector_size(32))) __a,
    long long __attribute__((vector_size(32))) __b,
    unsigned char __c);
#define __builtin_ia32_vpconflictdi_256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_vpconflictdi_256_mask((P0), (P1), (P2))

extern long long __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpconflictdi_512_mask(
    long long __attribute__((vector_size(64))) __a,
    long long __attribute__((vector_size(64))) __b,
    unsigned char __c);
#define __builtin_ia32_vpconflictdi_512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_vpconflictdi_512_mask((P0), (P1), (P2))

extern int __attribute__((vector_size(16)))
__coverity___builtin_ia32_vpconflictsi_128_mask(
    int __attribute__((vector_size(16))) __a,
    int __attribute__((vector_size(16))) __b,
    unsigned char __c);
#define __builtin_ia32_vpconflictsi_128_mask(P0, P1, P2) \
    __coverity___builtin_ia32_vpconflictsi_128_mask((P0), (P1), (P2))

extern int __attribute__((vector_size(32)))
__coverity___builtin_ia32_vpconflictsi_256_mask(
    int __attribute__((vector_size(32))) __a,
    int __attribute__((vector_size(32))) __b,
    unsigned char __c);
#define __builtin_ia32_vpconflictsi_256_mask(P0, P1, P2) \
    __coverity___builtin_ia32_vpconflictsi_256_mask((P0), (P1), (P2))

extern int __attribute__((vector_size(64)))
__coverity___builtin_ia32_vpconflictsi_512_mask(
    int __attribute__((vector_size(64))) __a,
    int __attribute__((vector_size(64))) __b,
    unsigned short __c);
#define __builtin_ia32_vpconflictsi_512_mask(P0, P1, P2) \
    __coverity___builtin_ia32_vpconflictsi_512_mask((P0), (P1), (P2))

extern void
__coverity___builtin_wasm_rethrow(
);
#define __builtin_wasm_rethrow() \
    __coverity___builtin_wasm_rethrow()

/* } Removed in Clang 9.0 */
#endif // clang < 9.0

#if (__cov_clang_version_lt(9, 0) ) || \
    ( __coverity_assume_xcode__ && __cov_clang_version_lt(11, 0) ) || \
    (__coverity_assume_android__ && __cov_clang_version_lt(11, 0) ) /* { */
/* Removed in Clang 9.0 but kept in apple clang 11.4 until 12.0.5 when it was removed */
/* Similarly Android NDK kept this option longer { */

extern void
__coverity___builtin_ia32_storehps(
    int __attribute__((vector_size(8)))* __a,
    float __attribute__((vector_size(16))) __b);
#define __builtin_ia32_storehps(P0, P1) \
    __coverity___builtin_ia32_storehps((P0), (P1))

extern void
__coverity___builtin_ia32_storelps(
    int __attribute__((vector_size(8)))* __a,
    float __attribute__((vector_size(16))) __b);
#define __builtin_ia32_storelps(P0, P1) \
    __coverity___builtin_ia32_storelps((P0), (P1))

/* } Removed in Clang 9.0 but kept in apple clang */
#endif


/*************************************
 ************ Clang 10.0 *************
 *************************************/

#if (__cov_clang_version_lt(10, 0)) /* { */

/* Signatures changed in Clang 10.0 { */

/* _InterlockedAdd("LiLiD*Li" vs. "NiNiD*Ni") differs only in L vs N specifier (LP64): Not generated */
/* _InterlockedAnd_acq("LiLiD*Li" vs. "NiNiD*Ni") differs only in L vs N specifier (LP64): Not generated */
/* _InterlockedAnd_nf("LiLiD*Li" vs. "NiNiD*Ni") differs only in L vs N specifier (LP64): Not generated */
/* _InterlockedAnd_rel("LiLiD*Li" vs. "NiNiD*Ni") differs only in L vs N specifier (LP64): Not generated */
/* _InterlockedCompareExchange_acq("LiLiD*LiLi" vs. "NiNiD*NiNi") differs only in L vs N specifier (LP64): Not generated */
/* _InterlockedCompareExchange_nf("LiLiD*LiLi" vs. "NiNiD*NiNi") differs only in L vs N specifier (LP64): Not generated */
/* _InterlockedCompareExchange_rel("LiLiD*LiLi" vs. "NiNiD*NiNi") differs only in L vs N specifier (LP64): Not generated */
/* _InterlockedDecrement_acq("LiLiD*" vs. "NiNiD*") differs only in L vs N specifier (LP64): Not generated */
/* _InterlockedDecrement_nf("LiLiD*" vs. "NiNiD*") differs only in L vs N specifier (LP64): Not generated */
/* _InterlockedDecrement_rel("LiLiD*" vs. "NiNiD*") differs only in L vs N specifier (LP64): Not generated */
/* _InterlockedExchangeAdd_acq("LiLiD*Li" vs. "NiNiD*Ni") differs only in L vs N specifier (LP64): Not generated */
/* _InterlockedExchangeAdd_nf("LiLiD*Li" vs. "NiNiD*Ni") differs only in L vs N specifier (LP64): Not generated */
/* _InterlockedExchangeAdd_rel("LiLiD*Li" vs. "NiNiD*Ni") differs only in L vs N specifier (LP64): Not generated */
/* _InterlockedExchange_acq("LiLiD*Li" vs. "NiNiD*Ni") differs only in L vs N specifier (LP64): Not generated */
/* _InterlockedExchange_nf("LiLiD*Li" vs. "NiNiD*Ni") differs only in L vs N specifier (LP64): Not generated */
/* _InterlockedExchange_rel("LiLiD*Li" vs. "NiNiD*Ni") differs only in L vs N specifier (LP64): Not generated */
/* _InterlockedIncrement_acq("LiLiD*" vs. "NiNiD*") differs only in L vs N specifier (LP64): Not generated */
/* _InterlockedIncrement_nf("LiLiD*" vs. "NiNiD*") differs only in L vs N specifier (LP64): Not generated */
/* _InterlockedIncrement_rel("LiLiD*" vs. "NiNiD*") differs only in L vs N specifier (LP64): Not generated */
/* _InterlockedOr_acq("LiLiD*Li" vs. "NiNiD*Ni") differs only in L vs N specifier (LP64): Not generated */
/* _InterlockedOr_nf("LiLiD*Li" vs. "NiNiD*Ni") differs only in L vs N specifier (LP64): Not generated */
/* _InterlockedOr_rel("LiLiD*Li" vs. "NiNiD*Ni") differs only in L vs N specifier (LP64): Not generated */
/* _InterlockedXor_acq("LiLiD*Li" vs. "NiNiD*Ni") differs only in L vs N specifier (LP64): Not generated */
/* _InterlockedXor_nf("LiLiD*Li" vs. "NiNiD*Ni") differs only in L vs N specifier (LP64): Not generated */
/* _InterlockedXor_rel("LiLiD*Li" vs. "NiNiD*Ni") differs only in L vs N specifier (LP64): Not generated */
/* __builtin_altivec_dss("vUi" vs. "vUIi") differs only in constexpr int vs int: Not generated */
/* __builtin_altivec_dst("vvC*iUi" vs. "vvC*iUIi") differs only in constexpr int vs int: Not generated */
/* __builtin_altivec_dstst("vvC*iUi" vs. "vvC*iUIi") differs only in constexpr int vs int: Not generated */
/* __builtin_altivec_dststt("vvC*iUi" vs. "vvC*iUIi") differs only in constexpr int vs int: Not generated */
/* __builtin_altivec_dstt("vvC*iUi" vs. "vvC*iUIi") differs only in constexpr int vs int: Not generated */
/* __builtin_altivec_vcfsx("V4fV4iIi" vs. "V4fV4SiIi") differs only in signed int vs int: Not generated */
/* __builtin_arm_crc32cd("UiUiLLUi" vs. "UiUiWUi") differs only in W(int64_t) vs LL(long long): Not generated */
/* __builtin_arm_crc32cd("UiUiWUi" vs. "UiUiLLUi") differs only in W(int64_t) vs LL(long long): Not generated */
/* __builtin_arm_crc32d("UiUiLLUi" vs. "UiUiWUi") differs only in W(int64_t) vs LL(long long): Not generated */
/* __builtin_arm_crc32d("UiUiWUi" vs. "UiUiLLUi") differs only in W(int64_t) vs LL(long long): Not generated */
/* __builtin_arm_rsr64("LLUicC*" vs. "WUicC*") differs only in W(int64_t) vs LL(long long): Not generated */
/* __builtin_arm_rsr64("WUicC*" vs. "LLUicC*") differs only in W(int64_t) vs LL(long long): Not generated */
/* __builtin_arm_wsr64("vcC*LLUi" vs. "vcC*WUi") differs only in W(int64_t) vs LL(long long): Not generated */
/* __builtin_arm_wsr64("vcC*WUi" vs. "vcC*LLUi") differs only in W(int64_t) vs LL(long long): Not generated */
/* __builtin_ia32_loadapd128_mask("V2dV2d*V2dUc" vs. "V2dV2dC*V2dUc") differs only in const/volatile/restrict qualifiers: Not generated */
/* __builtin_ia32_loadapd256_mask("V4dV4d*V4dUc" vs. "V4dV4dC*V4dUc") differs only in const/volatile/restrict qualifiers: Not generated */
/* __builtin_ia32_loadaps128_mask("V4fV4f*V4fUc" vs. "V4fV4fC*V4fUc") differs only in const/volatile/restrict qualifiers: Not generated */
/* __builtin_ia32_loadaps256_mask("V8fV8f*V8fUc" vs. "V8fV8fC*V8fUc") differs only in const/volatile/restrict qualifiers: Not generated */
/* __builtin_ia32_loaddqudi128_mask("V2OiV2Oi*V2OiUc" vs. "V2OiV2OiC*V2OiUc") differs only in const/volatile/restrict qualifiers: Not generated */
/* __builtin_ia32_loaddqudi256_mask("V4OiV4Oi*V4OiUc" vs. "V4OiV4OiC*V4OiUc") differs only in const/volatile/restrict qualifiers: Not generated */
/* __builtin_ia32_loaddquhi128_mask("V8sV8s*V8sUc" vs. "V8sV8sC*V8sUc") differs only in const/volatile/restrict qualifiers: Not generated */
/* __builtin_ia32_loaddquhi256_mask("V16sV16s*V16sUs" vs. "V16sV16sC*V16sUs") differs only in const/volatile/restrict qualifiers: Not generated */
/* __builtin_ia32_loaddquhi512_mask("V32sV32s*V32sUi" vs. "V32sV32sC*V32sUi") differs only in const/volatile/restrict qualifiers: Not generated */
/* __builtin_ia32_loaddquqi128_mask("V16cV16c*V16cUs" vs. "V16cV16cC*V16cUs") differs only in const/volatile/restrict qualifiers: Not generated */
/* __builtin_ia32_loaddquqi256_mask("V32cV32c*V32cUi" vs. "V32cV32cC*V32cUi") differs only in const/volatile/restrict qualifiers: Not generated */
/* __builtin_ia32_loaddquqi512_mask("V64cV64c*V64cUOi" vs. "V64cV64cC*V64cUOi") differs only in const/volatile/restrict qualifiers: Not generated */
/* __builtin_ia32_loaddqusi128_mask("V4iV4i*V4iUc" vs. "V4iV4iC*V4iUc") differs only in const/volatile/restrict qualifiers: Not generated */
/* __builtin_ia32_loaddqusi256_mask("V8iV8i*V8iUc" vs. "V8iV8iC*V8iUc") differs only in const/volatile/restrict qualifiers: Not generated */
/* __builtin_ia32_loadsd128_mask("V2dV2d*V2dUc" vs. "V2dV2dC*V2dUc") differs only in const/volatile/restrict qualifiers: Not generated */
/* __builtin_ia32_loadss128_mask("V4fV4f*V4fUc" vs. "V4fV4fC*V4fUc") differs only in const/volatile/restrict qualifiers: Not generated */
/* __builtin_ia32_loadupd128_mask("V2dV2d*V2dUc" vs. "V2dV2dC*V2dUc") differs only in const/volatile/restrict qualifiers: Not generated */
/* __builtin_ia32_loadupd256_mask("V4dV4d*V4dUc" vs. "V4dV4dC*V4dUc") differs only in const/volatile/restrict qualifiers: Not generated */
/* __builtin_ia32_loadups128_mask("V4fV4f*V4fUc" vs. "V4fV4fC*V4fUc") differs only in const/volatile/restrict qualifiers: Not generated */
/* __builtin_ia32_loadups256_mask("V8fV8f*V8fUc" vs. "V8fV8fC*V8fUc") differs only in const/volatile/restrict qualifiers: Not generated */
/* __builtin_ia32_lwpins32("UcUiUiUi" vs. "UcUiUiIUi") differs only in constexpr int vs int: Not generated */
/* __builtin_ia32_lwpins64("UcUOiUiUi" vs. "UcUOiUiIUi") differs only in constexpr int vs int: Not generated */
/* __builtin_ia32_lwpval32("vUiUiUi" vs. "vUiUiIUi") differs only in constexpr int vs int: Not generated */
/* __builtin_ia32_lwpval64("vUOiUiUi" vs. "vUOiUiIUi") differs only in constexpr int vs int: Not generated */
/* __builtin_ia32_monitor("vv*UiUi" vs. "vvC*UiUi") differs only in const/volatile/restrict qualifiers: Not generated */
/* __builtin_ia32_monitorx("vv*UiUi" vs. "vvC*UiUi") differs only in const/volatile/restrict qualifiers: Not generated */
/* __builtin_ia32_movdqa32load128_mask("V4iV4i*V4iUc" vs. "V4iV4iC*V4iUc") differs only in const/volatile/restrict qualifiers: Not generated */
/* __builtin_ia32_movdqa32load256_mask("V8iV8i*V8iUc" vs. "V8iV8iC*V8iUc") differs only in const/volatile/restrict qualifiers: Not generated */
/* __builtin_ia32_umonitor("vv*" vs. "vvC*") differs only in const/volatile/restrict qualifiers: Not generated */

extern  float __attribute__((vector_size(16)))
__coverity__builtin_altivec_vcfux(
     int __attribute__((vector_size(16))) __a,
    const int __b,
    int __c);
#define __builtin_altivec_vcfux(P0, P1, P2) \
    __coverity__builtin_altivec_vcfux((P0), (P1), (P2))

#if defined(__ARM_NEON__) || defined(__ARM_NEON) || defined(__AARCH_FEATURE_ADVSIMD) /* { */

extern unsigned short
__coverity__builtin_neon_vaddlv_u8(
    signed char __attribute__((neon_vector_type(8))) __);
#define __builtin_neon_vaddlv_u8(P0) \
    __coverity__builtin_neon_vaddlv_u8((P0))

extern unsigned short
__coverity__builtin_neon_vaddlvq_u8(
    signed char __attribute__((neon_vector_type(16))) __);
#define __builtin_neon_vaddlvq_u8(P0) \
    __coverity__builtin_neon_vaddlvq_u8((P0))

extern signed char
__coverity__builtin_neon_vaddv_u8(
    signed char __attribute__((neon_vector_type(8))) __);
#define __builtin_neon_vaddv_u8(P0) \
    __coverity__builtin_neon_vaddv_u8((P0))

extern signed char
__coverity__builtin_neon_vaddvq_u8(
    signed char __attribute__((neon_vector_type(16))) __);
#define __builtin_neon_vaddvq_u8(P0) \
    __coverity__builtin_neon_vaddvq_u8((P0))

extern  float __attribute__((neon_vector_type(2)))
__coverity__builtin_neon_vcvt_f32_v(
    signed char __attribute__((neon_vector_type(8))) __a,
    int __);
#define __builtin_neon_vcvt_f32_v(P0, P1) \
    __coverity__builtin_neon_vcvt_f32_v((P0), (P1))

extern  __cov_float16_t __attribute__((neon_vector_type(4)))
__coverity__builtin_neon_vcvt_n_f16_v(
    signed char __attribute__((neon_vector_type(8))) __a,
    const int __b,
    int __c,
    int __);
#define __builtin_neon_vcvt_n_f16_v(P0, P1, P2, P3) \
    __coverity__builtin_neon_vcvt_n_f16_v((P0), (P1), (P2), (P3))

extern  float __attribute__((neon_vector_type(2)))
__coverity__builtin_neon_vcvt_n_f32_v(
    signed char __attribute__((neon_vector_type(8))) __a,
    const int __b,
    int __c,
    int __);
#define __builtin_neon_vcvt_n_f32_v(P0, P1, P2, P3) \
    __coverity__builtin_neon_vcvt_n_f32_v((P0), (P1), (P2), (P3))

extern  __cov_float16_t __attribute__((neon_vector_type(8)))
__coverity__builtin_neon_vcvtq_f16_v(
    signed char __attribute__((neon_vector_type(16))) __a,
    int __);
#define __builtin_neon_vcvtq_f16_v(P0, P1) \
    __coverity__builtin_neon_vcvtq_f16_v((P0), (P1))

extern  float __attribute__((neon_vector_type(4)))
__coverity__builtin_neon_vcvtq_f32_v(
    signed char __attribute__((neon_vector_type(16))) __a,
    int __);
#define __builtin_neon_vcvtq_f32_v(P0, P1) \
    __coverity__builtin_neon_vcvtq_f32_v((P0), (P1))

extern  __cov_float16_t __attribute__((neon_vector_type(8)))
__coverity__builtin_neon_vcvtq_n_f16_v(
    signed char __attribute__((neon_vector_type(16))) __a,
    const int __b,
    int __c,
    int __);
#define __builtin_neon_vcvtq_n_f16_v(P0, P1, P2, P3) \
    __coverity__builtin_neon_vcvtq_n_f16_v((P0), (P1), (P2), (P3))

extern  float __attribute__((neon_vector_type(4)))
__coverity__builtin_neon_vcvtq_n_f32_v(
    signed char __attribute__((neon_vector_type(16))) __a,
    const int __b,
    int __c,
    int __);
#define __builtin_neon_vcvtq_n_f32_v(P0, P1, P2, P3) \
    __coverity__builtin_neon_vcvtq_n_f32_v((P0), (P1), (P2), (P3))

extern  float __attribute__((neon_vector_type(2)))
__coverity__builtin_neon_vcvtx_f32_v(
    signed char __attribute__((neon_vector_type(16))) __a,
    int __);
#define __builtin_neon_vcvtx_f32_v(P0, P1) \
    __coverity__builtin_neon_vcvtx_f32_v((P0), (P1))

extern signed char
__coverity__builtin_neon_vdupb_lane_i8(
    signed char __attribute__((neon_vector_type(8))) __a,
    const int __b,
    int __);
#define __builtin_neon_vdupb_lane_i8(P0, P1, P2) \
    __coverity__builtin_neon_vdupb_lane_i8((P0), (P1), (P2))

extern signed char
__coverity__builtin_neon_vdupb_laneq_i8(
    signed char __attribute__((neon_vector_type(16))) __a,
    const int __b,
    int __);
#define __builtin_neon_vdupb_laneq_i8(P0, P1, P2) \
    __coverity__builtin_neon_vdupb_laneq_i8((P0), (P1), (P2))

extern  float __attribute__((neon_vector_type(2)))
__coverity__builtin_neon_vfmlal_high_v(
     float __attribute__((neon_vector_type(2))) __a,
    signed char __attribute__((neon_vector_type(8))) __b,
    signed char __attribute__((neon_vector_type(8))) __c,
    int __);
#define __builtin_neon_vfmlal_high_v(P0, P1, P2, P3) \
    __coverity__builtin_neon_vfmlal_high_v((P0), (P1), (P2), (P3))

extern  float __attribute__((neon_vector_type(2)))
__coverity__builtin_neon_vfmlal_low_v(
     float __attribute__((neon_vector_type(2))) __a,
    signed char __attribute__((neon_vector_type(8))) __b,
    signed char __attribute__((neon_vector_type(8))) __c,
    int __);
#define __builtin_neon_vfmlal_low_v(P0, P1, P2, P3) \
    __coverity__builtin_neon_vfmlal_low_v((P0), (P1), (P2), (P3))

extern  float __attribute__((neon_vector_type(4)))
__coverity__builtin_neon_vfmlalq_high_v(
     float __attribute__((neon_vector_type(4))) __a,
    signed char __attribute__((neon_vector_type(16))) __b,
    signed char __attribute__((neon_vector_type(16))) __c,
    int __);
#define __builtin_neon_vfmlalq_high_v(P0, P1, P2, P3) \
    __coverity__builtin_neon_vfmlalq_high_v((P0), (P1), (P2), (P3))

extern  float __attribute__((neon_vector_type(4)))
__coverity__builtin_neon_vfmlalq_low_v(
     float __attribute__((neon_vector_type(4))) __a,
    signed char __attribute__((neon_vector_type(16))) __b,
    signed char __attribute__((neon_vector_type(16))) __c,
    int __);
#define __builtin_neon_vfmlalq_low_v(P0, P1, P2, P3) \
    __coverity__builtin_neon_vfmlalq_low_v((P0), (P1), (P2), (P3))

extern  float __attribute__((neon_vector_type(2)))
__coverity__builtin_neon_vfmlsl_high_v(
     float __attribute__((neon_vector_type(2))) __a,
    signed char __attribute__((neon_vector_type(8))) __b,
    signed char __attribute__((neon_vector_type(8))) __c,
    int __);
#define __builtin_neon_vfmlsl_high_v(P0, P1, P2, P3) \
    __coverity__builtin_neon_vfmlsl_high_v((P0), (P1), (P2), (P3))

extern  float __attribute__((neon_vector_type(2)))
__coverity__builtin_neon_vfmlsl_low_v(
     float __attribute__((neon_vector_type(2))) __a,
    signed char __attribute__((neon_vector_type(8))) __b,
    signed char __attribute__((neon_vector_type(8))) __c,
    int __);
#define __builtin_neon_vfmlsl_low_v(P0, P1, P2, P3) \
    __coverity__builtin_neon_vfmlsl_low_v((P0), (P1), (P2), (P3))

extern  float __attribute__((neon_vector_type(4)))
__coverity__builtin_neon_vfmlslq_high_v(
     float __attribute__((neon_vector_type(4))) __a,
    signed char __attribute__((neon_vector_type(16))) __b,
    signed char __attribute__((neon_vector_type(16))) __c,
    int __);
#define __builtin_neon_vfmlslq_high_v(P0, P1, P2, P3) \
    __coverity__builtin_neon_vfmlslq_high_v((P0), (P1), (P2), (P3))

extern  float __attribute__((neon_vector_type(4)))
__coverity__builtin_neon_vfmlslq_low_v(
     float __attribute__((neon_vector_type(4))) __a,
    signed char __attribute__((neon_vector_type(16))) __b,
    signed char __attribute__((neon_vector_type(16))) __c,
    int __);
#define __builtin_neon_vfmlslq_low_v(P0, P1, P2, P3) \
    __coverity__builtin_neon_vfmlslq_low_v((P0), (P1), (P2), (P3))

extern signed char
__coverity__builtin_neon_vget_lane_i8(
    signed char __attribute__((neon_vector_type(8))) __a,
    const int __b,
    int __);
#define __builtin_neon_vget_lane_i8(P0, P1, P2) \
    __coverity__builtin_neon_vget_lane_i8((P0), (P1), (P2))

extern signed char
__coverity__builtin_neon_vgetq_lane_i8(
    signed char __attribute__((neon_vector_type(16))) __a,
    const int __b,
    int __);
#define __builtin_neon_vgetq_lane_i8(P0, P1, P2) \
    __coverity__builtin_neon_vgetq_lane_i8((P0), (P1), (P2))

extern signed char
__coverity__builtin_neon_vmaxv_u8(
    signed char __attribute__((neon_vector_type(8))) __);
#define __builtin_neon_vmaxv_u8(P0) \
    __coverity__builtin_neon_vmaxv_u8((P0))

extern signed char
__coverity__builtin_neon_vmaxvq_u8(
    signed char __attribute__((neon_vector_type(16))) __);
#define __builtin_neon_vmaxvq_u8(P0) \
    __coverity__builtin_neon_vmaxvq_u8((P0))

extern signed char
__coverity__builtin_neon_vminv_u8(
    signed char __attribute__((neon_vector_type(8))) __);
#define __builtin_neon_vminv_u8(P0) \
    __coverity__builtin_neon_vminv_u8((P0))

extern signed char
__coverity__builtin_neon_vminvq_u8(
    signed char __attribute__((neon_vector_type(16))) __);
#define __builtin_neon_vminvq_u8(P0) \
    __coverity__builtin_neon_vminvq_u8((P0))

extern signed char
__coverity__builtin_neon_vqaddb_u8(
    signed char __a,
    signed char __);
#define __builtin_neon_vqaddb_u8(P0, P1) \
    __coverity__builtin_neon_vqaddb_u8((P0), (P1))

extern signed char
__coverity__builtin_neon_vqmovnh_u16(
    unsigned short __);
#define __builtin_neon_vqmovnh_u16(P0) \
    __coverity__builtin_neon_vqmovnh_u16((P0))

extern signed char
__coverity__builtin_neon_vqrshlb_u8(
    signed char __a,
    signed char __);
#define __builtin_neon_vqrshlb_u8(P0, P1) \
    __coverity__builtin_neon_vqrshlb_u8((P0), (P1))

extern signed char
__coverity__builtin_neon_vqrshrnh_n_u16(
    unsigned short __a,
    const int __b,
    int __);
#define __builtin_neon_vqrshrnh_n_u16(P0, P1, P2) \
    __coverity__builtin_neon_vqrshrnh_n_u16((P0), (P1), (P2))

extern signed char
__coverity__builtin_neon_vqshlb_n_u8(
    signed char __a,
    const int __b,
    int __);
#define __builtin_neon_vqshlb_n_u8(P0, P1, P2) \
    __coverity__builtin_neon_vqshlb_n_u8((P0), (P1), (P2))

extern signed char
__coverity__builtin_neon_vqshlb_u8(
    signed char __a,
    signed char __);
#define __builtin_neon_vqshlb_u8(P0, P1) \
    __coverity__builtin_neon_vqshlb_u8((P0), (P1))

extern signed char
__coverity__builtin_neon_vqshrnh_n_u16(
    unsigned short __a,
    const int __b,
    int __);
#define __builtin_neon_vqshrnh_n_u16(P0, P1, P2) \
    __coverity__builtin_neon_vqshrnh_n_u16((P0), (P1), (P2))

extern signed char
__coverity__builtin_neon_vqsubb_u8(
    signed char __a,
    signed char __);
#define __builtin_neon_vqsubb_u8(P0, P1) \
    __coverity__builtin_neon_vqsubb_u8((P0), (P1))

extern signed char
__coverity__builtin_neon_vsqaddb_u8(
    signed char __a,
    signed char __);
#define __builtin_neon_vsqaddb_u8(P0, P1) \
    __coverity__builtin_neon_vsqaddb_u8((P0), (P1))

extern signed char
__coverity__builtin_neon_vuqaddb_s8(
    signed char __a,
    signed char __);
#define __builtin_neon_vuqaddb_s8(P0, P1) \
    __coverity__builtin_neon_vuqaddb_s8((P0), (P1))

/*
 * __ARM_NEON_FP is a bitmask that indicates what floating
 * point types (if any) are supported as Neon vector base types.
 * Bit 3 corresponds to `double`.
 */
#if defined(__ARM_NEON_FP) && ((__ARM_NEON_FP & 8U) != 0U)
extern  double __attribute__((neon_vector_type(1)))
__coverity__builtin_neon_vcvt_f64_v(
    signed char __attribute__((neon_vector_type(8))) __a,
    int __);
#define __builtin_neon_vcvt_f64_v(P0, P1) \
    __coverity__builtin_neon_vcvt_f64_v((P0), (P1))

extern  double __attribute__((neon_vector_type(1)))
__coverity__builtin_neon_vcvt_n_f64_v(
    signed char __attribute__((neon_vector_type(8))) __a,
    const int __b,
    int __c,
    int __);
#define __builtin_neon_vcvt_n_f64_v(P0, P1, P2, P3) \
    __coverity__builtin_neon_vcvt_n_f64_v((P0), (P1), (P2), (P3))

extern  double __attribute__((neon_vector_type(2)))
__coverity__builtin_neon_vcvtq_f64_v(
    signed char __attribute__((neon_vector_type(16))) __a,
    int __);
#define __builtin_neon_vcvtq_f64_v(P0, P1) \
    __coverity__builtin_neon_vcvtq_f64_v((P0), (P1))

extern  double __attribute__((neon_vector_type(2)))
__coverity__builtin_neon_vcvtq_n_f64_v(
    signed char __attribute__((neon_vector_type(16))) __a,
    const int __b,
    int __c,
    int __);
#define __builtin_neon_vcvtq_n_f64_v(P0, P1, P2, P3) \
    __coverity__builtin_neon_vcvtq_n_f64_v((P0), (P1), (P2), (P3))

#endif /* defined(__ARM_NEON_FP) && ((__ARM_NEON_FP & 8U) != 0U) */
#endif /* } defined(__ARM_NEON__) || defined(__AARCH_FEATURE_ADVSIMD) */

/* } Changed in Clang 10.0 */

/* Removed in Clang 10.0 { */

extern int
__coverityqsetjmp(
    void * __);
#define qsetjmp(P0) \
    __coverityqsetjmp((P0))

extern int
__coveritysetjmp_syscall(
    void * __);
#define setjmp_syscall(P0) \
    __coveritysetjmp_syscall((P0))

/* } Removed in Clang 10.0 */
#endif // clang < 10.0

/*************************************
 ************ Clang 11.0 *************
 *************************************/

#if (__cov_clang_version_lt(11, 0)) /* { */

/* Signatures changed in Clang 11.0 { */


/* _InterlockedAnd64("LLiLLiD*LLi" vs. "WiWiD*Wi") differs only in W(int64_t) vs LL(long long): Not generated */
/* _InterlockedDecrement64("LLiLLiD*" vs. "WiWiD*") differs only in W(int64_t) vs LL(long long): Not generated */
/* _InterlockedExchange64("LLiLLiD*LLi" vs. "WiWiD*Wi") differs only in W(int64_t) vs LL(long long): Not generated */
/* _InterlockedExchangeAdd64("LLiLLiD*LLi" vs. "WiWiD*Wi") differs only in W(int64_t) vs LL(long long): Not generated */
/* _InterlockedExchangeSub64("LLiLLiD*LLi" vs. "WiWiD*Wi") differs only in W(int64_t) vs LL(long long): Not generated */
/* _InterlockedIncrement64("LLiLLiD*" vs. "WiWiD*") differs only in W(int64_t) vs LL(long long): Not generated */
/* _InterlockedOr64("LLiLLiD*LLi" vs. "WiWiD*Wi") differs only in W(int64_t) vs LL(long long): Not generated */
/* _InterlockedXor64("LLiLLiD*LLi" vs. "WiWiD*Wi") differs only in W(int64_t) vs LL(long long): Not generated */
/* __atomic_always_lock_free("izvCD*" vs. "bzvCD*") differs only in return type: Not generated */
/* __atomic_is_lock_free("izvCD*" vs. "bzvCD*") differs only in return type: Not generated */

/* __builtin_HEXAGON_V6_pred_scalar2("V16ii" vs. "V64bi") differs only in return type: Not generated */
/* __builtin_HEXAGON_V6_pred_scalar2_128B("V32ii" vs. "V128bi") differs only in return type: Not generated */
/* __builtin_HEXAGON_V6_pred_scalar2v2("V16ii" vs. "V64bi") differs only in return type: Not generated */
/* __builtin_HEXAGON_V6_pred_scalar2v2_128B("V32ii" vs. "V128bi") differs only in return type: Not generated */
/* __builtin_HEXAGON_V6_vandvrt("V16iV16ii" vs. "V64bV16ii") differs only in return type: Not generated */
/* __builtin_HEXAGON_V6_vandvrt_128B("V32iV32ii" vs. "V128bV32ii") differs only in return type: Not generated */
/* __builtin_HEXAGON_V6_veqb("V16iV16iV16i" vs. "V64bV16iV16i") differs only in return type: Not generated */
/* __builtin_HEXAGON_V6_veqb_128B("V32iV32iV32i" vs. "V128bV32iV32i") differs only in return type: Not generated */
/* __builtin_HEXAGON_V6_veqh("V16iV16iV16i" vs. "V64bV16iV16i") differs only in return type: Not generated */
/* __builtin_HEXAGON_V6_veqh_128B("V32iV32iV32i" vs. "V128bV32iV32i") differs only in return type: Not generated */
/* __builtin_HEXAGON_V6_veqw("V16iV16iV16i" vs. "V64bV16iV16i") differs only in return type: Not generated */
/* __builtin_HEXAGON_V6_veqw_128B("V32iV32iV32i" vs. "V128bV32iV32i") differs only in return type: Not generated */
/* __builtin_HEXAGON_V6_vgtb("V16iV16iV16i" vs. "V64bV16iV16i") differs only in return type: Not generated */
/* __builtin_HEXAGON_V6_vgtb_128B("V32iV32iV32i" vs. "V128bV32iV32i") differs only in return type: Not generated */
/* __builtin_HEXAGON_V6_vgth("V16iV16iV16i" vs. "V64bV16iV16i") differs only in return type: Not generated */
/* __builtin_HEXAGON_V6_vgth_128B("V32iV32iV32i" vs. "V128bV32iV32i") differs only in return type: Not generated */
/* __builtin_HEXAGON_V6_vgtub("V16iV16iV16i" vs. "V64bV16iV16i") differs only in return type: Not generated */
/* __builtin_HEXAGON_V6_vgtub_128B("V32iV32iV32i" vs. "V128bV32iV32i") differs only in return type: Not generated */
/* __builtin_HEXAGON_V6_vgtuh("V16iV16iV16i" vs. "V64bV16iV16i") differs only in return type: Not generated */
/* __builtin_HEXAGON_V6_vgtuh_128B("V32iV32iV32i" vs. "V128bV32iV32i") differs only in return type: Not generated */
/* __builtin_HEXAGON_V6_vgtuw("V16iV16iV16i" vs. "V64bV16iV16i") differs only in return type: Not generated */
/* __builtin_HEXAGON_V6_vgtuw_128B("V32iV32iV32i" vs. "V128bV32iV32i") differs only in return type: Not generated */
/* __builtin_HEXAGON_V6_vgtw("V16iV16iV16i" vs. "V64bV16iV16i") differs only in return type: Not generated */
/* __builtin_HEXAGON_V6_vgtw_128B("V32iV32iV32i" vs. "V128bV32iV32i") differs only in return type: Not generated */
/* __builtin_arm_crc32cd("UiUiLLUi" vs. "UiUiWUi") differs only in W(int64_t) vs LL(long long): Not generated */
/* __builtin_arm_crc32cd("UiUiWUi" vs. "UiUiLLUi") differs only in W(int64_t) vs LL(long long): Not generated */
/* __builtin_arm_crc32d("UiUiLLUi" vs. "UiUiWUi") differs only in W(int64_t) vs LL(long long): Not generated */
/* __builtin_arm_crc32d("UiUiWUi" vs. "UiUiLLUi") differs only in W(int64_t) vs LL(long long): Not generated */
/* __builtin_arm_rsr64("LLUicC*" vs. "WUicC*") differs only in W(int64_t) vs LL(long long): Not generated */
/* __builtin_arm_rsr64("WUicC*" vs. "LLUicC*") differs only in W(int64_t) vs LL(long long): Not generated */
/* __builtin_arm_wsr64("vcC*LLUi" vs. "vcC*WUi") differs only in W(int64_t) vs LL(long long): Not generated */
/* __builtin_arm_wsr64("vcC*WUi" vs. "vcC*LLUi") differs only in W(int64_t) vs LL(long long): Not generated */
/* __c11_atomic_is_lock_free("iz" vs. "bz") differs only in return type: Not generated */

extern  int __attribute__((vector_size(64)))
__coverity__builtin_HEXAGON_V6_pred_and(
     int __attribute__((vector_size(64))) __a,
     int __attribute__((vector_size(64))) __);
#define __builtin_HEXAGON_V6_pred_and(P0, P1) \
    __coverity__builtin_HEXAGON_V6_pred_and((P0), (P1))

extern  int __attribute__((vector_size(128)))
__coverity__builtin_HEXAGON_V6_pred_and_128B(
     int __attribute__((vector_size(128))) __a,
     int __attribute__((vector_size(128))) __);
#define __builtin_HEXAGON_V6_pred_and_128B(P0, P1) \
    __coverity__builtin_HEXAGON_V6_pred_and_128B((P0), (P1))

extern  int __attribute__((vector_size(64)))
__coverity__builtin_HEXAGON_V6_pred_and_n(
     int __attribute__((vector_size(64))) __a,
     int __attribute__((vector_size(64))) __);
#define __builtin_HEXAGON_V6_pred_and_n(P0, P1) \
    __coverity__builtin_HEXAGON_V6_pred_and_n((P0), (P1))

extern  int __attribute__((vector_size(128)))
__coverity__builtin_HEXAGON_V6_pred_and_n_128B(
     int __attribute__((vector_size(128))) __a,
     int __attribute__((vector_size(128))) __);
#define __builtin_HEXAGON_V6_pred_and_n_128B(P0, P1) \
    __coverity__builtin_HEXAGON_V6_pred_and_n_128B((P0), (P1))

extern  int __attribute__((vector_size(64)))
__coverity__builtin_HEXAGON_V6_pred_not(
     int __attribute__((vector_size(64))) __);
#define __builtin_HEXAGON_V6_pred_not(P0) \
    __coverity__builtin_HEXAGON_V6_pred_not((P0))

extern  int __attribute__((vector_size(128)))
__coverity__builtin_HEXAGON_V6_pred_not_128B(
     int __attribute__((vector_size(128))) __);
#define __builtin_HEXAGON_V6_pred_not_128B(P0) \
    __coverity__builtin_HEXAGON_V6_pred_not_128B((P0))

extern  int __attribute__((vector_size(64)))
__coverity__builtin_HEXAGON_V6_pred_or(
     int __attribute__((vector_size(64))) __a,
     int __attribute__((vector_size(64))) __);
#define __builtin_HEXAGON_V6_pred_or(P0, P1) \
    __coverity__builtin_HEXAGON_V6_pred_or((P0), (P1))

extern  int __attribute__((vector_size(128)))
__coverity__builtin_HEXAGON_V6_pred_or_128B(
     int __attribute__((vector_size(128))) __a,
     int __attribute__((vector_size(128))) __);
#define __builtin_HEXAGON_V6_pred_or_128B(P0, P1) \
    __coverity__builtin_HEXAGON_V6_pred_or_128B((P0), (P1))

extern  int __attribute__((vector_size(64)))
__coverity__builtin_HEXAGON_V6_pred_or_n(
     int __attribute__((vector_size(64))) __a,
     int __attribute__((vector_size(64))) __);
#define __builtin_HEXAGON_V6_pred_or_n(P0, P1) \
    __coverity__builtin_HEXAGON_V6_pred_or_n((P0), (P1))

extern  int __attribute__((vector_size(128)))
__coverity__builtin_HEXAGON_V6_pred_or_n_128B(
     int __attribute__((vector_size(128))) __a,
     int __attribute__((vector_size(128))) __);
#define __builtin_HEXAGON_V6_pred_or_n_128B(P0, P1) \
    __coverity__builtin_HEXAGON_V6_pred_or_n_128B((P0), (P1))

extern  int __attribute__((vector_size(64)))
__coverity__builtin_HEXAGON_V6_pred_xor(
     int __attribute__((vector_size(64))) __a,
     int __attribute__((vector_size(64))) __);
#define __builtin_HEXAGON_V6_pred_xor(P0, P1) \
    __coverity__builtin_HEXAGON_V6_pred_xor((P0), (P1))

extern  int __attribute__((vector_size(128)))
__coverity__builtin_HEXAGON_V6_pred_xor_128B(
     int __attribute__((vector_size(128))) __a,
     int __attribute__((vector_size(128))) __);
#define __builtin_HEXAGON_V6_pred_xor_128B(P0, P1) \
    __coverity__builtin_HEXAGON_V6_pred_xor_128B((P0), (P1))

extern  int __attribute__((vector_size(64)))
__coverity__builtin_HEXAGON_V6_shuffeqh(
     int __attribute__((vector_size(64))) __a,
     int __attribute__((vector_size(64))) __);
#define __builtin_HEXAGON_V6_shuffeqh(P0, P1) \
    __coverity__builtin_HEXAGON_V6_shuffeqh((P0), (P1))

extern  int __attribute__((vector_size(128)))
__coverity__builtin_HEXAGON_V6_shuffeqh_128B(
     int __attribute__((vector_size(128))) __a,
     int __attribute__((vector_size(128))) __);
#define __builtin_HEXAGON_V6_shuffeqh_128B(P0, P1) \
    __coverity__builtin_HEXAGON_V6_shuffeqh_128B((P0), (P1))

extern  int __attribute__((vector_size(64)))
__coverity__builtin_HEXAGON_V6_shuffeqw(
     int __attribute__((vector_size(64))) __a,
     int __attribute__((vector_size(64))) __);
#define __builtin_HEXAGON_V6_shuffeqw(P0, P1) \
    __coverity__builtin_HEXAGON_V6_shuffeqw((P0), (P1))

extern  int __attribute__((vector_size(128)))
__coverity__builtin_HEXAGON_V6_shuffeqw_128B(
     int __attribute__((vector_size(128))) __a,
     int __attribute__((vector_size(128))) __);
#define __builtin_HEXAGON_V6_shuffeqw_128B(P0, P1) \
    __coverity__builtin_HEXAGON_V6_shuffeqw_128B((P0), (P1))

extern void
__coverity__builtin_HEXAGON_V6_vS32b_nqpred_ai(
     int __attribute__((vector_size(64))) __a,
    void *  __b,
     int __attribute__((vector_size(64))) __);
#define __builtin_HEXAGON_V6_vS32b_nqpred_ai(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vS32b_nqpred_ai((P0), (P1), (P2))

extern void
__coverity__builtin_HEXAGON_V6_vS32b_nqpred_ai_128B(
     int __attribute__((vector_size(128))) __a,
    void *  __b,
     int __attribute__((vector_size(128))) __);
#define __builtin_HEXAGON_V6_vS32b_nqpred_ai_128B(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vS32b_nqpred_ai_128B((P0), (P1), (P2))

extern void
__coverity__builtin_HEXAGON_V6_vS32b_nt_nqpred_ai(
     int __attribute__((vector_size(64))) __a,
    void *  __b,
     int __attribute__((vector_size(64))) __);
#define __builtin_HEXAGON_V6_vS32b_nt_nqpred_ai(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vS32b_nt_nqpred_ai((P0), (P1), (P2))

extern void
__coverity__builtin_HEXAGON_V6_vS32b_nt_nqpred_ai_128B(
     int __attribute__((vector_size(128))) __a,
    void *  __b,
     int __attribute__((vector_size(128))) __);
#define __builtin_HEXAGON_V6_vS32b_nt_nqpred_ai_128B(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vS32b_nt_nqpred_ai_128B((P0), (P1), (P2))

extern void
__coverity__builtin_HEXAGON_V6_vS32b_nt_qpred_ai(
     int __attribute__((vector_size(64))) __a,
    void *  __b,
     int __attribute__((vector_size(64))) __);
#define __builtin_HEXAGON_V6_vS32b_nt_qpred_ai(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vS32b_nt_qpred_ai((P0), (P1), (P2))

extern void
__coverity__builtin_HEXAGON_V6_vS32b_nt_qpred_ai_128B(
     int __attribute__((vector_size(128))) __a,
    void *  __b,
     int __attribute__((vector_size(128))) __);
#define __builtin_HEXAGON_V6_vS32b_nt_qpred_ai_128B(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vS32b_nt_qpred_ai_128B((P0), (P1), (P2))

extern void
__coverity__builtin_HEXAGON_V6_vS32b_qpred_ai(
     int __attribute__((vector_size(64))) __a,
    void *  __b,
     int __attribute__((vector_size(64))) __);
#define __builtin_HEXAGON_V6_vS32b_qpred_ai(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vS32b_qpred_ai((P0), (P1), (P2))

extern void
__coverity__builtin_HEXAGON_V6_vS32b_qpred_ai_128B(
     int __attribute__((vector_size(128))) __a,
    void *  __b,
     int __attribute__((vector_size(128))) __);
#define __builtin_HEXAGON_V6_vS32b_qpred_ai_128B(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vS32b_qpred_ai_128B((P0), (P1), (P2))

extern  int __attribute__((vector_size(64)))
__coverity__builtin_HEXAGON_V6_vaddbnq(
     int __attribute__((vector_size(64))) __a,
     int __attribute__((vector_size(64))) __b,
     int __attribute__((vector_size(64))) __);
#define __builtin_HEXAGON_V6_vaddbnq(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vaddbnq((P0), (P1), (P2))

extern  int __attribute__((vector_size(128)))
__coverity__builtin_HEXAGON_V6_vaddbnq_128B(
     int __attribute__((vector_size(128))) __a,
     int __attribute__((vector_size(128))) __b,
     int __attribute__((vector_size(128))) __);
#define __builtin_HEXAGON_V6_vaddbnq_128B(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vaddbnq_128B((P0), (P1), (P2))

extern  int __attribute__((vector_size(64)))
__coverity__builtin_HEXAGON_V6_vaddbq(
     int __attribute__((vector_size(64))) __a,
     int __attribute__((vector_size(64))) __b,
     int __attribute__((vector_size(64))) __);
#define __builtin_HEXAGON_V6_vaddbq(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vaddbq((P0), (P1), (P2))

extern  int __attribute__((vector_size(128)))
__coverity__builtin_HEXAGON_V6_vaddbq_128B(
     int __attribute__((vector_size(128))) __a,
     int __attribute__((vector_size(128))) __b,
     int __attribute__((vector_size(128))) __);
#define __builtin_HEXAGON_V6_vaddbq_128B(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vaddbq_128B((P0), (P1), (P2))

extern  int __attribute__((vector_size(64)))
__coverity__builtin_HEXAGON_V6_vaddcarrysat(
     int __attribute__((vector_size(64))) __a,
     int __attribute__((vector_size(64))) __b,
     int __attribute__((vector_size(64))) __);
#define __builtin_HEXAGON_V6_vaddcarrysat(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vaddcarrysat((P0), (P1), (P2))

extern  int __attribute__((vector_size(128)))
__coverity__builtin_HEXAGON_V6_vaddcarrysat_128B(
     int __attribute__((vector_size(128))) __a,
     int __attribute__((vector_size(128))) __b,
     int __attribute__((vector_size(128))) __);
#define __builtin_HEXAGON_V6_vaddcarrysat_128B(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vaddcarrysat_128B((P0), (P1), (P2))

extern  int __attribute__((vector_size(64)))
__coverity__builtin_HEXAGON_V6_vaddhnq(
     int __attribute__((vector_size(64))) __a,
     int __attribute__((vector_size(64))) __b,
     int __attribute__((vector_size(64))) __);
#define __builtin_HEXAGON_V6_vaddhnq(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vaddhnq((P0), (P1), (P2))

extern  int __attribute__((vector_size(128)))
__coverity__builtin_HEXAGON_V6_vaddhnq_128B(
     int __attribute__((vector_size(128))) __a,
     int __attribute__((vector_size(128))) __b,
     int __attribute__((vector_size(128))) __);
#define __builtin_HEXAGON_V6_vaddhnq_128B(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vaddhnq_128B((P0), (P1), (P2))

extern  int __attribute__((vector_size(64)))
__coverity__builtin_HEXAGON_V6_vaddhq(
     int __attribute__((vector_size(64))) __a,
     int __attribute__((vector_size(64))) __b,
     int __attribute__((vector_size(64))) __);
#define __builtin_HEXAGON_V6_vaddhq(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vaddhq((P0), (P1), (P2))

extern  int __attribute__((vector_size(128)))
__coverity__builtin_HEXAGON_V6_vaddhq_128B(
     int __attribute__((vector_size(128))) __a,
     int __attribute__((vector_size(128))) __b,
     int __attribute__((vector_size(128))) __);
#define __builtin_HEXAGON_V6_vaddhq_128B(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vaddhq_128B((P0), (P1), (P2))

extern  int __attribute__((vector_size(64)))
__coverity__builtin_HEXAGON_V6_vaddwnq(
     int __attribute__((vector_size(64))) __a,
     int __attribute__((vector_size(64))) __b,
     int __attribute__((vector_size(64))) __);
#define __builtin_HEXAGON_V6_vaddwnq(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vaddwnq((P0), (P1), (P2))

extern  int __attribute__((vector_size(128)))
__coverity__builtin_HEXAGON_V6_vaddwnq_128B(
     int __attribute__((vector_size(128))) __a,
     int __attribute__((vector_size(128))) __b,
     int __attribute__((vector_size(128))) __);
#define __builtin_HEXAGON_V6_vaddwnq_128B(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vaddwnq_128B((P0), (P1), (P2))

extern  int __attribute__((vector_size(64)))
__coverity__builtin_HEXAGON_V6_vaddwq(
     int __attribute__((vector_size(64))) __a,
     int __attribute__((vector_size(64))) __b,
     int __attribute__((vector_size(64))) __);
#define __builtin_HEXAGON_V6_vaddwq(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vaddwq((P0), (P1), (P2))

extern  int __attribute__((vector_size(128)))
__coverity__builtin_HEXAGON_V6_vaddwq_128B(
     int __attribute__((vector_size(128))) __a,
     int __attribute__((vector_size(128))) __b,
     int __attribute__((vector_size(128))) __);
#define __builtin_HEXAGON_V6_vaddwq_128B(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vaddwq_128B((P0), (P1), (P2))

extern  int __attribute__((vector_size(64)))
__coverity__builtin_HEXAGON_V6_vandnqrt(
     int __attribute__((vector_size(64))) __a,
    int __);
#define __builtin_HEXAGON_V6_vandnqrt(P0, P1) \
    __coverity__builtin_HEXAGON_V6_vandnqrt((P0), (P1))

extern  int __attribute__((vector_size(128)))
__coverity__builtin_HEXAGON_V6_vandnqrt_128B(
     int __attribute__((vector_size(128))) __a,
    int __);
#define __builtin_HEXAGON_V6_vandnqrt_128B(P0, P1) \
    __coverity__builtin_HEXAGON_V6_vandnqrt_128B((P0), (P1))

extern  int __attribute__((vector_size(64)))
__coverity__builtin_HEXAGON_V6_vandnqrt_acc(
     int __attribute__((vector_size(64))) __a,
     int __attribute__((vector_size(64))) __b,
    int __);
#define __builtin_HEXAGON_V6_vandnqrt_acc(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vandnqrt_acc((P0), (P1), (P2))

extern  int __attribute__((vector_size(128)))
__coverity__builtin_HEXAGON_V6_vandnqrt_acc_128B(
     int __attribute__((vector_size(128))) __a,
     int __attribute__((vector_size(128))) __b,
    int __);
#define __builtin_HEXAGON_V6_vandnqrt_acc_128B(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vandnqrt_acc_128B((P0), (P1), (P2))

extern  int __attribute__((vector_size(64)))
__coverity__builtin_HEXAGON_V6_vandqrt(
     int __attribute__((vector_size(64))) __a,
    int __);
#define __builtin_HEXAGON_V6_vandqrt(P0, P1) \
    __coverity__builtin_HEXAGON_V6_vandqrt((P0), (P1))

extern  int __attribute__((vector_size(128)))
__coverity__builtin_HEXAGON_V6_vandqrt_128B(
     int __attribute__((vector_size(128))) __a,
    int __);
#define __builtin_HEXAGON_V6_vandqrt_128B(P0, P1) \
    __coverity__builtin_HEXAGON_V6_vandqrt_128B((P0), (P1))

extern  int __attribute__((vector_size(64)))
__coverity__builtin_HEXAGON_V6_vandqrt_acc(
     int __attribute__((vector_size(64))) __a,
     int __attribute__((vector_size(64))) __b,
    int __);
#define __builtin_HEXAGON_V6_vandqrt_acc(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vandqrt_acc((P0), (P1), (P2))

extern  int __attribute__((vector_size(128)))
__coverity__builtin_HEXAGON_V6_vandqrt_acc_128B(
     int __attribute__((vector_size(128))) __a,
     int __attribute__((vector_size(128))) __b,
    int __);
#define __builtin_HEXAGON_V6_vandqrt_acc_128B(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vandqrt_acc_128B((P0), (P1), (P2))

extern  int __attribute__((vector_size(64)))
__coverity__builtin_HEXAGON_V6_vandvnqv(
     int __attribute__((vector_size(64))) __a,
     int __attribute__((vector_size(64))) __);
#define __builtin_HEXAGON_V6_vandvnqv(P0, P1) \
    __coverity__builtin_HEXAGON_V6_vandvnqv((P0), (P1))

extern  int __attribute__((vector_size(128)))
__coverity__builtin_HEXAGON_V6_vandvnqv_128B(
     int __attribute__((vector_size(128))) __a,
     int __attribute__((vector_size(128))) __);
#define __builtin_HEXAGON_V6_vandvnqv_128B(P0, P1) \
    __coverity__builtin_HEXAGON_V6_vandvnqv_128B((P0), (P1))

extern  int __attribute__((vector_size(64)))
__coverity__builtin_HEXAGON_V6_vandvqv(
     int __attribute__((vector_size(64))) __a,
     int __attribute__((vector_size(64))) __);
#define __builtin_HEXAGON_V6_vandvqv(P0, P1) \
    __coverity__builtin_HEXAGON_V6_vandvqv((P0), (P1))

extern  int __attribute__((vector_size(128)))
__coverity__builtin_HEXAGON_V6_vandvqv_128B(
     int __attribute__((vector_size(128))) __a,
     int __attribute__((vector_size(128))) __);
#define __builtin_HEXAGON_V6_vandvqv_128B(P0, P1) \
    __coverity__builtin_HEXAGON_V6_vandvqv_128B((P0), (P1))


extern  int __attribute__((vector_size(64)))
__coverity__builtin_HEXAGON_V6_vandvrt_acc(
     int __attribute__((vector_size(64))) __a,
     int __attribute__((vector_size(64))) __b,
    int __);
#define __builtin_HEXAGON_V6_vandvrt_acc(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vandvrt_acc((P0), (P1), (P2))

extern  int __attribute__((vector_size(128)))
__coverity__builtin_HEXAGON_V6_vandvrt_acc_128B(
     int __attribute__((vector_size(128))) __a,
     int __attribute__((vector_size(128))) __b,
    int __);
#define __builtin_HEXAGON_V6_vandvrt_acc_128B(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vandvrt_acc_128B((P0), (P1), (P2))

extern  int __attribute__((vector_size(64)))
__coverity__builtin_HEXAGON_V6_veqb_and(
     int __attribute__((vector_size(64))) __a,
     int __attribute__((vector_size(64))) __b,
     int __attribute__((vector_size(64))) __);
#define __builtin_HEXAGON_V6_veqb_and(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_veqb_and((P0), (P1), (P2))

extern  int __attribute__((vector_size(128)))
__coverity__builtin_HEXAGON_V6_veqb_and_128B(
     int __attribute__((vector_size(128))) __a,
     int __attribute__((vector_size(128))) __b,
     int __attribute__((vector_size(128))) __);
#define __builtin_HEXAGON_V6_veqb_and_128B(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_veqb_and_128B((P0), (P1), (P2))

extern  int __attribute__((vector_size(64)))
__coverity__builtin_HEXAGON_V6_veqb_or(
     int __attribute__((vector_size(64))) __a,
     int __attribute__((vector_size(64))) __b,
     int __attribute__((vector_size(64))) __);
#define __builtin_HEXAGON_V6_veqb_or(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_veqb_or((P0), (P1), (P2))

extern  int __attribute__((vector_size(128)))
__coverity__builtin_HEXAGON_V6_veqb_or_128B(
     int __attribute__((vector_size(128))) __a,
     int __attribute__((vector_size(128))) __b,
     int __attribute__((vector_size(128))) __);
#define __builtin_HEXAGON_V6_veqb_or_128B(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_veqb_or_128B((P0), (P1), (P2))

extern  int __attribute__((vector_size(64)))
__coverity__builtin_HEXAGON_V6_veqb_xor(
     int __attribute__((vector_size(64))) __a,
     int __attribute__((vector_size(64))) __b,
     int __attribute__((vector_size(64))) __);
#define __builtin_HEXAGON_V6_veqb_xor(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_veqb_xor((P0), (P1), (P2))

extern  int __attribute__((vector_size(128)))
__coverity__builtin_HEXAGON_V6_veqb_xor_128B(
     int __attribute__((vector_size(128))) __a,
     int __attribute__((vector_size(128))) __b,
     int __attribute__((vector_size(128))) __);
#define __builtin_HEXAGON_V6_veqb_xor_128B(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_veqb_xor_128B((P0), (P1), (P2))

extern  int __attribute__((vector_size(64)))
__coverity__builtin_HEXAGON_V6_veqh_and(
     int __attribute__((vector_size(64))) __a,
     int __attribute__((vector_size(64))) __b,
     int __attribute__((vector_size(64))) __);
#define __builtin_HEXAGON_V6_veqh_and(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_veqh_and((P0), (P1), (P2))

extern  int __attribute__((vector_size(128)))
__coverity__builtin_HEXAGON_V6_veqh_and_128B(
     int __attribute__((vector_size(128))) __a,
     int __attribute__((vector_size(128))) __b,
     int __attribute__((vector_size(128))) __);
#define __builtin_HEXAGON_V6_veqh_and_128B(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_veqh_and_128B((P0), (P1), (P2))

extern  int __attribute__((vector_size(64)))
__coverity__builtin_HEXAGON_V6_veqh_or(
     int __attribute__((vector_size(64))) __a,
     int __attribute__((vector_size(64))) __b,
     int __attribute__((vector_size(64))) __);
#define __builtin_HEXAGON_V6_veqh_or(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_veqh_or((P0), (P1), (P2))

extern  int __attribute__((vector_size(128)))
__coverity__builtin_HEXAGON_V6_veqh_or_128B(
     int __attribute__((vector_size(128))) __a,
     int __attribute__((vector_size(128))) __b,
     int __attribute__((vector_size(128))) __);
#define __builtin_HEXAGON_V6_veqh_or_128B(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_veqh_or_128B((P0), (P1), (P2))

extern  int __attribute__((vector_size(64)))
__coverity__builtin_HEXAGON_V6_veqh_xor(
     int __attribute__((vector_size(64))) __a,
     int __attribute__((vector_size(64))) __b,
     int __attribute__((vector_size(64))) __);
#define __builtin_HEXAGON_V6_veqh_xor(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_veqh_xor((P0), (P1), (P2))

extern  int __attribute__((vector_size(128)))
__coverity__builtin_HEXAGON_V6_veqh_xor_128B(
     int __attribute__((vector_size(128))) __a,
     int __attribute__((vector_size(128))) __b,
     int __attribute__((vector_size(128))) __);
#define __builtin_HEXAGON_V6_veqh_xor_128B(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_veqh_xor_128B((P0), (P1), (P2))

extern  int __attribute__((vector_size(64)))
__coverity__builtin_HEXAGON_V6_veqw_and(
     int __attribute__((vector_size(64))) __a,
     int __attribute__((vector_size(64))) __b,
     int __attribute__((vector_size(64))) __);
#define __builtin_HEXAGON_V6_veqw_and(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_veqw_and((P0), (P1), (P2))

extern  int __attribute__((vector_size(128)))
__coverity__builtin_HEXAGON_V6_veqw_and_128B(
     int __attribute__((vector_size(128))) __a,
     int __attribute__((vector_size(128))) __b,
     int __attribute__((vector_size(128))) __);
#define __builtin_HEXAGON_V6_veqw_and_128B(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_veqw_and_128B((P0), (P1), (P2))

extern  int __attribute__((vector_size(64)))
__coverity__builtin_HEXAGON_V6_veqw_or(
     int __attribute__((vector_size(64))) __a,
     int __attribute__((vector_size(64))) __b,
     int __attribute__((vector_size(64))) __);
#define __builtin_HEXAGON_V6_veqw_or(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_veqw_or((P0), (P1), (P2))

extern  int __attribute__((vector_size(128)))
__coverity__builtin_HEXAGON_V6_veqw_or_128B(
     int __attribute__((vector_size(128))) __a,
     int __attribute__((vector_size(128))) __b,
     int __attribute__((vector_size(128))) __);
#define __builtin_HEXAGON_V6_veqw_or_128B(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_veqw_or_128B((P0), (P1), (P2))

extern  int __attribute__((vector_size(64)))
__coverity__builtin_HEXAGON_V6_veqw_xor(
     int __attribute__((vector_size(64))) __a,
     int __attribute__((vector_size(64))) __b,
     int __attribute__((vector_size(64))) __);
#define __builtin_HEXAGON_V6_veqw_xor(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_veqw_xor((P0), (P1), (P2))

extern  int __attribute__((vector_size(128)))
__coverity__builtin_HEXAGON_V6_veqw_xor_128B(
     int __attribute__((vector_size(128))) __a,
     int __attribute__((vector_size(128))) __b,
     int __attribute__((vector_size(128))) __);
#define __builtin_HEXAGON_V6_veqw_xor_128B(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_veqw_xor_128B((P0), (P1), (P2))

extern void
__coverity__builtin_HEXAGON_V6_vgathermhq(
    void *  __a,
     int __attribute__((vector_size(64))) __b,
    int __c,
    int __d,
     int __attribute__((vector_size(64))) __);
#define __builtin_HEXAGON_V6_vgathermhq(P0, P1, P2, P3, P4) \
    __coverity__builtin_HEXAGON_V6_vgathermhq((P0), (P1), (P2), (P3), (P4))

extern void
__coverity__builtin_HEXAGON_V6_vgathermhq_128B(
    void *  __a,
     int __attribute__((vector_size(128))) __b,
    int __c,
    int __d,
     int __attribute__((vector_size(128))) __);
#define __builtin_HEXAGON_V6_vgathermhq_128B(P0, P1, P2, P3, P4) \
    __coverity__builtin_HEXAGON_V6_vgathermhq_128B((P0), (P1), (P2), (P3), (P4))

extern void
__coverity__builtin_HEXAGON_V6_vgathermhwq(
    void *  __a,
     int __attribute__((vector_size(64))) __b,
    int __c,
    int __d,
     int __attribute__((vector_size(128))) __);
#define __builtin_HEXAGON_V6_vgathermhwq(P0, P1, P2, P3, P4) \
    __coverity__builtin_HEXAGON_V6_vgathermhwq((P0), (P1), (P2), (P3), (P4))

extern void
__coverity__builtin_HEXAGON_V6_vgathermhwq_128B(
    void *  __a,
     int __attribute__((vector_size(128))) __b,
    int __c,
    int __d,
     int __attribute__((vector_size(256))) __);
#define __builtin_HEXAGON_V6_vgathermhwq_128B(P0, P1, P2, P3, P4) \
    __coverity__builtin_HEXAGON_V6_vgathermhwq_128B((P0), (P1), (P2), (P3), (P4))

extern void
__coverity__builtin_HEXAGON_V6_vgathermwq(
    void *  __a,
     int __attribute__((vector_size(64))) __b,
    int __c,
    int __d,
     int __attribute__((vector_size(64))) __);
#define __builtin_HEXAGON_V6_vgathermwq(P0, P1, P2, P3, P4) \
    __coverity__builtin_HEXAGON_V6_vgathermwq((P0), (P1), (P2), (P3), (P4))

extern void
__coverity__builtin_HEXAGON_V6_vgathermwq_128B(
    void *  __a,
     int __attribute__((vector_size(128))) __b,
    int __c,
    int __d,
     int __attribute__((vector_size(128))) __);
#define __builtin_HEXAGON_V6_vgathermwq_128B(P0, P1, P2, P3, P4) \
    __coverity__builtin_HEXAGON_V6_vgathermwq_128B((P0), (P1), (P2), (P3), (P4))

extern  int __attribute__((vector_size(64)))
__coverity__builtin_HEXAGON_V6_vgtb_and(
     int __attribute__((vector_size(64))) __a,
     int __attribute__((vector_size(64))) __b,
     int __attribute__((vector_size(64))) __);
#define __builtin_HEXAGON_V6_vgtb_and(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vgtb_and((P0), (P1), (P2))

extern  int __attribute__((vector_size(128)))
__coverity__builtin_HEXAGON_V6_vgtb_and_128B(
     int __attribute__((vector_size(128))) __a,
     int __attribute__((vector_size(128))) __b,
     int __attribute__((vector_size(128))) __);
#define __builtin_HEXAGON_V6_vgtb_and_128B(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vgtb_and_128B((P0), (P1), (P2))

extern  int __attribute__((vector_size(64)))
__coverity__builtin_HEXAGON_V6_vgtb_or(
     int __attribute__((vector_size(64))) __a,
     int __attribute__((vector_size(64))) __b,
     int __attribute__((vector_size(64))) __);
#define __builtin_HEXAGON_V6_vgtb_or(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vgtb_or((P0), (P1), (P2))

extern  int __attribute__((vector_size(128)))
__coverity__builtin_HEXAGON_V6_vgtb_or_128B(
     int __attribute__((vector_size(128))) __a,
     int __attribute__((vector_size(128))) __b,
     int __attribute__((vector_size(128))) __);
#define __builtin_HEXAGON_V6_vgtb_or_128B(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vgtb_or_128B((P0), (P1), (P2))

extern  int __attribute__((vector_size(64)))
__coverity__builtin_HEXAGON_V6_vgtb_xor(
     int __attribute__((vector_size(64))) __a,
     int __attribute__((vector_size(64))) __b,
     int __attribute__((vector_size(64))) __);
#define __builtin_HEXAGON_V6_vgtb_xor(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vgtb_xor((P0), (P1), (P2))

extern  int __attribute__((vector_size(128)))
__coverity__builtin_HEXAGON_V6_vgtb_xor_128B(
     int __attribute__((vector_size(128))) __a,
     int __attribute__((vector_size(128))) __b,
     int __attribute__((vector_size(128))) __);
#define __builtin_HEXAGON_V6_vgtb_xor_128B(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vgtb_xor_128B((P0), (P1), (P2))

extern  int __attribute__((vector_size(64)))
__coverity__builtin_HEXAGON_V6_vgth_and(
     int __attribute__((vector_size(64))) __a,
     int __attribute__((vector_size(64))) __b,
     int __attribute__((vector_size(64))) __);
#define __builtin_HEXAGON_V6_vgth_and(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vgth_and((P0), (P1), (P2))

extern  int __attribute__((vector_size(128)))
__coverity__builtin_HEXAGON_V6_vgth_and_128B(
     int __attribute__((vector_size(128))) __a,
     int __attribute__((vector_size(128))) __b,
     int __attribute__((vector_size(128))) __);
#define __builtin_HEXAGON_V6_vgth_and_128B(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vgth_and_128B((P0), (P1), (P2))

extern  int __attribute__((vector_size(64)))
__coverity__builtin_HEXAGON_V6_vgth_or(
     int __attribute__((vector_size(64))) __a,
     int __attribute__((vector_size(64))) __b,
     int __attribute__((vector_size(64))) __);
#define __builtin_HEXAGON_V6_vgth_or(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vgth_or((P0), (P1), (P2))

extern  int __attribute__((vector_size(128)))
__coverity__builtin_HEXAGON_V6_vgth_or_128B(
     int __attribute__((vector_size(128))) __a,
     int __attribute__((vector_size(128))) __b,
     int __attribute__((vector_size(128))) __);
#define __builtin_HEXAGON_V6_vgth_or_128B(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vgth_or_128B((P0), (P1), (P2))

extern  int __attribute__((vector_size(64)))
__coverity__builtin_HEXAGON_V6_vgth_xor(
     int __attribute__((vector_size(64))) __a,
     int __attribute__((vector_size(64))) __b,
     int __attribute__((vector_size(64))) __);
#define __builtin_HEXAGON_V6_vgth_xor(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vgth_xor((P0), (P1), (P2))

extern  int __attribute__((vector_size(128)))
__coverity__builtin_HEXAGON_V6_vgth_xor_128B(
     int __attribute__((vector_size(128))) __a,
     int __attribute__((vector_size(128))) __b,
     int __attribute__((vector_size(128))) __);
#define __builtin_HEXAGON_V6_vgth_xor_128B(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vgth_xor_128B((P0), (P1), (P2))

extern  int __attribute__((vector_size(64)))
__coverity__builtin_HEXAGON_V6_vgtub_and(
     int __attribute__((vector_size(64))) __a,
     int __attribute__((vector_size(64))) __b,
     int __attribute__((vector_size(64))) __);
#define __builtin_HEXAGON_V6_vgtub_and(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vgtub_and((P0), (P1), (P2))

extern  int __attribute__((vector_size(128)))
__coverity__builtin_HEXAGON_V6_vgtub_and_128B(
     int __attribute__((vector_size(128))) __a,
     int __attribute__((vector_size(128))) __b,
     int __attribute__((vector_size(128))) __);
#define __builtin_HEXAGON_V6_vgtub_and_128B(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vgtub_and_128B((P0), (P1), (P2))

extern  int __attribute__((vector_size(64)))
__coverity__builtin_HEXAGON_V6_vgtub_or(
     int __attribute__((vector_size(64))) __a,
     int __attribute__((vector_size(64))) __b,
     int __attribute__((vector_size(64))) __);
#define __builtin_HEXAGON_V6_vgtub_or(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vgtub_or((P0), (P1), (P2))

extern  int __attribute__((vector_size(128)))
__coverity__builtin_HEXAGON_V6_vgtub_or_128B(
     int __attribute__((vector_size(128))) __a,
     int __attribute__((vector_size(128))) __b,
     int __attribute__((vector_size(128))) __);
#define __builtin_HEXAGON_V6_vgtub_or_128B(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vgtub_or_128B((P0), (P1), (P2))

extern  int __attribute__((vector_size(64)))
__coverity__builtin_HEXAGON_V6_vgtub_xor(
     int __attribute__((vector_size(64))) __a,
     int __attribute__((vector_size(64))) __b,
     int __attribute__((vector_size(64))) __);
#define __builtin_HEXAGON_V6_vgtub_xor(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vgtub_xor((P0), (P1), (P2))

extern  int __attribute__((vector_size(128)))
__coverity__builtin_HEXAGON_V6_vgtub_xor_128B(
     int __attribute__((vector_size(128))) __a,
     int __attribute__((vector_size(128))) __b,
     int __attribute__((vector_size(128))) __);
#define __builtin_HEXAGON_V6_vgtub_xor_128B(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vgtub_xor_128B((P0), (P1), (P2))

extern  int __attribute__((vector_size(64)))
__coverity__builtin_HEXAGON_V6_vgtuh_and(
     int __attribute__((vector_size(64))) __a,
     int __attribute__((vector_size(64))) __b,
     int __attribute__((vector_size(64))) __);
#define __builtin_HEXAGON_V6_vgtuh_and(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vgtuh_and((P0), (P1), (P2))

extern  int __attribute__((vector_size(128)))
__coverity__builtin_HEXAGON_V6_vgtuh_and_128B(
     int __attribute__((vector_size(128))) __a,
     int __attribute__((vector_size(128))) __b,
     int __attribute__((vector_size(128))) __);
#define __builtin_HEXAGON_V6_vgtuh_and_128B(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vgtuh_and_128B((P0), (P1), (P2))

extern  int __attribute__((vector_size(64)))
__coverity__builtin_HEXAGON_V6_vgtuh_or(
     int __attribute__((vector_size(64))) __a,
     int __attribute__((vector_size(64))) __b,
     int __attribute__((vector_size(64))) __);
#define __builtin_HEXAGON_V6_vgtuh_or(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vgtuh_or((P0), (P1), (P2))

extern  int __attribute__((vector_size(128)))
__coverity__builtin_HEXAGON_V6_vgtuh_or_128B(
     int __attribute__((vector_size(128))) __a,
     int __attribute__((vector_size(128))) __b,
     int __attribute__((vector_size(128))) __);
#define __builtin_HEXAGON_V6_vgtuh_or_128B(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vgtuh_or_128B((P0), (P1), (P2))

extern  int __attribute__((vector_size(64)))
__coverity__builtin_HEXAGON_V6_vgtuh_xor(
     int __attribute__((vector_size(64))) __a,
     int __attribute__((vector_size(64))) __b,
     int __attribute__((vector_size(64))) __);
#define __builtin_HEXAGON_V6_vgtuh_xor(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vgtuh_xor((P0), (P1), (P2))

extern  int __attribute__((vector_size(128)))
__coverity__builtin_HEXAGON_V6_vgtuh_xor_128B(
     int __attribute__((vector_size(128))) __a,
     int __attribute__((vector_size(128))) __b,
     int __attribute__((vector_size(128))) __);
#define __builtin_HEXAGON_V6_vgtuh_xor_128B(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vgtuh_xor_128B((P0), (P1), (P2))

extern  int __attribute__((vector_size(64)))
__coverity__builtin_HEXAGON_V6_vgtuw_and(
     int __attribute__((vector_size(64))) __a,
     int __attribute__((vector_size(64))) __b,
     int __attribute__((vector_size(64))) __);
#define __builtin_HEXAGON_V6_vgtuw_and(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vgtuw_and((P0), (P1), (P2))

extern  int __attribute__((vector_size(128)))
__coverity__builtin_HEXAGON_V6_vgtuw_and_128B(
     int __attribute__((vector_size(128))) __a,
     int __attribute__((vector_size(128))) __b,
     int __attribute__((vector_size(128))) __);
#define __builtin_HEXAGON_V6_vgtuw_and_128B(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vgtuw_and_128B((P0), (P1), (P2))

extern  int __attribute__((vector_size(64)))
__coverity__builtin_HEXAGON_V6_vgtuw_or(
     int __attribute__((vector_size(64))) __a,
     int __attribute__((vector_size(64))) __b,
     int __attribute__((vector_size(64))) __);
#define __builtin_HEXAGON_V6_vgtuw_or(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vgtuw_or((P0), (P1), (P2))

extern  int __attribute__((vector_size(128)))
__coverity__builtin_HEXAGON_V6_vgtuw_or_128B(
     int __attribute__((vector_size(128))) __a,
     int __attribute__((vector_size(128))) __b,
     int __attribute__((vector_size(128))) __);
#define __builtin_HEXAGON_V6_vgtuw_or_128B(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vgtuw_or_128B((P0), (P1), (P2))

extern  int __attribute__((vector_size(64)))
__coverity__builtin_HEXAGON_V6_vgtuw_xor(
     int __attribute__((vector_size(64))) __a,
     int __attribute__((vector_size(64))) __b,
     int __attribute__((vector_size(64))) __);
#define __builtin_HEXAGON_V6_vgtuw_xor(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vgtuw_xor((P0), (P1), (P2))

extern  int __attribute__((vector_size(128)))
__coverity__builtin_HEXAGON_V6_vgtuw_xor_128B(
     int __attribute__((vector_size(128))) __a,
     int __attribute__((vector_size(128))) __b,
     int __attribute__((vector_size(128))) __);
#define __builtin_HEXAGON_V6_vgtuw_xor_128B(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vgtuw_xor_128B((P0), (P1), (P2))

extern  int __attribute__((vector_size(64)))
__coverity__builtin_HEXAGON_V6_vgtw_and(
     int __attribute__((vector_size(64))) __a,
     int __attribute__((vector_size(64))) __b,
     int __attribute__((vector_size(64))) __);
#define __builtin_HEXAGON_V6_vgtw_and(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vgtw_and((P0), (P1), (P2))

extern  int __attribute__((vector_size(128)))
__coverity__builtin_HEXAGON_V6_vgtw_and_128B(
     int __attribute__((vector_size(128))) __a,
     int __attribute__((vector_size(128))) __b,
     int __attribute__((vector_size(128))) __);
#define __builtin_HEXAGON_V6_vgtw_and_128B(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vgtw_and_128B((P0), (P1), (P2))

extern  int __attribute__((vector_size(64)))
__coverity__builtin_HEXAGON_V6_vgtw_or(
     int __attribute__((vector_size(64))) __a,
     int __attribute__((vector_size(64))) __b,
     int __attribute__((vector_size(64))) __);
#define __builtin_HEXAGON_V6_vgtw_or(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vgtw_or((P0), (P1), (P2))

extern  int __attribute__((vector_size(128)))
__coverity__builtin_HEXAGON_V6_vgtw_or_128B(
     int __attribute__((vector_size(128))) __a,
     int __attribute__((vector_size(128))) __b,
     int __attribute__((vector_size(128))) __);
#define __builtin_HEXAGON_V6_vgtw_or_128B(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vgtw_or_128B((P0), (P1), (P2))

extern  int __attribute__((vector_size(64)))
__coverity__builtin_HEXAGON_V6_vgtw_xor(
     int __attribute__((vector_size(64))) __a,
     int __attribute__((vector_size(64))) __b,
     int __attribute__((vector_size(64))) __);
#define __builtin_HEXAGON_V6_vgtw_xor(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vgtw_xor((P0), (P1), (P2))

extern  int __attribute__((vector_size(128)))
__coverity__builtin_HEXAGON_V6_vgtw_xor_128B(
     int __attribute__((vector_size(128))) __a,
     int __attribute__((vector_size(128))) __b,
     int __attribute__((vector_size(128))) __);
#define __builtin_HEXAGON_V6_vgtw_xor_128B(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vgtw_xor_128B((P0), (P1), (P2))

extern void
__coverity__builtin_HEXAGON_V6_vmaskedstorenq(
     int __attribute__((vector_size(64))) __a,
    void *  __b,
     int __attribute__((vector_size(64))) __);
#define __builtin_HEXAGON_V6_vmaskedstorenq(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vmaskedstorenq((P0), (P1), (P2))

extern void
__coverity__builtin_HEXAGON_V6_vmaskedstorenq_128B(
     int __attribute__((vector_size(128))) __a,
    void *  __b,
     int __attribute__((vector_size(128))) __);
#define __builtin_HEXAGON_V6_vmaskedstorenq_128B(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vmaskedstorenq_128B((P0), (P1), (P2))

extern void
__coverity__builtin_HEXAGON_V6_vmaskedstorentnq(
     int __attribute__((vector_size(64))) __a,
    void *  __b,
     int __attribute__((vector_size(64))) __);
#define __builtin_HEXAGON_V6_vmaskedstorentnq(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vmaskedstorentnq((P0), (P1), (P2))

extern void
__coverity__builtin_HEXAGON_V6_vmaskedstorentnq_128B(
     int __attribute__((vector_size(128))) __a,
    void *  __b,
     int __attribute__((vector_size(128))) __);
#define __builtin_HEXAGON_V6_vmaskedstorentnq_128B(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vmaskedstorentnq_128B((P0), (P1), (P2))

extern void
__coverity__builtin_HEXAGON_V6_vmaskedstorentq(
     int __attribute__((vector_size(64))) __a,
    void *  __b,
     int __attribute__((vector_size(64))) __);
#define __builtin_HEXAGON_V6_vmaskedstorentq(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vmaskedstorentq((P0), (P1), (P2))

extern void
__coverity__builtin_HEXAGON_V6_vmaskedstorentq_128B(
     int __attribute__((vector_size(128))) __a,
    void *  __b,
     int __attribute__((vector_size(128))) __);
#define __builtin_HEXAGON_V6_vmaskedstorentq_128B(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vmaskedstorentq_128B((P0), (P1), (P2))

extern void
__coverity__builtin_HEXAGON_V6_vmaskedstoreq(
     int __attribute__((vector_size(64))) __a,
    void *  __b,
     int __attribute__((vector_size(64))) __);
#define __builtin_HEXAGON_V6_vmaskedstoreq(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vmaskedstoreq((P0), (P1), (P2))

extern void
__coverity__builtin_HEXAGON_V6_vmaskedstoreq_128B(
     int __attribute__((vector_size(128))) __a,
    void *  __b,
     int __attribute__((vector_size(128))) __);
#define __builtin_HEXAGON_V6_vmaskedstoreq_128B(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vmaskedstoreq_128B((P0), (P1), (P2))

extern  int __attribute__((vector_size(64)))
__coverity__builtin_HEXAGON_V6_vmux(
     int __attribute__((vector_size(64))) __a,
     int __attribute__((vector_size(64))) __b,
     int __attribute__((vector_size(64))) __);
#define __builtin_HEXAGON_V6_vmux(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vmux((P0), (P1), (P2))

extern  int __attribute__((vector_size(128)))
__coverity__builtin_HEXAGON_V6_vmux_128B(
     int __attribute__((vector_size(128))) __a,
     int __attribute__((vector_size(128))) __b,
     int __attribute__((vector_size(128))) __);
#define __builtin_HEXAGON_V6_vmux_128B(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vmux_128B((P0), (P1), (P2))

extern  int __attribute__((vector_size(64)))
__coverity__builtin_HEXAGON_V6_vprefixqb(
     int __attribute__((vector_size(64))) __);
#define __builtin_HEXAGON_V6_vprefixqb(P0) \
    __coverity__builtin_HEXAGON_V6_vprefixqb((P0))

extern  int __attribute__((vector_size(128)))
__coverity__builtin_HEXAGON_V6_vprefixqb_128B(
     int __attribute__((vector_size(128))) __);
#define __builtin_HEXAGON_V6_vprefixqb_128B(P0) \
    __coverity__builtin_HEXAGON_V6_vprefixqb_128B((P0))

extern  int __attribute__((vector_size(64)))
__coverity__builtin_HEXAGON_V6_vprefixqh(
     int __attribute__((vector_size(64))) __);
#define __builtin_HEXAGON_V6_vprefixqh(P0) \
    __coverity__builtin_HEXAGON_V6_vprefixqh((P0))

extern  int __attribute__((vector_size(128)))
__coverity__builtin_HEXAGON_V6_vprefixqh_128B(
     int __attribute__((vector_size(128))) __);
#define __builtin_HEXAGON_V6_vprefixqh_128B(P0) \
    __coverity__builtin_HEXAGON_V6_vprefixqh_128B((P0))

extern  int __attribute__((vector_size(64)))
__coverity__builtin_HEXAGON_V6_vprefixqw(
     int __attribute__((vector_size(64))) __);
#define __builtin_HEXAGON_V6_vprefixqw(P0) \
    __coverity__builtin_HEXAGON_V6_vprefixqw((P0))

extern  int __attribute__((vector_size(128)))
__coverity__builtin_HEXAGON_V6_vprefixqw_128B(
     int __attribute__((vector_size(128))) __);
#define __builtin_HEXAGON_V6_vprefixqw_128B(P0) \
    __coverity__builtin_HEXAGON_V6_vprefixqw_128B((P0))

extern void
__coverity__builtin_HEXAGON_V6_vscattermhq(
     int __attribute__((vector_size(64))) __a,
    int __b,
    int __c,
     int __attribute__((vector_size(64))) __d,
     int __attribute__((vector_size(64))) __);
#define __builtin_HEXAGON_V6_vscattermhq(P0, P1, P2, P3, P4) \
    __coverity__builtin_HEXAGON_V6_vscattermhq((P0), (P1), (P2), (P3), (P4))

extern void
__coverity__builtin_HEXAGON_V6_vscattermhq_128B(
     int __attribute__((vector_size(128))) __a,
    int __b,
    int __c,
     int __attribute__((vector_size(128))) __d,
     int __attribute__((vector_size(128))) __);
#define __builtin_HEXAGON_V6_vscattermhq_128B(P0, P1, P2, P3, P4) \
    __coverity__builtin_HEXAGON_V6_vscattermhq_128B((P0), (P1), (P2), (P3), (P4))

extern void
__coverity__builtin_HEXAGON_V6_vscattermhwq(
     int __attribute__((vector_size(64))) __a,
    int __b,
    int __c,
     int __attribute__((vector_size(128))) __d,
     int __attribute__((vector_size(64))) __);
#define __builtin_HEXAGON_V6_vscattermhwq(P0, P1, P2, P3, P4) \
    __coverity__builtin_HEXAGON_V6_vscattermhwq((P0), (P1), (P2), (P3), (P4))

extern void
__coverity__builtin_HEXAGON_V6_vscattermhwq_128B(
     int __attribute__((vector_size(128))) __a,
    int __b,
    int __c,
     int __attribute__((vector_size(256))) __d,
     int __attribute__((vector_size(128))) __);
#define __builtin_HEXAGON_V6_vscattermhwq_128B(P0, P1, P2, P3, P4) \
    __coverity__builtin_HEXAGON_V6_vscattermhwq_128B((P0), (P1), (P2), (P3), (P4))

extern void
__coverity__builtin_HEXAGON_V6_vscattermwq(
     int __attribute__((vector_size(64))) __a,
    int __b,
    int __c,
     int __attribute__((vector_size(64))) __d,
     int __attribute__((vector_size(64))) __);
#define __builtin_HEXAGON_V6_vscattermwq(P0, P1, P2, P3, P4) \
    __coverity__builtin_HEXAGON_V6_vscattermwq((P0), (P1), (P2), (P3), (P4))

extern void
__coverity__builtin_HEXAGON_V6_vscattermwq_128B(
     int __attribute__((vector_size(128))) __a,
    int __b,
    int __c,
     int __attribute__((vector_size(128))) __d,
     int __attribute__((vector_size(128))) __);
#define __builtin_HEXAGON_V6_vscattermwq_128B(P0, P1, P2, P3, P4) \
    __coverity__builtin_HEXAGON_V6_vscattermwq_128B((P0), (P1), (P2), (P3), (P4))

extern  int __attribute__((vector_size(64)))
__coverity__builtin_HEXAGON_V6_vsubbnq(
     int __attribute__((vector_size(64))) __a,
     int __attribute__((vector_size(64))) __b,
     int __attribute__((vector_size(64))) __);
#define __builtin_HEXAGON_V6_vsubbnq(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vsubbnq((P0), (P1), (P2))

extern  int __attribute__((vector_size(128)))
__coverity__builtin_HEXAGON_V6_vsubbnq_128B(
     int __attribute__((vector_size(128))) __a,
     int __attribute__((vector_size(128))) __b,
     int __attribute__((vector_size(128))) __);
#define __builtin_HEXAGON_V6_vsubbnq_128B(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vsubbnq_128B((P0), (P1), (P2))

extern  int __attribute__((vector_size(64)))
__coverity__builtin_HEXAGON_V6_vsubbq(
     int __attribute__((vector_size(64))) __a,
     int __attribute__((vector_size(64))) __b,
     int __attribute__((vector_size(64))) __);
#define __builtin_HEXAGON_V6_vsubbq(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vsubbq((P0), (P1), (P2))

extern  int __attribute__((vector_size(128)))
__coverity__builtin_HEXAGON_V6_vsubbq_128B(
     int __attribute__((vector_size(128))) __a,
     int __attribute__((vector_size(128))) __b,
     int __attribute__((vector_size(128))) __);
#define __builtin_HEXAGON_V6_vsubbq_128B(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vsubbq_128B((P0), (P1), (P2))

extern  int __attribute__((vector_size(64)))
__coverity__builtin_HEXAGON_V6_vsubhnq(
     int __attribute__((vector_size(64))) __a,
     int __attribute__((vector_size(64))) __b,
     int __attribute__((vector_size(64))) __);
#define __builtin_HEXAGON_V6_vsubhnq(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vsubhnq((P0), (P1), (P2))

extern  int __attribute__((vector_size(128)))
__coverity__builtin_HEXAGON_V6_vsubhnq_128B(
     int __attribute__((vector_size(128))) __a,
     int __attribute__((vector_size(128))) __b,
     int __attribute__((vector_size(128))) __);
#define __builtin_HEXAGON_V6_vsubhnq_128B(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vsubhnq_128B((P0), (P1), (P2))

extern  int __attribute__((vector_size(64)))
__coverity__builtin_HEXAGON_V6_vsubhq(
     int __attribute__((vector_size(64))) __a,
     int __attribute__((vector_size(64))) __b,
     int __attribute__((vector_size(64))) __);
#define __builtin_HEXAGON_V6_vsubhq(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vsubhq((P0), (P1), (P2))

extern  int __attribute__((vector_size(128)))
__coverity__builtin_HEXAGON_V6_vsubhq_128B(
     int __attribute__((vector_size(128))) __a,
     int __attribute__((vector_size(128))) __b,
     int __attribute__((vector_size(128))) __);
#define __builtin_HEXAGON_V6_vsubhq_128B(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vsubhq_128B((P0), (P1), (P2))

extern  int __attribute__((vector_size(64)))
__coverity__builtin_HEXAGON_V6_vsubwnq(
     int __attribute__((vector_size(64))) __a,
     int __attribute__((vector_size(64))) __b,
     int __attribute__((vector_size(64))) __);
#define __builtin_HEXAGON_V6_vsubwnq(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vsubwnq((P0), (P1), (P2))

extern  int __attribute__((vector_size(128)))
__coverity__builtin_HEXAGON_V6_vsubwnq_128B(
     int __attribute__((vector_size(128))) __a,
     int __attribute__((vector_size(128))) __b,
     int __attribute__((vector_size(128))) __);
#define __builtin_HEXAGON_V6_vsubwnq_128B(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vsubwnq_128B((P0), (P1), (P2))

extern  int __attribute__((vector_size(64)))
__coverity__builtin_HEXAGON_V6_vsubwq(
     int __attribute__((vector_size(64))) __a,
     int __attribute__((vector_size(64))) __b,
     int __attribute__((vector_size(64))) __);
#define __builtin_HEXAGON_V6_vsubwq(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vsubwq((P0), (P1), (P2))

extern  int __attribute__((vector_size(128)))
__coverity__builtin_HEXAGON_V6_vsubwq_128B(
     int __attribute__((vector_size(128))) __a,
     int __attribute__((vector_size(128))) __b,
     int __attribute__((vector_size(128))) __);
#define __builtin_HEXAGON_V6_vsubwq_128B(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vsubwq_128B((P0), (P1), (P2))

extern  int __attribute__((vector_size(128)))
__coverity__builtin_HEXAGON_V6_vswap(
     int __attribute__((vector_size(64))) __a,
     int __attribute__((vector_size(64))) __b,
     int __attribute__((vector_size(64))) __);
#define __builtin_HEXAGON_V6_vswap(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vswap((P0), (P1), (P2))

extern  int __attribute__((vector_size(256)))
__coverity__builtin_HEXAGON_V6_vswap_128B(
     int __attribute__((vector_size(128))) __a,
     int __attribute__((vector_size(128))) __b,
     int __attribute__((vector_size(128))) __);
#define __builtin_HEXAGON_V6_vswap_128B(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vswap_128B((P0), (P1), (P2))

extern void
__coverity__builtin_HEXAGON_Y4_l2fetch(
    void *  __a,
    unsigned int __);
#define __builtin_HEXAGON_Y4_l2fetch(P0, P1) \
    __coverity__builtin_HEXAGON_Y4_l2fetch((P0), (P1))

extern void
__coverity__builtin_HEXAGON_Y5_l2fetch(
    void *  __a,
    unsigned long long int __);
#define __builtin_HEXAGON_Y5_l2fetch(P0, P1) \
    __coverity__builtin_HEXAGON_Y5_l2fetch((P0), (P1))

/* } Changed in Clang 11.0 */

/* Removed in Clang 11.0 { */

extern int
__coverity__builtin_HEXAGON_A2_pxorf(
    int __a,
    int __b,
    int __);
#define __builtin_HEXAGON_A2_pxorf(P0, P1, P2) \
    __coverity__builtin_HEXAGON_A2_pxorf((P0), (P1), (P2))

extern int
__coverity__builtin_HEXAGON_A2_tfrcrr(
    int __);
#define __builtin_HEXAGON_A2_tfrcrr(P0) \
    __coverity__builtin_HEXAGON_A2_tfrcrr((P0))

extern int
__coverity__builtin_HEXAGON_A2_tfrrcr(
    int __);
#define __builtin_HEXAGON_A2_tfrrcr(P0) \
    __coverity__builtin_HEXAGON_A2_tfrrcr((P0))

extern long long int
__coverity__builtin_HEXAGON_A4_addp_c(
    long long int __a,
    long long int __b,
    void *  __);
#define __builtin_HEXAGON_A4_addp_c(P0, P1, P2) \
    __coverity__builtin_HEXAGON_A4_addp_c((P0), (P1), (P2))

extern long long int
__coverity__builtin_HEXAGON_A4_combineii(
    const int __a,
    int __b,
    const unsigned int __c,
    int __);
#define __builtin_HEXAGON_A4_combineii(P0, P1, P2, P3) \
    __coverity__builtin_HEXAGON_A4_combineii((P0), (P1), (P2), (P3))

extern long long int
__coverity__builtin_HEXAGON_A4_subp_c(
    long long int __a,
    long long int __b,
    void *  __);
#define __builtin_HEXAGON_A4_subp_c(P0, P1, P2) \
    __coverity__builtin_HEXAGON_A4_subp_c((P0), (P1), (P2))

extern long long int
__coverity__builtin_HEXAGON_A4_tfrcpp(
    long long int __);
#define __builtin_HEXAGON_A4_tfrcpp(P0) \
    __coverity__builtin_HEXAGON_A4_tfrcpp((P0))

extern long long int
__coverity__builtin_HEXAGON_A4_tfrpcp(
    long long int __);
#define __builtin_HEXAGON_A4_tfrpcp(P0) \
    __coverity__builtin_HEXAGON_A4_tfrpcp((P0))

extern long long int
__coverity__builtin_HEXAGON_A5_ACS(
    long long int __a,
    long long int __b,
    long long int __);
#define __builtin_HEXAGON_A5_ACS(P0, P1, P2) \
    __coverity__builtin_HEXAGON_A5_ACS((P0), (P1), (P2))

extern float
__coverity__builtin_HEXAGON_F2_sfinvsqrta(
    float __);
#define __builtin_HEXAGON_F2_sfinvsqrta(P0) \
    __coverity__builtin_HEXAGON_F2_sfinvsqrta((P0))

extern float
__coverity__builtin_HEXAGON_F2_sfrecipa(
    float __a,
    float __);
#define __builtin_HEXAGON_F2_sfrecipa(P0, P1) \
    __coverity__builtin_HEXAGON_F2_sfrecipa((P0), (P1))

extern int
__coverity__builtin_HEXAGON_M2_mpysin(
    int __a,
    const unsigned int __b,
    int __);
#define __builtin_HEXAGON_M2_mpysin(P0, P1, P2) \
    __coverity__builtin_HEXAGON_M2_mpysin((P0), (P1), (P2))

extern int
__coverity__builtin_HEXAGON_M2_mpysip(
    int __a,
    const unsigned int __b,
    int __);
#define __builtin_HEXAGON_M2_mpysip(P0, P1, P2) \
    __coverity__builtin_HEXAGON_M2_mpysip((P0), (P1), (P2))

extern  int __attribute__((vector_size(64)))
__coverity__builtin_HEXAGON_V6_ld0(
    int __);
#define __builtin_HEXAGON_V6_ld0(P0) \
    __coverity__builtin_HEXAGON_V6_ld0((P0))

extern  int __attribute__((vector_size(128)))
__coverity__builtin_HEXAGON_V6_ld0_128B(
    int __);
#define __builtin_HEXAGON_V6_ld0_128B(P0) \
    __coverity__builtin_HEXAGON_V6_ld0_128B((P0))

extern  int __attribute__((vector_size(64)))
__coverity__builtin_HEXAGON_V6_ldcnp0(
    int __a,
    int __);
#define __builtin_HEXAGON_V6_ldcnp0(P0, P1) \
    __coverity__builtin_HEXAGON_V6_ldcnp0((P0), (P1))

extern  int __attribute__((vector_size(128)))
__coverity__builtin_HEXAGON_V6_ldcnp0_128B(
    int __a,
    int __);
#define __builtin_HEXAGON_V6_ldcnp0_128B(P0, P1) \
    __coverity__builtin_HEXAGON_V6_ldcnp0_128B((P0), (P1))

extern  int __attribute__((vector_size(64)))
__coverity__builtin_HEXAGON_V6_ldcnpnt0(
    int __a,
    int __);
#define __builtin_HEXAGON_V6_ldcnpnt0(P0, P1) \
    __coverity__builtin_HEXAGON_V6_ldcnpnt0((P0), (P1))

extern  int __attribute__((vector_size(128)))
__coverity__builtin_HEXAGON_V6_ldcnpnt0_128B(
    int __a,
    int __);
#define __builtin_HEXAGON_V6_ldcnpnt0_128B(P0, P1) \
    __coverity__builtin_HEXAGON_V6_ldcnpnt0_128B((P0), (P1))

extern  int __attribute__((vector_size(64)))
__coverity__builtin_HEXAGON_V6_ldcp0(
    int __a,
    int __);
#define __builtin_HEXAGON_V6_ldcp0(P0, P1) \
    __coverity__builtin_HEXAGON_V6_ldcp0((P0), (P1))

extern  int __attribute__((vector_size(128)))
__coverity__builtin_HEXAGON_V6_ldcp0_128B(
    int __a,
    int __);
#define __builtin_HEXAGON_V6_ldcp0_128B(P0, P1) \
    __coverity__builtin_HEXAGON_V6_ldcp0_128B((P0), (P1))

extern  int __attribute__((vector_size(64)))
__coverity__builtin_HEXAGON_V6_ldcpnt0(
    int __a,
    int __);
#define __builtin_HEXAGON_V6_ldcpnt0(P0, P1) \
    __coverity__builtin_HEXAGON_V6_ldcpnt0((P0), (P1))

extern  int __attribute__((vector_size(128)))
__coverity__builtin_HEXAGON_V6_ldcpnt0_128B(
    int __a,
    int __);
#define __builtin_HEXAGON_V6_ldcpnt0_128B(P0, P1) \
    __coverity__builtin_HEXAGON_V6_ldcpnt0_128B((P0), (P1))

extern  int __attribute__((vector_size(64)))
__coverity__builtin_HEXAGON_V6_ldnp0(
    int __a,
    int __);
#define __builtin_HEXAGON_V6_ldnp0(P0, P1) \
    __coverity__builtin_HEXAGON_V6_ldnp0((P0), (P1))

extern  int __attribute__((vector_size(128)))
__coverity__builtin_HEXAGON_V6_ldnp0_128B(
    int __a,
    int __);
#define __builtin_HEXAGON_V6_ldnp0_128B(P0, P1) \
    __coverity__builtin_HEXAGON_V6_ldnp0_128B((P0), (P1))

extern  int __attribute__((vector_size(64)))
__coverity__builtin_HEXAGON_V6_ldnpnt0(
    int __a,
    int __);
#define __builtin_HEXAGON_V6_ldnpnt0(P0, P1) \
    __coverity__builtin_HEXAGON_V6_ldnpnt0((P0), (P1))

extern  int __attribute__((vector_size(128)))
__coverity__builtin_HEXAGON_V6_ldnpnt0_128B(
    int __a,
    int __);
#define __builtin_HEXAGON_V6_ldnpnt0_128B(P0, P1) \
    __coverity__builtin_HEXAGON_V6_ldnpnt0_128B((P0), (P1))

extern  int __attribute__((vector_size(64)))
__coverity__builtin_HEXAGON_V6_ldnt0(
    int __);
#define __builtin_HEXAGON_V6_ldnt0(P0) \
    __coverity__builtin_HEXAGON_V6_ldnt0((P0))

extern  int __attribute__((vector_size(128)))
__coverity__builtin_HEXAGON_V6_ldnt0_128B(
    int __);
#define __builtin_HEXAGON_V6_ldnt0_128B(P0) \
    __coverity__builtin_HEXAGON_V6_ldnt0_128B((P0))

extern  int __attribute__((vector_size(64)))
__coverity__builtin_HEXAGON_V6_ldntnt0(
    int __);
#define __builtin_HEXAGON_V6_ldntnt0(P0) \
    __coverity__builtin_HEXAGON_V6_ldntnt0((P0))

extern  int __attribute__((vector_size(64)))
__coverity__builtin_HEXAGON_V6_ldp0(
    int __a,
    int __);
#define __builtin_HEXAGON_V6_ldp0(P0, P1) \
    __coverity__builtin_HEXAGON_V6_ldp0((P0), (P1))

extern  int __attribute__((vector_size(128)))
__coverity__builtin_HEXAGON_V6_ldp0_128B(
    int __a,
    int __);
#define __builtin_HEXAGON_V6_ldp0_128B(P0, P1) \
    __coverity__builtin_HEXAGON_V6_ldp0_128B((P0), (P1))

extern  int __attribute__((vector_size(64)))
__coverity__builtin_HEXAGON_V6_ldpnt0(
    int __a,
    int __);
#define __builtin_HEXAGON_V6_ldpnt0(P0, P1) \
    __coverity__builtin_HEXAGON_V6_ldpnt0((P0), (P1))

extern  int __attribute__((vector_size(128)))
__coverity__builtin_HEXAGON_V6_ldpnt0_128B(
    int __a,
    int __);
#define __builtin_HEXAGON_V6_ldpnt0_128B(P0, P1) \
    __coverity__builtin_HEXAGON_V6_ldpnt0_128B((P0), (P1))

extern  int __attribute__((vector_size(64)))
__coverity__builtin_HEXAGON_V6_ldtnp0(
    int __a,
    int __);
#define __builtin_HEXAGON_V6_ldtnp0(P0, P1) \
    __coverity__builtin_HEXAGON_V6_ldtnp0((P0), (P1))

extern  int __attribute__((vector_size(128)))
__coverity__builtin_HEXAGON_V6_ldtnp0_128B(
    int __a,
    int __);
#define __builtin_HEXAGON_V6_ldtnp0_128B(P0, P1) \
    __coverity__builtin_HEXAGON_V6_ldtnp0_128B((P0), (P1))

extern  int __attribute__((vector_size(64)))
__coverity__builtin_HEXAGON_V6_ldtnpnt0(
    int __a,
    int __);
#define __builtin_HEXAGON_V6_ldtnpnt0(P0, P1) \
    __coverity__builtin_HEXAGON_V6_ldtnpnt0((P0), (P1))

extern  int __attribute__((vector_size(128)))
__coverity__builtin_HEXAGON_V6_ldtnpnt0_128B(
    int __a,
    int __);
#define __builtin_HEXAGON_V6_ldtnpnt0_128B(P0, P1) \
    __coverity__builtin_HEXAGON_V6_ldtnpnt0_128B((P0), (P1))

extern  int __attribute__((vector_size(64)))
__coverity__builtin_HEXAGON_V6_ldtp0(
    int __a,
    int __);
#define __builtin_HEXAGON_V6_ldtp0(P0, P1) \
    __coverity__builtin_HEXAGON_V6_ldtp0((P0), (P1))

extern  int __attribute__((vector_size(128)))
__coverity__builtin_HEXAGON_V6_ldtp0_128B(
    int __a,
    int __);
#define __builtin_HEXAGON_V6_ldtp0_128B(P0, P1) \
    __coverity__builtin_HEXAGON_V6_ldtp0_128B((P0), (P1))

extern  int __attribute__((vector_size(64)))
__coverity__builtin_HEXAGON_V6_ldtpnt0(
    int __a,
    int __);
#define __builtin_HEXAGON_V6_ldtpnt0(P0, P1) \
    __coverity__builtin_HEXAGON_V6_ldtpnt0((P0), (P1))

extern  int __attribute__((vector_size(128)))
__coverity__builtin_HEXAGON_V6_ldtpnt0_128B(
    int __a,
    int __);
#define __builtin_HEXAGON_V6_ldtpnt0_128B(P0, P1) \
    __coverity__builtin_HEXAGON_V6_ldtpnt0_128B((P0), (P1))

extern  int __attribute__((vector_size(64)))
__coverity__builtin_HEXAGON_V6_ldu0(
    int __);
#define __builtin_HEXAGON_V6_ldu0(P0) \
    __coverity__builtin_HEXAGON_V6_ldu0((P0))

extern  int __attribute__((vector_size(128)))
__coverity__builtin_HEXAGON_V6_ldu0_128B(
    int __);
#define __builtin_HEXAGON_V6_ldu0_128B(P0) \
    __coverity__builtin_HEXAGON_V6_ldu0_128B((P0))

extern  int __attribute__((vector_size(64)))
__coverity__builtin_HEXAGON_V6_vtran2x2_map(
     int __attribute__((vector_size(64))) __a,
    void *  __b,
    int __);
#define __builtin_HEXAGON_V6_vtran2x2_map(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vtran2x2_map((P0), (P1), (P2))

extern  int __attribute__((vector_size(128)))
__coverity__builtin_HEXAGON_V6_vtran2x2_map_128B(
     int __attribute__((vector_size(128))) __a,
    void *  __b,
    int __);
#define __builtin_HEXAGON_V6_vtran2x2_map_128B(P0, P1, P2) \
    __coverity__builtin_HEXAGON_V6_vtran2x2_map_128B((P0), (P1), (P2))

extern void
__coverity__builtin_wasm_data_drop(
    const int __a,
    unsigned int __);
#define __builtin_wasm_data_drop(P0, P1) \
    __coverity__builtin_wasm_data_drop((P0), (P1))

extern void
__coverity__builtin_wasm_memory_init(
    const int __a,
    unsigned int __b,
    const int __c,
    unsigned int __d,
    void *  __e,
    unsigned int __f,
    unsigned int __);
#define __builtin_wasm_memory_init(P0, P1, P2, P3, P4, P5, P6) \
    __coverity__builtin_wasm_memory_init((P0), (P1), (P2), (P3), (P4), (P5), (P6))

extern  long long int __attribute__((vector_size(16)))
__coverity__builtin_wasm_trunc_saturate_s_i64x2_f64x2(
     double __attribute__((vector_size(16))) __);
#define __builtin_wasm_trunc_saturate_s_i64x2_f64x2(P0) \
    __coverity__builtin_wasm_trunc_saturate_s_i64x2_f64x2((P0))

extern  long long int __attribute__((vector_size(16)))
__coverity__builtin_wasm_trunc_saturate_u_i64x2_f64x2(
     double __attribute__((vector_size(16))) __);
#define __builtin_wasm_trunc_saturate_u_i64x2_f64x2(P0) \
    __coverity__builtin_wasm_trunc_saturate_u_i64x2_f64x2((P0))

/* } Removed in Clang 11.0 */


/* Apple Clang 12.0 (Clang 11.0) */
#if (__coverity_assume_xcode__ ) /* { */

// Changed in Apple Clang 12.0/12.1

extern unsigned long long
__coverity__builtin_rotateright64(
    unsigned long long __a,
    long long __b);
#define __builtin_rotateright64(P0, P1) \
    __coverity__builtin_rotateright64((P0), (P1))

/* } */
#endif // Apple Clang < 12.0

#endif // clang < 11.0


/*************************************
 ************ Clang 12.0 *************
 *************************************/

#if (__cov_clang_version_lt(12, 0)) /* { */
/* Removed in Clang 12.0 { */
extern unsigned int
__coverity__builtin_wasm_atomic_notify();
#define __builtin_wasm_atomic_notify() \
    __coverity__builtin_wasm_atomic_notify()

extern int
__coverity__builtin_wasm_atomic_wait_i32(
    int * __a,
    int __b,
    long long __c);
#define __builtin_wasm_atomic_wait_i32(P0, P1, P2) \
    __coverity__builtin_wasm_atomic_wait_i32((P0), (P1), (P2))

extern int
__coverity__builtin_wasm_atomic_wait_i64(
    long long * __a,
    long long __b,
    long long __c);
#define __builtin_wasm_atomic_wait_i64(P0, P1, P2) \
    __coverity__builtin_wasm_atomic_wait_i64((P0), (P1), (P2))

extern void
__coverity__builtin_wasm_rethrow_in_catch();
#define __builtin_wasm_rethrow_in_catch() \
    __coverity__builtin_wasm_rethrow_in_catch()

extern short __attribute__((vector_size(16)))
__coverity__builtin_wasm_widen_high_s_i16x8_i8x16(
    char __attribute__((vector_size(16))) __a);
#define __builtin_wasm_widen_high_s_i16x8_i8x16(P0) \
    __coverity__builtin_wasm_widen_high_s_i16x8_i8x16((P0))

extern int __attribute__((vector_size(16)))
__coverity__builtin_wasm_widen_high_s_i32x4_i16x8(
    short __attribute__((vector_size(16))) __);
#define __builtin_wasm_widen_high_s_i32x4_i16x8(P0) \
    __coverity__builtin_wasm_widen_high_s_i32x4_i16x8((P0))

extern short __attribute__((vector_size(16)))
__coverity__builtin_wasm_widen_high_u_i16x8_i8x16(
    char __attribute__((vector_size(16))) __);
#define __builtin_wasm_widen_high_u_i16x8_i8x16(P0) \
    __coverity__builtin_wasm_widen_high_u_i16x8_i8x16((P0))

extern int __attribute__((vector_size(16)))
__coverity__builtin_wasm_widen_high_u_i32x4_i16x8(
    short __attribute__((vector_size(16))) __);
#define __builtin_wasm_widen_high_u_i32x4_i16x8(P0) \
    __coverity__builtin_wasm_widen_high_u_i32x4_i16x8((P0))

extern short __attribute__((vector_size(16)))
__coverity__builtin_wasm_widen_low_s_i16x8_i8x16(
    char __attribute__((vector_size(16))) __);
#define __builtin_wasm_widen_low_s_i16x8_i8x16(P0) \
    __coverity__builtin_wasm_widen_low_s_i16x8_i8x16((P0))

extern int __attribute__((vector_size(16)))
__coverity__builtin_wasm_widen_low_s_i32x4_i16x8(
    short __attribute__((vector_size(16))) __);
#define __builtin_wasm_widen_low_s_i32x4_i16x8(P0) \
    __coverity__builtin_wasm_widen_low_s_i32x4_i16x8((P0))

extern short __attribute__((vector_size(16)))
__coverity__builtin_wasm_widen_low_u_i16x8_i8x16(
    char __attribute__((vector_size(16))) __);
#define __builtin_wasm_widen_low_u_i16x8_i8x16(P0) \
    __coverity__builtin_wasm_widen_low_u_i16x8_i8x16((P0))

extern int __attribute__((vector_size(16)))
__coverity__builtin_wasm_widen_low_u_i32x4_i16x8(
    short __attribute__((vector_size(16))) __);
#define __builtin_wasm_widen_low_u_i32x4_i16x8(P0) \
    __coverity__builtin_wasm_widen_low_u_i32x4_i16x8((P0))

/* } Removed in Clang 12.0 */

/* Apple Clang 13.0 (Clang 12.0) */
#if (__coverity_assume_xcode__ ) /* { */

// Changed in Apple Clang 13.0/13.1

/* } */
#endif // Apple Clang < 13.0

#endif // Clang 12.0

/*************************************
 ************ Clang 13.0 *************
 *************************************/

#if (__cov_clang_version_lt(13, 0)) /* { */

/* Removed in Clang 13.0 { */

extern  short __attribute__((vector_size(16)))
__coverity__builtin_wasm_add_saturate_s_i16x8(
     short __attribute__((vector_size(16))) __a,
     short __attribute__((vector_size(16))) __b);
#define __builtin_wasm_add_saturate_s_i16x8(P0, P1) \
    __coverity__builtin_wasm_add_saturate_s_i16x8((P0), (P1))

extern signed char __attribute__((vector_size(16)))
__coverity__builtin_wasm_add_saturate_s_i8x16(
    signed char __attribute__((vector_size(16))) __a,
    signed char __attribute__((vector_size(16))) __b);
#define __builtin_wasm_add_saturate_s_i8x16(P0, P1) \
    __coverity__builtin_wasm_add_saturate_s_i8x16((P0), (P1))

extern unsigned short __attribute__((vector_size(16)))
__coverity__builtin_wasm_add_saturate_u_i16x8(
    unsigned short __attribute__((vector_size(16))) __a,
    unsigned short __attribute__((vector_size(16))) __b);
#define __builtin_wasm_add_saturate_u_i16x8(P0, P1) \
    __coverity__builtin_wasm_add_saturate_u_i16x8((P0), (P1))

extern unsigned char __attribute__((vector_size(16)))
__coverity__builtin_wasm_add_saturate_u_i8x16(
    unsigned char __attribute__((vector_size(16))) __a,
    unsigned char __attribute__((vector_size(16))) __b);
#define __builtin_wasm_add_saturate_u_i8x16(P0, P1) \
    __coverity__builtin_wasm_add_saturate_u_i8x16((P0), (P1))

extern int
__coverity__builtin_wasm_any_true_i16x8(
     short __attribute__((vector_size(16))) __a);
#define __builtin_wasm_any_true_i16x8(P0) \
    __coverity__builtin_wasm_any_true_i16x8((P0))

extern int
__coverity__builtin_wasm_any_true_i32x4(
     int __attribute__((vector_size(16))) __a);
#define __builtin_wasm_any_true_i32x4(P0) \
    __coverity__builtin_wasm_any_true_i32x4((P0))

extern int
__coverity__builtin_wasm_any_true_i64x2(
     long long int __attribute__((vector_size(16))) __a);
#define __builtin_wasm_any_true_i64x2(P0) \
    __coverity__builtin_wasm_any_true_i64x2((P0))

extern int
__coverity__builtin_wasm_any_true_i8x16(
    signed char __attribute__((vector_size(16))) __a);
#define __builtin_wasm_any_true_i8x16(P0) \
    __coverity__builtin_wasm_any_true_i8x16((P0))

extern  double __attribute__((vector_size(16)))
__coverity__builtin_wasm_convert_low_s_i32x4_f64x2(
     int __attribute__((vector_size(16))) __a);
#define __builtin_wasm_convert_low_s_i32x4_f64x2(P0) \
    __coverity__builtin_wasm_convert_low_s_i32x4_f64x2((P0))

extern  double __attribute__((vector_size(16)))
__coverity__builtin_wasm_convert_low_u_i32x4_f64x2(
    unsigned int __attribute__((vector_size(16))) __a);
#define __builtin_wasm_convert_low_u_i32x4_f64x2(P0) \
    __coverity__builtin_wasm_convert_low_u_i32x4_f64x2((P0))

extern  float __attribute__((vector_size(16)))
__coverity__builtin_wasm_demote_zero_f64x2_f32x4(
     double __attribute__((vector_size(16))) __a);
#define __builtin_wasm_demote_zero_f64x2_f32x4(P0) \
    __coverity__builtin_wasm_demote_zero_f64x2_f32x4((P0))

extern  long long int __attribute__((vector_size(16)))
__coverity__builtin_wasm_eq_i64x2(
     long long int __attribute__((vector_size(16))) __a,
     long long int __attribute__((vector_size(16))) __b);
#define __builtin_wasm_eq_i64x2(P0, P1) \
    __coverity__builtin_wasm_eq_i64x2((P0), (P1))

extern  int __attribute__((vector_size(16)))
__coverity__builtin_wasm_extmul_high_i16x8_s_i32x4(
     short __attribute__((vector_size(16))) __a,
     short __attribute__((vector_size(16))) __b);
#define __builtin_wasm_extmul_high_i16x8_s_i32x4(P0, P1) \
    __coverity__builtin_wasm_extmul_high_i16x8_s_i32x4((P0), (P1))

extern unsigned int __attribute__((vector_size(16)))
__coverity__builtin_wasm_extmul_high_i16x8_u_i32x4(
    unsigned short __attribute__((vector_size(16))) __a,
    unsigned short __attribute__((vector_size(16))) __b);
#define __builtin_wasm_extmul_high_i16x8_u_i32x4(P0, P1) \
    __coverity__builtin_wasm_extmul_high_i16x8_u_i32x4((P0), (P1))

extern  long long int __attribute__((vector_size(16)))
__coverity__builtin_wasm_extmul_high_i32x4_s_i64x2(
     int __attribute__((vector_size(16))) __a,
     int __attribute__((vector_size(16))) __b);
#define __builtin_wasm_extmul_high_i32x4_s_i64x2(P0, P1) \
    __coverity__builtin_wasm_extmul_high_i32x4_s_i64x2((P0), (P1))

extern unsigned long long int __attribute__((vector_size(16)))
__coverity__builtin_wasm_extmul_high_i32x4_u_i64x2(
    unsigned int __attribute__((vector_size(16))) __a,
    unsigned int __attribute__((vector_size(16))) __b);
#define __builtin_wasm_extmul_high_i32x4_u_i64x2(P0, P1) \
    __coverity__builtin_wasm_extmul_high_i32x4_u_i64x2((P0), (P1))

extern  short __attribute__((vector_size(16)))
__coverity__builtin_wasm_extmul_high_i8x16_s_i16x8(
    signed char __attribute__((vector_size(16))) __a,
    signed char __attribute__((vector_size(16))) __b);
#define __builtin_wasm_extmul_high_i8x16_s_i16x8(P0, P1) \
    __coverity__builtin_wasm_extmul_high_i8x16_s_i16x8((P0), (P1))

extern unsigned short __attribute__((vector_size(16)))
__coverity__builtin_wasm_extmul_high_i8x16_u_i16x8(
    unsigned char __attribute__((vector_size(16))) __a,
    unsigned char __attribute__((vector_size(16))) __b);
#define __builtin_wasm_extmul_high_i8x16_u_i16x8(P0, P1) \
    __coverity__builtin_wasm_extmul_high_i8x16_u_i16x8((P0), (P1))

extern  int __attribute__((vector_size(16)))
__coverity__builtin_wasm_extmul_low_i16x8_s_i32x4(
     short __attribute__((vector_size(16))) __a,
     short __attribute__((vector_size(16))) __b);
#define __builtin_wasm_extmul_low_i16x8_s_i32x4(P0, P1) \
    __coverity__builtin_wasm_extmul_low_i16x8_s_i32x4((P0), (P1))

extern unsigned int __attribute__((vector_size(16)))
__coverity__builtin_wasm_extmul_low_i16x8_u_i32x4(
    unsigned short __attribute__((vector_size(16))) __a,
    unsigned short __attribute__((vector_size(16))) __b);
#define __builtin_wasm_extmul_low_i16x8_u_i32x4(P0, P1) \
    __coverity__builtin_wasm_extmul_low_i16x8_u_i32x4((P0), (P1))

extern  long long int __attribute__((vector_size(16)))
__coverity__builtin_wasm_extmul_low_i32x4_s_i64x2(
     int __attribute__((vector_size(16))) __a,
     int __attribute__((vector_size(16))) __b);
#define __builtin_wasm_extmul_low_i32x4_s_i64x2(P0, P1) \
    __coverity__builtin_wasm_extmul_low_i32x4_s_i64x2((P0), (P1))

extern unsigned long long int __attribute__((vector_size(16)))
__coverity__builtin_wasm_extmul_low_i32x4_u_i64x2(
    unsigned int __attribute__((vector_size(16))) __a,
    unsigned int __attribute__((vector_size(16))) __b);
#define __builtin_wasm_extmul_low_i32x4_u_i64x2(P0, P1) \
    __coverity__builtin_wasm_extmul_low_i32x4_u_i64x2((P0), (P1))

extern  short __attribute__((vector_size(16)))
__coverity__builtin_wasm_extmul_low_i8x16_s_i16x8(
    signed char __attribute__((vector_size(16))) __a,
    signed char __attribute__((vector_size(16))) __b);
#define __builtin_wasm_extmul_low_i8x16_s_i16x8(P0, P1) \
    __coverity__builtin_wasm_extmul_low_i8x16_s_i16x8((P0), (P1))

extern unsigned short __attribute__((vector_size(16)))
__coverity__builtin_wasm_extmul_low_i8x16_u_i16x8(
    unsigned char __attribute__((vector_size(16))) __a,
    unsigned char __attribute__((vector_size(16))) __b);
#define __builtin_wasm_extmul_low_i8x16_u_i16x8(P0, P1) \
    __coverity__builtin_wasm_extmul_low_i8x16_u_i16x8((P0), (P1))

extern float
__coverity__builtin_wasm_extract_lane_f32x4(
     float __attribute__((vector_size(16))) __a,
    const int __b,
    int __c);
#define __builtin_wasm_extract_lane_f32x4(P0, P1, P2) \
    __coverity__builtin_wasm_extract_lane_f32x4((P0), (P1), (P2))

extern double
__coverity__builtin_wasm_extract_lane_f64x2(
     double __attribute__((vector_size(16))) __a,
    const int __b,
    int __c);
#define __builtin_wasm_extract_lane_f64x2(P0, P1, P2) \
    __coverity__builtin_wasm_extract_lane_f64x2((P0), (P1), (P2))

extern int
__coverity__builtin_wasm_extract_lane_i32x4(
     int __attribute__((vector_size(16))) __a,
    const int __b,
    int __c);
#define __builtin_wasm_extract_lane_i32x4(P0, P1, P2) \
    __coverity__builtin_wasm_extract_lane_i32x4((P0), (P1), (P2))

extern long long int
__coverity__builtin_wasm_extract_lane_i64x2(
     long long int __attribute__((vector_size(16))) __a,
    const int __b,
    int __c);
#define __builtin_wasm_extract_lane_i64x2(P0, P1, P2) \
    __coverity__builtin_wasm_extract_lane_i64x2((P0), (P1), (P2))

extern int
__coverity__builtin_wasm_extract_lane_s_i16x8(
     short __attribute__((vector_size(16))) __a,
    const int __b,
    int __c);
#define __builtin_wasm_extract_lane_s_i16x8(P0, P1, P2) \
    __coverity__builtin_wasm_extract_lane_s_i16x8((P0), (P1), (P2))

extern int
__coverity__builtin_wasm_extract_lane_s_i8x16(
    signed char __attribute__((vector_size(16))) __a,
    const int __b,
    int __c);
#define __builtin_wasm_extract_lane_s_i8x16(P0, P1, P2) \
    __coverity__builtin_wasm_extract_lane_s_i8x16((P0), (P1), (P2))

extern int
__coverity__builtin_wasm_extract_lane_u_i16x8(
    unsigned short __attribute__((vector_size(16))) __a,
    const int __b,
    unsigned int __c);
#define __builtin_wasm_extract_lane_u_i16x8(P0, P1, P2) \
    __coverity__builtin_wasm_extract_lane_u_i16x8((P0), (P1), (P2))

extern int
__coverity__builtin_wasm_extract_lane_u_i8x16(
    unsigned char __attribute__((vector_size(16))) __a,
    const int __b,
    unsigned int __c);
#define __builtin_wasm_extract_lane_u_i8x16(P0, P1, P2) \
    __coverity__builtin_wasm_extract_lane_u_i8x16((P0), (P1), (P2))

extern  short __attribute__((vector_size(16)))
__coverity__builtin_wasm_load16_lane(
    short *  __a,
     short __attribute__((vector_size(16))) __b,
    const int __c,
    int __d);
#define __builtin_wasm_load16_lane(P0, P1, P2, P3) \
    __coverity__builtin_wasm_load16_lane((P0), (P1), (P2), (P3))

extern  int __attribute__((vector_size(16)))
__coverity__builtin_wasm_load32_lane(
    int *  __a,
     int __attribute__((vector_size(16))) __b,
    const int __c,
    int __d);
#define __builtin_wasm_load32_lane(P0, P1, P2, P3) \
    __coverity__builtin_wasm_load32_lane((P0), (P1), (P2), (P3))

extern  int __attribute__((vector_size(16)))
__coverity__builtin_wasm_load32_zero(
    int *  __a);
#define __builtin_wasm_load32_zero(P0) \
    __coverity__builtin_wasm_load32_zero((P0))

extern  long long int __attribute__((vector_size(16)))
__coverity__builtin_wasm_load64_lane(
    long long int *  __a,
     long long int __attribute__((vector_size(16))) __b,
    const int __c,
    int __d);
#define __builtin_wasm_load64_lane(P0, P1, P2, P3) \
    __coverity__builtin_wasm_load64_lane((P0), (P1), (P2), (P3))

extern  long long int __attribute__((vector_size(16)))
__coverity__builtin_wasm_load64_zero(
    long long int *  __a);
#define __builtin_wasm_load64_zero(P0) \
    __coverity__builtin_wasm_load64_zero((P0))

extern signed char __attribute__((vector_size(16)))
__coverity__builtin_wasm_load8_lane(
    signed char *  __a,
    signed char __attribute__((vector_size(16))) __b,
    const int __c,
    int __d);
#define __builtin_wasm_load8_lane(P0, P1, P2, P3) \
    __coverity__builtin_wasm_load8_lane((P0), (P1), (P2), (P3))

extern  float __attribute__((vector_size(16)))
__coverity__builtin_wasm_pmax_f32x4(
     float __attribute__((vector_size(16))) __a,
     float __attribute__((vector_size(16))) __b);
#define __builtin_wasm_pmax_f32x4(P0, P1) \
    __coverity__builtin_wasm_pmax_f32x4((P0), (P1))

extern  double __attribute__((vector_size(16)))
__coverity__builtin_wasm_pmax_f64x2(
     double __attribute__((vector_size(16))) __a,
     double __attribute__((vector_size(16))) __b);
#define __builtin_wasm_pmax_f64x2(P0, P1) \
    __coverity__builtin_wasm_pmax_f64x2((P0), (P1))

extern  float __attribute__((vector_size(16)))
__coverity__builtin_wasm_pmin_f32x4(
     float __attribute__((vector_size(16))) __a,
     float __attribute__((vector_size(16))) __b);
#define __builtin_wasm_pmin_f32x4(P0, P1) \
    __coverity__builtin_wasm_pmin_f32x4((P0), (P1))

extern  double __attribute__((vector_size(16)))
__coverity__builtin_wasm_pmin_f64x2(
     double __attribute__((vector_size(16))) __a,
     double __attribute__((vector_size(16))) __b);
#define __builtin_wasm_pmin_f64x2(P0, P1) \
    __coverity__builtin_wasm_pmin_f64x2((P0), (P1))

extern void
__coverity__builtin_wasm_prefetch_nt(
    void *  __a);
#define __builtin_wasm_prefetch_nt(P0) \
    __coverity__builtin_wasm_prefetch_nt((P0))

extern void
__coverity__builtin_wasm_prefetch_t(
    void *  __a);
#define __builtin_wasm_prefetch_t(P0) \
    __coverity__builtin_wasm_prefetch_t((P0))

extern  double __attribute__((vector_size(16)))
__coverity__builtin_wasm_promote_low_f32x4_f64x2(
     float __attribute__((vector_size(16))) __a);
#define __builtin_wasm_promote_low_f32x4_f64x2(P0) \
    __coverity__builtin_wasm_promote_low_f32x4_f64x2((P0))

extern  short __attribute__((vector_size(16)))
__coverity__builtin_wasm_q15mulr_saturate_s_i16x8(
     short __attribute__((vector_size(16))) __a,
     short __attribute__((vector_size(16))) __b);
#define __builtin_wasm_q15mulr_saturate_s_i16x8(P0, P1) \
    __coverity__builtin_wasm_q15mulr_saturate_s_i16x8((P0), (P1))

extern  float __attribute__((vector_size(16)))
__coverity__builtin_wasm_qfma_f32x4(
     float __attribute__((vector_size(16))) __a,
     float __attribute__((vector_size(16))) __b,
     float __attribute__((vector_size(16))) __c);
#define __builtin_wasm_qfma_f32x4(P0, P1, P2) \
    __coverity__builtin_wasm_qfma_f32x4((P0), (P1), (P2))

extern  double __attribute__((vector_size(16)))
__coverity__builtin_wasm_qfma_f64x2(
     double __attribute__((vector_size(16))) __a,
     double __attribute__((vector_size(16))) __b,
     double __attribute__((vector_size(16))) __c);
#define __builtin_wasm_qfma_f64x2(P0, P1, P2) \
    __coverity__builtin_wasm_qfma_f64x2((P0), (P1), (P2))

extern  float __attribute__((vector_size(16)))
__coverity__builtin_wasm_qfms_f32x4(
     float __attribute__((vector_size(16))) __a,
     float __attribute__((vector_size(16))) __b,
     float __attribute__((vector_size(16))) __c);
#define __builtin_wasm_qfms_f32x4(P0, P1, P2) \
    __coverity__builtin_wasm_qfms_f32x4((P0), (P1), (P2))

extern  double __attribute__((vector_size(16)))
__coverity__builtin_wasm_qfms_f64x2(
     double __attribute__((vector_size(16))) __a,
     double __attribute__((vector_size(16))) __b,
     double __attribute__((vector_size(16))) __c);
#define __builtin_wasm_qfms_f64x2(P0, P1, P2) \
    __coverity__builtin_wasm_qfms_f64x2((P0), (P1), (P2))

extern  float __attribute__((vector_size(16)))
__coverity__builtin_wasm_replace_lane_f32x4(
     float __attribute__((vector_size(16))) __a,
    const int __b,
    int __c,
    float __d);
#define __builtin_wasm_replace_lane_f32x4(P0, P1, P2, P3) \
    __coverity__builtin_wasm_replace_lane_f32x4((P0), (P1), (P2), (P3))

extern  double __attribute__((vector_size(16)))
__coverity__builtin_wasm_replace_lane_f64x2(
     double __attribute__((vector_size(16))) __a,
    const int __b,
    int __c,
    double __d);
#define __builtin_wasm_replace_lane_f64x2(P0, P1, P2, P3) \
    __coverity__builtin_wasm_replace_lane_f64x2((P0), (P1), (P2), (P3))

extern  short __attribute__((vector_size(16)))
__coverity__builtin_wasm_replace_lane_i16x8(
     short __attribute__((vector_size(16))) __a,
    const int __b,
    int __c,
    int __d);
#define __builtin_wasm_replace_lane_i16x8(P0, P1, P2, P3) \
    __coverity__builtin_wasm_replace_lane_i16x8((P0), (P1), (P2), (P3))

extern  int __attribute__((vector_size(16)))
__coverity__builtin_wasm_replace_lane_i32x4(
     int __attribute__((vector_size(16))) __a,
    const int __b,
    int __c,
    int __d);
#define __builtin_wasm_replace_lane_i32x4(P0, P1, P2, P3) \
    __coverity__builtin_wasm_replace_lane_i32x4((P0), (P1), (P2), (P3))

extern  long long int __attribute__((vector_size(16)))
__coverity__builtin_wasm_replace_lane_i64x2(
     long long int __attribute__((vector_size(16))) __a,
    const int __b,
    int __c,
    long long int __d);
#define __builtin_wasm_replace_lane_i64x2(P0, P1, P2, P3) \
    __coverity__builtin_wasm_replace_lane_i64x2((P0), (P1), (P2), (P3))

extern signed char __attribute__((vector_size(16)))
__coverity__builtin_wasm_replace_lane_i8x16(
    signed char __attribute__((vector_size(16))) __a,
    const int __b,
    int __c,
    int __d);
#define __builtin_wasm_replace_lane_i8x16(P0, P1, P2, P3) \
    __coverity__builtin_wasm_replace_lane_i8x16((P0), (P1), (P2), (P3))

extern signed char __attribute__((vector_size(16)))
__coverity__builtin_wasm_shuffle_v8x16(
    signed char __attribute__((vector_size(16))) __a,
    signed char __attribute__((vector_size(16))) __b,
    const int __c,
    int __d,
    const int __e,
    int __f,
    const int __g,
    int __h,
    const int __i,
    int __j,
    const int __k,
    int __l,
    const int __m,
    int __n,
    const int __o,
    int __p,
    const int __q,
    int __r,
    const int _s,
    int __t,
    const int __u,
    int __v,
    const int __x,
    int __y,
    const int __z,
    int __aa,
    const int __bb,
    int __cc,
    const int __dd,
    int __ee,
    const int __ff,
    int __gg,
    const int __hh,
    int __ii);
#define __builtin_wasm_shuffle_v8x16(P0, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15, P16, P17, P18, P19, P20, P21, P22, P23, P24, P25, P26, P27, P28, P29, P30, P31, P32, P33) \
    __coverity__builtin_wasm_shuffle_v8x16((P0), (P1), (P2), (P3), (P4), (P5), (P6), (P7), (P8), (P9), (P10), (P11), (P12), (P13), (P14), (P15), (P16), (P17), (P18), (P19), (P20), (P21), (P22), (P23), (P24), (P25), (P26), (P27), (P28), (P29), (P30), (P31), (P32), (P33))

extern  short __attribute__((vector_size(16)))
__coverity__builtin_wasm_signselect_i16x8(
     short __attribute__((vector_size(16))) __a,
     short __attribute__((vector_size(16))) __b,
     short __attribute__((vector_size(16))) __c);
#define __builtin_wasm_signselect_i16x8(P0, P1, P2) \
    __coverity__builtin_wasm_signselect_i16x8((P0), (P1), (P2))

extern  int __attribute__((vector_size(16)))
__coverity__builtin_wasm_signselect_i32x4(
     int __attribute__((vector_size(16))) __a,
     int __attribute__((vector_size(16))) __b,
     int __attribute__((vector_size(16))) __c);
#define __builtin_wasm_signselect_i32x4(P0, P1, P2) \
    __coverity__builtin_wasm_signselect_i32x4((P0), (P1), (P2))

extern  long long int __attribute__((vector_size(16)))
__coverity__builtin_wasm_signselect_i64x2(
     long long int __attribute__((vector_size(16))) __a,
     long long int __attribute__((vector_size(16))) __b,
     long long int __attribute__((vector_size(16))) __c);
#define __builtin_wasm_signselect_i64x2(P0, P1, P2) \
    __coverity__builtin_wasm_signselect_i64x2((P0), (P1), (P2))

extern signed char __attribute__((vector_size(16)))
__coverity__builtin_wasm_signselect_i8x16(
    signed char __attribute__((vector_size(16))) __a,
    signed char __attribute__((vector_size(16))) __b,
    signed char __attribute__((vector_size(16))) __c);
#define __builtin_wasm_signselect_i8x16(P0, P1, P2) \
    __coverity__builtin_wasm_signselect_i8x16((P0), (P1), (P2))

extern void
__coverity__builtin_wasm_store16_lane(
    short *  __a,
     short __attribute__((vector_size(16))) __b,
    const int __c,
    int __d);
#define __builtin_wasm_store16_lane(P0, P1, P2, P3) \
    __coverity__builtin_wasm_store16_lane((P0), (P1), (P2), (P3))

extern void
__coverity__builtin_wasm_store32_lane(
    int *  __a,
     int __attribute__((vector_size(16))) __b,
    const int __c,
    int __d);
#define __builtin_wasm_store32_lane(P0, P1, P2, P3) \
    __coverity__builtin_wasm_store32_lane((P0), (P1), (P2), (P3))

extern void
__coverity__builtin_wasm_store64_lane(
    long long int *  __a,
     long long int __attribute__((vector_size(16))) __b,
    const int __c,
    int __d);
#define __builtin_wasm_store64_lane(P0, P1, P2, P3) \
    __coverity__builtin_wasm_store64_lane((P0), (P1), (P2), (P3))

extern void
__coverity__builtin_wasm_store8_lane(
    signed char *  __a,
    signed char __attribute__((vector_size(16))) __b,
    const int __c,
    int __d);
#define __builtin_wasm_store8_lane(P0, P1, P2, P3) \
    __coverity__builtin_wasm_store8_lane((P0), (P1), (P2), (P3))

extern  short __attribute__((vector_size(16)))
__coverity__builtin_wasm_sub_saturate_s_i16x8(
     short __attribute__((vector_size(16))) __a,
     short __attribute__((vector_size(16))) __b);
#define __builtin_wasm_sub_saturate_s_i16x8(P0, P1) \
    __coverity__builtin_wasm_sub_saturate_s_i16x8((P0), (P1))

extern signed char __attribute__((vector_size(16)))
__coverity__builtin_wasm_sub_saturate_s_i8x16(
    signed char __attribute__((vector_size(16))) __a,
    signed char __attribute__((vector_size(16))) __b);
#define __builtin_wasm_sub_saturate_s_i8x16(P0, P1) \
    __coverity__builtin_wasm_sub_saturate_s_i8x16((P0), (P1))

extern unsigned short __attribute__((vector_size(16)))
__coverity__builtin_wasm_sub_saturate_u_i16x8(
    unsigned short __attribute__((vector_size(16))) __a,
    unsigned short __attribute__((vector_size(16))) __b);
#define __builtin_wasm_sub_saturate_u_i16x8(P0, P1) \
    __coverity__builtin_wasm_sub_saturate_u_i16x8((P0), (P1))

extern unsigned char __attribute__((vector_size(16)))
__coverity__builtin_wasm_sub_saturate_u_i8x16(
    unsigned char __attribute__((vector_size(16))) __a,
    unsigned char __attribute__((vector_size(16))) __b);
#define __builtin_wasm_sub_saturate_u_i8x16(P0, P1) \
    __coverity__builtin_wasm_sub_saturate_u_i8x16((P0), (P1))

extern signed char __attribute__((vector_size(16)))
__coverity__builtin_wasm_swizzle_v8x16(
    signed char __attribute__((vector_size(16))) __a,
    signed char __attribute__((vector_size(16))) __b);
#define __builtin_wasm_swizzle_v8x16(P0, P1) \
    __coverity__builtin_wasm_swizzle_v8x16((P0), (P1))

extern  int __attribute__((vector_size(16)))
__coverity__builtin_wasm_trunc_saturate_zero_s_f64x2_i32x4(
     double __attribute__((vector_size(16))) __a);
#define __builtin_wasm_trunc_saturate_zero_s_f64x2_i32x4(P0) \
    __coverity__builtin_wasm_trunc_saturate_zero_s_f64x2_i32x4((P0))

extern unsigned int __attribute__((vector_size(16)))
__coverity__builtin_wasm_trunc_saturate_zero_u_f64x2_i32x4(
     double __attribute__((vector_size(16))) __a);
#define __builtin_wasm_trunc_saturate_zero_u_f64x2_i32x4(P0) \
    __coverity__builtin_wasm_trunc_saturate_zero_u_f64x2_i32x4((P0))

extern  long long int __attribute__((vector_size(16)))
__coverity__builtin_wasm_widen_high_s_i32x4_i64x2(
     int __attribute__((vector_size(16))) __a);
#define __builtin_wasm_widen_high_s_i32x4_i64x2(P0) \
    __coverity__builtin_wasm_widen_high_s_i32x4_i64x2((P0))

extern  long long int __attribute__((vector_size(16)))
__coverity__builtin_wasm_widen_high_u_i32x4_i64x2(
    int __a,
    unsigned int __attribute__((vector_size(16))) __b);
#define __builtin_wasm_widen_high_u_i32x4_i64x2(P0, P1) \
    __coverity__builtin_wasm_widen_high_u_i32x4_i64x2((P0), (P1))

extern  long long int __attribute__((vector_size(16)))
__coverity__builtin_wasm_widen_low_s_i32x4_i64x2(
     int __attribute__((vector_size(16))) __a);
#define __builtin_wasm_widen_low_s_i32x4_i64x2(P0) \
    __coverity__builtin_wasm_widen_low_s_i32x4_i64x2((P0))

extern  long long int __attribute__((vector_size(16)))
__coverity__builtin_wasm_widen_low_u_i32x4_i64x2(
    int __a,
    unsigned int __attribute__((vector_size(16))) __b);
#define __builtin_wasm_widen_low_u_i32x4_i64x2(P0, P1) \
    __coverity__builtin_wasm_widen_low_u_i32x4_i64x2((P0), (P1))

/* } Removed in Clang 13.0 */

/* Signatures changed in Clang 13.0 { */

/* _InterlockedAnd64("LLiLLiD*LLi" vs. "WiWiD*Wi") differs only in W(int64_t) vs LL(long long): Not generated */
/* _InterlockedAnd64("WiWiD*Wi" vs. "LLiLLiD*LLi") differs only in W(int64_t) vs LL(long long): Not generated */
/* _InterlockedDecrement64("LLiLLiD*" vs. "WiWiD*") differs only in W(int64_t) vs LL(long long): Not generated */
/* _InterlockedDecrement64("WiWiD*" vs. "LLiLLiD*") differs only in W(int64_t) vs LL(long long): Not generated */
/* _InterlockedExchange64("LLiLLiD*LLi" vs. "WiWiD*Wi") differs only in W(int64_t) vs LL(long long): Not generated */
/* _InterlockedExchange64("WiWiD*Wi" vs. "LLiLLiD*LLi") differs only in W(int64_t) vs LL(long long): Not generated */
/* _InterlockedExchangeAdd64("LLiLLiD*LLi" vs. "WiWiD*Wi") differs only in W(int64_t) vs LL(long long): Not generated */
/* _InterlockedExchangeAdd64("WiWiD*Wi" vs. "LLiLLiD*LLi") differs only in W(int64_t) vs LL(long long): Not generated */
/* _InterlockedExchangeSub64("LLiLLiD*LLi" vs. "WiWiD*Wi") differs only in W(int64_t) vs LL(long long): Not generated */
/* _InterlockedExchangeSub64("WiWiD*Wi" vs. "LLiLLiD*LLi") differs only in W(int64_t) vs LL(long long): Not generated */
/* _InterlockedIncrement64("LLiLLiD*" vs. "WiWiD*") differs only in W(int64_t) vs LL(long long): Not generated */
/* _InterlockedIncrement64("WiWiD*" vs. "LLiLLiD*") differs only in W(int64_t) vs LL(long long): Not generated */
/* _InterlockedOr64("LLiLLiD*LLi" vs. "WiWiD*Wi") differs only in W(int64_t) vs LL(long long): Not generated */
/* _InterlockedOr64("WiWiD*Wi" vs. "LLiLLiD*LLi") differs only in W(int64_t) vs LL(long long): Not generated */
/* _InterlockedXor64("LLiLLiD*LLi" vs. "WiWiD*Wi") differs only in W(int64_t) vs LL(long long): Not generated */
/* _InterlockedXor64("WiWiD*Wi" vs. "LLiLLiD*LLi") differs only in W(int64_t) vs LL(long long): Not generated */
extern  char __attribute__((vector_size(16)))
__coverity__builtin_altivec_lvebx(
    int __a,
    const void *  __b);
#define __builtin_altivec_lvebx(P0, P1) \
    __coverity__builtin_altivec_lvebx((P0), (P1))

extern  short __attribute__((vector_size(16)))
__coverity__builtin_altivec_lvehx(
    int __a,
    const void *  __b);
#define __builtin_altivec_lvehx(P0, P1) \
    __coverity__builtin_altivec_lvehx((P0), (P1))

extern  int __attribute__((vector_size(16)))
__coverity__builtin_altivec_lvewx(
    int __a,
    const void *  __b);
#define __builtin_altivec_lvewx(P0, P1) \
    __coverity__builtin_altivec_lvewx((P0), (P1))

extern  int __attribute__((vector_size(16)))
__coverity__builtin_altivec_lvx(
    int __a,
    const void *  __b);
#define __builtin_altivec_lvx(P0, P1) \
    __coverity__builtin_altivec_lvx((P0), (P1))

extern  int __attribute__((vector_size(16)))
__coverity__builtin_altivec_lvxl(
    int __a,
    const void *  __b);
#define __builtin_altivec_lvxl(P0, P1) \
    __coverity__builtin_altivec_lvxl((P0), (P1))

extern void
__coverity__builtin_altivec_stvebx(
     char __attribute__((vector_size(16))) __a,
    int __b,
    void *  __c);
#define __builtin_altivec_stvebx(P0, P1, P2) \
    __coverity__builtin_altivec_stvebx((P0), (P1), (P2))

extern void
__coverity__builtin_altivec_stvehx(
     short __attribute__((vector_size(16))) __a,
    int __b,
    void *  __c);
#define __builtin_altivec_stvehx(P0, P1, P2) \
    __coverity__builtin_altivec_stvehx((P0), (P1), (P2))

extern void
__coverity__builtin_altivec_stvewx(
     int __attribute__((vector_size(16))) __a,
    int __b,
    void *  __c);
#define __builtin_altivec_stvewx(P0, P1, P2) \
    __coverity__builtin_altivec_stvewx((P0), (P1), (P2))

extern void
__coverity__builtin_altivec_stvx(
     int __attribute__((vector_size(16))) __a,
    int __b,
    void *  __c);
#define __builtin_altivec_stvx(P0, P1, P2) \
    __coverity__builtin_altivec_stvx((P0), (P1), (P2))

extern void
__coverity__builtin_altivec_stvxl(
     int __attribute__((vector_size(16))) __a,
    int __b,
    void *  __c);
#define __builtin_altivec_stvxl(P0, P1, P2) \
    __coverity__builtin_altivec_stvxl((P0), (P1), (P2))

/* __builtin_amdgcn_fcmp("LUiddIi" vs. "WUiddIi") differs only in return type: Not generated */
/* __builtin_amdgcn_fcmpf("LUiffIi" vs. "WUiffIi") differs only in return type: Not generated */
extern unsigned long int
__coverity__builtin_amdgcn_mqsad_pk_u16_u8(
    unsigned long int __a,
    unsigned int __b,
    unsigned long int __c);
#define __builtin_amdgcn_mqsad_pk_u16_u8(P0, P1, P2) \
    __coverity__builtin_amdgcn_mqsad_pk_u16_u8((P0), (P1), (P2))

extern unsigned int __attribute__((vector_size(16)))
__coverity__builtin_amdgcn_mqsad_u32_u8(
    unsigned long int __a,
    unsigned int __b,
    unsigned int __attribute__((vector_size(16))) __c);
#define __builtin_amdgcn_mqsad_u32_u8(P0, P1, P2) \
    __coverity__builtin_amdgcn_mqsad_u32_u8((P0), (P1), (P2))

extern unsigned long int
__coverity__builtin_amdgcn_qsad_pk_u16_u8(
    unsigned long int __a,
    unsigned int __b,
    unsigned long int __c);
#define __builtin_amdgcn_qsad_pk_u16_u8(P0, P1, P2) \
    __coverity__builtin_amdgcn_qsad_pk_u16_u8((P0), (P1), (P2))

/* __builtin_amdgcn_read_exec("LUi" vs. "WUi") differs only in return type: Not generated */
/* __builtin_amdgcn_s_getpc("LUi" vs. "WUi") differs only in return type: Not generated */
/* __builtin_amdgcn_s_memrealtime("LUi" vs. "WUi") differs only in return type: Not generated */
/* __builtin_amdgcn_s_memtime("LUi" vs. "WUi") differs only in return type: Not generated */
/* __builtin_amdgcn_sicmp("LUiiiIi" vs. "WUiiiIi") differs only in return type: Not generated */
extern unsigned long int
__coverity__builtin_amdgcn_sicmpl(
    long int __a,
    long int __b,
    const int __c,
    int __d);
#define __builtin_amdgcn_sicmpl(P0, P1, P2, P3) \
    __coverity__builtin_amdgcn_sicmpl((P0), (P1), (P2), (P3))

/* __builtin_amdgcn_uicmp("LUiUiUiIi" vs. "WUiUiUiIi") differs only in return type: Not generated */
extern unsigned long int
__coverity__builtin_amdgcn_uicmpl(
    unsigned long int __a,
    unsigned long int __b,
    const int __c,
    int __d);
#define __builtin_amdgcn_uicmpl(P0, P1, P2, P3) \
    __coverity__builtin_amdgcn_uicmpl((P0), (P1), (P2), (P3))

/* __builtin_arm_crc32cd("UiUiLLUi" vs. "UiUiWUi") differs only in W(int64_t) vs LL(long long): Not generated */
/* __builtin_arm_crc32cd("UiUiWUi" vs. "UiUiLLUi") differs only in W(int64_t) vs LL(long long): Not generated */
/* __builtin_arm_crc32d("UiUiLLUi" vs. "UiUiWUi") differs only in W(int64_t) vs LL(long long): Not generated */
/* __builtin_arm_crc32d("UiUiWUi" vs. "UiUiLLUi") differs only in W(int64_t) vs LL(long long): Not generated */
/* __builtin_arm_rsr64("LLUicC*" vs. "WUicC*") differs only in W(int64_t) vs LL(long long): Not generated */
/* __builtin_arm_rsr64("WUicC*" vs. "LLUicC*") differs only in W(int64_t) vs LL(long long): Not generated */
/* __builtin_arm_wsr64("vcC*LLUi" vs. "vcC*WUi") differs only in W(int64_t) vs LL(long long): Not generated */
/* __builtin_arm_wsr64("vcC*WUi" vs. "vcC*LLUi") differs only in W(int64_t) vs LL(long long): Not generated */

#if defined(__ARM_FEATURE_SVE) /* { */

extern __SVBool_t
__coverity__builtin_sve_svdup_n_b16(
    short __a);
#define __builtin_sve_svdup_n_b16(P0) \
    __coverity__builtin_sve_svdup_n_b16((P0))

extern __SVBool_t
__coverity__builtin_sve_svdup_n_b32(
    int __a);
#define __builtin_sve_svdup_n_b32(P0) \
    __coverity__builtin_sve_svdup_n_b32((P0))

extern __SVBool_t
__coverity__builtin_sve_svdup_n_b64(
    int64_t __a);
#define __builtin_sve_svdup_n_b64(P0) \
    __coverity__builtin_sve_svdup_n_b64((P0))

extern __SVBool_t
__coverity__builtin_sve_svdup_n_b8(
    signed char __a);
#define __builtin_sve_svdup_n_b8(P0) \
    __coverity__builtin_sve_svdup_n_b8((P0))

extern __SVBool_t
__coverity__builtin_sve_svdupq_n_b16(
    short __a,
    short __b,
    short __c,
    short __d,
    short __e,
    short __f,
    short __g,
    short __h);
#define __builtin_sve_svdupq_n_b16(P0, P1, P2, P3, P4, P5, P6, P7) \
    __coverity__builtin_sve_svdupq_n_b16((P0), (P1), (P2), (P3), (P4), (P5), (P6), (P7))

extern __SVBool_t
__coverity__builtin_sve_svdupq_n_b32(
    int __a,
    int __b,
    int __c,
    int __d);
#define __builtin_sve_svdupq_n_b32(P0, P1, P2, P3) \
    __coverity__builtin_sve_svdupq_n_b32((P0), (P1), (P2), (P3))

extern __SVBool_t
__coverity__builtin_sve_svdupq_n_b64(
    int64_t __a,
    int64_t __b);
#define __builtin_sve_svdupq_n_b64(P0, P1) \
    __coverity__builtin_sve_svdupq_n_b64((P0), (P1))

extern __SVBool_t
__coverity__builtin_sve_svdupq_n_b8(
    signed char __a,
    signed char __b,
    signed char __c,
    signed char __d,
    signed char __e,
    signed char __f,
    signed char __g,
    signed char __h,
    signed char __i,
    signed char __j,
    signed char __k,
    signed char __l,
    signed char __m,
    signed char __n,
    signed char __o,
    signed char __p);
#define __builtin_sve_svdupq_n_b8(P0, P1, P2, P3, P4, P5, P6, P7, P8, P9, P10, P11, P12, P13, P14, P15) \
    __coverity__builtin_sve_svdupq_n_b8((P0), (P1), (P2), (P3), (P4), (P5), (P6), (P7), (P8), (P9), (P10), (P11), (P12), (P13), (P14), (P15))

extern void
__coverity__builtin_sve_svprfb(
    __SVBool_t __a,
    const signed char *  __b,
    const int __c,
    int __d);
#define __builtin_sve_svprfb(P0, P1, P2, P3) \
    __coverity__builtin_sve_svprfb((P0), (P1), (P2), (P3))

extern void
__coverity__builtin_sve_svprfb_vnum(
    __SVBool_t __a,
    const signed char *  __b,
    int64_t __c,
    const int __d,
    int __e);
#define __builtin_sve_svprfb_vnum(P0, P1, P2, P3, P4) \
    __coverity__builtin_sve_svprfb_vnum((P0), (P1), (P2), (P3), (P4))

extern void
__coverity__builtin_sve_svprfd(
    __SVBool_t __a,
    const int64_t *  __b,
    const int __c,
    int __d);
#define __builtin_sve_svprfd(P0, P1, P2, P3) \
    __coverity__builtin_sve_svprfd((P0), (P1), (P2), (P3))

extern void
__coverity__builtin_sve_svprfd_vnum(
    __SVBool_t __a,
    const int64_t *  __b,
    int64_t __c,
    const int __d,
    int __e);
#define __builtin_sve_svprfd_vnum(P0, P1, P2, P3, P4) \
    __coverity__builtin_sve_svprfd_vnum((P0), (P1), (P2), (P3), (P4))

extern void
__coverity__builtin_sve_svprfh(
    __SVBool_t __a,
    const signed short *  __b,
    const int __c,
    int __d);
#define __builtin_sve_svprfh(P0, P1, P2, P3) \
    __coverity__builtin_sve_svprfh((P0), (P1), (P2), (P3))

extern void
__coverity__builtin_sve_svprfh_vnum(
    __SVBool_t __a,
    const signed short *  __b,
    int64_t __c,
    const int __d,
    int __e);
#define __builtin_sve_svprfh_vnum(P0, P1, P2, P3, P4) \
    __coverity__builtin_sve_svprfh_vnum((P0), (P1), (P2), (P3), (P4))

extern void
__coverity__builtin_sve_svprfw(
    __SVBool_t __a,
    const signed int *  __b,
    const int __c,
    int __d);
#define __builtin_sve_svprfw(P0, P1, P2, P3) \
    __coverity__builtin_sve_svprfw((P0), (P1), (P2), (P3))

extern void
__coverity__builtin_sve_svprfw_vnum(
    __SVBool_t __a,
    const signed int *  __b,
    int64_t __c,
    const int __d,
    int __e);
#define __builtin_sve_svprfw_vnum(P0, P1, P2, P3, P4) \
    __coverity__builtin_sve_svprfw_vnum((P0), (P1), (P2), (P3), (P4))

/* __builtin_sve_svptest_any("Scq16bq16b" vs. "bq16bq16b") differs only in return type: Not generated */
/* __builtin_sve_svptest_first("Scq16bq16b" vs. "bq16bq16b") differs only in return type: Not generated */
/* __builtin_sve_svptest_last("Scq16bq16b" vs. "bq16bq16b") differs only in return type: Not generated */
#endif /* } defined(__ARM_FEATURE_SVE) */

extern  double __attribute__((vector_size(16)))
__coverity__builtin_vsx_lxvd2x(
    int __a,
    const void *  __b);
#define __builtin_vsx_lxvd2x(P0, P1) \
    __coverity__builtin_vsx_lxvd2x((P0), (P1))

extern  int __attribute__((vector_size(16)))
__coverity__builtin_vsx_lxvw4x(
    int __a,
    const void *  __b);
#define __builtin_vsx_lxvw4x(P0, P1) \
    __coverity__builtin_vsx_lxvw4x((P0), (P1))

extern void
__coverity__builtin_vsx_stxvd2x(
     double __attribute__((vector_size(16))) __a,
    int __b,
    void *  __c);
#define __builtin_vsx_stxvd2x(P0, P1, P2) \
    __coverity__builtin_vsx_stxvd2x((P0), (P1), (P2))

extern void
__coverity__builtin_vsx_stxvw4x(
     int __attribute__((vector_size(16))) __a,
    int __b,
    void *  __c);
#define __builtin_vsx_stxvw4x(P0, P1, P2) \
    __coverity__builtin_vsx_stxvw4x((P0), (P1), (P2))

extern unsigned short __attribute__((vector_size(16)))
__coverity__builtin_wasm_narrow_u_i16x8_i32x4(
    unsigned int __attribute__((vector_size(16))) __a,
    unsigned int __attribute__((vector_size(16))) __b);
#define __builtin_wasm_narrow_u_i16x8_i32x4(P0, P1) \
    __coverity__builtin_wasm_narrow_u_i16x8_i32x4((P0), (P1))

extern unsigned char __attribute__((vector_size(16)))
__coverity__builtin_wasm_narrow_u_i8x16_i16x8(
    unsigned short __attribute__((vector_size(16))) __a,
    unsigned short __attribute__((vector_size(16))) __b);
#define __builtin_wasm_narrow_u_i8x16_i16x8(P0, P1) \
    __coverity__builtin_wasm_narrow_u_i8x16_i16x8((P0), (P1))

/* __mulh("LLiLLiLLi" vs. "SLLiSLLiSLLi") differs only in signed int vs int: Not generated */

/* } Changed in Clang 13.0 */

#endif /* }  Clang 13.0 */

/*************************************
 ************ Clang 14.0 *************
 *************************************/
#if (__cov_clang_version_lt(14, 0)) /* { */
/* Signatures changed in Clang 14.0 { */
/* _InterlockedAnd64("LLiLLiD*LLi" vs. "WiWiD*Wi") differs only in W(int64_t) vs LL(long long): Not generated */
/* _InterlockedAnd64("WiWiD*Wi" vs. "LLiLLiD*LLi") differs only in W(int64_t) vs LL(long long): Not generated */
/* _InterlockedDecrement64("LLiLLiD*" vs. "WiWiD*") differs only in W(int64_t) vs LL(long long): Not generated */
/* _InterlockedDecrement64("WiWiD*" vs. "LLiLLiD*") differs only in W(int64_t) vs LL(long long): Not generated */
/* _InterlockedExchange64("LLiLLiD*LLi" vs. "WiWiD*Wi") differs only in W(int64_t) vs LL(long long): Not generated */
/* _InterlockedExchange64("WiWiD*Wi" vs. "LLiLLiD*LLi") differs only in W(int64_t) vs LL(long long): Not generated */
/* _InterlockedExchangeAdd64("LLiLLiD*LLi" vs. "WiWiD*Wi") differs only in W(int64_t) vs LL(long long): Not generated */
/* _InterlockedExchangeAdd64("WiWiD*Wi" vs. "LLiLLiD*LLi") differs only in W(int64_t) vs LL(long long): Not generated */
/* _InterlockedExchangeSub64("LLiLLiD*LLi" vs. "WiWiD*Wi") differs only in W(int64_t) vs LL(long long): Not generated */
/* _InterlockedExchangeSub64("WiWiD*Wi" vs. "LLiLLiD*LLi") differs only in W(int64_t) vs LL(long long): Not generated */
/* _InterlockedIncrement64("LLiLLiD*" vs. "WiWiD*") differs only in W(int64_t) vs LL(long long): Not generated */
/* _InterlockedIncrement64("WiWiD*" vs. "LLiLLiD*") differs only in W(int64_t) vs LL(long long): Not generated */
/* _InterlockedOr64("LLiLLiD*LLi" vs. "WiWiD*Wi") differs only in W(int64_t) vs LL(long long): Not generated */
/* _InterlockedOr64("WiWiD*Wi" vs. "LLiLLiD*LLi") differs only in W(int64_t) vs LL(long long): Not generated */
/* _InterlockedXor64("LLiLLiD*LLi" vs. "WiWiD*Wi") differs only in W(int64_t) vs LL(long long): Not generated */
/* _InterlockedXor64("WiWiD*Wi" vs. "LLiLLiD*LLi") differs only in W(int64_t) vs LL(long long): Not generated */
/* __builtin_arm_crc32cd("UiUiLLUi" vs. "UiUiWUi") differs only in W(int64_t) vs LL(long long): Not generated */
/* __builtin_arm_crc32cd("UiUiWUi" vs. "UiUiLLUi") differs only in W(int64_t) vs LL(long long): Not generated */
/* __builtin_arm_crc32d("UiUiLLUi" vs. "UiUiWUi") differs only in W(int64_t) vs LL(long long): Not generated */
/* __builtin_arm_crc32d("UiUiWUi" vs. "UiUiLLUi") differs only in W(int64_t) vs LL(long long): Not generated */
/* __builtin_arm_rsr64("LLUicC*" vs. "WUicC*") differs only in W(int64_t) vs LL(long long): Not generated */
/* __builtin_arm_rsr64("WUicC*" vs. "LLUicC*") differs only in W(int64_t) vs LL(long long): Not generated */
/* __builtin_arm_wsr64("vcC*LLUi" vs. "vcC*WUi") differs only in W(int64_t) vs LL(long long): Not generated */
/* __builtin_arm_wsr64("vcC*WUi" vs. "vcC*LLUi") differs only in W(int64_t) vs LL(long long): Not generated */
extern unsigned int
__coverity__builtin_ppc_lbarx(
    volatile unsigned char *  __a);
#define __builtin_ppc_lbarx(P0) \
    __coverity__builtin_ppc_lbarx((P0))

/* __builtin_ppc_lharx("isD*" vs. "ssD*") differs only in return type: Not generated */
/* __builtin_ppc_load2r("UiUs*" vs. "UsUs*") differs only in return type: Not generated */
/* __builtin_ppc_rlwnm("UiUiIUiIUi" vs. "UiUiUiIUi") differs only in constexpr int vs int: Not generated */
/* __builtin_wasm_bitmask_i16x8("iV8s" vs. "UiV8s") differs only in return type: Not generated */
/* __builtin_wasm_bitmask_i32x4("iV4i" vs. "UiV4i") differs only in return type: Not generated */
/* __builtin_wasm_bitmask_i64x2("iV2LLi" vs. "UiV2LLi") differs only in return type: Not generated */
/* __builtin_wasm_bitmask_i8x16("iV16Sc" vs. "UiV16Sc") differs only in return type: Not generated */
/* __mulh("LLiLLiLLi" vs. "SLLiSLLiSLLi") differs only in signed int vs int: Not generated */
/* __mulh("SLLiSLLiSLLi" vs. "LLiLLiLLi") differs only in signed int vs int: Not generated */

/* } Changed in Clang 14.0 */
#endif /* }  Clang 14.0 */

#ifdef __arm__
/*
 * These builtins were introduced by Keil ARM compilers using the prefix
 * __builtin_mve_* but were renamed to __builtin_arm_mve_* in LLVM clang.
 */
#define __builtin_mve_asrl __builtin_arm_mve_asrl
#define __builtin_mve_lsll __builtin_arm_mve_lsll
#define __builtin_mve_sqrshr __builtin_arm_mve_sqrshr
#define __builtin_mve_sqrshrl __builtin_arm_mve_sqrshrl
#define __builtin_mve_sqrshrl_sat48 __builtin_arm_mve_sqrshrl_sat48
#define __builtin_mve_uqrshl __builtin_arm_mve_uqrshl
#define __builtin_mve_uqrshll __builtin_arm_mve_uqrshll
#define __builtin_mve_uqrshll_sat48 __builtin_arm_mve_uqrshll_sat48
#define __builtin_mve_vabavq_p_s16 __builtin_arm_mve_vabavq_p_s16
#define __builtin_mve_vabavq_p_s32 __builtin_arm_mve_vabavq_p_s32
#define __builtin_mve_vabavq_p_s8 __builtin_arm_mve_vabavq_p_s8
#define __builtin_mve_vabavq_p_u16 __builtin_arm_mve_vabavq_p_u16
#define __builtin_mve_vabavq_p_u32 __builtin_arm_mve_vabavq_p_u32
#define __builtin_mve_vabavq_p_u8 __builtin_arm_mve_vabavq_p_u8
#define __builtin_mve_vabavq_s16 __builtin_arm_mve_vabavq_s16
#define __builtin_mve_vabavq_s32 __builtin_arm_mve_vabavq_s32
#define __builtin_mve_vabavq_s8 __builtin_arm_mve_vabavq_s8
#define __builtin_mve_vabavq_u16 __builtin_arm_mve_vabavq_u16
#define __builtin_mve_vabavq_u32 __builtin_arm_mve_vabavq_u32
#define __builtin_mve_vabavq_u8 __builtin_arm_mve_vabavq_u8
#define __builtin_mve_vabdq_f16 __builtin_arm_mve_vabdq_f16
#define __builtin_mve_vabdq_f32 __builtin_arm_mve_vabdq_f32
#define __builtin_mve_vabdq_m_f16 __builtin_arm_mve_vabdq_m_f16
#define __builtin_mve_vabdq_m_f32 __builtin_arm_mve_vabdq_m_f32
#define __builtin_mve_vabdq_m_s16 __builtin_arm_mve_vabdq_m_s16
#define __builtin_mve_vabdq_m_s32 __builtin_arm_mve_vabdq_m_s32
#define __builtin_mve_vabdq_m_s8 __builtin_arm_mve_vabdq_m_s8
#define __builtin_mve_vabdq_m_u16 __builtin_arm_mve_vabdq_m_u16
#define __builtin_mve_vabdq_m_u32 __builtin_arm_mve_vabdq_m_u32
#define __builtin_mve_vabdq_m_u8 __builtin_arm_mve_vabdq_m_u8
#define __builtin_mve_vabdq_s16 __builtin_arm_mve_vabdq_s16
#define __builtin_mve_vabdq_s32 __builtin_arm_mve_vabdq_s32
#define __builtin_mve_vabdq_s8 __builtin_arm_mve_vabdq_s8
#define __builtin_mve_vabdq_u16 __builtin_arm_mve_vabdq_u16
#define __builtin_mve_vabdq_u32 __builtin_arm_mve_vabdq_u32
#define __builtin_mve_vabdq_u8 __builtin_arm_mve_vabdq_u8
#define __builtin_mve_vabsq_f16 __builtin_arm_mve_vabsq_f16
#define __builtin_mve_vabsq_f32 __builtin_arm_mve_vabsq_f32
#define __builtin_mve_vabsq_m_f16 __builtin_arm_mve_vabsq_m_f16
#define __builtin_mve_vabsq_m_f32 __builtin_arm_mve_vabsq_m_f32
#define __builtin_mve_vabsq_m_s16 __builtin_arm_mve_vabsq_m_s16
#define __builtin_mve_vabsq_m_s32 __builtin_arm_mve_vabsq_m_s32
#define __builtin_mve_vabsq_m_s8 __builtin_arm_mve_vabsq_m_s8
#define __builtin_mve_vabsq_s16 __builtin_arm_mve_vabsq_s16
#define __builtin_mve_vabsq_s32 __builtin_arm_mve_vabsq_s32
#define __builtin_mve_vabsq_s8 __builtin_arm_mve_vabsq_s8
#define __builtin_mve_vadciq_m_s32 __builtin_arm_mve_vadciq_m_s32
#define __builtin_mve_vadciq_m_u32 __builtin_arm_mve_vadciq_m_u32
#define __builtin_mve_vadciq_s32 __builtin_arm_mve_vadciq_s32
#define __builtin_mve_vadciq_u32 __builtin_arm_mve_vadciq_u32
#define __builtin_mve_vadcq_m_s32 __builtin_arm_mve_vadcq_m_s32
#define __builtin_mve_vadcq_m_u32 __builtin_arm_mve_vadcq_m_u32
#define __builtin_mve_vadcq_s32 __builtin_arm_mve_vadcq_s32
#define __builtin_mve_vadcq_u32 __builtin_arm_mve_vadcq_u32
#define __builtin_mve_vaddlvaq_p_s32 __builtin_arm_mve_vaddlvaq_p_s32
#define __builtin_mve_vaddlvaq_p_u32 __builtin_arm_mve_vaddlvaq_p_u32
#define __builtin_mve_vaddlvaq_s32 __builtin_arm_mve_vaddlvaq_s32
#define __builtin_mve_vaddlvaq_u32 __builtin_arm_mve_vaddlvaq_u32
#define __builtin_mve_vaddlvq_p_s32 __builtin_arm_mve_vaddlvq_p_s32
#define __builtin_mve_vaddlvq_p_u32 __builtin_arm_mve_vaddlvq_p_u32
#define __builtin_mve_vaddlvq_s32 __builtin_arm_mve_vaddlvq_s32
#define __builtin_mve_vaddlvq_u32 __builtin_arm_mve_vaddlvq_u32
#define __builtin_mve_vaddq_f16 __builtin_arm_mve_vaddq_f16
#define __builtin_mve_vaddq_f32 __builtin_arm_mve_vaddq_f32
#define __builtin_mve_vaddq_m_f16 __builtin_arm_mve_vaddq_m_f16
#define __builtin_mve_vaddq_m_f32 __builtin_arm_mve_vaddq_m_f32
#define __builtin_mve_vaddq_m_n_f16 __builtin_arm_mve_vaddq_m_n_f16
#define __builtin_mve_vaddq_m_n_f32 __builtin_arm_mve_vaddq_m_n_f32
#define __builtin_mve_vaddq_m_n_s16 __builtin_arm_mve_vaddq_m_n_s16
#define __builtin_mve_vaddq_m_n_s32 __builtin_arm_mve_vaddq_m_n_s32
#define __builtin_mve_vaddq_m_n_s8 __builtin_arm_mve_vaddq_m_n_s8
#define __builtin_mve_vaddq_m_n_u16 __builtin_arm_mve_vaddq_m_n_u16
#define __builtin_mve_vaddq_m_n_u32 __builtin_arm_mve_vaddq_m_n_u32
#define __builtin_mve_vaddq_m_n_u8 __builtin_arm_mve_vaddq_m_n_u8
#define __builtin_mve_vaddq_m_s16 __builtin_arm_mve_vaddq_m_s16
#define __builtin_mve_vaddq_m_s32 __builtin_arm_mve_vaddq_m_s32
#define __builtin_mve_vaddq_m_s8 __builtin_arm_mve_vaddq_m_s8
#define __builtin_mve_vaddq_m_u16 __builtin_arm_mve_vaddq_m_u16
#define __builtin_mve_vaddq_m_u32 __builtin_arm_mve_vaddq_m_u32
#define __builtin_mve_vaddq_m_u8 __builtin_arm_mve_vaddq_m_u8
#define __builtin_mve_vaddq_n_f16 __builtin_arm_mve_vaddq_n_f16
#define __builtin_mve_vaddq_n_f32 __builtin_arm_mve_vaddq_n_f32
#define __builtin_mve_vaddq_n_s16 __builtin_arm_mve_vaddq_n_s16
#define __builtin_mve_vaddq_n_s32 __builtin_arm_mve_vaddq_n_s32
#define __builtin_mve_vaddq_n_s8 __builtin_arm_mve_vaddq_n_s8
#define __builtin_mve_vaddq_n_u16 __builtin_arm_mve_vaddq_n_u16
#define __builtin_mve_vaddq_n_u32 __builtin_arm_mve_vaddq_n_u32
#define __builtin_mve_vaddq_n_u8 __builtin_arm_mve_vaddq_n_u8
#define __builtin_mve_vaddq_s16 __builtin_arm_mve_vaddq_s16
#define __builtin_mve_vaddq_s32 __builtin_arm_mve_vaddq_s32
#define __builtin_mve_vaddq_s8 __builtin_arm_mve_vaddq_s8
#define __builtin_mve_vaddq_u16 __builtin_arm_mve_vaddq_u16
#define __builtin_mve_vaddq_u32 __builtin_arm_mve_vaddq_u32
#define __builtin_mve_vaddq_u8 __builtin_arm_mve_vaddq_u8
#define __builtin_mve_vaddvaq_p_s16 __builtin_arm_mve_vaddvaq_p_s16
#define __builtin_mve_vaddvaq_p_s32 __builtin_arm_mve_vaddvaq_p_s32
#define __builtin_mve_vaddvaq_p_s8 __builtin_arm_mve_vaddvaq_p_s8
#define __builtin_mve_vaddvaq_p_u16 __builtin_arm_mve_vaddvaq_p_u16
#define __builtin_mve_vaddvaq_p_u32 __builtin_arm_mve_vaddvaq_p_u32
#define __builtin_mve_vaddvaq_p_u8 __builtin_arm_mve_vaddvaq_p_u8
#define __builtin_mve_vaddvaq_s16 __builtin_arm_mve_vaddvaq_s16
#define __builtin_mve_vaddvaq_s32 __builtin_arm_mve_vaddvaq_s32
#define __builtin_mve_vaddvaq_s8 __builtin_arm_mve_vaddvaq_s8
#define __builtin_mve_vaddvaq_u16 __builtin_arm_mve_vaddvaq_u16
#define __builtin_mve_vaddvaq_u32 __builtin_arm_mve_vaddvaq_u32
#define __builtin_mve_vaddvaq_u8 __builtin_arm_mve_vaddvaq_u8
#define __builtin_mve_vaddvq_p_s16 __builtin_arm_mve_vaddvq_p_s16
#define __builtin_mve_vaddvq_p_s32 __builtin_arm_mve_vaddvq_p_s32
#define __builtin_mve_vaddvq_p_s8 __builtin_arm_mve_vaddvq_p_s8
#define __builtin_mve_vaddvq_p_u16 __builtin_arm_mve_vaddvq_p_u16
#define __builtin_mve_vaddvq_p_u32 __builtin_arm_mve_vaddvq_p_u32
#define __builtin_mve_vaddvq_p_u8 __builtin_arm_mve_vaddvq_p_u8
#define __builtin_mve_vaddvq_s16 __builtin_arm_mve_vaddvq_s16
#define __builtin_mve_vaddvq_s32 __builtin_arm_mve_vaddvq_s32
#define __builtin_mve_vaddvq_s8 __builtin_arm_mve_vaddvq_s8
#define __builtin_mve_vaddvq_u16 __builtin_arm_mve_vaddvq_u16
#define __builtin_mve_vaddvq_u32 __builtin_arm_mve_vaddvq_u32
#define __builtin_mve_vaddvq_u8 __builtin_arm_mve_vaddvq_u8
#define __builtin_mve_vandq_f16 __builtin_arm_mve_vandq_f16
#define __builtin_mve_vandq_f32 __builtin_arm_mve_vandq_f32
#define __builtin_mve_vandq_m_f16 __builtin_arm_mve_vandq_m_f16
#define __builtin_mve_vandq_m_f32 __builtin_arm_mve_vandq_m_f32
#define __builtin_mve_vandq_m_s16 __builtin_arm_mve_vandq_m_s16
#define __builtin_mve_vandq_m_s32 __builtin_arm_mve_vandq_m_s32
#define __builtin_mve_vandq_m_s8 __builtin_arm_mve_vandq_m_s8
#define __builtin_mve_vandq_m_u16 __builtin_arm_mve_vandq_m_u16
#define __builtin_mve_vandq_m_u32 __builtin_arm_mve_vandq_m_u32
#define __builtin_mve_vandq_m_u8 __builtin_arm_mve_vandq_m_u8
#define __builtin_mve_vandq_s16 __builtin_arm_mve_vandq_s16
#define __builtin_mve_vandq_s32 __builtin_arm_mve_vandq_s32
#define __builtin_mve_vandq_s8 __builtin_arm_mve_vandq_s8
#define __builtin_mve_vandq_u16 __builtin_arm_mve_vandq_u16
#define __builtin_mve_vandq_u32 __builtin_arm_mve_vandq_u32
#define __builtin_mve_vandq_u8 __builtin_arm_mve_vandq_u8
#define __builtin_mve_vbicq_f16 __builtin_arm_mve_vbicq_f16
#define __builtin_mve_vbicq_f32 __builtin_arm_mve_vbicq_f32
#define __builtin_mve_vbicq_m_f16 __builtin_arm_mve_vbicq_m_f16
#define __builtin_mve_vbicq_m_f32 __builtin_arm_mve_vbicq_m_f32
#define __builtin_mve_vbicq_m_s16 __builtin_arm_mve_vbicq_m_s16
#define __builtin_mve_vbicq_m_s32 __builtin_arm_mve_vbicq_m_s32
#define __builtin_mve_vbicq_m_s8 __builtin_arm_mve_vbicq_m_s8
#define __builtin_mve_vbicq_m_u16 __builtin_arm_mve_vbicq_m_u16
#define __builtin_mve_vbicq_m_u32 __builtin_arm_mve_vbicq_m_u32
#define __builtin_mve_vbicq_m_u8 __builtin_arm_mve_vbicq_m_u8
#define __builtin_mve_vbicq_s16 __builtin_arm_mve_vbicq_s16
#define __builtin_mve_vbicq_s32 __builtin_arm_mve_vbicq_s32
#define __builtin_mve_vbicq_s8 __builtin_arm_mve_vbicq_s8
#define __builtin_mve_vbicq_u16 __builtin_arm_mve_vbicq_u16
#define __builtin_mve_vbicq_u32 __builtin_arm_mve_vbicq_u32
#define __builtin_mve_vbicq_u8 __builtin_arm_mve_vbicq_u8
#define __builtin_mve_vbrsrq_m_n_f16 __builtin_arm_mve_vbrsrq_m_n_f16
#define __builtin_mve_vbrsrq_m_n_f32 __builtin_arm_mve_vbrsrq_m_n_f32
#define __builtin_mve_vbrsrq_m_n_s16 __builtin_arm_mve_vbrsrq_m_n_s16
#define __builtin_mve_vbrsrq_m_n_s32 __builtin_arm_mve_vbrsrq_m_n_s32
#define __builtin_mve_vbrsrq_m_n_s8 __builtin_arm_mve_vbrsrq_m_n_s8
#define __builtin_mve_vbrsrq_m_n_u16 __builtin_arm_mve_vbrsrq_m_n_u16
#define __builtin_mve_vbrsrq_m_n_u32 __builtin_arm_mve_vbrsrq_m_n_u32
#define __builtin_mve_vbrsrq_m_n_u8 __builtin_arm_mve_vbrsrq_m_n_u8
#define __builtin_mve_vbrsrq_n_f16 __builtin_arm_mve_vbrsrq_n_f16
#define __builtin_mve_vbrsrq_n_f32 __builtin_arm_mve_vbrsrq_n_f32
#define __builtin_mve_vbrsrq_n_s16 __builtin_arm_mve_vbrsrq_n_s16
#define __builtin_mve_vbrsrq_n_s32 __builtin_arm_mve_vbrsrq_n_s32
#define __builtin_mve_vbrsrq_n_s8 __builtin_arm_mve_vbrsrq_n_s8
#define __builtin_mve_vbrsrq_n_u16 __builtin_arm_mve_vbrsrq_n_u16
#define __builtin_mve_vbrsrq_n_u32 __builtin_arm_mve_vbrsrq_n_u32
#define __builtin_mve_vbrsrq_n_u8 __builtin_arm_mve_vbrsrq_n_u8
#define __builtin_mve_vcaddq_rot270_f16 __builtin_arm_mve_vcaddq_rot270_f16
#define __builtin_mve_vcaddq_rot270_f32 __builtin_arm_mve_vcaddq_rot270_f32
#define __builtin_mve_vcaddq_rot270_m_f16 __builtin_arm_mve_vcaddq_rot270_m_f16
#define __builtin_mve_vcaddq_rot270_m_f32 __builtin_arm_mve_vcaddq_rot270_m_f32
#define __builtin_mve_vcaddq_rot270_m_s16 __builtin_arm_mve_vcaddq_rot270_m_s16
#define __builtin_mve_vcaddq_rot270_m_s32 __builtin_arm_mve_vcaddq_rot270_m_s32
#define __builtin_mve_vcaddq_rot270_m_s8 __builtin_arm_mve_vcaddq_rot270_m_s8
#define __builtin_mve_vcaddq_rot270_m_u16 __builtin_arm_mve_vcaddq_rot270_m_u16
#define __builtin_mve_vcaddq_rot270_m_u32 __builtin_arm_mve_vcaddq_rot270_m_u32
#define __builtin_mve_vcaddq_rot270_m_u8 __builtin_arm_mve_vcaddq_rot270_m_u8
#define __builtin_mve_vcaddq_rot270_s16 __builtin_arm_mve_vcaddq_rot270_s16
#define __builtin_mve_vcaddq_rot270_s32 __builtin_arm_mve_vcaddq_rot270_s32
#define __builtin_mve_vcaddq_rot270_s8 __builtin_arm_mve_vcaddq_rot270_s8
#define __builtin_mve_vcaddq_rot270_u16 __builtin_arm_mve_vcaddq_rot270_u16
#define __builtin_mve_vcaddq_rot270_u32 __builtin_arm_mve_vcaddq_rot270_u32
#define __builtin_mve_vcaddq_rot270_u8 __builtin_arm_mve_vcaddq_rot270_u8
#define __builtin_mve_vcaddq_rot90_f16 __builtin_arm_mve_vcaddq_rot90_f16
#define __builtin_mve_vcaddq_rot90_f32 __builtin_arm_mve_vcaddq_rot90_f32
#define __builtin_mve_vcaddq_rot90_m_f16 __builtin_arm_mve_vcaddq_rot90_m_f16
#define __builtin_mve_vcaddq_rot90_m_f32 __builtin_arm_mve_vcaddq_rot90_m_f32
#define __builtin_mve_vcaddq_rot90_m_s16 __builtin_arm_mve_vcaddq_rot90_m_s16
#define __builtin_mve_vcaddq_rot90_m_s32 __builtin_arm_mve_vcaddq_rot90_m_s32
#define __builtin_mve_vcaddq_rot90_m_s8 __builtin_arm_mve_vcaddq_rot90_m_s8
#define __builtin_mve_vcaddq_rot90_m_u16 __builtin_arm_mve_vcaddq_rot90_m_u16
#define __builtin_mve_vcaddq_rot90_m_u32 __builtin_arm_mve_vcaddq_rot90_m_u32
#define __builtin_mve_vcaddq_rot90_m_u8 __builtin_arm_mve_vcaddq_rot90_m_u8
#define __builtin_mve_vcaddq_rot90_s16 __builtin_arm_mve_vcaddq_rot90_s16
#define __builtin_mve_vcaddq_rot90_s32 __builtin_arm_mve_vcaddq_rot90_s32
#define __builtin_mve_vcaddq_rot90_s8 __builtin_arm_mve_vcaddq_rot90_s8
#define __builtin_mve_vcaddq_rot90_u16 __builtin_arm_mve_vcaddq_rot90_u16
#define __builtin_mve_vcaddq_rot90_u32 __builtin_arm_mve_vcaddq_rot90_u32
#define __builtin_mve_vcaddq_rot90_u8 __builtin_arm_mve_vcaddq_rot90_u8
#define __builtin_mve_vclsq_m_s16 __builtin_arm_mve_vclsq_m_s16
#define __builtin_mve_vclsq_m_s32 __builtin_arm_mve_vclsq_m_s32
#define __builtin_mve_vclsq_m_s8 __builtin_arm_mve_vclsq_m_s8
#define __builtin_mve_vclsq_s16 __builtin_arm_mve_vclsq_s16
#define __builtin_mve_vclsq_s32 __builtin_arm_mve_vclsq_s32
#define __builtin_mve_vclsq_s8 __builtin_arm_mve_vclsq_s8
#define __builtin_mve_vclzq_m_s16 __builtin_arm_mve_vclzq_m_s16
#define __builtin_mve_vclzq_m_s32 __builtin_arm_mve_vclzq_m_s32
#define __builtin_mve_vclzq_m_s8 __builtin_arm_mve_vclzq_m_s8
#define __builtin_mve_vclzq_m_u16 __builtin_arm_mve_vclzq_m_u16
#define __builtin_mve_vclzq_m_u32 __builtin_arm_mve_vclzq_m_u32
#define __builtin_mve_vclzq_m_u8 __builtin_arm_mve_vclzq_m_u8
#define __builtin_mve_vclzq_s16 __builtin_arm_mve_vclzq_s16
#define __builtin_mve_vclzq_s32 __builtin_arm_mve_vclzq_s32
#define __builtin_mve_vclzq_s8 __builtin_arm_mve_vclzq_s8
#define __builtin_mve_vclzq_u16 __builtin_arm_mve_vclzq_u16
#define __builtin_mve_vclzq_u32 __builtin_arm_mve_vclzq_u32
#define __builtin_mve_vclzq_u8 __builtin_arm_mve_vclzq_u8
#define __builtin_mve_vcmlaq_f16 __builtin_arm_mve_vcmlaq_f16
#define __builtin_mve_vcmlaq_f32 __builtin_arm_mve_vcmlaq_f32
#define __builtin_mve_vcmlaq_m_f16 __builtin_arm_mve_vcmlaq_m_f16
#define __builtin_mve_vcmlaq_m_f32 __builtin_arm_mve_vcmlaq_m_f32
#define __builtin_mve_vcmlaq_rot180_f16 __builtin_arm_mve_vcmlaq_rot180_f16
#define __builtin_mve_vcmlaq_rot180_f32 __builtin_arm_mve_vcmlaq_rot180_f32
#define __builtin_mve_vcmlaq_rot180_m_f16 __builtin_arm_mve_vcmlaq_rot180_m_f16
#define __builtin_mve_vcmlaq_rot180_m_f32 __builtin_arm_mve_vcmlaq_rot180_m_f32
#define __builtin_mve_vcmlaq_rot270_f16 __builtin_arm_mve_vcmlaq_rot270_f16
#define __builtin_mve_vcmlaq_rot270_f32 __builtin_arm_mve_vcmlaq_rot270_f32
#define __builtin_mve_vcmlaq_rot270_m_f16 __builtin_arm_mve_vcmlaq_rot270_m_f16
#define __builtin_mve_vcmlaq_rot270_m_f32 __builtin_arm_mve_vcmlaq_rot270_m_f32
#define __builtin_mve_vcmlaq_rot90_f16 __builtin_arm_mve_vcmlaq_rot90_f16
#define __builtin_mve_vcmlaq_rot90_f32 __builtin_arm_mve_vcmlaq_rot90_f32
#define __builtin_mve_vcmlaq_rot90_m_f16 __builtin_arm_mve_vcmlaq_rot90_m_f16
#define __builtin_mve_vcmlaq_rot90_m_f32 __builtin_arm_mve_vcmlaq_rot90_m_f32
#define __builtin_mve_vcmpcsq_m_n_u16 __builtin_arm_mve_vcmpcsq_m_n_u16
#define __builtin_mve_vcmpcsq_m_n_u32 __builtin_arm_mve_vcmpcsq_m_n_u32
#define __builtin_mve_vcmpcsq_m_n_u8 __builtin_arm_mve_vcmpcsq_m_n_u8
#define __builtin_mve_vcmpcsq_m_u16 __builtin_arm_mve_vcmpcsq_m_u16
#define __builtin_mve_vcmpcsq_m_u32 __builtin_arm_mve_vcmpcsq_m_u32
#define __builtin_mve_vcmpcsq_m_u8 __builtin_arm_mve_vcmpcsq_m_u8
#define __builtin_mve_vcmpcsq_n_u16 __builtin_arm_mve_vcmpcsq_n_u16
#define __builtin_mve_vcmpcsq_n_u32 __builtin_arm_mve_vcmpcsq_n_u32
#define __builtin_mve_vcmpcsq_n_u8 __builtin_arm_mve_vcmpcsq_n_u8
#define __builtin_mve_vcmpcsq_u16 __builtin_arm_mve_vcmpcsq_u16
#define __builtin_mve_vcmpcsq_u32 __builtin_arm_mve_vcmpcsq_u32
#define __builtin_mve_vcmpcsq_u8 __builtin_arm_mve_vcmpcsq_u8
#define __builtin_mve_vcmpeqq_f16 __builtin_arm_mve_vcmpeqq_f16
#define __builtin_mve_vcmpeqq_f32 __builtin_arm_mve_vcmpeqq_f32
#define __builtin_mve_vcmpeqq_m_f16 __builtin_arm_mve_vcmpeqq_m_f16
#define __builtin_mve_vcmpeqq_m_f32 __builtin_arm_mve_vcmpeqq_m_f32
#define __builtin_mve_vcmpeqq_m_n_f16 __builtin_arm_mve_vcmpeqq_m_n_f16
#define __builtin_mve_vcmpeqq_m_n_f32 __builtin_arm_mve_vcmpeqq_m_n_f32
#define __builtin_mve_vcmpeqq_m_n_s16 __builtin_arm_mve_vcmpeqq_m_n_s16
#define __builtin_mve_vcmpeqq_m_n_s32 __builtin_arm_mve_vcmpeqq_m_n_s32
#define __builtin_mve_vcmpeqq_m_n_s8 __builtin_arm_mve_vcmpeqq_m_n_s8
#define __builtin_mve_vcmpeqq_m_n_u16 __builtin_arm_mve_vcmpeqq_m_n_u16
#define __builtin_mve_vcmpeqq_m_n_u32 __builtin_arm_mve_vcmpeqq_m_n_u32
#define __builtin_mve_vcmpeqq_m_n_u8 __builtin_arm_mve_vcmpeqq_m_n_u8
#define __builtin_mve_vcmpeqq_m_s16 __builtin_arm_mve_vcmpeqq_m_s16
#define __builtin_mve_vcmpeqq_m_s32 __builtin_arm_mve_vcmpeqq_m_s32
#define __builtin_mve_vcmpeqq_m_s8 __builtin_arm_mve_vcmpeqq_m_s8
#define __builtin_mve_vcmpeqq_m_u16 __builtin_arm_mve_vcmpeqq_m_u16
#define __builtin_mve_vcmpeqq_m_u32 __builtin_arm_mve_vcmpeqq_m_u32
#define __builtin_mve_vcmpeqq_m_u8 __builtin_arm_mve_vcmpeqq_m_u8
#define __builtin_mve_vcmpeqq_n_f16 __builtin_arm_mve_vcmpeqq_n_f16
#define __builtin_mve_vcmpeqq_n_f32 __builtin_arm_mve_vcmpeqq_n_f32
#define __builtin_mve_vcmpeqq_n_s16 __builtin_arm_mve_vcmpeqq_n_s16
#define __builtin_mve_vcmpeqq_n_s32 __builtin_arm_mve_vcmpeqq_n_s32
#define __builtin_mve_vcmpeqq_n_s8 __builtin_arm_mve_vcmpeqq_n_s8
#define __builtin_mve_vcmpeqq_n_u16 __builtin_arm_mve_vcmpeqq_n_u16
#define __builtin_mve_vcmpeqq_n_u32 __builtin_arm_mve_vcmpeqq_n_u32
#define __builtin_mve_vcmpeqq_n_u8 __builtin_arm_mve_vcmpeqq_n_u8
#define __builtin_mve_vcmpeqq_s16 __builtin_arm_mve_vcmpeqq_s16
#define __builtin_mve_vcmpeqq_s32 __builtin_arm_mve_vcmpeqq_s32
#define __builtin_mve_vcmpeqq_s8 __builtin_arm_mve_vcmpeqq_s8
#define __builtin_mve_vcmpeqq_u16 __builtin_arm_mve_vcmpeqq_u16
#define __builtin_mve_vcmpeqq_u32 __builtin_arm_mve_vcmpeqq_u32
#define __builtin_mve_vcmpeqq_u8 __builtin_arm_mve_vcmpeqq_u8
#define __builtin_mve_vcmpgeq_f16 __builtin_arm_mve_vcmpgeq_f16
#define __builtin_mve_vcmpgeq_f32 __builtin_arm_mve_vcmpgeq_f32
#define __builtin_mve_vcmpgeq_m_f16 __builtin_arm_mve_vcmpgeq_m_f16
#define __builtin_mve_vcmpgeq_m_f32 __builtin_arm_mve_vcmpgeq_m_f32
#define __builtin_mve_vcmpgeq_m_n_f16 __builtin_arm_mve_vcmpgeq_m_n_f16
#define __builtin_mve_vcmpgeq_m_n_f32 __builtin_arm_mve_vcmpgeq_m_n_f32
#define __builtin_mve_vcmpgeq_m_n_s16 __builtin_arm_mve_vcmpgeq_m_n_s16
#define __builtin_mve_vcmpgeq_m_n_s32 __builtin_arm_mve_vcmpgeq_m_n_s32
#define __builtin_mve_vcmpgeq_m_n_s8 __builtin_arm_mve_vcmpgeq_m_n_s8
#define __builtin_mve_vcmpgeq_m_s16 __builtin_arm_mve_vcmpgeq_m_s16
#define __builtin_mve_vcmpgeq_m_s32 __builtin_arm_mve_vcmpgeq_m_s32
#define __builtin_mve_vcmpgeq_m_s8 __builtin_arm_mve_vcmpgeq_m_s8
#define __builtin_mve_vcmpgeq_n_f16 __builtin_arm_mve_vcmpgeq_n_f16
#define __builtin_mve_vcmpgeq_n_f32 __builtin_arm_mve_vcmpgeq_n_f32
#define __builtin_mve_vcmpgeq_n_s16 __builtin_arm_mve_vcmpgeq_n_s16
#define __builtin_mve_vcmpgeq_n_s32 __builtin_arm_mve_vcmpgeq_n_s32
#define __builtin_mve_vcmpgeq_n_s8 __builtin_arm_mve_vcmpgeq_n_s8
#define __builtin_mve_vcmpgeq_s16 __builtin_arm_mve_vcmpgeq_s16
#define __builtin_mve_vcmpgeq_s32 __builtin_arm_mve_vcmpgeq_s32
#define __builtin_mve_vcmpgeq_s8 __builtin_arm_mve_vcmpgeq_s8
#define __builtin_mve_vcmpgtq_f16 __builtin_arm_mve_vcmpgtq_f16
#define __builtin_mve_vcmpgtq_f32 __builtin_arm_mve_vcmpgtq_f32
#define __builtin_mve_vcmpgtq_m_f16 __builtin_arm_mve_vcmpgtq_m_f16
#define __builtin_mve_vcmpgtq_m_f32 __builtin_arm_mve_vcmpgtq_m_f32
#define __builtin_mve_vcmpgtq_m_n_f16 __builtin_arm_mve_vcmpgtq_m_n_f16
#define __builtin_mve_vcmpgtq_m_n_f32 __builtin_arm_mve_vcmpgtq_m_n_f32
#define __builtin_mve_vcmpgtq_m_n_s16 __builtin_arm_mve_vcmpgtq_m_n_s16
#define __builtin_mve_vcmpgtq_m_n_s32 __builtin_arm_mve_vcmpgtq_m_n_s32
#define __builtin_mve_vcmpgtq_m_n_s8 __builtin_arm_mve_vcmpgtq_m_n_s8
#define __builtin_mve_vcmpgtq_m_s16 __builtin_arm_mve_vcmpgtq_m_s16
#define __builtin_mve_vcmpgtq_m_s32 __builtin_arm_mve_vcmpgtq_m_s32
#define __builtin_mve_vcmpgtq_m_s8 __builtin_arm_mve_vcmpgtq_m_s8
#define __builtin_mve_vcmpgtq_n_f16 __builtin_arm_mve_vcmpgtq_n_f16
#define __builtin_mve_vcmpgtq_n_f32 __builtin_arm_mve_vcmpgtq_n_f32
#define __builtin_mve_vcmpgtq_n_s16 __builtin_arm_mve_vcmpgtq_n_s16
#define __builtin_mve_vcmpgtq_n_s32 __builtin_arm_mve_vcmpgtq_n_s32
#define __builtin_mve_vcmpgtq_n_s8 __builtin_arm_mve_vcmpgtq_n_s8
#define __builtin_mve_vcmpgtq_s16 __builtin_arm_mve_vcmpgtq_s16
#define __builtin_mve_vcmpgtq_s32 __builtin_arm_mve_vcmpgtq_s32
#define __builtin_mve_vcmpgtq_s8 __builtin_arm_mve_vcmpgtq_s8
#define __builtin_mve_vcmphiq_m_n_u16 __builtin_arm_mve_vcmphiq_m_n_u16
#define __builtin_mve_vcmphiq_m_n_u32 __builtin_arm_mve_vcmphiq_m_n_u32
#define __builtin_mve_vcmphiq_m_n_u8 __builtin_arm_mve_vcmphiq_m_n_u8
#define __builtin_mve_vcmphiq_m_u16 __builtin_arm_mve_vcmphiq_m_u16
#define __builtin_mve_vcmphiq_m_u32 __builtin_arm_mve_vcmphiq_m_u32
#define __builtin_mve_vcmphiq_m_u8 __builtin_arm_mve_vcmphiq_m_u8
#define __builtin_mve_vcmphiq_n_u16 __builtin_arm_mve_vcmphiq_n_u16
#define __builtin_mve_vcmphiq_n_u32 __builtin_arm_mve_vcmphiq_n_u32
#define __builtin_mve_vcmphiq_n_u8 __builtin_arm_mve_vcmphiq_n_u8
#define __builtin_mve_vcmphiq_u16 __builtin_arm_mve_vcmphiq_u16
#define __builtin_mve_vcmphiq_u32 __builtin_arm_mve_vcmphiq_u32
#define __builtin_mve_vcmphiq_u8 __builtin_arm_mve_vcmphiq_u8
#define __builtin_mve_vcmpleq_f16 __builtin_arm_mve_vcmpleq_f16
#define __builtin_mve_vcmpleq_f32 __builtin_arm_mve_vcmpleq_f32
#define __builtin_mve_vcmpleq_m_f16 __builtin_arm_mve_vcmpleq_m_f16
#define __builtin_mve_vcmpleq_m_f32 __builtin_arm_mve_vcmpleq_m_f32
#define __builtin_mve_vcmpleq_m_n_f16 __builtin_arm_mve_vcmpleq_m_n_f16
#define __builtin_mve_vcmpleq_m_n_f32 __builtin_arm_mve_vcmpleq_m_n_f32
#define __builtin_mve_vcmpleq_m_n_s16 __builtin_arm_mve_vcmpleq_m_n_s16
#define __builtin_mve_vcmpleq_m_n_s32 __builtin_arm_mve_vcmpleq_m_n_s32
#define __builtin_mve_vcmpleq_m_n_s8 __builtin_arm_mve_vcmpleq_m_n_s8
#define __builtin_mve_vcmpleq_m_s16 __builtin_arm_mve_vcmpleq_m_s16
#define __builtin_mve_vcmpleq_m_s32 __builtin_arm_mve_vcmpleq_m_s32
#define __builtin_mve_vcmpleq_m_s8 __builtin_arm_mve_vcmpleq_m_s8
#define __builtin_mve_vcmpleq_n_f16 __builtin_arm_mve_vcmpleq_n_f16
#define __builtin_mve_vcmpleq_n_f32 __builtin_arm_mve_vcmpleq_n_f32
#define __builtin_mve_vcmpleq_n_s16 __builtin_arm_mve_vcmpleq_n_s16
#define __builtin_mve_vcmpleq_n_s32 __builtin_arm_mve_vcmpleq_n_s32
#define __builtin_mve_vcmpleq_n_s8 __builtin_arm_mve_vcmpleq_n_s8
#define __builtin_mve_vcmpleq_s16 __builtin_arm_mve_vcmpleq_s16
#define __builtin_mve_vcmpleq_s32 __builtin_arm_mve_vcmpleq_s32
#define __builtin_mve_vcmpleq_s8 __builtin_arm_mve_vcmpleq_s8
#define __builtin_mve_vcmpltq_f16 __builtin_arm_mve_vcmpltq_f16
#define __builtin_mve_vcmpltq_f32 __builtin_arm_mve_vcmpltq_f32
#define __builtin_mve_vcmpltq_m_f16 __builtin_arm_mve_vcmpltq_m_f16
#define __builtin_mve_vcmpltq_m_f32 __builtin_arm_mve_vcmpltq_m_f32
#define __builtin_mve_vcmpltq_m_n_f16 __builtin_arm_mve_vcmpltq_m_n_f16
#define __builtin_mve_vcmpltq_m_n_f32 __builtin_arm_mve_vcmpltq_m_n_f32
#define __builtin_mve_vcmpltq_m_n_s16 __builtin_arm_mve_vcmpltq_m_n_s16
#define __builtin_mve_vcmpltq_m_n_s32 __builtin_arm_mve_vcmpltq_m_n_s32
#define __builtin_mve_vcmpltq_m_n_s8 __builtin_arm_mve_vcmpltq_m_n_s8
#define __builtin_mve_vcmpltq_m_s16 __builtin_arm_mve_vcmpltq_m_s16
#define __builtin_mve_vcmpltq_m_s32 __builtin_arm_mve_vcmpltq_m_s32
#define __builtin_mve_vcmpltq_m_s8 __builtin_arm_mve_vcmpltq_m_s8
#define __builtin_mve_vcmpltq_n_f16 __builtin_arm_mve_vcmpltq_n_f16
#define __builtin_mve_vcmpltq_n_f32 __builtin_arm_mve_vcmpltq_n_f32
#define __builtin_mve_vcmpltq_n_s16 __builtin_arm_mve_vcmpltq_n_s16
#define __builtin_mve_vcmpltq_n_s32 __builtin_arm_mve_vcmpltq_n_s32
#define __builtin_mve_vcmpltq_n_s8 __builtin_arm_mve_vcmpltq_n_s8
#define __builtin_mve_vcmpltq_s16 __builtin_arm_mve_vcmpltq_s16
#define __builtin_mve_vcmpltq_s32 __builtin_arm_mve_vcmpltq_s32
#define __builtin_mve_vcmpltq_s8 __builtin_arm_mve_vcmpltq_s8
#define __builtin_mve_vcmpneq_f16 __builtin_arm_mve_vcmpneq_f16
#define __builtin_mve_vcmpneq_f32 __builtin_arm_mve_vcmpneq_f32
#define __builtin_mve_vcmpneq_m_f16 __builtin_arm_mve_vcmpneq_m_f16
#define __builtin_mve_vcmpneq_m_f32 __builtin_arm_mve_vcmpneq_m_f32
#define __builtin_mve_vcmpneq_m_n_f16 __builtin_arm_mve_vcmpneq_m_n_f16
#define __builtin_mve_vcmpneq_m_n_f32 __builtin_arm_mve_vcmpneq_m_n_f32
#define __builtin_mve_vcmpneq_m_n_s16 __builtin_arm_mve_vcmpneq_m_n_s16
#define __builtin_mve_vcmpneq_m_n_s32 __builtin_arm_mve_vcmpneq_m_n_s32
#define __builtin_mve_vcmpneq_m_n_s8 __builtin_arm_mve_vcmpneq_m_n_s8
#define __builtin_mve_vcmpneq_m_n_u16 __builtin_arm_mve_vcmpneq_m_n_u16
#define __builtin_mve_vcmpneq_m_n_u32 __builtin_arm_mve_vcmpneq_m_n_u32
#define __builtin_mve_vcmpneq_m_n_u8 __builtin_arm_mve_vcmpneq_m_n_u8
#define __builtin_mve_vcmpneq_m_s16 __builtin_arm_mve_vcmpneq_m_s16
#define __builtin_mve_vcmpneq_m_s32 __builtin_arm_mve_vcmpneq_m_s32
#define __builtin_mve_vcmpneq_m_s8 __builtin_arm_mve_vcmpneq_m_s8
#define __builtin_mve_vcmpneq_m_u16 __builtin_arm_mve_vcmpneq_m_u16
#define __builtin_mve_vcmpneq_m_u32 __builtin_arm_mve_vcmpneq_m_u32
#define __builtin_mve_vcmpneq_m_u8 __builtin_arm_mve_vcmpneq_m_u8
#define __builtin_mve_vcmpneq_n_f16 __builtin_arm_mve_vcmpneq_n_f16
#define __builtin_mve_vcmpneq_n_f32 __builtin_arm_mve_vcmpneq_n_f32
#define __builtin_mve_vcmpneq_n_s16 __builtin_arm_mve_vcmpneq_n_s16
#define __builtin_mve_vcmpneq_n_s32 __builtin_arm_mve_vcmpneq_n_s32
#define __builtin_mve_vcmpneq_n_s8 __builtin_arm_mve_vcmpneq_n_s8
#define __builtin_mve_vcmpneq_n_u16 __builtin_arm_mve_vcmpneq_n_u16
#define __builtin_mve_vcmpneq_n_u32 __builtin_arm_mve_vcmpneq_n_u32
#define __builtin_mve_vcmpneq_n_u8 __builtin_arm_mve_vcmpneq_n_u8
#define __builtin_mve_vcmpneq_s16 __builtin_arm_mve_vcmpneq_s16
#define __builtin_mve_vcmpneq_s32 __builtin_arm_mve_vcmpneq_s32
#define __builtin_mve_vcmpneq_s8 __builtin_arm_mve_vcmpneq_s8
#define __builtin_mve_vcmpneq_u16 __builtin_arm_mve_vcmpneq_u16
#define __builtin_mve_vcmpneq_u32 __builtin_arm_mve_vcmpneq_u32
#define __builtin_mve_vcmpneq_u8 __builtin_arm_mve_vcmpneq_u8
#define __builtin_mve_vcmulq_f16 __builtin_arm_mve_vcmulq_f16
#define __builtin_mve_vcmulq_f32 __builtin_arm_mve_vcmulq_f32
#define __builtin_mve_vcmulq_m_f16 __builtin_arm_mve_vcmulq_m_f16
#define __builtin_mve_vcmulq_m_f32 __builtin_arm_mve_vcmulq_m_f32
#define __builtin_mve_vcmulq_rot180_f16 __builtin_arm_mve_vcmulq_rot180_f16
#define __builtin_mve_vcmulq_rot180_f32 __builtin_arm_mve_vcmulq_rot180_f32
#define __builtin_mve_vcmulq_rot180_m_f16 __builtin_arm_mve_vcmulq_rot180_m_f16
#define __builtin_mve_vcmulq_rot180_m_f32 __builtin_arm_mve_vcmulq_rot180_m_f32
#define __builtin_mve_vcmulq_rot270_f16 __builtin_arm_mve_vcmulq_rot270_f16
#define __builtin_mve_vcmulq_rot270_f32 __builtin_arm_mve_vcmulq_rot270_f32
#define __builtin_mve_vcmulq_rot270_m_f16 __builtin_arm_mve_vcmulq_rot270_m_f16
#define __builtin_mve_vcmulq_rot270_m_f32 __builtin_arm_mve_vcmulq_rot270_m_f32
#define __builtin_mve_vcmulq_rot90_f16 __builtin_arm_mve_vcmulq_rot90_f16
#define __builtin_mve_vcmulq_rot90_f32 __builtin_arm_mve_vcmulq_rot90_f32
#define __builtin_mve_vcmulq_rot90_m_f16 __builtin_arm_mve_vcmulq_rot90_m_f16
#define __builtin_mve_vcmulq_rot90_m_f32 __builtin_arm_mve_vcmulq_rot90_m_f32
#define __builtin_mve_vcreateq_f16 __builtin_arm_mve_vcreateq_f16
#define __builtin_mve_vcreateq_f32 __builtin_arm_mve_vcreateq_f32
#define __builtin_mve_vcreateq_s16 __builtin_arm_mve_vcreateq_s16
#define __builtin_mve_vcreateq_s32 __builtin_arm_mve_vcreateq_s32
#define __builtin_mve_vcreateq_s64 __builtin_arm_mve_vcreateq_s64
#define __builtin_mve_vcreateq_s8 __builtin_arm_mve_vcreateq_s8
#define __builtin_mve_vcreateq_u16 __builtin_arm_mve_vcreateq_u16
#define __builtin_mve_vcreateq_u32 __builtin_arm_mve_vcreateq_u32
#define __builtin_mve_vcreateq_u64 __builtin_arm_mve_vcreateq_u64
#define __builtin_mve_vcreateq_u8 __builtin_arm_mve_vcreateq_u8
#define __builtin_mve_vctp16q __builtin_arm_mve_vctp16q
#define __builtin_mve_vctp16q_m __builtin_arm_mve_vctp16q_m
#define __builtin_mve_vctp32q __builtin_arm_mve_vctp32q
#define __builtin_mve_vctp32q_m __builtin_arm_mve_vctp32q_m
#define __builtin_mve_vctp64q __builtin_arm_mve_vctp64q
#define __builtin_mve_vctp64q_m __builtin_arm_mve_vctp64q_m
#define __builtin_mve_vctp8q __builtin_arm_mve_vctp8q
#define __builtin_mve_vctp8q_m __builtin_arm_mve_vctp8q_m
#define __builtin_mve_vcvtaq_m_s16_f16 __builtin_arm_mve_vcvtaq_m_s16_f16
#define __builtin_mve_vcvtaq_m_s32_f32 __builtin_arm_mve_vcvtaq_m_s32_f32
#define __builtin_mve_vcvtaq_m_u16_f16 __builtin_arm_mve_vcvtaq_m_u16_f16
#define __builtin_mve_vcvtaq_m_u32_f32 __builtin_arm_mve_vcvtaq_m_u32_f32
#define __builtin_mve_vcvtaq_s16_f16 __builtin_arm_mve_vcvtaq_s16_f16
#define __builtin_mve_vcvtaq_s32_f32 __builtin_arm_mve_vcvtaq_s32_f32
#define __builtin_mve_vcvtaq_u16_f16 __builtin_arm_mve_vcvtaq_u16_f16
#define __builtin_mve_vcvtaq_u32_f32 __builtin_arm_mve_vcvtaq_u32_f32
#define __builtin_mve_vcvtbq_f16_f32 __builtin_arm_mve_vcvtbq_f16_f32
#define __builtin_mve_vcvtbq_f32_f16 __builtin_arm_mve_vcvtbq_f32_f16
#define __builtin_mve_vcvtbq_m_f16_f32 __builtin_arm_mve_vcvtbq_m_f16_f32
#define __builtin_mve_vcvtbq_m_f32_f16 __builtin_arm_mve_vcvtbq_m_f32_f16
#define __builtin_mve_vcvtmq_m_s16_f16 __builtin_arm_mve_vcvtmq_m_s16_f16
#define __builtin_mve_vcvtmq_m_s32_f32 __builtin_arm_mve_vcvtmq_m_s32_f32
#define __builtin_mve_vcvtmq_m_u16_f16 __builtin_arm_mve_vcvtmq_m_u16_f16
#define __builtin_mve_vcvtmq_m_u32_f32 __builtin_arm_mve_vcvtmq_m_u32_f32
#define __builtin_mve_vcvtmq_s16_f16 __builtin_arm_mve_vcvtmq_s16_f16
#define __builtin_mve_vcvtmq_s32_f32 __builtin_arm_mve_vcvtmq_s32_f32
#define __builtin_mve_vcvtmq_u16_f16 __builtin_arm_mve_vcvtmq_u16_f16
#define __builtin_mve_vcvtmq_u32_f32 __builtin_arm_mve_vcvtmq_u32_f32
#define __builtin_mve_vcvtnq_m_s16_f16 __builtin_arm_mve_vcvtnq_m_s16_f16
#define __builtin_mve_vcvtnq_m_s32_f32 __builtin_arm_mve_vcvtnq_m_s32_f32
#define __builtin_mve_vcvtnq_m_u16_f16 __builtin_arm_mve_vcvtnq_m_u16_f16
#define __builtin_mve_vcvtnq_m_u32_f32 __builtin_arm_mve_vcvtnq_m_u32_f32
#define __builtin_mve_vcvtnq_s16_f16 __builtin_arm_mve_vcvtnq_s16_f16
#define __builtin_mve_vcvtnq_s32_f32 __builtin_arm_mve_vcvtnq_s32_f32
#define __builtin_mve_vcvtnq_u16_f16 __builtin_arm_mve_vcvtnq_u16_f16
#define __builtin_mve_vcvtnq_u32_f32 __builtin_arm_mve_vcvtnq_u32_f32
#define __builtin_mve_vcvtpq_m_s16_f16 __builtin_arm_mve_vcvtpq_m_s16_f16
#define __builtin_mve_vcvtpq_m_s32_f32 __builtin_arm_mve_vcvtpq_m_s32_f32
#define __builtin_mve_vcvtpq_m_u16_f16 __builtin_arm_mve_vcvtpq_m_u16_f16
#define __builtin_mve_vcvtpq_m_u32_f32 __builtin_arm_mve_vcvtpq_m_u32_f32
#define __builtin_mve_vcvtpq_s16_f16 __builtin_arm_mve_vcvtpq_s16_f16
#define __builtin_mve_vcvtpq_s32_f32 __builtin_arm_mve_vcvtpq_s32_f32
#define __builtin_mve_vcvtpq_u16_f16 __builtin_arm_mve_vcvtpq_u16_f16
#define __builtin_mve_vcvtpq_u32_f32 __builtin_arm_mve_vcvtpq_u32_f32
#define __builtin_mve_vcvtq_f16_s16 __builtin_arm_mve_vcvtq_f16_s16
#define __builtin_mve_vcvtq_f16_u16 __builtin_arm_mve_vcvtq_f16_u16
#define __builtin_mve_vcvtq_f32_s32 __builtin_arm_mve_vcvtq_f32_s32
#define __builtin_mve_vcvtq_f32_u32 __builtin_arm_mve_vcvtq_f32_u32
#define __builtin_mve_vcvtq_m_f16_s16 __builtin_arm_mve_vcvtq_m_f16_s16
#define __builtin_mve_vcvtq_m_f16_u16 __builtin_arm_mve_vcvtq_m_f16_u16
#define __builtin_mve_vcvtq_m_f32_s32 __builtin_arm_mve_vcvtq_m_f32_s32
#define __builtin_mve_vcvtq_m_f32_u32 __builtin_arm_mve_vcvtq_m_f32_u32
#define __builtin_mve_vcvtq_m_s16_f16 __builtin_arm_mve_vcvtq_m_s16_f16
#define __builtin_mve_vcvtq_m_s32_f32 __builtin_arm_mve_vcvtq_m_s32_f32
#define __builtin_mve_vcvtq_m_u16_f16 __builtin_arm_mve_vcvtq_m_u16_f16
#define __builtin_mve_vcvtq_m_u32_f32 __builtin_arm_mve_vcvtq_m_u32_f32
#define __builtin_mve_vcvtq_s16_f16 __builtin_arm_mve_vcvtq_s16_f16
#define __builtin_mve_vcvtq_s32_f32 __builtin_arm_mve_vcvtq_s32_f32
#define __builtin_mve_vcvtq_u16_f16 __builtin_arm_mve_vcvtq_u16_f16
#define __builtin_mve_vcvtq_u32_f32 __builtin_arm_mve_vcvtq_u32_f32
#define __builtin_mve_vcvttq_f16_f32 __builtin_arm_mve_vcvttq_f16_f32
#define __builtin_mve_vcvttq_f32_f16 __builtin_arm_mve_vcvttq_f32_f16
#define __builtin_mve_vcvttq_m_f16_f32 __builtin_arm_mve_vcvttq_m_f16_f32
#define __builtin_mve_vcvttq_m_f32_f16 __builtin_arm_mve_vcvttq_m_f32_f16
#define __builtin_mve_vdupq_m_n_f16 __builtin_arm_mve_vdupq_m_n_f16
#define __builtin_mve_vdupq_m_n_f32 __builtin_arm_mve_vdupq_m_n_f32
#define __builtin_mve_vdupq_m_n_s16 __builtin_arm_mve_vdupq_m_n_s16
#define __builtin_mve_vdupq_m_n_s32 __builtin_arm_mve_vdupq_m_n_s32
#define __builtin_mve_vdupq_m_n_s8 __builtin_arm_mve_vdupq_m_n_s8
#define __builtin_mve_vdupq_m_n_u16 __builtin_arm_mve_vdupq_m_n_u16
#define __builtin_mve_vdupq_m_n_u32 __builtin_arm_mve_vdupq_m_n_u32
#define __builtin_mve_vdupq_m_n_u8 __builtin_arm_mve_vdupq_m_n_u8
#define __builtin_mve_vdupq_n_f16 __builtin_arm_mve_vdupq_n_f16
#define __builtin_mve_vdupq_n_f32 __builtin_arm_mve_vdupq_n_f32
#define __builtin_mve_vdupq_n_s16 __builtin_arm_mve_vdupq_n_s16
#define __builtin_mve_vdupq_n_s32 __builtin_arm_mve_vdupq_n_s32
#define __builtin_mve_vdupq_n_s8 __builtin_arm_mve_vdupq_n_s8
#define __builtin_mve_vdupq_n_u16 __builtin_arm_mve_vdupq_n_u16
#define __builtin_mve_vdupq_n_u32 __builtin_arm_mve_vdupq_n_u32
#define __builtin_mve_vdupq_n_u8 __builtin_arm_mve_vdupq_n_u8
#define __builtin_mve_veorq_f16 __builtin_arm_mve_veorq_f16
#define __builtin_mve_veorq_f32 __builtin_arm_mve_veorq_f32
#define __builtin_mve_veorq_m_f16 __builtin_arm_mve_veorq_m_f16
#define __builtin_mve_veorq_m_f32 __builtin_arm_mve_veorq_m_f32
#define __builtin_mve_veorq_m_s16 __builtin_arm_mve_veorq_m_s16
#define __builtin_mve_veorq_m_s32 __builtin_arm_mve_veorq_m_s32
#define __builtin_mve_veorq_m_s8 __builtin_arm_mve_veorq_m_s8
#define __builtin_mve_veorq_m_u16 __builtin_arm_mve_veorq_m_u16
#define __builtin_mve_veorq_m_u32 __builtin_arm_mve_veorq_m_u32
#define __builtin_mve_veorq_m_u8 __builtin_arm_mve_veorq_m_u8
#define __builtin_mve_veorq_s16 __builtin_arm_mve_veorq_s16
#define __builtin_mve_veorq_s32 __builtin_arm_mve_veorq_s32
#define __builtin_mve_veorq_s8 __builtin_arm_mve_veorq_s8
#define __builtin_mve_veorq_u16 __builtin_arm_mve_veorq_u16
#define __builtin_mve_veorq_u32 __builtin_arm_mve_veorq_u32
#define __builtin_mve_veorq_u8 __builtin_arm_mve_veorq_u8
#define __builtin_mve_vfmaq_f16 __builtin_arm_mve_vfmaq_f16
#define __builtin_mve_vfmaq_f32 __builtin_arm_mve_vfmaq_f32
#define __builtin_mve_vfmaq_m_f16 __builtin_arm_mve_vfmaq_m_f16
#define __builtin_mve_vfmaq_m_f32 __builtin_arm_mve_vfmaq_m_f32
#define __builtin_mve_vfmaq_m_n_f16 __builtin_arm_mve_vfmaq_m_n_f16
#define __builtin_mve_vfmaq_m_n_f32 __builtin_arm_mve_vfmaq_m_n_f32
#define __builtin_mve_vfmaq_n_f16 __builtin_arm_mve_vfmaq_n_f16
#define __builtin_mve_vfmaq_n_f32 __builtin_arm_mve_vfmaq_n_f32
#define __builtin_mve_vfmasq_m_n_f16 __builtin_arm_mve_vfmasq_m_n_f16
#define __builtin_mve_vfmasq_m_n_f32 __builtin_arm_mve_vfmasq_m_n_f32
#define __builtin_mve_vfmasq_n_f16 __builtin_arm_mve_vfmasq_n_f16
#define __builtin_mve_vfmasq_n_f32 __builtin_arm_mve_vfmasq_n_f32
#define __builtin_mve_vfmsq_f16 __builtin_arm_mve_vfmsq_f16
#define __builtin_mve_vfmsq_f32 __builtin_arm_mve_vfmsq_f32
#define __builtin_mve_vfmsq_m_f16 __builtin_arm_mve_vfmsq_m_f16
#define __builtin_mve_vfmsq_m_f32 __builtin_arm_mve_vfmsq_m_f32
#define __builtin_mve_vhaddq_m_n_s16 __builtin_arm_mve_vhaddq_m_n_s16
#define __builtin_mve_vhaddq_m_n_s32 __builtin_arm_mve_vhaddq_m_n_s32
#define __builtin_mve_vhaddq_m_n_s8 __builtin_arm_mve_vhaddq_m_n_s8
#define __builtin_mve_vhaddq_m_n_u16 __builtin_arm_mve_vhaddq_m_n_u16
#define __builtin_mve_vhaddq_m_n_u32 __builtin_arm_mve_vhaddq_m_n_u32
#define __builtin_mve_vhaddq_m_n_u8 __builtin_arm_mve_vhaddq_m_n_u8
#define __builtin_mve_vhaddq_m_s16 __builtin_arm_mve_vhaddq_m_s16
#define __builtin_mve_vhaddq_m_s32 __builtin_arm_mve_vhaddq_m_s32
#define __builtin_mve_vhaddq_m_s8 __builtin_arm_mve_vhaddq_m_s8
#define __builtin_mve_vhaddq_m_u16 __builtin_arm_mve_vhaddq_m_u16
#define __builtin_mve_vhaddq_m_u32 __builtin_arm_mve_vhaddq_m_u32
#define __builtin_mve_vhaddq_m_u8 __builtin_arm_mve_vhaddq_m_u8
#define __builtin_mve_vhaddq_n_s16 __builtin_arm_mve_vhaddq_n_s16
#define __builtin_mve_vhaddq_n_s32 __builtin_arm_mve_vhaddq_n_s32
#define __builtin_mve_vhaddq_n_s8 __builtin_arm_mve_vhaddq_n_s8
#define __builtin_mve_vhaddq_n_u16 __builtin_arm_mve_vhaddq_n_u16
#define __builtin_mve_vhaddq_n_u32 __builtin_arm_mve_vhaddq_n_u32
#define __builtin_mve_vhaddq_n_u8 __builtin_arm_mve_vhaddq_n_u8
#define __builtin_mve_vhaddq_s16 __builtin_arm_mve_vhaddq_s16
#define __builtin_mve_vhaddq_s32 __builtin_arm_mve_vhaddq_s32
#define __builtin_mve_vhaddq_s8 __builtin_arm_mve_vhaddq_s8
#define __builtin_mve_vhaddq_u16 __builtin_arm_mve_vhaddq_u16
#define __builtin_mve_vhaddq_u32 __builtin_arm_mve_vhaddq_u32
#define __builtin_mve_vhaddq_u8 __builtin_arm_mve_vhaddq_u8
#define __builtin_mve_vhcaddq_rot270_m_s16 __builtin_arm_mve_vhcaddq_rot270_m_s16
#define __builtin_mve_vhcaddq_rot270_m_s32 __builtin_arm_mve_vhcaddq_rot270_m_s32
#define __builtin_mve_vhcaddq_rot270_m_s8 __builtin_arm_mve_vhcaddq_rot270_m_s8
#define __builtin_mve_vhcaddq_rot270_s16 __builtin_arm_mve_vhcaddq_rot270_s16
#define __builtin_mve_vhcaddq_rot270_s32 __builtin_arm_mve_vhcaddq_rot270_s32
#define __builtin_mve_vhcaddq_rot270_s8 __builtin_arm_mve_vhcaddq_rot270_s8
#define __builtin_mve_vhcaddq_rot90_m_s16 __builtin_arm_mve_vhcaddq_rot90_m_s16
#define __builtin_mve_vhcaddq_rot90_m_s32 __builtin_arm_mve_vhcaddq_rot90_m_s32
#define __builtin_mve_vhcaddq_rot90_m_s8 __builtin_arm_mve_vhcaddq_rot90_m_s8
#define __builtin_mve_vhcaddq_rot90_s16 __builtin_arm_mve_vhcaddq_rot90_s16
#define __builtin_mve_vhcaddq_rot90_s32 __builtin_arm_mve_vhcaddq_rot90_s32
#define __builtin_mve_vhcaddq_rot90_s8 __builtin_arm_mve_vhcaddq_rot90_s8
#define __builtin_mve_vhsubq_m_n_s16 __builtin_arm_mve_vhsubq_m_n_s16
#define __builtin_mve_vhsubq_m_n_s32 __builtin_arm_mve_vhsubq_m_n_s32
#define __builtin_mve_vhsubq_m_n_s8 __builtin_arm_mve_vhsubq_m_n_s8
#define __builtin_mve_vhsubq_m_n_u16 __builtin_arm_mve_vhsubq_m_n_u16
#define __builtin_mve_vhsubq_m_n_u32 __builtin_arm_mve_vhsubq_m_n_u32
#define __builtin_mve_vhsubq_m_n_u8 __builtin_arm_mve_vhsubq_m_n_u8
#define __builtin_mve_vhsubq_m_s16 __builtin_arm_mve_vhsubq_m_s16
#define __builtin_mve_vhsubq_m_s32 __builtin_arm_mve_vhsubq_m_s32
#define __builtin_mve_vhsubq_m_s8 __builtin_arm_mve_vhsubq_m_s8
#define __builtin_mve_vhsubq_m_u16 __builtin_arm_mve_vhsubq_m_u16
#define __builtin_mve_vhsubq_m_u32 __builtin_arm_mve_vhsubq_m_u32
#define __builtin_mve_vhsubq_m_u8 __builtin_arm_mve_vhsubq_m_u8
#define __builtin_mve_vhsubq_n_s16 __builtin_arm_mve_vhsubq_n_s16
#define __builtin_mve_vhsubq_n_s32 __builtin_arm_mve_vhsubq_n_s32
#define __builtin_mve_vhsubq_n_s8 __builtin_arm_mve_vhsubq_n_s8
#define __builtin_mve_vhsubq_n_u16 __builtin_arm_mve_vhsubq_n_u16
#define __builtin_mve_vhsubq_n_u32 __builtin_arm_mve_vhsubq_n_u32
#define __builtin_mve_vhsubq_n_u8 __builtin_arm_mve_vhsubq_n_u8
#define __builtin_mve_vhsubq_s16 __builtin_arm_mve_vhsubq_s16
#define __builtin_mve_vhsubq_s32 __builtin_arm_mve_vhsubq_s32
#define __builtin_mve_vhsubq_s8 __builtin_arm_mve_vhsubq_s8
#define __builtin_mve_vhsubq_u16 __builtin_arm_mve_vhsubq_u16
#define __builtin_mve_vhsubq_u32 __builtin_arm_mve_vhsubq_u32
#define __builtin_mve_vhsubq_u8 __builtin_arm_mve_vhsubq_u8
#define __builtin_mve_vldrbq_gather_offset_s16 __builtin_arm_mve_vldrbq_gather_offset_s16
#define __builtin_mve_vldrbq_gather_offset_s32 __builtin_arm_mve_vldrbq_gather_offset_s32
#define __builtin_mve_vldrbq_gather_offset_s8 __builtin_arm_mve_vldrbq_gather_offset_s8
#define __builtin_mve_vldrbq_gather_offset_u16 __builtin_arm_mve_vldrbq_gather_offset_u16
#define __builtin_mve_vldrbq_gather_offset_u32 __builtin_arm_mve_vldrbq_gather_offset_u32
#define __builtin_mve_vldrbq_gather_offset_u8 __builtin_arm_mve_vldrbq_gather_offset_u8
#define __builtin_mve_vldrbq_gather_offset_z_s16 __builtin_arm_mve_vldrbq_gather_offset_z_s16
#define __builtin_mve_vldrbq_gather_offset_z_s32 __builtin_arm_mve_vldrbq_gather_offset_z_s32
#define __builtin_mve_vldrbq_gather_offset_z_s8 __builtin_arm_mve_vldrbq_gather_offset_z_s8
#define __builtin_mve_vldrbq_gather_offset_z_u16 __builtin_arm_mve_vldrbq_gather_offset_z_u16
#define __builtin_mve_vldrbq_gather_offset_z_u32 __builtin_arm_mve_vldrbq_gather_offset_z_u32
#define __builtin_mve_vldrbq_gather_offset_z_u8 __builtin_arm_mve_vldrbq_gather_offset_z_u8
#define __builtin_mve_vldrbq_s16 __builtin_arm_mve_vldrbq_s16
#define __builtin_mve_vldrbq_s32 __builtin_arm_mve_vldrbq_s32
#define __builtin_mve_vldrbq_s8 __builtin_arm_mve_vldrbq_s8
#define __builtin_mve_vldrbq_u16 __builtin_arm_mve_vldrbq_u16
#define __builtin_mve_vldrbq_u32 __builtin_arm_mve_vldrbq_u32
#define __builtin_mve_vldrbq_u8 __builtin_arm_mve_vldrbq_u8
#define __builtin_mve_vldrbq_z_s16 __builtin_arm_mve_vldrbq_z_s16
#define __builtin_mve_vldrbq_z_s32 __builtin_arm_mve_vldrbq_z_s32
#define __builtin_mve_vldrbq_z_s8 __builtin_arm_mve_vldrbq_z_s8
#define __builtin_mve_vldrbq_z_u16 __builtin_arm_mve_vldrbq_z_u16
#define __builtin_mve_vldrbq_z_u32 __builtin_arm_mve_vldrbq_z_u32
#define __builtin_mve_vldrbq_z_u8 __builtin_arm_mve_vldrbq_z_u8
#define __builtin_mve_vldrdq_gather_offset_s64 __builtin_arm_mve_vldrdq_gather_offset_s64
#define __builtin_mve_vldrdq_gather_offset_u64 __builtin_arm_mve_vldrdq_gather_offset_u64
#define __builtin_mve_vldrdq_gather_offset_z_s64 __builtin_arm_mve_vldrdq_gather_offset_z_s64
#define __builtin_mve_vldrdq_gather_offset_z_u64 __builtin_arm_mve_vldrdq_gather_offset_z_u64
#define __builtin_mve_vldrdq_gather_shifted_offset_s64 __builtin_arm_mve_vldrdq_gather_shifted_offset_s64
#define __builtin_mve_vldrdq_gather_shifted_offset_u64 __builtin_arm_mve_vldrdq_gather_shifted_offset_u64
#define __builtin_mve_vldrdq_gather_shifted_offset_z_s64 __builtin_arm_mve_vldrdq_gather_shifted_offset_z_s64
#define __builtin_mve_vldrdq_gather_shifted_offset_z_u64 __builtin_arm_mve_vldrdq_gather_shifted_offset_z_u64
#define __builtin_mve_vldrhq_f16 __builtin_arm_mve_vldrhq_f16
#define __builtin_mve_vldrhq_gather_offset_f16 __builtin_arm_mve_vldrhq_gather_offset_f16
#define __builtin_mve_vldrhq_gather_offset_s16 __builtin_arm_mve_vldrhq_gather_offset_s16
#define __builtin_mve_vldrhq_gather_offset_s32 __builtin_arm_mve_vldrhq_gather_offset_s32
#define __builtin_mve_vldrhq_gather_offset_u16 __builtin_arm_mve_vldrhq_gather_offset_u16
#define __builtin_mve_vldrhq_gather_offset_u32 __builtin_arm_mve_vldrhq_gather_offset_u32
#define __builtin_mve_vldrhq_gather_offset_z_f16 __builtin_arm_mve_vldrhq_gather_offset_z_f16
#define __builtin_mve_vldrhq_gather_offset_z_s16 __builtin_arm_mve_vldrhq_gather_offset_z_s16
#define __builtin_mve_vldrhq_gather_offset_z_s32 __builtin_arm_mve_vldrhq_gather_offset_z_s32
#define __builtin_mve_vldrhq_gather_offset_z_u16 __builtin_arm_mve_vldrhq_gather_offset_z_u16
#define __builtin_mve_vldrhq_gather_offset_z_u32 __builtin_arm_mve_vldrhq_gather_offset_z_u32
#define __builtin_mve_vldrhq_gather_shifted_offset_f16 __builtin_arm_mve_vldrhq_gather_shifted_offset_f16
#define __builtin_mve_vldrhq_gather_shifted_offset_s16 __builtin_arm_mve_vldrhq_gather_shifted_offset_s16
#define __builtin_mve_vldrhq_gather_shifted_offset_s32 __builtin_arm_mve_vldrhq_gather_shifted_offset_s32
#define __builtin_mve_vldrhq_gather_shifted_offset_u16 __builtin_arm_mve_vldrhq_gather_shifted_offset_u16
#define __builtin_mve_vldrhq_gather_shifted_offset_u32 __builtin_arm_mve_vldrhq_gather_shifted_offset_u32
#define __builtin_mve_vldrhq_gather_shifted_offset_z_f16 __builtin_arm_mve_vldrhq_gather_shifted_offset_z_f16
#define __builtin_mve_vldrhq_gather_shifted_offset_z_s16 __builtin_arm_mve_vldrhq_gather_shifted_offset_z_s16
#define __builtin_mve_vldrhq_gather_shifted_offset_z_s32 __builtin_arm_mve_vldrhq_gather_shifted_offset_z_s32
#define __builtin_mve_vldrhq_gather_shifted_offset_z_u16 __builtin_arm_mve_vldrhq_gather_shifted_offset_z_u16
#define __builtin_mve_vldrhq_gather_shifted_offset_z_u32 __builtin_arm_mve_vldrhq_gather_shifted_offset_z_u32
#define __builtin_mve_vldrhq_s16 __builtin_arm_mve_vldrhq_s16
#define __builtin_mve_vldrhq_s32 __builtin_arm_mve_vldrhq_s32
#define __builtin_mve_vldrhq_u16 __builtin_arm_mve_vldrhq_u16
#define __builtin_mve_vldrhq_u32 __builtin_arm_mve_vldrhq_u32
#define __builtin_mve_vldrhq_z_f16 __builtin_arm_mve_vldrhq_z_f16
#define __builtin_mve_vldrhq_z_s16 __builtin_arm_mve_vldrhq_z_s16
#define __builtin_mve_vldrhq_z_s32 __builtin_arm_mve_vldrhq_z_s32
#define __builtin_mve_vldrhq_z_u16 __builtin_arm_mve_vldrhq_z_u16
#define __builtin_mve_vldrhq_z_u32 __builtin_arm_mve_vldrhq_z_u32
#define __builtin_mve_vldrwq_f32 __builtin_arm_mve_vldrwq_f32
#define __builtin_mve_vldrwq_gather_offset_f32 __builtin_arm_mve_vldrwq_gather_offset_f32
#define __builtin_mve_vldrwq_gather_offset_s32 __builtin_arm_mve_vldrwq_gather_offset_s32
#define __builtin_mve_vldrwq_gather_offset_u32 __builtin_arm_mve_vldrwq_gather_offset_u32
#define __builtin_mve_vldrwq_gather_offset_z_f32 __builtin_arm_mve_vldrwq_gather_offset_z_f32
#define __builtin_mve_vldrwq_gather_offset_z_s32 __builtin_arm_mve_vldrwq_gather_offset_z_s32
#define __builtin_mve_vldrwq_gather_offset_z_u32 __builtin_arm_mve_vldrwq_gather_offset_z_u32
#define __builtin_mve_vldrwq_gather_shifted_offset_f32 __builtin_arm_mve_vldrwq_gather_shifted_offset_f32
#define __builtin_mve_vldrwq_gather_shifted_offset_s32 __builtin_arm_mve_vldrwq_gather_shifted_offset_s32
#define __builtin_mve_vldrwq_gather_shifted_offset_u32 __builtin_arm_mve_vldrwq_gather_shifted_offset_u32
#define __builtin_mve_vldrwq_gather_shifted_offset_z_f32 __builtin_arm_mve_vldrwq_gather_shifted_offset_z_f32
#define __builtin_mve_vldrwq_gather_shifted_offset_z_s32 __builtin_arm_mve_vldrwq_gather_shifted_offset_z_s32
#define __builtin_mve_vldrwq_gather_shifted_offset_z_u32 __builtin_arm_mve_vldrwq_gather_shifted_offset_z_u32
#define __builtin_mve_vldrwq_s32 __builtin_arm_mve_vldrwq_s32
#define __builtin_mve_vldrwq_u32 __builtin_arm_mve_vldrwq_u32
#define __builtin_mve_vldrwq_z_f32 __builtin_arm_mve_vldrwq_z_f32
#define __builtin_mve_vldrwq_z_s32 __builtin_arm_mve_vldrwq_z_s32
#define __builtin_mve_vldrwq_z_u32 __builtin_arm_mve_vldrwq_z_u32
#define __builtin_mve_vmaxaq_m_s16 __builtin_arm_mve_vmaxaq_m_s16
#define __builtin_mve_vmaxaq_m_s32 __builtin_arm_mve_vmaxaq_m_s32
#define __builtin_mve_vmaxaq_m_s8 __builtin_arm_mve_vmaxaq_m_s8
#define __builtin_mve_vmaxaq_s16 __builtin_arm_mve_vmaxaq_s16
#define __builtin_mve_vmaxaq_s32 __builtin_arm_mve_vmaxaq_s32
#define __builtin_mve_vmaxaq_s8 __builtin_arm_mve_vmaxaq_s8
#define __builtin_mve_vmaxavq_p_s16 __builtin_arm_mve_vmaxavq_p_s16
#define __builtin_mve_vmaxavq_p_s32 __builtin_arm_mve_vmaxavq_p_s32
#define __builtin_mve_vmaxavq_p_s8 __builtin_arm_mve_vmaxavq_p_s8
#define __builtin_mve_vmaxavq_s16 __builtin_arm_mve_vmaxavq_s16
#define __builtin_mve_vmaxavq_s32 __builtin_arm_mve_vmaxavq_s32
#define __builtin_mve_vmaxavq_s8 __builtin_arm_mve_vmaxavq_s8
#define __builtin_mve_vmaxnmaq_f16 __builtin_arm_mve_vmaxnmaq_f16
#define __builtin_mve_vmaxnmaq_f32 __builtin_arm_mve_vmaxnmaq_f32
#define __builtin_mve_vmaxnmaq_m_f16 __builtin_arm_mve_vmaxnmaq_m_f16
#define __builtin_mve_vmaxnmaq_m_f32 __builtin_arm_mve_vmaxnmaq_m_f32
#define __builtin_mve_vmaxnmavq_f16 __builtin_arm_mve_vmaxnmavq_f16
#define __builtin_mve_vmaxnmavq_f32 __builtin_arm_mve_vmaxnmavq_f32
#define __builtin_mve_vmaxnmavq_p_f16 __builtin_arm_mve_vmaxnmavq_p_f16
#define __builtin_mve_vmaxnmavq_p_f32 __builtin_arm_mve_vmaxnmavq_p_f32
#define __builtin_mve_vmaxnmq_f16 __builtin_arm_mve_vmaxnmq_f16
#define __builtin_mve_vmaxnmq_f32 __builtin_arm_mve_vmaxnmq_f32
#define __builtin_mve_vmaxnmq_m_f16 __builtin_arm_mve_vmaxnmq_m_f16
#define __builtin_mve_vmaxnmq_m_f32 __builtin_arm_mve_vmaxnmq_m_f32
#define __builtin_mve_vmaxnmvq_f16 __builtin_arm_mve_vmaxnmvq_f16
#define __builtin_mve_vmaxnmvq_f32 __builtin_arm_mve_vmaxnmvq_f32
#define __builtin_mve_vmaxnmvq_p_f16 __builtin_arm_mve_vmaxnmvq_p_f16
#define __builtin_mve_vmaxnmvq_p_f32 __builtin_arm_mve_vmaxnmvq_p_f32
#define __builtin_mve_vmaxq_m_s16 __builtin_arm_mve_vmaxq_m_s16
#define __builtin_mve_vmaxq_m_s32 __builtin_arm_mve_vmaxq_m_s32
#define __builtin_mve_vmaxq_m_s8 __builtin_arm_mve_vmaxq_m_s8
#define __builtin_mve_vmaxq_m_u16 __builtin_arm_mve_vmaxq_m_u16
#define __builtin_mve_vmaxq_m_u32 __builtin_arm_mve_vmaxq_m_u32
#define __builtin_mve_vmaxq_m_u8 __builtin_arm_mve_vmaxq_m_u8
#define __builtin_mve_vmaxq_s16 __builtin_arm_mve_vmaxq_s16
#define __builtin_mve_vmaxq_s32 __builtin_arm_mve_vmaxq_s32
#define __builtin_mve_vmaxq_s8 __builtin_arm_mve_vmaxq_s8
#define __builtin_mve_vmaxq_u16 __builtin_arm_mve_vmaxq_u16
#define __builtin_mve_vmaxq_u32 __builtin_arm_mve_vmaxq_u32
#define __builtin_mve_vmaxq_u8 __builtin_arm_mve_vmaxq_u8
#define __builtin_mve_vmaxvq_p_s16 __builtin_arm_mve_vmaxvq_p_s16
#define __builtin_mve_vmaxvq_p_s32 __builtin_arm_mve_vmaxvq_p_s32
#define __builtin_mve_vmaxvq_p_s8 __builtin_arm_mve_vmaxvq_p_s8
#define __builtin_mve_vmaxvq_p_u16 __builtin_arm_mve_vmaxvq_p_u16
#define __builtin_mve_vmaxvq_p_u32 __builtin_arm_mve_vmaxvq_p_u32
#define __builtin_mve_vmaxvq_p_u8 __builtin_arm_mve_vmaxvq_p_u8
#define __builtin_mve_vmaxvq_s16 __builtin_arm_mve_vmaxvq_s16
#define __builtin_mve_vmaxvq_s32 __builtin_arm_mve_vmaxvq_s32
#define __builtin_mve_vmaxvq_s8 __builtin_arm_mve_vmaxvq_s8
#define __builtin_mve_vmaxvq_u16 __builtin_arm_mve_vmaxvq_u16
#define __builtin_mve_vmaxvq_u32 __builtin_arm_mve_vmaxvq_u32
#define __builtin_mve_vmaxvq_u8 __builtin_arm_mve_vmaxvq_u8
#define __builtin_mve_vminaq_m_s16 __builtin_arm_mve_vminaq_m_s16
#define __builtin_mve_vminaq_m_s32 __builtin_arm_mve_vminaq_m_s32
#define __builtin_mve_vminaq_m_s8 __builtin_arm_mve_vminaq_m_s8
#define __builtin_mve_vminaq_s16 __builtin_arm_mve_vminaq_s16
#define __builtin_mve_vminaq_s32 __builtin_arm_mve_vminaq_s32
#define __builtin_mve_vminaq_s8 __builtin_arm_mve_vminaq_s8
#define __builtin_mve_vminavq_p_s16 __builtin_arm_mve_vminavq_p_s16
#define __builtin_mve_vminavq_p_s32 __builtin_arm_mve_vminavq_p_s32
#define __builtin_mve_vminavq_p_s8 __builtin_arm_mve_vminavq_p_s8
#define __builtin_mve_vminavq_s16 __builtin_arm_mve_vminavq_s16
#define __builtin_mve_vminavq_s32 __builtin_arm_mve_vminavq_s32
#define __builtin_mve_vminavq_s8 __builtin_arm_mve_vminavq_s8
#define __builtin_mve_vminnmaq_f16 __builtin_arm_mve_vminnmaq_f16
#define __builtin_mve_vminnmaq_f32 __builtin_arm_mve_vminnmaq_f32
#define __builtin_mve_vminnmaq_m_f16 __builtin_arm_mve_vminnmaq_m_f16
#define __builtin_mve_vminnmaq_m_f32 __builtin_arm_mve_vminnmaq_m_f32
#define __builtin_mve_vminnmavq_f16 __builtin_arm_mve_vminnmavq_f16
#define __builtin_mve_vminnmavq_f32 __builtin_arm_mve_vminnmavq_f32
#define __builtin_mve_vminnmavq_p_f16 __builtin_arm_mve_vminnmavq_p_f16
#define __builtin_mve_vminnmavq_p_f32 __builtin_arm_mve_vminnmavq_p_f32
#define __builtin_mve_vminnmq_f16 __builtin_arm_mve_vminnmq_f16
#define __builtin_mve_vminnmq_f32 __builtin_arm_mve_vminnmq_f32
#define __builtin_mve_vminnmq_m_f16 __builtin_arm_mve_vminnmq_m_f16
#define __builtin_mve_vminnmq_m_f32 __builtin_arm_mve_vminnmq_m_f32
#define __builtin_mve_vminnmvq_f16 __builtin_arm_mve_vminnmvq_f16
#define __builtin_mve_vminnmvq_f32 __builtin_arm_mve_vminnmvq_f32
#define __builtin_mve_vminnmvq_p_f16 __builtin_arm_mve_vminnmvq_p_f16
#define __builtin_mve_vminnmvq_p_f32 __builtin_arm_mve_vminnmvq_p_f32
#define __builtin_mve_vminq_m_s16 __builtin_arm_mve_vminq_m_s16
#define __builtin_mve_vminq_m_s32 __builtin_arm_mve_vminq_m_s32
#define __builtin_mve_vminq_m_s8 __builtin_arm_mve_vminq_m_s8
#define __builtin_mve_vminq_m_u16 __builtin_arm_mve_vminq_m_u16
#define __builtin_mve_vminq_m_u32 __builtin_arm_mve_vminq_m_u32
#define __builtin_mve_vminq_m_u8 __builtin_arm_mve_vminq_m_u8
#define __builtin_mve_vminq_s16 __builtin_arm_mve_vminq_s16
#define __builtin_mve_vminq_s32 __builtin_arm_mve_vminq_s32
#define __builtin_mve_vminq_s8 __builtin_arm_mve_vminq_s8
#define __builtin_mve_vminq_u16 __builtin_arm_mve_vminq_u16
#define __builtin_mve_vminq_u32 __builtin_arm_mve_vminq_u32
#define __builtin_mve_vminq_u8 __builtin_arm_mve_vminq_u8
#define __builtin_mve_vminvq_p_s16 __builtin_arm_mve_vminvq_p_s16
#define __builtin_mve_vminvq_p_s32 __builtin_arm_mve_vminvq_p_s32
#define __builtin_mve_vminvq_p_s8 __builtin_arm_mve_vminvq_p_s8
#define __builtin_mve_vminvq_p_u16 __builtin_arm_mve_vminvq_p_u16
#define __builtin_mve_vminvq_p_u32 __builtin_arm_mve_vminvq_p_u32
#define __builtin_mve_vminvq_p_u8 __builtin_arm_mve_vminvq_p_u8
#define __builtin_mve_vminvq_s16 __builtin_arm_mve_vminvq_s16
#define __builtin_mve_vminvq_s32 __builtin_arm_mve_vminvq_s32
#define __builtin_mve_vminvq_s8 __builtin_arm_mve_vminvq_s8
#define __builtin_mve_vminvq_u16 __builtin_arm_mve_vminvq_u16
#define __builtin_mve_vminvq_u32 __builtin_arm_mve_vminvq_u32
#define __builtin_mve_vminvq_u8 __builtin_arm_mve_vminvq_u8
#define __builtin_mve_vmladavaq_p_s16 __builtin_arm_mve_vmladavaq_p_s16
#define __builtin_mve_vmladavaq_p_s32 __builtin_arm_mve_vmladavaq_p_s32
#define __builtin_mve_vmladavaq_p_s8 __builtin_arm_mve_vmladavaq_p_s8
#define __builtin_mve_vmladavaq_p_u16 __builtin_arm_mve_vmladavaq_p_u16
#define __builtin_mve_vmladavaq_p_u32 __builtin_arm_mve_vmladavaq_p_u32
#define __builtin_mve_vmladavaq_p_u8 __builtin_arm_mve_vmladavaq_p_u8
#define __builtin_mve_vmladavaq_s16 __builtin_arm_mve_vmladavaq_s16
#define __builtin_mve_vmladavaq_s32 __builtin_arm_mve_vmladavaq_s32
#define __builtin_mve_vmladavaq_s8 __builtin_arm_mve_vmladavaq_s8
#define __builtin_mve_vmladavaq_u16 __builtin_arm_mve_vmladavaq_u16
#define __builtin_mve_vmladavaq_u32 __builtin_arm_mve_vmladavaq_u32
#define __builtin_mve_vmladavaq_u8 __builtin_arm_mve_vmladavaq_u8
#define __builtin_mve_vmladavaxq_p_s16 __builtin_arm_mve_vmladavaxq_p_s16
#define __builtin_mve_vmladavaxq_p_s32 __builtin_arm_mve_vmladavaxq_p_s32
#define __builtin_mve_vmladavaxq_p_s8 __builtin_arm_mve_vmladavaxq_p_s8
#define __builtin_mve_vmladavaxq_s16 __builtin_arm_mve_vmladavaxq_s16
#define __builtin_mve_vmladavaxq_s32 __builtin_arm_mve_vmladavaxq_s32
#define __builtin_mve_vmladavaxq_s8 __builtin_arm_mve_vmladavaxq_s8
#define __builtin_mve_vmladavq_p_s16 __builtin_arm_mve_vmladavq_p_s16
#define __builtin_mve_vmladavq_p_s32 __builtin_arm_mve_vmladavq_p_s32
#define __builtin_mve_vmladavq_p_s8 __builtin_arm_mve_vmladavq_p_s8
#define __builtin_mve_vmladavq_p_u16 __builtin_arm_mve_vmladavq_p_u16
#define __builtin_mve_vmladavq_p_u32 __builtin_arm_mve_vmladavq_p_u32
#define __builtin_mve_vmladavq_p_u8 __builtin_arm_mve_vmladavq_p_u8
#define __builtin_mve_vmladavq_s16 __builtin_arm_mve_vmladavq_s16
#define __builtin_mve_vmladavq_s32 __builtin_arm_mve_vmladavq_s32
#define __builtin_mve_vmladavq_s8 __builtin_arm_mve_vmladavq_s8
#define __builtin_mve_vmladavq_u16 __builtin_arm_mve_vmladavq_u16
#define __builtin_mve_vmladavq_u32 __builtin_arm_mve_vmladavq_u32
#define __builtin_mve_vmladavq_u8 __builtin_arm_mve_vmladavq_u8
#define __builtin_mve_vmladavxq_p_s16 __builtin_arm_mve_vmladavxq_p_s16
#define __builtin_mve_vmladavxq_p_s32 __builtin_arm_mve_vmladavxq_p_s32
#define __builtin_mve_vmladavxq_p_s8 __builtin_arm_mve_vmladavxq_p_s8
#define __builtin_mve_vmladavxq_s16 __builtin_arm_mve_vmladavxq_s16
#define __builtin_mve_vmladavxq_s32 __builtin_arm_mve_vmladavxq_s32
#define __builtin_mve_vmladavxq_s8 __builtin_arm_mve_vmladavxq_s8
#define __builtin_mve_vmlaldavaq_p_s16 __builtin_arm_mve_vmlaldavaq_p_s16
#define __builtin_mve_vmlaldavaq_p_s32 __builtin_arm_mve_vmlaldavaq_p_s32
#define __builtin_mve_vmlaldavaq_p_u16 __builtin_arm_mve_vmlaldavaq_p_u16
#define __builtin_mve_vmlaldavaq_p_u32 __builtin_arm_mve_vmlaldavaq_p_u32
#define __builtin_mve_vmlaldavaq_s16 __builtin_arm_mve_vmlaldavaq_s16
#define __builtin_mve_vmlaldavaq_s32 __builtin_arm_mve_vmlaldavaq_s32
#define __builtin_mve_vmlaldavaq_u16 __builtin_arm_mve_vmlaldavaq_u16
#define __builtin_mve_vmlaldavaq_u32 __builtin_arm_mve_vmlaldavaq_u32
#define __builtin_mve_vmlaldavaxq_p_s16 __builtin_arm_mve_vmlaldavaxq_p_s16
#define __builtin_mve_vmlaldavaxq_p_s32 __builtin_arm_mve_vmlaldavaxq_p_s32
#define __builtin_mve_vmlaldavaxq_s16 __builtin_arm_mve_vmlaldavaxq_s16
#define __builtin_mve_vmlaldavaxq_s32 __builtin_arm_mve_vmlaldavaxq_s32
#define __builtin_mve_vmlaldavq_p_s16 __builtin_arm_mve_vmlaldavq_p_s16
#define __builtin_mve_vmlaldavq_p_s32 __builtin_arm_mve_vmlaldavq_p_s32
#define __builtin_mve_vmlaldavq_p_u16 __builtin_arm_mve_vmlaldavq_p_u16
#define __builtin_mve_vmlaldavq_p_u32 __builtin_arm_mve_vmlaldavq_p_u32
#define __builtin_mve_vmlaldavq_s16 __builtin_arm_mve_vmlaldavq_s16
#define __builtin_mve_vmlaldavq_s32 __builtin_arm_mve_vmlaldavq_s32
#define __builtin_mve_vmlaldavq_u16 __builtin_arm_mve_vmlaldavq_u16
#define __builtin_mve_vmlaldavq_u32 __builtin_arm_mve_vmlaldavq_u32
#define __builtin_mve_vmlaldavxq_p_s16 __builtin_arm_mve_vmlaldavxq_p_s16
#define __builtin_mve_vmlaldavxq_p_s32 __builtin_arm_mve_vmlaldavxq_p_s32
#define __builtin_mve_vmlaldavxq_s16 __builtin_arm_mve_vmlaldavxq_s16
#define __builtin_mve_vmlaldavxq_s32 __builtin_arm_mve_vmlaldavxq_s32
#define __builtin_mve_vmlaq_m_n_s16 __builtin_arm_mve_vmlaq_m_n_s16
#define __builtin_mve_vmlaq_m_n_s32 __builtin_arm_mve_vmlaq_m_n_s32
#define __builtin_mve_vmlaq_m_n_s8 __builtin_arm_mve_vmlaq_m_n_s8
#define __builtin_mve_vmlaq_m_n_u16 __builtin_arm_mve_vmlaq_m_n_u16
#define __builtin_mve_vmlaq_m_n_u32 __builtin_arm_mve_vmlaq_m_n_u32
#define __builtin_mve_vmlaq_m_n_u8 __builtin_arm_mve_vmlaq_m_n_u8
#define __builtin_mve_vmlaq_n_s16 __builtin_arm_mve_vmlaq_n_s16
#define __builtin_mve_vmlaq_n_s32 __builtin_arm_mve_vmlaq_n_s32
#define __builtin_mve_vmlaq_n_s8 __builtin_arm_mve_vmlaq_n_s8
#define __builtin_mve_vmlaq_n_u16 __builtin_arm_mve_vmlaq_n_u16
#define __builtin_mve_vmlaq_n_u32 __builtin_arm_mve_vmlaq_n_u32
#define __builtin_mve_vmlaq_n_u8 __builtin_arm_mve_vmlaq_n_u8
#define __builtin_mve_vmlasq_m_n_s16 __builtin_arm_mve_vmlasq_m_n_s16
#define __builtin_mve_vmlasq_m_n_s32 __builtin_arm_mve_vmlasq_m_n_s32
#define __builtin_mve_vmlasq_m_n_s8 __builtin_arm_mve_vmlasq_m_n_s8
#define __builtin_mve_vmlasq_m_n_u16 __builtin_arm_mve_vmlasq_m_n_u16
#define __builtin_mve_vmlasq_m_n_u32 __builtin_arm_mve_vmlasq_m_n_u32
#define __builtin_mve_vmlasq_m_n_u8 __builtin_arm_mve_vmlasq_m_n_u8
#define __builtin_mve_vmlasq_n_s16 __builtin_arm_mve_vmlasq_n_s16
#define __builtin_mve_vmlasq_n_s32 __builtin_arm_mve_vmlasq_n_s32
#define __builtin_mve_vmlasq_n_s8 __builtin_arm_mve_vmlasq_n_s8
#define __builtin_mve_vmlasq_n_u16 __builtin_arm_mve_vmlasq_n_u16
#define __builtin_mve_vmlasq_n_u32 __builtin_arm_mve_vmlasq_n_u32
#define __builtin_mve_vmlasq_n_u8 __builtin_arm_mve_vmlasq_n_u8
#define __builtin_mve_vmlsdavaq_p_s16 __builtin_arm_mve_vmlsdavaq_p_s16
#define __builtin_mve_vmlsdavaq_p_s32 __builtin_arm_mve_vmlsdavaq_p_s32
#define __builtin_mve_vmlsdavaq_p_s8 __builtin_arm_mve_vmlsdavaq_p_s8
#define __builtin_mve_vmlsdavaq_s16 __builtin_arm_mve_vmlsdavaq_s16
#define __builtin_mve_vmlsdavaq_s32 __builtin_arm_mve_vmlsdavaq_s32
#define __builtin_mve_vmlsdavaq_s8 __builtin_arm_mve_vmlsdavaq_s8
#define __builtin_mve_vmlsdavaxq_p_s16 __builtin_arm_mve_vmlsdavaxq_p_s16
#define __builtin_mve_vmlsdavaxq_p_s32 __builtin_arm_mve_vmlsdavaxq_p_s32
#define __builtin_mve_vmlsdavaxq_p_s8 __builtin_arm_mve_vmlsdavaxq_p_s8
#define __builtin_mve_vmlsdavaxq_s16 __builtin_arm_mve_vmlsdavaxq_s16
#define __builtin_mve_vmlsdavaxq_s32 __builtin_arm_mve_vmlsdavaxq_s32
#define __builtin_mve_vmlsdavaxq_s8 __builtin_arm_mve_vmlsdavaxq_s8
#define __builtin_mve_vmlsdavq_p_s16 __builtin_arm_mve_vmlsdavq_p_s16
#define __builtin_mve_vmlsdavq_p_s32 __builtin_arm_mve_vmlsdavq_p_s32
#define __builtin_mve_vmlsdavq_p_s8 __builtin_arm_mve_vmlsdavq_p_s8
#define __builtin_mve_vmlsdavq_s16 __builtin_arm_mve_vmlsdavq_s16
#define __builtin_mve_vmlsdavq_s32 __builtin_arm_mve_vmlsdavq_s32
#define __builtin_mve_vmlsdavq_s8 __builtin_arm_mve_vmlsdavq_s8
#define __builtin_mve_vmlsdavxq_p_s16 __builtin_arm_mve_vmlsdavxq_p_s16
#define __builtin_mve_vmlsdavxq_p_s32 __builtin_arm_mve_vmlsdavxq_p_s32
#define __builtin_mve_vmlsdavxq_p_s8 __builtin_arm_mve_vmlsdavxq_p_s8
#define __builtin_mve_vmlsdavxq_s16 __builtin_arm_mve_vmlsdavxq_s16
#define __builtin_mve_vmlsdavxq_s32 __builtin_arm_mve_vmlsdavxq_s32
#define __builtin_mve_vmlsdavxq_s8 __builtin_arm_mve_vmlsdavxq_s8
#define __builtin_mve_vmlsldavaq_p_s16 __builtin_arm_mve_vmlsldavaq_p_s16
#define __builtin_mve_vmlsldavaq_p_s32 __builtin_arm_mve_vmlsldavaq_p_s32
#define __builtin_mve_vmlsldavaq_s16 __builtin_arm_mve_vmlsldavaq_s16
#define __builtin_mve_vmlsldavaq_s32 __builtin_arm_mve_vmlsldavaq_s32
#define __builtin_mve_vmlsldavaxq_p_s16 __builtin_arm_mve_vmlsldavaxq_p_s16
#define __builtin_mve_vmlsldavaxq_p_s32 __builtin_arm_mve_vmlsldavaxq_p_s32
#define __builtin_mve_vmlsldavaxq_s16 __builtin_arm_mve_vmlsldavaxq_s16
#define __builtin_mve_vmlsldavaxq_s32 __builtin_arm_mve_vmlsldavaxq_s32
#define __builtin_mve_vmlsldavq_p_s16 __builtin_arm_mve_vmlsldavq_p_s16
#define __builtin_mve_vmlsldavq_p_s32 __builtin_arm_mve_vmlsldavq_p_s32
#define __builtin_mve_vmlsldavq_s16 __builtin_arm_mve_vmlsldavq_s16
#define __builtin_mve_vmlsldavq_s32 __builtin_arm_mve_vmlsldavq_s32
#define __builtin_mve_vmlsldavxq_p_s16 __builtin_arm_mve_vmlsldavxq_p_s16
#define __builtin_mve_vmlsldavxq_p_s32 __builtin_arm_mve_vmlsldavxq_p_s32
#define __builtin_mve_vmlsldavxq_s16 __builtin_arm_mve_vmlsldavxq_s16
#define __builtin_mve_vmlsldavxq_s32 __builtin_arm_mve_vmlsldavxq_s32
#define __builtin_mve_vmovlbq_m_s16 __builtin_arm_mve_vmovlbq_m_s16
#define __builtin_mve_vmovlbq_m_s8 __builtin_arm_mve_vmovlbq_m_s8
#define __builtin_mve_vmovlbq_m_u16 __builtin_arm_mve_vmovlbq_m_u16
#define __builtin_mve_vmovlbq_m_u8 __builtin_arm_mve_vmovlbq_m_u8
#define __builtin_mve_vmovlbq_s16 __builtin_arm_mve_vmovlbq_s16
#define __builtin_mve_vmovlbq_s8 __builtin_arm_mve_vmovlbq_s8
#define __builtin_mve_vmovlbq_u16 __builtin_arm_mve_vmovlbq_u16
#define __builtin_mve_vmovlbq_u8 __builtin_arm_mve_vmovlbq_u8
#define __builtin_mve_vmovltq_m_s16 __builtin_arm_mve_vmovltq_m_s16
#define __builtin_mve_vmovltq_m_s8 __builtin_arm_mve_vmovltq_m_s8
#define __builtin_mve_vmovltq_m_u16 __builtin_arm_mve_vmovltq_m_u16
#define __builtin_mve_vmovltq_m_u8 __builtin_arm_mve_vmovltq_m_u8
#define __builtin_mve_vmovltq_s16 __builtin_arm_mve_vmovltq_s16
#define __builtin_mve_vmovltq_s8 __builtin_arm_mve_vmovltq_s8
#define __builtin_mve_vmovltq_u16 __builtin_arm_mve_vmovltq_u16
#define __builtin_mve_vmovltq_u8 __builtin_arm_mve_vmovltq_u8
#define __builtin_mve_vmovnbq_m_s16 __builtin_arm_mve_vmovnbq_m_s16
#define __builtin_mve_vmovnbq_m_s32 __builtin_arm_mve_vmovnbq_m_s32
#define __builtin_mve_vmovnbq_m_u16 __builtin_arm_mve_vmovnbq_m_u16
#define __builtin_mve_vmovnbq_m_u32 __builtin_arm_mve_vmovnbq_m_u32
#define __builtin_mve_vmovnbq_s16 __builtin_arm_mve_vmovnbq_s16
#define __builtin_mve_vmovnbq_s32 __builtin_arm_mve_vmovnbq_s32
#define __builtin_mve_vmovnbq_u16 __builtin_arm_mve_vmovnbq_u16
#define __builtin_mve_vmovnbq_u32 __builtin_arm_mve_vmovnbq_u32
#define __builtin_mve_vmovntq_m_s16 __builtin_arm_mve_vmovntq_m_s16
#define __builtin_mve_vmovntq_m_s32 __builtin_arm_mve_vmovntq_m_s32
#define __builtin_mve_vmovntq_m_u16 __builtin_arm_mve_vmovntq_m_u16
#define __builtin_mve_vmovntq_m_u32 __builtin_arm_mve_vmovntq_m_u32
#define __builtin_mve_vmovntq_s16 __builtin_arm_mve_vmovntq_s16
#define __builtin_mve_vmovntq_s32 __builtin_arm_mve_vmovntq_s32
#define __builtin_mve_vmovntq_u16 __builtin_arm_mve_vmovntq_u16
#define __builtin_mve_vmovntq_u32 __builtin_arm_mve_vmovntq_u32
#define __builtin_mve_vmulhq_m_s16 __builtin_arm_mve_vmulhq_m_s16
#define __builtin_mve_vmulhq_m_s32 __builtin_arm_mve_vmulhq_m_s32
#define __builtin_mve_vmulhq_m_s8 __builtin_arm_mve_vmulhq_m_s8
#define __builtin_mve_vmulhq_m_u16 __builtin_arm_mve_vmulhq_m_u16
#define __builtin_mve_vmulhq_m_u32 __builtin_arm_mve_vmulhq_m_u32
#define __builtin_mve_vmulhq_m_u8 __builtin_arm_mve_vmulhq_m_u8
#define __builtin_mve_vmulhq_s16 __builtin_arm_mve_vmulhq_s16
#define __builtin_mve_vmulhq_s32 __builtin_arm_mve_vmulhq_s32
#define __builtin_mve_vmulhq_s8 __builtin_arm_mve_vmulhq_s8
#define __builtin_mve_vmulhq_u16 __builtin_arm_mve_vmulhq_u16
#define __builtin_mve_vmulhq_u32 __builtin_arm_mve_vmulhq_u32
#define __builtin_mve_vmulhq_u8 __builtin_arm_mve_vmulhq_u8
#define __builtin_mve_vmullbq_int_m_s16 __builtin_arm_mve_vmullbq_int_m_s16
#define __builtin_mve_vmullbq_int_m_s32 __builtin_arm_mve_vmullbq_int_m_s32
#define __builtin_mve_vmullbq_int_m_s8 __builtin_arm_mve_vmullbq_int_m_s8
#define __builtin_mve_vmullbq_int_m_u16 __builtin_arm_mve_vmullbq_int_m_u16
#define __builtin_mve_vmullbq_int_m_u32 __builtin_arm_mve_vmullbq_int_m_u32
#define __builtin_mve_vmullbq_int_m_u8 __builtin_arm_mve_vmullbq_int_m_u8
#define __builtin_mve_vmullbq_int_s16 __builtin_arm_mve_vmullbq_int_s16
#define __builtin_mve_vmullbq_int_s32 __builtin_arm_mve_vmullbq_int_s32
#define __builtin_mve_vmullbq_int_s8 __builtin_arm_mve_vmullbq_int_s8
#define __builtin_mve_vmullbq_int_u16 __builtin_arm_mve_vmullbq_int_u16
#define __builtin_mve_vmullbq_int_u32 __builtin_arm_mve_vmullbq_int_u32
#define __builtin_mve_vmullbq_int_u8 __builtin_arm_mve_vmullbq_int_u8
#define __builtin_mve_vmullbq_poly_m_p16 __builtin_arm_mve_vmullbq_poly_m_p16
#define __builtin_mve_vmullbq_poly_m_p8 __builtin_arm_mve_vmullbq_poly_m_p8
#define __builtin_mve_vmullbq_poly_p16 __builtin_arm_mve_vmullbq_poly_p16
#define __builtin_mve_vmullbq_poly_p8 __builtin_arm_mve_vmullbq_poly_p8
#define __builtin_mve_vmulltq_int_m_s16 __builtin_arm_mve_vmulltq_int_m_s16
#define __builtin_mve_vmulltq_int_m_s32 __builtin_arm_mve_vmulltq_int_m_s32
#define __builtin_mve_vmulltq_int_m_s8 __builtin_arm_mve_vmulltq_int_m_s8
#define __builtin_mve_vmulltq_int_m_u16 __builtin_arm_mve_vmulltq_int_m_u16
#define __builtin_mve_vmulltq_int_m_u32 __builtin_arm_mve_vmulltq_int_m_u32
#define __builtin_mve_vmulltq_int_m_u8 __builtin_arm_mve_vmulltq_int_m_u8
#define __builtin_mve_vmulltq_int_s16 __builtin_arm_mve_vmulltq_int_s16
#define __builtin_mve_vmulltq_int_s32 __builtin_arm_mve_vmulltq_int_s32
#define __builtin_mve_vmulltq_int_s8 __builtin_arm_mve_vmulltq_int_s8
#define __builtin_mve_vmulltq_int_u16 __builtin_arm_mve_vmulltq_int_u16
#define __builtin_mve_vmulltq_int_u32 __builtin_arm_mve_vmulltq_int_u32
#define __builtin_mve_vmulltq_int_u8 __builtin_arm_mve_vmulltq_int_u8
#define __builtin_mve_vmulltq_poly_m_p16 __builtin_arm_mve_vmulltq_poly_m_p16
#define __builtin_mve_vmulltq_poly_m_p8 __builtin_arm_mve_vmulltq_poly_m_p8
#define __builtin_mve_vmulltq_poly_p16 __builtin_arm_mve_vmulltq_poly_p16
#define __builtin_mve_vmulltq_poly_p8 __builtin_arm_mve_vmulltq_poly_p8
#define __builtin_mve_vmulq_f16 __builtin_arm_mve_vmulq_f16
#define __builtin_mve_vmulq_f32 __builtin_arm_mve_vmulq_f32
#define __builtin_mve_vmulq_m_f16 __builtin_arm_mve_vmulq_m_f16
#define __builtin_mve_vmulq_m_f32 __builtin_arm_mve_vmulq_m_f32
#define __builtin_mve_vmulq_m_n_f16 __builtin_arm_mve_vmulq_m_n_f16
#define __builtin_mve_vmulq_m_n_f32 __builtin_arm_mve_vmulq_m_n_f32
#define __builtin_mve_vmulq_m_n_s16 __builtin_arm_mve_vmulq_m_n_s16
#define __builtin_mve_vmulq_m_n_s32 __builtin_arm_mve_vmulq_m_n_s32
#define __builtin_mve_vmulq_m_n_s8 __builtin_arm_mve_vmulq_m_n_s8
#define __builtin_mve_vmulq_m_n_u16 __builtin_arm_mve_vmulq_m_n_u16
#define __builtin_mve_vmulq_m_n_u32 __builtin_arm_mve_vmulq_m_n_u32
#define __builtin_mve_vmulq_m_n_u8 __builtin_arm_mve_vmulq_m_n_u8
#define __builtin_mve_vmulq_m_s16 __builtin_arm_mve_vmulq_m_s16
#define __builtin_mve_vmulq_m_s32 __builtin_arm_mve_vmulq_m_s32
#define __builtin_mve_vmulq_m_s8 __builtin_arm_mve_vmulq_m_s8
#define __builtin_mve_vmulq_m_u16 __builtin_arm_mve_vmulq_m_u16
#define __builtin_mve_vmulq_m_u32 __builtin_arm_mve_vmulq_m_u32
#define __builtin_mve_vmulq_m_u8 __builtin_arm_mve_vmulq_m_u8
#define __builtin_mve_vmulq_n_f16 __builtin_arm_mve_vmulq_n_f16
#define __builtin_mve_vmulq_n_f32 __builtin_arm_mve_vmulq_n_f32
#define __builtin_mve_vmulq_n_s16 __builtin_arm_mve_vmulq_n_s16
#define __builtin_mve_vmulq_n_s32 __builtin_arm_mve_vmulq_n_s32
#define __builtin_mve_vmulq_n_s8 __builtin_arm_mve_vmulq_n_s8
#define __builtin_mve_vmulq_n_u16 __builtin_arm_mve_vmulq_n_u16
#define __builtin_mve_vmulq_n_u32 __builtin_arm_mve_vmulq_n_u32
#define __builtin_mve_vmulq_n_u8 __builtin_arm_mve_vmulq_n_u8
#define __builtin_mve_vmulq_s16 __builtin_arm_mve_vmulq_s16
#define __builtin_mve_vmulq_s32 __builtin_arm_mve_vmulq_s32
#define __builtin_mve_vmulq_s8 __builtin_arm_mve_vmulq_s8
#define __builtin_mve_vmulq_u16 __builtin_arm_mve_vmulq_u16
#define __builtin_mve_vmulq_u32 __builtin_arm_mve_vmulq_u32
#define __builtin_mve_vmulq_u8 __builtin_arm_mve_vmulq_u8
#define __builtin_mve_vmvnq_m_s16 __builtin_arm_mve_vmvnq_m_s16
#define __builtin_mve_vmvnq_m_s32 __builtin_arm_mve_vmvnq_m_s32
#define __builtin_mve_vmvnq_m_s8 __builtin_arm_mve_vmvnq_m_s8
#define __builtin_mve_vmvnq_m_u16 __builtin_arm_mve_vmvnq_m_u16
#define __builtin_mve_vmvnq_m_u32 __builtin_arm_mve_vmvnq_m_u32
#define __builtin_mve_vmvnq_m_u8 __builtin_arm_mve_vmvnq_m_u8
#define __builtin_mve_vmvnq_s16 __builtin_arm_mve_vmvnq_s16
#define __builtin_mve_vmvnq_s32 __builtin_arm_mve_vmvnq_s32
#define __builtin_mve_vmvnq_s8 __builtin_arm_mve_vmvnq_s8
#define __builtin_mve_vmvnq_u16 __builtin_arm_mve_vmvnq_u16
#define __builtin_mve_vmvnq_u32 __builtin_arm_mve_vmvnq_u32
#define __builtin_mve_vmvnq_u8 __builtin_arm_mve_vmvnq_u8
#define __builtin_mve_vnegq_f16 __builtin_arm_mve_vnegq_f16
#define __builtin_mve_vnegq_f32 __builtin_arm_mve_vnegq_f32
#define __builtin_mve_vnegq_m_f16 __builtin_arm_mve_vnegq_m_f16
#define __builtin_mve_vnegq_m_f32 __builtin_arm_mve_vnegq_m_f32
#define __builtin_mve_vnegq_m_s16 __builtin_arm_mve_vnegq_m_s16
#define __builtin_mve_vnegq_m_s32 __builtin_arm_mve_vnegq_m_s32
#define __builtin_mve_vnegq_m_s8 __builtin_arm_mve_vnegq_m_s8
#define __builtin_mve_vnegq_s16 __builtin_arm_mve_vnegq_s16
#define __builtin_mve_vnegq_s32 __builtin_arm_mve_vnegq_s32
#define __builtin_mve_vnegq_s8 __builtin_arm_mve_vnegq_s8
#define __builtin_mve_vornq_f16 __builtin_arm_mve_vornq_f16
#define __builtin_mve_vornq_f32 __builtin_arm_mve_vornq_f32
#define __builtin_mve_vornq_m_f16 __builtin_arm_mve_vornq_m_f16
#define __builtin_mve_vornq_m_f32 __builtin_arm_mve_vornq_m_f32
#define __builtin_mve_vornq_m_s16 __builtin_arm_mve_vornq_m_s16
#define __builtin_mve_vornq_m_s32 __builtin_arm_mve_vornq_m_s32
#define __builtin_mve_vornq_m_s8 __builtin_arm_mve_vornq_m_s8
#define __builtin_mve_vornq_m_u16 __builtin_arm_mve_vornq_m_u16
#define __builtin_mve_vornq_m_u32 __builtin_arm_mve_vornq_m_u32
#define __builtin_mve_vornq_m_u8 __builtin_arm_mve_vornq_m_u8
#define __builtin_mve_vornq_s16 __builtin_arm_mve_vornq_s16
#define __builtin_mve_vornq_s32 __builtin_arm_mve_vornq_s32
#define __builtin_mve_vornq_s8 __builtin_arm_mve_vornq_s8
#define __builtin_mve_vornq_u16 __builtin_arm_mve_vornq_u16
#define __builtin_mve_vornq_u32 __builtin_arm_mve_vornq_u32
#define __builtin_mve_vornq_u8 __builtin_arm_mve_vornq_u8
#define __builtin_mve_vorrq_f16 __builtin_arm_mve_vorrq_f16
#define __builtin_mve_vorrq_f32 __builtin_arm_mve_vorrq_f32
#define __builtin_mve_vorrq_m_f16 __builtin_arm_mve_vorrq_m_f16
#define __builtin_mve_vorrq_m_f32 __builtin_arm_mve_vorrq_m_f32
#define __builtin_mve_vorrq_m_s16 __builtin_arm_mve_vorrq_m_s16
#define __builtin_mve_vorrq_m_s32 __builtin_arm_mve_vorrq_m_s32
#define __builtin_mve_vorrq_m_s8 __builtin_arm_mve_vorrq_m_s8
#define __builtin_mve_vorrq_m_u16 __builtin_arm_mve_vorrq_m_u16
#define __builtin_mve_vorrq_m_u32 __builtin_arm_mve_vorrq_m_u32
#define __builtin_mve_vorrq_m_u8 __builtin_arm_mve_vorrq_m_u8
#define __builtin_mve_vorrq_s16 __builtin_arm_mve_vorrq_s16
#define __builtin_mve_vorrq_s32 __builtin_arm_mve_vorrq_s32
#define __builtin_mve_vorrq_s8 __builtin_arm_mve_vorrq_s8
#define __builtin_mve_vorrq_u16 __builtin_arm_mve_vorrq_u16
#define __builtin_mve_vorrq_u32 __builtin_arm_mve_vorrq_u32
#define __builtin_mve_vorrq_u8 __builtin_arm_mve_vorrq_u8
#define __builtin_mve_vpnot __builtin_arm_mve_vpnot
#define __builtin_mve_vpselq_f16 __builtin_arm_mve_vpselq_f16
#define __builtin_mve_vpselq_f32 __builtin_arm_mve_vpselq_f32
#define __builtin_mve_vpselq_s16 __builtin_arm_mve_vpselq_s16
#define __builtin_mve_vpselq_s32 __builtin_arm_mve_vpselq_s32
#define __builtin_mve_vpselq_s64 __builtin_arm_mve_vpselq_s64
#define __builtin_mve_vpselq_s8 __builtin_arm_mve_vpselq_s8
#define __builtin_mve_vpselq_u16 __builtin_arm_mve_vpselq_u16
#define __builtin_mve_vpselq_u32 __builtin_arm_mve_vpselq_u32
#define __builtin_mve_vpselq_u64 __builtin_arm_mve_vpselq_u64
#define __builtin_mve_vpselq_u8 __builtin_arm_mve_vpselq_u8
#define __builtin_mve_vqabsq_m_s16 __builtin_arm_mve_vqabsq_m_s16
#define __builtin_mve_vqabsq_m_s32 __builtin_arm_mve_vqabsq_m_s32
#define __builtin_mve_vqabsq_m_s8 __builtin_arm_mve_vqabsq_m_s8
#define __builtin_mve_vqabsq_s16 __builtin_arm_mve_vqabsq_s16
#define __builtin_mve_vqabsq_s32 __builtin_arm_mve_vqabsq_s32
#define __builtin_mve_vqabsq_s8 __builtin_arm_mve_vqabsq_s8
#define __builtin_mve_vqaddq_m_n_s16 __builtin_arm_mve_vqaddq_m_n_s16
#define __builtin_mve_vqaddq_m_n_s32 __builtin_arm_mve_vqaddq_m_n_s32
#define __builtin_mve_vqaddq_m_n_s8 __builtin_arm_mve_vqaddq_m_n_s8
#define __builtin_mve_vqaddq_m_n_u16 __builtin_arm_mve_vqaddq_m_n_u16
#define __builtin_mve_vqaddq_m_n_u32 __builtin_arm_mve_vqaddq_m_n_u32
#define __builtin_mve_vqaddq_m_n_u8 __builtin_arm_mve_vqaddq_m_n_u8
#define __builtin_mve_vqaddq_m_s16 __builtin_arm_mve_vqaddq_m_s16
#define __builtin_mve_vqaddq_m_s32 __builtin_arm_mve_vqaddq_m_s32
#define __builtin_mve_vqaddq_m_s8 __builtin_arm_mve_vqaddq_m_s8
#define __builtin_mve_vqaddq_m_u16 __builtin_arm_mve_vqaddq_m_u16
#define __builtin_mve_vqaddq_m_u32 __builtin_arm_mve_vqaddq_m_u32
#define __builtin_mve_vqaddq_m_u8 __builtin_arm_mve_vqaddq_m_u8
#define __builtin_mve_vqaddq_n_s16 __builtin_arm_mve_vqaddq_n_s16
#define __builtin_mve_vqaddq_n_s32 __builtin_arm_mve_vqaddq_n_s32
#define __builtin_mve_vqaddq_n_s8 __builtin_arm_mve_vqaddq_n_s8
#define __builtin_mve_vqaddq_n_u16 __builtin_arm_mve_vqaddq_n_u16
#define __builtin_mve_vqaddq_n_u32 __builtin_arm_mve_vqaddq_n_u32
#define __builtin_mve_vqaddq_n_u8 __builtin_arm_mve_vqaddq_n_u8
#define __builtin_mve_vqaddq_s16 __builtin_arm_mve_vqaddq_s16
#define __builtin_mve_vqaddq_s32 __builtin_arm_mve_vqaddq_s32
#define __builtin_mve_vqaddq_s8 __builtin_arm_mve_vqaddq_s8
#define __builtin_mve_vqaddq_u16 __builtin_arm_mve_vqaddq_u16
#define __builtin_mve_vqaddq_u32 __builtin_arm_mve_vqaddq_u32
#define __builtin_mve_vqaddq_u8 __builtin_arm_mve_vqaddq_u8
#define __builtin_mve_vqdmladhq_m_s16 __builtin_arm_mve_vqdmladhq_m_s16
#define __builtin_mve_vqdmladhq_m_s32 __builtin_arm_mve_vqdmladhq_m_s32
#define __builtin_mve_vqdmladhq_m_s8 __builtin_arm_mve_vqdmladhq_m_s8
#define __builtin_mve_vqdmladhq_s16 __builtin_arm_mve_vqdmladhq_s16
#define __builtin_mve_vqdmladhq_s32 __builtin_arm_mve_vqdmladhq_s32
#define __builtin_mve_vqdmladhq_s8 __builtin_arm_mve_vqdmladhq_s8
#define __builtin_mve_vqdmladhxq_m_s16 __builtin_arm_mve_vqdmladhxq_m_s16
#define __builtin_mve_vqdmladhxq_m_s32 __builtin_arm_mve_vqdmladhxq_m_s32
#define __builtin_mve_vqdmladhxq_m_s8 __builtin_arm_mve_vqdmladhxq_m_s8
#define __builtin_mve_vqdmladhxq_s16 __builtin_arm_mve_vqdmladhxq_s16
#define __builtin_mve_vqdmladhxq_s32 __builtin_arm_mve_vqdmladhxq_s32
#define __builtin_mve_vqdmladhxq_s8 __builtin_arm_mve_vqdmladhxq_s8
#define __builtin_mve_vqdmlahq_m_n_s16 __builtin_arm_mve_vqdmlahq_m_n_s16
#define __builtin_mve_vqdmlahq_m_n_s32 __builtin_arm_mve_vqdmlahq_m_n_s32
#define __builtin_mve_vqdmlahq_m_n_s8 __builtin_arm_mve_vqdmlahq_m_n_s8
#define __builtin_mve_vqdmlahq_n_s16 __builtin_arm_mve_vqdmlahq_n_s16
#define __builtin_mve_vqdmlahq_n_s32 __builtin_arm_mve_vqdmlahq_n_s32
#define __builtin_mve_vqdmlahq_n_s8 __builtin_arm_mve_vqdmlahq_n_s8
#define __builtin_mve_vqdmlsdhq_m_s16 __builtin_arm_mve_vqdmlsdhq_m_s16
#define __builtin_mve_vqdmlsdhq_m_s32 __builtin_arm_mve_vqdmlsdhq_m_s32
#define __builtin_mve_vqdmlsdhq_m_s8 __builtin_arm_mve_vqdmlsdhq_m_s8
#define __builtin_mve_vqdmlsdhq_s16 __builtin_arm_mve_vqdmlsdhq_s16
#define __builtin_mve_vqdmlsdhq_s32 __builtin_arm_mve_vqdmlsdhq_s32
#define __builtin_mve_vqdmlsdhq_s8 __builtin_arm_mve_vqdmlsdhq_s8
#define __builtin_mve_vqdmlsdhxq_m_s16 __builtin_arm_mve_vqdmlsdhxq_m_s16
#define __builtin_mve_vqdmlsdhxq_m_s32 __builtin_arm_mve_vqdmlsdhxq_m_s32
#define __builtin_mve_vqdmlsdhxq_m_s8 __builtin_arm_mve_vqdmlsdhxq_m_s8
#define __builtin_mve_vqdmlsdhxq_s16 __builtin_arm_mve_vqdmlsdhxq_s16
#define __builtin_mve_vqdmlsdhxq_s32 __builtin_arm_mve_vqdmlsdhxq_s32
#define __builtin_mve_vqdmlsdhxq_s8 __builtin_arm_mve_vqdmlsdhxq_s8
#define __builtin_mve_vqdmulhq_m_n_s16 __builtin_arm_mve_vqdmulhq_m_n_s16
#define __builtin_mve_vqdmulhq_m_n_s32 __builtin_arm_mve_vqdmulhq_m_n_s32
#define __builtin_mve_vqdmulhq_m_n_s8 __builtin_arm_mve_vqdmulhq_m_n_s8
#define __builtin_mve_vqdmulhq_m_s16 __builtin_arm_mve_vqdmulhq_m_s16
#define __builtin_mve_vqdmulhq_m_s32 __builtin_arm_mve_vqdmulhq_m_s32
#define __builtin_mve_vqdmulhq_m_s8 __builtin_arm_mve_vqdmulhq_m_s8
#define __builtin_mve_vqdmulhq_n_s16 __builtin_arm_mve_vqdmulhq_n_s16
#define __builtin_mve_vqdmulhq_n_s32 __builtin_arm_mve_vqdmulhq_n_s32
#define __builtin_mve_vqdmulhq_n_s8 __builtin_arm_mve_vqdmulhq_n_s8
#define __builtin_mve_vqdmulhq_s16 __builtin_arm_mve_vqdmulhq_s16
#define __builtin_mve_vqdmulhq_s32 __builtin_arm_mve_vqdmulhq_s32
#define __builtin_mve_vqdmulhq_s8 __builtin_arm_mve_vqdmulhq_s8
#define __builtin_mve_vqdmullbq_m_n_s16 __builtin_arm_mve_vqdmullbq_m_n_s16
#define __builtin_mve_vqdmullbq_m_n_s32 __builtin_arm_mve_vqdmullbq_m_n_s32
#define __builtin_mve_vqdmullbq_m_s16 __builtin_arm_mve_vqdmullbq_m_s16
#define __builtin_mve_vqdmullbq_m_s32 __builtin_arm_mve_vqdmullbq_m_s32
#define __builtin_mve_vqdmullbq_n_s16 __builtin_arm_mve_vqdmullbq_n_s16
#define __builtin_mve_vqdmullbq_n_s32 __builtin_arm_mve_vqdmullbq_n_s32
#define __builtin_mve_vqdmullbq_s16 __builtin_arm_mve_vqdmullbq_s16
#define __builtin_mve_vqdmullbq_s32 __builtin_arm_mve_vqdmullbq_s32
#define __builtin_mve_vqdmulltq_m_n_s16 __builtin_arm_mve_vqdmulltq_m_n_s16
#define __builtin_mve_vqdmulltq_m_n_s32 __builtin_arm_mve_vqdmulltq_m_n_s32
#define __builtin_mve_vqdmulltq_m_s16 __builtin_arm_mve_vqdmulltq_m_s16
#define __builtin_mve_vqdmulltq_m_s32 __builtin_arm_mve_vqdmulltq_m_s32
#define __builtin_mve_vqdmulltq_n_s16 __builtin_arm_mve_vqdmulltq_n_s16
#define __builtin_mve_vqdmulltq_n_s32 __builtin_arm_mve_vqdmulltq_n_s32
#define __builtin_mve_vqdmulltq_s16 __builtin_arm_mve_vqdmulltq_s16
#define __builtin_mve_vqdmulltq_s32 __builtin_arm_mve_vqdmulltq_s32
#define __builtin_mve_vqmovnbq_m_s16 __builtin_arm_mve_vqmovnbq_m_s16
#define __builtin_mve_vqmovnbq_m_s32 __builtin_arm_mve_vqmovnbq_m_s32
#define __builtin_mve_vqmovnbq_m_u16 __builtin_arm_mve_vqmovnbq_m_u16
#define __builtin_mve_vqmovnbq_m_u32 __builtin_arm_mve_vqmovnbq_m_u32
#define __builtin_mve_vqmovnbq_s16 __builtin_arm_mve_vqmovnbq_s16
#define __builtin_mve_vqmovnbq_s32 __builtin_arm_mve_vqmovnbq_s32
#define __builtin_mve_vqmovnbq_u16 __builtin_arm_mve_vqmovnbq_u16
#define __builtin_mve_vqmovnbq_u32 __builtin_arm_mve_vqmovnbq_u32
#define __builtin_mve_vqmovntq_m_s16 __builtin_arm_mve_vqmovntq_m_s16
#define __builtin_mve_vqmovntq_m_s32 __builtin_arm_mve_vqmovntq_m_s32
#define __builtin_mve_vqmovntq_m_u16 __builtin_arm_mve_vqmovntq_m_u16
#define __builtin_mve_vqmovntq_m_u32 __builtin_arm_mve_vqmovntq_m_u32
#define __builtin_mve_vqmovntq_s16 __builtin_arm_mve_vqmovntq_s16
#define __builtin_mve_vqmovntq_s32 __builtin_arm_mve_vqmovntq_s32
#define __builtin_mve_vqmovntq_u16 __builtin_arm_mve_vqmovntq_u16
#define __builtin_mve_vqmovntq_u32 __builtin_arm_mve_vqmovntq_u32
#define __builtin_mve_vqmovunbq_m_s16 __builtin_arm_mve_vqmovunbq_m_s16
#define __builtin_mve_vqmovunbq_m_s32 __builtin_arm_mve_vqmovunbq_m_s32
#define __builtin_mve_vqmovunbq_s16 __builtin_arm_mve_vqmovunbq_s16
#define __builtin_mve_vqmovunbq_s32 __builtin_arm_mve_vqmovunbq_s32
#define __builtin_mve_vqmovuntq_m_s16 __builtin_arm_mve_vqmovuntq_m_s16
#define __builtin_mve_vqmovuntq_m_s32 __builtin_arm_mve_vqmovuntq_m_s32
#define __builtin_mve_vqmovuntq_s16 __builtin_arm_mve_vqmovuntq_s16
#define __builtin_mve_vqmovuntq_s32 __builtin_arm_mve_vqmovuntq_s32
#define __builtin_mve_vqnegq_m_s16 __builtin_arm_mve_vqnegq_m_s16
#define __builtin_mve_vqnegq_m_s32 __builtin_arm_mve_vqnegq_m_s32
#define __builtin_mve_vqnegq_m_s8 __builtin_arm_mve_vqnegq_m_s8
#define __builtin_mve_vqnegq_s16 __builtin_arm_mve_vqnegq_s16
#define __builtin_mve_vqnegq_s32 __builtin_arm_mve_vqnegq_s32
#define __builtin_mve_vqnegq_s8 __builtin_arm_mve_vqnegq_s8
#define __builtin_mve_vqrdmladhq_m_s16 __builtin_arm_mve_vqrdmladhq_m_s16
#define __builtin_mve_vqrdmladhq_m_s32 __builtin_arm_mve_vqrdmladhq_m_s32
#define __builtin_mve_vqrdmladhq_m_s8 __builtin_arm_mve_vqrdmladhq_m_s8
#define __builtin_mve_vqrdmladhq_s16 __builtin_arm_mve_vqrdmladhq_s16
#define __builtin_mve_vqrdmladhq_s32 __builtin_arm_mve_vqrdmladhq_s32
#define __builtin_mve_vqrdmladhq_s8 __builtin_arm_mve_vqrdmladhq_s8
#define __builtin_mve_vqrdmladhxq_m_s16 __builtin_arm_mve_vqrdmladhxq_m_s16
#define __builtin_mve_vqrdmladhxq_m_s32 __builtin_arm_mve_vqrdmladhxq_m_s32
#define __builtin_mve_vqrdmladhxq_m_s8 __builtin_arm_mve_vqrdmladhxq_m_s8
#define __builtin_mve_vqrdmladhxq_s16 __builtin_arm_mve_vqrdmladhxq_s16
#define __builtin_mve_vqrdmladhxq_s32 __builtin_arm_mve_vqrdmladhxq_s32
#define __builtin_mve_vqrdmladhxq_s8 __builtin_arm_mve_vqrdmladhxq_s8
#define __builtin_mve_vqrdmlahq_m_n_s16 __builtin_arm_mve_vqrdmlahq_m_n_s16
#define __builtin_mve_vqrdmlahq_m_n_s32 __builtin_arm_mve_vqrdmlahq_m_n_s32
#define __builtin_mve_vqrdmlahq_m_n_s8 __builtin_arm_mve_vqrdmlahq_m_n_s8
#define __builtin_mve_vqrdmlahq_n_s16 __builtin_arm_mve_vqrdmlahq_n_s16
#define __builtin_mve_vqrdmlahq_n_s32 __builtin_arm_mve_vqrdmlahq_n_s32
#define __builtin_mve_vqrdmlahq_n_s8 __builtin_arm_mve_vqrdmlahq_n_s8
#define __builtin_mve_vqrdmlashq_m_n_s16 __builtin_arm_mve_vqrdmlashq_m_n_s16
#define __builtin_mve_vqrdmlashq_m_n_s32 __builtin_arm_mve_vqrdmlashq_m_n_s32
#define __builtin_mve_vqrdmlashq_m_n_s8 __builtin_arm_mve_vqrdmlashq_m_n_s8
#define __builtin_mve_vqrdmlashq_n_s16 __builtin_arm_mve_vqrdmlashq_n_s16
#define __builtin_mve_vqrdmlashq_n_s32 __builtin_arm_mve_vqrdmlashq_n_s32
#define __builtin_mve_vqrdmlashq_n_s8 __builtin_arm_mve_vqrdmlashq_n_s8
#define __builtin_mve_vqrdmlsdhq_m_s16 __builtin_arm_mve_vqrdmlsdhq_m_s16
#define __builtin_mve_vqrdmlsdhq_m_s32 __builtin_arm_mve_vqrdmlsdhq_m_s32
#define __builtin_mve_vqrdmlsdhq_m_s8 __builtin_arm_mve_vqrdmlsdhq_m_s8
#define __builtin_mve_vqrdmlsdhq_s16 __builtin_arm_mve_vqrdmlsdhq_s16
#define __builtin_mve_vqrdmlsdhq_s32 __builtin_arm_mve_vqrdmlsdhq_s32
#define __builtin_mve_vqrdmlsdhq_s8 __builtin_arm_mve_vqrdmlsdhq_s8
#define __builtin_mve_vqrdmlsdhxq_m_s16 __builtin_arm_mve_vqrdmlsdhxq_m_s16
#define __builtin_mve_vqrdmlsdhxq_m_s32 __builtin_arm_mve_vqrdmlsdhxq_m_s32
#define __builtin_mve_vqrdmlsdhxq_m_s8 __builtin_arm_mve_vqrdmlsdhxq_m_s8
#define __builtin_mve_vqrdmlsdhxq_s16 __builtin_arm_mve_vqrdmlsdhxq_s16
#define __builtin_mve_vqrdmlsdhxq_s32 __builtin_arm_mve_vqrdmlsdhxq_s32
#define __builtin_mve_vqrdmlsdhxq_s8 __builtin_arm_mve_vqrdmlsdhxq_s8
#define __builtin_mve_vqrdmulhq_m_n_s16 __builtin_arm_mve_vqrdmulhq_m_n_s16
#define __builtin_mve_vqrdmulhq_m_n_s32 __builtin_arm_mve_vqrdmulhq_m_n_s32
#define __builtin_mve_vqrdmulhq_m_n_s8 __builtin_arm_mve_vqrdmulhq_m_n_s8
#define __builtin_mve_vqrdmulhq_m_s16 __builtin_arm_mve_vqrdmulhq_m_s16
#define __builtin_mve_vqrdmulhq_m_s32 __builtin_arm_mve_vqrdmulhq_m_s32
#define __builtin_mve_vqrdmulhq_m_s8 __builtin_arm_mve_vqrdmulhq_m_s8
#define __builtin_mve_vqrdmulhq_n_s16 __builtin_arm_mve_vqrdmulhq_n_s16
#define __builtin_mve_vqrdmulhq_n_s32 __builtin_arm_mve_vqrdmulhq_n_s32
#define __builtin_mve_vqrdmulhq_n_s8 __builtin_arm_mve_vqrdmulhq_n_s8
#define __builtin_mve_vqrdmulhq_s16 __builtin_arm_mve_vqrdmulhq_s16
#define __builtin_mve_vqrdmulhq_s32 __builtin_arm_mve_vqrdmulhq_s32
#define __builtin_mve_vqrdmulhq_s8 __builtin_arm_mve_vqrdmulhq_s8
#define __builtin_mve_vqrshlq_m_n_s16 __builtin_arm_mve_vqrshlq_m_n_s16
#define __builtin_mve_vqrshlq_m_n_s32 __builtin_arm_mve_vqrshlq_m_n_s32
#define __builtin_mve_vqrshlq_m_n_s8 __builtin_arm_mve_vqrshlq_m_n_s8
#define __builtin_mve_vqrshlq_m_n_u16 __builtin_arm_mve_vqrshlq_m_n_u16
#define __builtin_mve_vqrshlq_m_n_u32 __builtin_arm_mve_vqrshlq_m_n_u32
#define __builtin_mve_vqrshlq_m_n_u8 __builtin_arm_mve_vqrshlq_m_n_u8
#define __builtin_mve_vqrshlq_m_s16 __builtin_arm_mve_vqrshlq_m_s16
#define __builtin_mve_vqrshlq_m_s32 __builtin_arm_mve_vqrshlq_m_s32
#define __builtin_mve_vqrshlq_m_s8 __builtin_arm_mve_vqrshlq_m_s8
#define __builtin_mve_vqrshlq_m_u16 __builtin_arm_mve_vqrshlq_m_u16
#define __builtin_mve_vqrshlq_m_u32 __builtin_arm_mve_vqrshlq_m_u32
#define __builtin_mve_vqrshlq_m_u8 __builtin_arm_mve_vqrshlq_m_u8
#define __builtin_mve_vqrshlq_n_s16 __builtin_arm_mve_vqrshlq_n_s16
#define __builtin_mve_vqrshlq_n_s32 __builtin_arm_mve_vqrshlq_n_s32
#define __builtin_mve_vqrshlq_n_s8 __builtin_arm_mve_vqrshlq_n_s8
#define __builtin_mve_vqrshlq_n_u16 __builtin_arm_mve_vqrshlq_n_u16
#define __builtin_mve_vqrshlq_n_u32 __builtin_arm_mve_vqrshlq_n_u32
#define __builtin_mve_vqrshlq_n_u8 __builtin_arm_mve_vqrshlq_n_u8
#define __builtin_mve_vqrshlq_s16 __builtin_arm_mve_vqrshlq_s16
#define __builtin_mve_vqrshlq_s32 __builtin_arm_mve_vqrshlq_s32
#define __builtin_mve_vqrshlq_s8 __builtin_arm_mve_vqrshlq_s8
#define __builtin_mve_vqrshlq_u16 __builtin_arm_mve_vqrshlq_u16
#define __builtin_mve_vqrshlq_u32 __builtin_arm_mve_vqrshlq_u32
#define __builtin_mve_vqrshlq_u8 __builtin_arm_mve_vqrshlq_u8
#define __builtin_mve_vqshlq_m_r_s16 __builtin_arm_mve_vqshlq_m_r_s16
#define __builtin_mve_vqshlq_m_r_s32 __builtin_arm_mve_vqshlq_m_r_s32
#define __builtin_mve_vqshlq_m_r_s8 __builtin_arm_mve_vqshlq_m_r_s8
#define __builtin_mve_vqshlq_m_r_u16 __builtin_arm_mve_vqshlq_m_r_u16
#define __builtin_mve_vqshlq_m_r_u32 __builtin_arm_mve_vqshlq_m_r_u32
#define __builtin_mve_vqshlq_m_r_u8 __builtin_arm_mve_vqshlq_m_r_u8
#define __builtin_mve_vqshlq_m_s16 __builtin_arm_mve_vqshlq_m_s16
#define __builtin_mve_vqshlq_m_s32 __builtin_arm_mve_vqshlq_m_s32
#define __builtin_mve_vqshlq_m_s8 __builtin_arm_mve_vqshlq_m_s8
#define __builtin_mve_vqshlq_m_u16 __builtin_arm_mve_vqshlq_m_u16
#define __builtin_mve_vqshlq_m_u32 __builtin_arm_mve_vqshlq_m_u32
#define __builtin_mve_vqshlq_m_u8 __builtin_arm_mve_vqshlq_m_u8
#define __builtin_mve_vqshlq_r_s16 __builtin_arm_mve_vqshlq_r_s16
#define __builtin_mve_vqshlq_r_s32 __builtin_arm_mve_vqshlq_r_s32
#define __builtin_mve_vqshlq_r_s8 __builtin_arm_mve_vqshlq_r_s8
#define __builtin_mve_vqshlq_r_u16 __builtin_arm_mve_vqshlq_r_u16
#define __builtin_mve_vqshlq_r_u32 __builtin_arm_mve_vqshlq_r_u32
#define __builtin_mve_vqshlq_r_u8 __builtin_arm_mve_vqshlq_r_u8
#define __builtin_mve_vqshlq_s16 __builtin_arm_mve_vqshlq_s16
#define __builtin_mve_vqshlq_s32 __builtin_arm_mve_vqshlq_s32
#define __builtin_mve_vqshlq_s8 __builtin_arm_mve_vqshlq_s8
#define __builtin_mve_vqshlq_u16 __builtin_arm_mve_vqshlq_u16
#define __builtin_mve_vqshlq_u32 __builtin_arm_mve_vqshlq_u32
#define __builtin_mve_vqshlq_u8 __builtin_arm_mve_vqshlq_u8
#define __builtin_mve_vqsubq_m_n_s16 __builtin_arm_mve_vqsubq_m_n_s16
#define __builtin_mve_vqsubq_m_n_s32 __builtin_arm_mve_vqsubq_m_n_s32
#define __builtin_mve_vqsubq_m_n_s8 __builtin_arm_mve_vqsubq_m_n_s8
#define __builtin_mve_vqsubq_m_n_u16 __builtin_arm_mve_vqsubq_m_n_u16
#define __builtin_mve_vqsubq_m_n_u32 __builtin_arm_mve_vqsubq_m_n_u32
#define __builtin_mve_vqsubq_m_n_u8 __builtin_arm_mve_vqsubq_m_n_u8
#define __builtin_mve_vqsubq_m_s16 __builtin_arm_mve_vqsubq_m_s16
#define __builtin_mve_vqsubq_m_s32 __builtin_arm_mve_vqsubq_m_s32
#define __builtin_mve_vqsubq_m_s8 __builtin_arm_mve_vqsubq_m_s8
#define __builtin_mve_vqsubq_m_u16 __builtin_arm_mve_vqsubq_m_u16
#define __builtin_mve_vqsubq_m_u32 __builtin_arm_mve_vqsubq_m_u32
#define __builtin_mve_vqsubq_m_u8 __builtin_arm_mve_vqsubq_m_u8
#define __builtin_mve_vqsubq_n_s16 __builtin_arm_mve_vqsubq_n_s16
#define __builtin_mve_vqsubq_n_s32 __builtin_arm_mve_vqsubq_n_s32
#define __builtin_mve_vqsubq_n_s8 __builtin_arm_mve_vqsubq_n_s8
#define __builtin_mve_vqsubq_n_u16 __builtin_arm_mve_vqsubq_n_u16
#define __builtin_mve_vqsubq_n_u32 __builtin_arm_mve_vqsubq_n_u32
#define __builtin_mve_vqsubq_n_u8 __builtin_arm_mve_vqsubq_n_u8
#define __builtin_mve_vqsubq_s16 __builtin_arm_mve_vqsubq_s16
#define __builtin_mve_vqsubq_s32 __builtin_arm_mve_vqsubq_s32
#define __builtin_mve_vqsubq_s8 __builtin_arm_mve_vqsubq_s8
#define __builtin_mve_vqsubq_u16 __builtin_arm_mve_vqsubq_u16
#define __builtin_mve_vqsubq_u32 __builtin_arm_mve_vqsubq_u32
#define __builtin_mve_vqsubq_u8 __builtin_arm_mve_vqsubq_u8
#define __builtin_mve_vrev16q_m_s8 __builtin_arm_mve_vrev16q_m_s8
#define __builtin_mve_vrev16q_m_u8 __builtin_arm_mve_vrev16q_m_u8
#define __builtin_mve_vrev16q_s8 __builtin_arm_mve_vrev16q_s8
#define __builtin_mve_vrev16q_u8 __builtin_arm_mve_vrev16q_u8
#define __builtin_mve_vrev32q_f16 __builtin_arm_mve_vrev32q_f16
#define __builtin_mve_vrev32q_m_f16 __builtin_arm_mve_vrev32q_m_f16
#define __builtin_mve_vrev32q_m_s16 __builtin_arm_mve_vrev32q_m_s16
#define __builtin_mve_vrev32q_m_s8 __builtin_arm_mve_vrev32q_m_s8
#define __builtin_mve_vrev32q_m_u16 __builtin_arm_mve_vrev32q_m_u16
#define __builtin_mve_vrev32q_m_u8 __builtin_arm_mve_vrev32q_m_u8
#define __builtin_mve_vrev32q_s16 __builtin_arm_mve_vrev32q_s16
#define __builtin_mve_vrev32q_s8 __builtin_arm_mve_vrev32q_s8
#define __builtin_mve_vrev32q_u16 __builtin_arm_mve_vrev32q_u16
#define __builtin_mve_vrev32q_u8 __builtin_arm_mve_vrev32q_u8
#define __builtin_mve_vrev64q_f16 __builtin_arm_mve_vrev64q_f16
#define __builtin_mve_vrev64q_f32 __builtin_arm_mve_vrev64q_f32
#define __builtin_mve_vrev64q_m_f16 __builtin_arm_mve_vrev64q_m_f16
#define __builtin_mve_vrev64q_m_f32 __builtin_arm_mve_vrev64q_m_f32
#define __builtin_mve_vrev64q_m_s16 __builtin_arm_mve_vrev64q_m_s16
#define __builtin_mve_vrev64q_m_s32 __builtin_arm_mve_vrev64q_m_s32
#define __builtin_mve_vrev64q_m_s8 __builtin_arm_mve_vrev64q_m_s8
#define __builtin_mve_vrev64q_m_u16 __builtin_arm_mve_vrev64q_m_u16
#define __builtin_mve_vrev64q_m_u32 __builtin_arm_mve_vrev64q_m_u32
#define __builtin_mve_vrev64q_m_u8 __builtin_arm_mve_vrev64q_m_u8
#define __builtin_mve_vrev64q_s16 __builtin_arm_mve_vrev64q_s16
#define __builtin_mve_vrev64q_s32 __builtin_arm_mve_vrev64q_s32
#define __builtin_mve_vrev64q_s8 __builtin_arm_mve_vrev64q_s8
#define __builtin_mve_vrev64q_u16 __builtin_arm_mve_vrev64q_u16
#define __builtin_mve_vrev64q_u32 __builtin_arm_mve_vrev64q_u32
#define __builtin_mve_vrev64q_u8 __builtin_arm_mve_vrev64q_u8
#define __builtin_mve_vrhaddq_m_s16 __builtin_arm_mve_vrhaddq_m_s16
#define __builtin_mve_vrhaddq_m_s32 __builtin_arm_mve_vrhaddq_m_s32
#define __builtin_mve_vrhaddq_m_s8 __builtin_arm_mve_vrhaddq_m_s8
#define __builtin_mve_vrhaddq_m_u16 __builtin_arm_mve_vrhaddq_m_u16
#define __builtin_mve_vrhaddq_m_u32 __builtin_arm_mve_vrhaddq_m_u32
#define __builtin_mve_vrhaddq_m_u8 __builtin_arm_mve_vrhaddq_m_u8
#define __builtin_mve_vrhaddq_s16 __builtin_arm_mve_vrhaddq_s16
#define __builtin_mve_vrhaddq_s32 __builtin_arm_mve_vrhaddq_s32
#define __builtin_mve_vrhaddq_s8 __builtin_arm_mve_vrhaddq_s8
#define __builtin_mve_vrhaddq_u16 __builtin_arm_mve_vrhaddq_u16
#define __builtin_mve_vrhaddq_u32 __builtin_arm_mve_vrhaddq_u32
#define __builtin_mve_vrhaddq_u8 __builtin_arm_mve_vrhaddq_u8
#define __builtin_mve_vrmlaldavhaq_p_s32 __builtin_arm_mve_vrmlaldavhaq_p_s32
#define __builtin_mve_vrmlaldavhaq_p_u32 __builtin_arm_mve_vrmlaldavhaq_p_u32
#define __builtin_mve_vrmlaldavhaq_s32 __builtin_arm_mve_vrmlaldavhaq_s32
#define __builtin_mve_vrmlaldavhaq_u32 __builtin_arm_mve_vrmlaldavhaq_u32
#define __builtin_mve_vrmlaldavhaxq_p_s32 __builtin_arm_mve_vrmlaldavhaxq_p_s32
#define __builtin_mve_vrmlaldavhaxq_s32 __builtin_arm_mve_vrmlaldavhaxq_s32
#define __builtin_mve_vrmlaldavhq_p_s32 __builtin_arm_mve_vrmlaldavhq_p_s32
#define __builtin_mve_vrmlaldavhq_p_u32 __builtin_arm_mve_vrmlaldavhq_p_u32
#define __builtin_mve_vrmlaldavhq_s32 __builtin_arm_mve_vrmlaldavhq_s32
#define __builtin_mve_vrmlaldavhq_u32 __builtin_arm_mve_vrmlaldavhq_u32
#define __builtin_mve_vrmlaldavhxq_p_s32 __builtin_arm_mve_vrmlaldavhxq_p_s32
#define __builtin_mve_vrmlaldavhxq_s32 __builtin_arm_mve_vrmlaldavhxq_s32
#define __builtin_mve_vrmlsldavhaq_p_s32 __builtin_arm_mve_vrmlsldavhaq_p_s32
#define __builtin_mve_vrmlsldavhaq_s32 __builtin_arm_mve_vrmlsldavhaq_s32
#define __builtin_mve_vrmlsldavhaxq_p_s32 __builtin_arm_mve_vrmlsldavhaxq_p_s32
#define __builtin_mve_vrmlsldavhaxq_s32 __builtin_arm_mve_vrmlsldavhaxq_s32
#define __builtin_mve_vrmlsldavhq_p_s32 __builtin_arm_mve_vrmlsldavhq_p_s32
#define __builtin_mve_vrmlsldavhq_s32 __builtin_arm_mve_vrmlsldavhq_s32
#define __builtin_mve_vrmlsldavhxq_p_s32 __builtin_arm_mve_vrmlsldavhxq_p_s32
#define __builtin_mve_vrmlsldavhxq_s32 __builtin_arm_mve_vrmlsldavhxq_s32
#define __builtin_mve_vrmulhq_m_s16 __builtin_arm_mve_vrmulhq_m_s16
#define __builtin_mve_vrmulhq_m_s32 __builtin_arm_mve_vrmulhq_m_s32
#define __builtin_mve_vrmulhq_m_s8 __builtin_arm_mve_vrmulhq_m_s8
#define __builtin_mve_vrmulhq_m_u16 __builtin_arm_mve_vrmulhq_m_u16
#define __builtin_mve_vrmulhq_m_u32 __builtin_arm_mve_vrmulhq_m_u32
#define __builtin_mve_vrmulhq_m_u8 __builtin_arm_mve_vrmulhq_m_u8
#define __builtin_mve_vrmulhq_s16 __builtin_arm_mve_vrmulhq_s16
#define __builtin_mve_vrmulhq_s32 __builtin_arm_mve_vrmulhq_s32
#define __builtin_mve_vrmulhq_s8 __builtin_arm_mve_vrmulhq_s8
#define __builtin_mve_vrmulhq_u16 __builtin_arm_mve_vrmulhq_u16
#define __builtin_mve_vrmulhq_u32 __builtin_arm_mve_vrmulhq_u32
#define __builtin_mve_vrmulhq_u8 __builtin_arm_mve_vrmulhq_u8
#define __builtin_mve_vrndaq_f16 __builtin_arm_mve_vrndaq_f16
#define __builtin_mve_vrndaq_f32 __builtin_arm_mve_vrndaq_f32
#define __builtin_mve_vrndaq_m_f16 __builtin_arm_mve_vrndaq_m_f16
#define __builtin_mve_vrndaq_m_f32 __builtin_arm_mve_vrndaq_m_f32
#define __builtin_mve_vrndmq_f16 __builtin_arm_mve_vrndmq_f16
#define __builtin_mve_vrndmq_f32 __builtin_arm_mve_vrndmq_f32
#define __builtin_mve_vrndmq_m_f16 __builtin_arm_mve_vrndmq_m_f16
#define __builtin_mve_vrndmq_m_f32 __builtin_arm_mve_vrndmq_m_f32
#define __builtin_mve_vrndnq_f16 __builtin_arm_mve_vrndnq_f16
#define __builtin_mve_vrndnq_f32 __builtin_arm_mve_vrndnq_f32
#define __builtin_mve_vrndnq_m_f16 __builtin_arm_mve_vrndnq_m_f16
#define __builtin_mve_vrndnq_m_f32 __builtin_arm_mve_vrndnq_m_f32
#define __builtin_mve_vrndpq_f16 __builtin_arm_mve_vrndpq_f16
#define __builtin_mve_vrndpq_f32 __builtin_arm_mve_vrndpq_f32
#define __builtin_mve_vrndpq_m_f16 __builtin_arm_mve_vrndpq_m_f16
#define __builtin_mve_vrndpq_m_f32 __builtin_arm_mve_vrndpq_m_f32
#define __builtin_mve_vrndq_f16 __builtin_arm_mve_vrndq_f16
#define __builtin_mve_vrndq_f32 __builtin_arm_mve_vrndq_f32
#define __builtin_mve_vrndq_m_f16 __builtin_arm_mve_vrndq_m_f16
#define __builtin_mve_vrndq_m_f32 __builtin_arm_mve_vrndq_m_f32
#define __builtin_mve_vrndxq_f16 __builtin_arm_mve_vrndxq_f16
#define __builtin_mve_vrndxq_f32 __builtin_arm_mve_vrndxq_f32
#define __builtin_mve_vrndxq_m_f16 __builtin_arm_mve_vrndxq_m_f16
#define __builtin_mve_vrndxq_m_f32 __builtin_arm_mve_vrndxq_m_f32
#define __builtin_mve_vrshlq_m_n_s16 __builtin_arm_mve_vrshlq_m_n_s16
#define __builtin_mve_vrshlq_m_n_s32 __builtin_arm_mve_vrshlq_m_n_s32
#define __builtin_mve_vrshlq_m_n_s8 __builtin_arm_mve_vrshlq_m_n_s8
#define __builtin_mve_vrshlq_m_n_u16 __builtin_arm_mve_vrshlq_m_n_u16
#define __builtin_mve_vrshlq_m_n_u32 __builtin_arm_mve_vrshlq_m_n_u32
#define __builtin_mve_vrshlq_m_n_u8 __builtin_arm_mve_vrshlq_m_n_u8
#define __builtin_mve_vrshlq_m_s16 __builtin_arm_mve_vrshlq_m_s16
#define __builtin_mve_vrshlq_m_s32 __builtin_arm_mve_vrshlq_m_s32
#define __builtin_mve_vrshlq_m_s8 __builtin_arm_mve_vrshlq_m_s8
#define __builtin_mve_vrshlq_m_u16 __builtin_arm_mve_vrshlq_m_u16
#define __builtin_mve_vrshlq_m_u32 __builtin_arm_mve_vrshlq_m_u32
#define __builtin_mve_vrshlq_m_u8 __builtin_arm_mve_vrshlq_m_u8
#define __builtin_mve_vrshlq_n_s16 __builtin_arm_mve_vrshlq_n_s16
#define __builtin_mve_vrshlq_n_s32 __builtin_arm_mve_vrshlq_n_s32
#define __builtin_mve_vrshlq_n_s8 __builtin_arm_mve_vrshlq_n_s8
#define __builtin_mve_vrshlq_n_u16 __builtin_arm_mve_vrshlq_n_u16
#define __builtin_mve_vrshlq_n_u32 __builtin_arm_mve_vrshlq_n_u32
#define __builtin_mve_vrshlq_n_u8 __builtin_arm_mve_vrshlq_n_u8
#define __builtin_mve_vrshlq_s16 __builtin_arm_mve_vrshlq_s16
#define __builtin_mve_vrshlq_s32 __builtin_arm_mve_vrshlq_s32
#define __builtin_mve_vrshlq_s8 __builtin_arm_mve_vrshlq_s8
#define __builtin_mve_vrshlq_u16 __builtin_arm_mve_vrshlq_u16
#define __builtin_mve_vrshlq_u32 __builtin_arm_mve_vrshlq_u32
#define __builtin_mve_vrshlq_u8 __builtin_arm_mve_vrshlq_u8
#define __builtin_mve_vsbciq_m_s32 __builtin_arm_mve_vsbciq_m_s32
#define __builtin_mve_vsbciq_m_u32 __builtin_arm_mve_vsbciq_m_u32
#define __builtin_mve_vsbciq_s32 __builtin_arm_mve_vsbciq_s32
#define __builtin_mve_vsbciq_u32 __builtin_arm_mve_vsbciq_u32
#define __builtin_mve_vsbcq_m_s32 __builtin_arm_mve_vsbcq_m_s32
#define __builtin_mve_vsbcq_m_u32 __builtin_arm_mve_vsbcq_m_u32
#define __builtin_mve_vsbcq_s32 __builtin_arm_mve_vsbcq_s32
#define __builtin_mve_vsbcq_u32 __builtin_arm_mve_vsbcq_u32
#define __builtin_mve_vshlq_m_r_s16 __builtin_arm_mve_vshlq_m_r_s16
#define __builtin_mve_vshlq_m_r_s32 __builtin_arm_mve_vshlq_m_r_s32
#define __builtin_mve_vshlq_m_r_s8 __builtin_arm_mve_vshlq_m_r_s8
#define __builtin_mve_vshlq_m_r_u16 __builtin_arm_mve_vshlq_m_r_u16
#define __builtin_mve_vshlq_m_r_u32 __builtin_arm_mve_vshlq_m_r_u32
#define __builtin_mve_vshlq_m_r_u8 __builtin_arm_mve_vshlq_m_r_u8
#define __builtin_mve_vshlq_m_s16 __builtin_arm_mve_vshlq_m_s16
#define __builtin_mve_vshlq_m_s32 __builtin_arm_mve_vshlq_m_s32
#define __builtin_mve_vshlq_m_s8 __builtin_arm_mve_vshlq_m_s8
#define __builtin_mve_vshlq_m_u16 __builtin_arm_mve_vshlq_m_u16
#define __builtin_mve_vshlq_m_u32 __builtin_arm_mve_vshlq_m_u32
#define __builtin_mve_vshlq_m_u8 __builtin_arm_mve_vshlq_m_u8
#define __builtin_mve_vshlq_r_s16 __builtin_arm_mve_vshlq_r_s16
#define __builtin_mve_vshlq_r_s32 __builtin_arm_mve_vshlq_r_s32
#define __builtin_mve_vshlq_r_s8 __builtin_arm_mve_vshlq_r_s8
#define __builtin_mve_vshlq_r_u16 __builtin_arm_mve_vshlq_r_u16
#define __builtin_mve_vshlq_r_u32 __builtin_arm_mve_vshlq_r_u32
#define __builtin_mve_vshlq_r_u8 __builtin_arm_mve_vshlq_r_u8
#define __builtin_mve_vshlq_s16 __builtin_arm_mve_vshlq_s16
#define __builtin_mve_vshlq_s32 __builtin_arm_mve_vshlq_s32
#define __builtin_mve_vshlq_s8 __builtin_arm_mve_vshlq_s8
#define __builtin_mve_vshlq_u16 __builtin_arm_mve_vshlq_u16
#define __builtin_mve_vshlq_u32 __builtin_arm_mve_vshlq_u32
#define __builtin_mve_vshlq_u8 __builtin_arm_mve_vshlq_u8
#define __builtin_mve_vsubq_f16 __builtin_arm_mve_vsubq_f16
#define __builtin_mve_vsubq_f32 __builtin_arm_mve_vsubq_f32
#define __builtin_mve_vsubq_m_f16 __builtin_arm_mve_vsubq_m_f16
#define __builtin_mve_vsubq_m_f32 __builtin_arm_mve_vsubq_m_f32
#define __builtin_mve_vsubq_m_n_f16 __builtin_arm_mve_vsubq_m_n_f16
#define __builtin_mve_vsubq_m_n_f32 __builtin_arm_mve_vsubq_m_n_f32
#define __builtin_mve_vsubq_m_n_s16 __builtin_arm_mve_vsubq_m_n_s16
#define __builtin_mve_vsubq_m_n_s32 __builtin_arm_mve_vsubq_m_n_s32
#define __builtin_mve_vsubq_m_n_s8 __builtin_arm_mve_vsubq_m_n_s8
#define __builtin_mve_vsubq_m_n_u16 __builtin_arm_mve_vsubq_m_n_u16
#define __builtin_mve_vsubq_m_n_u32 __builtin_arm_mve_vsubq_m_n_u32
#define __builtin_mve_vsubq_m_n_u8 __builtin_arm_mve_vsubq_m_n_u8
#define __builtin_mve_vsubq_m_s16 __builtin_arm_mve_vsubq_m_s16
#define __builtin_mve_vsubq_m_s32 __builtin_arm_mve_vsubq_m_s32
#define __builtin_mve_vsubq_m_s8 __builtin_arm_mve_vsubq_m_s8
#define __builtin_mve_vsubq_m_u16 __builtin_arm_mve_vsubq_m_u16
#define __builtin_mve_vsubq_m_u32 __builtin_arm_mve_vsubq_m_u32
#define __builtin_mve_vsubq_m_u8 __builtin_arm_mve_vsubq_m_u8
#define __builtin_mve_vsubq_n_f16 __builtin_arm_mve_vsubq_n_f16
#define __builtin_mve_vsubq_n_f32 __builtin_arm_mve_vsubq_n_f32
#define __builtin_mve_vsubq_n_s16 __builtin_arm_mve_vsubq_n_s16
#define __builtin_mve_vsubq_n_s32 __builtin_arm_mve_vsubq_n_s32
#define __builtin_mve_vsubq_n_s8 __builtin_arm_mve_vsubq_n_s8
#define __builtin_mve_vsubq_n_u16 __builtin_arm_mve_vsubq_n_u16
#define __builtin_mve_vsubq_n_u32 __builtin_arm_mve_vsubq_n_u32
#define __builtin_mve_vsubq_n_u8 __builtin_arm_mve_vsubq_n_u8
#define __builtin_mve_vsubq_s16 __builtin_arm_mve_vsubq_s16
#define __builtin_mve_vsubq_s32 __builtin_arm_mve_vsubq_s32
#define __builtin_mve_vsubq_s8 __builtin_arm_mve_vsubq_s8
#define __builtin_mve_vsubq_u16 __builtin_arm_mve_vsubq_u16
#define __builtin_mve_vsubq_u32 __builtin_arm_mve_vsubq_u32
#define __builtin_mve_vsubq_u8 __builtin_arm_mve_vsubq_u8
#define __builtin_mve_vuninitializedq_f16 __builtin_arm_mve_vuninitializedq_f16
#define __builtin_mve_vuninitializedq_f32 __builtin_arm_mve_vuninitializedq_f32
#define __builtin_mve_vuninitializedq_s16 __builtin_arm_mve_vuninitializedq_s16
#define __builtin_mve_vuninitializedq_s32 __builtin_arm_mve_vuninitializedq_s32
#define __builtin_mve_vuninitializedq_s8 __builtin_arm_mve_vuninitializedq_s8
#define __builtin_mve_vuninitializedq_u16 __builtin_arm_mve_vuninitializedq_u16
#define __builtin_mve_vuninitializedq_u32 __builtin_arm_mve_vuninitializedq_u32
#define __builtin_mve_vuninitializedq_u8 __builtin_arm_mve_vuninitializedq_u8
#define __builtin_mve_vld1q_f16 __builtin_arm_mve_vld1q_f16
#define __builtin_mve_vld1q_f32 __builtin_arm_mve_vld1q_f32
#define __builtin_mve_vld1q_s16 __builtin_arm_mve_vld1q_s16
#define __builtin_mve_vld1q_s32 __builtin_arm_mve_vld1q_s32
#define __builtin_mve_vld1q_s8 __builtin_arm_mve_vld1q_s8
#define __builtin_mve_vld1q_u16 __builtin_arm_mve_vld1q_u16
#define __builtin_mve_vld1q_u32 __builtin_arm_mve_vld1q_u32
#define __builtin_mve_vld1q_u8 __builtin_arm_mve_vld1q_u8
#define __builtin_mve_vld2q_f16 __builtin_arm_mve_vld2q_f16
#define __builtin_mve_vld2q_f32 __builtin_arm_mve_vld2q_f32
#define __builtin_mve_vld2q_s16 __builtin_arm_mve_vld2q_s16
#define __builtin_mve_vld2q_s32 __builtin_arm_mve_vld2q_s32
#define __builtin_mve_vld2q_s8 __builtin_arm_mve_vld2q_s8
#define __builtin_mve_vld2q_u16 __builtin_arm_mve_vld2q_u16
#define __builtin_mve_vld2q_u32 __builtin_arm_mve_vld2q_u32
#define __builtin_mve_vld2q_u8 __builtin_arm_mve_vld2q_u8
#define __builtin_mve_vld4q_f16 __builtin_arm_mve_vld4q_f16
#define __builtin_mve_vld4q_f32 __builtin_arm_mve_vld4q_f32
#define __builtin_mve_vld4q_s16 __builtin_arm_mve_vld4q_s16
#define __builtin_mve_vld4q_s32 __builtin_arm_mve_vld4q_s32
#define __builtin_mve_vld4q_s8 __builtin_arm_mve_vld4q_s8
#define __builtin_mve_vld4q_u16 __builtin_arm_mve_vld4q_u16
#define __builtin_mve_vld4q_u32 __builtin_arm_mve_vld4q_u32
#define __builtin_mve_vld4q_u8 __builtin_arm_mve_vld4q_u8
#define __builtin_mve_vst2q_f16 __builtin_arm_mve_vst2q_f16
#define __builtin_mve_vst2q_f32 __builtin_arm_mve_vst2q_f32
#define __builtin_mve_vst2q_s16 __builtin_arm_mve_vst2q_s16
#define __builtin_mve_vst2q_s32 __builtin_arm_mve_vst2q_s32
#define __builtin_mve_vst2q_s8 __builtin_arm_mve_vst2q_s8
#define __builtin_mve_vst2q_u16 __builtin_arm_mve_vst2q_u16
#define __builtin_mve_vst2q_u32 __builtin_arm_mve_vst2q_u32
#define __builtin_mve_vst2q_u8 __builtin_arm_mve_vst2q_u8
#define __builtin_mve_vst4q_f16 __builtin_arm_mve_vst4q_f16
#define __builtin_mve_vst4q_f32 __builtin_arm_mve_vst4q_f32
#define __builtin_mve_vst4q_s16 __builtin_arm_mve_vst4q_s16
#define __builtin_mve_vst4q_s32 __builtin_arm_mve_vst4q_s32
#define __builtin_mve_vst4q_s8 __builtin_arm_mve_vst4q_s8
#define __builtin_mve_vst4q_u16 __builtin_arm_mve_vst4q_u16
#define __builtin_mve_vst4q_u32 __builtin_arm_mve_vst4q_u32
#define __builtin_mve_vst4q_u8 __builtin_arm_mve_vst4q_u8
#define __builtin_mve_vstrbq_p_s16 __builtin_arm_mve_vstrbq_p_s16
#define __builtin_mve_vstrbq_p_s32 __builtin_arm_mve_vstrbq_p_s32
#define __builtin_mve_vstrbq_p_s8 __builtin_arm_mve_vstrbq_p_s8
#define __builtin_mve_vstrbq_p_u16 __builtin_arm_mve_vstrbq_p_u16
#define __builtin_mve_vstrbq_p_u32 __builtin_arm_mve_vstrbq_p_u32
#define __builtin_mve_vstrbq_p_u8 __builtin_arm_mve_vstrbq_p_u8
#define __builtin_mve_vstrbq_s16 __builtin_arm_mve_vstrbq_s16
#define __builtin_mve_vstrbq_s32 __builtin_arm_mve_vstrbq_s32
#define __builtin_mve_vstrbq_s8 __builtin_arm_mve_vstrbq_s8
#define __builtin_mve_vstrbq_scatter_offset_p_s16 __builtin_arm_mve_vstrbq_scatter_offset_p_s16
#define __builtin_mve_vstrbq_scatter_offset_p_s32 __builtin_arm_mve_vstrbq_scatter_offset_p_s32
#define __builtin_mve_vstrbq_scatter_offset_p_s8 __builtin_arm_mve_vstrbq_scatter_offset_p_s8
#define __builtin_mve_vstrbq_scatter_offset_p_u16 __builtin_arm_mve_vstrbq_scatter_offset_p_u16
#define __builtin_mve_vstrbq_scatter_offset_p_u32 __builtin_arm_mve_vstrbq_scatter_offset_p_u32
#define __builtin_mve_vstrbq_scatter_offset_p_u8 __builtin_arm_mve_vstrbq_scatter_offset_p_u8
#define __builtin_mve_vstrbq_scatter_offset_s16 __builtin_arm_mve_vstrbq_scatter_offset_s16
#define __builtin_mve_vstrbq_scatter_offset_s32 __builtin_arm_mve_vstrbq_scatter_offset_s32
#define __builtin_mve_vstrbq_scatter_offset_s8 __builtin_arm_mve_vstrbq_scatter_offset_s8
#define __builtin_mve_vstrbq_scatter_offset_u16 __builtin_arm_mve_vstrbq_scatter_offset_u16
#define __builtin_mve_vstrbq_scatter_offset_u32 __builtin_arm_mve_vstrbq_scatter_offset_u32
#define __builtin_mve_vstrbq_scatter_offset_u8 __builtin_arm_mve_vstrbq_scatter_offset_u8
#define __builtin_mve_vstrbq_u16 __builtin_arm_mve_vstrbq_u16
#define __builtin_mve_vstrbq_u32 __builtin_arm_mve_vstrbq_u32
#define __builtin_mve_vstrbq_u8 __builtin_arm_mve_vstrbq_u8
#define __builtin_mve_vstrdq_scatter_offset_p_s64 __builtin_arm_mve_vstrdq_scatter_offset_p_s64
#define __builtin_mve_vstrdq_scatter_offset_p_u64 __builtin_arm_mve_vstrdq_scatter_offset_p_u64
#define __builtin_mve_vstrdq_scatter_offset_s64 __builtin_arm_mve_vstrdq_scatter_offset_s64
#define __builtin_mve_vstrdq_scatter_offset_u64 __builtin_arm_mve_vstrdq_scatter_offset_u64
#define __builtin_mve_vstrdq_scatter_shifted_offset_p_s64 __builtin_arm_mve_vstrdq_scatter_shifted_offset_p_s64
#define __builtin_mve_vstrdq_scatter_shifted_offset_p_u64 __builtin_arm_mve_vstrdq_scatter_shifted_offset_p_u64
#define __builtin_mve_vstrdq_scatter_shifted_offset_s64 __builtin_arm_mve_vstrdq_scatter_shifted_offset_s64
#define __builtin_mve_vstrdq_scatter_shifted_offset_u64 __builtin_arm_mve_vstrdq_scatter_shifted_offset_u64
#define __builtin_mve_vstrhq_f16 __builtin_arm_mve_vstrhq_f16
#define __builtin_mve_vstrhq_p_f16 __builtin_arm_mve_vstrhq_p_f16
#define __builtin_mve_vstrhq_p_s16 __builtin_arm_mve_vstrhq_p_s16
#define __builtin_mve_vstrhq_p_s32 __builtin_arm_mve_vstrhq_p_s32
#define __builtin_mve_vstrhq_p_u16 __builtin_arm_mve_vstrhq_p_u16
#define __builtin_mve_vstrhq_p_u32 __builtin_arm_mve_vstrhq_p_u32
#define __builtin_mve_vstrhq_s16 __builtin_arm_mve_vstrhq_s16
#define __builtin_mve_vstrhq_s32 __builtin_arm_mve_vstrhq_s32
#define __builtin_mve_vstrhq_scatter_offset_f16 __builtin_arm_mve_vstrhq_scatter_offset_f16
#define __builtin_mve_vstrhq_scatter_offset_p_f16 __builtin_arm_mve_vstrhq_scatter_offset_p_f16
#define __builtin_mve_vstrhq_scatter_offset_p_s16 __builtin_arm_mve_vstrhq_scatter_offset_p_s16
#define __builtin_mve_vstrhq_scatter_offset_p_s32 __builtin_arm_mve_vstrhq_scatter_offset_p_s32
#define __builtin_mve_vstrhq_scatter_offset_p_u16 __builtin_arm_mve_vstrhq_scatter_offset_p_u16
#define __builtin_mve_vstrhq_scatter_offset_p_u32 __builtin_arm_mve_vstrhq_scatter_offset_p_u32
#define __builtin_mve_vstrhq_scatter_offset_s16 __builtin_arm_mve_vstrhq_scatter_offset_s16
#define __builtin_mve_vstrhq_scatter_offset_s32 __builtin_arm_mve_vstrhq_scatter_offset_s32
#define __builtin_mve_vstrhq_scatter_offset_u16 __builtin_arm_mve_vstrhq_scatter_offset_u16
#define __builtin_mve_vstrhq_scatter_offset_u32 __builtin_arm_mve_vstrhq_scatter_offset_u32
#define __builtin_mve_vstrhq_scatter_shifted_offset_f16 __builtin_arm_mve_vstrhq_scatter_shifted_offset_f16
#define __builtin_mve_vstrhq_scatter_shifted_offset_p_f16 __builtin_arm_mve_vstrhq_scatter_shifted_offset_p_f16
#define __builtin_mve_vstrhq_scatter_shifted_offset_p_s16 __builtin_arm_mve_vstrhq_scatter_shifted_offset_p_s16
#define __builtin_mve_vstrhq_scatter_shifted_offset_p_s32 __builtin_arm_mve_vstrhq_scatter_shifted_offset_p_s32
#define __builtin_mve_vstrhq_scatter_shifted_offset_p_u16 __builtin_arm_mve_vstrhq_scatter_shifted_offset_p_u16
#define __builtin_mve_vstrhq_scatter_shifted_offset_p_u32 __builtin_arm_mve_vstrhq_scatter_shifted_offset_p_u32
#define __builtin_mve_vstrhq_scatter_shifted_offset_s16 __builtin_arm_mve_vstrhq_scatter_shifted_offset_s16
#define __builtin_mve_vstrhq_scatter_shifted_offset_s32 __builtin_arm_mve_vstrhq_scatter_shifted_offset_s32
#define __builtin_mve_vstrhq_scatter_shifted_offset_u16 __builtin_arm_mve_vstrhq_scatter_shifted_offset_u16
#define __builtin_mve_vstrhq_scatter_shifted_offset_u32 __builtin_arm_mve_vstrhq_scatter_shifted_offset_u32
#define __builtin_mve_vstrhq_u16 __builtin_arm_mve_vstrhq_u16
#define __builtin_mve_vstrhq_u32 __builtin_arm_mve_vstrhq_u32
#define __builtin_mve_vstrwq_f32 __builtin_arm_mve_vstrwq_f32
#define __builtin_mve_vstrwq_p_f32 __builtin_arm_mve_vstrwq_p_f32
#define __builtin_mve_vstrwq_p_s32 __builtin_arm_mve_vstrwq_p_s32
#define __builtin_mve_vstrwq_p_u32 __builtin_arm_mve_vstrwq_p_u32
#define __builtin_mve_vstrwq_s32 __builtin_arm_mve_vstrwq_s32
#define __builtin_mve_vstrwq_scatter_offset_f32 __builtin_arm_mve_vstrwq_scatter_offset_f32
#define __builtin_mve_vstrwq_scatter_offset_p_f32 __builtin_arm_mve_vstrwq_scatter_offset_p_f32
#define __builtin_mve_vstrwq_scatter_offset_p_s32 __builtin_arm_mve_vstrwq_scatter_offset_p_s32
#define __builtin_mve_vstrwq_scatter_offset_p_u32 __builtin_arm_mve_vstrwq_scatter_offset_p_u32
#define __builtin_mve_vstrwq_scatter_offset_s32 __builtin_arm_mve_vstrwq_scatter_offset_s32
#define __builtin_mve_vstrwq_scatter_offset_u32 __builtin_arm_mve_vstrwq_scatter_offset_u32
#define __builtin_mve_vstrwq_scatter_shifted_offset_f32 __builtin_arm_mve_vstrwq_scatter_shifted_offset_f32
#define __builtin_mve_vstrwq_scatter_shifted_offset_p_f32 __builtin_arm_mve_vstrwq_scatter_shifted_offset_p_f32
#define __builtin_mve_vstrwq_scatter_shifted_offset_p_s32 __builtin_arm_mve_vstrwq_scatter_shifted_offset_p_s32
#define __builtin_mve_vstrwq_scatter_shifted_offset_p_u32 __builtin_arm_mve_vstrwq_scatter_shifted_offset_p_u32
#define __builtin_mve_vstrwq_scatter_shifted_offset_s32 __builtin_arm_mve_vstrwq_scatter_shifted_offset_s32
#define __builtin_mve_vstrwq_scatter_shifted_offset_u32 __builtin_arm_mve_vstrwq_scatter_shifted_offset_u32
#define __builtin_mve_vstrwq_u32 __builtin_arm_mve_vstrwq_u32
#define __builtin_mve_vst1q_f16 __builtin_arm_mve_vst1q_f16
#define __builtin_mve_vst1q_f32 __builtin_arm_mve_vst1q_f32
#define __builtin_mve_vst1q_s16 __builtin_arm_mve_vst1q_s16
#define __builtin_mve_vst1q_s32 __builtin_arm_mve_vst1q_s32
#define __builtin_mve_vst1q_s8 __builtin_arm_mve_vst1q_s8
#define __builtin_mve_vst1q_u16 __builtin_arm_mve_vst1q_u16
#define __builtin_mve_vst1q_u32 __builtin_arm_mve_vst1q_u32
#define __builtin_mve_vst1q_u8 __builtin_arm_mve_vst1q_u8
#define __builtin_mve_sqshl __builtin_arm_mve_sqshl
#define __builtin_mve_sqshll __builtin_arm_mve_sqshll
#define __builtin_mve_srshr __builtin_arm_mve_srshr
#define __builtin_mve_srshrl __builtin_arm_mve_srshrl
#define __builtin_mve_uqshl __builtin_arm_mve_uqshl
#define __builtin_mve_uqshll __builtin_arm_mve_uqshll
#define __builtin_mve_urshr __builtin_arm_mve_urshr
#define __builtin_mve_urshrl __builtin_arm_mve_urshrl
#define __builtin_mve_vbicq_m_n_s16 __builtin_arm_mve_vbicq_m_n_s16
#define __builtin_mve_vbicq_m_n_s32 __builtin_arm_mve_vbicq_m_n_s32
#define __builtin_mve_vbicq_m_n_u16 __builtin_arm_mve_vbicq_m_n_u16
#define __builtin_mve_vbicq_m_n_u32 __builtin_arm_mve_vbicq_m_n_u32
#define __builtin_mve_vbicq_n_s16 __builtin_arm_mve_vbicq_n_s16
#define __builtin_mve_vbicq_n_s32 __builtin_arm_mve_vbicq_n_s32
#define __builtin_mve_vbicq_n_u16 __builtin_arm_mve_vbicq_n_u16
#define __builtin_mve_vbicq_n_u32 __builtin_arm_mve_vbicq_n_u32
#define __builtin_mve_vcvtq_m_n_f16_s16 __builtin_arm_mve_vcvtq_m_n_f16_s16
#define __builtin_mve_vcvtq_m_n_f16_u16 __builtin_arm_mve_vcvtq_m_n_f16_u16
#define __builtin_mve_vcvtq_m_n_f32_s32 __builtin_arm_mve_vcvtq_m_n_f32_s32
#define __builtin_mve_vcvtq_m_n_f32_u32 __builtin_arm_mve_vcvtq_m_n_f32_u32
#define __builtin_mve_vcvtq_m_n_s16_f16 __builtin_arm_mve_vcvtq_m_n_s16_f16
#define __builtin_mve_vcvtq_m_n_s32_f32 __builtin_arm_mve_vcvtq_m_n_s32_f32
#define __builtin_mve_vcvtq_m_n_u16_f16 __builtin_arm_mve_vcvtq_m_n_u16_f16
#define __builtin_mve_vcvtq_m_n_u32_f32 __builtin_arm_mve_vcvtq_m_n_u32_f32
#define __builtin_mve_vcvtq_n_f16_s16 __builtin_arm_mve_vcvtq_n_f16_s16
#define __builtin_mve_vcvtq_n_f16_u16 __builtin_arm_mve_vcvtq_n_f16_u16
#define __builtin_mve_vcvtq_n_f32_s32 __builtin_arm_mve_vcvtq_n_f32_s32
#define __builtin_mve_vcvtq_n_f32_u32 __builtin_arm_mve_vcvtq_n_f32_u32
#define __builtin_mve_vcvtq_n_s16_f16 __builtin_arm_mve_vcvtq_n_s16_f16
#define __builtin_mve_vcvtq_n_s32_f32 __builtin_arm_mve_vcvtq_n_s32_f32
#define __builtin_mve_vcvtq_n_u16_f16 __builtin_arm_mve_vcvtq_n_u16_f16
#define __builtin_mve_vcvtq_n_u32_f32 __builtin_arm_mve_vcvtq_n_u32_f32
#define __builtin_mve_vddupq_m_n_u16 __builtin_arm_mve_vddupq_m_n_u16
#define __builtin_mve_vddupq_m_n_u32 __builtin_arm_mve_vddupq_m_n_u32
#define __builtin_mve_vddupq_m_n_u8 __builtin_arm_mve_vddupq_m_n_u8
#define __builtin_mve_vddupq_m_wb_u16 __builtin_arm_mve_vddupq_m_wb_u16
#define __builtin_mve_vddupq_m_wb_u32 __builtin_arm_mve_vddupq_m_wb_u32
#define __builtin_mve_vddupq_m_wb_u8 __builtin_arm_mve_vddupq_m_wb_u8
#define __builtin_mve_vddupq_n_u16 __builtin_arm_mve_vddupq_n_u16
#define __builtin_mve_vddupq_n_u32 __builtin_arm_mve_vddupq_n_u32
#define __builtin_mve_vddupq_n_u8 __builtin_arm_mve_vddupq_n_u8
#define __builtin_mve_vddupq_wb_u16 __builtin_arm_mve_vddupq_wb_u16
#define __builtin_mve_vddupq_wb_u32 __builtin_arm_mve_vddupq_wb_u32
#define __builtin_mve_vddupq_wb_u8 __builtin_arm_mve_vddupq_wb_u8
#define __builtin_mve_vdwdupq_m_n_u16 __builtin_arm_mve_vdwdupq_m_n_u16
#define __builtin_mve_vdwdupq_m_n_u32 __builtin_arm_mve_vdwdupq_m_n_u32
#define __builtin_mve_vdwdupq_m_n_u8 __builtin_arm_mve_vdwdupq_m_n_u8
#define __builtin_mve_vdwdupq_m_wb_u16 __builtin_arm_mve_vdwdupq_m_wb_u16
#define __builtin_mve_vdwdupq_m_wb_u32 __builtin_arm_mve_vdwdupq_m_wb_u32
#define __builtin_mve_vdwdupq_m_wb_u8 __builtin_arm_mve_vdwdupq_m_wb_u8
#define __builtin_mve_vdwdupq_n_u16 __builtin_arm_mve_vdwdupq_n_u16
#define __builtin_mve_vdwdupq_n_u32 __builtin_arm_mve_vdwdupq_n_u32
#define __builtin_mve_vdwdupq_n_u8 __builtin_arm_mve_vdwdupq_n_u8
#define __builtin_mve_vdwdupq_wb_u16 __builtin_arm_mve_vdwdupq_wb_u16
#define __builtin_mve_vdwdupq_wb_u32 __builtin_arm_mve_vdwdupq_wb_u32
#define __builtin_mve_vdwdupq_wb_u8 __builtin_arm_mve_vdwdupq_wb_u8
#define __builtin_mve_vgetq_lane_f16 __builtin_arm_mve_vgetq_lane_f16
#define __builtin_mve_vgetq_lane_f32 __builtin_arm_mve_vgetq_lane_f32
#define __builtin_mve_vgetq_lane_s16 __builtin_arm_mve_vgetq_lane_s16
#define __builtin_mve_vgetq_lane_s32 __builtin_arm_mve_vgetq_lane_s32
#define __builtin_mve_vgetq_lane_s64 __builtin_arm_mve_vgetq_lane_s64
#define __builtin_mve_vgetq_lane_s8 __builtin_arm_mve_vgetq_lane_s8
#define __builtin_mve_vgetq_lane_u16 __builtin_arm_mve_vgetq_lane_u16
#define __builtin_mve_vgetq_lane_u32 __builtin_arm_mve_vgetq_lane_u32
#define __builtin_mve_vgetq_lane_u64 __builtin_arm_mve_vgetq_lane_u64
#define __builtin_mve_vgetq_lane_u8 __builtin_arm_mve_vgetq_lane_u8
#define __builtin_mve_vidupq_m_n_u16 __builtin_arm_mve_vidupq_m_n_u16
#define __builtin_mve_vidupq_m_n_u32 __builtin_arm_mve_vidupq_m_n_u32
#define __builtin_mve_vidupq_m_n_u8 __builtin_arm_mve_vidupq_m_n_u8
#define __builtin_mve_vidupq_m_wb_u16 __builtin_arm_mve_vidupq_m_wb_u16
#define __builtin_mve_vidupq_m_wb_u32 __builtin_arm_mve_vidupq_m_wb_u32
#define __builtin_mve_vidupq_m_wb_u8 __builtin_arm_mve_vidupq_m_wb_u8
#define __builtin_mve_vidupq_n_u16 __builtin_arm_mve_vidupq_n_u16
#define __builtin_mve_vidupq_n_u32 __builtin_arm_mve_vidupq_n_u32
#define __builtin_mve_vidupq_n_u8 __builtin_arm_mve_vidupq_n_u8
#define __builtin_mve_vidupq_wb_u16 __builtin_arm_mve_vidupq_wb_u16
#define __builtin_mve_vidupq_wb_u32 __builtin_arm_mve_vidupq_wb_u32
#define __builtin_mve_vidupq_wb_u8 __builtin_arm_mve_vidupq_wb_u8
#define __builtin_mve_viwdupq_m_n_u16 __builtin_arm_mve_viwdupq_m_n_u16
#define __builtin_mve_viwdupq_m_n_u32 __builtin_arm_mve_viwdupq_m_n_u32
#define __builtin_mve_viwdupq_m_n_u8 __builtin_arm_mve_viwdupq_m_n_u8
#define __builtin_mve_viwdupq_m_wb_u16 __builtin_arm_mve_viwdupq_m_wb_u16
#define __builtin_mve_viwdupq_m_wb_u32 __builtin_arm_mve_viwdupq_m_wb_u32
#define __builtin_mve_viwdupq_m_wb_u8 __builtin_arm_mve_viwdupq_m_wb_u8
#define __builtin_mve_viwdupq_n_u16 __builtin_arm_mve_viwdupq_n_u16
#define __builtin_mve_viwdupq_n_u32 __builtin_arm_mve_viwdupq_n_u32
#define __builtin_mve_viwdupq_n_u8 __builtin_arm_mve_viwdupq_n_u8
#define __builtin_mve_viwdupq_wb_u16 __builtin_arm_mve_viwdupq_wb_u16
#define __builtin_mve_viwdupq_wb_u32 __builtin_arm_mve_viwdupq_wb_u32
#define __builtin_mve_viwdupq_wb_u8 __builtin_arm_mve_viwdupq_wb_u8
#define __builtin_mve_vldrdq_gather_base_s64 __builtin_arm_mve_vldrdq_gather_base_s64
#define __builtin_mve_vldrdq_gather_base_u64 __builtin_arm_mve_vldrdq_gather_base_u64
#define __builtin_mve_vldrdq_gather_base_wb_s64 __builtin_arm_mve_vldrdq_gather_base_wb_s64
#define __builtin_mve_vldrdq_gather_base_wb_u64 __builtin_arm_mve_vldrdq_gather_base_wb_u64
#define __builtin_mve_vldrdq_gather_base_wb_z_s64 __builtin_arm_mve_vldrdq_gather_base_wb_z_s64
#define __builtin_mve_vldrdq_gather_base_wb_z_u64 __builtin_arm_mve_vldrdq_gather_base_wb_z_u64
#define __builtin_mve_vldrdq_gather_base_z_s64 __builtin_arm_mve_vldrdq_gather_base_z_s64
#define __builtin_mve_vldrdq_gather_base_z_u64 __builtin_arm_mve_vldrdq_gather_base_z_u64
#define __builtin_mve_vldrwq_gather_base_f32 __builtin_arm_mve_vldrwq_gather_base_f32
#define __builtin_mve_vldrwq_gather_base_s32 __builtin_arm_mve_vldrwq_gather_base_s32
#define __builtin_mve_vldrwq_gather_base_u32 __builtin_arm_mve_vldrwq_gather_base_u32
#define __builtin_mve_vldrwq_gather_base_wb_f32 __builtin_arm_mve_vldrwq_gather_base_wb_f32
#define __builtin_mve_vldrwq_gather_base_wb_s32 __builtin_arm_mve_vldrwq_gather_base_wb_s32
#define __builtin_mve_vldrwq_gather_base_wb_u32 __builtin_arm_mve_vldrwq_gather_base_wb_u32
#define __builtin_mve_vldrwq_gather_base_wb_z_f32 __builtin_arm_mve_vldrwq_gather_base_wb_z_f32
#define __builtin_mve_vldrwq_gather_base_wb_z_s32 __builtin_arm_mve_vldrwq_gather_base_wb_z_s32
#define __builtin_mve_vldrwq_gather_base_wb_z_u32 __builtin_arm_mve_vldrwq_gather_base_wb_z_u32
#define __builtin_mve_vldrwq_gather_base_z_f32 __builtin_arm_mve_vldrwq_gather_base_z_f32
#define __builtin_mve_vldrwq_gather_base_z_s32 __builtin_arm_mve_vldrwq_gather_base_z_s32
#define __builtin_mve_vldrwq_gather_base_z_u32 __builtin_arm_mve_vldrwq_gather_base_z_u32
#define __builtin_mve_vmvnq_m_n_s16 __builtin_arm_mve_vmvnq_m_n_s16
#define __builtin_mve_vmvnq_m_n_s32 __builtin_arm_mve_vmvnq_m_n_s32
#define __builtin_mve_vmvnq_m_n_u16 __builtin_arm_mve_vmvnq_m_n_u16
#define __builtin_mve_vmvnq_m_n_u32 __builtin_arm_mve_vmvnq_m_n_u32
#define __builtin_mve_vmvnq_n_s16 __builtin_arm_mve_vmvnq_n_s16
#define __builtin_mve_vmvnq_n_s32 __builtin_arm_mve_vmvnq_n_s32
#define __builtin_mve_vmvnq_n_u16 __builtin_arm_mve_vmvnq_n_u16
#define __builtin_mve_vmvnq_n_u32 __builtin_arm_mve_vmvnq_n_u32
#define __builtin_mve_vorrq_m_n_s16 __builtin_arm_mve_vorrq_m_n_s16
#define __builtin_mve_vorrq_m_n_s32 __builtin_arm_mve_vorrq_m_n_s32
#define __builtin_mve_vorrq_m_n_u16 __builtin_arm_mve_vorrq_m_n_u16
#define __builtin_mve_vorrq_m_n_u32 __builtin_arm_mve_vorrq_m_n_u32
#define __builtin_mve_vorrq_n_s16 __builtin_arm_mve_vorrq_n_s16
#define __builtin_mve_vorrq_n_s32 __builtin_arm_mve_vorrq_n_s32
#define __builtin_mve_vorrq_n_u16 __builtin_arm_mve_vorrq_n_u16
#define __builtin_mve_vorrq_n_u32 __builtin_arm_mve_vorrq_n_u32
#define __builtin_mve_vqrshrnbq_m_n_s16 __builtin_arm_mve_vqrshrnbq_m_n_s16
#define __builtin_mve_vqrshrnbq_m_n_s32 __builtin_arm_mve_vqrshrnbq_m_n_s32
#define __builtin_mve_vqrshrnbq_m_n_u16 __builtin_arm_mve_vqrshrnbq_m_n_u16
#define __builtin_mve_vqrshrnbq_m_n_u32 __builtin_arm_mve_vqrshrnbq_m_n_u32
#define __builtin_mve_vqrshrnbq_n_s16 __builtin_arm_mve_vqrshrnbq_n_s16
#define __builtin_mve_vqrshrnbq_n_s32 __builtin_arm_mve_vqrshrnbq_n_s32
#define __builtin_mve_vqrshrnbq_n_u16 __builtin_arm_mve_vqrshrnbq_n_u16
#define __builtin_mve_vqrshrnbq_n_u32 __builtin_arm_mve_vqrshrnbq_n_u32
#define __builtin_mve_vqrshrntq_m_n_s16 __builtin_arm_mve_vqrshrntq_m_n_s16
#define __builtin_mve_vqrshrntq_m_n_s32 __builtin_arm_mve_vqrshrntq_m_n_s32
#define __builtin_mve_vqrshrntq_m_n_u16 __builtin_arm_mve_vqrshrntq_m_n_u16
#define __builtin_mve_vqrshrntq_m_n_u32 __builtin_arm_mve_vqrshrntq_m_n_u32
#define __builtin_mve_vqrshrntq_n_s16 __builtin_arm_mve_vqrshrntq_n_s16
#define __builtin_mve_vqrshrntq_n_s32 __builtin_arm_mve_vqrshrntq_n_s32
#define __builtin_mve_vqrshrntq_n_u16 __builtin_arm_mve_vqrshrntq_n_u16
#define __builtin_mve_vqrshrntq_n_u32 __builtin_arm_mve_vqrshrntq_n_u32
#define __builtin_mve_vqrshrunbq_m_n_s16 __builtin_arm_mve_vqrshrunbq_m_n_s16
#define __builtin_mve_vqrshrunbq_m_n_s32 __builtin_arm_mve_vqrshrunbq_m_n_s32
#define __builtin_mve_vqrshrunbq_n_s16 __builtin_arm_mve_vqrshrunbq_n_s16
#define __builtin_mve_vqrshrunbq_n_s32 __builtin_arm_mve_vqrshrunbq_n_s32
#define __builtin_mve_vqrshruntq_m_n_s16 __builtin_arm_mve_vqrshruntq_m_n_s16
#define __builtin_mve_vqrshruntq_m_n_s32 __builtin_arm_mve_vqrshruntq_m_n_s32
#define __builtin_mve_vqrshruntq_n_s16 __builtin_arm_mve_vqrshruntq_n_s16
#define __builtin_mve_vqrshruntq_n_s32 __builtin_arm_mve_vqrshruntq_n_s32
#define __builtin_mve_vqshlq_m_n_s16 __builtin_arm_mve_vqshlq_m_n_s16
#define __builtin_mve_vqshlq_m_n_s32 __builtin_arm_mve_vqshlq_m_n_s32
#define __builtin_mve_vqshlq_m_n_s8 __builtin_arm_mve_vqshlq_m_n_s8
#define __builtin_mve_vqshlq_m_n_u16 __builtin_arm_mve_vqshlq_m_n_u16
#define __builtin_mve_vqshlq_m_n_u32 __builtin_arm_mve_vqshlq_m_n_u32
#define __builtin_mve_vqshlq_m_n_u8 __builtin_arm_mve_vqshlq_m_n_u8
#define __builtin_mve_vqshlq_n_s16 __builtin_arm_mve_vqshlq_n_s16
#define __builtin_mve_vqshlq_n_s32 __builtin_arm_mve_vqshlq_n_s32
#define __builtin_mve_vqshlq_n_s8 __builtin_arm_mve_vqshlq_n_s8
#define __builtin_mve_vqshlq_n_u16 __builtin_arm_mve_vqshlq_n_u16
#define __builtin_mve_vqshlq_n_u32 __builtin_arm_mve_vqshlq_n_u32
#define __builtin_mve_vqshlq_n_u8 __builtin_arm_mve_vqshlq_n_u8
#define __builtin_mve_vqshluq_m_n_s16 __builtin_arm_mve_vqshluq_m_n_s16
#define __builtin_mve_vqshluq_m_n_s32 __builtin_arm_mve_vqshluq_m_n_s32
#define __builtin_mve_vqshluq_m_n_s8 __builtin_arm_mve_vqshluq_m_n_s8
#define __builtin_mve_vqshluq_n_s16 __builtin_arm_mve_vqshluq_n_s16
#define __builtin_mve_vqshluq_n_s32 __builtin_arm_mve_vqshluq_n_s32
#define __builtin_mve_vqshluq_n_s8 __builtin_arm_mve_vqshluq_n_s8
#define __builtin_mve_vqshrnbq_m_n_s16 __builtin_arm_mve_vqshrnbq_m_n_s16
#define __builtin_mve_vqshrnbq_m_n_s32 __builtin_arm_mve_vqshrnbq_m_n_s32
#define __builtin_mve_vqshrnbq_m_n_u16 __builtin_arm_mve_vqshrnbq_m_n_u16
#define __builtin_mve_vqshrnbq_m_n_u32 __builtin_arm_mve_vqshrnbq_m_n_u32
#define __builtin_mve_vqshrnbq_n_s16 __builtin_arm_mve_vqshrnbq_n_s16
#define __builtin_mve_vqshrnbq_n_s32 __builtin_arm_mve_vqshrnbq_n_s32
#define __builtin_mve_vqshrnbq_n_u16 __builtin_arm_mve_vqshrnbq_n_u16
#define __builtin_mve_vqshrnbq_n_u32 __builtin_arm_mve_vqshrnbq_n_u32
#define __builtin_mve_vqshrntq_m_n_s16 __builtin_arm_mve_vqshrntq_m_n_s16
#define __builtin_mve_vqshrntq_m_n_s32 __builtin_arm_mve_vqshrntq_m_n_s32
#define __builtin_mve_vqshrntq_m_n_u16 __builtin_arm_mve_vqshrntq_m_n_u16
#define __builtin_mve_vqshrntq_m_n_u32 __builtin_arm_mve_vqshrntq_m_n_u32
#define __builtin_mve_vqshrntq_n_s16 __builtin_arm_mve_vqshrntq_n_s16
#define __builtin_mve_vqshrntq_n_s32 __builtin_arm_mve_vqshrntq_n_s32
#define __builtin_mve_vqshrntq_n_u16 __builtin_arm_mve_vqshrntq_n_u16
#define __builtin_mve_vqshrntq_n_u32 __builtin_arm_mve_vqshrntq_n_u32
#define __builtin_mve_vqshrunbq_m_n_s16 __builtin_arm_mve_vqshrunbq_m_n_s16
#define __builtin_mve_vqshrunbq_m_n_s32 __builtin_arm_mve_vqshrunbq_m_n_s32
#define __builtin_mve_vqshrunbq_n_s16 __builtin_arm_mve_vqshrunbq_n_s16
#define __builtin_mve_vqshrunbq_n_s32 __builtin_arm_mve_vqshrunbq_n_s32
#define __builtin_mve_vqshruntq_m_n_s16 __builtin_arm_mve_vqshruntq_m_n_s16
#define __builtin_mve_vqshruntq_m_n_s32 __builtin_arm_mve_vqshruntq_m_n_s32
#define __builtin_mve_vqshruntq_n_s16 __builtin_arm_mve_vqshruntq_n_s16
#define __builtin_mve_vqshruntq_n_s32 __builtin_arm_mve_vqshruntq_n_s32
#define __builtin_mve_vrshrnbq_m_n_s16 __builtin_arm_mve_vrshrnbq_m_n_s16
#define __builtin_mve_vrshrnbq_m_n_s32 __builtin_arm_mve_vrshrnbq_m_n_s32
#define __builtin_mve_vrshrnbq_m_n_u16 __builtin_arm_mve_vrshrnbq_m_n_u16
#define __builtin_mve_vrshrnbq_m_n_u32 __builtin_arm_mve_vrshrnbq_m_n_u32
#define __builtin_mve_vrshrnbq_n_s16 __builtin_arm_mve_vrshrnbq_n_s16
#define __builtin_mve_vrshrnbq_n_s32 __builtin_arm_mve_vrshrnbq_n_s32
#define __builtin_mve_vrshrnbq_n_u16 __builtin_arm_mve_vrshrnbq_n_u16
#define __builtin_mve_vrshrnbq_n_u32 __builtin_arm_mve_vrshrnbq_n_u32
#define __builtin_mve_vrshrntq_m_n_s16 __builtin_arm_mve_vrshrntq_m_n_s16
#define __builtin_mve_vrshrntq_m_n_s32 __builtin_arm_mve_vrshrntq_m_n_s32
#define __builtin_mve_vrshrntq_m_n_u16 __builtin_arm_mve_vrshrntq_m_n_u16
#define __builtin_mve_vrshrntq_m_n_u32 __builtin_arm_mve_vrshrntq_m_n_u32
#define __builtin_mve_vrshrntq_n_s16 __builtin_arm_mve_vrshrntq_n_s16
#define __builtin_mve_vrshrntq_n_s32 __builtin_arm_mve_vrshrntq_n_s32
#define __builtin_mve_vrshrntq_n_u16 __builtin_arm_mve_vrshrntq_n_u16
#define __builtin_mve_vrshrntq_n_u32 __builtin_arm_mve_vrshrntq_n_u32
#define __builtin_mve_vrshrq_m_n_s16 __builtin_arm_mve_vrshrq_m_n_s16
#define __builtin_mve_vrshrq_m_n_s32 __builtin_arm_mve_vrshrq_m_n_s32
#define __builtin_mve_vrshrq_m_n_s8 __builtin_arm_mve_vrshrq_m_n_s8
#define __builtin_mve_vrshrq_m_n_u16 __builtin_arm_mve_vrshrq_m_n_u16
#define __builtin_mve_vrshrq_m_n_u32 __builtin_arm_mve_vrshrq_m_n_u32
#define __builtin_mve_vrshrq_m_n_u8 __builtin_arm_mve_vrshrq_m_n_u8
#define __builtin_mve_vrshrq_n_s16 __builtin_arm_mve_vrshrq_n_s16
#define __builtin_mve_vrshrq_n_s32 __builtin_arm_mve_vrshrq_n_s32
#define __builtin_mve_vrshrq_n_s8 __builtin_arm_mve_vrshrq_n_s8
#define __builtin_mve_vrshrq_n_u16 __builtin_arm_mve_vrshrq_n_u16
#define __builtin_mve_vrshrq_n_u32 __builtin_arm_mve_vrshrq_n_u32
#define __builtin_mve_vrshrq_n_u8 __builtin_arm_mve_vrshrq_n_u8
#define __builtin_mve_vsetq_lane_f16 __builtin_arm_mve_vsetq_lane_f16
#define __builtin_mve_vsetq_lane_f32 __builtin_arm_mve_vsetq_lane_f32
#define __builtin_mve_vsetq_lane_s16 __builtin_arm_mve_vsetq_lane_s16
#define __builtin_mve_vsetq_lane_s32 __builtin_arm_mve_vsetq_lane_s32
#define __builtin_mve_vsetq_lane_s64 __builtin_arm_mve_vsetq_lane_s64
#define __builtin_mve_vsetq_lane_s8 __builtin_arm_mve_vsetq_lane_s8
#define __builtin_mve_vsetq_lane_u16 __builtin_arm_mve_vsetq_lane_u16
#define __builtin_mve_vsetq_lane_u32 __builtin_arm_mve_vsetq_lane_u32
#define __builtin_mve_vsetq_lane_u64 __builtin_arm_mve_vsetq_lane_u64
#define __builtin_mve_vsetq_lane_u8 __builtin_arm_mve_vsetq_lane_u8
#define __builtin_mve_vshlcq_m_s16 __builtin_arm_mve_vshlcq_m_s16
#define __builtin_mve_vshlcq_m_s32 __builtin_arm_mve_vshlcq_m_s32
#define __builtin_mve_vshlcq_m_s8 __builtin_arm_mve_vshlcq_m_s8
#define __builtin_mve_vshlcq_m_u16 __builtin_arm_mve_vshlcq_m_u16
#define __builtin_mve_vshlcq_m_u32 __builtin_arm_mve_vshlcq_m_u32
#define __builtin_mve_vshlcq_m_u8 __builtin_arm_mve_vshlcq_m_u8
#define __builtin_mve_vshlcq_s16 __builtin_arm_mve_vshlcq_s16
#define __builtin_mve_vshlcq_s32 __builtin_arm_mve_vshlcq_s32
#define __builtin_mve_vshlcq_s8 __builtin_arm_mve_vshlcq_s8
#define __builtin_mve_vshlcq_u16 __builtin_arm_mve_vshlcq_u16
#define __builtin_mve_vshlcq_u32 __builtin_arm_mve_vshlcq_u32
#define __builtin_mve_vshlcq_u8 __builtin_arm_mve_vshlcq_u8
#define __builtin_mve_vshllbq_m_n_s16 __builtin_arm_mve_vshllbq_m_n_s16
#define __builtin_mve_vshllbq_m_n_s8 __builtin_arm_mve_vshllbq_m_n_s8
#define __builtin_mve_vshllbq_m_n_u16 __builtin_arm_mve_vshllbq_m_n_u16
#define __builtin_mve_vshllbq_m_n_u8 __builtin_arm_mve_vshllbq_m_n_u8
#define __builtin_mve_vshllbq_n_s16 __builtin_arm_mve_vshllbq_n_s16
#define __builtin_mve_vshllbq_n_s8 __builtin_arm_mve_vshllbq_n_s8
#define __builtin_mve_vshllbq_n_u16 __builtin_arm_mve_vshllbq_n_u16
#define __builtin_mve_vshllbq_n_u8 __builtin_arm_mve_vshllbq_n_u8
#define __builtin_mve_vshlltq_m_n_s16 __builtin_arm_mve_vshlltq_m_n_s16
#define __builtin_mve_vshlltq_m_n_s8 __builtin_arm_mve_vshlltq_m_n_s8
#define __builtin_mve_vshlltq_m_n_u16 __builtin_arm_mve_vshlltq_m_n_u16
#define __builtin_mve_vshlltq_m_n_u8 __builtin_arm_mve_vshlltq_m_n_u8
#define __builtin_mve_vshlltq_n_s16 __builtin_arm_mve_vshlltq_n_s16
#define __builtin_mve_vshlltq_n_s8 __builtin_arm_mve_vshlltq_n_s8
#define __builtin_mve_vshlltq_n_u16 __builtin_arm_mve_vshlltq_n_u16
#define __builtin_mve_vshlltq_n_u8 __builtin_arm_mve_vshlltq_n_u8
#define __builtin_mve_vshlq_m_n_s16 __builtin_arm_mve_vshlq_m_n_s16
#define __builtin_mve_vshlq_m_n_s32 __builtin_arm_mve_vshlq_m_n_s32
#define __builtin_mve_vshlq_m_n_s8 __builtin_arm_mve_vshlq_m_n_s8
#define __builtin_mve_vshlq_m_n_u16 __builtin_arm_mve_vshlq_m_n_u16
#define __builtin_mve_vshlq_m_n_u32 __builtin_arm_mve_vshlq_m_n_u32
#define __builtin_mve_vshlq_m_n_u8 __builtin_arm_mve_vshlq_m_n_u8
#define __builtin_mve_vshlq_n_s16 __builtin_arm_mve_vshlq_n_s16
#define __builtin_mve_vshlq_n_s32 __builtin_arm_mve_vshlq_n_s32
#define __builtin_mve_vshlq_n_s8 __builtin_arm_mve_vshlq_n_s8
#define __builtin_mve_vshlq_n_u16 __builtin_arm_mve_vshlq_n_u16
#define __builtin_mve_vshlq_n_u32 __builtin_arm_mve_vshlq_n_u32
#define __builtin_mve_vshlq_n_u8 __builtin_arm_mve_vshlq_n_u8
#define __builtin_mve_vshrnbq_m_n_s16 __builtin_arm_mve_vshrnbq_m_n_s16
#define __builtin_mve_vshrnbq_m_n_s32 __builtin_arm_mve_vshrnbq_m_n_s32
#define __builtin_mve_vshrnbq_m_n_u16 __builtin_arm_mve_vshrnbq_m_n_u16
#define __builtin_mve_vshrnbq_m_n_u32 __builtin_arm_mve_vshrnbq_m_n_u32
#define __builtin_mve_vshrnbq_n_s16 __builtin_arm_mve_vshrnbq_n_s16
#define __builtin_mve_vshrnbq_n_s32 __builtin_arm_mve_vshrnbq_n_s32
#define __builtin_mve_vshrnbq_n_u16 __builtin_arm_mve_vshrnbq_n_u16
#define __builtin_mve_vshrnbq_n_u32 __builtin_arm_mve_vshrnbq_n_u32
#define __builtin_mve_vshrntq_m_n_s16 __builtin_arm_mve_vshrntq_m_n_s16
#define __builtin_mve_vshrntq_m_n_s32 __builtin_arm_mve_vshrntq_m_n_s32
#define __builtin_mve_vshrntq_m_n_u16 __builtin_arm_mve_vshrntq_m_n_u16
#define __builtin_mve_vshrntq_m_n_u32 __builtin_arm_mve_vshrntq_m_n_u32
#define __builtin_mve_vshrntq_n_s16 __builtin_arm_mve_vshrntq_n_s16
#define __builtin_mve_vshrntq_n_s32 __builtin_arm_mve_vshrntq_n_s32
#define __builtin_mve_vshrntq_n_u16 __builtin_arm_mve_vshrntq_n_u16
#define __builtin_mve_vshrntq_n_u32 __builtin_arm_mve_vshrntq_n_u32
#define __builtin_mve_vshrq_m_n_s16 __builtin_arm_mve_vshrq_m_n_s16
#define __builtin_mve_vshrq_m_n_s32 __builtin_arm_mve_vshrq_m_n_s32
#define __builtin_mve_vshrq_m_n_s8 __builtin_arm_mve_vshrq_m_n_s8
#define __builtin_mve_vshrq_m_n_u16 __builtin_arm_mve_vshrq_m_n_u16
#define __builtin_mve_vshrq_m_n_u32 __builtin_arm_mve_vshrq_m_n_u32
#define __builtin_mve_vshrq_m_n_u8 __builtin_arm_mve_vshrq_m_n_u8
#define __builtin_mve_vshrq_n_s16 __builtin_arm_mve_vshrq_n_s16
#define __builtin_mve_vshrq_n_s32 __builtin_arm_mve_vshrq_n_s32
#define __builtin_mve_vshrq_n_s8 __builtin_arm_mve_vshrq_n_s8
#define __builtin_mve_vshrq_n_u16 __builtin_arm_mve_vshrq_n_u16
#define __builtin_mve_vshrq_n_u32 __builtin_arm_mve_vshrq_n_u32
#define __builtin_mve_vshrq_n_u8 __builtin_arm_mve_vshrq_n_u8
#define __builtin_mve_vsliq_m_n_s16 __builtin_arm_mve_vsliq_m_n_s16
#define __builtin_mve_vsliq_m_n_s32 __builtin_arm_mve_vsliq_m_n_s32
#define __builtin_mve_vsliq_m_n_s8 __builtin_arm_mve_vsliq_m_n_s8
#define __builtin_mve_vsliq_m_n_u16 __builtin_arm_mve_vsliq_m_n_u16
#define __builtin_mve_vsliq_m_n_u32 __builtin_arm_mve_vsliq_m_n_u32
#define __builtin_mve_vsliq_m_n_u8 __builtin_arm_mve_vsliq_m_n_u8
#define __builtin_mve_vsliq_n_s16 __builtin_arm_mve_vsliq_n_s16
#define __builtin_mve_vsliq_n_s32 __builtin_arm_mve_vsliq_n_s32
#define __builtin_mve_vsliq_n_s8 __builtin_arm_mve_vsliq_n_s8
#define __builtin_mve_vsliq_n_u16 __builtin_arm_mve_vsliq_n_u16
#define __builtin_mve_vsliq_n_u32 __builtin_arm_mve_vsliq_n_u32
#define __builtin_mve_vsliq_n_u8 __builtin_arm_mve_vsliq_n_u8
#define __builtin_mve_vsriq_m_n_s16 __builtin_arm_mve_vsriq_m_n_s16
#define __builtin_mve_vsriq_m_n_s32 __builtin_arm_mve_vsriq_m_n_s32
#define __builtin_mve_vsriq_m_n_s8 __builtin_arm_mve_vsriq_m_n_s8
#define __builtin_mve_vsriq_m_n_u16 __builtin_arm_mve_vsriq_m_n_u16
#define __builtin_mve_vsriq_m_n_u32 __builtin_arm_mve_vsriq_m_n_u32
#define __builtin_mve_vsriq_m_n_u8 __builtin_arm_mve_vsriq_m_n_u8
#define __builtin_mve_vsriq_n_s16 __builtin_arm_mve_vsriq_n_s16
#define __builtin_mve_vsriq_n_s32 __builtin_arm_mve_vsriq_n_s32
#define __builtin_mve_vsriq_n_s8 __builtin_arm_mve_vsriq_n_s8
#define __builtin_mve_vsriq_n_u16 __builtin_arm_mve_vsriq_n_u16
#define __builtin_mve_vsriq_n_u32 __builtin_arm_mve_vsriq_n_u32
#define __builtin_mve_vsriq_n_u8 __builtin_arm_mve_vsriq_n_u8
#define __builtin_mve_vstrdq_scatter_base_p_s64 __builtin_arm_mve_vstrdq_scatter_base_p_s64
#define __builtin_mve_vstrdq_scatter_base_p_u64 __builtin_arm_mve_vstrdq_scatter_base_p_u64
#define __builtin_mve_vstrdq_scatter_base_s64 __builtin_arm_mve_vstrdq_scatter_base_s64
#define __builtin_mve_vstrdq_scatter_base_u64 __builtin_arm_mve_vstrdq_scatter_base_u64
#define __builtin_mve_vstrdq_scatter_base_wb_p_s64 __builtin_arm_mve_vstrdq_scatter_base_wb_p_s64
#define __builtin_mve_vstrdq_scatter_base_wb_p_u64 __builtin_arm_mve_vstrdq_scatter_base_wb_p_u64
#define __builtin_mve_vstrdq_scatter_base_wb_s64 __builtin_arm_mve_vstrdq_scatter_base_wb_s64
#define __builtin_mve_vstrdq_scatter_base_wb_u64 __builtin_arm_mve_vstrdq_scatter_base_wb_u64
#define __builtin_mve_vstrwq_scatter_base_f32 __builtin_arm_mve_vstrwq_scatter_base_f32
#define __builtin_mve_vstrwq_scatter_base_p_f32 __builtin_arm_mve_vstrwq_scatter_base_p_f32
#define __builtin_mve_vstrwq_scatter_base_p_s32 __builtin_arm_mve_vstrwq_scatter_base_p_s32
#define __builtin_mve_vstrwq_scatter_base_p_u32 __builtin_arm_mve_vstrwq_scatter_base_p_u32
#define __builtin_mve_vstrwq_scatter_base_s32 __builtin_arm_mve_vstrwq_scatter_base_s32
#define __builtin_mve_vstrwq_scatter_base_u32 __builtin_arm_mve_vstrwq_scatter_base_u32
#define __builtin_mve_vstrwq_scatter_base_wb_f32 __builtin_arm_mve_vstrwq_scatter_base_wb_f32
#define __builtin_mve_vstrwq_scatter_base_wb_p_f32 __builtin_arm_mve_vstrwq_scatter_base_wb_p_f32
#define __builtin_mve_vstrwq_scatter_base_wb_p_s32 __builtin_arm_mve_vstrwq_scatter_base_wb_p_s32
#define __builtin_mve_vstrwq_scatter_base_wb_p_u32 __builtin_arm_mve_vstrwq_scatter_base_wb_p_u32
#define __builtin_mve_vstrwq_scatter_base_wb_s32 __builtin_arm_mve_vstrwq_scatter_base_wb_s32
#define __builtin_mve_vstrwq_scatter_base_wb_u32 __builtin_arm_mve_vstrwq_scatter_base_wb_u32
#endif /* __arm__ */



/*************************************
 ************ Clang 15.0 *************
 *************************************/
#if (__cov_clang_version_lt(15, 0)) /* { */
/* Signatures removed in Clang 15.0 { */
extern unsigned int __attribute__((vector_size(16)))
__coverity___builtin_altivec_vec_replace_elt(
    unsigned int __attribute__((vector_size(16))) __a,
    unsigned int __b,
    const int __c);
#define __builtin_altivec_vec_replace_elt(P0, P1, P2) \
    __coverity___builtin_altivec_vec_replace_elt((P0), (P1), (P2))

extern unsigned int __attribute__((vector_size(16)))
__coverity___builtin_altivec_vec_replace_unaligned(
    unsigned int __attribute__((vector_size(16))) __a,
    unsigned int __b,
    const int __c);
#define __builtin_altivec_vec_replace_unaligned(P0, P1, P2) \
    __coverity___builtin_altivec_vec_replace_unaligned((P0), (P1), (P2))

extern char __attribute__((vector_size(16)))
__coverity___builtin_ia32_paddsb128(
    char __attribute__((vector_size(16))) __a,
    char __attribute__((vector_size(16))) __b);
#define __builtin_ia32_paddsb128(P0, P1) \
    __coverity___builtin_ia32_paddsb128((P0), (P1))

extern char __attribute__((vector_size(32)))
__coverity___builtin_ia32_paddsb256(
    char __attribute__((vector_size(32))) __a,
    char __attribute__((vector_size(32))) __b);
#define __builtin_ia32_paddsb256(P0, P1) \
    __coverity___builtin_ia32_paddsb256((P0), (P1))

extern char __attribute__((vector_size(64)))
__coverity___builtin_ia32_paddsb512(
    char __attribute__((vector_size(64))) __a,
    char __attribute__((vector_size(64))) __b);
#define __builtin_ia32_paddsb512(P0, P1) \
    __coverity___builtin_ia32_paddsb512((P0), (P1))

extern short __attribute__((vector_size(16)))
__coverity___builtin_ia32_paddsw128(
    short __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b);
#define __builtin_ia32_paddsw128(P0, P1) \
    __coverity___builtin_ia32_paddsw128((P0), (P1))

extern short __attribute__((vector_size(32)))
__coverity___builtin_ia32_paddsw256(
    short __attribute__((vector_size(32))) __a,
    short __attribute__((vector_size(32))) __b);
#define __builtin_ia32_paddsw256(P0, P1) \
    __coverity___builtin_ia32_paddsw256((P0), (P1))

extern short __attribute__((vector_size(64)))
__coverity___builtin_ia32_paddsw512(
    short __attribute__((vector_size(64))) __a,
    short __attribute__((vector_size(64))) __b);
#define __builtin_ia32_paddsw512(P0, P1) \
    __coverity___builtin_ia32_paddsw512((P0), (P1))

extern char __attribute__((vector_size(16)))
__coverity___builtin_ia32_paddusb128(
    char __attribute__((vector_size(16))) __a,
    char __attribute__((vector_size(16))) __b);
#define __builtin_ia32_paddusb128(P0, P1) \
    __coverity___builtin_ia32_paddusb128((P0), (P1))

extern char __attribute__((vector_size(32)))
__coverity___builtin_ia32_paddusb256(
    char __attribute__((vector_size(32))) __a,
    char __attribute__((vector_size(32))) __b);
#define __builtin_ia32_paddusb256(P0, P1) \
    __coverity___builtin_ia32_paddusb256((P0), (P1))

extern char __attribute__((vector_size(64)))
__coverity___builtin_ia32_paddusb512(
    char __attribute__((vector_size(64))) __a,
    char __attribute__((vector_size(64))) __b);
#define __builtin_ia32_paddusb512(P0, P1) \
    __coverity___builtin_ia32_paddusb512((P0), (P1))

extern short __attribute__((vector_size(16)))
__coverity___builtin_ia32_paddusw128(
    short __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b);
#define __builtin_ia32_paddusw128(P0, P1) \
    __coverity___builtin_ia32_paddusw128((P0), (P1))

extern short __attribute__((vector_size(32)))
__coverity___builtin_ia32_paddusw256(
    short __attribute__((vector_size(32))) __a,
    short __attribute__((vector_size(32))) __b);
#define __builtin_ia32_paddusw256(P0, P1) \
    __coverity___builtin_ia32_paddusw256((P0), (P1))

extern short __attribute__((vector_size(64)))
__coverity___builtin_ia32_paddusw512(
    short __attribute__((vector_size(64))) __a,
    short __attribute__((vector_size(64))) __b);
#define __builtin_ia32_paddusw512(P0, P1) \
    __coverity___builtin_ia32_paddusw512((P0), (P1))

extern char __attribute__((vector_size(16)))
__coverity___builtin_ia32_psubsb128(
    char __attribute__((vector_size(16))) __a,
    char __attribute__((vector_size(16))) __b);
#define __builtin_ia32_psubsb128(P0, P1) \
    __coverity___builtin_ia32_psubsb128((P0), (P1))

extern char __attribute__((vector_size(32)))
__coverity___builtin_ia32_psubsb256(
    char __attribute__((vector_size(32))) __a,
    char __attribute__((vector_size(32))) __b);
#define __builtin_ia32_psubsb256(P0, P1) \
    __coverity___builtin_ia32_psubsb256((P0), (P1))

extern char __attribute__((vector_size(64)))
__coverity___builtin_ia32_psubsb512(
    char __attribute__((vector_size(64))) __a,
    char __attribute__((vector_size(64))) __b);
#define __builtin_ia32_psubsb512(P0, P1) \
    __coverity___builtin_ia32_psubsb512((P0), (P1))

extern short __attribute__((vector_size(16)))
__coverity___builtin_ia32_psubsw128(
    short __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b);
#define __builtin_ia32_psubsw128(P0, P1) \
    __coverity___builtin_ia32_psubsw128((P0), (P1))

extern short __attribute__((vector_size(32)))
__coverity___builtin_ia32_psubsw256(
    short __attribute__((vector_size(32))) __a,
    short __attribute__((vector_size(32))) __b);
#define __builtin_ia32_psubsw256(P0, P1) \
    __coverity___builtin_ia32_psubsw256((P0), (P1))

extern short __attribute__((vector_size(64)))
__coverity___builtin_ia32_psubsw512(
    short __attribute__((vector_size(64))) __a,
    short __attribute__((vector_size(64))) __b);
#define __builtin_ia32_psubsw512(P0, P1) \
    __coverity___builtin_ia32_psubsw512((P0), (P1))

extern char __attribute__((vector_size(16)))
__coverity___builtin_ia32_psubusb128(
    char __attribute__((vector_size(16))) __a,
    char __attribute__((vector_size(16))) __b);
#define __builtin_ia32_psubusb128(P0, P1) \
    __coverity___builtin_ia32_psubusb128((P0), (P1))

extern char __attribute__((vector_size(32)))
__coverity___builtin_ia32_psubusb256(
    char __attribute__((vector_size(32))) __a,
    char __attribute__((vector_size(32))) __b);
#define __builtin_ia32_psubusb256(P0, P1) \
    __coverity___builtin_ia32_psubusb256((P0), (P1))

extern char __attribute__((vector_size(64)))
__coverity___builtin_ia32_psubusb512(
    char __attribute__((vector_size(64))) __a,
    char __attribute__((vector_size(64))) __b);
#define __builtin_ia32_psubusb512(P0, P1) \
    __coverity___builtin_ia32_psubusb512((P0), (P1))

extern short __attribute__((vector_size(16)))
__coverity___builtin_ia32_psubusw128(
    short __attribute__((vector_size(16))) __a,
    short __attribute__((vector_size(16))) __b);
#define __builtin_ia32_psubusw128(P0, P1) \
    __coverity___builtin_ia32_psubusw128((P0), (P1))

extern short __attribute__((vector_size(32)))
__coverity___builtin_ia32_psubusw256(
    short __attribute__((vector_size(32))) __a,
    short __attribute__((vector_size(32))) __b);
#define __builtin_ia32_psubusw256(P0, P1) \
    __coverity___builtin_ia32_psubusw256((P0), (P1))

extern short __attribute__((vector_size(64)))
__coverity___builtin_ia32_psubusw512(
    short __attribute__((vector_size(64))) __a,
    short __attribute__((vector_size(64))) __b);
#define __builtin_ia32_psubusw512(P0, P1) \
    __coverity___builtin_ia32_psubusw512((P0), (P1))

extern int
__coverity___builtin_ia32_reduce_add_d512(
    int __attribute__((vector_size(64))) __a);
#define __builtin_ia32_reduce_add_d512(P0) \
    __coverity___builtin_ia32_reduce_add_d512((P0))

extern long long int
__coverity__builtin_ia32_reduce_add_q512(
     long long int __attribute__((vector_size(64))) __a);
#define __builtin_ia32_reduce_add_q512(P0) \
    __coverity__builtin_ia32_reduce_add_q512((P0))

extern int
__coverity___builtin_ia32_reduce_mul_d512(
    int __attribute__((vector_size(64))) __a);
#define __builtin_ia32_reduce_mul_d512(P0) \
    __coverity___builtin_ia32_reduce_mul_d512((P0))

extern long long int
__coverity__builtin_ia32_reduce_mul_q512(
     long long int __attribute__((vector_size(64))) __a);
#define __builtin_ia32_reduce_mul_q512(P0) \
    __coverity__builtin_ia32_reduce_mul_q512((P0))

extern int __attribute__((vector_size(16)))
__coverity___builtin_wasm_relaxed_trunc_zero_s_i32x4_f64x2(
    double __attribute__((vector_size(16))) __a);
#define __builtin_wasm_relaxed_trunc_zero_s_i32x4_f64x2(P0) \
    __coverity___builtin_wasm_relaxed_trunc_zero_s_i32x4_f64x2((P0))

extern unsigned int __attribute__((vector_size(16)))
__coverity___builtin_wasm_relaxed_trunc_zero_u_i32x4_f64x2(
    double __attribute__((vector_size(16))) __a);
#define __builtin_wasm_relaxed_trunc_zero_u_i32x4_f64x2(P0) \
    __coverity___builtin_wasm_relaxed_trunc_zero_u_i32x4_f64x2((P0))

extern int __attribute__((vector_size(16)))
__coverity___builtin_wasm_trunc_sat_zero_s_f64x2_i32x4(
    double __attribute__((vector_size(16))) __a);
#define __builtin_wasm_trunc_sat_zero_s_f64x2_i32x4(P0) \
    __coverity___builtin_wasm_trunc_sat_zero_s_f64x2_i32x4((P0))

extern unsigned int __attribute__((vector_size(16)))
__coverity___builtin_wasm_trunc_sat_zero_u_f64x2_i32x4(
    double __attribute__((vector_size(16))) __a);
#define __builtin_wasm_trunc_sat_zero_u_f64x2_i32x4(P0) \
    __coverity___builtin_wasm_trunc_sat_zero_u_f64x2_i32x4((P0))
/* } Removed in Clang 15 */

/* Apple Clang 14.0 (Clang 15.0) */
#if (__coverity_assume_xcode__ ) /* { */
/* Added in Apple Clang 14 { */
// Use vector 8 unsigned int to emulate vbool8_t
extern unsigned int __attribute__((vector_size(8)))
__coverity___builtin_rvv_vmandnot_mm();
#define __builtin_rvv_vmandnot_mm() \
    __coverity___builtin_rvv_vmandnot_mm()

extern unsigned int __attribute__((vector_size(8)))
__coverity___builtin_rvv_vmornot_mm();
#define __builtin_rvv_vmornot_mm() \
    __coverity___builtin_rvv_vmornot_mm()

extern unsigned int __attribute__((vector_size(8)))
__coverity___builtin_rvv_vpopc_m();
#define __builtin_rvv_vpopc_m() \
    __coverity___builtin_rvv_vpopc_m()

extern unsigned int __attribute__((vector_size(8)))
__coverity___builtin_rvv_vpopc_m_m();
#define __builtin_rvv_vpopc_m_m() \
    __coverity___builtin_rvv_vpopc_m_m()
/* } Added in Apple Clang 14 */

/* Changed in Apple Clang 14 { */
extern unsigned int
__coverity___builtin_ppc_fetch_and_add(
    volatile unsigned int* __a,
    unsigned int __b);
#define __builtin_ppc_fetch_and_add(P0, P1) \
    __coverity___builtin_ppc_fetch_and_add((P0), (P1))

extern unsigned long
__coverity___builtin_ppc_fetch_and_addlp(
    volatile unsigned long* __a,
    unsigned long __b);
#define __builtin_ppc_fetch_and_addlp(P0, P1) \
    __coverity___builtin_ppc_fetch_and_addlp((P0), (P1))
/* } Changed in Apple Clang 14 */

/* } */
#endif // Apple Clang < 14.0

#endif /* Clang 15 */



/*************************************
 ************ Clang 16.0 *************
 *************************************/
#if (__cov_clang_version_lt(16, 0)) /* { */
extern unsigned long long int __attribute__((vector_size(16)))
__coverity__builtin_altivec_crypto_vcipher(
    unsigned long long int __attribute__((vector_size(16))) __a,
    unsigned long long int __attribute__((vector_size(16))) __b);
#define __builtin_altivec_crypto_vcipher(P0, P1) \
    __coverity__builtin_altivec_crypto_vcipher((P0), (P1))

extern unsigned long long int __attribute__((vector_size(16)))
__coverity__builtin_altivec_crypto_vcipherlast(
    unsigned long long int __attribute__((vector_size(16))) __a,
    unsigned long long int __attribute__((vector_size(16))) __b);
#define __builtin_altivec_crypto_vcipherlast(P0, P1) \
    __coverity__builtin_altivec_crypto_vcipherlast((P0), (P1))

extern unsigned long long int __attribute__((vector_size(16)))
__coverity__builtin_altivec_crypto_vncipher(
    unsigned long long int __attribute__((vector_size(16))) __a,
    unsigned long long int __attribute__((vector_size(16))) __b);
#define __builtin_altivec_crypto_vncipher(P0, P1) \
    __coverity__builtin_altivec_crypto_vncipher((P0), (P1))

extern unsigned long long int __attribute__((vector_size(16)))
__coverity__builtin_altivec_crypto_vncipherlast(
    unsigned long long int __attribute__((vector_size(16))) __a,
    unsigned long long int __attribute__((vector_size(16))) __b);
#define __builtin_altivec_crypto_vncipherlast(P0, P1) \
    __coverity__builtin_altivec_crypto_vncipherlast((P0), (P1))

extern unsigned long long int __attribute__((vector_size(16)))
__coverity__builtin_altivec_crypto_vsbox(
    unsigned long long int __attribute__((vector_size(16))) __a);
#define __builtin_altivec_crypto_vsbox(P0) \
    __coverity__builtin_altivec_crypto_vsbox((P0))

extern  short __attribute__((vector_size(16)))
__coverity__builtin_ia32_cvtneps2bf16_128_mask(
     float __attribute__((vector_size(16))) __a,
     short __attribute__((vector_size(16))) __b,
    unsigned char __c);
#define __builtin_ia32_cvtneps2bf16_128_mask(P0, P1, P2) \
    __coverity__builtin_ia32_cvtneps2bf16_128_mask((P0), (P1), (P2))

extern  short __attribute__((vector_size(16)))
__coverity__builtin_ia32_cvtneps2bf16_256_mask(
     float __attribute__((vector_size(32))) __a,
     short __attribute__((vector_size(16))) __b,
    unsigned char __c);
#define __builtin_ia32_cvtneps2bf16_256_mask(P0, P1, P2) \
    __coverity__builtin_ia32_cvtneps2bf16_256_mask((P0), (P1), (P2))

extern  short __attribute__((vector_size(32)))
__coverity__builtin_ia32_cvtneps2bf16_512_mask(
     float __attribute__((vector_size(64))) __a,
     short __attribute__((vector_size(32))) __b,
    unsigned short __c);
#define __builtin_ia32_cvtneps2bf16_512_mask(P0, P1, P2) \
    __coverity__builtin_ia32_cvtneps2bf16_512_mask((P0), (P1), (P2))

extern float
__coverity__builtin_ia32_cvtsbf162ss_32(
    unsigned short __a);
#define __builtin_ia32_cvtsbf162ss_32(P0) \
    __coverity__builtin_ia32_cvtsbf162ss_32((P0))

extern  float __attribute__((vector_size(16)))
__coverity__builtin_ia32_dpbf16ps_128(
     float __attribute__((vector_size(16))) __a,
     int __attribute__((vector_size(16))) __b,
     int __attribute__((vector_size(16))) __c);
#define __builtin_ia32_dpbf16ps_128(P0, P1, P2) \
    __coverity__builtin_ia32_dpbf16ps_128((P0), (P1), (P2))

extern  float __attribute__((vector_size(32)))
__coverity__builtin_ia32_dpbf16ps_256(
     float __attribute__((vector_size(32))) __a,
     int __attribute__((vector_size(32))) __b,
     int __attribute__((vector_size(32))) __c);
#define __builtin_ia32_dpbf16ps_256(P0, P1, P2) \
    __coverity__builtin_ia32_dpbf16ps_256((P0), (P1), (P2))

extern  float __attribute__((vector_size(64)))
__coverity__builtin_ia32_dpbf16ps_512(
     float __attribute__((vector_size(64))) __a,
     int __attribute__((vector_size(64))) __b,
     int __attribute__((vector_size(64))) __c);
#define __builtin_ia32_dpbf16ps_512(P0, P1, P2) \
    __coverity__builtin_ia32_dpbf16ps_512((P0), (P1), (P2))

extern  float __attribute__((vector_size(16)))
__coverity__builtin_ia32_cvtne2ps2bf16_128(
     float __attribute__((vector_size(16))) __a,
     float __attribute__((vector_size(16))) __b);
#define __builtin_ia32_cvtne2ps2bf16_128(P0, P1) \
    __coverity__builtin_ia32_cvtne2ps2bf16_128((P0), (P1))

extern  float __attribute__((vector_size(32)))
__coverity__builtin_ia32_cvtne2ps2bf16_256(
     float __attribute__((vector_size(32))) __a,
     float __attribute__((vector_size(32))) __b);
#define __builtin_ia32_cvtne2ps2bf16_256(P0, P1) \
    __coverity__builtin_ia32_cvtne2ps2bf16_256((P0), (P1))

extern  float __attribute__((vector_size(64)))
__coverity__builtin_ia32_cvtne2ps2bf16_512(
     float __attribute__((vector_size(64))) __a,
     float __attribute__((vector_size(64))) __b);
#define __builtin_ia32_cvtne2ps2bf16_512(P0, P1) \
    __coverity__builtin_ia32_cvtne2ps2bf16_512((P0), (P1))


/* Apple Clang 14.3 (Clang 16.0) */
#if (__coverity_assume_xcode__ ) /* { */
// To be updated in CMPCPP-13233
#endif // Apple Clang < 14.3
#endif /* Clang 16 */

#if defined(__cplusplus)
} /* extern "C" */
#endif


/*************************************
 ************ Clang 17.0 *************
 *************************************/
#if (__cov_clang_version_lt(17, 0)) /* { */
extern double
__coverity__builtin_roundeven(
    double __a);
#define __builtin_roundeven(P0) \
    __coverity__builtin_roundeven((P0))

extern float
__coverity__builtin_roundevenf(
    float __a);
#define __builtin_roundevenf(P0) \
    __coverity__builtin_roundevenf((P0))

extern long long int
__coverity__builtin_roundevenl(
    double __a);
#define __builtin_roundevenl(P0) \
    __coverity__builtin_roundevenl((P0))
#endif /* Clang 17 */


#endif /* COVERITY_COMPAT_444796f5c87569ee11c7bd44b5db7139 */
#endif /* __COVERITY__ */
