//----------------------------------------------------------------------------------
//! Tools for MLPDF specification generation.
/*!
// \file    MLPDF_PDFDocumentTools.h
// \author  Axel Newe (axel.newe@fau.de)
// \date    2015-10-15
*/
//----------------------------------------------------------------------------------


#ifndef _PDF_PDFDocumentTools_H
#define _PDF_PDFDocumentTools_H 

// Local includes
#include "MLPDFSystem.h"

// ML includes
#include <mlModuleIncludes.h>


ML_START_NAMESPACE

namespace mlPDF {

class MLPDF_EXPORT PDFDocumentTools
{

public:

  static void CalculateCameraPropertiesFromInventorCamera(
    Vector3 inventorCameraPosition, Vector4 inventorCameraOrientation, float inventorCameraFocalDistance, float inventorCameraHeight, // inputs
    Vector3& camCenterOfOrbit, Vector3& camCenterToCamera, float& camRadiusOfOrbit, float& camRollAngle, float& camFOVAngle           // outputs
  );

  static void CalculateDefaultCameraProperties(
    Vector3 boundingBoxCenter, double boundingBoxRadius,                                                                     // inputs
    Vector3& camCenterOfOrbit, Vector3& camCenterToCamera, float& camRadiusOfOrbit, float& camRollAngle, float& camFOVAngle  // outputs
  );

};

} // end namespace mlPDF

ML_END_NAMESPACE

#endif // _PDF_PDFDocumentTools_H