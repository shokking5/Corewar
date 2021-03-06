# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    CMakeLists.txt                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acyrenna <acyrenna@school21.ru>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/07 23:51:44 by acyrenna          #+#    #+#              #
#    Updated: 2021/02/11 01:54:11 by talyx            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cmake_minimum_required(VERSION 3.15.3)

project(corewar)

set(BUILD_FLAGS " -g -Wall -Werror -Wextra")
set(DST_NAME ${PROJECT_NAME})
set(SRC_DIR ${PROJECT_SOURCE_DIR}/sources/)
set(INC_DIR ${PROJECT_SOURCE_DIR}/includes/)
set(LIBFT_DIR ${PROJECT_SOURCE_DIR}/libft/)

FILE(GLOB_RECURSE PROJ_SOURCES ${SRC_DIR}*.c)

add_subdirectory(${LIBFT_DIR})

set(INC_DIRS ./)
INCLUDE_DIRS(INC_DIRS)

add_executable(${DST_NAME} ${PROJ_SOURCES})
target_include_directories(${DST_NAME} PUBLIC ${LIBFT_DIR}includes/)
target_include_directories(${DST_NAME} PUBLIC ${INC_DIRS})
target_link_libraries(${DST_NAME} libft)
set_target_properties(${DST_NAME} PROPERTIES
		RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}
		OUTPUT_NAME ${DST_NAME}
		COMPILE_FLAGS ${BUILD_FLAGS})

add_dependencies(${DST_NAME} libft)
