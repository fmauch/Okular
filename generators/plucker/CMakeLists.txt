include_directories(
   ${CMAKE_BINARY_DIR}/okular
   ${CMAKE_CURRENT_SOURCE_DIR}/../..
   ${CMAKE_CURRENT_SOURCE_DIR}/../../generators/plucker/unpluck
   ${JPEG_INCLUDE_DIR}
   ${ZLIB_INCLUDE_DIR}
)

set(qunpluck_SRCS
    unpluck/config.cpp
    unpluck/image.cpp
    unpluck/qunpluck.cpp
    unpluck/unpluck.cpp
    unpluck/util.cpp
)

########### next target ###############

set(okularGenerator_plucker_SRCS
  generator_plucker.cpp
)


add_library(okularGenerator_plucker MODULE ${okularGenerator_plucker_SRCS} ${qunpluck_SRCS})

target_link_libraries(okularGenerator_plucker okularcore KF5::KIOCore KF5::I18n ${MATH_LIB} ${JPEG_LIBRARY} ${ZLIB_LIBRARY})

install(TARGETS okularGenerator_plucker DESTINATION ${KDE_INSTALL_PLUGINDIR})


########### install files ###############

install( FILES libokularGenerator_plucker.desktop okularPlucker.desktop  DESTINATION  ${KDE_INSTALL_KSERVICES5DIR} )
install( PROGRAMS okularApplication_plucker.desktop org.kde.mobile.okular_plucker.desktop  DESTINATION  ${KDE_INSTALL_APPDIR} )

