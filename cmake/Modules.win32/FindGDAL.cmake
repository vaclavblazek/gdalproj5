# we look for gdal in Program Files/gdal and the default WIN install path
find_path(GDAL_INCLUDE_DIR gdal.h
  PATHS "$ENV{PROGRAMFILES}/gdal"
        "C:/warmerda/bld"
  PATH_SUFFIXES include)

find_library(GDAL_LIBRARY NAMES gdal gdal_i
  PATHS "$ENV{PROGRAMFILES}/gdal"
        "C:/warmerda/bld"
  PATH_SUFFIXES lib)

if(GDAL_LIBRARY)
  set(GDAL_LIBRARIES "${GDAL_LIBRARY}")
endif()

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(GDAL DEFAULT_MSG
  GDAL_LIBRARIES GDAL_INCLUDE_DIR)
mark_as_advanced(GDAL_LIBRARIES GDAL_INCLUDE_DIR)
