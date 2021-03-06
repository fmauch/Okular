include_directories(
   ${CMAKE_CURRENT_SOURCE_DIR}/../..
)


########### next target ###############

set( okularGenerator_comicbook_PART_SRCS
     document.cpp
     generator_comicbook.cpp
     directory.cpp
     unrar.cpp qnatsort.cpp
     unrarflavours.cpp
   )


add_library(okularGenerator_comicbook MODULE ${okularGenerator_comicbook_PART_SRCS})

target_link_libraries(okularGenerator_comicbook  okularcore KF5::KIOCore)
if (UNIX)
   find_package(KF5 REQUIRED Pty)
   target_link_libraries(okularGenerator_comicbook KF5::Pty KF5::I18n KF5::Archive KF5::KDELibs4Support)
endif (UNIX)

install(TARGETS okularGenerator_comicbook DESTINATION ${KDE_INSTALL_PLUGINDIR})


########### install files ###############

install( FILES libokularGenerator_comicbook.desktop okularComicbook.desktop DESTINATION  ${KDE_INSTALL_KSERVICES5DIR} )
install( PROGRAMS okularApplication_comicbook.desktop org.kde.mobile.okular_comicbook.desktop  DESTINATION  ${KDE_INSTALL_APPDIR} )

