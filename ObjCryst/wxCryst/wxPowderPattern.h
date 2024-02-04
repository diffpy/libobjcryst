/*  ObjCryst++ Object-Oriented Crystallographic Library
    (c) 2000-2002 Vincent Favre-Nicolin vincefn@users.sourceforge.net
        2000-2001 University of Geneva (Switzerland)

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
*/

#ifndef _VFN_WX_POWDERPATTERN_H_
#define _VFN_WX_POWDERPATTERN_H_

#include "wx/grid.h"

#include "ObjCryst/wxCryst/wxRefinableObj.h"
#include "ObjCryst/ObjCryst/ScatteringCorr.h"
#include "ObjCryst/ObjCryst/PowderPattern.h"
#include "ObjCryst/ObjCryst/Indexing.h"
namespace ObjCryst
{
class WXPowderPatternGraph;

/// WX Class for PowderPattern objects
class WXPowderPattern: public WXRefinableObj
{
   public:
      WXPowderPattern(wxWindow *parent, PowderPattern*);
      virtual void CrystUpdate(const bool updateUI=false,const bool mutexlock=false);
      void OnMenuAddCompBackgd(wxCommandEvent & WXUNUSED(event));
      void OnMenuAddCompBackgdBayesian(wxCommandEvent & WXUNUSED(event));
      void OnMenuAddCompCryst(wxCommandEvent & WXUNUSED(event));
      void OnMenuRemoveComp(wxCommandEvent & WXUNUSED(event));
      void OnMenuShowGraph(wxCommandEvent & WXUNUSED(event));
      void OnMenuSaveText(wxCommandEvent & WXUNUSED(event));
      void OnMenuSimulate(wxCommandEvent & WXUNUSED(event));
      void OnMenuImportPattern(wxCommandEvent & WXUNUSED(event));
      void OnMenuFitScaleForR(wxCommandEvent & WXUNUSED(event));
      void OnMenuFitScaleForRw(wxCommandEvent & WXUNUSED(event));
      void OnMenuSavePattern(wxCommandEvent & WXUNUSED(event));
      void OnMenuSetWavelength(wxCommandEvent &event);
      void OnMenuAddExclude(wxCommandEvent & WXUNUSED(event));
      /// Profile fitting & Le Bail intensity extraction
      void OnMenuLeBail(wxCommandEvent &event);
      void OnMenuExport(wxCommandEvent &event);
      void NotifyDeleteGraph();
      const PowderPattern& GetPowderPattern()const;
      PowderPattern& GetPowderPattern();
      void UpdateUI(const bool mutexlock=false);
   private:
      PowderPattern *mpPowderPattern;
      WXRegistry<PowderPatternComponent> *mpWXComponent;
      WXPowderPatternGraph *mpGraph;
      // Store statistics for display
      REAL mChi2;
      REAL mGoF;
      REAL mRwp;
      REAL mRp;
      /// This flag is used to automatically open the powder pattern graph once data has been loaded.
      bool mPowderPatternWasPreviouslyEmpty;
   DECLARE_EVENT_TABLE()
};
/** Class to display a Powder Pattern (calc,obs) in a graphic window.
*
* So far only displays calc and obs patterns.
* \todo display the difference pattern. Allow to zoom. Display
* reflection positions for crystalline phases.
*/
class WXPowderPatternGraph: public wxWindow
{
   public:
      /// Constructor. The top frame should have a Status bar with two fields (at least)
      WXPowderPatternGraph(wxFrame *frame, WXPowderPattern* parent);
      ~WXPowderPatternGraph();
      /// Redraw the spectrum
      void OnPaint(wxPaintEvent& WXUNUSED(event));
      /// Display the Theta and intensity values at the mouse position, in the status bar
      void OnMouse(wxMouseEvent &event);
      /// Wheel wan be used to scroll the pattern
      void OnMouseWheel(wxMouseEvent &event);
      /// Update the powder spectrum, at the user's request. This calls
      /// the WXPowderPattern::CrystUpdate().
      void OnUpdate(wxCommandEvent & WXUNUSED(event));
      /** Update the pattern. This is called by the WXPowderPattern parent.
      *
      * \deprecated Rather, use the new WXPowderPatternGraph::SetPattern() which
      * takes a full vector of x coordinates rather than min & step
      */
      void SetPattern(const CrystVector_REAL &obs,
                      const CrystVector_REAL &calc,
                      const REAL tthetaMin,const REAL tthetaStep,
                      const CrystVector_REAL &sigma,
                      const CrystVector_REAL &chi2Cumul);
      /** Update the pattern. This is called by the WXPowderPattern parent.
      *
      */
      void SetPattern(const CrystVector_REAL &x,
                      const CrystVector_REAL &obs,
                      const CrystVector_REAL &calc,
                      const CrystVector_REAL &sigma,
                      const CrystVector_REAL &chi2Cumul);
      /// Redraw the pattern (special function to ensure complete redrawing under windows...)
      void OnRedrawNewPattern(wxUpdateUIEvent& WXUNUSED(event));
      void OnToggleLabel(wxCommandEvent& WXUNUSED(event));
      void OnFindPeaks(wxCommandEvent& WXUNUSED(event));
      void OnLoadPeaks(wxCommandEvent& WXUNUSED(event));
      void OnSavePeaks(wxCommandEvent& WXUNUSED(event));
      /// Add or remove peak
      void OnChangePeak(wxCommandEvent& WXUNUSED(event));
      void OnIndex(wxCommandEvent& WXUNUSED(event));
      void OnChangeScale(wxCommandEvent &event);
      /// Profile fitting & Le Bail intensity extraction
      void OnLeBail(wxCommandEvent &event);
      void OnKeyDown(wxKeyEvent& event);
      void OnSize(wxSizeEvent& event);
      WXPowderPattern& GetWXPowderPattern();
      const WXPowderPattern& GetWXPowderPattern()const;
   private:
      /// Reset the limits of the axis to full range.
      void ResetAxisLimits();
      /// Convert X data (2theta) coordinate to screen coordinate (pixel)
      long Data2ScreenX(const REAL x)const;
      /// Convert X data (as data point index) to screen coordinate (pixel)
      long Point2ScreenX(const long x)const;
      /// Convert Y data (intensity) coordinate to screen coordinate (pixel)
      long Data2ScreenY(const REAL y)const;
      /// Convert X screen coordinate (pixel) to data (2theta) coordinate
      REAL Screen2DataX(const long x)const;
      /// Convert Y screen coordinate (pixel) to data (intensity) coordinate
      REAL Screen2DataY(const long y)const;
      WXPowderPattern *mpPattern;
      /// Data vectors (Note that when x coordinates are 2theta, they are stored in degrees here)
      CrystVector_REAL mX,mObs,mCalc,m2theta,mSigma,mChi2Cumul;
      const long mMargin;
      const REAL mDiffPercentShift;
      REAL mMaxIntensity,mMinIntensity,mMinX,mMaxX;
      /// True if no vertical zoom has been used
      bool mDefaultIntensityScale;
      wxFrame *mpParentFrame;
      /// Mutex to lock the pattern and associated data
      CrystMutex mMutex;
      /// Pop-up menu
      wxMenu* mpPopUpMenu;
      /// Are we within a dragging event ?
      bool mIsDragging;
      /// Remember coordinates at the beginning of the dragging
      REAL mDraggingX0,mDraggingIntensity0;
      /// Clock corresponding to when the graph limits where last changed. This
      /// is compared to PowderPattern::GetClockPowderPatternPar() to know if
      /// these parameter need to be reset.
      RefinableObjClock mClockAxisLimits;
      /// Display labels ?
      bool mDisplayLabel;
      /// Display peaks ?
      bool mDisplayPeak;
      /// The lists of labels for all components of the powder pattern.
      list<list<pair<const REAL ,const string > > > mvLabelList;
      /// List of observed peak positions
      PeakList mPeakList;
      /// Scaling options for x and y axis
      /// x: 0 data (2theta, tof) ; 1: 1/d ; 2: 2pi/d
      /// y: 0 linear ; 1: sqrt(I) ; 2: log10(I)
      long mXScale,mYScale;
      DECLARE_EVENT_TABLE()
};

/** Class to display a Powder Pattern Background
*
* Still very limited ! Only allows to import a list of background
* points...
* \todo Display the list of background points with the refinable
* intensity. Add th possibility to change the points.
*/
class WXPowderPatternBackground: public WXRefinableObj
{
   public:
      WXPowderPatternBackground(wxWindow *parent, PowderPatternBackground*);
      void OnMenuImportUserBackground(wxCommandEvent & WXUNUSED(event));
      void OnMenuOptimizeBayesianBackground(wxCommandEvent & WXUNUSED(event));
      void OnMenuAutomaticBayesianBackground(wxCommandEvent & WXUNUSED(event));
      void OnEditGridBackgroundPoint(wxGridEvent &e);
      virtual void CrystUpdate(const bool updateUI=false,const bool mutexlock=false);
      virtual void UpdateUI(const bool mutexlock=false);
      virtual bool Enable(bool enable=true);
   private:
      PowderPatternBackground *mpPowderPatternBackground;
      wxGrid *mpGridBackgroundPoint;
      /// Copy of the list of points and intensity
      mutable CrystVector_REAL mBackgroundInterpPointX,mBackgroundInterpPointIntensity;
      /// True if the list of points has changed since last displayed
      bool mNeedUpdateUI;
      bool mIsSelfUpdating;
   DECLARE_EVENT_TABLE()
};
/** Class to display one Preferred Orientation phase using
* the March-Dollase parametrization
*
*/
class WXTexturePhaseMarchDollase: public WXCrystObjBasic
{
   public:
      WXTexturePhaseMarchDollase(wxWindow *parent, TexturePhaseMarchDollase*,TextureMarchDollase*);
      ~WXTexturePhaseMarchDollase();
      virtual void CrystUpdate(const bool updateUI=false,const bool mutexlock=false);
      virtual void UpdateUI(const bool mutexlock=false);
   private:
      wxBoxSizer *mpSizer;
      WXCrystObjBasicList mList;
      TexturePhaseMarchDollase* mpTexturePhaseMarchDollase;
};

/** Class to display the Preferred Orientation Correction using
* the March-Dollase parametrization
*
* Allows to add phases, and change the parameters.
*/
class WXTextureMarchDollase: public WXRefinableObj
{
   public:
      WXTextureMarchDollase(wxWindow *parent, TextureMarchDollase*);
      void OnAddTexturePhase(wxCommandEvent & WXUNUSED(event));
      void OnDeleteTexturePhase(wxCommandEvent & WXUNUSED(event));
   private:
      TextureMarchDollase* mpTextureMarchDollase;
   DECLARE_EVENT_TABLE()
};

/** Class to display one Preferred Orientation phase using
* the Ellipsoid model
*
*/
class WXTextureEllipsoid: public WXCrystObj
{
   public:
      WXTextureEllipsoid(wxWindow *parent, TextureEllipsoid *prof);
      virtual ~WXTextureEllipsoid();
      virtual bool OnChangeName(const int id);
   private:
      TextureEllipsoid* mpTextureEllipsoid;
};

/** Class to display a Powder Pattern for a crystalline phase
*
* Allows to choose the Crystal, as well as the profile
* associated to this crystalline phase.
*/
class WXPowderPatternDiffraction: public WXRefinableObj
{
   public:
      WXPowderPatternDiffraction(wxWindow *parent, PowderPatternDiffraction*);
      void OnChangeCrystal(wxCommandEvent & WXUNUSED(event));
      void OnMenuSaveHKLFcalc(wxCommandEvent & WXUNUSED(event));
      void OnChangeProfile(wxCommandEvent & event);
      virtual void CrystUpdate(const bool updateUI=false,const bool mutexlock=false);
      virtual void UpdateUI(const bool mutexlock=false);
      virtual bool Enable(bool enable=true);
      /// Perform Le Bail extraction
      void OnLeBail(wxCommandEvent &event);
      /// Freeze lattice parameter, which will not follow anymore the Crystal Unitcell values
      void OnFreezeLatticePar(wxCommandEvent &event);
   private:
      PowderPatternDiffraction *mpPowderPatternDiffraction;
      WXFieldChoice* mpFieldCrystal;
      wxCheckBox *mpProfileFittingMode;
      wxCheckBox *mpFreezeLatticePar;
      wxGrid *mpGridFrozenLatticePar;
      bool mFreezeLatticePar;
      CrystVector_REAL mFrozenLatticePar;
      //Need Layout if we show/hide frozen lattice parameters
      bool mNeedLayout;
   DECLARE_EVENT_TABLE()
};

/** Class to display a Powder Pattern Pseudo-Voigt Profile
*
*/
class WXProfilePseudoVoigt: public WXCrystObj
{
   public:
      WXProfilePseudoVoigt(wxWindow *parent, ReflectionProfilePseudoVoigt *prof);
      virtual ~WXProfilePseudoVoigt();
      virtual bool OnChangeName(const int id);
   private:
      ReflectionProfilePseudoVoigt *mpProfile;
};

/** Class to display a Powder Pattern Pseudo-Voigt Profile with Anisotropic broadening
*
*/
class WXProfilePseudoVoigtAnisotropic: public WXCrystObj
{
   public:
      WXProfilePseudoVoigtAnisotropic(wxWindow *parent, ReflectionProfilePseudoVoigtAnisotropic *prof);
      virtual ~WXProfilePseudoVoigtAnisotropic();
      virtual bool OnChangeName(const int id);
   private:
      ReflectionProfilePseudoVoigtAnisotropic *mpProfile;
};

/** Class to display a Powder Pattern Pseudo-Voigt Profile
*
*/
class WXProfileDoubleExponentialPseudoVoigt: public WXCrystObj
{
   public:
      WXProfileDoubleExponentialPseudoVoigt
         (wxWindow *parent, ReflectionProfileDoubleExponentialPseudoVoigt *prof);
      virtual ~WXProfileDoubleExponentialPseudoVoigt();
      virtual bool OnChangeName(const int id);
   private:
      ReflectionProfileDoubleExponentialPseudoVoigt *mpProfile;
};

} //namespace

#endif //_VFN_WX_POWDERPATTERN_H_
