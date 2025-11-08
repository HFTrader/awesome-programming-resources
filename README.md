# awesome-programming-resources

My curated collection of great sources of information for programming

The code inside **substack** was moved to [AssemblyTales](https://github.com/HFTrader/AssemblyTales)

# Hardware

## x86/x64 Architecture

[What Every Programmer Should Know About Memory](papers/cpumemory.pdf)
*Landmark 2007 paper explaining CPU cache hierarchy, memory bandwidth, and latency impacts. Essential for understanding performance characteristics of modern processors and writing cache-friendly code.*

[System V Application Binary Interface](papers/x86-64-psABI-1.0.pdf)
*Defines calling conventions, register usage, stack layout, and object file formats for x86-64 Linux systems. Critical for compiler writers, low-level programmers, and understanding assembly/C interop.*

[Intel® 64 and IA-32 Architectures - Software Developer's Manual - Latest](https://www.intel.com/content/www/us/en/developer/articles/technical/intel-sdm.html)
*The definitive reference for Intel instruction set architecture. Covers every instruction, architectural details, system programming, and virtualization. The bible for x86 development.*

[Intel 64 and IA32 Optimization Reference Manual - Latest](https://www.intel.com/content/www/us/en/content-details/671488/intel-64-and-ia-32-architectures-optimization-reference-manual-volume-1.html)
*Intel's official guide to writing high-performance code. Details microarchitectural optimization techniques, instruction throughput, branch prediction, and cache behavior for Intel CPUs.*

[Intel Architecture Instruction Set Extensions and Future Reference - Latest](https://www.intel.com/content/www/us/en/developer/articles/technical/intel-sdm.html)
*Documents new and upcoming x86 instruction set extensions (AVX-512, AMX, etc.). Essential for staying current with latest SIMD and accelerator capabilities.*

[Intel Intrinsics Guide (online)](https://www.intel.com/content/www/us/en/docs/intrinsics-guide/index.html)
*Searchable database of all Intel intrinsics with detailed documentation, pseudocode, and performance characteristics. Indispensable for SIMD programming with SSE, AVX, AVX-512.*

[Instruction Latencies and Throughput for Intel and AMD Processors - Agner Fog Latest](https://www.agner.org/optimize/)
*Comprehensive tables of instruction timing for all modern CPUs. Critical for performance optimization, understanding execution ports, and instruction-level parallelism. Industry-standard reference.*

[Agner Fog's Optimization Manuals (Complete Collection)](https://www.agner.org/optimize/)
*Five detailed manuals covering optimization in C++, assembly, microarchitecture, and calling conventions. Practical, authoritative guidance based on extensive testing and research.*

[Micro-ops complete reference](https://uops.info/)
*Database showing how instructions decompose into micro-operations on various CPU architectures. Essential for understanding execution unit pressure and optimizing hot loops.*

## AMD Architecture

[AMD64 Architecture Programmer's Manual - Latest](https://www.amd.com/en/search/documentation/hub.html)
*Official AMD specification for x86-64 architecture, instruction set, system programming, and virtualization. Critical for understanding AMD-specific features and architectural differences from Intel.*

[AMD Software Optimization Guide - Latest](https://www.amd.com/en/search/documentation/hub.html)
*AMD's recommendations for optimizing code on Zen architectures. Covers microarchitecture-specific details, instruction scheduling, and cache optimization for EPYC and Ryzen processors.*

[Performance Tuning Guidelines for AMD EPYC 9004 Series (Genoa)](https://www.amd.com/en/developer/resources/technical-publications.html)
*Specific tuning guide for latest EPYC processors. Details NUMA topology, memory configuration, core chiplet design, and workload-specific optimization strategies for server deployments.*

[AMD EPYC 4th Gen (Genoa) Tuning Guide](https://www.amd.com/en/developer/resources/technical-publications.html)
*Platform-level tuning for Genoa systems including BIOS settings, OS configuration, and performance monitoring. Essential for extracting maximum performance in HPC and datacenter environments.*

[AMD Software development manuals](https://developer.amd.com/resources/developer-guides-manuals/)
*Complete collection of AMD technical documentation including architecture manuals, optimization guides, and programming references for all AMD processor families.*

## ARM Architecture

[ARM Architecture Reference Manual for A-profile](https://developer.arm.com/documentation/ddi0487/latest)
*Complete architectural specification for ARMv8/v9 A-profile processors. Definitive reference for instruction encoding, system registers, exception handling, and memory model for servers and workstations.*

[ARM Cortex-A Series Programmer's Guide](https://developer.arm.com/documentation/)
*Practical guide to programming ARM Cortex-A processors. Covers optimization techniques, cache management, NEON SIMD, and architectural features specific to high-performance ARM cores.*

[ARM Neon Intrinsics Reference](https://developer.arm.com/architectures/instruction-sets/intrinsics/)
*Complete reference for ARM NEON SIMD intrinsics. Essential for vectorizing code on ARM processors including Apple Silicon, AWS Graviton, and mobile devices.*

[ARM SVE (Scalable Vector Extension) Specification](https://developer.arm.com/documentation/ddi0584/latest)
*Specification for ARM's scalable vector extension supporting variable vector lengths. Critical for HPC and server optimization on modern ARM processors with advanced SIMD.*

[Apple Silicon M-Series Documentation](https://developer.apple.com/documentation/apple-silicon)
*Official Apple documentation for developing and optimizing applications on M1/M2/M3 chips. Covers architecture-specific features, performance guidelines, and Rosetta 2 translation.*

[AWS Graviton Performance Runbook](https://github.com/aws/aws-graviton-getting-started)
*AWS's practical guide to optimizing workloads for Graviton processors. Includes compiler flags, library recommendations, and performance tuning for cloud-native ARM deployments.*

## RISC-V Architecture

[RISC-V Instruction Set Manual - Latest Ratified](https://github.com/riscv/riscv-isa-manual/releases)
*Official specification for the open RISC-V ISA. Covers base integer instructions, extensions, and privileged architecture. Essential for anyone working with RISC-V hardware or simulators.*

[RISC-V Assembly Programmer's Manual](https://github.com/riscv-non-isa/riscv-asm-manual)
*Practical guide to RISC-V assembly programming including pseudoinstructions, calling conventions, and common patterns. Useful for compiler development and low-level RISC-V programming.*

[RISC-V Vector Extension Specification](https://github.com/riscv/riscv-v-spec)
*Specification for RISC-V's vector extension supporting scalable SIMD operations. Important for understanding vectorization capabilities on emerging RISC-V processors.*

# FPGA

[Xilinx Design Hubs](https://www.xilinx.com/support/documentation-navigation/design-hubs.html)
*Organized collection of Xilinx FPGA documentation by application domain. Central portal for finding UltraScale+, Versal, and Zynq technical references, tutorials, and design guides.*

[Xilinx Documentation Portal](https://docs.xilinx.com/home)
*Searchable repository of all Xilinx/AMD FPGA documentation. Includes user guides, data sheets, application notes, and IP core documentation for entire product line.*

[AMD Xilinx Vitis Unified Software Platform](https://www.xilinx.com/products/design-tools/vitis.html)
*Modern development environment for Xilinx FPGAs supporting C/C++, OpenCL, and RTL. Enables heterogeneous computing with software-like programming models for hardware acceleration.*

[Intel FPGA Documentation](https://www.intel.com/content/www/us/en/products/details/fpga/development-tools/quartus-prime.html)
*Complete documentation for Intel (Altera) FPGAs and Quartus development tools. Covers Stratix, Arria, and Cyclone families with design guides and IP documentation.*

# GPU & Accelerator Programming

## NVIDIA CUDA

[CUDA Programming Guide](https://docs.nvidia.com/cuda/cuda-c-programming-guide/)
*Comprehensive guide to CUDA C++ programming. Covers thread hierarchy, memory model, synchronization, and kernel optimization. Essential starting point for NVIDIA GPU programming.*

[CUDA Best Practices Guide](https://docs.nvidia.com/cuda/cuda-c-best-practices-guide/)
*Official optimization strategies for CUDA applications. Details memory coalescing, occupancy, kernel launch configuration, and performance patterns for extracting maximum GPU performance.*

[CUDA Toolkit Documentation](https://docs.nvidia.com/cuda/)
*Complete reference for CUDA libraries, compiler, debugger, and profiler. Includes API documentation for cuBLAS, cuFFT, Thrust, and other CUDA ecosystem tools.*

[Nsight Systems Profiler](https://developer.nvidia.com/nsight-systems)
*System-wide performance analysis tool for CUDA applications. Profiles CPU-GPU interaction, kernel launches, memory transfers, and library calls to identify bottlenecks.*

[Nsight Compute Profiler](https://developer.nvidia.com/nsight-compute)
*Kernel-level profiler providing detailed GPU metrics. Analyzes warp execution, memory throughput, instruction mix, and provides optimization suggestions for individual kernels.*

[cuBLAS Library](https://docs.nvidia.com/cuda/cublas/)
*GPU-accelerated BLAS (Basic Linear Algebra Subprograms) library. Provides highly optimized matrix operations critical for scientific computing and deep learning.*

[cuDNN Deep Neural Network Library](https://developer.nvidia.com/cudnn)
*NVIDIA's library of optimized deep learning primitives. Implements convolutions, pooling, normalization, and activations used by all major deep learning frameworks.*

## AMD ROCm

[ROCm Documentation](https://rocm.docs.amd.com/)
*Complete documentation for AMD's open-source GPU compute platform. Covers programming models, runtime, libraries, and tools for AMD Instinct and Radeon GPUs.*

[HIP Programming Guide](https://rocm.docs.amd.com/projects/HIP/en/latest/)
*Guide to HIP (Heterogeneous-Compute Interface for Portability), AMD's CUDA-compatible API. Enables code portability between NVIDIA and AMD GPUs with minimal changes.*

[ROCm Libraries](https://rocm.docs.amd.com/en/latest/reference/rocm-libraries.html)
*Collection of GPU-accelerated libraries for AMD GPUs including rocBLAS, rocFFT, and MIOpen. AMD equivalents to CUDA libraries for compute and deep learning.*

## OpenCL

[OpenCL Programming Guide](https://www.khronos.org/opencl/)
*Introduction to the open standard for heterogeneous parallel programming. Works across CPUs, GPUs, and FPGAs from multiple vendors enabling portable accelerator code.*

[OpenCL Specification](https://registry.khronos.org/OpenCL/)
*Official OpenCL language and API specification. Defines platform model, execution model, memory model, and programming interface for cross-vendor heterogeneous computing.*

## Intel oneAPI

[Intel oneAPI Documentation](https://www.intel.com/content/www/us/en/developer/tools/oneapi/overview.html)
*Intel's unified programming model for CPUs, GPUs, and FPGAs. Includes DPC++, libraries, and tools for cross-architecture performance and productivity.*

[SYCL Programming Guide](https://www.khronos.org/sycl/)
*Standard C++-based heterogeneous programming model. Enables single-source programming for CPUs and accelerators with modern C++ syntax and abstractions.*

[Intel DPC++ (Data Parallel C++)](https://www.intel.com/content/www/us/en/developer/tools/oneapi/dpc-compiler.html)
*Intel's implementation of SYCL with extensions. Compiles to Intel CPUs, GPUs (Arc, Flex, Max), and FPGAs from single codebase.*

## Portable GPU Programming

[Kokkos Programming Guide](https://kokkos.github.io/kokkos-core-wiki/)
*Performance-portable programming model for HPC. Abstracts parallelism and memory spaces to run efficiently on CPUs, NVIDIA GPUs, AMD GPUs, and other architectures.*

[RAJA Performance Portability Layer](https://raja.readthedocs.io/)
*C++ library from LLNL providing portable parallel execution patterns. Enables writing loops that compile for CPUs, CUDA, HIP, and SYCL backends.*

[Alpaka](https://alpaka.readthedocs.io/)
*Header-only C++ abstraction library for accelerator programming. Single source code targets CPUs, CUDA, HIP, and SYCL with compile-time backend selection.*

# Unix & Linux

## Core Documentation

The GNU C Library Reference Manual [PDF](papers/glibc-manual.pdf) [HTML](https://www.gnu.org/software/libc/manual/html_mono/libc.html)
*Complete reference for glibc, the GNU C standard library used on Linux. Documents every function, macro, and system interface. Essential for understanding Linux system programming.*

[POSIX.1-2024 (IEEE Std 1003.1)](https://pubs.opengroup.org/onlinepubs/9799919799/)
*Official POSIX specification defining portable operating system interfaces. Critical for writing portable Unix/Linux code and understanding standard system call behavior across platforms.*

[Linux man-pages project](https://www.kernel.org/doc/man-pages/)
*Canonical source for Linux manual pages documenting system calls, library functions, and file formats. The authoritative reference for Linux-specific API behavior.*

[Advanced Programming in the UNIX Environment (APUE)](https://www.apuebook.com/)
*Classic book on Unix systems programming covering files, processes, signals, IPC, and threads. Widely regarded as the most comprehensive Unix programming reference.*

## System Programming

[The Linux Programming Interface (TLPI)](https://man7.org/tlpi/)
*Comprehensive 1500+ page guide to Linux system programming. Covers system calls, file I/O, processes, signals, sockets, and more with detailed examples.*

[System Programming (LWN.net Articles)](https://lwn.net/)
*Linux Weekly News articles covering kernel development, new system calls, and system programming topics. Excellent for staying current with Linux internals.*

[Linux System Call Reference](https://man7.org/linux/man-pages/man2/syscalls.2.html)
*Complete list of all Linux system calls with links to their manual pages. Quick reference for kernel interface and understanding what operations require syscalls.*

## Shell & Scripting

[Advanced Bash-Scripting Guide](https://tldp.org/LDP/abs/html/)
*Comprehensive tutorial on bash scripting from basics to advanced topics. Covers variables, control flow, functions, text processing, and script development best practices.*

[Bash Reference Manual](https://www.gnu.org/software/bash/manual/bash.html)
*Official bash documentation describing language syntax, built-ins, and shell features. The authoritative reference for bash scripting and command-line usage.*

[ShellCheck - Shell Script Analysis Tool](https://www.shellcheck.net/)
*Static analysis tool for shell scripts identifying bugs, portability issues, and style problems. Essential for writing robust and maintainable shell scripts.*

# C++

## Standards & References

[C++ Standards Drafts on Github](https://github.com/cplusplus/draft)
*LaTeX source for C++ standard working drafts. For reading latest committee proposals and tracking language evolution. Requires compilation to generate readable PDFs.*

[Latest C++ Standard - generated from above](https://eel.is/c++draft/)
*HTML rendering of current C++ working draft. Most accessible way to read the complete language specification with search and hyperlinks.*

[C++23 Standard (ISO/IEC 14882:2023)](https://isocpp.org/std/the-standard)
*Information about C++23, the latest finalized standard. Includes ranges improvements, coroutine enhancements, modules, and numerous library additions.*

[C++26 Working Draft](https://eel.is/c++draft/)
*Preview of upcoming C++26 features under active development. Tracks proposed language changes like reflection, pattern matching, and execution improvements.*

[cppreference.com - Complete C++ Reference](https://en.cppreference.com/)
*Community-maintained comprehensive C++ reference covering language and standard library. Better organized and more practical than the official standard for daily use.*

[C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/CppCoreGuidelines)
*Bjarne Stroustrup's authoritative best practices for modern C++. Covers resource management, type safety, bounds safety, and effective use of modern features.*

## Modern C++ Resources

[CppCon Videos (YouTube)](https://www.youtube.com/@CppCon)
*Annual C++ conference talks from world experts. Covers latest features, best practices, performance optimization, and advanced techniques. Essential learning resource.*

[C++ Weekly by Jason Turner](https://www.youtube.com/@cppweekly)
*Short weekly videos on C++ tips, tricks, and features. Practical demonstrations of modern C++ idioms and optimization techniques.*

[Awesome Modern C++](https://github.com/rigtorp/awesome-modern-cpp)
*Curated list of C++ libraries, frameworks, and resources. Organized by category, helps discover high-quality modern C++ projects and tools.*

[Modern C++ Features - C++11/14/17/20/23](https://github.com/AnthonyCalandra/modern-cpp-features)
*Concise cheat sheet of features introduced in each C++ version. Quick reference with code examples showing new language capabilities.*

## Build Systems & Tooling

[CMake Official Documentation](https://cmake.org/documentation/)
*Reference for CMake, the de facto standard C++ build system. Covers generators, modules, find packages, and cross-platform build configuration.*

[Modern CMake (Book)](https://cliutils.gitlab.io/modern-cmake/)
*Best practices for CMake 3.x avoiding legacy patterns. Teaches target-based approach, proper dependency management, and maintainable build configurations.*

[Bazel Build System](https://bazel.build/)
*Google's build system designed for large monorepos. Provides hermetic builds, remote caching, and excellent multi-language support for scalable projects.*

[Meson Build System](https://mesonbuild.com/)
*Fast, user-friendly build system with simple syntax. Excellent alternative to CMake with better defaults and faster configuration times.*

[Conan Package Manager](https://conan.io/)
*C/C++ package manager supporting multiple platforms and compilers. Handles transitive dependencies and integrates with CMake, Meson, and other build systems.*

[vcpkg Package Manager](https://vcpkg.io/)
*Microsoft's cross-platform C++ package manager. Large registry of libraries with CMake integration, making dependency management straightforward.*

## Static Analysis & Sanitizers

[Clang-Tidy Documentation](https://clang.llvm.org/extra/clang-tidy/)
*Clang-based linter with hundreds of checks for bugs, performance issues, and style violations. Integrates with build systems and can auto-fix issues.*

[Clang Static Analyzer](https://clang-analyzer.llvm.org/)
*Deep static analysis tool finding bugs through symbolic execution. Detects memory leaks, null dereferences, and use-after-free without running code.*

[AddressSanitizer (ASan)](https://github.com/google/sanitizers/wiki/AddressSanitizer)
*Runtime detector for memory errors like buffer overflows, use-after-free, and leaks. Essential tool for finding memory bugs with low overhead.*

[ThreadSanitizer (TSan)](https://github.com/google/sanitizers/wiki/ThreadSanitizerCppManual)
*Runtime detector for data races and threading bugs. Finds race conditions, deadlocks, and synchronization issues in concurrent code.*

[UndefinedBehaviorSanitizer (UBSan)](https://clang.llvm.org/docs/UndefinedBehaviorSanitizer.html)
*Catches undefined behavior at runtime including integer overflow, null pointer dereference, and type violations. Critical for correctness testing.*

[MemorySanitizer (MSan)](https://github.com/google/sanitizers/wiki/MemorySanitizer)
*Detects reads of uninitialized memory. Finds bugs where variables are used before initialization, particularly important for security.*

## Algorithms & Data Structures

[Hashed and Hierarchical Timed Wheels](papers/sosp87-timing-wheels.pdf)
*Classic 1987 paper on efficient timer implementation using hashed wheels. Foundation for timer queues in operating systems and network stacks.*

[Scheduler Problem](papers/scheduler_problem.png)
*Visualization of scheduling challenges and algorithms. Illustrates priority inversion, convoy effects, and fairness issues in task scheduling.*

[Fast Efficient Fixed Size Memory Pools](papers/computation_tools_2012_1_10_80006.pdf)
*Techniques for implementing high-performance memory pools. Reduces allocation overhead and fragmentation in performance-critical applications.*

## Testing

[Google Test (GTest)](https://github.com/google/googletest)
*Industry-standard C++ testing framework. Provides assertions, test fixtures, mocking, and death tests. Widely used and well-integrated with build systems.*

[Catch2 Testing Framework](https://github.com/catchorg/Catch2)
*Modern header-only test framework with natural syntax. Supports BDD-style tests, benchmarking, and excellent error messages without boilerplate.*

[Google Benchmark](https://github.com/google/benchmark)
*Microbenchmarking library from Google. Provides statistical analysis, timing various configurations, and preventing compiler optimizations from invalidating results.*

[Quick Bench - Online C++ Benchmarking](https://quick-bench.com/)
*Web-based tool for quick C++ performance comparisons. Runs benchmarks on consistent hardware and visualizes results for comparing implementations.*

# Compilers

## LLVM & Clang

[LLVM Documentation](https://llvm.org/docs/)
*Complete documentation for LLVM compiler infrastructure. Covers IR, passes, code generation, and tooling. Essential for compiler development and optimization work.*

[LLVM Language Reference Manual](https://llvm.org/docs/LangRef.html)
*Specification of LLVM intermediate representation. Defines instructions, type system, and semantics. Critical for writing LLVM passes and understanding optimization.*

[LLVM Programmer's Manual](https://llvm.org/docs/ProgrammersManual.html)
*Guide to LLVM APIs and idioms. Covers data structures, memory management, and conventions for developing LLVM tools and transformations.*

[Clang Documentation](https://clang.llvm.org/docs/)
*Documentation for Clang C/C++ compiler. Includes user guides, internal design, AST manipulation, and developing plugins. Foundation for static analysis tools.*

[LLVM Tutor](https://github.com/banach-space/llvm-tutor)
*Collection of example LLVM passes with detailed tutorials. Teaches pass development through practical examples from simple to advanced optimizations.*

[CLANG Tutor](https://github.com/banach-space/clang-tutor)
*Example Clang plugins demonstrating AST manipulation. Shows how to build static analysis tools, refactoring utilities, and custom compiler extensions.*

[MLIR (Multi-Level Intermediate Representation)](https://mlir.llvm.org/)
*Extensible compiler infrastructure for building domain-specific IRs. Used for machine learning compilers, hardware synthesis, and polyhedral optimization.*

## GCC

[GCC Online Documentation](https://gcc.gnu.org/onlinedocs/)
*Complete GCC documentation including user manuals, language standards support, and optimization guides. Reference for GNU compiler collection across C/C++/Fortran.*

[GCC Internals Manual](https://gcc.gnu.org/onlinedocs/gccint/)
*GCC internal architecture and pass pipeline documentation. Essential for developing GCC plugins, understanding optimizations, and contributing to GCC.*

[GCC Optimization Options](https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html)
*Detailed reference for GCC optimization flags. Explains -O levels, individual optimizations, and their impact on code generation and performance.*

## Compiler Theory

[Crafting Interpreters (online book)](https://craftinginterpreters.com/)
*Free online book building interpreters from scratch. Covers lexing, parsing, tree-walk and bytecode VMs. Excellent introduction to language implementation.*

[Engineering a Compiler](https://www.elsevier.com/books/engineering-a-compiler/cooper/978-0-12-815412-0)
*Comprehensive compiler textbook emphasizing optimization and code generation. Covers SSA, register allocation, instruction scheduling, and modern optimization techniques.*

[Dragon Book - Compilers: Principles, Techniques, and Tools](https://www.pearson.com/en-us/subject-catalog/p/compilers-principles-techniques-and-tools/P200000003190)
*Classic compiler textbook covering theory and practice. Authoritative reference for parsing algorithms, semantic analysis, and traditional optimization methods.*

## Tools & Analysis

[Compiler Explorer (Godbolt)](https://godbolt.org/)
*Interactive online tool showing assembly output from multiple compilers. Invaluable for understanding code generation, comparing optimizations, and learning assembly.*

[LLVM-MCA (Machine Code Analyzer)](https://llvm.org/docs/CommandGuide/llvm-mca.html)
*Tool for analyzing instruction-level performance of assembly. Predicts throughput, resource pressure, and identifies bottlenecks in tight loops.*

[Bloaty McBloatface - Size Profiler](https://github.com/google/bloaty)
*Binary size analyzer showing where code and data bloat originates. Helps reduce binary size by identifying large symbols, sections, and compilation units.* 


# Assembly

## x86/x64 Assembly

[x86 Assembly Guide (University of Virginia)](https://www.cs.virginia.edu/~evans/cs216/guides/x86.html)
*Concise introduction to x86 assembly covering registers, addressing modes, and common instructions. Good starting point for learning assembly programming basics.*

[x86-64 Assembly Language Programming with Ubuntu](papers/x86-64-assembly-ubuntu.pdf)
*Comprehensive textbook on x86-64 assembly for Linux. Covers system calls, data structures, floating-point, and practical programming examples.*

[Intel x86 Assembler Instruction Set Opcode Table](http://ref.x86asm.net/)
*Quick reference for x86 instruction encodings and opcodes. Useful for hand-assembling instructions or understanding binary instruction formats.*

[Sandpile.org - x86-64 Instruction Reference](https://www.sandpile.org/)
*Detailed x86 instruction reference with encoding, flags, and microarchitecture details. Comprehensive resource for assembly programming and reverse engineering.*

## ARM Assembly

[ARM Assembly Language Guide](https://developer.arm.com/documentation/den0013/latest)
*Official ARM assembly programming guide covering A-profile architecture. Explains instruction set, calling conventions, and optimization techniques for ARM processors.*

[ARM Assembly Basics (Azeria Labs)](https://azeria-labs.com/writing-arm-assembly-part-1/)
*Practical tutorial series on ARM assembly for reverse engineering and exploitation. Excellent hands-on introduction to ARM architecture and programming.*

## Assembly Tools

[NASM - The Netwide Assembler](https://www.nasm.us/)
*Popular x86 assembler with Intel syntax. Widely used for OS development, bootloaders, and low-level programming. Supports multiple object formats.*

[FASM - Flat Assembler](https://flatassembler.net/)
*Fast self-assembling assembler written in assembly. Known for speed, simplicity, and single-pass assembly. Popular for small binaries and demos.*

[GNU Assembler (GAS) Documentation](https://sourceware.org/binutils/docs/as/)
*Documentation for GAS, the assembler in GNU binutils. Uses AT&T syntax by default. Standard assembler for GCC and Linux development.*

# Container & Cloud Native

## Docker & Containers

[Docker Documentation](https://docs.docker.com/)
*Official Docker documentation covering images, containers, networking, and orchestration. Essential reference for containerization fundamentals and best practices.*

[Docker Best Practices](https://docs.docker.com/develop/dev-best-practices/)
*Guidelines for building efficient, secure Docker images. Covers layer optimization, security scanning, multi-stage builds, and production deployment strategies.*

[containerd](https://containerd.io/)
*Industry-standard container runtime used by Docker and Kubernetes. Lightweight daemon managing container lifecycle, images, and storage.*

[Podman Documentation](https://docs.podman.io/)
*Daemonless container engine compatible with Docker. Rootless containers, pod support, and systemd integration for security-focused environments.*

[BuildKit](https://github.com/moby/buildkit)
*Modern Docker build backend with parallel execution, caching improvements, and reproducible builds. Powers docker buildx and advanced build features.*

## Kubernetes

[Kubernetes Documentation](https://kubernetes.io/docs/home/)
*Complete Kubernetes documentation covering concepts, tasks, and API reference. Essential for container orchestration, scaling, and cloud-native deployments.*

[Kubernetes The Hard Way](https://github.com/kelseyhightower/kubernetes-the-hard-way)
*Tutorial bootstrapping Kubernetes from scratch without scripts. Teaches deep understanding of components, networking, and security through manual setup.*

[Kubernetes Patterns (Book)](https://www.redhat.com/en/resources/oreilly-kubernetes-patterns-cloud-native-apps)
*Design patterns for cloud-native applications on Kubernetes. Covers deployment strategies, configuration management, and operational patterns.*

[kubectl Reference](https://kubernetes.io/docs/reference/kubectl/)
*Complete kubectl command reference. Essential for cluster management, debugging, and resource manipulation in Kubernetes environments.*

## Service Mesh

[Istio Documentation](https://istio.io/latest/docs/)
*Service mesh providing traffic management, security, and observability. Handles service-to-service communication, mTLS, and advanced routing without code changes.*

[Linkerd Documentation](https://linkerd.io/2.14/overview/)
*Lightweight service mesh focused on simplicity and performance. Provides mutual TLS, load balancing, and observability with minimal configuration.*

[Envoy Proxy Documentation](https://www.envoyproxy.io/docs)
*High-performance proxy used by Istio and other service meshes. Provides advanced load balancing, observability, and traffic control at L7.*

## Observability

[Prometheus Documentation](https://prometheus.io/docs/)
*Time-series database and monitoring system for cloud-native applications. De facto standard for Kubernetes metrics collection and alerting.*

[Grafana Documentation](https://grafana.com/docs/)
*Visualization and analytics platform for metrics, logs, and traces. Creates dashboards from Prometheus, Elasticsearch, and other data sources.*

[Jaeger Tracing](https://www.jaegertracing.io/docs/)
*Distributed tracing system for monitoring microservices. Tracks requests across services to identify performance bottlenecks and dependencies.*

[OpenTelemetry](https://opentelemetry.io/docs/)
*Vendor-neutral observability framework for metrics, logs, and traces. Standardizes instrumentation across languages and backends.*

# Rust

## Official Documentation

[The Rust Programming Language (The Book)](https://doc.rust-lang.org/book/)
*Official Rust book teaching ownership, borrowing, lifetimes, and core concepts. Best starting point for learning Rust systematically with comprehensive examples.*

[Rust by Example](https://doc.rust-lang.org/rust-by-example/)
*Learn Rust through executable examples covering syntax and standard library. Complements The Book with practical, runnable code snippets.*

[The Rustonomicon (Unsafe Rust)](https://doc.rust-lang.org/nomicon/)
*Advanced guide to unsafe Rust covering FFI, raw pointers, and low-level details. Essential for systems programming and understanding Rust's safety boundaries.*

[The Rust Reference](https://doc.rust-lang.org/reference/)
*Normative documentation of Rust language semantics and behavior. Technical reference for understanding exact language rules and edge cases.*

[Rust API Guidelines](https://rust-lang.github.io/api-guidelines/)
*Best practices for designing Rust APIs. Covers naming conventions, type design, and idiomatic patterns for writing libraries.*

## Performance & Low-Level

[The Rust Performance Book](https://nnethercote.github.io/perf-book/)
*Guide to profiling and optimizing Rust code. Covers benchmarking, allocation reduction, and compiler optimization techniques.*

[Rust Compiler Performance](https://perf.rust-lang.org/)
*Tracking dashboard for Rust compiler performance over time. Useful for understanding compilation time regressions and improvements.*

[Inline Assembly in Rust](https://doc.rust-lang.org/reference/inline-assembly.html)
*Documentation for writing assembly within Rust using asm! macro. Essential for performance-critical code and platform-specific optimizations.*

## Async & Concurrency

[Asynchronous Programming in Rust](https://rust-lang.github.io/async-book/)
*Official guide to async/await, futures, and asynchronous programming patterns. Covers runtime selection, async traits, and concurrency primitives.*

[Tokio Tutorial](https://tokio.rs/tokio/tutorial)
*Tutorial for Tokio async runtime. Teaches building async applications with TCP servers, timers, and channels. Industry-standard async ecosystem.*

## Embedded & Systems

[The Embedded Rust Book](https://docs.rust-embedded.org/book/)
*Guide to embedded programming with Rust on microcontrollers. Covers no_std development, peripheral access, and real-time constraints.*

[The Embedonomicon](https://docs.rust-embedded.org/embedonomicon/)
*Deep dive into embedded Rust internals. Explains linker scripts, startup code, and building runtime from scratch for bare metal.*

[Writing an OS in Rust](https://os.phil-opp.com/)
*Tutorial series building x86 operating system in Rust. Covers bootloader, memory management, interrupts, and kernel development from scratch.*

## Advanced Topics

[Rust Design Patterns](https://rust-unofficial.github.io/patterns/)
*Collection of idiomatic Rust patterns and anti-patterns. Covers architectural patterns, creational patterns, and Rust-specific idioms.*

[Too Many Linked Lists](https://rust-unofficial.github.io/too-many-lists/)
*Learn advanced Rust through implementing linked lists. Teaches unsafe code, interior mutability, and memory management through practical examples.*

[Crust of Rust (Jon Gjengset)](https://www.youtube.com/playlist?list=PLqbS7AVVErFiWDOAVrPt7aYmnuuOLYvOa)
*Video series diving deep into Rust internals and advanced topics. Covers iterators, smart pointers, async, and intermediate-to-advanced concepts.*

# WebAssembly

## Official Documentation

[WebAssembly Specification](https://webassembly.github.io/spec/)
*Official WebAssembly specification defining instruction set, binary format, and execution semantics. Reference for implementing runtimes and understanding Wasm internals.*

[WebAssembly MDN Documentation](https://developer.mozilla.org/en-US/docs/WebAssembly)
*Practical guide to using WebAssembly in web browsers. Covers JavaScript API, loading modules, and integrating Wasm with web applications.*

[WebAssembly.org](https://webassembly.org/)
*Official WebAssembly website with introductions, use cases, and getting started guides. Central hub for community resources and specifications.*

## Tooling & Runtimes

[Wasmtime - Standalone WebAssembly Runtime](https://wasmtime.dev/)
*Fast and secure WebAssembly runtime from Bytecode Alliance. Implements WASI for running Wasm outside browsers with sandboxing and JIT compilation.*

[WasmEdge - Lightweight Runtime](https://wasmedge.org/)
*High-performance Wasm runtime optimized for edge computing and cloud-native applications. Supports WASI, networking extensions, and serverless deployments.*

[WASI (WebAssembly System Interface)](https://wasi.dev/)
*System interface standard for WebAssembly. Provides portable access to files, networking, and OS resources for non-browser environments.*

[wasm-pack - Rust to WebAssembly](https://rustwasm.github.io/wasm-pack/)
*Build tool for compiling Rust to WebAssembly. Handles npm integration, JavaScript bindings generation, and packaging for web deployment.*

[Emscripten - C/C++ to WebAssembly](https://emscripten.org/)
*Compiler toolchain converting C/C++ to WebAssembly. Provides POSIX emulation, SDL, OpenGL support for porting existing applications to web.*

## Performance & Optimization

[WebAssembly Performance](https://webassembly.org/docs/use-cases/)
*Use cases and performance characteristics of WebAssembly. Explains when Wasm provides benefits over JavaScript and optimization strategies.*

[SIMD in WebAssembly](https://github.com/WebAssembly/simd)
*Specification for SIMD (Single Instruction Multiple Data) in WebAssembly. Enables vectorized operations for compute-intensive tasks like graphics and ML.*

[WebAssembly Threads](https://github.com/WebAssembly/threads)
*Specification for multi-threading support in WebAssembly. Defines shared memory, atomic operations, and thread coordination primitives.*

## Books & Tutorials

[Rust and WebAssembly Book](https://rustwasm.github.io/docs/book/)
*Guide to building WebAssembly applications with Rust. Covers tooling, optimization, JavaScript interop, and deploying Rust code to browsers.*

[WebAssembly: The Definitive Guide](https://www.oreilly.com/library/view/webassembly-the-definitive/9781492089834/)
*Comprehensive book on WebAssembly covering architecture, tooling, and practical applications. Explains compilation, runtimes, and real-world use cases.*

# Systems Programming

## Linux Kernel & Operating Systems

[The Linux Kernel documentation](https://www.kernel.org/doc/html/latest/)
*Official Linux kernel documentation covering subsystems, APIs, and development process. Essential reference for kernel programming and understanding Linux internals.*

[Linux Kernel Development (3rd Edition) - LWN.net](https://lwn.net/Kernel/LDD3/)
*Classic book on Linux kernel architecture and development. Covers process management, memory, filesystems, and kernel programming best practices.*

[Linux Device Drivers (LDD3)](https://lwn.net/Kernel/LDD3/)
*Definitive guide to writing Linux device drivers. Covers character devices, interrupts, DMA, and kernel module development with practical examples.*

[Linux Insides](https://0xax.gitbooks.io/linux-insides/content/)
*Deep dive into Linux kernel internals from boot to userspace. Covers initialization, system calls, interrupts, and low-level mechanisms.*

[Writing a Simple Operating System from Scratch](papers/os-from-scratch.pdf)
*Tutorial building minimal x86 operating system from scratch. Teaches bootloader, protected mode, interrupts, and basic OS concepts hands-on.*

## High-Performance Networking

[DPDK (Data Plane Development Kit)](https://www.dpdk.org/)
*Framework for fast packet processing in userspace. Bypasses kernel for maximum throughput in networking applications, firewalls, and load balancers.*

[DPDK Programmer's Guide](https://doc.dpdk.org/guides/prog_guide/)
*Comprehensive DPDK programming documentation. Covers memory pools, ring buffers, poll-mode drivers, and building high-performance network applications.*

[XDP (eXpress Data Path) Tutorial](https://github.com/xdp-project/xdp-tutorial)
*Hands-on tutorial for eBPF-based packet processing in kernel. Enables programmable, high-performance networking without kernel modification.*

[io_uring - Lord of the io_uring Guide](https://unixism.net/loti/)
*Comprehensive guide to io_uring, Linux's modern async I/O interface. Explains ring buffers, submission queues, and building high-performance I/O applications.*

[io_uring by Example](https://github.com/shuveb/loti-examples)
*Practical examples demonstrating io_uring usage. Covers file I/O, networking, and advanced features with complete working code.*

## eBPF & Tracing

[BPF and XDP Reference Guide](https://docs.cilium.io/en/stable/bpf/)
*Comprehensive eBPF reference from Cilium project. Covers BPF programs, maps, helpers, and networking use cases for observability and security.*

[Learning eBPF (Book Resources)](https://github.com/lizrice/learning-ebpf)
*Resources for learning eBPF programming. Examples and tools for tracing, networking, and security using modern Linux kernel capabilities.*

[eBPF Documentation](https://ebpf.io/what-is-ebpf/)
*Official eBPF documentation and tutorials. Explains architecture, use cases, and getting started with programmable kernel instrumentation.*

[BCC (BPF Compiler Collection)](https://github.com/iovisor/bcc)
*Toolkit for creating efficient eBPF-based tools. Provides Python and Lua frontends for writing tracing and monitoring tools quickly.*

[bpftrace Reference Guide](https://github.com/iovisor/bpftrace)
*High-level tracing language for Linux eBPF. Enables one-liner scripts and complex tracing with DTrace-like syntax.*

## Memory Management

[What Every Programmer Should Know About Memory (Ulrich Drepper)](https://people.freebsd.org/~lstewart/articles/cpumemory.pdf)
*Same foundational paper on memory architecture. Essential reading duplicated here for systems programming context.*

[Memory Management Reference](https://www.memorymanagement.org/)
*Comprehensive encyclopedia of memory management techniques. Covers garbage collection, allocation algorithms, and memory system design.*

[TCMalloc Documentation](https://google.github.io/tcmalloc/)
*Google's high-performance thread-caching malloc. Reduces lock contention and fragmentation in multi-threaded applications.*

[jemalloc Documentation](http://jemalloc.net/)
*Advanced memory allocator used by Firefox and FreeBSD. Optimized for multi-threaded performance with detailed profiling capabilities.*

## Synchronization & Lock-Free Programming

[Is Parallel Programming Hard?](https://www.kernel.org/pub/linux/kernel/people/paulmck/perfbook/perfbook.html)
*Paul McKenney's comprehensive book on parallel programming. Covers memory models, synchronization primitives, RCU, and lock-free algorithms with Linux focus.*

[The Art of Multiprocessor Programming](https://www.elsevier.com/books/the-art-of-multiprocessor-programming/herlihy/978-0-12-415950-1)
*Academic textbook on concurrent programming principles. Explains lock-free data structures, consensus, and theoretical foundations with practical implementations.*

[Concurrency Freaks](http://concurrencyfreaks.blogspot.com/)
*Blog analyzing concurrent algorithms and data structures. Deep technical analysis of lock-free programming patterns and performance characteristics.*

# Performance Engineering

## Performance Analysis & Profiling

[Systems Performance (Brendan Gregg)](https://www.brendangregg.com/systems-performance-2nd-edition-book.html)
*Comprehensive guide to performance analysis methodology. Covers USE method, observability tools, and systematic approach to finding bottlenecks in production systems.*

[BPF Performance Tools](https://www.brendangregg.com/bpf-performance-tools-book.html)
*Book on using eBPF for performance analysis and tracing. Demonstrates powerful Linux observability tools for CPU, memory, networking, and application profiling.*

[The Flame Graph](https://www.brendangregg.com/flamegraphs.html)
*Visualization technique for profiling data showing call stacks and time spent. Industry-standard method for identifying performance hotspots quickly.*

[Linux perf Examples](https://www.brendangregg.com/perf.html)
*Practical examples using Linux perf for CPU profiling. Covers sampling, tracing, hardware counters, and performance analysis workflows.*

[Intel VTune Profiler](https://www.intel.com/content/www/us/en/developer/tools/oneapi/vtune-profiler.html)
*Advanced profiler for Intel CPUs with microarchitectural analysis. Provides detailed metrics on cache misses, branch mispredictions, and vectorization efficiency.*

[AMD uProf](https://www.amd.com/en/developer/uprof.html)
*Profiler for AMD processors with hardware counter access. Analyzes CPU utilization, memory bandwidth, and microarchitectural bottlenecks on EPYC and Ryzen.*

[Tracy Profiler](https://github.com/wolfpld/tracy)
*Real-time frame profiler for games and interactive applications. Provides nanosecond precision, memory tracking, and low overhead instrumentation.*

[Heaptrack Memory Profiler](https://github.com/KDE/heaptrack)
*Memory profiler tracking allocations and leaks. Identifies allocation hotspots, temporary allocations, and memory usage patterns with detailed call graphs.*

## SIMD & Vectorization

[Intel Intrinsics Guide](https://www.intel.com/content/www/us/en/docs/intrinsics-guide/index.html)
*Searchable reference for all Intel SIMD intrinsics. Already listed in Hardware section, critical for vectorization work.*

[ARM Neon Programmer's Guide](https://developer.arm.com/architectures/instruction-sets/intrinsics/)
*SIMD programming guide for ARM processors. Essential for vectorizing code on mobile, embedded, and server ARM platforms.*

[SIMD for C++ Developers](https://const.me/articles/simd/simd.pdf)
*Practical guide to SIMD programming in C++. Explains vectorization concepts, intrinsics usage, and optimization patterns.*

[Highway - Portable SIMD Library](https://github.com/google/highway)
*Google's library for portable SIMD code. Single source compiles to SSE, AVX, NEON, and other architectures with near-native performance.*

[xsimd - C++ SIMD Wrappers](https://github.com/xtensor-stack/xsimd)
*Header-only C++ wrapper for SIMD intrinsics. Provides type-safe, modern C++ interface to vectorization across platforms.*

## Benchmarking

[Google Benchmark](https://github.com/google/benchmark)
*Microbenchmarking framework already listed in C++ section. Standard tool for measuring function-level performance.*

[Catch2 Benchmarking](https://github.com/catchorg/Catch2/blob/devel/docs/benchmarks.md)
*Benchmarking capabilities in Catch2 testing framework. Integrates performance testing with unit tests.*

[nanobench - C++ Benchmarking Library](https://github.com/martinus/nanobench)
*Lightweight benchmarking library with statistical analysis. Fast, header-only, focuses on accurate microbenchmark results.*

[Quick Bench (Online)](https://quick-bench.com/)
*Online C++ benchmarking tool already listed. Useful for quick performance comparisons without local setup.*

[Compiler Explorer (Godbolt)](https://godbolt.org/)
*Assembly output viewer already listed. Essential for verifying compiler optimizations and understanding generated code.*

## Cache Optimization

[Gallery of Processor Cache Effects](https://igoro.com/archive/gallery-of-processor-cache-effects/)
*Interactive demonstrations of cache behavior. Shows impact of cache misses, false sharing, and memory access patterns on performance.*

[Cache-Oblivious Algorithms](https://en.wikipedia.org/wiki/Cache-oblivious_algorithm)
*Algorithms that perform well across cache hierarchies without tuning. Theoretical foundation for portable performance optimization.*

[ACCU - Cache-Friendly Code](https://accu.org/journals/overload/12/63/kilpatrick_268/)
*Practical guide to writing cache-efficient code. Covers data layout, access patterns, and techniques for reducing cache misses.*

## Performance Books & Papers

[Computer Architecture: A Quantitative Approach](https://www.elsevier.com/books/computer-architecture/hennessy/978-0-12-811905-1)
*Classic textbook on computer architecture and performance. Covers pipelining, memory hierarchy, ILP, and quantitative analysis methods.*

[Every Programmer Should Know](https://github.com/mtdvio/every-programmer-should-know)
*Curated list of technical knowledge including performance, distributed systems, and algorithms. Broad collection of important computer science concepts.*

[Latency Numbers Every Programmer Should Know](https://gist.github.com/jboner/2841832)
*Reference card showing latency of common operations. Essential for developing performance intuition and understanding operation costs.*

# Security & Cryptography

## Cryptography

[The Cryptopals Crypto Challenges](https://cryptopals.com/)
*Hands-on cryptography challenges teaching concepts through breaking implementations. Learn by attacking weak crypto including AES, RSA, and padding oracles.*

[A Graduate Course in Applied Cryptography](https://toc.cryptobook.us/)
*Free comprehensive textbook by Boneh and Shoup. Covers modern cryptographic primitives, protocols, and mathematical foundations at graduate level.*

[Practical Cryptography for Developers](https://cryptobook.nakov.com/)
*Developer-focused guide to using cryptography correctly. Explains hashing, encryption, signatures, and common pitfalls with code examples.*

[OpenSSL Documentation](https://www.openssl.org/docs/)
*Documentation for OpenSSL cryptography library. Industry-standard implementation of TLS, certificates, and cryptographic primitives.*

[libsodium Documentation](https://doc.libsodium.org/)
*Easy-to-use modern crypto library with safe defaults. Provides authenticated encryption, signatures, and key exchange resistant to common mistakes.*

[BoringSSL](https://boringssl.googlesource.com/boringssl/)
*Google's fork of OpenSSL used in Chrome and Android. Focuses on simplicity, security, and eliminating legacy features.*

## Application Security

[OWASP Top 10](https://owasp.org/www-project-top-ten/)
*List of most critical web application security risks. Essential awareness for developers including injection, broken auth, and XSS.*

[OWASP Cheat Sheet Series](https://cheatsheetseries.owasp.org/)
*Collection of security best practices and defensive techniques. Covers authentication, input validation, cryptography, and common vulnerabilities.*

[CWE - Common Weakness Enumeration](https://cwe.mitre.org/)
*Comprehensive catalog of software security weaknesses. Provides taxonomy for identifying and communicating vulnerability types.*

[CERT C Coding Standard](https://wiki.sei.cmu.edu/confluence/display/c/SEI+CERT+C+Coding+Standard)
*Secure coding guidelines for C. Covers undefined behavior, buffer overflows, integer overflow, and common security pitfalls.*

[CERT C++ Coding Standard](https://wiki.sei.cmu.edu/confluence/pages/viewpage.action?pageId=88046682)
*Secure C++ programming guidelines. Addresses C++-specific issues like RAII, exceptions, templates, and modern C++ security concerns.*

## Reverse Engineering & Binary Analysis

[Radare2 Book](https://book.rada.re/)
*Documentation for radare2 reverse engineering framework. Covers disassembly, debugging, binary patching, and exploit development.*

[Ghidra Documentation](https://ghidra-sre.org/)
*Documentation for NSA's Ghidra reverse engineering tool. Powerful disassembler and decompiler with scripting for automated analysis.*

[Binary Ninja](https://binary.ninja/)
*Commercial reverse engineering platform with clean UI and powerful API. Excellent for malware analysis, vulnerability research, and binary understanding.*

[Reverse Engineering for Beginners (RE4B)](https://beginners.re/)
*Free book teaching reverse engineering through examples. Covers x86, ARM, and MIPS with practical debugging and analysis techniques.*

[Practical Binary Analysis](https://practicalbinaryanalysis.com/)
*Book on binary analysis covering formats, disassembly, and dynamic analysis. Teaches building analysis tools with practical examples.*

## Vulnerability Research

[The Art of Software Security Assessment](https://www.amazon.com/Art-Software-Security-Assessment-Vulnerabilities/dp/0321444426)
*Comprehensive guide to finding security vulnerabilities. Covers code auditing methodology, common flaws, and exploitation techniques.*

[Fuzzing Book](https://www.fuzzingbook.org/)
*Interactive book teaching fuzzing and software testing. Covers mutation, generation-based, grammar-based fuzzing with Python examples.*

[AFL++ (American Fuzzy Lop)](https://github.com/AFLplusplus/AFLplusplus)
*Advanced fuzzer for finding bugs through instrumented execution. Industry-standard coverage-guided fuzzing tool for vulnerability discovery.*

[libFuzzer Documentation](https://llvm.org/docs/LibFuzzer.html)
*In-process coverage-guided fuzzer from LLVM. Integrates with SanitizerCoverage for effective testing of libraries and APIs.*

# Distributed Systems

## Foundational Papers

[Time, Clocks, and the Ordering of Events (Lamport 1978)](papers/lamport-time-clocks.pdf)
*Seminal paper establishing logical clocks and causality in distributed systems. Foundation for understanding ordering, happens-before relationships, and distributed algorithms.*

[The Byzantine Generals Problem](papers/byzantine-generals.pdf)
*Classic paper on achieving consensus with faulty/malicious nodes. Fundamental to understanding fault tolerance, blockchain, and distributed consensus protocols.*

[Paxos Made Simple](papers/paxos-simple.pdf)
*Lamport's simplified explanation of Paxos consensus algorithm. Essential but challenging read for understanding distributed consensus.*

[In Search of an Understandable Consensus Algorithm (Raft)](papers/raft.pdf)
*More understandable alternative to Paxos. Widely adopted consensus algorithm used in etcd, Consul, and many distributed systems.*

[Dynamo: Amazon's Highly Available Key-value Store](papers/dynamo-amazon.pdf)
*Describes Amazon's eventually consistent, highly available database. Influenced Cassandra, Riak, and modern NoSQL database design.*

[MapReduce: Simplified Data Processing on Large Clusters](papers/mapreduce-google.pdf)
*Google's framework for distributed data processing. Spawned Hadoop ecosystem and influenced modern big data processing systems.*

[The Google File System](papers/gfs-google.pdf)
*Architecture of Google's distributed file system. Influenced HDFS and modern distributed storage design patterns.*

[Bigtable: A Distributed Storage System for Structured Data](papers/bigtable-google.pdf)
*Google's wide-column distributed database. Influenced HBase, Cassandra, and cloud-native database architectures.*

## Consensus & Coordination

[Raft Consensus Algorithm](https://raft.github.io/)
*Interactive visualization and documentation for Raft. Easier-to-understand consensus algorithm compared to Paxos.*

[etcd Documentation](https://etcd.io/docs/)
*Distributed key-value store using Raft for Kubernetes and service discovery. Industry-standard for configuration and coordination.*

[Apache ZooKeeper](https://zookeeper.apache.org/doc/current/)
*Centralized coordination service for distributed applications. Provides naming, configuration, synchronization, and group services.*

[Consul by HashiCorp](https://www.consul.io/docs)
*Service mesh and service discovery platform. Combines service registry, health checking, and KV store with Raft consensus.*

## Distributed Databases

[CockroachDB Architecture](https://www.cockroachlabs.com/docs/stable/architecture/overview.html)
*NewSQL database combining SQL with horizontal scalability. Uses Raft for consistency and provides distributed ACID transactions.*

[TiDB Documentation](https://docs.pingcap.com/tidb/stable)
*MySQL-compatible distributed database. Separates compute and storage layers, uses Raft for replication.*

[FoundationDB Architecture](https://apple.github.io/foundationdb/)
*Transactional key-value store with deterministic simulation testing. Provides strong consistency foundation for building distributed systems.*

## Message Queues & Event Streaming

[Apache Kafka Documentation](https://kafka.apache.org/documentation/)
*Distributed streaming platform for high-throughput messaging. Industry standard for event streaming, log aggregation, and real-time data pipelines.*

[Kafka: The Definitive Guide](https://www.confluent.io/resources/kafka-the-definitive-guide/)
*Comprehensive book on Kafka architecture and usage. Covers producers, consumers, stream processing, and operational best practices.*

[NATS Documentation](https://docs.nats.io/)
*Lightweight, high-performance messaging system. Simple pub-sub with JetStream for persistence and streaming.*

[RabbitMQ Documentation](https://www.rabbitmq.com/documentation.html)
*AMQP message broker with complex routing. Popular for task queues, microservices communication, and asynchronous processing.*

[Apache Pulsar Documentation](https://pulsar.apache.org/docs/)
*Cloud-native distributed messaging with multi-tenancy. Separates serving and storage layers, supports both queue and stream semantics.*

## Network Programming

[Beej's Guide to Network Programming](https://beej.us/guide/bgnet/)
*Practical guide to socket programming in C. Covers TCP, UDP, and network programming basics with clear examples.*

[TCP/IP Illustrated, Volume 1](https://www.informit.com/store/tcp-ip-illustrated-volume-1-the-protocols-9780321336316)
*Classic detailed explanation of TCP/IP protocol stack. Deep dive into packet formats, state machines, and protocol behavior.*

[QUIC Protocol](https://www.chromium.org/quic/)
*Modern transport protocol built on UDP providing TLS encryption and multiplexing. Used by HTTP/3, faster connection establishment than TCP.*

## Books & Resources

[Designing Data-Intensive Applications (Martin Kleppmann)](https://dataintensive.net/)
*Comprehensive guide to distributed systems and data architecture. Covers replication, partitioning, transactions, and consistency models. Essential reading.*

[Distributed Systems for Fun and Profit](http://book.mixu.net/distsys/)
*Free online book covering distributed systems fundamentals. Explains time, replication, and consistency in accessible manner.*

[The System Design Primer](https://github.com/donnemartin/system-design-primer)
*Curated collection of system design resources. Covers scalability, databases, caching, load balancing for interview preparation and learning.*

[Awesome Distributed Systems](https://github.com/theanalyst/awesome-distributed-systems)
*Curated list of distributed systems papers, books, and resources. Organized collection for deep learning about distributed computing.*

# Books

# Finance

## Risk & asset allocation: 

[Active Portfolio Management (Grinold & Kahn)](https://www.amazon.com/Active-Portfolio-Management-Quantitative-Controlling/dp/0070248826)

[Quantitative Equity Portfolio Management]( https://www.amazon.com/Quantitative-Equity-Portfolio-Management-Second-ebook/dp/B09KF52TKD)

[Quantitative Portfolio Management](https://www.amazon.com/Quantitative-Portfolio-Management-Statistical-Arbitrage )

"Equity Portfolio Management" (Fabozzi) https://www.amazon.com/Equity-Portfolio-Management-Frank-Fabozzi/dp/1883249406 

"Advanced Portfolio Management" https://www.amazon.com/Advanced-Portfolio-Management-Fundamental-Investors

"Modern Invesment Management" (Litterman/GSAM) https://www.amazon.com/Modern-Investment-Management-Equilibrium-Approach/dp/0471124109#customerReviews 

## Analysis of financial time series:

"Anaysis of Financial Time Series" (Tsay) https://www.amazon.com/Analysis-Financial-Time-Ruey-Tsay/dp/0470414359

"Applied Econometric Time Series" https://www.amazon.com/Applied-Econometric-Wiley-Probability-Statistics 

"Econometrics: A Modern Approach" https://www.amazon.com/Introductory-Econometrics-Modern-Approach-MindTap-dp-1337558869/dp/1337558869/

"Statistics & Data Analysis for Financial Engineering" https://www.amazon.com/dp/1461427495

## Financial ML/Stats:

"The Elements of Statistical Learning" https://www.amazon.com/Elements-Statistical-Learning-Prediction-Statistics/dp/0387848576

"All of Statistics" https://www.amazon.com/All-Statistics-Statistical-Inference-Springer/dp/1441923225 

"Advances in Financial ML" (Lopez de Prado) https://www.amazon.com/Advances-Financial-Machine-Learning-Marcos/dp/1119482089

"Linear Algebra Done Right" https://www.amazon.com/dp/0387982582

"Deep Reinforcement Learning" (Yuxi Li) https://arxiv.org/pdf/1810.06339

## Options, derivatives, credit, FX, & commodities: 

"Options, Futures, and Other Derivatives" (Hull) https://www.amazon.com/Options-Futures-Other-Derivatives-Global-dp-1292410655

"Stochastic Volatility Modeling" https://www.amazon.com/Stochastic-Volatility-Modeling-Financial-Mathematics/dp/1482244063

"Value at Risk" https://www.amazon.com/gp/product/0071464956

"Mathematical Methods for FX" https://www.amazon.com/gp/product/9810248237

"FX Options & Structued Products" https://www.amazon.com/Options-Structured-Products-Wiley-Finance/dp/1118471067 

"Commodities & Commodity Derivatives" https://www.amazon.com/Commodities-Commodity-Derivatives-Modelling-Agriculturals/dp/0470012188 

"Managing Credit Risk" (Altman) https://www.amazon.com/Managing-Credit-Risk-Challenge-Financial/dp/0470118725 

"Credit Risk Modeling" https://www.amazon.com/gp/product/1584889926

"Bond Markets, Analysis, & Strategies" (Fabozzi) https://www.amazon.com/Bond-Markets-Analysis-Strategies-tenth-dp-026204627X/dp/026204627X/ 

"Valuation" (Damodoran - makes both lists) https://www.amazon.com/Investment-Valuation-Techniques-Determining-University/dp/1118130731
