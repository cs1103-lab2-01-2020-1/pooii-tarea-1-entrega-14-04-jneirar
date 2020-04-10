cmake_minimum_required(VERSION 3.10)

project(unidad1)

file(GLOB SOURCES "src/*", "src/clases/*")

add_executable(unidad1 ${SOURCES})