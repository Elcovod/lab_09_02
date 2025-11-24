#include <iostream>

void checkCompilerOptions() {
    std::cout << "Checking compiler options..." << std::endl;


#if defined(_DEBUG) || defined(DEBUG)
    std::cout << "Mode: DEBUG (Active)" << std::endl;
#else
    std::cout << "Mode: RELEASE (Active)" << std::endl;
#endif

    // Перевірка версії стандарту C++
#if defined(__cplusplus)
    std::cout << "C++ Standard: " << __cplusplus << std::endl;
#else
    std::cout << "C++ Standard: Unknown" << std::endl;
#endif

#if defined(_WIN32) || defined(_WIN64)
    std::cout << "OS: Windows" << std::endl;
#elif defined(__linux__)
    std::cout << "OS: Linux" << std::endl;
#elif defined(__APPLE__)
    std::cout << "OS: MacOS" << std::endl;
#else
    std::cout << "OS: Unknown" << std::endl;
#endif
}

int main() {
    checkCompilerOptions();
    return 0;
}
