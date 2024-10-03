#
# Copyright (c) Contributors to the Open 3D Engine Project.
# For complete copyright and license terms please see the LICENSE at the root of this distribution.
#
# SPDX-License-Identifier: Apache-2.0 OR MIT
#
#

if(PAL_TRAIT_BUILD_TESTS_SUPPORTED)
    o3de_pal_dir(pal_aztest_dir ${CMAKE_CURRENT_LIST_DIR}/AzTest/Platform/${PAL_PLATFORM_NAME} ${O3DE_ENGINE_RESTRICTED_PATH} ${LY_ROOT_FOLDER})

    include(FetchContent)
    FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG b514bdc898e2951020cbdca1304b75f5950d1f59 # v1.15.2
    )
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE) # Prevent overriding the parent project's compiler/linker settings
    set(BUILD_GMOCK ON CACHE BOOL "" FORCE) # This setting builds gtest and gmock
    set(INSTALL_GTEST OFF CACHE BOOL "" FORCE) # Install target is not needed
    FetchContent_MakeAvailable(googletest)

    ly_add_target(
        NAME AzTest STATIC
        NAMESPACE AZ
        FILES_CMAKE
            AzTest/aztest_files.cmake
            ${pal_aztest_dir}/platform_${PAL_PLATFORM_NAME_LOWERCASE}_files.cmake
        COMPILE_DEFINITIONS
            PUBLIC
                GTEST_REMOVE_LEGACY_TEST_CASEAPI_=1
        INCLUDE_DIRECTORIES
            PUBLIC
                .
                ${pal_aztest_dir}
        BUILD_DEPENDENCIES
            PUBLIC
                GTest::gtest
                GTest::gmock
                3rdParty::GoogleBenchmark
                AZ::AzCore
        PLATFORM_INCLUDE_FILES
            ${pal_aztest_dir}/platform_${PAL_PLATFORM_NAME_LOWERCASE}.cmake
    )
endif()
