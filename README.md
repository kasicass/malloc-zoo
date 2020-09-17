# Malloc Zoo

## Objective

 * benchmark various memory allocator implementations
 * a heap-profiler inspired by [gperftools][1]


## Architecture

```
MallocZoo.dll                  malloc/free abstract layer
MallocZooKeeper.dll            heap-profiler
MallocAnimalRaw.dll            raw, system malloc/free
MallocAnimalMimalloc.dll       mimalloc, Microsoft 
MallocAnimalJemalloc.dll       jemalloc, FreeBSD libc
MallocAnimalTcmalloc.dll       tcmalloc, google perftools
```

## About Project Name

 * It's fun, huh?


[1]:https://github.com/gperftools/gperftools
