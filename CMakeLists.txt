cmake_minimum_required(VERSION 3.31)
project(proyecto_poo)

include(FetchContent)

FetchContent_Declare(
        json
        GIT_REPOSITORY https://github.com/nlohmann/json.git
        GIT_TAG v3.11.3
)

FetchContent_MakeAvailable(json)
set(CMAKE_CXX_STANDARD 20)
add_executable(proyecto_poo main.cpp clases/Serie/Serie.cpp clases/Episodio/Episodio.cpp clases/Video/Video.cpp clases/Pelicula/Pelicula.cpp clases/StreamingServ/StreamimgServ.cpp)
target_link_libraries(proyecto_poo PRIVATE nlohmann_json::nlohmann_json)
