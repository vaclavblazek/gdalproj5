#include <cstdlib>
#include <memory>
#include <iostream>

#include <cpl_error.h>
#include <ogr_spatialref.h>

const char *SourceSrs = "+proj=longlat +a=3396190 +b=3376200 +no_defs";
const char *TargetSrs
    = "+proj=geocent +a=3396190 +b=3376200 +lon_0=0 +units=m +no_defs";

int main()
{
    ::OGRSpatialReference sSrs;
    sSrs.importFromProj4(SourceSrs);

    ::OGRSpatialReference tSrs;
    tSrs.importFromProj4(TargetSrs);

    std::unique_ptr< ::OGRCoordinateTransformation>
        ct(::OGRCreateCoordinateTransformation(&sSrs, &tSrs));

    double x(0), y(0), z(0);
    if (!(ct->Transform(1, &x, &y, &z))) {
        std::cerr << "Cannot convert point between coordinate systems: <"
                  << ::CPLGetLastErrorMsg() << ">.";
        return EXIT_FAILURE;
    }

    std::cout << std::fixed << x << ", " << y << ", " << z << std::endl;

    return EXIT_SUCCESS;
}
