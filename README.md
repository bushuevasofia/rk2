# RK2 

## Задание

Цель:  
Реализовать шаблон проектирования `State` для обработки сообщений, разделить классы на модульные компоненты, протестировать их, собрать проект локально и удаленно, создать `.deb` пакет и прикрепить его как GitHub Release.

### Пункты задания:
1. Добиться, чтобы данный код собирался локально.
Код был разделен на несколько файлов (`src/*.cpp`, `include/message_handler.hpp`)
- Настроен `CMakeLists.txt` для сборки проекта через CMake
- Локальная сборка выполняется командами:
  ```bash
  mkdir _build && cd _build
  cmake ..
  cmake --build .
2. Вынести все классы, используемые в шаблоне проектирования, в отдельные файлы, чтобы они могли быть протестированы.
# MessageHandler message_handler.hpp
# State state.hpp
# DefaultState default_state.cpp, объявление default_state.hpp
# SessionState session_state.cpp, объявление session_state.hpp
# реализация MessageHandler message_handler.cpp
# тесты для GoogleTest test_message_handler.cpp
3. Создать `CMakeLists.txt`, который создаёт статическую библиотеку и исполняемый файл.
Создан CMakeLists.txt, который:
- Создаёт статическую библиотеку message_handler
- Создаёт исполняемый файл main
- Включает GoogleTest через FetchContent или git submodule
- Поддерживает сборку тестов при опции -DBUILD_TESTS=ON
4. Написать хотя бы один тест для каждого конкретного класса.
 Написаны модульные тесты для всех состояний в файле tests/test_message_handler.cpp.
Примеры тестов:
DefaultState_StartSession_ReturnsSessionState — проверяет, что команда start_session создаёт новую сессию.
SessionState_Print_MessageIsPrinted — проверяет, что команда print выводит корректный текст.
5. Добавить этот тест в сборочный файл `CMakeLists.txt`.
В CMakeLists.txt добавлены:
option(BUILD_TESTS "Build tests" ON)

if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(third-party/gtest)

    file(GLOB TEST_SOURCES tests/*.cpp)
    add_executable(run_tests ${TEST_SOURCES})
    target_link_libraries(run_tests PRIVATE message_handler gtest gtest_main)
    add_test(NAME run_tests COMMAND run_tests)
endif()
6. Написать скрипт GitHub Action, чтобы весь код и тесты собирались удалённо на GitHub (Ubuntu).
Добавлен файл .github/workflows/ci.yml с конфигурацией GitHub Actions:
name: CI/CD Pipeline

on:
  push:
    branches:
      - main

jobs:
  build:
    runs-on: ubuntu-latest
    steps:
      - uses: actions/checkout@v4

      - name: Install dependencies
        run: |
          sudo apt-get update
          sudo apt-get install -y cmake g++ googletest libgtest-dev dpkg-dev devscripts debhelper build-essential

      - name: Configure CMake
        run: |
          mkdir _build && cd _build
          cmake .. -DBUILD_TESTS=ON

      - name: Build project
        run: |
          cd _build
          cmake --build .
          ctest --output-on-failure

      - name: Create deb package
        run: |
          cd _build
          cpack -G DEB

      - name: Upload deb as GitHub Release
        uses: ncipollo/release-action@v1
        with:
          artifacts: "_build/*.deb"
          token: ${{ secrets.GITHUB_TOKEN }}
          allowUpdates: true


7. Упаковать результат в `.deb` пакет.
cd _build
cpack -G DEB
8. Прикрепить собранный пакет как GitHub Release.

---

