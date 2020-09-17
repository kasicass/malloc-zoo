#pragma once

// ----------------------------------------------------------------------------
// This header provides convenient overrides for the new and
// delete operations in C++.
//
// This header should be included in only one source file!
//
// On Windows, or when linking dynamically with mimalloc, these
// can be more performant than the standard new-delete operations.
// See <https://en.cppreference.com/w/cpp/memory/new/operator_new>
// ---------------------------------------------------------------------------
#if defined(__cplusplus)
#include <new>
#include "MallocZoo.h"

void operator delete(void* p) noexcept   { FatFree(p); };
void operator delete[](void* p) noexcept { FatFree(p); };

void* operator new(std::size_t n) noexcept(false)   { return FatMalloc(n); }
void* operator new[](std::size_t n) noexcept(false) { return FatMalloc(n); }

void* operator new  (std::size_t n, const std::nothrow_t& tag) noexcept { (void)(tag); return FatMalloc(n); }
void* operator new[](std::size_t n, const std::nothrow_t& tag) noexcept { (void)(tag); return FatMalloc(n); }

#endif
