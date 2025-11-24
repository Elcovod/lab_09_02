#include "pch.h"
#include "CppUnitTest.h"

#include <sstream>
#include <iostream>
#include "F:\Project\lab_09_02_02\lab_09_02_02\lab.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

void checkCompilerOptions();

namespace UnitTestCompilerOptions
{
    TEST_CLASS(UnitTestCompilerOptions)
    {
    public:

        TEST_METHOD(Test_Output)
        {
            // Перехоплення std::cout
            std::stringstream buffer;
            std::streambuf* old_buf = std::cout.rdbuf(buffer.rdbuf());

            // Виклик цільової функції
            checkCompilerOptions();

            // Повернення std::cout
            std::cout.rdbuf(old_buf);

            std::string output = buffer.str();

            // --- Базове повідомлення ---
            Assert::IsTrue(
                output.find("Checking compiler options...") != std::string::npos,
                L"Повідомлення старту не знайдене."
            );

            // --- Режим компіляції ---
#if defined(_DEBUG) || defined(DEBUG)
            Assert::IsTrue(
                output.find("Mode: DEBUG") != std::string::npos,
                L"DEBUG режим мав бути активним."
            );
#else
            Assert::IsTrue(
                output.find("Mode: RELEASE") != std::string::npos,
                L"RELEASE режим мав бути активним."
            );
#endif

            // --- Версія C++ ---
#if defined(__cplusplus)
            std::string cppVal = std::to_string(__cplusplus);
            Assert::IsTrue(
                output.find(cppVal) != std::string::npos,
                L"Не знайдено виводу стандарту C++ (__cplusplus)."
            );
#endif

            // --- ОС ---
#if defined(_WIN32) || defined(_WIN64)
            Assert::IsTrue(
                output.find("OS: Windows") != std::string::npos,
                L"Мала бути Windows."
            );
#elif defined(__linux__)
            Assert::IsTrue(
                output.find("OS: Linux") != std::string::npos,
                L"Мала бути Linux."
            );
#elif defined(__APPLE__)
            Assert::IsTrue(
                output.find("OS: MacOS") != std::string::npos,
                L"Мала бути MacOS."
            );
#else
            Assert::IsTrue(
                output.find("OS: Unknown") != std::string::npos,
                L"Мала бути інша (unknown) ОС."
            );
#endif
        }
    };
}
