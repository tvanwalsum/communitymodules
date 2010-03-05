//----------------------------------------------------------------------------------
//! The ML module class WEMVolume.
/*!
// \file    WEMVolume.h
// \author  Coert Metz
// \date    2009-12-08
//
// Computes the volume of the WEM patches in a WEM.
*/
//----------------------------------------------------------------------------------

/* =================================================================================
   Copyright (c) 2010, Biomedical Imaging Group Rotterdam (BIGR),
   Departments of Radiology and Medical Informatics, Erasmus MC. All
   rights reserved.

   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are met:
   * Redistributions of source code must retain the above copyright
     notice, this list of conditions and the following disclaimer.
   * Redistributions in binary form must reproduce the above copyright
     notice, this list of conditions and the following disclaimer in the
     documentation and/or other materials provided with the distribution.
   * Neither the name of BIGR nor the names of its contributors
     may be used to endorse or promote products derived from this software
     without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
  ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
  WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  DISCLAIMED. IN NO EVENT SHALL BIGR BE LIABLE FOR ANY DIRECT, INDIRECT,
  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
  OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
  LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE
  OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
  ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
  =================================================================================*/

#ifndef __WEMVolume_H
#define __WEMVolume_H


// Local includes
#include "MLWEMCommunityModulesSystem.h"

// ML includes
#include "mlOperatorIncludes.h"

// CurveData include
#include "mlDiagramData.h"

// WEM inspector include
#include <WEMBase/WEMModuleBase/WEMInspector.h>

ML_START_NAMESPACE


//! Computes the center of mass of a WEM object
class MLWEMCOMMUNITYMODULES_EXPORT WEMVolume : public WEMInspector
{
  //! Implements interface for the runtime type system of the ML.
  ML_BASEOP_CLASS_HEADER(WEMVolume)

public:

  //! Constructor.
  WEMVolume (std::string type="WEMVolume");

protected:

  //! Destructor.
  virtual ~WEMVolume();

  //! Initialize module after loading.
  virtual void activateAttachments();

  //! Handle field changes of the field \c field.
  virtual void handleNotification (Field *field);

  //! _process()-routine for correct processing.
  virtual void _process();

private:

  // ----------------------------------------------------------
  //@{ \name Module field declarations
  // ----------------------------------------------------------

  //! Min, max volume field and patch index field
  FloatField* _minVolumeFld, * _maxVolumeFld;
  IntField* _minVolumeIndexFld, * _maxVolumeIndexFld;

  //! Output curvelist with volume values
  BaseField * _outputVolumeCurveFld;
  CurveList _outputVolumeCurve;
  CurveData _outputVolumeCurveData;

  //@}

  //! The main processing routine. Here, the own mesh algorithm can be implemented.
  void ComputeVolumes();

};


ML_END_NAMESPACE

#endif // __mlWEMVolume_H


