include_directories(
   ${CMAKE_CURRENT_SOURCE_DIR}/../..
   ${CMAKE_BINARY_DIR}/okular
)

#add_definitions(-DDEBUG_DVIRENDERER -DDEBUG_RENDER -DDEBUG_PRESCAN -DDEBUG_PSGS -DDEBUG_FONTPOOL)

if (FREETYPE_FOUND)
   add_definitions(-DHAVE_FREETYPE)
   include_directories(${FREETYPE_INCLUDE_DIRS})
else (FREETYPE_FOUND)
   remove_definitions(-DHAVE_FREETYPE)
endif (FREETYPE_FOUND)

########### next target ###############

set(okularGenerator_dvi_SRCS
   generator_dvi.cpp
   bigEndianByteReader.cpp
   dviRenderer.cpp
   dviRenderer_draw.cpp
   dviRenderer_prescan.cpp
   dviRenderer_dr.cpp
   special.cpp
   dviFile.cpp
   dviPageInfo.cpp
   psgs.cpp
#   psheader.cpp        # already included in psgs.cpp
   glyph.cpp
   TeXFont.cpp
   TeXFontDefinition.cpp
   vf.cpp
   TeXFont_PFB.cpp
   TeXFont_PK.cpp
   TeXFont_TFM.cpp
   util.cpp
   pageSize.cpp
   simplePageSize.cpp
   length.cpp
   fontEncoding.cpp
   fontEncodingPool.cpp
   fontMap.cpp
   fontpool.cpp
   dvisourcesplitter.cpp
   dviexport.cpp
)


add_library(okularGenerator_dvi MODULE ${okularGenerator_dvi_SRCS})

target_link_libraries(okularGenerator_dvi okularcore KF5::I18n KF5::KDELibs4Support)
if (FREETYPE_FOUND)
   target_link_libraries(okularGenerator_dvi ${FREETYPE_LIBRARIES})
endif (FREETYPE_FOUND)

install(TARGETS okularGenerator_dvi DESTINATION ${KDE_INSTALL_PLUGINDIR})


########### install files ###############

install( FILES libokularGenerator_dvi.desktop okularDvi.desktop  DESTINATION  ${KDE_INSTALL_KSERVICES5DIR} )
install( PROGRAMS okularApplication_dvi.desktop org.kde.mobile.okular_dvi.desktop  DESTINATION  ${KDE_INSTALL_APPDIR} )

