﻿
#if !(defined(IBAction) || defined(__coverity_undefine_IBAction))
#define IBAction void)__attribute__((ibaction)
#endif
#if !(defined(IBInspectable) || defined(__coverity_undefine_IBInspectable))
#define IBInspectable 
#endif
#if !(defined(IBOutlet) || defined(__coverity_undefine_IBOutlet))
#define IBOutlet __attribute__((iboutlet))
#endif
#if !(defined(IBOutletCollection) || defined(__coverity_undefine_IBOutletCollection))
#define IBOutletCollection(ClassName) __attribute__((iboutletcollection(ClassName)))
#endif
#if !(defined(IB_DESIGNABLE) || defined(__coverity_undefine_IB_DESIGNABLE))
#define IB_DESIGNABLE 
#endif
#if !(defined(OBJC_NEW_PROPERTIES) || defined(__coverity_undefine_OBJC_NEW_PROPERTIES))
#define OBJC_NEW_PROPERTIES 1
#endif
#if !(defined(WIN32) || defined(__coverity_undefine_WIN32))
#define WIN32 1
#endif
#if !(defined(WIN64) || defined(__coverity_undefine_WIN64))
#define WIN64 1
#endif
#if !(defined(WINNT) || defined(__coverity_undefine_WINNT))
#define WINNT 1
#endif
#if !(defined(_WIN32) || defined(__coverity_undefine__WIN32))
#define _WIN32 1
#endif
#if !(defined(_WIN64) || defined(__coverity_undefine__WIN64))
#define _WIN64 1
#endif
#if !(defined(__ATOMIC_ACQUIRE) || defined(__coverity_undefine___ATOMIC_ACQUIRE))
#define __ATOMIC_ACQUIRE 2
#endif
#if !(defined(__ATOMIC_ACQ_REL) || defined(__coverity_undefine___ATOMIC_ACQ_REL))
#define __ATOMIC_ACQ_REL 4
#endif
#if !(defined(__ATOMIC_CONSUME) || defined(__coverity_undefine___ATOMIC_CONSUME))
#define __ATOMIC_CONSUME 1
#endif
#if !(defined(__ATOMIC_RELAXED) || defined(__coverity_undefine___ATOMIC_RELAXED))
#define __ATOMIC_RELAXED 0
#endif
#if !(defined(__ATOMIC_RELEASE) || defined(__coverity_undefine___ATOMIC_RELEASE))
#define __ATOMIC_RELEASE 3
#endif
#if !(defined(__ATOMIC_SEQ_CST) || defined(__coverity_undefine___ATOMIC_SEQ_CST))
#define __ATOMIC_SEQ_CST 5
#endif
#if !(defined(__BIGGEST_ALIGNMENT__) || defined(__coverity_undefine___BIGGEST_ALIGNMENT__))
#define __BIGGEST_ALIGNMENT__ 16
#endif
#if !(defined(__BITINT_MAXWIDTH__) || defined(__coverity_undefine___BITINT_MAXWIDTH__))
#define __BITINT_MAXWIDTH__ 8388608
#endif
#if !(defined(__BOOL_WIDTH__) || defined(__coverity_undefine___BOOL_WIDTH__))
#define __BOOL_WIDTH__ 8
#endif
#if !(defined(__BYTE_ORDER__) || defined(__coverity_undefine___BYTE_ORDER__))
#define __BYTE_ORDER__ __ORDER_LITTLE_ENDIAN__
#endif
#if !(defined(__CHAR16_TYPE__) || defined(__coverity_undefine___CHAR16_TYPE__))
#define __CHAR16_TYPE__ unsigned short
#endif
#if !(defined(__CHAR32_TYPE__) || defined(__coverity_undefine___CHAR32_TYPE__))
#define __CHAR32_TYPE__ unsigned int
#endif
#if !(defined(__CHAR_BIT__) || defined(__coverity_undefine___CHAR_BIT__))
#define __CHAR_BIT__ 8
#endif
#if !(defined(__CLANG_ATOMIC_BOOL_LOCK_FREE) || defined(__coverity_undefine___CLANG_ATOMIC_BOOL_LOCK_FREE))
#define __CLANG_ATOMIC_BOOL_LOCK_FREE 2
#endif
#if !(defined(__CLANG_ATOMIC_CHAR16_T_LOCK_FREE) || defined(__coverity_undefine___CLANG_ATOMIC_CHAR16_T_LOCK_FREE))
#define __CLANG_ATOMIC_CHAR16_T_LOCK_FREE 2
#endif
#if !(defined(__CLANG_ATOMIC_CHAR32_T_LOCK_FREE) || defined(__coverity_undefine___CLANG_ATOMIC_CHAR32_T_LOCK_FREE))
#define __CLANG_ATOMIC_CHAR32_T_LOCK_FREE 2
#endif
#if !(defined(__CLANG_ATOMIC_CHAR_LOCK_FREE) || defined(__coverity_undefine___CLANG_ATOMIC_CHAR_LOCK_FREE))
#define __CLANG_ATOMIC_CHAR_LOCK_FREE 2
#endif
#if !(defined(__CLANG_ATOMIC_INT_LOCK_FREE) || defined(__coverity_undefine___CLANG_ATOMIC_INT_LOCK_FREE))
#define __CLANG_ATOMIC_INT_LOCK_FREE 2
#endif
#if !(defined(__CLANG_ATOMIC_LLONG_LOCK_FREE) || defined(__coverity_undefine___CLANG_ATOMIC_LLONG_LOCK_FREE))
#define __CLANG_ATOMIC_LLONG_LOCK_FREE 2
#endif
#if !(defined(__CLANG_ATOMIC_LONG_LOCK_FREE) || defined(__coverity_undefine___CLANG_ATOMIC_LONG_LOCK_FREE))
#define __CLANG_ATOMIC_LONG_LOCK_FREE 2
#endif
#if !(defined(__CLANG_ATOMIC_POINTER_LOCK_FREE) || defined(__coverity_undefine___CLANG_ATOMIC_POINTER_LOCK_FREE))
#define __CLANG_ATOMIC_POINTER_LOCK_FREE 2
#endif
#if !(defined(__CLANG_ATOMIC_SHORT_LOCK_FREE) || defined(__coverity_undefine___CLANG_ATOMIC_SHORT_LOCK_FREE))
#define __CLANG_ATOMIC_SHORT_LOCK_FREE 2
#endif
#if !(defined(__CLANG_ATOMIC_WCHAR_T_LOCK_FREE) || defined(__coverity_undefine___CLANG_ATOMIC_WCHAR_T_LOCK_FREE))
#define __CLANG_ATOMIC_WCHAR_T_LOCK_FREE 2
#endif
#if !(defined(__CONSTANT_CFSTRINGS__) || defined(__coverity_undefine___CONSTANT_CFSTRINGS__))
#define __CONSTANT_CFSTRINGS__ 1
#endif
#if !(defined(__DBL_DECIMAL_DIG__) || defined(__coverity_undefine___DBL_DECIMAL_DIG__))
#define __DBL_DECIMAL_DIG__ 17
#endif
#if !(defined(__DBL_DENORM_MIN__) || defined(__coverity_undefine___DBL_DENORM_MIN__))
#define __DBL_DENORM_MIN__ 4.9406564584124654e-324
#endif
#if !(defined(__DBL_DIG__) || defined(__coverity_undefine___DBL_DIG__))
#define __DBL_DIG__ 15
#endif
#if !(defined(__DBL_EPSILON__) || defined(__coverity_undefine___DBL_EPSILON__))
#define __DBL_EPSILON__ 2.2204460492503131e-16
#endif
#if !(defined(__DBL_HAS_DENORM__) || defined(__coverity_undefine___DBL_HAS_DENORM__))
#define __DBL_HAS_DENORM__ 1
#endif
#if !(defined(__DBL_HAS_INFINITY__) || defined(__coverity_undefine___DBL_HAS_INFINITY__))
#define __DBL_HAS_INFINITY__ 1
#endif
#if !(defined(__DBL_HAS_QUIET_NAN__) || defined(__coverity_undefine___DBL_HAS_QUIET_NAN__))
#define __DBL_HAS_QUIET_NAN__ 1
#endif
#if !(defined(__DBL_MANT_DIG__) || defined(__coverity_undefine___DBL_MANT_DIG__))
#define __DBL_MANT_DIG__ 53
#endif
#if !(defined(__DBL_MAX_10_EXP__) || defined(__coverity_undefine___DBL_MAX_10_EXP__))
#define __DBL_MAX_10_EXP__ 308
#endif
#if !(defined(__DBL_MAX_EXP__) || defined(__coverity_undefine___DBL_MAX_EXP__))
#define __DBL_MAX_EXP__ 1024
#endif
#if !(defined(__DBL_MAX__) || defined(__coverity_undefine___DBL_MAX__))
#define __DBL_MAX__ 1.7976931348623157e+308
#endif
#if !(defined(__DBL_MIN_10_EXP__) || defined(__coverity_undefine___DBL_MIN_10_EXP__))
#define __DBL_MIN_10_EXP__ (-307)
#endif
#if !(defined(__DBL_MIN_EXP__) || defined(__coverity_undefine___DBL_MIN_EXP__))
#define __DBL_MIN_EXP__ (-1021)
#endif
#if !(defined(__DBL_MIN__) || defined(__coverity_undefine___DBL_MIN__))
#define __DBL_MIN__ 2.2250738585072014e-308
#endif
#if !(defined(__DECIMAL_DIG__) || defined(__coverity_undefine___DECIMAL_DIG__))
#define __DECIMAL_DIG__ __LDBL_DECIMAL_DIG__
#endif
#if !(defined(__DEPRECATED) || defined(__coverity_undefine___DEPRECATED))
#define __DEPRECATED 1
#endif
#if !(defined(__EXCEPTIONS) || defined(__coverity_undefine___EXCEPTIONS))
#define __EXCEPTIONS 1
#endif
#if !(defined(__FINITE_MATH_ONLY__) || defined(__coverity_undefine___FINITE_MATH_ONLY__))
#define __FINITE_MATH_ONLY__ 0
#endif
#if !(defined(__FLT16_DECIMAL_DIG__) || defined(__coverity_undefine___FLT16_DECIMAL_DIG__))
#define __FLT16_DECIMAL_DIG__ 5
#endif
#if !(defined(__FLT16_DENORM_MIN__) || defined(__coverity_undefine___FLT16_DENORM_MIN__))
#define __FLT16_DENORM_MIN__ 5.9604644775390625e-8F16
#endif
#if !(defined(__FLT16_DIG__) || defined(__coverity_undefine___FLT16_DIG__))
#define __FLT16_DIG__ 3
#endif
#if !(defined(__FLT16_EPSILON__) || defined(__coverity_undefine___FLT16_EPSILON__))
#define __FLT16_EPSILON__ 9.765625e-4F16
#endif
#if !(defined(__FLT16_HAS_DENORM__) || defined(__coverity_undefine___FLT16_HAS_DENORM__))
#define __FLT16_HAS_DENORM__ 1
#endif
#if !(defined(__FLT16_HAS_INFINITY__) || defined(__coverity_undefine___FLT16_HAS_INFINITY__))
#define __FLT16_HAS_INFINITY__ 1
#endif
#if !(defined(__FLT16_HAS_QUIET_NAN__) || defined(__coverity_undefine___FLT16_HAS_QUIET_NAN__))
#define __FLT16_HAS_QUIET_NAN__ 1
#endif
#if !(defined(__FLT16_MANT_DIG__) || defined(__coverity_undefine___FLT16_MANT_DIG__))
#define __FLT16_MANT_DIG__ 11
#endif
#if !(defined(__FLT16_MAX_10_EXP__) || defined(__coverity_undefine___FLT16_MAX_10_EXP__))
#define __FLT16_MAX_10_EXP__ 4
#endif
#if !(defined(__FLT16_MAX_EXP__) || defined(__coverity_undefine___FLT16_MAX_EXP__))
#define __FLT16_MAX_EXP__ 16
#endif
#if !(defined(__FLT16_MAX__) || defined(__coverity_undefine___FLT16_MAX__))
#define __FLT16_MAX__ 6.5504e+4F16
#endif
#if !(defined(__FLT16_MIN_10_EXP__) || defined(__coverity_undefine___FLT16_MIN_10_EXP__))
#define __FLT16_MIN_10_EXP__ (-4)
#endif
#if !(defined(__FLT16_MIN_EXP__) || defined(__coverity_undefine___FLT16_MIN_EXP__))
#define __FLT16_MIN_EXP__ (-13)
#endif
#if !(defined(__FLT16_MIN__) || defined(__coverity_undefine___FLT16_MIN__))
#define __FLT16_MIN__ 6.103515625e-5F16
#endif
#if !(defined(__FLT_DECIMAL_DIG__) || defined(__coverity_undefine___FLT_DECIMAL_DIG__))
#define __FLT_DECIMAL_DIG__ 9
#endif
#if !(defined(__FLT_DENORM_MIN__) || defined(__coverity_undefine___FLT_DENORM_MIN__))
#define __FLT_DENORM_MIN__ 1.40129846e-45F
#endif
#if !(defined(__FLT_DIG__) || defined(__coverity_undefine___FLT_DIG__))
#define __FLT_DIG__ 6
#endif
#if !(defined(__FLT_EPSILON__) || defined(__coverity_undefine___FLT_EPSILON__))
#define __FLT_EPSILON__ 1.19209290e-7F
#endif
#if !(defined(__FLT_HAS_DENORM__) || defined(__coverity_undefine___FLT_HAS_DENORM__))
#define __FLT_HAS_DENORM__ 1
#endif
#if !(defined(__FLT_HAS_INFINITY__) || defined(__coverity_undefine___FLT_HAS_INFINITY__))
#define __FLT_HAS_INFINITY__ 1
#endif
#if !(defined(__FLT_HAS_QUIET_NAN__) || defined(__coverity_undefine___FLT_HAS_QUIET_NAN__))
#define __FLT_HAS_QUIET_NAN__ 1
#endif
#if !(defined(__FLT_MANT_DIG__) || defined(__coverity_undefine___FLT_MANT_DIG__))
#define __FLT_MANT_DIG__ 24
#endif
#if !(defined(__FLT_MAX_10_EXP__) || defined(__coverity_undefine___FLT_MAX_10_EXP__))
#define __FLT_MAX_10_EXP__ 38
#endif
#if !(defined(__FLT_MAX_EXP__) || defined(__coverity_undefine___FLT_MAX_EXP__))
#define __FLT_MAX_EXP__ 128
#endif
#if !(defined(__FLT_MAX__) || defined(__coverity_undefine___FLT_MAX__))
#define __FLT_MAX__ 3.40282347e+38F
#endif
#if !(defined(__FLT_MIN_10_EXP__) || defined(__coverity_undefine___FLT_MIN_10_EXP__))
#define __FLT_MIN_10_EXP__ (-37)
#endif
#if !(defined(__FLT_MIN_EXP__) || defined(__coverity_undefine___FLT_MIN_EXP__))
#define __FLT_MIN_EXP__ (-125)
#endif
#if !(defined(__FLT_MIN__) || defined(__coverity_undefine___FLT_MIN__))
#define __FLT_MIN__ 1.17549435e-38F
#endif
#if !(defined(__FLT_RADIX__) || defined(__coverity_undefine___FLT_RADIX__))
#define __FLT_RADIX__ 2
#endif
#if !(defined(__FPCLASS_NEGINF) || defined(__coverity_undefine___FPCLASS_NEGINF))
#define __FPCLASS_NEGINF 0x0004
#endif
#if !(defined(__FPCLASS_NEGNORMAL) || defined(__coverity_undefine___FPCLASS_NEGNORMAL))
#define __FPCLASS_NEGNORMAL 0x0008
#endif
#if !(defined(__FPCLASS_NEGSUBNORMAL) || defined(__coverity_undefine___FPCLASS_NEGSUBNORMAL))
#define __FPCLASS_NEGSUBNORMAL 0x0010
#endif
#if !(defined(__FPCLASS_NEGZERO) || defined(__coverity_undefine___FPCLASS_NEGZERO))
#define __FPCLASS_NEGZERO 0x0020
#endif
#if !(defined(__FPCLASS_POSINF) || defined(__coverity_undefine___FPCLASS_POSINF))
#define __FPCLASS_POSINF 0x0200
#endif
#if !(defined(__FPCLASS_POSNORMAL) || defined(__coverity_undefine___FPCLASS_POSNORMAL))
#define __FPCLASS_POSNORMAL 0x0100
#endif
#if !(defined(__FPCLASS_POSSUBNORMAL) || defined(__coverity_undefine___FPCLASS_POSSUBNORMAL))
#define __FPCLASS_POSSUBNORMAL 0x0080
#endif
#if !(defined(__FPCLASS_POSZERO) || defined(__coverity_undefine___FPCLASS_POSZERO))
#define __FPCLASS_POSZERO 0x0040
#endif
#if !(defined(__FPCLASS_QNAN) || defined(__coverity_undefine___FPCLASS_QNAN))
#define __FPCLASS_QNAN 0x0002
#endif
#if !(defined(__FPCLASS_SNAN) || defined(__coverity_undefine___FPCLASS_SNAN))
#define __FPCLASS_SNAN 0x0001
#endif
#if !(defined(__FXSR__) || defined(__coverity_undefine___FXSR__))
#define __FXSR__ 1
#endif
#if !(defined(__GCC_ASM_FLAG_OUTPUTS__) || defined(__coverity_undefine___GCC_ASM_FLAG_OUTPUTS__))
#define __GCC_ASM_FLAG_OUTPUTS__ 1
#endif
#if !(defined(__GCC_ATOMIC_BOOL_LOCK_FREE) || defined(__coverity_undefine___GCC_ATOMIC_BOOL_LOCK_FREE))
#define __GCC_ATOMIC_BOOL_LOCK_FREE 2
#endif
#if !(defined(__GCC_ATOMIC_CHAR16_T_LOCK_FREE) || defined(__coverity_undefine___GCC_ATOMIC_CHAR16_T_LOCK_FREE))
#define __GCC_ATOMIC_CHAR16_T_LOCK_FREE 2
#endif
#if !(defined(__GCC_ATOMIC_CHAR32_T_LOCK_FREE) || defined(__coverity_undefine___GCC_ATOMIC_CHAR32_T_LOCK_FREE))
#define __GCC_ATOMIC_CHAR32_T_LOCK_FREE 2
#endif
#if !(defined(__GCC_ATOMIC_CHAR_LOCK_FREE) || defined(__coverity_undefine___GCC_ATOMIC_CHAR_LOCK_FREE))
#define __GCC_ATOMIC_CHAR_LOCK_FREE 2
#endif
#if !(defined(__GCC_ATOMIC_INT_LOCK_FREE) || defined(__coverity_undefine___GCC_ATOMIC_INT_LOCK_FREE))
#define __GCC_ATOMIC_INT_LOCK_FREE 2
#endif
#if !(defined(__GCC_ATOMIC_LLONG_LOCK_FREE) || defined(__coverity_undefine___GCC_ATOMIC_LLONG_LOCK_FREE))
#define __GCC_ATOMIC_LLONG_LOCK_FREE 2
#endif
#if !(defined(__GCC_ATOMIC_LONG_LOCK_FREE) || defined(__coverity_undefine___GCC_ATOMIC_LONG_LOCK_FREE))
#define __GCC_ATOMIC_LONG_LOCK_FREE 2
#endif
#if !(defined(__GCC_ATOMIC_POINTER_LOCK_FREE) || defined(__coverity_undefine___GCC_ATOMIC_POINTER_LOCK_FREE))
#define __GCC_ATOMIC_POINTER_LOCK_FREE 2
#endif
#if !(defined(__GCC_ATOMIC_SHORT_LOCK_FREE) || defined(__coverity_undefine___GCC_ATOMIC_SHORT_LOCK_FREE))
#define __GCC_ATOMIC_SHORT_LOCK_FREE 2
#endif
#if !(defined(__GCC_ATOMIC_TEST_AND_SET_TRUEVAL) || defined(__coverity_undefine___GCC_ATOMIC_TEST_AND_SET_TRUEVAL))
#define __GCC_ATOMIC_TEST_AND_SET_TRUEVAL 1
#endif
#if !(defined(__GCC_ATOMIC_WCHAR_T_LOCK_FREE) || defined(__coverity_undefine___GCC_ATOMIC_WCHAR_T_LOCK_FREE))
#define __GCC_ATOMIC_WCHAR_T_LOCK_FREE 2
#endif
#if !(defined(__GCC_HAVE_SYNC_COMPARE_AND_SWAP_1) || defined(__coverity_undefine___GCC_HAVE_SYNC_COMPARE_AND_SWAP_1))
#define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_1 1
#endif
#if !(defined(__GCC_HAVE_SYNC_COMPARE_AND_SWAP_2) || defined(__coverity_undefine___GCC_HAVE_SYNC_COMPARE_AND_SWAP_2))
#define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_2 1
#endif
#if !(defined(__GCC_HAVE_SYNC_COMPARE_AND_SWAP_4) || defined(__coverity_undefine___GCC_HAVE_SYNC_COMPARE_AND_SWAP_4))
#define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_4 1
#endif
#if !(defined(__GCC_HAVE_SYNC_COMPARE_AND_SWAP_8) || defined(__coverity_undefine___GCC_HAVE_SYNC_COMPARE_AND_SWAP_8))
#define __GCC_HAVE_SYNC_COMPARE_AND_SWAP_8 1
#endif
#if !(defined(__GLIBCXX_BITSIZE_INT_N_0) || defined(__coverity_undefine___GLIBCXX_BITSIZE_INT_N_0))
#define __GLIBCXX_BITSIZE_INT_N_0 128
#endif
#if !(defined(__GLIBCXX_TYPE_INT_N_0) || defined(__coverity_undefine___GLIBCXX_TYPE_INT_N_0))
#define __GLIBCXX_TYPE_INT_N_0 __int128
#endif
#if !(defined(__GNUC_GNU_INLINE__) || defined(__coverity_undefine___GNUC_GNU_INLINE__))
#define __GNUC_GNU_INLINE__ 1
#endif
#if !(defined(__GNUC_MINOR__) || defined(__coverity_undefine___GNUC_MINOR__))
#define __GNUC_MINOR__ 2
#endif
#if !(defined(__GNUC_PATCHLEVEL__) || defined(__coverity_undefine___GNUC_PATCHLEVEL__))
#define __GNUC_PATCHLEVEL__ 1
#endif
#if !(defined(__GNUC__) || defined(__coverity_undefine___GNUC__))
#define __GNUC__ 4
#endif
#if !(defined(__GNUG__) || defined(__coverity_undefine___GNUG__))
#define __GNUG__ 4
#endif
#if !(defined(__GXX_ABI_VERSION) || defined(__coverity_undefine___GXX_ABI_VERSION))
#define __GXX_ABI_VERSION 1002
#endif
#if !(defined(__GXX_EXPERIMENTAL_CXX0X__) || defined(__coverity_undefine___GXX_EXPERIMENTAL_CXX0X__))
#define __GXX_EXPERIMENTAL_CXX0X__ 1
#endif
#if !(defined(__GXX_RTTI) || defined(__coverity_undefine___GXX_RTTI))
#define __GXX_RTTI 1
#endif
#if !(defined(__GXX_WEAK__) || defined(__coverity_undefine___GXX_WEAK__))
#define __GXX_WEAK__ 1
#endif
#if !(defined(__INT16_C_SUFFIX__) || defined(__coverity_undefine___INT16_C_SUFFIX__))
#define __INT16_C_SUFFIX__ 
#endif
#if !(defined(__INT16_FMTd__) || defined(__coverity_undefine___INT16_FMTd__))
#define __INT16_FMTd__ "hd"
#endif
#if !(defined(__INT16_FMTi__) || defined(__coverity_undefine___INT16_FMTi__))
#define __INT16_FMTi__ "hi"
#endif
#if !(defined(__INT16_MAX__) || defined(__coverity_undefine___INT16_MAX__))
#define __INT16_MAX__ 32767
#endif
#if !(defined(__INT16_TYPE__) || defined(__coverity_undefine___INT16_TYPE__))
#define __INT16_TYPE__ short
#endif
#if !(defined(__INT32_C_SUFFIX__) || defined(__coverity_undefine___INT32_C_SUFFIX__))
#define __INT32_C_SUFFIX__ 
#endif
#if !(defined(__INT32_FMTd__) || defined(__coverity_undefine___INT32_FMTd__))
#define __INT32_FMTd__ "d"
#endif
#if !(defined(__INT32_FMTi__) || defined(__coverity_undefine___INT32_FMTi__))
#define __INT32_FMTi__ "i"
#endif
#if !(defined(__INT32_MAX__) || defined(__coverity_undefine___INT32_MAX__))
#define __INT32_MAX__ 2147483647
#endif
#if !(defined(__INT32_TYPE__) || defined(__coverity_undefine___INT32_TYPE__))
#define __INT32_TYPE__ int
#endif
#if !(defined(__INT64_C_SUFFIX__) || defined(__coverity_undefine___INT64_C_SUFFIX__))
#define __INT64_C_SUFFIX__ LL
#endif
#if !(defined(__INT64_FMTd__) || defined(__coverity_undefine___INT64_FMTd__))
#define __INT64_FMTd__ "lld"
#endif
#if !(defined(__INT64_FMTi__) || defined(__coverity_undefine___INT64_FMTi__))
#define __INT64_FMTi__ "lli"
#endif
#if !(defined(__INT64_MAX__) || defined(__coverity_undefine___INT64_MAX__))
#define __INT64_MAX__ 9223372036854775807LL
#endif
#if !(defined(__INT64_TYPE__) || defined(__coverity_undefine___INT64_TYPE__))
#define __INT64_TYPE__ long long int
#endif
#if !(defined(__INT8_C_SUFFIX__) || defined(__coverity_undefine___INT8_C_SUFFIX__))
#define __INT8_C_SUFFIX__ 
#endif
#if !(defined(__INT8_FMTd__) || defined(__coverity_undefine___INT8_FMTd__))
#define __INT8_FMTd__ "hhd"
#endif
#if !(defined(__INT8_FMTi__) || defined(__coverity_undefine___INT8_FMTi__))
#define __INT8_FMTi__ "hhi"
#endif
#if !(defined(__INT8_MAX__) || defined(__coverity_undefine___INT8_MAX__))
#define __INT8_MAX__ 127
#endif
#if !(defined(__INT8_TYPE__) || defined(__coverity_undefine___INT8_TYPE__))
#define __INT8_TYPE__ signed char
#endif
#if !(defined(__INTMAX_C_SUFFIX__) || defined(__coverity_undefine___INTMAX_C_SUFFIX__))
#define __INTMAX_C_SUFFIX__ LL
#endif
#if !(defined(__INTMAX_FMTd__) || defined(__coverity_undefine___INTMAX_FMTd__))
#define __INTMAX_FMTd__ "lld"
#endif
#if !(defined(__INTMAX_FMTi__) || defined(__coverity_undefine___INTMAX_FMTi__))
#define __INTMAX_FMTi__ "lli"
#endif
#if !(defined(__INTMAX_MAX__) || defined(__coverity_undefine___INTMAX_MAX__))
#define __INTMAX_MAX__ 9223372036854775807LL
#endif
#if !(defined(__INTMAX_TYPE__) || defined(__coverity_undefine___INTMAX_TYPE__))
#define __INTMAX_TYPE__ long long int
#endif
#if !(defined(__INTMAX_WIDTH__) || defined(__coverity_undefine___INTMAX_WIDTH__))
#define __INTMAX_WIDTH__ 64
#endif
#if !(defined(__INTPTR_FMTd__) || defined(__coverity_undefine___INTPTR_FMTd__))
#define __INTPTR_FMTd__ "lld"
#endif
#if !(defined(__INTPTR_FMTi__) || defined(__coverity_undefine___INTPTR_FMTi__))
#define __INTPTR_FMTi__ "lli"
#endif
#if !(defined(__INTPTR_MAX__) || defined(__coverity_undefine___INTPTR_MAX__))
#define __INTPTR_MAX__ 9223372036854775807LL
#endif
#if !(defined(__INTPTR_TYPE__) || defined(__coverity_undefine___INTPTR_TYPE__))
#define __INTPTR_TYPE__ long long int
#endif
#if !(defined(__INTPTR_WIDTH__) || defined(__coverity_undefine___INTPTR_WIDTH__))
#define __INTPTR_WIDTH__ 64
#endif
#if !(defined(__INT_FAST16_FMTd__) || defined(__coverity_undefine___INT_FAST16_FMTd__))
#define __INT_FAST16_FMTd__ "hd"
#endif
#if !(defined(__INT_FAST16_FMTi__) || defined(__coverity_undefine___INT_FAST16_FMTi__))
#define __INT_FAST16_FMTi__ "hi"
#endif
#if !(defined(__INT_FAST16_MAX__) || defined(__coverity_undefine___INT_FAST16_MAX__))
#define __INT_FAST16_MAX__ 32767
#endif
#if !(defined(__INT_FAST16_TYPE__) || defined(__coverity_undefine___INT_FAST16_TYPE__))
#define __INT_FAST16_TYPE__ short
#endif
#if !(defined(__INT_FAST16_WIDTH__) || defined(__coverity_undefine___INT_FAST16_WIDTH__))
#define __INT_FAST16_WIDTH__ 16
#endif
#if !(defined(__INT_FAST32_FMTd__) || defined(__coverity_undefine___INT_FAST32_FMTd__))
#define __INT_FAST32_FMTd__ "d"
#endif
#if !(defined(__INT_FAST32_FMTi__) || defined(__coverity_undefine___INT_FAST32_FMTi__))
#define __INT_FAST32_FMTi__ "i"
#endif
#if !(defined(__INT_FAST32_MAX__) || defined(__coverity_undefine___INT_FAST32_MAX__))
#define __INT_FAST32_MAX__ 2147483647
#endif
#if !(defined(__INT_FAST32_TYPE__) || defined(__coverity_undefine___INT_FAST32_TYPE__))
#define __INT_FAST32_TYPE__ int
#endif
#if !(defined(__INT_FAST32_WIDTH__) || defined(__coverity_undefine___INT_FAST32_WIDTH__))
#define __INT_FAST32_WIDTH__ 32
#endif
#if !(defined(__INT_FAST64_FMTd__) || defined(__coverity_undefine___INT_FAST64_FMTd__))
#define __INT_FAST64_FMTd__ "lld"
#endif
#if !(defined(__INT_FAST64_FMTi__) || defined(__coverity_undefine___INT_FAST64_FMTi__))
#define __INT_FAST64_FMTi__ "lli"
#endif
#if !(defined(__INT_FAST64_MAX__) || defined(__coverity_undefine___INT_FAST64_MAX__))
#define __INT_FAST64_MAX__ 9223372036854775807LL
#endif
#if !(defined(__INT_FAST64_TYPE__) || defined(__coverity_undefine___INT_FAST64_TYPE__))
#define __INT_FAST64_TYPE__ long long int
#endif
#if !(defined(__INT_FAST64_WIDTH__) || defined(__coverity_undefine___INT_FAST64_WIDTH__))
#define __INT_FAST64_WIDTH__ 64
#endif
#if !(defined(__INT_FAST8_FMTd__) || defined(__coverity_undefine___INT_FAST8_FMTd__))
#define __INT_FAST8_FMTd__ "hhd"
#endif
#if !(defined(__INT_FAST8_FMTi__) || defined(__coverity_undefine___INT_FAST8_FMTi__))
#define __INT_FAST8_FMTi__ "hhi"
#endif
#if !(defined(__INT_FAST8_MAX__) || defined(__coverity_undefine___INT_FAST8_MAX__))
#define __INT_FAST8_MAX__ 127
#endif
#if !(defined(__INT_FAST8_TYPE__) || defined(__coverity_undefine___INT_FAST8_TYPE__))
#define __INT_FAST8_TYPE__ signed char
#endif
#if !(defined(__INT_FAST8_WIDTH__) || defined(__coverity_undefine___INT_FAST8_WIDTH__))
#define __INT_FAST8_WIDTH__ 8
#endif
#if !(defined(__INT_LEAST16_FMTd__) || defined(__coverity_undefine___INT_LEAST16_FMTd__))
#define __INT_LEAST16_FMTd__ "hd"
#endif
#if !(defined(__INT_LEAST16_FMTi__) || defined(__coverity_undefine___INT_LEAST16_FMTi__))
#define __INT_LEAST16_FMTi__ "hi"
#endif
#if !(defined(__INT_LEAST16_MAX__) || defined(__coverity_undefine___INT_LEAST16_MAX__))
#define __INT_LEAST16_MAX__ 32767
#endif
#if !(defined(__INT_LEAST16_TYPE__) || defined(__coverity_undefine___INT_LEAST16_TYPE__))
#define __INT_LEAST16_TYPE__ short
#endif
#if !(defined(__INT_LEAST16_WIDTH__) || defined(__coverity_undefine___INT_LEAST16_WIDTH__))
#define __INT_LEAST16_WIDTH__ 16
#endif
#if !(defined(__INT_LEAST32_FMTd__) || defined(__coverity_undefine___INT_LEAST32_FMTd__))
#define __INT_LEAST32_FMTd__ "d"
#endif
#if !(defined(__INT_LEAST32_FMTi__) || defined(__coverity_undefine___INT_LEAST32_FMTi__))
#define __INT_LEAST32_FMTi__ "i"
#endif
#if !(defined(__INT_LEAST32_MAX__) || defined(__coverity_undefine___INT_LEAST32_MAX__))
#define __INT_LEAST32_MAX__ 2147483647
#endif
#if !(defined(__INT_LEAST32_TYPE__) || defined(__coverity_undefine___INT_LEAST32_TYPE__))
#define __INT_LEAST32_TYPE__ int
#endif
#if !(defined(__INT_LEAST32_WIDTH__) || defined(__coverity_undefine___INT_LEAST32_WIDTH__))
#define __INT_LEAST32_WIDTH__ 32
#endif
#if !(defined(__INT_LEAST64_FMTd__) || defined(__coverity_undefine___INT_LEAST64_FMTd__))
#define __INT_LEAST64_FMTd__ "lld"
#endif
#if !(defined(__INT_LEAST64_FMTi__) || defined(__coverity_undefine___INT_LEAST64_FMTi__))
#define __INT_LEAST64_FMTi__ "lli"
#endif
#if !(defined(__INT_LEAST64_MAX__) || defined(__coverity_undefine___INT_LEAST64_MAX__))
#define __INT_LEAST64_MAX__ 9223372036854775807LL
#endif
#if !(defined(__INT_LEAST64_TYPE__) || defined(__coverity_undefine___INT_LEAST64_TYPE__))
#define __INT_LEAST64_TYPE__ long long int
#endif
#if !(defined(__INT_LEAST64_WIDTH__) || defined(__coverity_undefine___INT_LEAST64_WIDTH__))
#define __INT_LEAST64_WIDTH__ 64
#endif
#if !(defined(__INT_LEAST8_FMTd__) || defined(__coverity_undefine___INT_LEAST8_FMTd__))
#define __INT_LEAST8_FMTd__ "hhd"
#endif
#if !(defined(__INT_LEAST8_FMTi__) || defined(__coverity_undefine___INT_LEAST8_FMTi__))
#define __INT_LEAST8_FMTi__ "hhi"
#endif
#if !(defined(__INT_LEAST8_MAX__) || defined(__coverity_undefine___INT_LEAST8_MAX__))
#define __INT_LEAST8_MAX__ 127
#endif
#if !(defined(__INT_LEAST8_TYPE__) || defined(__coverity_undefine___INT_LEAST8_TYPE__))
#define __INT_LEAST8_TYPE__ signed char
#endif
#if !(defined(__INT_LEAST8_WIDTH__) || defined(__coverity_undefine___INT_LEAST8_WIDTH__))
#define __INT_LEAST8_WIDTH__ 8
#endif
#if !(defined(__INT_MAX__) || defined(__coverity_undefine___INT_MAX__))
#define __INT_MAX__ 2147483647
#endif
#if !(defined(__INT_WIDTH__) || defined(__coverity_undefine___INT_WIDTH__))
#define __INT_WIDTH__ 32
#endif
#if !(defined(__LDBL_DECIMAL_DIG__) || defined(__coverity_undefine___LDBL_DECIMAL_DIG__))
#define __LDBL_DECIMAL_DIG__ 21
#endif
#if !(defined(__LDBL_DENORM_MIN__) || defined(__coverity_undefine___LDBL_DENORM_MIN__))
#define __LDBL_DENORM_MIN__ 3.64519953188247460253e-4951L
#endif
#if !(defined(__LDBL_DIG__) || defined(__coverity_undefine___LDBL_DIG__))
#define __LDBL_DIG__ 18
#endif
#if !(defined(__LDBL_EPSILON__) || defined(__coverity_undefine___LDBL_EPSILON__))
#define __LDBL_EPSILON__ 1.08420217248550443401e-19L
#endif
#if !(defined(__LDBL_HAS_DENORM__) || defined(__coverity_undefine___LDBL_HAS_DENORM__))
#define __LDBL_HAS_DENORM__ 1
#endif
#if !(defined(__LDBL_HAS_INFINITY__) || defined(__coverity_undefine___LDBL_HAS_INFINITY__))
#define __LDBL_HAS_INFINITY__ 1
#endif
#if !(defined(__LDBL_HAS_QUIET_NAN__) || defined(__coverity_undefine___LDBL_HAS_QUIET_NAN__))
#define __LDBL_HAS_QUIET_NAN__ 1
#endif
#if !(defined(__LDBL_MANT_DIG__) || defined(__coverity_undefine___LDBL_MANT_DIG__))
#define __LDBL_MANT_DIG__ 64
#endif
#if !(defined(__LDBL_MAX_10_EXP__) || defined(__coverity_undefine___LDBL_MAX_10_EXP__))
#define __LDBL_MAX_10_EXP__ 4932
#endif
#if !(defined(__LDBL_MAX_EXP__) || defined(__coverity_undefine___LDBL_MAX_EXP__))
#define __LDBL_MAX_EXP__ 16384
#endif
#if !(defined(__LDBL_MAX__) || defined(__coverity_undefine___LDBL_MAX__))
#define __LDBL_MAX__ 1.18973149535723176502e+4932L
#endif
#if !(defined(__LDBL_MIN_10_EXP__) || defined(__coverity_undefine___LDBL_MIN_10_EXP__))
#define __LDBL_MIN_10_EXP__ (-4931)
#endif
#if !(defined(__LDBL_MIN_EXP__) || defined(__coverity_undefine___LDBL_MIN_EXP__))
#define __LDBL_MIN_EXP__ (-16381)
#endif
#if !(defined(__LDBL_MIN__) || defined(__coverity_undefine___LDBL_MIN__))
#define __LDBL_MIN__ 3.36210314311209350626e-4932L
#endif
#if !(defined(__LITTLE_ENDIAN__) || defined(__coverity_undefine___LITTLE_ENDIAN__))
#define __LITTLE_ENDIAN__ 1
#endif
#if !(defined(__LLONG_WIDTH__) || defined(__coverity_undefine___LLONG_WIDTH__))
#define __LLONG_WIDTH__ 64
#endif
#if !(defined(__LONG_LONG_MAX__) || defined(__coverity_undefine___LONG_LONG_MAX__))
#define __LONG_LONG_MAX__ 9223372036854775807LL
#endif
#if !(defined(__LONG_MAX__) || defined(__coverity_undefine___LONG_MAX__))
#define __LONG_MAX__ 2147483647L
#endif
#if !(defined(__LONG_WIDTH__) || defined(__coverity_undefine___LONG_WIDTH__))
#define __LONG_WIDTH__ 32
#endif
#if !(defined(__MEMORY_SCOPE_DEVICE) || defined(__coverity_undefine___MEMORY_SCOPE_DEVICE))
#define __MEMORY_SCOPE_DEVICE 1
#endif
#if !(defined(__MEMORY_SCOPE_SINGLE) || defined(__coverity_undefine___MEMORY_SCOPE_SINGLE))
#define __MEMORY_SCOPE_SINGLE 4
#endif
#if !(defined(__MEMORY_SCOPE_SYSTEM) || defined(__coverity_undefine___MEMORY_SCOPE_SYSTEM))
#define __MEMORY_SCOPE_SYSTEM 0
#endif
#if !(defined(__MEMORY_SCOPE_WRKGRP) || defined(__coverity_undefine___MEMORY_SCOPE_WRKGRP))
#define __MEMORY_SCOPE_WRKGRP 2
#endif
#if !(defined(__MEMORY_SCOPE_WVFRNT) || defined(__coverity_undefine___MEMORY_SCOPE_WVFRNT))
#define __MEMORY_SCOPE_WVFRNT 3
#endif
#if !(defined(__MINGW32__) || defined(__coverity_undefine___MINGW32__))
#define __MINGW32__ 1
#endif
#if !(defined(__MINGW64__) || defined(__coverity_undefine___MINGW64__))
#define __MINGW64__ 1
#endif
#if !(defined(__MMX__) || defined(__coverity_undefine___MMX__))
#define __MMX__ 1
#endif
#if !(defined(__MSVCRT__) || defined(__coverity_undefine___MSVCRT__))
#define __MSVCRT__ 1
#endif
#if !(defined(__NO_MATH_INLINES) || defined(__coverity_undefine___NO_MATH_INLINES))
#define __NO_MATH_INLINES 1
#endif
#if !(defined(__OBJC_BOOL_IS_BOOL) || defined(__coverity_undefine___OBJC_BOOL_IS_BOOL))
#define __OBJC_BOOL_IS_BOOL 0
#endif
#if !(defined(__OBJC__) || defined(__coverity_undefine___OBJC__))
#define __OBJC__ 1
#endif
#if !(defined(__OPENCL_MEMORY_SCOPE_ALL_SVM_DEVICES) || defined(__coverity_undefine___OPENCL_MEMORY_SCOPE_ALL_SVM_DEVICES))
#define __OPENCL_MEMORY_SCOPE_ALL_SVM_DEVICES 3
#endif
#if !(defined(__OPENCL_MEMORY_SCOPE_DEVICE) || defined(__coverity_undefine___OPENCL_MEMORY_SCOPE_DEVICE))
#define __OPENCL_MEMORY_SCOPE_DEVICE 2
#endif
#if !(defined(__OPENCL_MEMORY_SCOPE_SUB_GROUP) || defined(__coverity_undefine___OPENCL_MEMORY_SCOPE_SUB_GROUP))
#define __OPENCL_MEMORY_SCOPE_SUB_GROUP 4
#endif
#if !(defined(__OPENCL_MEMORY_SCOPE_WORK_GROUP) || defined(__coverity_undefine___OPENCL_MEMORY_SCOPE_WORK_GROUP))
#define __OPENCL_MEMORY_SCOPE_WORK_GROUP 1
#endif
#if !(defined(__OPENCL_MEMORY_SCOPE_WORK_ITEM) || defined(__coverity_undefine___OPENCL_MEMORY_SCOPE_WORK_ITEM))
#define __OPENCL_MEMORY_SCOPE_WORK_ITEM 0
#endif
#if !(defined(__OPTIMIZE__) || defined(__coverity_undefine___OPTIMIZE__))
#define __OPTIMIZE__ 1
#endif
#if !(defined(__ORDER_BIG_ENDIAN__) || defined(__coverity_undefine___ORDER_BIG_ENDIAN__))
#define __ORDER_BIG_ENDIAN__ 4321
#endif
#if !(defined(__ORDER_LITTLE_ENDIAN__) || defined(__coverity_undefine___ORDER_LITTLE_ENDIAN__))
#define __ORDER_LITTLE_ENDIAN__ 1234
#endif
#if !(defined(__ORDER_PDP_ENDIAN__) || defined(__coverity_undefine___ORDER_PDP_ENDIAN__))
#define __ORDER_PDP_ENDIAN__ 3412
#endif
#if !(defined(__PIC__) || defined(__coverity_undefine___PIC__))
#define __PIC__ 2
#endif
#if !(defined(__POINTER_WIDTH__) || defined(__coverity_undefine___POINTER_WIDTH__))
#define __POINTER_WIDTH__ 64
#endif
#if !(defined(__PRAGMA_REDEFINE_EXTNAME) || defined(__coverity_undefine___PRAGMA_REDEFINE_EXTNAME))
#define __PRAGMA_REDEFINE_EXTNAME 1
#endif
#if !(defined(__PTRDIFF_FMTd__) || defined(__coverity_undefine___PTRDIFF_FMTd__))
#define __PTRDIFF_FMTd__ "lld"
#endif
#if !(defined(__PTRDIFF_FMTi__) || defined(__coverity_undefine___PTRDIFF_FMTi__))
#define __PTRDIFF_FMTi__ "lli"
#endif
#if !(defined(__PTRDIFF_MAX__) || defined(__coverity_undefine___PTRDIFF_MAX__))
#define __PTRDIFF_MAX__ 9223372036854775807LL
#endif
#if !(defined(__PTRDIFF_TYPE__) || defined(__coverity_undefine___PTRDIFF_TYPE__))
#define __PTRDIFF_TYPE__ long long int
#endif
#if !(defined(__PTRDIFF_WIDTH__) || defined(__coverity_undefine___PTRDIFF_WIDTH__))
#define __PTRDIFF_WIDTH__ 64
#endif
#if !(defined(__REGISTER_PREFIX__) || defined(__coverity_undefine___REGISTER_PREFIX__))
#define __REGISTER_PREFIX__ 
#endif
#if !(defined(__SCHAR_MAX__) || defined(__coverity_undefine___SCHAR_MAX__))
#define __SCHAR_MAX__ 127
#endif
#if !(defined(__SEG_FS) || defined(__coverity_undefine___SEG_FS))
#define __SEG_FS 1
#endif
#if !(defined(__SEG_GS) || defined(__coverity_undefine___SEG_GS))
#define __SEG_GS 1
#endif
#if !(defined(__SEH__) || defined(__coverity_undefine___SEH__))
#define __SEH__ 1
#endif
#if !(defined(__SHRT_MAX__) || defined(__coverity_undefine___SHRT_MAX__))
#define __SHRT_MAX__ 32767
#endif
#if !(defined(__SHRT_WIDTH__) || defined(__coverity_undefine___SHRT_WIDTH__))
#define __SHRT_WIDTH__ 16
#endif
#if !(defined(__SIG_ATOMIC_MAX__) || defined(__coverity_undefine___SIG_ATOMIC_MAX__))
#define __SIG_ATOMIC_MAX__ 2147483647
#endif
#if !(defined(__SIG_ATOMIC_WIDTH__) || defined(__coverity_undefine___SIG_ATOMIC_WIDTH__))
#define __SIG_ATOMIC_WIDTH__ 32
#endif
#if !(defined(__SIZEOF_DOUBLE__) || defined(__coverity_undefine___SIZEOF_DOUBLE__))
#define __SIZEOF_DOUBLE__ 8
#endif
#if !(defined(__SIZEOF_FLOAT128__) || defined(__coverity_undefine___SIZEOF_FLOAT128__))
#define __SIZEOF_FLOAT128__ 16
#endif
#if !(defined(__SIZEOF_FLOAT__) || defined(__coverity_undefine___SIZEOF_FLOAT__))
#define __SIZEOF_FLOAT__ 4
#endif
#if !(defined(__SIZEOF_INT128__) || defined(__coverity_undefine___SIZEOF_INT128__))
#define __SIZEOF_INT128__ 16
#endif
#if !(defined(__SIZEOF_INT__) || defined(__coverity_undefine___SIZEOF_INT__))
#define __SIZEOF_INT__ 4
#endif
#if !(defined(__SIZEOF_LONG_DOUBLE__) || defined(__coverity_undefine___SIZEOF_LONG_DOUBLE__))
#define __SIZEOF_LONG_DOUBLE__ 16
#endif
#if !(defined(__SIZEOF_LONG_LONG__) || defined(__coverity_undefine___SIZEOF_LONG_LONG__))
#define __SIZEOF_LONG_LONG__ 8
#endif
#if !(defined(__SIZEOF_LONG__) || defined(__coverity_undefine___SIZEOF_LONG__))
#define __SIZEOF_LONG__ 4
#endif
#if !(defined(__SIZEOF_POINTER__) || defined(__coverity_undefine___SIZEOF_POINTER__))
#define __SIZEOF_POINTER__ 8
#endif
#if !(defined(__SIZEOF_PTRDIFF_T__) || defined(__coverity_undefine___SIZEOF_PTRDIFF_T__))
#define __SIZEOF_PTRDIFF_T__ 8
#endif
#if !(defined(__SIZEOF_SHORT__) || defined(__coverity_undefine___SIZEOF_SHORT__))
#define __SIZEOF_SHORT__ 2
#endif
#if !(defined(__SIZEOF_SIZE_T__) || defined(__coverity_undefine___SIZEOF_SIZE_T__))
#define __SIZEOF_SIZE_T__ 8
#endif
#if !(defined(__SIZEOF_WCHAR_T__) || defined(__coverity_undefine___SIZEOF_WCHAR_T__))
#define __SIZEOF_WCHAR_T__ 2
#endif
#if !(defined(__SIZEOF_WINT_T__) || defined(__coverity_undefine___SIZEOF_WINT_T__))
#define __SIZEOF_WINT_T__ 2
#endif
#if !(defined(__SIZE_FMTX__) || defined(__coverity_undefine___SIZE_FMTX__))
#define __SIZE_FMTX__ "llX"
#endif
#if !(defined(__SIZE_FMTo__) || defined(__coverity_undefine___SIZE_FMTo__))
#define __SIZE_FMTo__ "llo"
#endif
#if !(defined(__SIZE_FMTu__) || defined(__coverity_undefine___SIZE_FMTu__))
#define __SIZE_FMTu__ "llu"
#endif
#if !(defined(__SIZE_FMTx__) || defined(__coverity_undefine___SIZE_FMTx__))
#define __SIZE_FMTx__ "llx"
#endif
#if !(defined(__SIZE_MAX__) || defined(__coverity_undefine___SIZE_MAX__))
#define __SIZE_MAX__ 18446744073709551615ULL
#endif
#if !(defined(__SIZE_TYPE__) || defined(__coverity_undefine___SIZE_TYPE__))
#define __SIZE_TYPE__ long long unsigned int
#endif
#if !(defined(__SIZE_WIDTH__) || defined(__coverity_undefine___SIZE_WIDTH__))
#define __SIZE_WIDTH__ 64
#endif
#if !(defined(__SSE2_MATH__) || defined(__coverity_undefine___SSE2_MATH__))
#define __SSE2_MATH__ 1
#endif
#if !(defined(__SSE2__) || defined(__coverity_undefine___SSE2__))
#define __SSE2__ 1
#endif
#if !(defined(__SSE_MATH__) || defined(__coverity_undefine___SSE_MATH__))
#define __SSE_MATH__ 1
#endif
#if !(defined(__SSE__) || defined(__coverity_undefine___SSE__))
#define __SSE__ 1
#endif
#if !(defined(__STDCPP_DEFAULT_NEW_ALIGNMENT__) || defined(__coverity_undefine___STDCPP_DEFAULT_NEW_ALIGNMENT__))
#define __STDCPP_DEFAULT_NEW_ALIGNMENT__ 16ULL
#endif
#if !(defined(__STDCPP_THREADS__) || defined(__coverity_undefine___STDCPP_THREADS__))
#define __STDCPP_THREADS__ 1
#endif
#if !(defined(__STDC_HOSTED__) || defined(__coverity_undefine___STDC_HOSTED__))
#define __STDC_HOSTED__ 1
#endif
#if !(defined(__STDC_UTF_16__) || defined(__coverity_undefine___STDC_UTF_16__))
#define __STDC_UTF_16__ 1
#endif
#if !(defined(__STDC_UTF_32__) || defined(__coverity_undefine___STDC_UTF_32__))
#define __STDC_UTF_32__ 1
#endif
#if !(defined(__STDC__) || defined(__coverity_undefine___STDC__))
#define __STDC__ 1
#endif
#if !(defined(__UINT16_C_SUFFIX__) || defined(__coverity_undefine___UINT16_C_SUFFIX__))
#define __UINT16_C_SUFFIX__ 
#endif
#if !(defined(__UINT16_FMTX__) || defined(__coverity_undefine___UINT16_FMTX__))
#define __UINT16_FMTX__ "hX"
#endif
#if !(defined(__UINT16_FMTo__) || defined(__coverity_undefine___UINT16_FMTo__))
#define __UINT16_FMTo__ "ho"
#endif
#if !(defined(__UINT16_FMTu__) || defined(__coverity_undefine___UINT16_FMTu__))
#define __UINT16_FMTu__ "hu"
#endif
#if !(defined(__UINT16_FMTx__) || defined(__coverity_undefine___UINT16_FMTx__))
#define __UINT16_FMTx__ "hx"
#endif
#if !(defined(__UINT16_MAX__) || defined(__coverity_undefine___UINT16_MAX__))
#define __UINT16_MAX__ 65535
#endif
#if !(defined(__UINT16_TYPE__) || defined(__coverity_undefine___UINT16_TYPE__))
#define __UINT16_TYPE__ unsigned short
#endif
#if !(defined(__UINT32_C_SUFFIX__) || defined(__coverity_undefine___UINT32_C_SUFFIX__))
#define __UINT32_C_SUFFIX__ U
#endif
#if !(defined(__UINT32_FMTX__) || defined(__coverity_undefine___UINT32_FMTX__))
#define __UINT32_FMTX__ "X"
#endif
#if !(defined(__UINT32_FMTo__) || defined(__coverity_undefine___UINT32_FMTo__))
#define __UINT32_FMTo__ "o"
#endif
#if !(defined(__UINT32_FMTu__) || defined(__coverity_undefine___UINT32_FMTu__))
#define __UINT32_FMTu__ "u"
#endif
#if !(defined(__UINT32_FMTx__) || defined(__coverity_undefine___UINT32_FMTx__))
#define __UINT32_FMTx__ "x"
#endif
#if !(defined(__UINT32_MAX__) || defined(__coverity_undefine___UINT32_MAX__))
#define __UINT32_MAX__ 4294967295U
#endif
#if !(defined(__UINT32_TYPE__) || defined(__coverity_undefine___UINT32_TYPE__))
#define __UINT32_TYPE__ unsigned int
#endif
#if !(defined(__UINT64_C_SUFFIX__) || defined(__coverity_undefine___UINT64_C_SUFFIX__))
#define __UINT64_C_SUFFIX__ ULL
#endif
#if !(defined(__UINT64_FMTX__) || defined(__coverity_undefine___UINT64_FMTX__))
#define __UINT64_FMTX__ "llX"
#endif
#if !(defined(__UINT64_FMTo__) || defined(__coverity_undefine___UINT64_FMTo__))
#define __UINT64_FMTo__ "llo"
#endif
#if !(defined(__UINT64_FMTu__) || defined(__coverity_undefine___UINT64_FMTu__))
#define __UINT64_FMTu__ "llu"
#endif
#if !(defined(__UINT64_FMTx__) || defined(__coverity_undefine___UINT64_FMTx__))
#define __UINT64_FMTx__ "llx"
#endif
#if !(defined(__UINT64_MAX__) || defined(__coverity_undefine___UINT64_MAX__))
#define __UINT64_MAX__ 18446744073709551615ULL
#endif
#if !(defined(__UINT64_TYPE__) || defined(__coverity_undefine___UINT64_TYPE__))
#define __UINT64_TYPE__ long long unsigned int
#endif
#if !(defined(__UINT8_C_SUFFIX__) || defined(__coverity_undefine___UINT8_C_SUFFIX__))
#define __UINT8_C_SUFFIX__ 
#endif
#if !(defined(__UINT8_FMTX__) || defined(__coverity_undefine___UINT8_FMTX__))
#define __UINT8_FMTX__ "hhX"
#endif
#if !(defined(__UINT8_FMTo__) || defined(__coverity_undefine___UINT8_FMTo__))
#define __UINT8_FMTo__ "hho"
#endif
#if !(defined(__UINT8_FMTu__) || defined(__coverity_undefine___UINT8_FMTu__))
#define __UINT8_FMTu__ "hhu"
#endif
#if !(defined(__UINT8_FMTx__) || defined(__coverity_undefine___UINT8_FMTx__))
#define __UINT8_FMTx__ "hhx"
#endif
#if !(defined(__UINT8_MAX__) || defined(__coverity_undefine___UINT8_MAX__))
#define __UINT8_MAX__ 255
#endif
#if !(defined(__UINT8_TYPE__) || defined(__coverity_undefine___UINT8_TYPE__))
#define __UINT8_TYPE__ unsigned char
#endif
#if !(defined(__UINTMAX_C_SUFFIX__) || defined(__coverity_undefine___UINTMAX_C_SUFFIX__))
#define __UINTMAX_C_SUFFIX__ ULL
#endif
#if !(defined(__UINTMAX_FMTX__) || defined(__coverity_undefine___UINTMAX_FMTX__))
#define __UINTMAX_FMTX__ "llX"
#endif
#if !(defined(__UINTMAX_FMTo__) || defined(__coverity_undefine___UINTMAX_FMTo__))
#define __UINTMAX_FMTo__ "llo"
#endif
#if !(defined(__UINTMAX_FMTu__) || defined(__coverity_undefine___UINTMAX_FMTu__))
#define __UINTMAX_FMTu__ "llu"
#endif
#if !(defined(__UINTMAX_FMTx__) || defined(__coverity_undefine___UINTMAX_FMTx__))
#define __UINTMAX_FMTx__ "llx"
#endif
#if !(defined(__UINTMAX_MAX__) || defined(__coverity_undefine___UINTMAX_MAX__))
#define __UINTMAX_MAX__ 18446744073709551615ULL
#endif
#if !(defined(__UINTMAX_TYPE__) || defined(__coverity_undefine___UINTMAX_TYPE__))
#define __UINTMAX_TYPE__ long long unsigned int
#endif
#if !(defined(__UINTMAX_WIDTH__) || defined(__coverity_undefine___UINTMAX_WIDTH__))
#define __UINTMAX_WIDTH__ 64
#endif
#if !(defined(__UINTPTR_FMTX__) || defined(__coverity_undefine___UINTPTR_FMTX__))
#define __UINTPTR_FMTX__ "llX"
#endif
#if !(defined(__UINTPTR_FMTo__) || defined(__coverity_undefine___UINTPTR_FMTo__))
#define __UINTPTR_FMTo__ "llo"
#endif
#if !(defined(__UINTPTR_FMTu__) || defined(__coverity_undefine___UINTPTR_FMTu__))
#define __UINTPTR_FMTu__ "llu"
#endif
#if !(defined(__UINTPTR_FMTx__) || defined(__coverity_undefine___UINTPTR_FMTx__))
#define __UINTPTR_FMTx__ "llx"
#endif
#if !(defined(__UINTPTR_MAX__) || defined(__coverity_undefine___UINTPTR_MAX__))
#define __UINTPTR_MAX__ 18446744073709551615ULL
#endif
#if !(defined(__UINTPTR_TYPE__) || defined(__coverity_undefine___UINTPTR_TYPE__))
#define __UINTPTR_TYPE__ long long unsigned int
#endif
#if !(defined(__UINTPTR_WIDTH__) || defined(__coverity_undefine___UINTPTR_WIDTH__))
#define __UINTPTR_WIDTH__ 64
#endif
#if !(defined(__UINT_FAST16_FMTX__) || defined(__coverity_undefine___UINT_FAST16_FMTX__))
#define __UINT_FAST16_FMTX__ "hX"
#endif
#if !(defined(__UINT_FAST16_FMTo__) || defined(__coverity_undefine___UINT_FAST16_FMTo__))
#define __UINT_FAST16_FMTo__ "ho"
#endif
#if !(defined(__UINT_FAST16_FMTu__) || defined(__coverity_undefine___UINT_FAST16_FMTu__))
#define __UINT_FAST16_FMTu__ "hu"
#endif
#if !(defined(__UINT_FAST16_FMTx__) || defined(__coverity_undefine___UINT_FAST16_FMTx__))
#define __UINT_FAST16_FMTx__ "hx"
#endif
#if !(defined(__UINT_FAST16_MAX__) || defined(__coverity_undefine___UINT_FAST16_MAX__))
#define __UINT_FAST16_MAX__ 65535
#endif
#if !(defined(__UINT_FAST16_TYPE__) || defined(__coverity_undefine___UINT_FAST16_TYPE__))
#define __UINT_FAST16_TYPE__ unsigned short
#endif
#if !(defined(__UINT_FAST32_FMTX__) || defined(__coverity_undefine___UINT_FAST32_FMTX__))
#define __UINT_FAST32_FMTX__ "X"
#endif
#if !(defined(__UINT_FAST32_FMTo__) || defined(__coverity_undefine___UINT_FAST32_FMTo__))
#define __UINT_FAST32_FMTo__ "o"
#endif
#if !(defined(__UINT_FAST32_FMTu__) || defined(__coverity_undefine___UINT_FAST32_FMTu__))
#define __UINT_FAST32_FMTu__ "u"
#endif
#if !(defined(__UINT_FAST32_FMTx__) || defined(__coverity_undefine___UINT_FAST32_FMTx__))
#define __UINT_FAST32_FMTx__ "x"
#endif
#if !(defined(__UINT_FAST32_MAX__) || defined(__coverity_undefine___UINT_FAST32_MAX__))
#define __UINT_FAST32_MAX__ 4294967295U
#endif
#if !(defined(__UINT_FAST32_TYPE__) || defined(__coverity_undefine___UINT_FAST32_TYPE__))
#define __UINT_FAST32_TYPE__ unsigned int
#endif
#if !(defined(__UINT_FAST64_FMTX__) || defined(__coverity_undefine___UINT_FAST64_FMTX__))
#define __UINT_FAST64_FMTX__ "llX"
#endif
#if !(defined(__UINT_FAST64_FMTo__) || defined(__coverity_undefine___UINT_FAST64_FMTo__))
#define __UINT_FAST64_FMTo__ "llo"
#endif
#if !(defined(__UINT_FAST64_FMTu__) || defined(__coverity_undefine___UINT_FAST64_FMTu__))
#define __UINT_FAST64_FMTu__ "llu"
#endif
#if !(defined(__UINT_FAST64_FMTx__) || defined(__coverity_undefine___UINT_FAST64_FMTx__))
#define __UINT_FAST64_FMTx__ "llx"
#endif
#if !(defined(__UINT_FAST64_MAX__) || defined(__coverity_undefine___UINT_FAST64_MAX__))
#define __UINT_FAST64_MAX__ 18446744073709551615ULL
#endif
#if !(defined(__UINT_FAST64_TYPE__) || defined(__coverity_undefine___UINT_FAST64_TYPE__))
#define __UINT_FAST64_TYPE__ long long unsigned int
#endif
#if !(defined(__UINT_FAST8_FMTX__) || defined(__coverity_undefine___UINT_FAST8_FMTX__))
#define __UINT_FAST8_FMTX__ "hhX"
#endif
#if !(defined(__UINT_FAST8_FMTo__) || defined(__coverity_undefine___UINT_FAST8_FMTo__))
#define __UINT_FAST8_FMTo__ "hho"
#endif
#if !(defined(__UINT_FAST8_FMTu__) || defined(__coverity_undefine___UINT_FAST8_FMTu__))
#define __UINT_FAST8_FMTu__ "hhu"
#endif
#if !(defined(__UINT_FAST8_FMTx__) || defined(__coverity_undefine___UINT_FAST8_FMTx__))
#define __UINT_FAST8_FMTx__ "hhx"
#endif
#if !(defined(__UINT_FAST8_MAX__) || defined(__coverity_undefine___UINT_FAST8_MAX__))
#define __UINT_FAST8_MAX__ 255
#endif
#if !(defined(__UINT_FAST8_TYPE__) || defined(__coverity_undefine___UINT_FAST8_TYPE__))
#define __UINT_FAST8_TYPE__ unsigned char
#endif
#if !(defined(__UINT_LEAST16_FMTX__) || defined(__coverity_undefine___UINT_LEAST16_FMTX__))
#define __UINT_LEAST16_FMTX__ "hX"
#endif
#if !(defined(__UINT_LEAST16_FMTo__) || defined(__coverity_undefine___UINT_LEAST16_FMTo__))
#define __UINT_LEAST16_FMTo__ "ho"
#endif
#if !(defined(__UINT_LEAST16_FMTu__) || defined(__coverity_undefine___UINT_LEAST16_FMTu__))
#define __UINT_LEAST16_FMTu__ "hu"
#endif
#if !(defined(__UINT_LEAST16_FMTx__) || defined(__coverity_undefine___UINT_LEAST16_FMTx__))
#define __UINT_LEAST16_FMTx__ "hx"
#endif
#if !(defined(__UINT_LEAST16_MAX__) || defined(__coverity_undefine___UINT_LEAST16_MAX__))
#define __UINT_LEAST16_MAX__ 65535
#endif
#if !(defined(__UINT_LEAST16_TYPE__) || defined(__coverity_undefine___UINT_LEAST16_TYPE__))
#define __UINT_LEAST16_TYPE__ unsigned short
#endif
#if !(defined(__UINT_LEAST32_FMTX__) || defined(__coverity_undefine___UINT_LEAST32_FMTX__))
#define __UINT_LEAST32_FMTX__ "X"
#endif
#if !(defined(__UINT_LEAST32_FMTo__) || defined(__coverity_undefine___UINT_LEAST32_FMTo__))
#define __UINT_LEAST32_FMTo__ "o"
#endif
#if !(defined(__UINT_LEAST32_FMTu__) || defined(__coverity_undefine___UINT_LEAST32_FMTu__))
#define __UINT_LEAST32_FMTu__ "u"
#endif
#if !(defined(__UINT_LEAST32_FMTx__) || defined(__coverity_undefine___UINT_LEAST32_FMTx__))
#define __UINT_LEAST32_FMTx__ "x"
#endif
#if !(defined(__UINT_LEAST32_MAX__) || defined(__coverity_undefine___UINT_LEAST32_MAX__))
#define __UINT_LEAST32_MAX__ 4294967295U
#endif
#if !(defined(__UINT_LEAST32_TYPE__) || defined(__coverity_undefine___UINT_LEAST32_TYPE__))
#define __UINT_LEAST32_TYPE__ unsigned int
#endif
#if !(defined(__UINT_LEAST64_FMTX__) || defined(__coverity_undefine___UINT_LEAST64_FMTX__))
#define __UINT_LEAST64_FMTX__ "llX"
#endif
#if !(defined(__UINT_LEAST64_FMTo__) || defined(__coverity_undefine___UINT_LEAST64_FMTo__))
#define __UINT_LEAST64_FMTo__ "llo"
#endif
#if !(defined(__UINT_LEAST64_FMTu__) || defined(__coverity_undefine___UINT_LEAST64_FMTu__))
#define __UINT_LEAST64_FMTu__ "llu"
#endif
#if !(defined(__UINT_LEAST64_FMTx__) || defined(__coverity_undefine___UINT_LEAST64_FMTx__))
#define __UINT_LEAST64_FMTx__ "llx"
#endif
#if !(defined(__UINT_LEAST64_MAX__) || defined(__coverity_undefine___UINT_LEAST64_MAX__))
#define __UINT_LEAST64_MAX__ 18446744073709551615ULL
#endif
#if !(defined(__UINT_LEAST64_TYPE__) || defined(__coverity_undefine___UINT_LEAST64_TYPE__))
#define __UINT_LEAST64_TYPE__ long long unsigned int
#endif
#if !(defined(__UINT_LEAST8_FMTX__) || defined(__coverity_undefine___UINT_LEAST8_FMTX__))
#define __UINT_LEAST8_FMTX__ "hhX"
#endif
#if !(defined(__UINT_LEAST8_FMTo__) || defined(__coverity_undefine___UINT_LEAST8_FMTo__))
#define __UINT_LEAST8_FMTo__ "hho"
#endif
#if !(defined(__UINT_LEAST8_FMTu__) || defined(__coverity_undefine___UINT_LEAST8_FMTu__))
#define __UINT_LEAST8_FMTu__ "hhu"
#endif
#if !(defined(__UINT_LEAST8_FMTx__) || defined(__coverity_undefine___UINT_LEAST8_FMTx__))
#define __UINT_LEAST8_FMTx__ "hhx"
#endif
#if !(defined(__UINT_LEAST8_MAX__) || defined(__coverity_undefine___UINT_LEAST8_MAX__))
#define __UINT_LEAST8_MAX__ 255
#endif
#if !(defined(__UINT_LEAST8_TYPE__) || defined(__coverity_undefine___UINT_LEAST8_TYPE__))
#define __UINT_LEAST8_TYPE__ unsigned char
#endif
#if !(defined(__USER_LABEL_PREFIX__) || defined(__coverity_undefine___USER_LABEL_PREFIX__))
#define __USER_LABEL_PREFIX__ 
#endif
#if !(defined(__VERSION__) || defined(__coverity_undefine___VERSION__))
#define __VERSION__ "Clang 18.1.4"
#endif
#if !(defined(__WCHAR_MAX__) || defined(__coverity_undefine___WCHAR_MAX__))
#define __WCHAR_MAX__ 65535
#endif
#if !(defined(__WCHAR_TYPE__) || defined(__coverity_undefine___WCHAR_TYPE__))
#define __WCHAR_TYPE__ unsigned short
#endif
#if !(defined(__WCHAR_UNSIGNED__) || defined(__coverity_undefine___WCHAR_UNSIGNED__))
#define __WCHAR_UNSIGNED__ 1
#endif
#if !(defined(__WCHAR_WIDTH__) || defined(__coverity_undefine___WCHAR_WIDTH__))
#define __WCHAR_WIDTH__ 16
#endif
#if !(defined(__WIN32) || defined(__coverity_undefine___WIN32))
#define __WIN32 1
#endif
#if !(defined(__WIN32__) || defined(__coverity_undefine___WIN32__))
#define __WIN32__ 1
#endif
#if !(defined(__WIN64) || defined(__coverity_undefine___WIN64))
#define __WIN64 1
#endif
#if !(defined(__WIN64__) || defined(__coverity_undefine___WIN64__))
#define __WIN64__ 1
#endif
#if !(defined(__WINNT) || defined(__coverity_undefine___WINNT))
#define __WINNT 1
#endif
#if !(defined(__WINNT__) || defined(__coverity_undefine___WINNT__))
#define __WINNT__ 1
#endif
#if !(defined(__WINT_MAX__) || defined(__coverity_undefine___WINT_MAX__))
#define __WINT_MAX__ 65535
#endif
#if !(defined(__WINT_TYPE__) || defined(__coverity_undefine___WINT_TYPE__))
#define __WINT_TYPE__ unsigned short
#endif
#if !(defined(__WINT_UNSIGNED__) || defined(__coverity_undefine___WINT_UNSIGNED__))
#define __WINT_UNSIGNED__ 1
#endif
#if !(defined(__WINT_WIDTH__) || defined(__coverity_undefine___WINT_WIDTH__))
#define __WINT_WIDTH__ 16
#endif
#if !(defined(__amd64) || defined(__coverity_undefine___amd64))
#define __amd64 1
#endif
#if !(defined(__amd64__) || defined(__coverity_undefine___amd64__))
#define __amd64__ 1
#endif
#if !(defined(__autoreleasing) || defined(__coverity_undefine___autoreleasing))
#define __autoreleasing __attribute__((objc_ownership(autoreleasing)))
#endif
#if !(defined(__cdecl) || defined(__coverity_undefine___cdecl))
#define __cdecl __attribute__((__cdecl__))
#endif
#if !(defined(__clang__) || defined(__coverity_undefine___clang__))
#define __clang__ 1
#endif
#if !(defined(__clang_literal_encoding__) || defined(__coverity_undefine___clang_literal_encoding__))
#define __clang_literal_encoding__ "UTF-8"
#endif
#if !(defined(__clang_major__) || defined(__coverity_undefine___clang_major__))
#define __clang_major__ 18
#endif
#if !(defined(__clang_minor__) || defined(__coverity_undefine___clang_minor__))
#define __clang_minor__ 1
#endif
#if !(defined(__clang_patchlevel__) || defined(__coverity_undefine___clang_patchlevel__))
#define __clang_patchlevel__ 4
#endif
#if !(defined(__clang_version__) || defined(__coverity_undefine___clang_version__))
#define __clang_version__ "18.1.4 "
#endif
#if !(defined(__clang_wide_literal_encoding__) || defined(__coverity_undefine___clang_wide_literal_encoding__))
#define __clang_wide_literal_encoding__ "UTF-16"
#endif
#if !(defined(__code_model_small__) || defined(__coverity_undefine___code_model_small__))
#define __code_model_small__ 1
#endif
#if !(defined(__cplusplus) || defined(__coverity_undefine___cplusplus))
#define __cplusplus 201703L
#endif
#if !(defined(__cpp_aggregate_bases) || defined(__coverity_undefine___cpp_aggregate_bases))
#define __cpp_aggregate_bases 201603L
#endif
#if !(defined(__cpp_aggregate_nsdmi) || defined(__coverity_undefine___cpp_aggregate_nsdmi))
#define __cpp_aggregate_nsdmi 201304L
#endif
#if !(defined(__cpp_alias_templates) || defined(__coverity_undefine___cpp_alias_templates))
#define __cpp_alias_templates 200704L
#endif
#if !(defined(__cpp_aligned_new) || defined(__coverity_undefine___cpp_aligned_new))
#define __cpp_aligned_new 201606L
#endif
#if !(defined(__cpp_attributes) || defined(__coverity_undefine___cpp_attributes))
#define __cpp_attributes 200809L
#endif
#if !(defined(__cpp_binary_literals) || defined(__coverity_undefine___cpp_binary_literals))
#define __cpp_binary_literals 201304L
#endif
#if !(defined(__cpp_capture_star_this) || defined(__coverity_undefine___cpp_capture_star_this))
#define __cpp_capture_star_this 201603L
#endif
#if !(defined(__cpp_constexpr) || defined(__coverity_undefine___cpp_constexpr))
#define __cpp_constexpr 201603L
#endif
#if !(defined(__cpp_constexpr_in_decltype) || defined(__coverity_undefine___cpp_constexpr_in_decltype))
#define __cpp_constexpr_in_decltype 201711L
#endif
#if !(defined(__cpp_decltype) || defined(__coverity_undefine___cpp_decltype))
#define __cpp_decltype 200707L
#endif
#if !(defined(__cpp_decltype_auto) || defined(__coverity_undefine___cpp_decltype_auto))
#define __cpp_decltype_auto 201304L
#endif
#if !(defined(__cpp_deduction_guides) || defined(__coverity_undefine___cpp_deduction_guides))
#define __cpp_deduction_guides 201703L
#endif
#if !(defined(__cpp_delegating_constructors) || defined(__coverity_undefine___cpp_delegating_constructors))
#define __cpp_delegating_constructors 200604L
#endif
#if !(defined(__cpp_digit_separators) || defined(__coverity_undefine___cpp_digit_separators))
#define __cpp_digit_separators 201309L
#endif
#if !(defined(__cpp_enumerator_attributes) || defined(__coverity_undefine___cpp_enumerator_attributes))
#define __cpp_enumerator_attributes 201411L
#endif
#if !(defined(__cpp_exceptions) || defined(__coverity_undefine___cpp_exceptions))
#define __cpp_exceptions 199711L
#endif
#if !(defined(__cpp_fold_expressions) || defined(__coverity_undefine___cpp_fold_expressions))
#define __cpp_fold_expressions 201603L
#endif
#if !(defined(__cpp_generic_lambdas) || defined(__coverity_undefine___cpp_generic_lambdas))
#define __cpp_generic_lambdas 201304L
#endif
#if !(defined(__cpp_guaranteed_copy_elision) || defined(__coverity_undefine___cpp_guaranteed_copy_elision))
#define __cpp_guaranteed_copy_elision 201606L
#endif
#if !(defined(__cpp_hex_float) || defined(__coverity_undefine___cpp_hex_float))
#define __cpp_hex_float 201603L
#endif
#if !(defined(__cpp_if_constexpr) || defined(__coverity_undefine___cpp_if_constexpr))
#define __cpp_if_constexpr 201606L
#endif
#if !(defined(__cpp_impl_destroying_delete) || defined(__coverity_undefine___cpp_impl_destroying_delete))
#define __cpp_impl_destroying_delete 201806L
#endif
#if !(defined(__cpp_inheriting_constructors) || defined(__coverity_undefine___cpp_inheriting_constructors))
#define __cpp_inheriting_constructors 201511L
#endif
#if !(defined(__cpp_init_captures) || defined(__coverity_undefine___cpp_init_captures))
#define __cpp_init_captures 201304L
#endif
#if !(defined(__cpp_initializer_lists) || defined(__coverity_undefine___cpp_initializer_lists))
#define __cpp_initializer_lists 200806L
#endif
#if !(defined(__cpp_inline_variables) || defined(__coverity_undefine___cpp_inline_variables))
#define __cpp_inline_variables 201606L
#endif
#if !(defined(__cpp_lambdas) || defined(__coverity_undefine___cpp_lambdas))
#define __cpp_lambdas 200907L
#endif
#if !(defined(__cpp_named_character_escapes) || defined(__coverity_undefine___cpp_named_character_escapes))
#define __cpp_named_character_escapes 202207L
#endif
#if !(defined(__cpp_namespace_attributes) || defined(__coverity_undefine___cpp_namespace_attributes))
#define __cpp_namespace_attributes 201411L
#endif
#if !(defined(__cpp_nested_namespace_definitions) || defined(__coverity_undefine___cpp_nested_namespace_definitions))
#define __cpp_nested_namespace_definitions 201411L
#endif
#if !(defined(__cpp_noexcept_function_type) || defined(__coverity_undefine___cpp_noexcept_function_type))
#define __cpp_noexcept_function_type 201510L
#endif
#if !(defined(__cpp_nontype_template_args) || defined(__coverity_undefine___cpp_nontype_template_args))
#define __cpp_nontype_template_args 201411L
#endif
#if !(defined(__cpp_nontype_template_parameter_auto) || defined(__coverity_undefine___cpp_nontype_template_parameter_auto))
#define __cpp_nontype_template_parameter_auto 201606L
#endif
#if !(defined(__cpp_nsdmi) || defined(__coverity_undefine___cpp_nsdmi))
#define __cpp_nsdmi 200809L
#endif
#if !(defined(__cpp_placeholder_variables) || defined(__coverity_undefine___cpp_placeholder_variables))
#define __cpp_placeholder_variables 202306L
#endif
#if !(defined(__cpp_range_based_for) || defined(__coverity_undefine___cpp_range_based_for))
#define __cpp_range_based_for 201603L
#endif
#if !(defined(__cpp_raw_strings) || defined(__coverity_undefine___cpp_raw_strings))
#define __cpp_raw_strings 200710L
#endif
#if !(defined(__cpp_ref_qualifiers) || defined(__coverity_undefine___cpp_ref_qualifiers))
#define __cpp_ref_qualifiers 200710L
#endif
#if !(defined(__cpp_return_type_deduction) || defined(__coverity_undefine___cpp_return_type_deduction))
#define __cpp_return_type_deduction 201304L
#endif
#if !(defined(__cpp_rtti) || defined(__coverity_undefine___cpp_rtti))
#define __cpp_rtti 199711L
#endif
#if !(defined(__cpp_rvalue_references) || defined(__coverity_undefine___cpp_rvalue_references))
#define __cpp_rvalue_references 200610L
#endif
#if !(defined(__cpp_static_assert) || defined(__coverity_undefine___cpp_static_assert))
#define __cpp_static_assert 201411L
#endif
#if !(defined(__cpp_static_call_operator) || defined(__coverity_undefine___cpp_static_call_operator))
#define __cpp_static_call_operator 202207L
#endif
#if !(defined(__cpp_structured_bindings) || defined(__coverity_undefine___cpp_structured_bindings))
#define __cpp_structured_bindings 201606L
#endif
#if !(defined(__cpp_template_auto) || defined(__coverity_undefine___cpp_template_auto))
#define __cpp_template_auto 201606L
#endif
#if !(defined(__cpp_threadsafe_static_init) || defined(__coverity_undefine___cpp_threadsafe_static_init))
#define __cpp_threadsafe_static_init 200806L
#endif
#if !(defined(__cpp_unicode_characters) || defined(__coverity_undefine___cpp_unicode_characters))
#define __cpp_unicode_characters 200704L
#endif
#if !(defined(__cpp_unicode_literals) || defined(__coverity_undefine___cpp_unicode_literals))
#define __cpp_unicode_literals 200710L
#endif
#if !(defined(__cpp_user_defined_literals) || defined(__coverity_undefine___cpp_user_defined_literals))
#define __cpp_user_defined_literals 200809L
#endif
#if !(defined(__cpp_variable_templates) || defined(__coverity_undefine___cpp_variable_templates))
#define __cpp_variable_templates 201304L
#endif
#if !(defined(__cpp_variadic_templates) || defined(__coverity_undefine___cpp_variadic_templates))
#define __cpp_variadic_templates 200704L
#endif
#if !(defined(__cpp_variadic_using) || defined(__coverity_undefine___cpp_variadic_using))
#define __cpp_variadic_using 201611L
#endif
#if !(defined(__declspec) || defined(__coverity_undefine___declspec))
#define __declspec(a) __attribute__((a))
#endif
#if !(defined(__fastcall) || defined(__coverity_undefine___fastcall))
#define __fastcall __attribute__((__fastcall__))
#endif
#if !(defined(__k8) || defined(__coverity_undefine___k8))
#define __k8 1
#endif
#if !(defined(__k8__) || defined(__coverity_undefine___k8__))
#define __k8__ 1
#endif
#if !(defined(__llvm__) || defined(__coverity_undefine___llvm__))
#define __llvm__ 1
#endif
#if !(defined(__pascal) || defined(__coverity_undefine___pascal))
#define __pascal __attribute__((__pascal__))
#endif
#if !(defined(__pic__) || defined(__coverity_undefine___pic__))
#define __pic__ 2
#endif
#if !(defined(__private_extern__) || defined(__coverity_undefine___private_extern__))
#define __private_extern__ extern
#endif
#if !(defined(__seg_fs) || defined(__coverity_undefine___seg_fs))
#define __seg_fs __attribute__((address_space(257)))
#endif
#if !(defined(__seg_gs) || defined(__coverity_undefine___seg_gs))
#define __seg_gs __attribute__((address_space(256)))
#endif
#if !(defined(__stdcall) || defined(__coverity_undefine___stdcall))
#define __stdcall __attribute__((__stdcall__))
#endif
#if !(defined(__strong) || defined(__coverity_undefine___strong))
#define __strong __attribute__((objc_ownership(strong)))
#endif
#if !(defined(__thiscall) || defined(__coverity_undefine___thiscall))
#define __thiscall __attribute__((__thiscall__))
#endif
#if !(defined(__tune_k8__) || defined(__coverity_undefine___tune_k8__))
#define __tune_k8__ 1
#endif
#if !(defined(__unsafe_unretained) || defined(__coverity_undefine___unsafe_unretained))
#define __unsafe_unretained __attribute__((objc_ownership(none)))
#endif
#if !(defined(__weak) || defined(__coverity_undefine___weak))
#define __weak __attribute__((objc_ownership(weak)))
#endif
#if !(defined(__x86_64) || defined(__coverity_undefine___x86_64))
#define __x86_64 1
#endif
#if !(defined(__x86_64__) || defined(__coverity_undefine___x86_64__))
#define __x86_64__ 1
#endif
#if !(defined(_cdecl) || defined(__coverity_undefine__cdecl))
#define _cdecl __attribute__((__cdecl__))
#endif
#if !(defined(_fastcall) || defined(__coverity_undefine__fastcall))
#define _fastcall __attribute__((__fastcall__))
#endif
#if !(defined(_pascal) || defined(__coverity_undefine__pascal))
#define _pascal __attribute__((__pascal__))
#endif
#if !(defined(_stdcall) || defined(__coverity_undefine__stdcall))
#define _stdcall __attribute__((__stdcall__))
#endif
#if !(defined(_thiscall) || defined(__coverity_undefine__thiscall))
#define _thiscall __attribute__((__thiscall__))
#endif
#if !(defined(__STDCPP_DEFAULT_NEW_ALIGNMENT__) || defined(__coverity_undefine___STDCPP_DEFAULT_NEW_ALIGNMENT__))
#define __STDCPP_DEFAULT_NEW_ALIGNMENT__ 16ULL
#endif
#if !(defined(__cpp_aggregate_bases) || defined(__coverity_undefine___cpp_aggregate_bases))
#define __cpp_aggregate_bases 201603L
#endif
#if !(defined(__cpp_aggregate_nsdmi) || defined(__coverity_undefine___cpp_aggregate_nsdmi))
#define __cpp_aggregate_nsdmi 201304L
#endif
#if !(defined(__cpp_alias_templates) || defined(__coverity_undefine___cpp_alias_templates))
#define __cpp_alias_templates 200704L
#endif
#if !(defined(__cpp_aligned_new) || defined(__coverity_undefine___cpp_aligned_new))
#define __cpp_aligned_new 201606L
#endif
#if !(defined(__cpp_attributes) || defined(__coverity_undefine___cpp_attributes))
#define __cpp_attributes 200809L
#endif
#if !(defined(__cpp_binary_literals) || defined(__coverity_undefine___cpp_binary_literals))
#define __cpp_binary_literals 201304L
#endif
#if !(defined(__cpp_capture_star_this) || defined(__coverity_undefine___cpp_capture_star_this))
#define __cpp_capture_star_this 201603L
#endif
#if !(defined(__cpp_constexpr) || defined(__coverity_undefine___cpp_constexpr))
#define __cpp_constexpr 201603L
#endif
#if !(defined(__cpp_constexpr_in_decltype) || defined(__coverity_undefine___cpp_constexpr_in_decltype))
#define __cpp_constexpr_in_decltype 201711L
#endif
#if !(defined(__cpp_decltype) || defined(__coverity_undefine___cpp_decltype))
#define __cpp_decltype 200707L
#endif
#if !(defined(__cpp_decltype_auto) || defined(__coverity_undefine___cpp_decltype_auto))
#define __cpp_decltype_auto 201304L
#endif
#if !(defined(__cpp_deduction_guides) || defined(__coverity_undefine___cpp_deduction_guides))
#define __cpp_deduction_guides 201703L
#endif
#if !(defined(__cpp_delegating_constructors) || defined(__coverity_undefine___cpp_delegating_constructors))
#define __cpp_delegating_constructors 200604L
#endif
#if !(defined(__cpp_enumerator_attributes) || defined(__coverity_undefine___cpp_enumerator_attributes))
#define __cpp_enumerator_attributes 201411L
#endif
#if !(defined(__cpp_exceptions) || defined(__coverity_undefine___cpp_exceptions))
#define __cpp_exceptions 199711L
#endif
#if !(defined(__cpp_fold_expressions) || defined(__coverity_undefine___cpp_fold_expressions))
#define __cpp_fold_expressions 201603L
#endif
#if !(defined(__cpp_generic_lambdas) || defined(__coverity_undefine___cpp_generic_lambdas))
#define __cpp_generic_lambdas 201304L
#endif
#if !(defined(__cpp_guaranteed_copy_elision) || defined(__coverity_undefine___cpp_guaranteed_copy_elision))
#define __cpp_guaranteed_copy_elision 201606L
#endif
#if !(defined(__cpp_hex_float) || defined(__coverity_undefine___cpp_hex_float))
#define __cpp_hex_float 201603L
#endif
#if !(defined(__cpp_if_constexpr) || defined(__coverity_undefine___cpp_if_constexpr))
#define __cpp_if_constexpr 201606L
#endif
#if !(defined(__cpp_impl_destroying_delete) || defined(__coverity_undefine___cpp_impl_destroying_delete))
#define __cpp_impl_destroying_delete 201806L
#endif
#if !(defined(__cpp_inheriting_constructors) || defined(__coverity_undefine___cpp_inheriting_constructors))
#define __cpp_inheriting_constructors 201511L
#endif
#if !(defined(__cpp_init_captures) || defined(__coverity_undefine___cpp_init_captures))
#define __cpp_init_captures 201304L
#endif
#if !(defined(__cpp_initializer_lists) || defined(__coverity_undefine___cpp_initializer_lists))
#define __cpp_initializer_lists 200806L
#endif
#if !(defined(__cpp_inline_variables) || defined(__coverity_undefine___cpp_inline_variables))
#define __cpp_inline_variables 201606L
#endif
#if !(defined(__cpp_lambdas) || defined(__coverity_undefine___cpp_lambdas))
#define __cpp_lambdas 200907L
#endif
#if !(defined(__cpp_namespace_attributes) || defined(__coverity_undefine___cpp_namespace_attributes))
#define __cpp_namespace_attributes 201411L
#endif
#if !(defined(__cpp_nested_namespace_definitions) || defined(__coverity_undefine___cpp_nested_namespace_definitions))
#define __cpp_nested_namespace_definitions 201411L
#endif
#if !(defined(__cpp_noexcept_function_type) || defined(__coverity_undefine___cpp_noexcept_function_type))
#define __cpp_noexcept_function_type 201510L
#endif
#if !(defined(__cpp_nontype_template_args) || defined(__coverity_undefine___cpp_nontype_template_args))
#define __cpp_nontype_template_args 201411L
#endif
#if !(defined(__cpp_nontype_template_parameter_auto) || defined(__coverity_undefine___cpp_nontype_template_parameter_auto))
#define __cpp_nontype_template_parameter_auto 201606L
#endif
#if !(defined(__cpp_nsdmi) || defined(__coverity_undefine___cpp_nsdmi))
#define __cpp_nsdmi 200809L
#endif
#if !(defined(__cpp_range_based_for) || defined(__coverity_undefine___cpp_range_based_for))
#define __cpp_range_based_for 201603L
#endif
#if !(defined(__cpp_raw_strings) || defined(__coverity_undefine___cpp_raw_strings))
#define __cpp_raw_strings 200710L
#endif
#if !(defined(__cpp_ref_qualifiers) || defined(__coverity_undefine___cpp_ref_qualifiers))
#define __cpp_ref_qualifiers 200710L
#endif
#if !(defined(__cpp_return_type_deduction) || defined(__coverity_undefine___cpp_return_type_deduction))
#define __cpp_return_type_deduction 201304L
#endif
#if !(defined(__cpp_rtti) || defined(__coverity_undefine___cpp_rtti))
#define __cpp_rtti 199711L
#endif
#if !(defined(__cpp_rvalue_references) || defined(__coverity_undefine___cpp_rvalue_references))
#define __cpp_rvalue_references 200610L
#endif
#if !(defined(__cpp_static_assert) || defined(__coverity_undefine___cpp_static_assert))
#define __cpp_static_assert 201411L
#endif
#if !(defined(__cpp_structured_bindings) || defined(__coverity_undefine___cpp_structured_bindings))
#define __cpp_structured_bindings 201606L
#endif
#if !(defined(__cpp_threadsafe_static_init) || defined(__coverity_undefine___cpp_threadsafe_static_init))
#define __cpp_threadsafe_static_init 200806L
#endif
#if !(defined(__cpp_unicode_characters) || defined(__coverity_undefine___cpp_unicode_characters))
#define __cpp_unicode_characters 200704L
#endif
#if !(defined(__cpp_unicode_literals) || defined(__coverity_undefine___cpp_unicode_literals))
#define __cpp_unicode_literals 200710L
#endif
#if !(defined(__cpp_user_defined_literals) || defined(__coverity_undefine___cpp_user_defined_literals))
#define __cpp_user_defined_literals 200809L
#endif
#if !(defined(__cpp_variable_templates) || defined(__coverity_undefine___cpp_variable_templates))
#define __cpp_variable_templates 201304L
#endif
#if !(defined(__cpp_variadic_templates) || defined(__coverity_undefine___cpp_variadic_templates))
#define __cpp_variadic_templates 200704L
#endif
#if !(defined(__cpp_variadic_using) || defined(__coverity_undefine___cpp_variadic_using))
#define __cpp_variadic_using 201611L
#endif