// EnergyPlus, Copyright (c) 1996-2020, The Board of Trustees of the University of Illinois,
// The Regents of the University of California, through Lawrence Berkeley National Laboratory
// (subject to receipt of any required approvals from the U.S. Dept. of Energy), Oak Ridge
// National Laboratory, managed by UT-Battelle, Alliance for Sustainable Energy, LLC, and other
// contributors. All rights reserved.
//
// NOTICE: This Software was developed under funding from the U.S. Department of Energy and the
// U.S. Government consequently retains certain rights. As such, the U.S. Government has been
// granted for itself and others acting on its behalf a paid-up, nonexclusive, irrevocable,
// worldwide license in the Software to reproduce, distribute copies to the public, prepare
// derivative works, and perform publicly and display publicly, and to permit others to do so.
//
// Redistribution and use in source and binary forms, with or without modification, are permitted
// provided that the following conditions are met:
//
// (1) Redistributions of source code must retain the above copyright notice, this list of
//     conditions and the following disclaimer.
//
// (2) Redistributions in binary form must reproduce the above copyright notice, this list of
//     conditions and the following disclaimer in the documentation and/or other materials
//     provided with the distribution.
//
// (3) Neither the name of the University of California, Lawrence Berkeley National Laboratory,
//     the University of Illinois, U.S. Dept. of Energy nor the names of its contributors may be
//     used to endorse or promote products derived from this software without specific prior
//     written permission.
//
// (4) Use of EnergyPlus(TM) Name. If Licensee (i) distributes the software in stand-alone form
//     without changes from the version obtained under this License, or (ii) Licensee makes a
//     reference solely to the software portion of its product, Licensee must refer to the
//     software as "EnergyPlus version X" software, where "X" is the version number Licensee
//     obtained under this License and may not use a different name for the software. Except as
//     specifically required in this Section (4), Licensee shall not use in a company name, a
//     product name, in advertising, publicity, or other promotional activities any name, trade
//     name, trademark, logo, or other designation of "EnergyPlus", "E+", "e+" or confusingly
//     similar designation, without the U.S. Department of Energy's prior written consent.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR
// IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
// AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
// OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.

#ifndef ReportSizingManager_hh_INCLUDED
#define ReportSizingManager_hh_INCLUDED

// ObjexxFCL Headers
#include <ObjexxFCL/Optional.hh>

// EnergyPlus Headers
#include <EnergyPlus/EnergyPlus.hh>
#include <EnergyPlus/Data/EnergyPlusData.hh>

namespace EnergyPlus {
    class OutputFiles;

namespace ReportSizingManager {

    // Functions

    void ReportSizingOutput(std::string const &CompType,        // the type of the component
                            std::string const &CompName,        // the name of the component
                            std::string const &VarDesc,         // the description of the input variable
                            Real64 const VarValue,              // the value from the sizing calculation
                            Optional_string_const UsrDesc = _,  // the description of a user-specified variable
                            Optional<Real64 const> UsrValue = _ // the value from the user for the desc item
    );

    void RequestSizing(EnergyPlusData &state, std::string const &CompType,      // type of component
                       std::string const &CompName,      // name of component
                       int const SizingType,             // integerized type of sizing requested (see DataHVACGlobals, e.g. CoolingCapacitySizing)
                       std::string const &SizingString,  // string containing info for eio report
                       Real64 &SizingResult,             // result of the sizing procedure
                       bool const PrintWarningFlag,      // TRUE when requesting output (eio) reporting
                       std::string const &CallingRoutine, // name of calling rotuine for warning messages
                       Real64 const fraction = 1.0
    );

    void GetCoilDesFlowT(int SysNum,           // central air system index
                         Real64 CpAir,         // specific heat to be used in calculations [J/kgC]
                         Real64 &DesFlow,      // returned design mass flow [kg/s]
                         Real64 &DesExitTemp,  // returned design coil exit temperature [kg/s]
                         Real64 &DesExitHumRat // returned design coil exit humidity ratio [kg/kg]
    );

    Real64 setOAFracForZoneEqSizing(Real64 const &desMassFlow, DataSizing::ZoneEqSizingData const &zoneEqSizing);
    Real64 setHeatCoilInletTempForZoneEqSizing(Real64 const &outAirFrac,
                                               DataSizing::ZoneEqSizingData const &zoneEqSizing,
                                               DataSizing::ZoneSizingData const &finalZoneSizing);
    Real64 setHeatCoilInletHumRatForZoneEqSizing(Real64 const &outAirFrac,
                                                 DataSizing::ZoneEqSizingData const &zoneEqSizing,
                                                 DataSizing::ZoneSizingData const &finalZoneSizing);
    Real64 setCoolCoilInletTempForZoneEqSizing(Real64 const &outAirFrac,
                                               DataSizing::ZoneEqSizingData const &zoneEqSizing,
                                               DataSizing::ZoneSizingData const &finalZoneSizing);
    Real64 setCoolCoilInletHumRatForZoneEqSizing(Real64 const &outAirFrac,
                                                 DataSizing::ZoneEqSizingData const &zoneEqSizing,
                                                 DataSizing::ZoneSizingData const &finalZoneSizing);

} // namespace ReportSizingManager

} // namespace EnergyPlus

#endif
