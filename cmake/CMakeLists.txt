cmake_minimum_required(VERSION 3.5.0)

set(PROJECT_NAME lba2classic)

project(${PROJECT_NAME})

SET(SOURCE_DIR "${CMAKE_SOURCE_DIR}/../SOURCES")
SET(L386_SOURCE_DIR "${CMAKE_SOURCE_DIR}/../LIB386")

# Handle the libs
SET(L386_3D_SOURCE_DIR "${L386_SOURCE_DIR}/3D")
SET(L386_AIL_SOURCE_DIR "${L386_SOURCE_DIR}/ail")
SET(L386_ANIM_SOURCE_DIR "${L386_SOURCE_DIR}/ANIM")
SET(L386_FILEIO_SOURCE_DIR "${L386_SOURCE_DIR}/FILEIO")
SET(L386_LIB_3D_SOURCE_DIR "${L386_SOURCE_DIR}/LIB_3D")
SET(L386_LIB_CD_SOURCE_DIR "${L386_SOURCE_DIR}/LIB_CD")
SET(L386_LIB_MENU_SOURCE_DIR "${L386_SOURCE_DIR}/LIB_MENU")
SET(L386_LIB_MIDI_SOURCE_DIR "${L386_SOURCE_DIR}/LIB_MIDI")
SET(L386_LIB_MIX_SOURCE_DIR "${L386_SOURCE_DIR}/LIB_MIX")
SET(L386_LIB_SAMP_SOURCE_DIR "${L386_SOURCE_DIR}/LIB_SAMP")
SET(L386_LIB_SYS_SOURCE_DIR "${L386_SOURCE_DIR}/LIB_SYS")
SET(L386_MENU_SOURCE_DIR "${L386_SOURCE_DIR}/MENU")
SET(L386_OBJECT_SOURCE_DIR "${L386_SOURCE_DIR}/OBJECT")
SET(L386_POL_WORK_SOURCE_DIR "${L386_SOURCE_DIR}/pol_work")
SET(L386_SMACKER_SOURCE_DIR "${L386_SOURCE_DIR}/smacker")
SET(L386_SVGA_SOURCE_DIR "${L386_SOURCE_DIR}/SVGA")
SET(L386_SYSTEM_SOURCE_DIR "${L386_SOURCE_DIR}/SYSTEM")

set(WIN32_SOURCE_GRP "Source Files")
set(WIN32_HEADER_GRP "Header Files")

file(GLOB lib386_3d_src
    "${L386_3D_SOURCE_DIR}/*.asm"
    "${L386_3D_SOURCE_DIR}/*.c"
    "${L386_3D_SOURCE_DIR}/*.cpp"
)

file(GLOB lib386_ail_src
    "${L386_AIL_SOURCE_DIR}/*.asm"
    "${L386_AIL_SOURCE_DIR}/*.c"
    "${L386_AIL_SOURCE_DIR}/*.cpp"
)

file(GLOB lib386_anim_src
    "${L386_ANIM_SOURCE_DIR}/*.asm"
    "${L386_ANIM_SOURCE_DIR}/*.c"
    "${L386_ANIM_SOURCE_DIR}/*.cpp"
)

file(GLOB lib386_fileio_src
    "${L386_FILEIO_SOURCE_DIR}/*.asm"
    "${L386_FILEIO_SOURCE_DIR}/*.c"
    "${L386_FILEIO_SOURCE_DIR}/*.cpp"
)

file(GLOB lib386_lib_3d_src
    "${L386_LIB_3D_SOURCE_DIR}/*.asm"
    "${L386_LIB_3D_SOURCE_DIR}/*.c"
    "${L386_LIB_3D_SOURCE_DIR}/*.cpp"
)

file(GLOB lib386_lib_cd_src
    "${L386_LIB_CD_SOURCE_DIR}/*.asm"
    "${L386_LIB_CD_SOURCE_DIR}/*.c"
    "${L386_LIB_CD_SOURCE_DIR}/*.cpp"
)

file(GLOB lib386_lib_menu_src
    "${L386_LIB_MENU_SOURCE_DIR}/*.asm"
    "${L386_LIB_MENU_SOURCE_DIR}/*.c"
    "${L386_LIB_MENU_SOURCE_DIR}/*.cpp"
)

file(GLOB lib386_lib_midi_src
    "${L386_LIB_MIDI_SOURCE_DIR}/*.asm"
    "${L386_LIB_MIDI_SOURCE_DIR}/*.c"
    "${L386_LIB_MIDI_SOURCE_DIR}/*.cpp"
)

file(GLOB lib386_lib_mix_src
    "${L386_LIB_MIX_SOURCE_DIR}/*.asm"
    "${L386_LIB_MIX_SOURCE_DIR}/*.c"
    "${L386_LIB_MIX_SOURCE_DIR}/*.cpp"
)

file(GLOB lib386_lib_samp_src
    "${L386_LIB_SAMP_SOURCE_DIR}/*.asm"
    "${L386_LIB_SAMP_SOURCE_DIR}/*.c"
    "${L386_LIB_SAMP_SOURCE_DIR}/*.cpp"
)

file(GLOB lib386_lib_sys_src
    "${L386_LIB_SYS_SOURCE_DIR}/*.asm"
    "${L386_LIB_SYS_SOURCE_DIR}/*.c"
    "${L386_LIB_SYS_SOURCE_DIR}/*.cpp"
)

file(GLOB lib386_menu_src
    "${L386_MENU_SOURCE_DIR}/*.asm"
    "${L386_MENU_SOURCE_DIR}/*.c"
    "${L386_MENU_SOURCE_DIR}/*.cpp"
)

file(GLOB lib386_object_src
    "${L386_OBJECT_SOURCE_DIR}/*.asm"
    "${L386_OBJECT_SOURCE_DIR}/*.c"
    "${L386_OBJECT_SOURCE_DIR}/*.cpp"
)

file(GLOB lib386_pol_work_src
    "${L386_POL_WORK_SOURCE_DIR}/*.asm"
    "${L386_POL_WORK_SOURCE_DIR}/*.c"
    "${L386_POL_WORK_SOURCE_DIR}/*.cpp"
)


file(GLOB lib386_smacker_src
    "${L386_SMACKER_SOURCE_DIR}/*.asm"
    "${L386_SMACKER_SOURCE_DIR}/*.c"
    "${L386_SMACKER_SOURCE_DIR}/*.cpp"
)

file(GLOB lib386_svga_src
    "${L386_SVGA_SOURCE_DIR}/*.asm"
    "${L386_SVGA_SOURCE_DIR}/*.c"
    "${L386_SVGA_SOURCE_DIR}/*.cpp"
)

file(GLOB lib386_system_src
    "${L386_SYSTEM_SOURCE_DIR}/*.asm"
    "${L386_SYSTEM_SOURCE_DIR}/*.c"
    "${L386_SYSTEM_SOURCE_DIR}/*.cpp"
)

file(GLOB lib386_h
    "${L386_SOURCE_DIR}/H/*.hpp"
    "${L386_SOURCE_DIR}/H/*.h"
)

file(GLOB lba2_src
    "${SOURCE_DIR}/*.cpp"
    "${SOURCE_DIR}/*.c"
)

file(GLOB lba2_h
    "${SOURCE_DIR}/*.hpp"
    "${SOURCE_DIR}/*.h"
)

include_directories(
    "${SOURCE_DIR}"
    "${L386_SOURCE_DIR}/H"
    # "${L386_SOURCE_DIR}/H/3D"
    # "${L386_SOURCE_DIR}/H/AIL"
    # "${L386_SOURCE_DIR}/H/ANIM"
    # "${L386_SOURCE_DIR}/H/FILEIO"
    # "${L386_SOURCE_DIR}/H/MENU"
    # "${L386_SOURCE_DIR}/H/OBJECT"
    # "${L386_SOURCE_DIR}/H/POLYGON"
    # "${L386_SOURCE_DIR}/H/smacker"
    # "${L386_SOURCE_DIR}/H/SVGA"
    # "${L386_SOURCE_DIR}/H/SYSTEM"
)

add_library("3D" STATIC
    ${lib386_3d_src}
)
add_library("AIL" STATIC
    ${lib386_ail_src})
add_library("ANIM" STATIC
    ${lib386_anim_src})
add_library("FILEIO" STATIC
    ${lib386_fileio_src})
add_library("LIB_3D" STATIC
    ${lib386_lib_3d_src})
add_library("LIB_CD" STATIC
    ${lib386_lib_cd_src})
add_library("LIB_MENU" STATIC
    ${lib386_lib_menu_src})
add_library("LIB_MIDI" STATIC
    ${lib386_lib_midi_src})
add_library("LIB_MIX" STATIC
    ${lib386_lib_mix_src})
add_library("LIB_SAMP" STATIC
    ${lib386_lib_samp_src})
add_library("LIB_SYS" STATIC
    ${lib386_lib_sys_src})
add_library("MENU" STATIC
    ${lib386_menu_src})
add_library("OBJECT" STATIC
    ${lib386_object_src})
add_library("POL_WORK" STATIC
    ${lib386_pol_work_src})
add_library("SMACKER" STATIC
    ${lib386_smacker_src})
add_library("SVGA" STATIC
    ${lib386_svga_src})
add_library("SYSTEM" STATIC
    ${lib386_system_src})

set_target_properties("ANIM" PROPERTIES LINKER_LANGUAGE C)
set_target_properties("LIB_CD" PROPERTIES LINKER_LANGUAGE C)
set_target_properties("LIB_3D" PROPERTIES LINKER_LANGUAGE C)
set_target_properties("OBJECT" PROPERTIES LINKER_LANGUAGE C)
set_target_properties("POL_WORK" PROPERTIES LINKER_LANGUAGE C)

source_group("${WIN32_SOURCE_GRP}" FILES ${lba2_src})
source_group("${WIN32_HEADER_GRP}" FILES ${lba2_h})

add_executable(${PROJECT_NAME}
    ${lba2_src}
    ${lba2_h}
)

target_link_libraries(${PROJECT_NAME}
    "3D"
    "AIL"
    "ANIM"
    "FILEIO"
    "LIB_3D"
    "LIB_CD"
    "LIB_MENU"
    "LIB_MIDI"
    "LIB_MIDI"
    "LIB_MIX"
    "LIB_SAMP"
    "LIB_SYS"
    "MENU"
    "OBJECT"
    "POL_WORK"
    "SMACKER"
    "SVGA"
    "SYSTEM"
)